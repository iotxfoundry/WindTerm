#pragma once

#include "MainWindowFace.h"

class QMainWindow;

// 批 149(M14-①b)启动链 — s_application_lockScreenTimeout_7626ce
// (510B,0023.c:29843)语料序对位转写;宿主成员槽位与未转写腿逐条
// cited(铁律 3/6,见 cpp 内地址注记),真身化腿仅:
//   themeGui/lockScreenTimeout 配置读(CTerminalConfig 真单例调面,
//   语料 global_setting_get 调面对位)+ 失败腿 FUN_0075e3fe
//   (kitWindowRestoreFirstPage,批 142 真身)。
// 产品挂点:FUN_007626ce 语料内无代码调用者(信号/vtable 引用,
// 证据不足)→ 不发明 QApplication 信号接线(铁律 3);消费点 =
// mwctest 级直调(KITWINDOW-RECON Q4 同判)。
void startupChain(MainWindowFace::Slots host, QMainWindow *mainWindow);
