#include "VtParser.h"

#include <QStringList>

#include "ScreenModel.h"

VtParser::VtParser(ScreenModel *screen)
    : m_screen(screen)
{
}

void VtParser::feed(const QByteArray &data)
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
    for (const QChar ch : text)
        processChar(ch);
}

void VtParser::processChar(QChar ch)
{
    switch (m_state) {
    case Normal:
        if (ch == QLatin1Char('\x1b')) {
            m_state = Escape;
        } else if (ch == QLatin1Char('\n')) {
            m_screen->newline();
        } else if (ch == QLatin1Char('\r')) {
            m_screen->carriageReturn();
        } else if (ch == QLatin1Char('\b')) {
            m_screen->backspace();
        } else if (ch == QLatin1Char('\t')) {
            m_screen->tab();
        } else if (ch == QLatin1Char('\a')) {
            // BEL 忽略
        } else if (ch.unicode() >= 0x20 && ch != QChar(0x7f)) {
            m_screen->printText(QString(ch));
        }
        return;

    case Escape:
        if (ch == QLatin1Char('[')) {
            m_csi.clear();
            m_state = Csi;
        } else if (ch == QLatin1Char(']')) {
            m_state = Osc;
        } else if (ch == QLatin1Char('P') || ch == QLatin1Char('X')
                   || ch == QLatin1Char('^') || ch == QLatin1Char('_')) {
            m_state = Dcs;
        } else {
            if (ch == QLatin1Char('7'))
                m_screen->saveCursor();
            else if (ch == QLatin1Char('8'))
                m_screen->restoreCursor();
            else if (ch == QLatin1Char('D'))
                m_screen->newline();
            else if (ch == QLatin1Char('E')) {
                m_screen->carriageReturn();
                m_screen->newline();
            } else if (ch == QLatin1Char('M'))
                m_screen->reverseIndex();
            else if (ch == QLatin1Char('c'))
                m_screen->reset();
            m_state = Normal;
        }
        return;

    case Csi:
        if (ch.unicode() >= 0x40 && ch.unicode() <= 0x7e) {
            dispatchCsi(ch);
            m_state = Normal;
        } else if (ch.unicode() >= 0x20 && ch.unicode() <= 0x3f) {
            if (m_csi.size() < 64)
                m_csi.append(ch);
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

    case Dcs:
        if (ch == QLatin1Char('\a'))
            m_state = Normal;
        else if (ch == QLatin1Char('\x1b'))
            m_state = DcsEscape;
        return;

    case DcsEscape:
        m_state = (ch == QLatin1Char('\\')) ? Normal : Dcs;
        return;
    }
}

void VtParser::dispatchCsi(QChar finalChar)
{
    QString paramsText = m_csi;
    bool dec = paramsText.startsWith(QLatin1Char('?'));
    if (dec || paramsText.startsWith(QLatin1Char('$')) || paramsText.startsWith(QLatin1Char('!')))
        paramsText.remove(0, 1);

    QStringList parts = paramsText.split(QLatin1Char(';'));
    auto param = [&parts](int index, int defaultValue) {
        if (index >= parts.size() || parts.at(index).isEmpty())
            return defaultValue;
        bool ok = false;
        const int value = parts.at(index).toInt(&ok);
        return ok ? value : defaultValue;
    };

    switch (finalChar.unicode()) {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'G':
        m_screen->moveCursor(static_cast<char>(finalChar.unicode()), param(0, 1));
        break;
    case 'H':
    case 'f':
        m_screen->moveCursor('H', param(0, 1), param(1, 1));
        break;
    case 'd':
        m_screen->moveCursor('d', param(0, 1));
        break;
    case 'J':
    case 'K':
    case 'X':
        m_screen->erase(static_cast<char>(finalChar.unicode()), param(0, 0));
        break;
    case 'L':
    case 'M':
    case 'P':
    case '@':
        m_screen->insertDelete(static_cast<char>(finalChar.unicode()), param(0, 1));
        break;
    case 'S':
    case 'T':
        m_screen->scroll(static_cast<char>(finalChar.unicode()), param(0, 1));
        break;
    case 'r':
        m_screen->setScrollRegion(param(0, 1), param(1, m_screen->rows()));
        break;
    case 's':
        m_screen->saveCursor();
        break;
    case 'u':
        m_screen->restoreCursor();
        break;
    case 'h':
    case 'l':
        for (int i = 0; i < parts.size(); ++i) {
            const int mode = param(i, 0);
            if (finalChar == QLatin1Char('h'))
                m_screen->setMode(mode, dec);
            else
                m_screen->resetMode(mode, dec);
        }
        break;
    case 'm':
        m_screen->selectGraphicRendition(paramsText.isEmpty() ? QStringLiteral("0") : paramsText);
        break;
    case 'b':
        m_screen->repeatLast(param(0, 1));
        break;
    default:
        break;
    }
}
