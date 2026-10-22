#include "VtFilter.h"

namespace {

const QColor kAnsiColors[8] = {
    QColor(QStringLiteral("#000000")), QColor(QStringLiteral("#ff0000")),
    QColor(QStringLiteral("#00ff00")), QColor(QStringLiteral("#ffff00")),
    QColor(QStringLiteral("#0000ff")), QColor(QStringLiteral("#ff00ff")),
    QColor(QStringLiteral("#00ffff")), QColor(QStringLiteral("#ffffff"))
};

const QColor kAnsiBrightColors[8] = {
    QColor(QStringLiteral("#808080")), QColor(QStringLiteral("#ff0000")),
    QColor(QStringLiteral("#00ff00")), QColor(QStringLiteral("#ffff00")),
    QColor(QStringLiteral("#0000ff")), QColor(QStringLiteral("#ff00ff")),
    QColor(QStringLiteral("#00ffff")), QColor(QStringLiteral("#ffffff"))
};

} // namespace

QString VtFilter::feed(const QByteArray &data)
{
    m_pendingUtf8.append(data);

    // 保留不完整的 UTF-8 尾巴，等下一次 feed 拼接后再解码
    int cut = m_pendingUtf8.size();
    int index = m_pendingUtf8.size() - 1;
    int continuations = 0;
    while (index >= 0 && (static_cast<unsigned char>(m_pendingUtf8.at(index)) & 0xC0) == 0x80) {
        ++continuations;
        --index;
    }
    if (index >= 0) {
        const unsigned char lead = static_cast<unsigned char>(m_pendingUtf8.at(index));
        int expected = 0;
        if ((lead & 0xE0) == 0xC0)
            expected = 2;
        else if ((lead & 0xF0) == 0xE0)
            expected = 3;
        else if ((lead & 0xF8) == 0xF0)
            expected = 4;
        if (expected > 0 && continuations + 1 < expected)
            cut = index;
    }

    const QByteArray complete = m_pendingUtf8.left(cut);
    m_pendingUtf8 = m_pendingUtf8.mid(cut);

    const QString text = QString::fromUtf8(complete);
    QString html;
    for (const QChar ch : text)
        processChar(ch, html);
    if (m_spanOpen) {
        html += QStringLiteral("</span>");
        m_spanOpen = false;
        m_openStyle.clear();
    }
    return html;
}

bool VtFilter::takeClearRequest()
{
    const bool requested = m_clearRequested;
    m_clearRequested = false;
    return requested;
}

void VtFilter::processChar(QChar ch, QString &html)
{
    switch (m_state) {
    case Normal:
        if (ch == QLatin1Char('\x1b')) {
            m_state = Escape;
        } else if (ch == QLatin1Char('\n')) {
            html += QStringLiteral("<br>");
        } else if (ch == QLatin1Char('\r')) {
            // 忽略 CR：bash 的 CRLF 由 LF 换行即可
        } else if (ch == QLatin1Char('\b')) {
            if (!html.isEmpty() && !html.endsWith(QLatin1Char('>')))
                html.chop(1);
        } else if (ch == QLatin1Char('\t')) {
            html += QStringLiteral("&nbsp;&nbsp;&nbsp;&nbsp;");
        } else if (ch.unicode() >= 0x20 && ch != QChar(0x7f)) {
            appendStyled(ch, html);
        }
        return;

    case Escape:
        if (ch == QLatin1Char('[')) {
            m_csi.clear();
            m_state = Csi;
        } else if (ch == QLatin1Char(']')) {
            m_state = Osc;
        } else {
            m_state = Normal;
        }
        return;

    case Csi:
        if (ch.unicode() >= 0x40 && ch.unicode() <= 0x7e) {
            const QString params = QString::fromLatin1(m_csi);
            if (ch == QLatin1Char('m')) {
                applySgr(params);
            } else if (ch == QLatin1Char('J')) {
                if (params == QStringLiteral("2") || params.isEmpty())
                    m_clearRequested = true;
            }
            // ESC[K（清行）与其它私有 CSI 直接吞掉
            m_state = Normal;
        } else if (ch.unicode() >= 0x20) {
            if (m_csi.size() < 32)
                m_csi.append(static_cast<char>(ch.unicode()));
        }
        return;

    case Osc:
        if (ch == QLatin1Char('\a'))
            m_state = Normal;
        else if (ch == QLatin1Char('\x1b'))
            m_state = OscEscape;
        return;

    case OscEscape:
        m_state = (ch == QLatin1Char('\\')) ? Normal : Osc;
        return;
    }
}

void VtFilter::applySgr(const QString &params)
{
    const QStringList parts = params.split(QLatin1Char(';'));
    for (const QString &part : parts) {
        const int code = part.isEmpty() ? 0 : part.toInt();
        if (code == 0) {
            m_fg = QColor();
            m_bg = QColor();
            m_bold = false;
            m_underline = false;
        } else if (code == 1) {
            m_bold = true;
        } else if (code == 3) {
            // italic 暂不渲染
        } else if (code == 4) {
            m_underline = true;
        } else if (code == 22) {
            m_bold = false;
        } else if (code == 24) {
            m_underline = false;
        } else if (code >= 30 && code <= 37) {
            m_fg = kAnsiColors[code - 30];
        } else if (code == 39) {
            m_fg = QColor();
        } else if (code >= 40 && code <= 47) {
            m_bg = kAnsiColors[code - 40];
        } else if (code == 49) {
            m_bg = QColor();
        } else if (code >= 90 && code <= 97) {
            m_fg = kAnsiBrightColors[code - 90];
        } else if (code >= 100 && code <= 107) {
            m_bg = kAnsiBrightColors[code - 100];
        }
    }
}

void VtFilter::appendStyled(QChar ch, QString &html)
{
    QString text = ch == QLatin1Char('&') ? QStringLiteral("&amp;")
                 : ch == QLatin1Char('<') ? QStringLiteral("&lt;")
                 : ch == QLatin1Char('>') ? QStringLiteral("&gt;")
                 : QString(ch);

    QString style;
    if (m_fg.isValid())
        style += QStringLiteral("color:%1;").arg(m_fg.name());
    if (m_bg.isValid())
        style += QStringLiteral("background-color:%1;").arg(m_bg.name());
    if (m_bold)
        style += QStringLiteral("font-weight:bold;");
    if (m_underline)
        style += QStringLiteral("text-decoration:underline;");

    if (style != m_openStyle) {
        if (m_spanOpen) {
            html += QStringLiteral("</span>");
            m_spanOpen = false;
        }
        m_openStyle = style;
        if (!style.isEmpty()) {
            html += QStringLiteral("<span style=\"%1\">").arg(style);
            m_spanOpen = true;
        }
    }
    html += text;
}
