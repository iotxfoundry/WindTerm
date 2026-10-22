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

QString span(const QString &text, const QString &color)
{
    return QStringLiteral("<span style=\"color:%1\">%2</span>").arg(color, text.toHtmlEscaped());
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
    m_gutter->setFixedWidth(110);
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

    // margin.* 见 scheme.theme margin.number/margin.timestamp
    const QString lineNumber = schemeColor(QStringLiteral("margin.number"), QStringLiteral("#2B91AF"));
    const QString timestamp = schemeColor(QStringLiteral("margin.timestamp"), QStringLiteral("gray"));
    const QString green = schemeColor(QStringLiteral("terminal.ansiGreen"), QStringLiteral("#86B42B"));
    const QString blue = schemeColor(QStringLiteral("terminal.ansiBlue"), QStringLiteral("#3465A4"));
    const QString red = schemeColor(QStringLiteral("terminal.ansiRed"), QStringLiteral("#C4265E"));
    const QString white = schemeColor(QStringLiteral("terminal.ansiWhite"), QStringLiteral("#e3e3dd"));

    const QString user = span(QStringLiteral("neardi@LB3576"), green);
    const QString path = span(QStringLiteral("~"), blue);

    const auto timestampRow = [&](const QString &text) {
        m_gutter->appendHtml(QStringLiteral("<div align=\"right\">%1</div>").arg(span(text, timestamp)));
    };
    m_gutter->appendPlainText(QString());
    timestampRow(QStringLiteral("[14:38:38]"));
    m_gutter->appendPlainText(QStringLiteral(" "));
    timestampRow(QStringLiteral("[14:38:43]"));
    m_gutter->appendPlainText(QStringLiteral(" "));
    timestampRow(QStringLiteral("[14:39:26]"));

    m_main->appendHtml(span(sessionName + QStringLiteral(" terminal placeholder"), white));
    m_main->appendHtml(span(QStringLiteral("728"), lineNumber) + QLatin1Char(' ') + user + QLatin1Char(' ')
                       + path + QStringLiteral(" $ ping 192.168.1.35"));
    m_main->appendHtml(span(QStringLiteral("64 bytes from 192.168.1.35: icmp_seq=1 ttl=64 time=3.99 ms"), white));
    m_main->appendHtml(span(QStringLiteral("733"), lineNumber) + QLatin1Char(' ') + user + QLatin1Char(' ')
                       + path + QStringLiteral(" $ frpc -c wapi.toml"));
    m_main->appendHtml(span(QStringLiteral("E [proxy/proxy.go:237] connect to local service error"), red));
    m_main->appendHtml(span(QStringLiteral("759"), lineNumber) + QLatin1Char(' ') + user + QLatin1Char(' ')
                       + path + QStringLiteral(" $"));
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
    for (const QString &line : m_screen->scrollback()) {
        html += QStringLiteral("<span style=\"color:#888888\">%1</span><br>").arg(line.toHtmlEscaped());
    }

    for (int row = 0; row < m_screen->rows(); ++row) {
        QString style;
        bool spanOpen = false;
        for (int col = 0; col < m_screen->cols(); ++col) {
            const Cell &cell = m_screen->cellAt(row, col);
            QColor fg = cell.fg;
            QColor bg = cell.bg;
            if (cell.reverse)
                qSwap(fg, bg);

            QString current = QStringLiteral("color:%1;background-color:%2;").arg(fg.name(), bg.name());
            if (cell.bold)
                current += QStringLiteral("font-weight:bold;");
            if (cell.underline)
                current += QStringLiteral("text-decoration:underline;");

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
        if (row + 1 < m_screen->rows())
            html += QStringLiteral("<br>");
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
    cursor.insertHtml(QStringLiteral("<span style=\"color:#888888\">%1</span><br>").arg(text.toHtmlEscaped()));
    m_main->verticalScrollBar()->setValue(m_main->verticalScrollBar()->maximum());
}
