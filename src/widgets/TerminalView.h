#pragma once

#include <QAbstractScrollArea>
#include <QColor>
#include <QFont>
#include <QHash>
#include <QPoint>
#include <QRect>
#include <QString>
#include <QTimer>

class Session;
class QContextMenuEvent;
class QKeyEvent;
class QMouseEvent;
class QPaintEvent;
class QResizeEvent;
class ScreenModel;
class VtParser;

// 原版 TextView 自研自绘引擎的重建（docs/terminal-render-audit.md 修复路线 1+2）：
// QAbstractScrollArea + paintEvent 逐 cell 网格绘制（0xa64cea editor_paint_line_colors 模型），
// cell 度量→rows/cols→Session::resize 尺寸协商（0xa52aa8 horizontalAdvance 缓存）。
class TerminalView : public QAbstractScrollArea
{
    Q_OBJECT
    // statusbar.config JS 面（0x005a3156 runInit 依赖 7 项）：
    // keyMode=本地/远程（King.LocalMode=16/King.RemoteMode=8，0xccbc40 KeyMode 枚举）；
    // shortcut: 真实 keyMode 存储未接（keymap 焦点过滤 0x8cb962 只读未回写），setter 仅置位
    Q_PROPERTY(int keyMode READ keyMode WRITE setKeyMode NOTIFY keyModeChanged)
    // 终端字符矩阵行列（原版 termview 面名）；首次度量前缺省 24x80
    Q_PROPERTY(int windowRows READ windowRows NOTIFY screenSizeChanged)
    Q_PROPERTY(int windowColumns READ windowColumns NOTIFY screenSizeChanged)
    // 光标行/列（ScreenModel cursorX/Y，1 基行=caretLine+1 由 JS 侧处理——config:52
    // 'view.caretLine + 1'）；无光标数据→0 占位
    Q_PROPERTY(int caretLine READ caretLine NOTIFY caretPositionChanged)
    Q_PROPERTY(int caretLineOffset READ caretLineOffset NOTIFY caretPositionChanged)

public:
    explicit TerminalView(const QString &sessionName, QWidget *parent = nullptr);
    ~TerminalView() override;

    void attachSession(Session *session);
    Session *session() const { return m_session; }
    // 会话持久化 uuid（0x8bbab6 url="$<uuid>"；无会话→空串）
    QString sessionUuid() const;

    // quickbar "Send Text" 命令（0x56d890）：文本直接写入会话
    void sendText(const QString &text);

    // 当前活动 view（0x8d9764 焦点终端链骨架等价：focusWidget 上溯；无→nullptr）
    static TerminalView *activeView();

    int keyMode() const { return m_keyMode; }
    void setKeyMode(int mode) { if (mode != m_keyMode) { m_keyMode = mode; emit keyModeChanged(); } }
    int windowRows() const { return m_windowRows; }
    int windowColumns() const { return m_windowColumns; }
    int caretLine() const;
    int caretLineOffset() const;
    // 当前 scheme 名（SchemeManager 当前值）；切换点无→挂账
    Q_INVOKABLE QString scheme() const;

signals:
    // 0x84005a TerminalWidget/0x834f2c TerminalView contextMenuEvent → MainWindow 弹 View Popup
    void contextMenuRequested(const QPoint &globalPos, Qt::KeyboardModifiers mods);
    void keyModeChanged();
    void screenSizeChanged();
    void caretPositionChanged();
    // shortcut: scheme 切换点未接（SchemeManager 单例无 per-view 切换），挂账
    void schemeChanged();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    // 0x84005a/0x834f2c：原版按事件位置 + 修饰键弹 pane 菜单（viewport 事件经
    // QAbstractScrollArea::viewportEvent 转发到本类 contextMenuEvent）
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void applyResize();
    void updateScrollRange();
    void appendSystemMessage(const QString &text);
    // 0xa52aa8 horizontalAdvance 懒填缓存
    qreal advanceOf(QChar ch);
    QColor selectionColor() const;
    // 光标 cell 矩形（viewport 坐标）；不可见/隐藏→无效 QRect
    QRect cursorCellRect() const;
    // block 光标：反色填充整 cell 重画字符（0xa64838 覆盖式）
    void drawBlockCaret(QPainter &p, const QRect &r);
    // viewport 像素 → cell（col, 绝对行=scrollOffset+viewport 行）；无屏→(-1,-1)
    QPoint cellFromPos(const QPoint &viewportPos) const;
    QChar charAtLine(int line, int col) const;
    QString selectedText() const;
    bool hasSelection() const { return m_selAnchor.x() >= 0; }
    void copySelection();
    void pasteClipboard();

    QFont m_font;
    qreal m_cellW = 0.0;
    qreal m_cellH = 0.0;
    QHash<quint32, qreal> m_advanceCache;
    QColor m_defaultFg;
    QColor m_defaultBg;
    QString m_systemMessage;

    // 光标（0xa63550 闪烁 QTimer / 0xa5940a 形态）
    QTimer m_caretTimer;
    QRect m_lastCaretRect;
    bool m_caretOn = true;
    bool m_caretBlink = true;
    int m_caretShape = 0; // text.caretShape：0 block/1 line/2 rectangle/3 underline

    // 选区（0xa3e5ca 3px 拖动阈值/word 语义）：cell 坐标（col, 绝对行），(-1,-1)=无
    QPoint m_selAnchor = QPoint(-1, -1);
    QPoint m_selEnd = QPoint(-1, -1);
    QPoint m_pressPos;
    bool m_selecting = false;

    Session *m_session;
    ScreenModel *m_screen;
    VtParser *m_parser;
    int m_keyMode = 8; // King.RemoteMode（0xccbc40：RemoteMode=8；默认远程）
    int m_windowRows = 24;
    int m_windowColumns = 80;
};
