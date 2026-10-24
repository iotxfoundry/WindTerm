#pragma once

#include <QAbstractScrollArea>
#include <QEvent>
#include <QColor>
#include <QFont>
#include <QHash>
#include <QPoint>
#include <QRect>
#include <QScrollBar>
#include <QString>
#include <QTimer>
#include <QVariant>
#include <QVector>

class Session;
class QContextMenuEvent;
class QKeyEvent;
class QMouseEvent;
class QPaintEvent;
class QResizeEvent;
class ScreenModel;
class VtParser;

// P4 find 选项（SearchPane 选项表 0x74d90c 子集；searchIncremental/searchContext 只影响
// 触发时机/挂账，不进匹配引擎）
struct FindOptions
{
    bool regex = false;         // matchRegex
    bool caseSensitive = false; // matchCase
    bool wholeWord = false;     // matchWholeWord
    bool wrap = true;           // searchWrap（回绕循环）
    bool fromSelection = false; // searchSelection（以选区为 pattern）
};

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

    // ═══ P4 终端搜索/高亮（深逆 0x74efe6 族；B 节 find API——函数体未 dump，
    // 按动作脚本面+SearchPane 执行链语义实现+挂账注明）═══

    // 0x75cb7c 槽族语义：useSelection=true→以当前选区文本为 pattern（wind.actions
    // "window.activeText.findNext(true)"）；在滚回+活动屏全文本中匹配，命中→设选区+
    // 滚动定位+状态栏消息，未命中→"未找到"（wrap on 回绕循环）
    void findNext(bool useSelection = false);
    void findPrevious(bool useSelection = false);
    // SearchPane pattern/options 传入（原版 pane 直读视图属性；骨架 setter 单向传递）
    void setFindPattern(const QString &pattern) { m_findPattern = pattern; }
    void setFindOptions(const FindOptions &options) { m_findOptions = options; }

    // 0x75c7/0x75cb 槽语义（方法体未 dump 挂账）：start/end 为全局文本位置——实现取
    // (line,colStart)/(line,colEnd) 对编码：line*10000+col（cols<10000 恒成立，列超界夹取）。
    // 颜色名映射 QColor（Red/Orange/Yellow/Green/Royalblue/Cyan/Purple）
    void setHighlightRange(int start, int end, const QString &colorName);
    void clearHighlightRange(int pos);

    // 当前选区文本（HighlightTextBar toggled 取选区用）
    QString selectionText() const { return selectedText(); }
    bool hasSel() const { return hasSelection(); }

    // ═══ palette JS API 面（*.palette 一手证据：goto-line/calculator 用到的 text.* 契约）═══
    // 行数（scrollback+屏行——原版 text.lineCount 契约：全文行数）
    Q_INVOKABLE int lineCount() const;
    // 跳行（0 基；goto-line commitEvent `text.gotoLine(line - 1)`——caret 移动+滚动定位）
    Q_INVOKABLE void gotoLine(int line);
    // 滚动位置（行语义：goto-line.palette `text.scrollTop = line - 1`——JS 全部按行读写）
    Q_PROPERTY(int scrollTop READ scrollTop WRITE setScrollTop)
    Q_PROPERTY(int scrollLeft READ scrollLeft WRITE setScrollLeft)
    int scrollTop() const { return verticalScrollBar()->value(); }
    void setScrollTop(int line) { verticalScrollBar()->setValue(qBound(0, line, verticalScrollBar()->maximum())); }
    int scrollLeft() const { return horizontalScrollBar()->value(); }
    void setScrollLeft(int px) { horizontalScrollBar()->setValue(px); }
    // 可视行数（goto-line `text.screenLineCapacity`——scrollTop 定位取半高）
    Q_INVOKABLE int screenLineCapacity() const { return windowRows(); }
    // 选区起始位置（goto-line 相对跳转基准 `text.lineFromPosition(text.selectionStartP())`——
    // 骨架无位置编解码，映射 caret 行：无选区时 selectionStartP 即 caret 位置，语义等效挂账注明）
    Q_INVOKABLE int selectionStartP() const;
    Q_INVOKABLE int lineFromPosition(int pos) const { Q_UNUSED(pos); return caretLine(); }
    // 寄存器（goto-line setRegister/getRegister/removeRegister——滚动位置暂存）
    Q_INVOKABLE void setRegister(const QString &name, const QVariantList &value) { m_registers.insert(name, value); }
    Q_INVOKABLE QVariantList getRegister(const QString &name) const { return m_registers.value(name).toList(); }
    Q_INVOKABLE void removeRegister(const QString &name) { m_registers.remove(name); }
    // HighlightTextBar：当前选区整体以命名色高亮（选区起止单行/跨行逐行拆分在实现内）
    void highlightSelection(const QString &colorName);
    // 高亮span直查（测试断言用）
    int highlightCount() const { return m_highlights.size(); }
    // 选区规范化锚点（测试断言用：s0=(min line,min col)）
    QPoint selectionAnchor() const;
    void clearSelectionForTest() { m_selAnchor = m_selEnd = QPoint(-1, -1); viewport()->update(); }
    // 命中时状态栏消息由 TerminalView 经宿主链走 MainWindow::statusBar；骨架提供回调注入
    // （原版直调 kit 状态栏 0x74f5ac；避免 widgets 层反向依赖 MainWindow）
    static void (*statusMessageHandler)(TerminalView *, const QString &, int timeoutMs);

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
    void wheelEvent(QWheelEvent *event) override;
    void sendMouseEvent(QEvent::Type type, Qt::MouseButton button, Qt::MouseButtons buttons,
                        Qt::KeyboardModifiers mods, const QPoint &pos);
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
    // 全文本线性位置 ↔ (line,col)（滚回+活动屏；pos=line*10000+col）
    QPair<int, int> posToCell(int pos) const;
    // 在 [fromLine+fromCol, …] 起找下一个匹配（含 wrap）；命中返回 (line,colStart)，colEnd 填 len
    bool matchAt(int line, int col, int *colEnd) const;
    bool findImpl(bool backward, bool useSelection);

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
    QPoint m_lastMouseCell{-1, -1}; // 鼠标上报同格去重(0x7ebdfc)
    bool m_selecting = false;

    Session *m_session;
    ScreenModel *m_screen;
    VtParser *m_parser;
    int m_keyMode = 8; // King.RemoteMode（0xccbc40：RemoteMode=8；默认远程）
    int m_windowRows = 24;
    int m_windowColumns = 80;

    // P4 find/高亮状态
    QString m_findPattern;
    FindOptions m_findOptions;
    struct HighlightSpan { int line; int colStart; int colEnd; QColor color; };
    QVector<HighlightSpan> m_highlights;
    QHash<QString, QVariant> m_registers; // palette JS 寄存器（goto-line 滚动暂存）
};
