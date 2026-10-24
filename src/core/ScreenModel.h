#pragma once

#include <QColor>
#include <QSet>
#include <QString>
#include <QVector>

struct Cell
{
    QChar ch = QLatin1Char(' ');
    QColor fg;
    QColor bg;
    bool bold = false;
    bool underline = false;
    bool reverse = false;
};

class ScreenModel
{
public:
    ScreenModel(int rows, int cols,
                const QColor &fg = QColor(QStringLiteral("#e3e3dd")),
                const QColor &bg = QColor(QStringLiteral("#1c1c1c")));

    int rows() const { return m_rows; }
    int cols() const { return m_cols; }
    const Cell &cellAt(int row, int col) const;
    int cursorX() const { return m_cursorX; }
    int cursorY() const { return m_cursorY; }
    // 滚动回看保存带格式快照——原版滚回保留原色（不重刷历史行颜色）
    const QList<QVector<Cell>> &scrollback() const { return m_scrollback; }
    bool cursorVisible() const { return m_cursorVisible; }
    bool alternateScreen() const { return m_alternate; }
    bool bracketedPaste() const { return m_bracketedPaste; }

    void putChar(QChar ch);
    void printText(const QString &text);
    void newline();
    void carriageReturn();
    void backspace();
    void tab();
    void clearScreen();
    void reset();

    void moveCursor(char op, int n1, int n2 = 1);
    void erase(char op, int n);
    void insertDelete(char op, int n);
    void scroll(char op, int n);
    void reverseIndex();
    void setScrollRegion(int top, int bottom);

    void setMode(int mode, bool dec = false);
    void resetMode(int mode, bool dec = false);
    // DEC 私有模式查询（DECCKM=1 应用光标——键盘序列形态的键面依据）
    bool mode(int mode) const { return m_modes.contains(mode); }
    void selectGraphicRendition(const QString &params);
    void saveCursor();
    void restoreCursor();
    void repeatLast(int n);

    // 尺寸协商（TerminalView applyResize）：行/列扩缩+光标夹取+滚动区重置；
    // 主屏缩行时溢出行沉入 scrollback（对齐原版滚回=文档历史行语义）
    void resizeScreen(int rows, int cols);

private:
    void scrollUp(int n);
    void scrollDown(int n);
    void blankRow(int row);
    void blankCell(Cell &cell) const;
    QVector<Cell> rowCells(int row) const;
    void clampCursor();

    int m_rows;
    int m_cols;
    QVector<QVector<Cell>> m_cells;

    int m_cursorX = 0;
    int m_cursorY = 0;
    int m_top = 0;
    int m_bottom;
    int m_savedX = 0;
    int m_savedY = 0;

    QColor m_defaultFg;
    QColor m_defaultBg;
    QColor m_fg;
    QColor m_bg;
    bool m_bold = false;
    bool m_underline = false;
    bool m_reverse = false;
    QColor m_savedFg;
    QColor m_savedBg;
    bool m_savedBold = false;
    bool m_savedUnderline = false;
    bool m_savedReverse = false;

    bool m_cursorVisible = true;
    bool m_alternate = false;
    bool m_bracketedPaste = false;
    QSet<int> m_modes;

    QVector<QVector<Cell>> m_mainCells;
    int m_mainCursorX = 0;
    int m_mainCursorY = 0;

    QList<QVector<Cell>> m_scrollback;
    QChar m_lastChar;
};
