#pragma once

#include <QByteArray>
#include <QString>

#include "MainWindowFace.h"

class QMainWindow;

// 批 149(M14-①b)/批 150(M15-①a)启动链 — s_application_lockScreenTimeout_
// 7626ce(510B,0023.c:29843)语料序对位转写;宿主成员槽位与未转写腿逐条
// cited(铁律 3/6,见 cpp 内地址注记),真身化腿:
//   themeGui/lockScreenTimeout 配置读(CTerminalConfig 真单例调面)+
//   失败腿 FUN_0075e3fe(kitWindowRestoreFirstPage,批 142 真身)+
//   恢复门 FUN_0075ffcc(批 150 真身,startupRestoreGate)+ 恢复分发壳
//   FUN_00766c26(startupRestoreDispatch;kit.startupSessions &4 腿
//   s_kit_startupSessions_8d2f7e 3122B cited 挂账)。
// 产品挂点:FUN_007626ce 语料内无代码调用者(信号/vtable 引用,证据
// 不足)→ 不发明 QApplication 信号接线(铁律 3);消费点 = mwctest 级
// 直调(KITWINDOW-RECON Q4 同判)。

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
// (008d2f7e 3122B cited 挂账 — 唯一调用点 flags=1 不可达)。
bool startupRestoreDispatch(MainWindowFace::Slots host, QMainWindow *mainWindow,
                            quint32 magic, const QByteArray &payload,
                            quint32 flags);

void startupChain(MainWindowFace::Slots host, QMainWindow *mainWindow);
