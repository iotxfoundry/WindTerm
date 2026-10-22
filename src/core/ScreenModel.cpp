#include "ScreenModel.h"

#include <QStringList>

#include "SchemeManager.h"

namespace {

// scheme.theme 的 ansi 色；未加载或缺失时回退到 VGA 调色板
QColor ansiColor(const char *name, const char *fallback)
{
    const QColor color = SchemeManager::instance().color(QLatin1String(name));
    return color.isValid() ? color : QColor(QLatin1String(fallback));
}

QColor color256(int index)
{
    static const QColor base[16] = {
        ansiColor("terminal.ansiBlack", "#000000"),
        ansiColor("terminal.ansiRed", "#800000"),
        ansiColor("terminal.ansiGreen", "#008000"),
        ansiColor("terminal.ansiYellow", "#808000"),
        ansiColor("terminal.ansiBlue", "#000080"),
        ansiColor("terminal.ansiMagenta", "#800080"),
        ansiColor("terminal.ansiCyan", "#008080"),
        ansiColor("terminal.ansiWhite", "#c0c0c0"),
        ansiColor("terminal.ansiBrightBlack", "#808080"),
        ansiColor("terminal.ansiBrightRed", "#ff0000"),
        ansiColor("terminal.ansiBrightGreen", "#00ff00"),
        ansiColor("terminal.ansiBrightYellow", "#ffff00"),
        ansiColor("terminal.ansiBrightBlue", "#0000ff"),
        ansiColor("terminal.ansiBrightMagenta", "#ff00ff"),
        ansiColor("terminal.ansiBrightCyan", "#00ffff"),
        ansiColor("terminal.ansiBrightWhite", "#ffffff")
    };

    if (index < 0)
        return QColor();
    if (index < 16)
        return base[index];
    if (index < 232) {
        const int cube = index - 16;
        const int r = cube / 36;
        const int g = (cube % 36) / 6;
        const int b = cube % 6;
        return QColor(r * 51, g * 51, b * 51);
    }
    if (index < 256) {
        const int level = 8 + (index - 232) * 10;
        return QColor(level, level, level);
    }
    return QColor();
}

int paramAt(const QStringList &parts, int index, int defaultValue)
{
    if (index >= parts.size() || parts.at(index).isEmpty())
        return defaultValue;
    bool ok = false;
    const int value = parts.at(index).toInt(&ok);
    return ok ? value : defaultValue;
}

} // namespace

ScreenModel::ScreenModel(int rows, int cols, const QColor &fg, const QColor &bg)
    : m_rows(qMax(1, rows))
    , m_cols(qMax(1, cols))
    , m_bottom(m_rows - 1)
    , m_defaultFg(fg)
    , m_defaultBg(bg)
    , m_fg(fg)
    , m_bg(bg)
    , m_savedFg(fg)
    , m_savedBg(bg)
{
    Cell blank;
    blank.ch = QLatin1Char(' ');
    blank.fg = m_defaultFg;
    blank.bg = m_defaultBg;
    m_cells = QVector<QVector<Cell>>(m_rows, QVector<Cell>(m_cols, blank));
}

const Cell &ScreenModel::cellAt(int row, int col) const
{
    static const Cell empty;
    if (row < 0 || row >= m_rows || col < 0 || col >= m_cols)
        return empty;
    return m_cells.at(row).at(col);
}

void ScreenModel::putChar(QChar ch)
{
    if (m_cursorX >= m_cols) {
        carriageReturn();
        newline();
    }

    Cell &cell = m_cells[m_cursorY][m_cursorX];
    cell.ch = ch;
    cell.fg = m_fg;
    cell.bg = m_bg;
    cell.bold = m_bold;
    cell.underline = m_underline;
    cell.reverse = m_reverse;

    m_lastChar = ch;
    ++m_cursorX;
}

void ScreenModel::printText(const QString &text)
{
    for (const QChar ch : text)
        putChar(ch);
}

void ScreenModel::newline()
{
    if (m_cursorY == m_bottom)
        scrollUp(1);
    else if (m_cursorY < m_rows - 1)
        ++m_cursorY;
}

void ScreenModel::carriageReturn()
{
    m_cursorX = 0;
}

void ScreenModel::backspace()
{
    if (m_cursorX > 0)
        --m_cursorX;
}

void ScreenModel::tab()
{
    m_cursorX = qMin(m_cols - 1, ((m_cursorX / 8) + 1) * 8);
}

void ScreenModel::clearScreen()
{
    for (int row = 0; row < m_rows; ++row)
        blankRow(row);
    m_cursorX = 0;
    m_cursorY = 0;
}

void ScreenModel::reset()
{
    clearScreen();
    m_top = 0;
    m_bottom = m_rows - 1;
    m_fg = m_defaultFg;
    m_bg = m_defaultBg;
    m_bold = false;
    m_underline = false;
    m_reverse = false;
    m_cursorVisible = true;
    m_alternate = false;
    m_bracketedPaste = false;
    m_modes.clear();
    m_scrollback.clear();
    m_lastChar = QChar();
}

void ScreenModel::moveCursor(char op, int n1, int n2)
{
    const int n = qMax(1, n1);
    switch (op) {
    case 'A': m_cursorY = qMax(m_top, m_cursorY - n); break;
    case 'B': m_cursorY = qMin(m_bottom, m_cursorY + n); break;
    case 'C': m_cursorX = qMin(m_cols - 1, m_cursorX + n); break;
    case 'D': m_cursorX = qMax(0, m_cursorX - n); break;
    case 'E':
        m_cursorY = qMin(m_bottom, m_cursorY + n);
        m_cursorX = 0;
        break;
    case 'F':
        m_cursorY = qMax(m_top, m_cursorY - n);
        m_cursorX = 0;
        break;
    case 'G': m_cursorX = qBound(0, n - 1, m_cols - 1); break;
    case 'd': m_cursorY = qBound(0, n - 1, m_rows - 1); break;
    case 'H':
    case 'f':
        m_cursorY = qBound(0, n - 1, m_rows - 1);
        m_cursorX = qBound(0, qMax(1, n2) - 1, m_cols - 1);
        break;
    default:
        break;
    }
    clampCursor();
}

void ScreenModel::erase(char op, int n)
{
    if (op == QLatin1Char('J')) {
        if (n == 0) {
            for (int x = m_cursorX; x < m_cols; ++x)
                blankCell(m_cells[m_cursorY][x]);
            for (int row = m_cursorY + 1; row < m_rows; ++row)
                blankRow(row);
        } else if (n == 1) {
            for (int row = 0; row < m_cursorY; ++row)
                blankRow(row);
            for (int x = 0; x <= m_cursorX && x < m_cols; ++x)
                blankCell(m_cells[m_cursorY][x]);
        } else if (n == 2) {
            for (int row = 0; row < m_rows; ++row)
                blankRow(row);
        } else if (n == 3) {
            m_scrollback.clear();
        }
    } else if (op == QLatin1Char('K')) {
        if (n == 0) {
            for (int x = m_cursorX; x < m_cols; ++x)
                blankCell(m_cells[m_cursorY][x]);
        } else if (n == 1) {
            for (int x = 0; x <= m_cursorX && x < m_cols; ++x)
                blankCell(m_cells[m_cursorY][x]);
        } else if (n == 2) {
            blankRow(m_cursorY);
        }
    } else if (op == QLatin1Char('X')) {
        const int count = qMax(1, n);
        for (int x = m_cursorX; x < m_cursorX + count && x < m_cols; ++x)
            blankCell(m_cells[m_cursorY][x]);
    }
}

void ScreenModel::insertDelete(char op, int n)
{
    const int count = qBound(1, n, m_rows);
    switch (op) {
    case 'L':
        if (m_cursorY >= m_top && m_cursorY <= m_bottom) {
            for (int i = 0; i < count; ++i) {
                m_cells.removeAt(m_bottom);
                Cell blank;
                blank.fg = m_defaultFg;
                blank.bg = m_defaultBg;
                m_cells.insert(m_cursorY, QVector<Cell>(m_cols, blank));
            }
        }
        break;
    case 'M':
        if (m_cursorY >= m_top && m_cursorY <= m_bottom) {
            for (int i = 0; i < count; ++i) {
                m_cells.removeAt(m_cursorY);
                Cell blank;
                blank.fg = m_defaultFg;
                blank.bg = m_defaultBg;
                m_cells.insert(m_bottom, QVector<Cell>(m_cols, blank));
            }
        }
        break;
    case 'P': {
        const int chars = qBound(1, n, m_cols);
        for (int x = m_cursorX; x < m_cols; ++x) {
            if (x + chars < m_cols)
                m_cells[m_cursorY][x] = m_cells[m_cursorY][x + chars];
            else
                blankCell(m_cells[m_cursorY][x]);
        }
        break;
    }
    case '@': {
        const int chars = qBound(1, n, m_cols);
        for (int x = m_cols - 1; x >= m_cursorX; --x) {
            if (x - chars >= m_cursorX)
                m_cells[m_cursorY][x] = m_cells[m_cursorY][x - chars];
            else
                blankCell(m_cells[m_cursorY][x]);
        }
        break;
    }
    default:
        break;
    }
}

void ScreenModel::scroll(char op, int n)
{
    if (op == QLatin1Char('S'))
        scrollUp(qMax(1, n));
    else if (op == QLatin1Char('T'))
        scrollDown(qMax(1, n));
}

void ScreenModel::reverseIndex()
{
    if (m_cursorY == m_top)
        scrollDown(1);
    else if (m_cursorY > 0)
        --m_cursorY;
}

void ScreenModel::setScrollRegion(int top, int bottom)
{
    const int t = qBound(1, top, m_rows) - 1;
    const int b = qBound(1, bottom, m_rows) - 1;
    if (t < b) {
        m_top = t;
        m_bottom = b;
        m_cursorX = 0;
        m_cursorY = m_top;
    }
}

void ScreenModel::setMode(int mode, bool dec)
{
    if (!dec) {
        m_modes.insert(mode);
        return;
    }

    if (mode == 25) {
        m_cursorVisible = true;
    } else if (mode == 1049) {
        if (!m_alternate) {
            m_mainCells = m_cells;
            m_mainCursorX = m_cursorX;
            m_mainCursorY = m_cursorY;
            m_alternate = true;
            clearScreen();
        }
    } else if (mode == 2004) {
        m_bracketedPaste = true;
    } else {
        m_modes.insert(mode);
    }
}

void ScreenModel::resetMode(int mode, bool dec)
{
    if (!dec) {
        m_modes.remove(mode);
        return;
    }

    if (mode == 25) {
        m_cursorVisible = false;
    } else if (mode == 1049) {
        if (m_alternate) {
            m_cells = m_mainCells;
            m_cursorX = m_mainCursorX;
            m_cursorY = m_mainCursorY;
            m_alternate = false;
        }
    } else if (mode == 2004) {
        m_bracketedPaste = false;
    } else {
        m_modes.remove(mode);
    }
}

void ScreenModel::selectGraphicRendition(const QString &params)
{
    const QStringList parts = params.split(QLatin1Char(';'));
    for (int i = 0; i < parts.size(); ++i) {
        const int code = paramAt(parts, i, 0);
        if (code == 0) {
            m_fg = m_defaultFg;
            m_bg = m_defaultBg;
            m_bold = false;
            m_underline = false;
            m_reverse = false;
        } else if (code == 1) {
            m_bold = true;
        } else if (code == 4) {
            m_underline = true;
        } else if (code == 7) {
            m_reverse = true;
        } else if (code == 22) {
            m_bold = false;
        } else if (code == 24) {
            m_underline = false;
        } else if (code == 27) {
            m_reverse = false;
        } else if (code >= 30 && code <= 37) {
            m_fg = color256(code - 30);
        } else if (code == 39) {
            m_fg = m_defaultFg;
        } else if (code >= 40 && code <= 47) {
            m_bg = color256(code - 40);
        } else if (code == 49) {
            m_bg = m_defaultBg;
        } else if (code >= 90 && code <= 97) {
            m_fg = color256(code - 90 + 8);
        } else if (code >= 100 && code <= 107) {
            m_bg = color256(code - 100 + 8);
        } else if (code == 38 || code == 48) {
            QColor color;
            if (i + 1 < parts.size() && parts.at(i + 1) == QStringLiteral("5")
                && i + 2 < parts.size()) {
                color = color256(parts.at(i + 2).toInt());
                i += 2;
            } else if (i + 1 < parts.size() && parts.at(i + 1) == QStringLiteral("2")
                       && i + 4 < parts.size()) {
                color = QColor(parts.at(i + 2).toInt(), parts.at(i + 3).toInt(), parts.at(i + 4).toInt());
                i += 4;
            }
            if (color.isValid()) {
                if (code == 38)
                    m_fg = color;
                else
                    m_bg = color;
            }
        }
    }
}

void ScreenModel::saveCursor()
{
    m_savedX = m_cursorX;
    m_savedY = m_cursorY;
    m_savedFg = m_fg;
    m_savedBg = m_bg;
    m_savedBold = m_bold;
    m_savedUnderline = m_underline;
    m_savedReverse = m_reverse;
}

void ScreenModel::restoreCursor()
{
    m_cursorX = m_savedX;
    m_cursorY = m_savedY;
    m_fg = m_savedFg;
    m_bg = m_savedBg;
    m_bold = m_savedBold;
    m_underline = m_savedUnderline;
    m_reverse = m_savedReverse;
    clampCursor();
}

void ScreenModel::repeatLast(int n)
{
    if (m_lastChar.isNull())
        return;
    const QChar ch = m_lastChar;
    for (int i = 0; i < qMax(1, n); ++i)
        putChar(ch);
}

void ScreenModel::scrollUp(int n)
{
    for (int i = 0; i < n; ++i) {
        if (m_top == 0) {
            m_scrollback.append(rowText(0));
            if (m_scrollback.size() > 1000)
                m_scrollback.removeFirst();
        }
        for (int row = m_top; row < m_bottom; ++row)
            m_cells[row] = m_cells[row + 1];
        blankRow(m_bottom);
    }
    clampCursor();
}

void ScreenModel::scrollDown(int n)
{
    for (int i = 0; i < n; ++i) {
        for (int row = m_bottom; row > m_top; --row)
            m_cells[row] = m_cells[row - 1];
        blankRow(m_top);
    }
    clampCursor();
}

void ScreenModel::blankRow(int row)
{
    for (int x = 0; x < m_cols; ++x)
        blankCell(m_cells[row][x]);
}

void ScreenModel::blankCell(Cell &cell) const
{
    cell.ch = QLatin1Char(' ');
    cell.fg = m_defaultFg;
    cell.bg = m_defaultBg;
    cell.bold = false;
    cell.underline = false;
    cell.reverse = false;
}

QString ScreenModel::rowText(int row) const
{
    QString text;
    text.reserve(m_cols);
    for (int x = 0; x < m_cols; ++x)
        text.append(m_cells.at(row).at(x).ch);
    while (text.endsWith(QLatin1Char(' ')))
        text.chop(1);
    return text;
}

void ScreenModel::clampCursor()
{
    m_cursorX = qBound(0, m_cursorX, m_cols - 1);
    m_cursorY = qBound(0, m_cursorY, m_rows - 1);
}
