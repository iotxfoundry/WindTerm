#include "TerminalView.h"

#include <QFont>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QPlainTextEdit>
#include <QScrollBar>
#include <QTextCursor>

#include "core/Session.h"
#include "core/SchemeManager.h"
#include "core/ScreenModel.h"
#include "core/VtParser.h"
#include "core/WindConfig.h"

namespace {

QString schemeColor(const QString &name, const QString &fallback)
{
    const QColor color = SchemeManager::instance().color(name);
    return color.isValid() ? color.name(QColor::HexRgb) : fallback;
}

// 系统提示色（视图层元素，原版无对应；与滚回旧内容同为弱化灰）
QString hintColor()
{
    return schemeColor(QStringLiteral("terminal.ansiBrightBlack"), QStringLiteral("#666666"));
}

QString span(const QString &text, const QString &color)
{
    return QStringLiteral("<span style=\"color:%1\">%2</span>").arg(color, text.toHtmlEscaped());
}

// 历史行与当前屏共用同一 cell→HTML 路径——滚回保留原色（原版不重刷历史行颜色）
void appendRowHtml(QString &html, const QVector<Cell> &cells, bool last)
{
    QString style;
    bool spanOpen = false;
    for (const Cell &cell : cells) {
        QColor fg = cell.fg;
        QColor bg = cell.bg;
        if (cell.reverse)
            qSwap(fg, bg);

        const QString current = QStringLiteral("color:%1;background-color:%2;%3%4")
                                    .arg(fg.name(), bg.name(),
                                         cell.bold ? QStringLiteral("font-weight:bold;") : QString(),
                                         cell.underline ? QStringLiteral("text-decoration:underline;") : QString());
        if (current != style) {
            if (spanOpen)
                html += QStringLiteral("</span>");
            html += QStringLiteral("<span style=\"%1\">").arg(current);
            style = current;
            spanOpen = true;
        }

        const QChar ch = cell.ch;
        html += ch == QLatin1Char('&') ? QStringLiteral("&amp;")
              : ch == QLatin1Char('<') ? QStringLiteral("&lt;")
              : ch == QLatin1Char('>') ? QStringLiteral("&gt;")
              : QString(ch);
    }
    if (spanOpen)
        html += QStringLiteral("</span>");
    if (!last)
        html += QStringLiteral("<br>");
}

} // namespace

TerminalView::TerminalView(const QString &sessionName, QWidget *parent)
    : QWidget(parent)
    , m_gutter(new QPlainTextEdit(this))
    , m_main(new QPlainTextEdit(this))
    , m_session(nullptr)
    , m_screen(nullptr)
    , m_parser(nullptr)
{
    // 原版 TextView（MuxPane 终端区）以类名挂 objectName（0x005c6d16），驱动 gui.theme TextView 规则
    setObjectName(QStringLiteral("TextView"));
    Q_UNUSED(sessionName); // 占位内容已删（NoSessions），参数保留兼容调用方

    // 终端外观内聚在此，不依赖 MainWindow 的时机补丁
    const QString background = schemeColor(QStringLiteral("line.background"), QStringLiteral("#272822"));
    const QString foreground = schemeColor(QStringLiteral("terminal.ansiWhite"), QStringLiteral("#e3e3dd"));
    const QString editorStyle = QStringLiteral("QPlainTextEdit{background-color:%1;color:%2;border:none;}")
                                    .arg(background, foreground);

    QFont font(WindConfig::instance().valueToString(QStringLiteral("text.fontFamily1"),
                                                    QStringLiteral("Roboto Mono")));
    font.setPointSizeF(WindConfig::instance().valueToDouble(QStringLiteral("text.fontSize"), 10));

    for (QPlainTextEdit *edit : {m_gutter, m_main}) {
        edit->setReadOnly(true);
        edit->setFont(font);
        edit->setStyleSheet(editorStyle);
        edit->setFrameShape(QFrame::NoFrame);
        edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
    // gui.theme:851 TextView > QAbstractScrollArea QScrollBar:vertical{width:16px}，原版终端区有滚动条
    m_main->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    // wind.config text.margins（L111-116）：timestamp width 10 leftPadding 4 / number width 10 leftPadding 4
    // 两列合成当前 gutter；宽度按等宽字符数换算，padding 左右各 4 -> 共 8px
    const int ch = m_gutter->fontMetrics().horizontalAdvance(QLatin1Char('0'));
    m_gutter->setFixedWidth((10 + 10) * ch + 4 * 2);
    m_gutter->setFocusPolicy(Qt::NoFocus);

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(m_gutter);
    layout->addWidget(m_main, 1);

    // gutter 与主区滚动联动；先比较值避免双向递归
    connect(m_main->verticalScrollBar(), &QScrollBar::valueChanged, this, [this](int value) {
        if (m_gutter->verticalScrollBar()->value() != value)
            m_gutter->verticalScrollBar()->setValue(value);
    });
    connect(m_gutter->verticalScrollBar(), &QScrollBar::valueChanged, this, [this](int value) {
        if (m_main->verticalScrollBar()->value() != value)
            m_main->verticalScrollBar()->setValue(value);
    });

    // margin.*（scheme.theme margin.number/margin.timestamp）配色延迟到 attachSession/渲染路径；
    // profile terminal.startupSessions=NoSessions：构造后空白（原版启动无假内容）
}

void TerminalView::attachSession(Session *session)
{
    m_session = session;
    if (!m_session)
        return;

    delete m_parser;
    delete m_screen;

    QColor fg = SchemeManager::instance().color(QStringLiteral("terminal.ansiWhite"));
    QColor bg = SchemeManager::instance().color(QStringLiteral("line.background"));
    if (!fg.isValid())
        fg = QColor(QStringLiteral("#e3e3dd"));
    if (!bg.isValid())
        bg = QColor(QStringLiteral("#272822"));

    m_screen = new ScreenModel(24, 80, fg, bg);
    m_parser = new VtParser(m_screen);

    m_gutter->clear();
    m_main->clear();
    m_main->setReadOnly(false);
    m_main->installEventFilter(this);
    m_main->setFocus();

    connect(m_session, &Session::output, this, [this](const QByteArray &data) {
        m_parser->feed(data);
        renderScreen();
    });

    connect(m_session, &Session::finished, this, [this]() {
        appendSystemMessage(tr("[进程已退出]"));
        m_main->setReadOnly(true);
    });
}

TerminalView::~TerminalView()
{
    delete m_parser;
    delete m_screen;
}

void TerminalView::renderScreen()
{
    QString html;
    for (const auto &row : m_screen->scrollback())
        appendRowHtml(html, row, false);

    for (int row = 0; row < m_screen->rows(); ++row) {
        QVector<Cell> cells(m_screen->cols());
        for (int col = 0; col < m_screen->cols(); ++col)
            cells[col] = m_screen->cellAt(row, col);
        appendRowHtml(html, cells, row + 1 == m_screen->rows());
    }

    m_main->document()->setHtml(html);
    m_main->verticalScrollBar()->setValue(m_main->verticalScrollBar()->maximum());
}

bool TerminalView::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == m_main && event->type() == QEvent::KeyPress && m_session) {
        auto *keyEvent = static_cast<QKeyEvent *>(event);
        QByteArray data;
        switch (keyEvent->key()) {
        case Qt::Key_Return:
        case Qt::Key_Enter:
            data = QByteArrayLiteral("\r");
            break;
        case Qt::Key_Backspace:
            data = QByteArrayLiteral("\x7f");
            break;
        case Qt::Key_Tab:
            data = QByteArrayLiteral("\t");
            break;
        case Qt::Key_Escape:
            data = QByteArrayLiteral("\x1b");
            break;
        default:
            if (!keyEvent->text().isEmpty())
                data = keyEvent->text().toUtf8();
            break;
        }
        if (!data.isEmpty()) {
            m_session->write(data);
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void TerminalView::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    if (m_session) {
        // TODO: 用字体 metrics 精确估算 rows/cols，F1 先固定 24x80
        m_session->resize(24, 80);
    }
}

void TerminalView::appendSystemMessage(const QString &text)
{
    QTextCursor cursor(m_main->document());
    cursor.movePosition(QTextCursor::End);
    cursor.insertHtml(QStringLiteral("<span style=\"color:%1\">%2</span><br>").arg(hintColor(), text.toHtmlEscaped()));
    m_main->verticalScrollBar()->setValue(m_main->verticalScrollBar()->maximum());
}
