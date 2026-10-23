#pragma once

#include <QByteArray>
#include <QString>
#include <QVector>

// tabListBlob（0x8bbab6）单 view 项：QString url("$<uuid>" 会话 / 内部视图跳过)
// + QBA viewState + QColor(magic>0x15) + RenamedTitle QString(magic>0x24)——后两项写侧恒空
struct ReopenTabEntry
{
    // 挂账: Session 无 uuid 暴露（原版 url="$<uuid>"，0x833db4 真重连入口）——留空 url，
    // uuid 接入 TerminalView 会话后回填
    QString url;
};

// 单窗口重建态（原版顶层 i32 窗口数可多窗，重建恒 1——0x5dd560 读链逐窗循环）
struct ReopenState
{
    QByteArray geometry; // QWidget::saveGeometry() 透传（0x76073a）
    bool maximized = false;
    int currentIndex = 0; // 0x7669b2 stateBlob 层 + 0x8bbab6 tabList 层共用的当前标签索引
    QVector<ReopenTabEntry> tabs;
    // 盘上语义（0x8d2f7e 实证）：bool=hidden（000→三栏全可见）；本结构字段=可见性，读写时取反
    bool menuBarVisible = true;
    bool statusBarVisible = true;
    bool toolBarVisible = true;
};

// global/reopen.history 二进制读写（格式规格 docs/reopen-history.md，622B 真实样例验证；
// QDataStream 默认大端 + setVersion(Qt_5_15)，读 0x5dd560/0x75ffcc 链、写 0x5dd6fc/0x76073a 链）。
// 读侧只消费 geometry/maximized/bars/currentIndex/tabList；docks/right 内部结构跳过不解析
// （等价映射见 ReopenHistory.cpp）。
namespace ReopenHistory
{
// ~/.wind/profiles/default.v10/global/reopen.history
QString defaultPath();
bool load(const QString &path, ReopenState &out);
bool save(const QString &path, const ReopenState &in);
}
