#pragma once

#include <QByteArray>
#include <QList>
#include <QMap>
#include <QObject>
#include <QRegularExpression>
#include <QString>
#include <QTimer>
#include <functional>

// P7a tmux control 模式模型+通知解析+命令下发（深逆 0x878fee 族照搬）。
// 纯 QObject 模型无 GUI；挂 TerminalView（tmux 会话启用时，0x7e9a06 链）。
// GUI 映射（MuxDesktop/MuxPaneGroup 页/分屏树 0x8d9786）属 P7b 挂账。
class Tmux : public QObject
{
    Q_OBJECT

public:
    explicit Tmux(QObject *parent = nullptr);

    // pane 模型（0x00879d62 字段集；flags bit0 active·bit1 alt·bit2 sync）
    struct Pane
    {
        int id = -1;
        QString title;
        QString cwd;
        quint8 flags = 0;
        int cursorX = 0;
        int cursorY = 0;
        int w = 0;
        int h = 0;
        int history = 0;
        int pid = 0;
        int sessionId = -1;
        int windowId = -1;
        int modes = 0; // DECSET 位（cursor 25/insert 4/keypadCursor 1/keypad 66/mouse 1000-1006/origin 6/wrap 7）
    };
    // window 模型（0x0087b76a 字段集）
    struct Window
    {
        QString rawFlags;      // window_raw_flags（*=active Z=zoomed）
        bool attached = false; // session_id == 本客户端会话
        int id = -1;
        int idx = -1;
        int activePaneId = -1;
        int sessionId = -1;
        QString name;
        QString layout;
        QString visibleLayout;
        QString sessionName;
    };

    // 启用（0x7e9a06 落模型侧段）：排队初始查询 version/list-panes/list-windows
    void start();
    // VT 层喂入口（0x7e9a32 语义：按 \n 切行去 \r→parseLine；行不完整回缓冲；
    // %exit 正则 `^%exit( reason)?\r?\n\033\\` 整体匹配置换行级切分）
    void feedData(const QByteArray &data);
    // 20-token 分派（0x878fee 返回枚举）：0 未知名%/1 普通行/2 begin/5 end/6 error/
    // 7 exit 起始/8 layout-change/9 output(已路由)/11 挂起中输出/12 行内嵌 %end 尾/13..23 通知族
    int parseLine(const QByteArray &line);

    // 当前显示 pane（0x7e6b64 路由：活动 pane 输出经 vtOutput 直喂 VT，
    // 否则暂存 pendingOut[paneId]；切活动时冲账发 outputCached）
    void setActivePane(int paneId);

    // ═══ 命令下发原语（0x83eaa6 族命令串照抄；写会话 stdin，"\n" 结尾）═══
    void sendCommand(const QString &cmd);              // 直写（外部命令面）
    void newWindow();                                  // 0x83f360
    void splitWindow(int paneId, int dir);             // 0x83eeb2：0 -bh/1 -h/2 -bv/3 -v
    void killPane(int paneId);                         // 0x83f1f0
    void killWindow(int idx);                          // 0x83f2e2（-1 无操作）
    void killSession(const QString &name);             // 0x83f264
    void selectPane(int paneId);                       // 0x83f830
    void selectPaneDirection(int paneId, int dir);     // 0x83ed36：0 -L/1 -R/2 -U/3 -D
    void resizePane(int paneId, int dir, int count);   // 0x83eb50：同上方向，count<1→1
    void swapPaneTarget(int paneId, int dir);          // 0x83f02e：{left-of}/{right-of}/{up-of}/{down-of}
    void swapPane(int a, int b);                       // 0x83f924
    void swapWindow(int a, int b);                     // 0x83fa46
    void selectWindow(int idx);                        // 0x83f8aa
    void attachSession(const QString &name);           // 0x83f12c
    void detachClient();                               // 0x83f1aa
    void renameWindow(int idx, const QString &name);   // 0x83f70e
    void renameSession(const QString &oldName, const QString &newName); // 0x83f666
    void renamePaneTitle(int paneId, const QString &title);             // 0x83f460
    void selectLayout(const QString &name);            // 0x83f7bc
    void resizeClient(int columns, int rows);          // 0x83f3a6：refresh-client -C W,H
    void zoomPane(int paneId, bool zoom);              // 0x83fb6e：resize-pane[ -Z] -t %N
    void setSynchronize(bool on);                      // 0x83fafa
    void clearHistory(int paneId);                     // 0x83fc2c
    void breakPane(int paneId);                        // 0x83eac6

    const QMap<int, Pane> &panes() const { return m_panes; }
    const QMap<int, Window> &windows() const { return m_windows; }
    const QString &version() const { return m_version; }
    const QMap<int, QByteArray> &pendingOut() const { return m_pendingOut; }

    // 输出汇（TerminalView 接会话 stdin；测试接捕获 lambda）
    void setWriter(std::function<void(const QByteArray &)> w) { m_write = std::move(w); }
    // 退出后残余缓冲移交（0x7e9a1e 链：[exited] 屏显后残余直通 VT）
    QByteArray takeBuffer() { QByteArray b = m_buf; m_buf.clear(); return b; }

signals:
    // 12 信号照抄 0x9191c0 族/Tmux meta 表（声明序=信号序 0..11）
    void errorOccurred(const QString &text);   // 0x00919198
    void outputCached(int paneId, const QByteArray &text); // 0x0091929e
    void paneCwdChanged(int paneId, const QString &cwd);   // 0x009192da
    void paneInited(int paneId);               // 0x009191c0
    void screenCaptured(int paneId, bool altScreen, int historySize, const QByteArray &data); // 0x00919316
    void screenResized(int paneId);            // 0x009191f6
    void screenZoomed(int paneId);             // 0x0091922c
    void sessionsChanged(const QStringList &sessionNames, const QString &currentSessionName); // 0x009193c6
    void termAdded(int paneId, const QString &cwd);        // 0x00919262
    void termsRemoved(const QList<int> &paneIds);          // 0x00919372
    void windowsChanged();                     // 0x009193f6（骨架无参；GUI 重读模型，QVariantList 载荷挂账）
    void windowsRemoved(const QList<int> &windowIds);      // 0x0091939c
    // 骨架侧缝（原版 vtable 直喂 VT 无信号）：活动 pane 输出直通
    void vtOutput(const QByteArray &data);
    // %exit 完成帧（0x7e9a1e：宿主销毁 Tmux+屏显 [exited(: reason)]）
    void exited(const QString &reason);

private:
    // 查询命令帧（0x00877564 构造族）：type 0 capture/1 pane-cwd/3 version/4 list-panes/5 list-windows
    struct PendingCommand
    {
        int type = 0;
        int targetId = -1; // -1=全量
        QByteArray payload;
    };

    void queueCommand(int type, int targetId, const QByteArray &payload); // 0x00877c06+0x008778dc 去重
    void flushQueue();                                                    // 0x0087826d：全部写盘+"\n"
    void enqueueFullRefresh();                                            // 0x00877f30：Type4/5(-1)
    void completeFrame(bool endFrame);                                    // 0x0087c44e terminal_parsePromptMeta

    void refreshPanes(const QList<QByteArray> &lines);   // 0x00879d62
    void refreshWindows(const QList<QByteArray> &lines); // 0x0087b76a
    void applyLayoutGeometry(const QString &layout);     // 0x0087ad18 visibleLayout 全局匹配段
    void routeOutput(int paneId, const QByteArray &data); // 0x7e6b64
    void feedVt(const QByteArray &data);                  // vtOutput（空槽=丢弃）

    static QList<QPair<QByteArray, QByteArray>> parseFields(const QByteArray &line);
    static int idValue(const QByteArray &v, char prefix); // 剥 %/$/@ 前缀→int

    QMap<int, Pane> m_panes;
    QMap<int, Window> m_windows;
    QMap<int, QByteArray> m_pendingOut;
    QString m_version;
    int m_sessionId = -1; // 0x00879d62 从 list-panes session_id 回填（+0x34）
    int m_activePaneId = -1;
    bool m_enabled = false;

    // 命令帧状态（0x878fee +0xf0/+0x148/+0x150）
    bool m_frameOpen = false;
    qlonglong m_frameTs = 0;
    int m_frameIdx = 0;
    QByteArray m_endTail;      // "%end <ts> <idx>"
    QByteArray m_errorTail;    // "%error <ts> <idx>"
    QList<QByteArray> m_frameOutput;

    // 命令队列（pending=去重批/flush 后入 sent；帧完成弹 sent 队首分派）
    QList<PendingCommand> m_pending;
    QList<PendingCommand> m_sent;
    QTimer m_flushTimer;

    // 0x0087842e ctor 正则原文照抄
    QRegularExpression m_reBegin{QStringLiteral(R"(^%begin (?<timestamp>\d++) (?<commandIndex>\d++) (?<flags>\d++))")};
    QRegularExpression m_reClientDetached{QStringLiteral(R"(^%client-detached (?<clientName>\S++)$)")};
    QRegularExpression m_reClientSessionChanged{QStringLiteral(R"(^%client-session-changed (?<clientName>\S++) \$(?<sessionId>\d++) (?<sessionName>.++)$)")};
    QRegularExpression m_reEnd{QStringLiteral(R"(^%end (?<timestamp>\d++) (?<commandIndex>\d++) (?<flags>\d++))")};
    QRegularExpression m_reError{QStringLiteral(R"(^%error (?<timestamp>\d++) (?<commandIndex>\d++) (?<flags>\d++))")};
    QRegularExpression m_reExit{QStringLiteral(R"(^%exit( (?<reason>[^\r\n]++)?)?\r?\n\033\\)")};
    QRegularExpression m_reLayoutChange{QStringLiteral(R"(^%layout-change @(?<windowId>\d++) (?<layout>.++)$)")};
    QRegularExpression m_reOutput{QStringLiteral(R"(^%output %(?<paneId>\d++) )")};
    QRegularExpression m_rePaneCwdChanged{QStringLiteral(R"(^pane-cwd-changed pane_id:%(?<paneId>\d++);pane_current_path:(?<paneCwd>[^;]*+);pane_pid:(?<panePid>\d++))")};
    QRegularExpression m_rePaneModeChanged{QStringLiteral(R"(^%pane-mode-changed %(?<paneId>\d++)$)")};
    QRegularExpression m_rePaneRenamed{QStringLiteral(R"(^%pane-renamed %(?<paneId>\d++) '(?<paneTitle>.+?)'$)")};
    QRegularExpression m_reSessionChanged{QStringLiteral(R"(^%session-changed \$(?<sessionId>\d++) (?<sessionName>.++)$)")};
    QRegularExpression m_reSessionRenamed{QStringLiteral(R"(^%session-renamed \$(?<sessionId>\d++) (?<sessionName>.++)$)")};
    QRegularExpression m_reSessionsChanged{QStringLiteral(R"(^%sessions-changed$)")};
    QRegularExpression m_reSessionWindowChanged{QStringLiteral(R"(^%session-window-changed \$(?<sessionId>\d++) @(?<windowId>\d++)$)")};
    QRegularExpression m_reUnlinkedWindowAdd{QStringLiteral(R"(^%unlinked-window-add @(?<windowId>\d++)$)")};
    QRegularExpression m_reUnlinkedWindowClose{QStringLiteral(R"(^%unlinked-window-close @(?<windowId>\d++)$)")};
    QRegularExpression m_reUnlinkedWindowRenamed{QStringLiteral(R"(^%unlinked-window-renamed @(?<windowId>\d++) (?<windowName>.++)$)")};
    QRegularExpression m_reWindowAdd{QStringLiteral(R"(^%window-add @(?<windowId>\d++)$)")};
    QRegularExpression m_reWindowClose{QStringLiteral(R"(^%window-close @(?<windowId>\d++)$)")};
    QRegularExpression m_reWindowPaneChanged{QStringLiteral(R"(^%window-pane-changed @(?<windowId>\d++) %(?<paneId>\d++)$)")};
    QRegularExpression m_reWindowRenamed{QStringLiteral(R"(^%window-renamed @(?<windowId>\d++) (?<windowName>.++)$)")};
    QRegularExpression m_reGeoAnchored{QStringLiteral(R"(^(?<width>\d+)x(?<height>\d++),(?<x>\d++),(?<y>\d++),(?<id>\d++),?)")};
    QRegularExpression m_reGeoGlobal{QStringLiteral(R"((?<width>\d+)x(?<height>\d++),(?<x>\d++),(?<y>\d++),(?<id>\d++),?)")};
    QRegularExpression m_reGeoMark{QStringLiteral(R"(^(?<width>\d+)x(?<height>\d++),(?<x>\d++),(?<y>\d++)(?<mark>[\[\{]))")};
    QRegularExpression m_reWindowListLine{QStringLiteral(R"(@(?<windowId>\d++)\s++(?<windowLayout>\S++)\s++(?<windowVisibleLayout>\S++)\s++(?<windowRawFlags>\S*+)$)")};
    QRegularExpression m_reRefreshClient{QStringLiteral(R"(refresh-client -C (?<columns>\d++),(?<rows>\d++))")};

    QByteArray m_buf; // 行切分残余（0x7e9a32 回填缓冲）
    std::function<void(const QByteArray &)> m_write;
};
