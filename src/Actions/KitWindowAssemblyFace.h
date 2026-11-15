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

// 008b8694(79B,0027.c:75790):父链上溯 dynamic_cast → KitWindow
//   (RTTI 011ab390 = "9KitWindow");未命中 nullptr。菜单/弹窗族共同前置腿。
KitWindowFace *kitWindowAncestor(QObject *object);

// 008ca002(87B,0028.c:11430)TabGroup 弹菜单:menu() 容器 +
//   kitFindOrCreateGroupMenu("TabGroup Popup")(批 189 真身)→ QMenu。
class QMenu;
QMenu *kitTabGroupPopupMenu(KitWindowFace *host);

// ── 面板工厂(s_ExplorerPane_89eed8,1185B,0027.c:56200)─────────────
// 0089ede8(232B)+0089ebe2(278B)面板名归一:不以 "Pane" 结尾(忽略大小写)
//   → 追加 "Pane" @0089ebe2;空串 resize(1,' ') → 首字母 toUpper。
QString kitPaneNameNormalized(const QString &rawName);

// 建面分派表(语料 compare 链顺序,大小写不敏感;objectSize = operator_new 字节)。
struct KitPaneSpec {
	const char *name;
	int objectSize;
	const char *ctor;
};
// 返回 9 条静态表(见 .cpp 逐条地址)。
const KitPaneSpec *kitPaneSpecs(int *count);

// 查面腿:归一名 → findChild<QWidget>(递归)@0089ef1b 命中即返;
//   未命中 → 建面分派(cited:我方 pane 类非 QWidget 承载,不造 glue)
//   → 当前返回 nullptr。尾部 hide + 双 connect(信号 FUN_0091d368/
//   FUN_0091d378 → 槽)cited。
QWidget *kitPanelFindOrCreate(QWidget *kit, const QString &rawName);

// 008b8226(399B,0027.c:75484)页挂:host+0x30 = TabGroup 槽(以实参承接)——
//   insertPage(index, panel, windowTitle, windowIcon, windowTitle)
//   (FUN_005abe1c)@008b825x;idx!=-1 → connect(panel::windowIconChanged →
//   host 槽 FUN_008b842d,cited);select → tabBar->setCurrentIndex(idx)
//   (FUN_005ab5d4)。panel 空 → -1。
class TabGroup;
int kitPanelAdd(TabGroup *tabs, QWidget *panel, int index, bool select);

// 008b881c(485B,0027.c:75873)页恢复(blob 空 → false):
//   >>count >>current → 逐 i:>>panelName >>propBA → blockSignals(current != i)
//   @008b8899 → panel = 工厂(归一名 find-or-create)→ 非空 →
//   setProperty("History", QVariant(propBA))(0xc9e544)@008b892d →
//   kitPanelAdd(tabs,panel,-1,current==i)@008b8901 → 尾 blockSignals(false)。
bool kitPanelsRestore(TabGroup *tabs, const QByteArray &blob);

// King::assembleCentralSplitters(1010B,0028.c:13782):七槽中央树
//   (+0x38..+0x68)+ 朝向/sizes/setCentralWidget(+0x68)。
void kitCentralSplittersAssemble(KitWindowFace *host);
