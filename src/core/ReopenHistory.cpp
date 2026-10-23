#include "ReopenHistory.h"

#include <QColor>
#include <QDataStream>
#include <QDir>
#include <QFile>

namespace {

// 0xB9E7E626：低 8 位=格式修订号（docs/reopen-history.md；0xB9E7E626 六位样例验证）
constexpr quint32 MAGIC = 0xB9E7E626u;
constexpr int PAGE_COUNT = 1; // 重建单窗口单页；pageName 恒 "Terminal"

// 写 tabListBlob（0x8bbab6）：i32 current + i32 count + 每 view
// QString url + QBA viewState(空) + QColor()（magic>0x15）+ QString ""（magic>0x24）
void writeTabList(QDataStream &s, const QVector<ReopenTabEntry> &tabs, int current)
{
    s << qint32(current);
    s << qint32(tabs.size());
    for (const ReopenTabEntry &t : tabs) {
        s << t.url;
        s << QByteArray(); // KitView_vt9 viewState：重建无内容，透传空（0x8bbab6）
        s << QColor();     // magic>0x15 字段，恒空色
        s << QString();    // magic>0x24 RenamedTitle（page=="Terminal"），恒空
    }
}

bool readTabList(QDataStream &s, QVector<ReopenTabEntry> &tabs, int &current)
{
    qint32 cur = 0;
    qint32 count = 0;
    s >> cur >> count;
    if (s.status() != QDataStream::Ok || count < 0)
        return false;
    for (qint32 i = 0; i < count; ++i) {
        ReopenTabEntry e;
        s >> e.url;
        QByteArray viewState;
        QColor color;
        QString renamed;
        s >> viewState >> color >> renamed; // QColor 存 5×quint16（Qt_5_15），对称即可
        if (s.status() != QDataStream::Ok)
            return false;
        tabs.append(e);
    }
    current = cur;
    return true;
}

// 写页 blob（0x8cf0c8 写侧）：innerMagic + docksBlob + rightBlob + barsBlob + 尾块。
// 重建树与原版 splitter 树不同构，写"等效空/单节点结构"保持解析对称；
// 读侧（0x8d2f7e）本类跳过不解析这些子块。
void writePageBlob(QDataStream &s, const ReopenState &st)
{
    s << quint32(MAGIC); // 页 innerMagic（quint32 直写，避免 i32 截断为负）
    // 等价映射: 重建无 dock tab 组, 写空结构保持解析对称(0x8cf0c8；子结构 0x8b921a 空)
    {
        QByteArray docks;
        QDataStream ds(&docks, QIODevice::WriteOnly);
        ds.setByteOrder(QDataStream::BigEndian);
        ds.setVersion(QDataStream::Qt_5_15);
        ds << qint32(0); // i32 0：中央 splitter 子数 0（0x8b921a 等价空）
        s << docks;
    }
    // 等价映射: 重建 rightBlob splitter 树与原版不同构, 写 BFS 单节点结构保持解析对称(0x8cf0c8 param&1 路径)
    {
        QByteArray right;
        QDataStream ds(&right, QIODevice::WriteOnly);
        ds.setByteOrder(QDataStream::BigEndian);
        ds.setVersion(QDataStream::Qt_5_15);
        ds << quint8(1);                     // flag
        ds << qint32(0) << qint32(1);        // nodeIdx=0, childCount=1（BFS 单节点）
        ds << QByteArray();                  // QSplitter::saveState——重建无对应树, 透传空
        ds << quint8(2);                     // marker=2（tab 组→QBA tabListBlob）
        // 嵌套 QBA tabListBlob（0x8bbab6）：与读侧 rs >> tabListBlob 对称
        QByteArray tabList;
        QDataStream tls(&tabList, QIODevice::WriteOnly);
        tls.setByteOrder(QDataStream::BigEndian);
        tls.setVersion(QDataStream::Qt_5_15);
        writeTabList(tls, st.tabs, st.currentIndex);
        ds << tabList;
        s << right;
    }
    {
        QByteArray bars;
        QDataStream ds(&bars, QIODevice::WriteOnly);
        ds.setByteOrder(QDataStream::BigEndian);
        ds.setVersion(QDataStream::Qt_5_15);
        // 0x8d2f7e 实证：bool=hidden，应用时取反传 setBarVisible；第 3 字节仅 magic>0x21
        ds << quint8(!st.menuBarVisible) << quint8(!st.statusBarVisible) << quint8(!st.toolBarVisible);
        s << bars;
    }
    // 0x8cf0c8 子类钩子尾块直写, 样例 5B 全 0, 语义未明透传（docs/reopen-history.md）
    s << QByteArray(5, '\0');
}

} // namespace

QString ReopenHistory::defaultPath()
{
    // WindConfig::profileDir 私有（0x80647e 拼法），本类同构拼接；不改 WindConfig
    return QDir::homePath() + QStringLiteral("/.wind/profiles/default.v10/global/reopen.history");
}

bool ReopenHistory::load(const QString &path, ReopenState &out)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QDataStream s(&file);
    s.setByteOrder(QDataStream::BigEndian); // QDataStream 默认大端（docs 规格），显式声明
    s.setVersion(QDataStream::Qt_5_15);

    quint32 magic = 0;
    s >> magic;
    // 读侧校验 (magic & 0xB9E7E600)==0xB9E7E600（低 8 位修订号容忍）
    if (s.status() != QDataStream::Ok || (magic & 0xB9E7E600u) != 0xB9E7E600u)
        return false;

    qint32 windowCount = 0;
    s >> windowCount;
    if (s.status() != QDataStream::Ok || windowCount < 1)
        return false;

    // 重建恒单窗口：首窗消费即返回（0x5dd560 每窗循环，多窗原版语义挂账）
    ReopenState st;
    QByteArray geometry;
    s >> geometry;
    if (s.status() != QDataStream::Ok)
        return false;
    st.geometry = geometry;

    // 窗口状态 blob（0x7669b2）：QBA 透传读入——内含 pageCount/currentIndex/每页
    // pageName+pageBlob；重建只消费 tabList 层的 currentIndex，故整块读入后拆
    QByteArray stateBlob;
    s >> stateBlob;
    if (s.status() != QDataStream::Ok)
        return false;
    quint8 barsMenu = 1, barsStatus = 1, barsTool = 1; // 缺省全可见
    bool rightOk = false;
    {
        QDataStream ps(stateBlob);
        ps.setByteOrder(QDataStream::BigEndian);
        ps.setVersion(QDataStream::Qt_5_15);
        qint32 pageCount = 0;
        qint32 stateIndex = 0;
        ps >> pageCount >> stateIndex; // 0x7669b2：i32 pageCount + i32 currentIndex
        if (ps.status() != QDataStream::Ok || pageCount < 1)
            return false;
        st.currentIndex = stateIndex; // stateBlob 层 currentIndex（无 tabList 时兜底）
        QString pageName;
        QByteArray pageBlob;
        ps >> pageName >> pageBlob; // 取第一页（重建恒 "Terminal"）
        if (ps.status() != QDataStream::Ok)
            return false;
        // 页 blob 读侧（0x8d2f7e）：只拆 barsBlob 与 rightBlob 内 tabList；
        // docks/right 其余结构跳过不解析（几何恢复无条件走顶层 geometry, 0x75ffcc）
        QDataStream gs(pageBlob);
        gs.setByteOrder(QDataStream::BigEndian);
        gs.setVersion(QDataStream::Qt_5_15);
        qint32 innerMagic = 0;
        gs >> innerMagic;
        // (innerMagic & 0xB9E7E600)==0xB9E7E600 以 u32 语义判（写侧 quint32 直写无符号截断）
        if (gs.status() != QDataStream::Ok
            || (quint32(innerMagic) & 0xB9E7E600u) != 0xB9E7E600u)
            return false;
        QByteArray docksBlob;
        QByteArray rightBlob;
        QByteArray barsBlob;
        QByteArray tailBlob;
        gs >> docksBlob >> rightBlob >> barsBlob >> tailBlob; // docks 跳过不解析
        if (gs.status() != QDataStream::Ok)
            return false;
        {
            QDataStream bs(barsBlob);
            bs.setByteOrder(QDataStream::BigEndian);
            bs.setVersion(QDataStream::Qt_5_15);
            bs >> barsMenu >> barsStatus >> barsTool;
            if (bs.status() != QDataStream::Ok)
                return false;
        }
        // rightBlob（0x8cf0c8 param&1 BFS）：quint8 flag + i32 nodeIdx + i32 childCount
        // + QBA splitterState + 每子 1B marker；marker=2 → QBA tabListBlob
        // （0x8bbab6/0x8bb3e6）。真样例 childCount 位读出 255（结构分歧挂账：
        // 真样例 rightBlob 结构与 docs 描述不完全一致）——读侧挂账只按重建写侧
        // 结构精确解析；分歧处（marker 非法/childCount 越界）即停，bars 不应用
        // （防结构位移读出假值隐藏三栏），保底只恢复 geometry。
        // shortcut: 0x8d2e46 读链未逆明, 逆明后按真结构重写本段
        {
            QDataStream rs(rightBlob);
            rs.setByteOrder(QDataStream::BigEndian);
            rs.setVersion(QDataStream::Qt_5_15);
            quint8 flag = 0;
            rs >> flag;
            if (rs.status() != QDataStream::Ok)
                return false;
            if (flag & 1) { // param&1 才有 BFS 树（写侧同构）
                qint32 nodeIdx = 0;
                qint32 childCount = 0;
                QByteArray splitterState;
                rs >> nodeIdx >> childCount >> splitterState;
                if (rs.status() != QDataStream::Ok)
                    return false;
                if (childCount < 0 || childCount > 16)
                    rightOk = false; // 结构分歧（真样例 255）——bars 不应用
                else
                for (qint32 c = 0; c < childCount && !rs.atEnd(); ++c) {
                    quint8 marker = 0;
                    rs >> marker;
                    if (rs.status() != QDataStream::Ok)
                        break;
                    if (marker != 1 && marker != 2)
                        break; // 结构分歧（真样例无 marker 前缀）挂账
                    if (marker == 1) {
                        QByteArray child;
                        rs >> child; // 子 splitter 入队（BFS），重建无对应物跳过
                        continue;
                    }
                    // marker == 2：QBA tabListBlob（0x8bbab6/0x8bb3e6）
                    QByteArray tabListBlob;
                    rs >> tabListBlob;
                    if (rs.status() != QDataStream::Ok)
                        break;
                    if (tabListBlob.isNull() && !tabListBlob.isEmpty()) {
                        // null QBA（NoSessions，docs 0x8bbab6 尾注）→ 空 tabList
                        st.tabs.clear();
                        st.currentIndex = 0;
                        continue;
                    }
                    QDataStream ts(tabListBlob);
                    ts.setByteOrder(QDataStream::BigEndian);
                    ts.setVersion(QDataStream::Qt_5_15);
                    QVector<ReopenTabEntry> tabs;
                    int tabCurrent = 0;
                    if (!readTabList(ts, tabs, tabCurrent))
                        break;
                    st.tabs = tabs;
                    st.currentIndex = tabCurrent;
                }
                rightOk = true; // BFS 树合法走完（无分歧 break）
            } else {
                rightOk = true; // flag&0：无树=无分歧
            }
        }
    }

    quint8 maximized = 0;
    s >> maximized;
    if (s.status() != QDataStream::Ok)
        return false;
    st.maximized = maximized != 0;

    // bars 语义已实证（0x8d2f7e）：bool=hidden（000→三栏全可见，与实机一致），
    // 应用时取反传 setBarVisible；第 3 字节（ToolBar）仅 magic>0x21 存在（0x8d2f7e 版本条件）
    // 尾块 5B=状态栏 message 区（vtbl+0x240）
    if (rightOk) {
        st.menuBarVisible = barsMenu == 0;
        st.statusBarVisible = barsStatus == 0;
        st.toolBarVisible = barsTool == 0;
    } else {
        Q_UNUSED(barsMenu); Q_UNUSED(barsStatus); Q_UNUSED(barsTool); Q_UNUSED(rightOk);
    }

    out = st;
    return true;
}

bool ReopenHistory::save(const QString &path, const ReopenState &in)
{
    QFile file(path);
    // 中间目录缺失即失败（不代建——profile 目录属用户原版资产，勿越权创建）
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return false;
    QDataStream s(&file);
    s.setByteOrder(QDataStream::BigEndian);
    s.setVersion(QDataStream::Qt_5_15);

    s << MAGIC; // 0xB9E7E626：写侧低字节 0x26（修订号）
    s << qint32(1); // 窗口数：重建恒 1

    s << in.geometry; // QWidget::saveGeometry() 透传（0x76073a）
    {
        // 窗口状态 blob（0x7669b2）：pageCount=1/currentIndex=0/单页 pageName="Terminal"
        QByteArray stateBlob;
        QDataStream ps(&stateBlob, QIODevice::WriteOnly);
        ps.setByteOrder(QDataStream::BigEndian);
        ps.setVersion(QDataStream::Qt_5_15);
        ps << qint32(PAGE_COUNT) << qint32(0);
        ps << QStringLiteral("Terminal");
        QByteArray pageBlob;
        QDataStream gs(&pageBlob, QIODevice::WriteOnly);
        gs.setByteOrder(QDataStream::BigEndian);
        gs.setVersion(QDataStream::Qt_5_15);
        writePageBlob(gs, in);
        ps << pageBlob;
        s << stateBlob;
    }
    s << quint8(in.maximized ? 1 : 0);
    return s.status() == QDataStream::Ok;
}
