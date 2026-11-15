#pragma once

#include <QStatusBar>

class QMenuBar;
class KitWindowFace;
class CGlobalConfigFace;

// KitWindowAssemblyFace — KitWindow 延迟装配链(批 192,P1 · GUI-MAP ①):
// 语料锚 = FUN_008d3cc2(296B,0028.c:17649)调用序;各段地址见实现处注。
// 铁律 7:本域未过编译门(收尾期首编译修);铁律 1:每句带 vaddr。

// 008c9ee4(159B,0028.c:11376):King::MenuBar::MenuBar(cfg,"Kit",host) +
//   cornerWidget(+0x218)非空 → setCornerWidget(TopRightCorner) +
//   setMenuBar(host)。返回菜单栏。
QMenuBar *kitMenubarAssemble(KitWindowFace *host);

// 00692766(493B,0021.c:18604):状态栏构建(objectName "StatusBar")。
//   container = menu() 面(仅 cited singleShot 腿消费)。
QStatusBar *kitStatusbarBuild(CGlobalConfigFace *container, QWidget *hostPane);

// 008c9f8c(54B,0028.c:11401):构建 → setStatusBar。
void kitStatusbarAssemble(KitWindowFace *host);

// King::assembleCentralSplitters(1010B,0028.c:13782):七槽中央树
//   (+0x38..+0x68)+ 朝向/sizes/setCentralWidget(+0x68)。
void kitCentralSplittersAssemble(KitWindowFace *host);
