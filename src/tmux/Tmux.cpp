#include "tmux/Tmux.h"

#include <QSet>

namespace {
// 0x00877564 命令串照抄（27 个 #{var} 原文；reference/full/decomp-part-0027.c:20027）
const char kListPanesFmt[] =
    "list-panes -s -F 'alternate_on:#{alternate_on};cursor_flag:#{cursor_flag};cursor_x:#{cursor_x};"
    "cursor_y:#{cursor_y};history_size:#{history_size};insert_flag:#{insert_flag};"
    "keypad_cursor_flag:#{keypad_cursor_flag};keypad_flag:#{keypad_flag};"
    "mouse_all_flag:#{mouse_all_flag};mouse_any_flag:#{mouse_any_flag};"
    "mouse_button_flag:#{mouse_button_flag};mouse_sgr_flag:#{mouse_sgr_flag};"
    "mouse_standard_flag:#{mouse_standard_flag};mouse_utf8_flag:#{mouse_utf8_flag};"
    "origin_flag:#{origin_flag};pane_active:#{pane_active};pane_current_path:#{pane_current_path};"
    "pane_height:#{pane_height};pane_id:#{pane_id};pane_index:#{pane_index};pane_pid:#{pane_pid};"
    "pane_synchronized:#{pane_synchronized};pane_title:#{pane_title};pane_width:#{pane_width};"
    "session_id:#{session_id};window_id:#{window_id};wrap_flag:#{wrap_flag}'";
// decomp-part-0027.c:20033（8 个 #{var} 原文）
const char kListWindowsFmt[] =
    "list-windows -a -F 'session_id:#{session_id};session_name:#{session_name};window_id:#{window_id};"
    "window_index:#{window_index};window_layout:#{window_layout};window_name:#{window_name};"
    "window_raw_flags:#{window_raw_flags};window_visible_layout:#{window_visible_layout}'";

QByteArray joinLines(const QList<QByteArray> &lines)
{
    QByteArray out;
    for (int i = 0; i < lines.size(); ++i) {
        if (i)
            out += "\r\n";
        out += lines.at(i);
    }
    return out;
}
} // namespace

Tmux::Tmux(QObject *parent)
    : QObject(parent)
{
    // 命令批刷（0x00877c06：队列非空即定时弹出全部写盘）
    m_flushTimer.setSingleShot(true);
    m_flushTimer.setInterval(0);
    connect(&m_flushTimer, &QTimer::timeout, this, &Tmux::flushQueue);
}

void Tmux::start()
{
    if (m_enabled)
        return;
    m_enabled = true;
    // 启用后排队初始查询（0x00877564 构造）：version / list-panes 全量 / list-windows 全量
    queueCommand(3, -1, QByteArrayLiteral("display-message -p 'version:#{version}'"));
    queueCommand(4, -1, QByteArray(kListPanesFmt));
    queueCommand(5, -1, QByteArray(kListWindowsFmt));
}

// ═══ 0x878fee 20-token 分派 ═══

int Tmux::parseLine(const QByteArray &line)
{
    if (m_frameOpen) { // 命令帧挂起中
        const int at = line.indexOf(m_endTail);
        if (at > 0)
            return 12; // 行内嵌 %end 尾（0x0087c832：切左/中——宿主 feedData 处理）
        if (at == 0) { // %end 帧完成（0x0087c44e terminal_parsePromptMeta）
            completeFrame(true);
            return 5;
        }
        if (line.indexOf(m_errorTail) == 0) { // %error 帧完成：errorOccurred(全输出)
            completeFrame(false);
            return 6;
        }
        m_frameOutput.append(line); // 11：追加当前命令输出
        return 11;
    }
    if (!line.startsWith('%'))
        return 1; // 普通行→透传终端
    const int sp = line.indexOf(' ');
    const QByteArray name = line.mid(1, sp > 0 ? sp - 1 : -1);
    // 分派表（0x00878fee 静态 QHash：name→枚举）
    static const QHash<QByteArray, int> table = {
        {"begin", 2},       {"client-detached", 3},   {"client-session-changed", 4},
        {"end", 5},         {"error", 6},             {"exit", 7},
        {"layout-change", 8}, {"output", 9},          {"pane-mode-changed", 10},
        {"session-changed", 13}, {"session-renamed", 14}, {"sessions-changed", 15},
        {"session-window-changed", 16}, {"unlinked-window-add", 17}, {"unlinked-window-close", 18},
        {"unlinked-window-renamed", 19}, {"window-add", 20}, {"window-close", 21},
        {"window-pane-changed", 22}, {"window-renamed", 23},
    };
    const auto it = table.constFind(name);
    if (it == table.constEnd())
        return 0; // 未知名 %→透传（0x7e9a32 case0 并入 case1）
    const int token = it.value();

    switch (token) {
    case 2: { // %begin（0x008795a6）：开帧+拼期望尾
        const auto m = m_reBegin.match(QString::fromLatin1(line));
        if (!m.hasMatch())
            return 2;
        m_frameTs = m.captured("timestamp").toLongLong();
        m_frameIdx = m.captured("commandIndex").toInt();
        m_frameOpen = true;
        m_frameOutput.clear();
        m_endTail = QStringLiteral("%end %1 %2").arg(m_frameTs).arg(m_frameIdx).toUtf8();
        m_errorTail = QStringLiteral("%error %1 %2").arg(m_frameTs).arg(m_frameIdx).toUtf8();
        return 2;
    }
    case 5: // %end/%error 帧完成已在帧挂起分支处理
    case 6:
        return token;
    case 9: { // %output（0x0087728a）：取 paneId→\X 反转义（0x00877128）→路由
        const auto m = m_reOutput.match(QString::fromLatin1(line));
        if (!m.hasMatch())
            return 9;
        const int paneId = m.captured("paneId").toInt();
        const int prefixLen = m.capturedLength() + 1 + QString::number(paneId).size();
        Q_UNUSED(prefixLen);
        // 反转义段：匹配点之后整行（tmux 对 \n 已转义为 \X 形态，行内安全）
        QByteArray data = line.mid(m.capturedLength());
        // \X 四字符→控制字节（0x00877128 原式：c1*'@'+c3+'P'+c2*'\b' 截断=八进制）
        QByteArray out;
        out.reserve(data.size());
        for (int i = 0; i < data.size();) {
            if (data.at(i) == '\\' && i + 3 < data.size()) {
                out += char(data.at(i + 1) * '@' + data.at(i + 3) + 'P' + data.at(i + 2) * '\b');
                i += 4;
            } else {
                out += data.at(i++);
            }
        }
        routeOutput(paneId, out);
        return 9;
    }
    case 8: { // %layout-change（0x0087ad18）
        const auto m = m_reWindowListLine.match(QString::fromLatin1(line)); // 非锚定，命负载段
        if (m.hasMatch()) {
            const auto wit = m_windows.constFind(m.captured("windowId").toInt());
            if (wit != m_windows.constEnd() && wit->attached)
                applyLayoutGeometry(m.captured("windowVisibleLayout"));
        }
        // 同函数尾：再命 ^%layout-change 正则（恒真）→全量重查入队
        if (m_reLayoutChange.match(QString::fromLatin1(line)).hasMatch())
            enqueueFullRefresh();
        return 8;
    }
    case 22: { // %window-pane-changed（0x0087afee）
        const auto m = m_reWindowPaneChanged.match(QString::fromLatin1(line));
        const int paneId = m.hasMatch() ? m.captured("paneId").toInt() : -1;
        const int windowId = m.hasMatch() ? m.captured("windowId").toInt() : -1;
        auto pit = m_panes.find(paneId);
        auto wit = m_windows.find(windowId);
        if (pit == m_panes.end() || wit == m_windows.end()) {
            enqueueFullRefresh();
            return 22;
        }
        // 同窗 pane active 位重算
        for (auto it2 = m_panes.begin(); it2 != m_panes.end(); ++it2) {
            if (it2->windowId == windowId)
                it2->flags = quint8((it2->flags & ~1) | (it2.key() == paneId ? 1 : 0));
        }
        wit->activePaneId = paneId;
        wit->rawFlags += QLatin1Char('*'); // window flags bit0（*=active，0x0087afee +0xc|1）
        emit windowsChanged(); // 原版经批刷 QTimer（0x8773a4）聚发——骨架直发，批刷挂账
        return 22;
    }
    case 14: case 19: case 23: { // %session-renamed(0x0087b4d2)/unlinked-renamed/window-renamed(0x0087ac18/0x0087ab18)
        const QRegularExpression &re = token == 14 ? m_reSessionRenamed
                                     : token == 19 ? m_reUnlinkedWindowRenamed
                                                   : m_reWindowRenamed;
        const auto m = re.match(QString::fromLatin1(line));
        if (!m.hasMatch())
            return token;
        if (token == 14) { // session 改名→ attached 窗 sessionName 同步
            const int sid = m.captured("sessionId").toInt();
            const QString name = m.captured("sessionName");
            for (auto &w : m_windows) {
                if (w.sessionId == sid) {
                    w.sessionName = name;
                    w.attached = sid == m_sessionId;
                }
            }
            emit windowsChanged();
        } else {
            const int wid = m.captured("windowId").toInt();
            auto wit = m_windows.find(wid);
            if (wit != m_windows.end()) {
                wit->name = m.captured("windowName");
                emit windowsChanged();
            } else {
                enqueueFullRefresh();
            }
        }
        return token;
    }
    default: { // 3/4/10/13/15/16/17/18/20/21 泛化（0x0087ab18 形：正则命中→全量重查入队）
        const QRegularExpression *re = nullptr;
        switch (token) {
        case 3:  re = &m_reClientDetached; break;
        case 4:  re = &m_reClientSessionChanged; break;
        case 10: re = &m_rePaneModeChanged; break;
        case 13: re = &m_reSessionChanged; break;
        case 15: re = &m_reSessionsChanged; break;
        case 16: re = &m_reSessionWindowChanged; break;
        case 17: re = &m_reUnlinkedWindowAdd; break;
        case 18: re = &m_reUnlinkedWindowClose; break;
        case 20: re = &m_reWindowAdd; break;
        case 21: re = &m_reWindowClose; break;
        }
        if (re && re->match(QString::fromLatin1(line)).hasMatch())
            enqueueFullRefresh();
        return token;
    }
    }
}

void Tmux::feedData(const QByteArray &data)
{
    m_buf += data;
    while (!m_buf.isEmpty()) {
        // %exit 正则含 \r?\n\033\\——须对残余整体匹配（0x7e9a32 case7：非命中整体回缓冲）
        if (m_buf.startsWith("%exit")) {
            const auto m = m_reExit.match(QString::fromUtf8(m_buf));
            if (!m.hasMatch())
                return; // 未完整（等 ESC\）：整体回缓冲
            const QString reason = m.captured("reason");
            m_buf.remove(0, m.capturedLength());
            emit exited(reason);
            continue;
        }
        const int nl = m_buf.indexOf('\n');
        if (nl < 0)
            return; // 行不完整回缓冲
        int len = nl;
        if (len > 0 && m_buf.at(len - 1) == '\r')
            --len; // 去 \r
        const QByteArray line = m_buf.left(len);
        m_buf.remove(0, nl + 1);
        const int token = parseLine(line);
        switch (token) {
        case 0:
        case 1: // 透传终端
            feedVt(line + '\n');
            break;
        case 5: // %end 帧已在 parseLine 分派
        case 6:
        case 2:
        case 8:
        case 9:
        case 11:
        case 22:
        case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 23:
        case 3: case 4: case 7: case 10:
        case 12: { // 行内嵌 %end 尾（0x0087c832 近似：左段记输出，余段重投）
            const int at = line.indexOf(m_endTail);
            if (token == 12 && at > 0 && m_frameOpen) {
                m_frameOutput.append(line.left(at));
                parseLine(line.mid(at + m_endTail.size())); // 余段按新行分派（shortcut: 原版左段走 parsePromptMeta(1) 语义未全逆，挂账）
            }
            break;
        }
        default:
            break;
        }
        if (qobject_cast<Tmux *>(this) == nullptr)
            return; // exited 后宿主可能已销毁本对象
    }
}

// ═══ 帧完成分派（0x0087c44e terminal_parsePromptMeta）═══

void Tmux::completeFrame(bool endFrame)
{
    if (!m_frameOpen)
        return;
    const auto tail = endFrame ? m_reEnd.match(QString::fromLatin1(m_endTail)) : m_reError.match(QString::fromLatin1(m_errorTail));
    Q_UNUSED(tail);
    if (m_sent.isEmpty()) { // 外部命令帧（sendCommand 族）：记录在队即弃
        m_frameOpen = false;
        m_frameOutput.clear();
        return;
    }
    const PendingCommand cmd = m_sent.takeFirst();
    if (endFrame) {
        switch (cmd.type) {
        case 0: { // capture-pane（FUN_00879ab2：paneInited+screenCaptured）
            auto pit = m_panes.find(cmd.targetId);
            if (pit != m_panes.end()) {
                emit paneInited(cmd.targetId);
                emit screenCaptured(cmd.targetId, pit->flags & 2, pit->history, joinLines(m_frameOutput));
            }
            break;
        }
        case 1: { // pane-cwd（0x00879b76：首行正则→cwd 变更）
            if (!m_frameOutput.isEmpty()) {
                const auto m = m_rePaneCwdChanged.match(QString::fromLatin1(m_frameOutput.first()));
                if (m.hasMatch() && m.captured("paneId").toInt() == cmd.targetId) {
                    const QString cwd = m.captured("paneCwd");
                    auto pit = m_panes.find(cmd.targetId);
                    if (pit != m_panes.end() && pit->cwd != cwd) {
                        pit->cwd = cwd;
                        emit paneCwdChanged(cmd.targetId, cwd);
                    }
                }
            }
            break;
        }
        case 3: // version（0x0087771e：k:v 字段，key=="version"）
            for (const auto &f : parseFields(m_frameOutput.value(0)))
                if (f.first == "version")
                    m_version = f.second;
            break;
        case 4:
            refreshPanes(m_frameOutput);
            break;
        case 5:
            refreshWindows(m_frameOutput);
            break;
        }
    } else { // %error 帧：errorOccurred(全输出)（0x0087c44e param_3==0 分支）
        emit errorOccurred(QString::fromUtf8(joinLines(m_frameOutput)));
    }
    m_frameOpen = false;
    m_frameOutput.clear();
}

// ═══ pane/window 全量刷新 ═══

QList<QPair<QByteArray, QByteArray>> Tmux::parseFields(const QByteArray &line)
{
    QList<QPair<QByteArray, QByteArray>> out;
    const QList<QByteArray> parts = line.split(';');
    for (const QByteArray &p : parts) {
        const int c = p.indexOf(':');
        if (c > 0)
            out.append({p.left(c), p.mid(c + 1)});
    }
    return out;
}

int Tmux::idValue(const QByteArray &v, char prefix)
{
    if (v.isEmpty())
        return -1;
    QByteArray t = v;
    if (t.at(0) == prefix)
        t.remove(0, 1);
    return t.toInt();
}

void Tmux::refreshPanes(const QList<QByteArray> &lines) // 0x00879d62
{
    QSet<int> seen;
    for (const QByteArray &line : lines) {
        const auto f = parseFields(line);
        QByteArray pid, sid, wid, path, title;
        int paneActive = 0, alt = 0, sync = 0, cx = 0, cy = 0, w = 0, h = 0, hist = 0,
            pp = 0, modes = 0;
        for (const auto &kv : f) {
            const QByteArray &k = kv.first;
            const QByteArray &v = kv.second;
            if (k == "pane_active") paneActive = v.toInt() != 0;
            else if (k == "alternate_on") alt = v.toInt() != 0;
            else if (k == "pane_synchronized") sync = v.toInt() != 0;
            else if (k == "pane_current_path") path = v;
            else if (k == "pane_title") title = v;
            else if (k == "cursor_x") cx = v.toInt();
            else if (k == "cursor_y") cy = v.toInt();
            else if (k == "pane_height") h = v.toInt();
            else if (k == "pane_width") w = v.toInt();
            else if (k == "history_size") hist = v.toInt();
            else if (k == "pane_id") pid = v;
            else if (k == "pane_pid") pp = v.toInt();
            else if (k == "session_id") sid = v;
            else if (k == "window_id") wid = v;
            else if (k == "cursor_flag") modes = v.toInt() ? modes | (1 << 25) : modes & ~(1 << 25);
            else if (k == "insert_flag") modes = v.toInt() ? modes | 4 : modes & ~4;
            else if (k == "keypad_cursor_flag") modes = v.toInt() ? modes | 1 : modes & ~1;
            else if (k == "keypad_flag") modes = v.toInt() ? modes | 66 : modes & ~66;
            else if (k == "mouse_any_flag" || k == "mouse_all_flag") modes = v.toInt() ? modes | 1003 : modes & ~1003;
            else if (k == "mouse_button_flag") modes = v.toInt() ? modes | 1002 : modes & ~1002;
            else if (k == "mouse_sgr_flag") modes = v.toInt() ? modes | 1006 : modes & ~1006;
            else if (k == "mouse_standard_flag") modes = v.toInt() ? modes | 1000 : modes & ~1000;
            else if (k == "mouse_utf8_flag") modes = v.toInt() ? modes | 1005 : modes & ~1005;
            else if (k == "origin_flag") modes = v.toInt() ? modes | 6 : modes & ~6;
            else if (k == "wrap_flag") modes = v.toInt() ? modes | 7 : modes & ~7;
        }
        const int id = idValue(pid, '%');
        if (id < 0)
            continue;
        seen.insert(id);
        const int sidInt = sid.isEmpty() ? -1 : idValue(sid, '$');
        if (sidInt >= 0 && m_sessionId != sidInt)
            m_sessionId = sidInt; // +0x34 回填
        const bool isNew = !m_panes.contains(id);
        Pane pane = m_panes.value(id);
        const bool resized = !isNew && (pane.w != w || pane.h != h);
        pane.id = id;
        pane.flags = quint8(paneActive | (alt << 1) | (sync << 2));
        pane.cursorX = cx;
        pane.cursorY = cy;
        pane.w = w;
        pane.h = h;
        pane.history = hist;
        pane.pid = pp;
        pane.title = QString::fromUtf8(title);
        pane.cwd = QString::fromUtf8(path);
        pane.sessionId = sidInt;
        pane.windowId = wid.isEmpty() ? -1 : idValue(wid, '@');
        pane.modes = modes;
        m_panes.insert(id, pane);
        if (isNew) {
            emit termAdded(id, pane.cwd);
            if (m_pendingOut.contains(id)) // 待激活输出冲账（0x00879d62 新 pane 路径）
                emit outputCached(id, m_pendingOut.take(id));
            else
                emit paneInited(id);
            queueCommand(0, id, QByteArrayLiteral("capture-pane -peCqJ -t %") + QByteArray::number(id));
        } else if (resized) {
            emit screenResized(id);
        }
    }
    QList<int> removed;
    for (auto it = m_panes.begin(); it != m_panes.end();) {
        if (!seen.contains(it.key())) {
            removed.append(it.key());
            it = m_panes.erase(it);
        } else {
            ++it;
        }
    }
    if (!removed.isEmpty())
        emit termsRemoved(removed);
}

void Tmux::refreshWindows(const QList<QByteArray> &lines) // 0x0087b76a
{
    QSet<int> seen;
    bool changed = false;
    for (const QByteArray &line : lines) {
        const auto f = parseFields(line);
        QByteArray wid, wname, widx, layout, visibleLayout, rawFlags, sname, sid;
        for (const auto &kv : f) {
            const QByteArray &k = kv.first;
            const QByteArray &v = kv.second;
            if (k == "window_id") wid = v;
            else if (k == "window_name") wname = v;
            else if (k == "window_index") widx = v;
            else if (k == "window_layout") layout = v;
            else if (k == "window_visible_layout") visibleLayout = v;
            else if (k == "window_raw_flags") rawFlags = v;
            else if (k == "session_name") sname = v;
            else if (k == "session_id") sid = v;
        }
        const int id = idValue(wid, '@');
        if (id < 0)
            continue;
        seen.insert(id);
        const int sidInt = sid.isEmpty() ? -1 : idValue(sid, '$');
        const bool attached = sidInt >= 0 && sidInt == m_sessionId;
        const bool isNew = !m_windows.contains(id);
        Window w = m_windows.value(id);
        w.id = id;
        w.idx = widx.toInt();
        w.name = QString::fromUtf8(wname);
        w.sessionName = QString::fromUtf8(sname);
        w.sessionId = sidInt;
        w.rawFlags = QString::fromUtf8(rawFlags);
        w.attached = attached;
        if (attached) {
            w.layout = QString::fromUtf8(layout);
            w.visibleLayout = QString::fromUtf8(visibleLayout);
        }
        m_windows.insert(id, w);
        if (isNew)
            changed = true;
        // layout 几何（0x0087ad18 同管线）
        applyLayoutGeometry(attached ? QString::fromUtf8(visibleLayout) : QString::fromUtf8(layout));
    }
    QList<int> removed;
    for (auto it = m_windows.begin(); it != m_windows.end();) {
        if (!seen.contains(it.key())) {
            removed.append(it.key());
            it = m_windows.erase(it);
        } else {
            ++it;
        }
    }
    if (!removed.isEmpty()) {
        emit windowsRemoved(removed);
        changed = true;
    }
    if (changed)
        emit windowsChanged();
}

void Tmux::applyLayoutGeometry(const QString &layout)
{
    if (layout.isEmpty())
        return;
    auto it = m_reGeoGlobal.globalMatch(layout);
    while (it.hasNext()) {
        const auto m = it.next();
        const int paneId = m.captured("id").toInt();
        const int w = m.captured("width").toInt();
        const int h = m.captured("height").toInt();
        auto pit = m_panes.find(paneId);
        if (pit != m_panes.end() && (pit->w != w || pit->h != h)) {
            pit->w = w;
            pit->h = h;
            emit screenResized(paneId);
        }
    }
}

// ═══ 路由/队列 ═══

void Tmux::routeOutput(int paneId, const QByteArray &data) // 0x7e6b64
{
    if (paneId == m_activePaneId && !data.isEmpty()) {
        feedVt(data); // 当前显示 pane 直接喂 VT
        return;
    }
    m_pendingOut[paneId] += data; // 非活动暂存，激活/建 pane 时冲账
}

void Tmux::setActivePane(int paneId)
{
    if (m_activePaneId == paneId)
        return;
    m_activePaneId = paneId;
    // 0x7e6d78：切换后待冲账输出交还
    auto it = m_pendingOut.find(paneId);
    if (it != m_pendingOut.end()) {
        emit outputCached(paneId, it.value());
        m_pendingOut.erase(it);
    }
}

void Tmux::feedVt(const QByteArray &data)
{
    if (!data.isEmpty())
        emit vtOutput(data);
}

void Tmux::queueCommand(int type, int targetId, const QByteArray &payload)
{
    if (!m_enabled || payload.isEmpty())
        return;
    // 去重（0x008778dc：pending 批内 type+payload 同者弃）
    for (const PendingCommand &c : m_pending)
        if (c.type == type && c.targetId == targetId && c.payload == payload)
            return;
    m_pending.append({type, targetId, payload});
    m_flushTimer.start();
}

void Tmux::flushQueue() // 0x0087826d
{
    while (!m_pending.isEmpty()) {
        const PendingCommand c = m_pending.takeFirst();
        m_sent.append(c);
        if (m_write)
            m_write(c.payload + '\n');
    }
}

void Tmux::enqueueFullRefresh() // 0x00877f30
{
    if (!m_enabled)
        return;
    if (m_sessionId >= 0) {
        QByteArray lp(kListPanesFmt);
        lp += " -t $" + QByteArray::number(m_sessionId);
        queueCommand(4, m_sessionId, lp);
        QByteArray lw(kListWindowsFmt);
        lw += " -t $" + QByteArray::number(m_sessionId);
        queueCommand(5, m_sessionId, lw);
    } else {
        queueCommand(4, -1, QByteArray(kListPanesFmt));
        queueCommand(5, -1, QByteArray(kListWindowsFmt));
    }
}

// ═══ 命令下发原语（0x83eaa6 族串照抄）═══

void Tmux::sendCommand(const QString &cmd)
{
    if (cmd.isEmpty() || !m_write)
        return;
    m_write(cmd.toUtf8() + '\n');
}

void Tmux::newWindow() { sendCommand(QStringLiteral("new-window")); }
void Tmux::splitWindow(int paneId, int dir)
{
    static const char *dirs[] = {"-bh", "-h", "-bv", "-v"};
    const QString d = (dir >= 0 && dir <= 3) ? QLatin1String(dirs[dir]) : QString();
    sendCommand(QStringLiteral("split-window %1 -t %2").arg(d).arg(paneId));
}
void Tmux::killPane(int paneId) { sendCommand(QStringLiteral("kill-pane -t %1").arg(paneId)); }
void Tmux::killWindow(int idx)
{
    if (idx != -1)
        sendCommand(QStringLiteral("kill-window -t %1").arg(idx));
}
void Tmux::killSession(const QString &name) { sendCommand(QStringLiteral("kill-session -t '%1'").arg(name)); }
void Tmux::selectPane(int paneId) { sendCommand(QStringLiteral("select-pane -t %1").arg(paneId)); }
void Tmux::selectPaneDirection(int paneId, int dir)
{
    static const char *dirs[] = {"-L", "-R", "-U", "-D"};
    const QString d = (dir >= 0 && dir <= 3) ? QLatin1String(dirs[dir]) : QString();
    sendCommand(QStringLiteral("select-pane %1 -t %2").arg(d).arg(paneId));
}
void Tmux::resizePane(int paneId, int dir, int count)
{
    static const char *dirs[] = {"-L", "-R", "-U", "-D"};
    const QString d = (dir >= 0 && dir <= 3) ? QLatin1String(dirs[dir]) : QString();
    sendCommand(QStringLiteral("resize-pane %1 -t %2 %3").arg(d).arg(paneId).arg(qMax(1, count)));
}
void Tmux::swapPaneTarget(int paneId, int dir)
{
    static const char *dirs[] = {"{left-of}", "{right-of}", "{up-of}", "{down-of}"};
    const QString d = (dir >= 0 && dir <= 3) ? QLatin1String(dirs[dir]) : QString();
    if (!d.isEmpty())
        sendCommand(QStringLiteral("swap-pane -d -t '%1'").arg(d));
    Q_UNUSED(paneId);
}
void Tmux::swapPane(int a, int b) { sendCommand(QStringLiteral("swap-pane -s %1 -t %2").arg(a).arg(b)); }
void Tmux::swapWindow(int a, int b) { sendCommand(QStringLiteral("swap-window -s %1 -t %2").arg(a).arg(b)); }
void Tmux::selectWindow(int idx) { sendCommand(QStringLiteral("select-window -t %1").arg(idx)); }
void Tmux::attachSession(const QString &name) { sendCommand(QStringLiteral("attach-session -t '%1'").arg(name)); }
void Tmux::detachClient() { sendCommand(QStringLiteral("detach-client")); }
void Tmux::renameWindow(int idx, const QString &name) { sendCommand(QStringLiteral("rename-window -t %1 '%2'").arg(idx).arg(name)); }
void Tmux::renameSession(const QString &oldName, const QString &newName)
{
    sendCommand(QStringLiteral("rename-session -t '%1' '%2'").arg(oldName, newName));
}
void Tmux::renamePaneTitle(int paneId, const QString &title)
{
    sendCommand(QStringLiteral("select-pane -t %1 -T '%2'").arg(paneId).arg(title));
}
void Tmux::selectLayout(const QString &name) { sendCommand(QStringLiteral("select-layout '%1'").arg(name)); }
void Tmux::resizeClient(int columns, int rows)
{
    sendCommand(QStringLiteral("refresh-client -C %1,%2").arg(columns).arg(rows));
}
void Tmux::zoomPane(int paneId, bool zoom)
{
    sendCommand(QStringLiteral("resize-pane%1 -t %2").arg(zoom ? QStringLiteral(" -Z") : QString()).arg(paneId));
}
void Tmux::setSynchronize(bool on)
{
    sendCommand(QStringLiteral("set-option synchronize-panes '%1'").arg(on ? QStringLiteral("on") : QStringLiteral("off")));
}
void Tmux::clearHistory(int paneId) { sendCommand(QStringLiteral("clear-history -t %1").arg(paneId)); }
void Tmux::breakPane(int paneId) { sendCommand(QStringLiteral("break-pane -s %1").arg(paneId)); }
