#pragma once

#include <QJSEngine>
#include <QObject>

// MuxPane 面板类壳 —— 语料转写(批 50;铁律 6)。
// 语料:PTR_staticMetaObject_011a6c00(FUN_00665d8a 20B cast 目标;
//   0017:15348 / 0020:30185 交叉)—— QJSEngine @+0x48
//   (FUN_0076745c/00767a70/00767d08/d2e 四门实证)。
// 引导流程 = s_MuxPane_64b102(0064b102,1707B;批 39 MuxPaneJs
// 转写)——本壳为运行期宿主面(引擎持有点 + 调用门)。
// 面板装配(QWidget 面)属 Phase 4c;本壳零自造行为。
class MuxPane : public QObject {
    Q_OBJECT

public:
    explicit MuxPane(QObject *parent = nullptr);

    QJSEngine *m_engine = nullptr;   // 语料 +0x48(四门读取)
    QJSValue *m_cachedArg = nullptr; // 语料 +0x18(FUN_00668f3a 缓存)
};
