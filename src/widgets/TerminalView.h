#pragma once

// 增量行级重画（纯工程优化，不改视觉行为）：数据更新只对脏行 y 范围做局部 update()，
// paintEvent 绘制逻辑不变（裁剪区自然限制重画量）。
#include <QAbstractScrollArea>
#include <QEvent>
#include <QColor>
#include <QFont>
#include <QHash>
#include <QPoint>
#include <QPointer>
#include <QRect>
#include <QScrollBar>
#include <QSizeF>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <QVariant>
#include <QVector>

#include "MuxDesktop.h"

class Session;
class QContextMenuEvent;
class QKeyEvent;
class QMouseEvent;
class QPaintEvent;
class QResizeEvent;
class ScreenModel;
class Tmux;
class VtParser;
class MuxDesktop;

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

    // tmux control 模式（P7a：模型+解析+命令面；GUI 映射 MuxDesktop 属 P7b 挂账）。
    // R44：启用判定=VT 输出流通知行特征命中（0x7e9a32 泵，0x878fee 通知名 QHash），
    // 非 session 参数判定；本地/SSH 同泵（SSH 输出走同一 Session::output 路径）。
    void enableTmuxMode();
    Tmux *tmux() const { return m_tmux; }

    // quickbar "Send Text" 命令（0x56d890）：文本直接写入会话
    void sendText(const QString &text);

    // ── P7b tmux pane 视图（0x8de1a8 内嵌 TerminalWidget 语义：无会话独立缓冲）──
    // 无会话建屏（attachSession 屏建段同款缺省色/滚回；pane 视图初始化用）
    void ensureScreenModel(int cols, int rows);
    // ScreenModel::resizeScreen(cols/rows 参数序对齐视图面；pane 模型 w/h 随动)
    void resizeScreen(int cols, int rows);
    // screenCaptured 整缓冲替换：\r\n 拆行重建满行（溢出自然沉 scrollback）
    void loadScreen(const QStringList &lines);
    // tmux 输出回灌（MuxDesktop feedPaneView 落点）：VT 直喂+重绘
    void feedVtData(const QByteArray &data);
    // cell 像素度量（MuxDesktop resize-pane 计数换算）；paneId 挂靠（pane 命令目标）
    QSizeF cellSize() const { return QSizeF(m_cellW, m_cellH); }
    int paneId() const { return m_paneId; }
    void setPaneId(int id) { m_paneId = id; }
    // P7b：tmux 桌面（attach 幂等守卫 + 断言面；0x8de3e8 桌面指针字段语义）
    MuxDesktop *muxDesktop() const { return m_muxDesktop.data(); }
    void setMuxDesktop(MuxDesktop *desktop) { m_muxDesktop = desktop; }
    // 活动屏纯文本（测试断言用）
    QString plainText() const;

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

    // ═══ R52 View Popup 动作面（wind.actions script 桥已逆明子集；MainWindow::runActionScript
    // 调用。原版走 window.activeText.* JS 面——骨架宿主层等价直调）═══
    void copySelectionForScript() { copySelection(); }
    void pasteClipboardForScript() { pasteClipboard(); }
    // selectAll（0xa3e5ca 面）：全活动屏+滚回选区（原版 text.selectAll 全文档）
    void selectAllForScript();
    // clearScreen（Terminal.ClearScreen state=!isAltScreen 守卫挂账——骨架无 alt screen 概念）
    void clearScreenForScript();
    // reset（Terminal.ClearScreenAndScrollback/ClearScrollback：ScreenModel::reset 清滚回+屏）
    void resetForScript();

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
    // P7b：tmux 模式进出（MainWindow 挂载/恢复 MuxDesktop 接线点，0x8d9be0 链）
    void tmuxModeEntered();
    void tmuxModeExited();
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
    // 增量行级重画（纯工程优化）：ScreenModel 脏行集 → 视口局部 update()
    void updateDirtyRegion();
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

    // R44 tmux 启用检测（0x7e9a32 输出泵逐行通知名匹配）：data 累积按 \n 切行，
    // 通知行前缀命中→true（命中前缓冲经 m_tmuxDetectBuf 交还调用方喂 Tmux）
    bool detectTmuxControl(const QByteArray &data);

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
    // tmux control 检测状态（R44 0x7e9a32 输出泵）：跨块行残余/命中前缓冲
    QByteArray m_pending;
    QByteArray m_tmuxDetectBuf;
    bool m_tmuxDetected = false;
    Tmux *m_tmux = nullptr; // tmux control 模式挂载（0x7e9a06 +0x188）
    // P7b attach 守卫（0x8de3e8 同位语义：TerminalWidget 桌面指针字段）：
    // desktop destroyed→自动清零（QPointer），重复 attach 幂等
    QPointer<MuxDesktop> m_muxDesktop;
    int m_paneId = -1;      // P7b：tmux pane 目标（pane 视图用，非 tmux 挂 -1）
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
