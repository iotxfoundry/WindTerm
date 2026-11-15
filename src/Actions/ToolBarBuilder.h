#pragma once

#include <QList>
#include <QMainWindow>

#include "Editor/CGlobalConfigFace.h"

class QToolBar;
class QToolButton;

// ToolBarBuilder —— 语料 toolbar_build 族(批 190,M24-②,P3;铁律 6:
// 全部按钮/分组来自 toolbar.config 装载树 — CGlobalConfigFace::m_views,
// 批 147 loadViews 真身;禁止发明按钮)。
//
// 语料函数族(0021.c,toolbar 家):
//   toolbar_build      00694276(2164B,0021.c:19664)本文件主转写体;
//     唯一双调用点:kuna xrefs 实证 0x8bb018(s_tabbar_showSequenceNumbers_
//     8bade2,MainWindow 装配腿,"Kit" 组)+ 0x8c4180(sub_8c40a6,
//     pane 侧装配腿,pane objectName 组名)。
//   FUN_00692ef0(310B,0021.c:18914)组菜单查/建(S3 新建腿已由
//     MuxPaneGroup::kitFindOrCreateGroupMenu 批 133 真身;本族消费同型)
//   FUN_00692a70(1119B,0021.c:18732)菜单树消费(批 189 已转写,
//     KitWindowFactory 域)— 本文件不重复落(域界:批 189 落
//     menubar 面;本文件 = toolbar 面,消费同一 views 树的 toolbar 半边)
//   s_ToolBarPopup_693470(3293B,0021.c:19155)Grid 弹出菜单 — cited
//     (本批 trigger 腿接其入口,菜单体网格布局 0x18 行 cited — wave-2)
//   FUN_006941d5(152B,0021.c:19615)triggered 槽:popupFlag →
//     s_ToolBarPopup(action->property("Popup") 名);体全读,本批真身
//   FUN_00694de0(198B)/FUN_00694d14(50B)/FUN_00694c1e(245B)/
//     FUN_00694d70(111B)= QList<QString> append 族(QList 值语义承接)
//   FUN_00767b40(9B,0023.c:34273)= FUN_00666de2(*(mw+0x60),name)
//     工厂克隆:ActionFactory::getOrCreate 表查 → 新 QAction 拷
//     text/icon/toolTip/shortcut + setProperty("dynamic") +
//     triggered→FUN_0066a148(js_actionFire)(0020.c:50701,744B 全读;
//     触发链与仓库 ActionFactory 同构 — 复用)
//   FUN_00767c4a(9B,0023.c:34366)= action_registerDataType(*(mw+0x60))
//     (0066598c,902B,0020.c:49878 全读:property("dynamic") QAction*
//     门 → data() → canConvert(QJSValue/string)→ bool)→ popupMode
//     2/1 择位(menu-button vs instant)
//   子件 ctor:FUN_005211fe AddressBar(162B,0016.c:15189)/
//     FUN_0057eb0c FilterEdit(200B,0017.c:55458)— cited — wave-2
//     (组件本体未落库;_toolbar_citedSpacer 同型占位,零自造行为)
//
// Kind 位面(值对象 +0x10 低 nibble,批 147 权威):
//   0=Separator 1=Spacer 2=ToolBar(递归子栏)3=Action 4=Label
//   5=AddressBar 6=FilterEdit(与 toolbar.config 七键一一对应)。
namespace ToolBarBuilder {

// toolbar_build(00694276)主面:单组 views 树 → 工具栏(不挂主窗,
//   返回空栏判 = 空 actions 同相 @00694a8x;调用方 addToolBar)。
//   mainWindow = 语料 __dynamic_cast 目标(typeinfo "10MainWindow"
//   @0x11a69d0 ELF 实读;宿主 = 主窗链,KitWindowFactory 装配面)。
QToolBar *buildToolbar(QMainWindow *mainWindow, const QByteArray &groupName);

// toolbar_build 全组遍历腿(s_tabbar_showSequenceNumbers_8bade2,
//   1286B,0027.c:77736 的工具栏段转写):menu() 容器 views 树逐组
//   buildToolbar + addToolBar(空组跳过 — actions() 空判同相)。
void buildAllToolbars(QMainWindow *mainWindow);

// 触发槽 FUN_006941d5 真身(公开 = 测试面;connect 于 buildToolbar 内)。
void actionTriggered(QAction *action);

// case3 子腿(公开 = 测试面):工厂克隆 → 钮/action 接线全景。
// 返回挂栏 widget(tool-button 空间不足分支 = addWidget;其余 addAction)。
QWidget *buildActionEntry(QMainWindow *mainWindow, QToolBar *bar,
                          const class SharedConfigHandlerFace &node);

} // namespace ToolBarBuilder
