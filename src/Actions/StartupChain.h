#pragma once

#include <QByteArray>
#include <QString>

#include "MainWindowFace.h"

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
//   (startupWindowCreate = FUN_0075e0f8 窄面)。
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

void startupChain(MainWindowFace::Slots host, QMainWindow *mainWindow);
