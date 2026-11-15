#pragma once

#include <QList>
#include <QStatusBar>
#include <QString>

class CGlobalConfigFace;
class KitDockFace;
class KitWindowFace;
class QMenu;
class QMenuBar;
class QSplitter;
class TabGroup;

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

// 008cb0d8(75B,0028.c:12465):QMainWindow::statusBar() → dynamic_cast
//   01196b50(状态栏子类 face)→ 取面;后续 FUN_005a333e(4090B)cited。
class StatusBarFace;
StatusBarFace *kitStatusBarFace(QMainWindow *win);

// 008c9f8c(54B,0028.c:11401):构建 → setStatusBar。
void kitStatusbarAssemble(KitWindowFace *host);

// 008b8694(79B,0027.c:75790):父链上溯 dynamic_cast → KitWindow
//   (RTTI 011ab390 = "9KitWindow");未命中 nullptr。菜单/弹窗族共同前置腿。
KitWindowFace *kitWindowAncestor(QObject *object);

// 008ca002(87B,0028.c:11430)TabGroup 弹菜单:menu() 容器 +
//   kitFindOrCreateGroupMenu("TabGroup Popup")(批 189 真身)→ QMenu。
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
int kitPanelAdd(TabGroup *tabs, QWidget *panel, int index, bool select);

// 008b8a26(143B,0027.c:75960)页显:panel = 工厂(名, KitWindow 祖先)
//   → 非空 → kitPanelAdd(tabs,panel,index,select)。008b8abe(13B)同面
//   index = -1(尾页)。
int kitPanelShow(TabGroup *tabs, const QString &name, int index, bool select);
int kitPanelShowBack(TabGroup *tabs, const QString &name, bool select);

// 008b8acc(175B,0027.c:76005)批量页恢复:名表逐项 kitPanelShowBack +
//   blockSignals 包裹;返回 currentIndex 命中项的 idx(-1 = 无)。
int kitPanelsRestoreList(TabGroup *tabs, const QList<QString> &names,
                         int currentIndex);

// 005abce4(301B,0018.c:25843)页位说明解析:数字直取(int 成功腿);
//   "First"→0 / "Last"→-1(尾插)/ "Before"→max(cur-1,0)/
//   "After"→min(count,cur+1)/ 其他→-1。串 0xd0d1c3 域实读。
int kitTabPositionIndex(TabGroup *tabs, const QString &spec);

// 008b8bb8(44B,0027.c:7604x)按说明插页:index = 解析(spec) →
//   kitPanelShow(tabs,name,index,select)。
int kitPanelShowAt(TabGroup *tabs, const QString &name, const QString &spec,
                   bool select);

// s_tabbar_selectionBehaviorOnRemove_89d860(1346B,0027.c:55345)实为
//   **KitDock 创建腿**(名取自首段配置读):panel 空 → 0;
//   behavior = 配置 "tabbar.selectionBehaviorOnRemove"(QMetaEnum
//   keyToValue,缺省 2);dock = new KitDock(0x58)+ctor(panel,parent)
//   @0089d9d8;dock->tabs->tabBar()->setSelectionBehaviorOnRemove(behavior)
//   (FUN_008b8680 → 005abbc6 公开 API)@0089d9e0;双 connect + 尾部
//   connect(panel::destroyed → dock::deleteLater)@0089daxx。
KitDockFace *kitCreateDock(bool withExpand, QWidget *parent);

// 008d2f7e 中段 splitter 布局段恢复(8d302f-8d3317):
//   三槽序 [+0x38,+0x40,+0x50](FUN_008d7840 实参 = param_1[7]/[8]/[10]);
//   逐 splitter:>>int 页数(逆序页清理 cited)→ 逐页 >>BA → kitDockRestorePage
//   → 尾 >>BA → QSplitter::restoreState。
bool kitSplittersRestore(KitWindowFace *kit, const QByteArray &splitterBlob);

// 008d2f7e states 段(@008d3323-0x8d340x):
//   >>bool → 写 +0x70(语料 pane+0xe = 0xe*8 = 0x70,与 ctor 初值 1 同址);
//   三槽序 [+0x68,+0x58,+0x60](param_1[0xd]/[0xb]/[0xc])→ 逐项 >>BA →
//   QSplitter::restoreState。
bool kitSplittersStatesRestore(KitWindowFace *kit, const QByteArray &statesBlob);

// 恢复链单页腿(008d2f7e 中段 @asm 0x8d3234-0x8d3260):
//   withExpand = kit->+0x50->isAncestorOf(splitter)(rdi=+0x50,rsi=splitter);
//   dock = kitCreateDock(withExpand, kit)(89d860)@0x8d3247;
//   kitPanelsRestore(dock->tabGroup(), pageBlob)(8b881c)@0x8d3255;
//   splitter->addWidget(dock)(QSpin… QSplitter::addWidget)@0x8d3260。
KitDockFace *kitDockRestorePage(KitWindowFace *kit, QSplitter *splitter,
                                const QByteArray &pageBlob);

// 008b84b6(251B,0027.c:75629)按名查页位:归一名 → 逐 i<count
//   stackWidgetAt(i)->objectName() == 名 → i;无 → -1(008b83ee 53B 取页)。
int kitPanelIndexByName(TabGroup *tabs, const QString &rawName);

// 008b83dc(17B)+005ab2cc(73B,0018:258xx)摘页:index 为 -1 直返;
//   stackWidgetAt(index) 空直返;否则 QStackedWidget::removeWidget
//   (param_3 非 0 腿含 close() 门 + deleteLater,此处实参 0)。
void kitPanelRemoveAt(TabGroup *tabs, int index);

// 008b85ba(20B,0027.c:7568x)按名摘页:i = 008b84b6(按名查);
//   i != -1 → 008b83dc(摘页)。无命中直返。
void kitPanelRemoveByName(TabGroup *tabs, const QString &name);

// 008b8b7c(60B,0027.c:7606x)面板开关:按名查到 → 摘页;未查到 →
//   尾插并选中(kitPanelShowBack(name,true))。
int kitPanelToggle(TabGroup *tabs, const QString &name);

// 008b881c(485B,0027.c:75873)页恢复(blob 空 → false):
//   >>count >>current → 逐 i:>>panelName >>propBA → blockSignals(current != i)
//   @008b8899 → panel = 工厂(归一名 find-or-create)→ 非空 →
//   setProperty("History", QVariant(propBA))(0xc9e544)@008b892d →
//   kitPanelAdd(tabs,panel,-1,current==i)@008b8901 → 尾 blockSignals(false)。
bool kitPanelsRestore(TabGroup *tabs, const QByteArray &blob);

// King::assembleCentralSplitters(1010B,0028.c:13782):七槽中央树
//   (+0x38..+0x68)+ 朝向/sizes/setCentralWidget(+0x68)。
void kitCentralSplittersAssemble(KitWindowFace *host);
