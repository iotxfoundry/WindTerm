#pragma once

#include <QJSEngine>
#include <QObject>

// MuxPane 宿主壳 —— 语料转写(批 50;铁律 6)。
// ⚠ 批 71 勘正 + 批 87 km4 再勘:PTR_011a6c00 = readelf -r 实证
//   **_ZN11QMainWindow16staticMetaObjectE@Qt_5(Qt 导入)**—— cast 面
//   = qobject_cast<QMainWindow 后代>;本壳 = 主窗口宿主语义(引擎
//   @+0x48 由 FUN_00766192 挂载);真正面板 widget = 语料 MuxPane
//   (QWidget,s_MuxPane_8de0c0 ctor,MuxPaneGroup/TabGroup/Stacked
//   层级)= Phase 4c 新增 MuxPaneView(避让本名)。
// 语料:PTR_staticMetaObject_011a6c00(FUN_00665d8a 20B cast 目标;
//   0017:15348 / 0020:30185 交叉)—— 引擎 @+0x48
//   (FUN_0076745c/00767a70/00767d08/d2e 四门实证)。
// 引导流程 = s_MuxPane_64b102(0064b102,1707B;批 39 MuxPaneJs
// 转写)——本壳为运行期宿主面(引擎持有点 + 调用门)。
// 面板装配(QWidget 面)属 Phase 4c;本壳零自造行为。
// 勘误批 68:FUN_00766192 放 +0x48 的是 JsEngine*(0023:33040-44),
// 非裸 QJSEngine(旧注"QJSEngine @+0x48"随之勘正)
class JsEngine;

class MuxPane : public QObject {
    Q_OBJECT

public:
    explicit MuxPane(QObject *parent = nullptr);

    JsEngine *m_engine = nullptr;   // 语料 +0x48(四门读取)
    QJSValue *m_cachedArg = nullptr; // 语料 +0x18(FUN_00668f3a 缓存)
};
