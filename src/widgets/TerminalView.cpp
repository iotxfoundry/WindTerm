#include "TerminalView.h"

#include <QFontDatabase>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QScrollBar>

#include "core/SchemeManager.h"

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
{
    const QFont mono = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    for (QPlainTextEdit *edit : {m_gutter, m_main}) {
        edit->setReadOnly(true);
        edit->setFont(mono);
        edit->setFrameShape(QFrame::NoFrame);
        edit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
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

    const QString gray = schemeColor(QStringLiteral("terminal.ansiBrightBlack"), QStringLiteral("#666666"));
    const QString green = schemeColor(QStringLiteral("terminal.ansiGreen"), QStringLiteral("#86B42B"));
    const QString blue = schemeColor(QStringLiteral("terminal.ansiBlue"), QStringLiteral("#3465A4"));
    const QString red = schemeColor(QStringLiteral("terminal.ansiRed"), QStringLiteral("#C4265E"));
    const QString white = schemeColor(QStringLiteral("terminal.ansiWhite"), QStringLiteral("#e3e3dd"));

    const QString user = span(QStringLiteral("neardi@LB3576"), green);
    const QString path = span(QStringLiteral("~"), blue);

    m_gutter->appendPlainText(QString());
    m_gutter->appendHtml(QStringLiteral("<div align=\"right\">[14:38:38]</div>"));
    m_gutter->appendPlainText(QStringLiteral(" "));
    m_gutter->appendHtml(QStringLiteral("<div align=\"right\">[14:38:43]</div>"));
    m_gutter->appendPlainText(QStringLiteral(" "));
    m_gutter->appendHtml(QStringLiteral("<div align=\"right\">[14:39:26]</div>"));

    m_main->appendHtml(span(sessionName + QStringLiteral(" terminal placeholder"), white));
    m_main->appendHtml(span(QStringLiteral("728"), gray) + QLatin1Char(' ') + user + QLatin1Char(' ')
                       + path + QStringLiteral(" $ ping 192.168.1.35"));
    m_main->appendHtml(span(QStringLiteral("64 bytes from 192.168.1.35: icmp_seq=1 ttl=64 time=3.99 ms"), white));
    m_main->appendHtml(span(QStringLiteral("733"), gray) + QLatin1Char(' ') + user + QLatin1Char(' ')
                       + path + QStringLiteral(" $ frpc -c wapi.toml"));
    m_main->appendHtml(span(QStringLiteral("E [proxy/proxy.go:237] connect to local service error"), red));
    m_main->appendHtml(span(QStringLiteral("759"), gray) + QLatin1Char(' ') + user + QLatin1Char(' ')
                       + path + QStringLiteral(" $"));
}
