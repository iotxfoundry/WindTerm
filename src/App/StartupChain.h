#pragma once

#include <QByteArray>
#include <QString>

#include "Windows/Kit/MainWindowFace.h"

class QMainWindow;

// 批 149(M14-①b)/批 150(M15-①a)/批 154(M16-①)启动链 —
// s_application_lockScreenTimeout_ 7626ce(510B,0023.c:29843)语料序
// 对位转写;宿主成员槽位与未转写腿逐条 cited(铁律 3/6,见 cpp 内地址
// 注记),真身化腿:
//   themeGui/lockScreenTimeout 配置读(CTerminalConfig 真单例调面)+
//   失败腿 FUN_0075e3fe(kitWindowRestoreFirstPage,批 142 真身)+
//   恢复门 FUN_0075ffcc(批 150 真身,startupRestoreGate)+
//   恢复分发壳 FUN_00766c26(startupRestoreDispatch;kit.startupSessions
//   &4 腿批 154 接 s_kit_startupSessions_8d2f7e 真身 —
//   src/Sessions/WorkspaceLoader.cpp kitStartupSessions)+
//   &4 尾段批 154 真身(startupWindowTail:FUN_00766466 全屏切换 +
//   restoreGeometry/setWindowOpacity)+ 建窗腿批 154 真身
//   (startupWindowCreate = FUN_0075e0f8 窄面)+ 尾接线段批 188 真身
//   (mainWindowConnectSignals = mainWindow_connectSignals 0076b9ec 全文
//   分段:FUN_0075e0f8 @0075e2c0 尾调 — 恢复门腿承接,见 cpp)。
// 产品挂点:FUN_007626ce 语料内无代码调用者——批 154 裁决:真调用链 =
//   SuperApplication ctor FUN_0075dba4(131B,0023.c:27019)QTimer::
//   singleShotImpl(0,0,app,thunk{1,FUN_00762925,app})@0075dc1f →
//   thunk FUN_00762925(43B,29928)case1 → 7626ce(kuna xrefs 唯一引用
//   0x762935 JMP;.rela.dyn/.data.rel.ro 全扫描零数据引用)→ 接线 =
//   零毫秒单发定时器,非信号;产品落点属 SuperApplication 宿主批,
//   cited 维持(不发明)。

// FUN_005dd560(236B,0019.c:13838)状态文件路径面:根 = appdir/
// profiles.config "path"(s_profiles_config_5d8732 面;测试环境缺该
// 文件 → 空串同相)+ 尾串 "global/reopen.history"(@005dd570 字面)。
QString startupReopenHistoryPath();

// FUN_0075ffcc(504B,0023.c:28400)恢复门:状态文件读 + 魔数 0xb9e7e600
// 掩码门 + 逐窗 FUN_00766c26(payload,flags=1 字面 @28446);失败返
// false(链上走 first-page 失败腿)。historyPath 缺省 = 语料内部面
// (DAT_011c1240);显式实参 = mwctest 注入缝(ProfileLoader 缺省参判例)。
bool startupRestoreGate(MainWindowFace::Slots host, QMainWindow *mainWindow,
                        const QString &historyPath = startupReopenHistoryPath());

// FUN_00766c26(1042B,0023.c:33567)恢复分发壳:&4==0 → s_HistoryHints
// 页挂腿(@33637,007664a2 面真调);&4 → kit.startupSessions 腿
// (批 154 真身:widget(i) cast + 名比较 + kitStartupSessions —
// src/Sessions/WorkspaceLoader.h)+ &4 尾段(startupWindowTail)。
bool startupRestoreDispatch(MainWindowFace::Slots host, QMainWindow *mainWindow,
                            quint32 magic, const QByteArray &payload,
                            quint32 flags);

// mainWindow_connectSignals(1043B,0023.c:36614)全文分段真身
// (批 188):返回宿主槽位对(S3 装配段产物,FUN_007662e6 四件套)。
// 段序照语料 kuna/语料双读 —
//   S1 FUN_0076b9da(18B)= s_wind_actions_76b7c0(457B,36525:
//     wind.actions/user.actions 双源 → ActionFactory 现役真身)+
//     FUN_0076b430(68B,36366:keymap 懒建 + 双源装载,KeymapEngine
//     现役面委托);
//   S2 FUN_0076663e(114B,33272)= QMetaType 注册族探锚
//     (pthread_once + registerNormalizedType ×20)— cited 分段
//     (Qt 底座语义,消费面 KitWindow 批);
//   S3 FUN_007662e6(109B,33100)= MainWindowFace 装配四件套真身
//     (addToolBar(1)/setCentralWidget/bar->hide;槽位 = 返回值);
//   S4 connect×6(qApp↔宿主槽,序照 connectImpl @36645-36718):
//     ① qApp signal0(FUN_0090e018 → activate smo 011a6ce0
//       "14CommanderRobot",kuna read 实读)→ FUN_007662ce(24B
//       guard)→ FUN_00766192(JsEngine 懒建引导)+ FUN_007661dc
//       (QTimer session_throttled_refresh)— 发射源类我方无
//       Q_OBJECT 承载,接线面 cited 分段(铁律 6);
//     ② qApp focusChanged → FUN_0076dcae(MuxPane 焦点 QPointer 对
//       +0xd8/+0xe0 — 宿主槽位未建模,cited);
//     ③④ tools 容器(DAT_011c1240+0x10)信号 0/1(FUN_008fd3d0/
//       fc → smo 0119f720 "Tools" toolAdded/toolRemoved,kuna read
//       实读)→ FUN_0076aee6(keymap JSON 导入腿 = KeymapEngine::
//       loadJsonLeg 现役真身;发射源类 cited);0x82 = Unique|Auto
//       字面照录;
//     ⑤ KitBar(+0x50)kitActivated(FUN_0091a518,smo 011aaea0)→
//       FUN_007656bc(stack setCurrentIndex index<count 门真身);
//     ⑥ stack(+0x58)currentChanged → FUN_00767ba0(27B:+0x50 非空
//       → KitBar 按钮 setChecked(1)+ FUN_00767b4a 活性 QTimer
//       腿 cited);
//   S7 QTimer::singleShotImpl(0,0,host,FUN_0076bdff)(212B:单发
//     0x18 闭包 → windowHandle 非空 → screenChanged → FUN_00765721
//     +0xb0 屏幕指纹写 — 深腿 cited,单发面真身)。
MainWindowFace::Slots mainWindowConnectSignals(QMainWindow *mainWindow);

// FUN_0075e0f8(765B,0023.c:27251)全文真身(批 188 窄面扩张):
//   建窗窄面(startupWindowCreate,WorkspaceLoader 现役批 154)+
//   尾接线段 mainWindow_connectSignals(@0075e2c0,@27327 — 本头
//   mainWindowConnectSignals S1-S7)。
QMainWindow *startupWindowCreateFull(QMainWindow *mainWindow,
                                     const QByteArray &geometry);

void startupChain(MainWindowFace::Slots host, QMainWindow *mainWindow);
