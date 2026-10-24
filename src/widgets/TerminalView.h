#pragma once

#include <QWidget>

class Session;
class QContextMenuEvent;
class QPlainTextEdit;
class ScreenModel;
class VtParser;

class TerminalView : public QWidget
{
    Q_OBJECT
    // statusbar.config JS 面（0x005a3156 runInit 依赖 7 项）：
    // keyMode=本地/远程（King.LocalMode=16/King.RemoteMode=8，0xccbc40 KeyMode 枚举）；
    // shortcut: 真实 keyMode 存储未接（keymap 焦点过滤 0x8cb962 只读未回写），setter 仅置位
    Q_PROPERTY(int keyMode READ keyMode WRITE setKeyMode NOTIFY keyModeChanged)
    // 终端字符矩阵行列（原版 termview 面名）；骨架 24x80 定格，resizeEvent 发信号
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
    bool eventFilter(QObject *obj, QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void appendSystemMessage(const QString &text);
    void renderScreen();

    QPlainTextEdit *m_gutter;
    QPlainTextEdit *m_main;
    Session *m_session;
    ScreenModel *m_screen;
    VtParser *m_parser;
    int m_keyMode = 8; // King.RemoteMode（0xccbc40：RemoteMode=8；默认远程）
    int m_windowRows = 24;
    int m_windowColumns = 80;
};
