#include "MuxWindow.h"

#include "MuxPaneGroup.h"
#include "MuxPaneView.h"
#include "SplitterGroup.h"
#include "TabGroup.h"
#include "../Sessions/SuperSession.h"
#include "../Utility/ApplicationTheme.h"

#include <QApplication>
#include <QBoxLayout>
#include <QMap>
#include <QMessageBox>
#include <QSplitter>
#include <QTabBar>
#include <QTimer>
#include <QVBoxLayout>

#include <algorithm> // std::sort 承接面(FUN_0084c145 introsort 体 cited)

class MuxDesktop; // 0x28 槽;此类未复刻(转写面注见 findPane 调用点)

// === PaneDescriptor ===
// mux_restorePaneSplitter @0026:29862:param_5 = 0x28B POD(QVariant 经
//   FUN_00856450(0026:48104)canConvert 提取,QMetaType size 0x28 注册
//   @00856546;0x28 布局同型 FUN_008de260 0028:25546:0x28 结构体 delete,
//   读 +0x18 refcount、+0x20 裸指针)。唯一实证消费面 = +0x18 int pane
//   序号(@0083bb0e/0f8/ded 查询键/标题 arg/序号比对);其余字段语义
//   未解 — wave-2。结构体类名未解(registerNormalizedType 类型名串
//   在 FUN_00856450 局部,语料未见字面名)→ 匿名布局,不进产品头
//   (铁律 6:无落点不写)。
struct PaneDescriptor {                 // 0x28B;+0x18 int(唯一实证消费面)
    quint64 _0[3];                      // +0x00-0x17:未解 — wave-2
    int paneIndex;                      // +0x18 @0083bb0e/0f8/ded(唯一读面)
    int _1c;                            // +0x1c padding(未读)
    void *f20;                          // +0x20 指针(语义未解 — wave-2)
};

// === PanePosNode(win+0x30 表 0x20 节点,批 162 读体真身化)===
// 语料节点 0x20 @008e14f6 区/S5 追加腿 008e19f0 直译:{int pos(+0x0),
//   int pos2(+0x4,QVariant 头双 int 位 CONCAT44(param_2,param_2)),
//   bool vertical(+0x8,orientation==2 @008e1567),+0xc pad,int* ref
//   (+0x10,Qt 私有 ExternalRefCountData* @008e1550 getAndRef),
//   QObject* pane(+0x18)}。本仓强指针活判定以 QPointer 承接(m_f78
//   惯式判例:QPointer 惯式 getAndRef(pane)@008e0553-72 同批落形)
//   — 活判定 = pane 非空(@008e1459 ref 活 && pane==胜者 同相;
//   布局偏移非铁律约束 — 节点型原批注"未解 cited",本批按消费面
//   建模,不进产品头同 PaneDescriptor 判例)。
struct PanePosNode {
    QPointer<MuxPaneView> pane;         // 强指针活判定(+0x18 语料位)
    int pos;                            // +0x0(QVariant 头低位)
    int pos2;                           // +0x4(高位 @008e14a2 命中写位)
    bool vertical;                      // +0x8(orientation==2 @008e1567)
};

// === MuxWindow(bool,QWidget*) ===
// 转写 s_MuxWindow_8e0938(0028:27695,289B;asm 008e0938-a71 全读):
//   QWidget::QWidget(param_1,param_3,0) → vtable=MuxWindow(011ac088 族)→
//   +0x30 QList(shared_null)→ +0x38 ← 0 → +0x40 BYTE ← 1 @008e0980、
//   +0x41 BYTE ← param_2 @008e0984(byte 写;Ghidra QString 型系 8B 槽
//   对齐误型 — param_2 实参寄存器 ESI 8B 截 R12B,五调用点全 0/1,批 108
//   勘误)→ +0x44/+0x4c ← -1 → +0x58 串 shared_null → +0x60 = tr(0xc8c60e,
//   staticMetaObject 011ac2a0)→ +0x68 ← param_3 → +0x78/+0x80 ← 0 →
//   objectName("MuxWindow")@008e09f1 → FUN_008dffa0(装配)→
//   FUN_008dfee8(焦点接线)。
// (mp 笔记 §5 称 FUN_008dfee8 为 +0x78/0x80 初始化,体读证伪:
//   实为 focusChanged connect;见 MuxWindow.h 注。)
MuxWindow::MuxWindow(bool tmuxBranch, QWidget *parent)
	: QWidget(parent)
	, m_f30()               // *(this+0x30) = QListData::shared_null @008e097d
	, m_f38(0)              // *(this+0x38) = 0 @008e0978
	, m_f40(true)           // *(this+0x40) = byte 1 @008e0980
	, m_f41(tmuxBranch)     // *(this+0x41) = byte param_2 @008e0984(MOV [rbx+0x41],R12B)
	, m_f44(-1)             // *(this+0x44) = -1 @008e098f
	, m_f48(-1)             // *(this+0x48) = -1 @008e098f(ctor 8B 写覆盖 +0x44/+0x48 两 int)
	, m_f58()               // *(this+0x58) = QArrayData::shared_null @008e099e
	, m_f60()               // QMetaObject::tr(this+0x60,011ac2a0,0xc8c60e)@008e09b9(字面 cited)
	, m_f68(parent)         // *(this+0x68) = param_3 @008e09be
	, m_f70(nullptr)        // *(this+0x70) = 0 @008e09c2
	, m_f78()               // *(this+0x78) = 0 / *(this+0x80) = 0 @008e09c2-ca
	                        //   (QPointer<MuxPane> 默认构造 = 双槽清零,等价)
{
	setObjectName(QStringLiteral("MuxWindow")); // @008e09f1-a06
	muxWindowAssemble();     // FUN_008dffa0 @008e0a24-30
	connectFocusChanged();   // FUN_008dfee8 @008e0a29-2c
}

// === splitter() ===
// 转写 FUN_008e01ac(0028:27319,9B)= *(this+0x70)->+0x30
//   (SplitterGroup 的 QSplitter 槽;SplitterGroup.h 内联 splitter 面)。
QSplitter *MuxWindow::splitter() const
{
	return m_f70->splitter(); // FUN_008e01ac @008e01af
}

// === muxWindowAssemble() ===
// 转写 FUN_008dffa0(0028:27199,134B):
//   new QVBoxLayout(无 parent,尾 setLayout 收养)→
//   setContentsMargins/setSpacing(Ghidra 常量折叠 — cited)→
//   new SplitterGroup(this)(FUN_005a2314 @008dfff9,0x48)→ 存 +0x70 →
//   addWidget(+0x70,0,0)→ QWidget::setLayout。
void MuxWindow::muxWindowAssemble()
{
	QVBoxLayout *vbox = new QVBoxLayout;            // operator_new(0x20)@008dffb6
	// QLayout::setContentsMargins / QBoxLayout::setSpacing
	//   (实参 Ghidra 折叠)— cited — wave-2
	m_f70 = new SplitterGroup(this);                // operator_new(0x48)+FUN_005a2314 @008dfff9-ff
	vbox->addWidget(m_f70, 0, Qt::Alignment());     // QBoxLayout::addWidget @008e0016(展开 0,0)
	setLayout(vbox);                                // QWidget::setLayout @008e0024
}

// === connectFocusChanged() ===
// 转写 FUN_008dfee8(0028:27169,183B):
//   qcoreapp_self_get() → QObject::connectImpl(app,
//   &QApplication::focusChanged, this, 槽, functor functor 0x20
//   {1,FUN_008e16a0,FUN_008e0bb2,0}, 0, 0,
//   &QApplication::staticMetaObject)。
//   槽体 = 本类 lambda 槽(dynsym _ZN9MuxWindow14onFocusChangedEP7QWidgetS1_E)
//   = FUN_008e0bb2(1323B,0028:27798,本批真身落码);
//   调用器 FUN_008e16a0(118B,0028:28254,Qt connectImpl 通用形态,2 参转发)。
void MuxWindow::connectFocusChanged()
{
	// connect(qApp, &QApplication::focusChanged, this, &MuxWindow::onFocusChanged)
	//   @008dff10-4c(信号源/实参面照语料:app 级 focusChanged → 本类)。
	connect(qApp, &QApplication::focusChanged,
	        this, &MuxWindow::onFocusChanged);
}

// === sendSelectPane(MuxPaneView*,int) ===
// 转写 FUN_0083f830(0026:32772,105B;call @008e10ce):
//   "select-pane -t %1".arg(paneIndex) → FUN_0083eaa6(pane,cmd)。
// FUN_0083eaa6(0026:32168,25B)= pane+0x160==1 且串非空 → FUN_00910898
//   (tmux 发送门;门体已读 = activate 信号面,但 MuxPaneView +0x160 tmux
//   位成员未落库 → 发射面 cited,见 .cpp)。
void MuxWindow::sendSelectPane(MuxPaneView *pane, int paneIndex)
{
	const QString cmd = QStringLiteral("select-pane -t %1").arg(paneIndex); // @0083f86e-f72
	// FUN_0083eaa6 @0083f87d:pane+0x160==1 && !cmd.isEmpty() →
	//   FUN_00910898(0030:114,42B)= QMetaObject::activate(pane,
	//   staticMetaObject 011a7c00,idx0xd,&cmd)= TerminalWidget 信号 13
	//   "tmuxCommandWritten(QString)"(qmo_extract QMetaObject 权威,
	//   /tmp/opencode/qmo.json;信号面已解,发射已到位 — 但我方
	//   MuxPaneView 无 +0x160 tmux 位成员与 TerminalWidget 委托面
	//   (类未落库)→ 发射不可达,cited 保留 — wave-2)
	(void)pane; (void)cmd;
}

// === isZoomed() ===
// 转写 FUN_008e01a2(0028:27309,9B):尾 jmp FUN_005a23c6(*(this+0x70))
//   = *(SplitterGroup+0x40)!=0(占位页槽;空指针时语料直接崩 — m_f70
//   由装配必建,本仓库判空承接不改变非空路径语义)。
bool MuxWindow::isZoomed() const
{
	return m_f70 != nullptr && m_f70->isZoomed(); // FUN_008e01a2 @008e01a6
}

// === setPaneZoom(MuxPaneView*,bool) ===
// 转写 FUN_008e04ae(0028:27504,1095B,asm 008e04ae-008e0854 全读;
//   Ghidra 参形参折叠按寄存器勘补:rdi=win(this),rsi=pane,edx=confirm):
//   S0:pane==0 → return @008e04ae-b1。
//   S1:qcoreapp_self_get() 返回值弃 @008e04ce(75bd66)。
//   S2:pane 父链上溯 dynamic_cast<MuxPaneGroup>(011abe10)@008e04d6-fa;
//     命中 group;父链尽 → return @008e0505-0a。
//   S3:stackCur = FUN_005a24fc(this+0x70)(zoom 时 stack currentWidget,
//     非 zoom 0)@008e051d-21;cast<QWidget>(011b8aa8)@008e052f-3e。
//     confirm==0:cast 空即返 @008e08cb-8d4(非 zoom 无当前页无可退);
//     confirm!=0:group == stackCurCast 即返 @008e054e-51(pane 组已是
//       zoom 页,免重入)。
//   S4:QPointer 惯式 getAndRef(pane)/getAndRef(group)@008e0553-72
//     (QPointer<MuxPaneView>/QPointer<MuxPaneGroup> 承接);
//     title(d0)= pane->+0x38 增 ref @008e0577-8f。
//   S5:confirm!=0 → title += " [%1]".arg(tr("Zoomed"))@008e059f-088
//     (" [%1]" 0xc8ad1c,tr 0xcb77bb,smo 0x11ac2a0;QString::append)。
//   S6:FUN_008df06e(group,pane,title)@008e0697-a0(两腿都走;
//     stackIndexOf→TabBar::setTabText,本仓库 setTabTitle 同面)。
//   S7:group QPointer 活 @008e06a5-c4:
//     gate 段 @008e06ca-64/8e0764:MuxWindow +0x40 BYTE 旗标清 0
//       (FUN_008dfd9b:mov [win],0x40 ← 0)→ 尾置 1(FUN_008dfd93)。
//       +0x40 建模勘误纠缠(m_f40 QString vs ctor 8e0980/84 BYTE 写,
//       三源同证 +0x40/0x41 = BYTE 双旗标)→ 成员未建模,本段 cited。
//     FUN_005a2518(this+0x70, group, confirm)@008e0796-bd(zoom 页切换,
//       SplitterGroup::toggleZoomPage 真身)。
//   S8:pane QPointer 活 @008e080b-29 → QWidget::setFocus(pane,3)
//     @008e082f-39(ActiveWindowFocusReason)。
void MuxWindow::setPaneZoom(MuxPaneView *pane, bool confirm)
{
	if (pane == nullptr)                                    // S0 @008e04ae
		return;
	(void)qApp;                                             // S1 @008e04ce(值弃,原样)
	MuxPaneGroup *group = nullptr;                          // S2 @008e04d6-fa
	for (QWidget *w = pane; w != nullptr; w = w->parentWidget())
		if ((group = dynamic_cast<MuxPaneGroup *>(w)) != nullptr)
			break;
	if (group == nullptr)
		return;                                             // 008e0505-0a
	QWidget *stackCur = m_f70->isZoomed()
	                        ? m_f70->stackCurrentPage() : nullptr; // S3 @008e051d(FUN_005a24fc)
	// FUN_005a24fc(0018:18632,27B)= zoom?stack->currentWidget():0 —
	//   SplitterGroup::stackCurrentPage() 内联面(见下)。
	const QWidget *stackCurW = stackCur;                    // cast<QWidget> @008e052f-3e
	if (!confirm) {                                         // 008e0548 → 008e08cb
		if (stackCurW == nullptr)
			return;                                         // 008e08cb-8d4
	} else if (group == stackCurW) {                        // 008e054e-51
		return;                                             // pane 组已是 zoom 页
	}
	QPointer<MuxPaneView> paneRef(pane);                    // S4 getAndRef @008e0553
	QPointer<MuxPaneGroup> groupRef(group);                 // @008e0565
	QString title = pane->title();                          // d0 @008e0577
	if (confirm) {                                          // S5 @008e0594-088
		title += QStringLiteral(" [%1]").arg(tr("Zoomed")); // " [%1]" 0xc8ad1c / tr 0xcb77bb
	}
	// S6:FUN_008df06e(group,pane,title)@008e0697-a0 — stackIndexOf 非 -1
	//   才写(setTabTitle 面,批 100 已落)。
	const int idx = group->stackIndexOf(pane);              // FUN_005ab6c2 @008df07e
	if (idx != -1)                                          // 008df083-6
		group->setTabTitle(idx, title);                     // FUN_005ab09e @008df08e
	// S7 gate 段 @008e06ca-64/8e0764(批 108 勘正落码;QScopedValueRollback
	//   直译):gate 体 = FUN_008dfd9b(win)→ +0x40 BYTE ← 0 @008dfd9e,
	//   尾撤防 FUN_008dfd93(win)→ +0x40 BYTE ← 1 @008dfd96(asm 体读
	//   008dfd93-a4;仅 +0x40 参与,+0x41 不触)。
	if (groupRef != nullptr) {                              // 008e06a5-c4(QPointer 活)
		m_f40 = false;                                      // FUN_008dfd9b @008e0764(+0x40←0)
		m_f70->toggleZoomPage(group, confirm);              // FUN_005a2518 @008e07bd
		m_f40 = true;                                       // FUN_008dfd93 @008e07d4-ec(+0x40←1)
	}
	if (paneRef != nullptr)                                 // S8 @008e080b-29
		pane->setFocus(Qt::ActiveWindowFocusReason);        // 008e082f-39(原因 3)
}

// === confirmPaneClose(MuxPaneView*) ===
// 转写 pane_confirmClose(0028:26554,915B,asm 008df6c0-008df9c5 全读;
//   原为自由函数(this=MuxPaneGroup,pane),MuxWindow 上溯在其体内:
//   归辖落点取 this=MuxWindow,group 面改由 caller(MuxPaneGroup)传?不——
//   语料 param_1 = MuxPaneGroup(this),体内上溯 MuxWindow(011ac070)。
//   为保 caller 形态不动,本方法接收 pane;group 由 pane 父链重溯(同
//   008df6dc-f1 面的镜像;上溯 MuxWindow 在 caller 侧已由 MuxPaneGroup
//   消费)。展开:
//   S1:win = caller 上溯(见 MuxPaneGroup);pane==0 → return @008df728-b。
//   S2:title = tr(0xcba508 "Are you sure you want to close the pane
//     \"%1\"?").arg(pane->title())@008df740-76e;cap = tr(0xcba54b
//     "Close Pane")@008df77e-91;smo 0x11ac040(MuxPaneGroup tr 面)。
//   S3:r = QMessageBox::question(win, cap, title, 0x14000, 0)@008df7a7
//     (0x14000 = Yes|No);r != 0x4000(Yes)→ return @008df8ad-b2。
//   S4:expandable([group+0x30])!=0 腿 @008df80d-17:cast<TerminalWidget>
//     (pane)(011abb90→011a7470)非空 → FUN_0083f1f0(pane)="kill-pane -t
//     %1" tmux 面 → MuxPaneView 无 +0x160 tmux 位 → cited(同
//     sendSelectPane 先例);空则直返 @008df832-f。
//   S5:expandable==0 腿 @008df8cb-e7:idx = tabGroup->stackIndexOf(pane)
//     (FUN_005ab6c2)!=-1 → FUN_005ab2cc(tabGroup, idx, 1)(0018:25074,73B
//     asm 全读:widget(idx) 空→返;close() 失败→返;deleteLater;
//     stack->removeWidget(w))——本仓库 TabGroup 面 = stackWidgetAt +
//     close/deleteLater/removeWidget 直译。
//   S6:tabCount = FUN_005abbda(+0x38)!=0 → return @008df8ec-f7。
//   S7:tabCount==0 → QPointer(group) getAndRef 增 ref + QTimer::singleShot
//     (0,group,0x28B 闭包{FUN_008de260,group,ref,pane})@008df8fd-9c5。
//     闭包深腿(0x28B 结构 + FUN_008de260→FUN_008e01b6→FUN_005a29e6
//     splitter 收缩 690B)未建模 → 整段 cited(不发明)。
void MuxWindow::confirmPaneClose(MuxPaneView *pane)
{
	if (pane == nullptr)                                    // S1 @008df728
		return;
	const QString title = tr("Are you sure you want to close the pane \"%1\"?")
	                          .arg(pane->title());          // S2 @008df740-6e(0xcba508,arg @008df76e)
	const QString cap = tr("Close Pane");                   // 0xcba54b @008df77e
	const int r = QMessageBox::question(this, cap, title,
	                                    QMessageBox::Yes | QMessageBox::No); // S3 @008df7a7(0x14000)
	if (r != QMessageBox::Yes)                              // 008df8ad(0x4000 门)
		return;
	// S4/S5 的 expandable 面在 group(MuxPaneGroup)侧 —— 由 caller 携带,
	// 这里按 pane 父链取 group(与语料体内上溯镜像;见头注)。
	MuxPaneGroup *group = nullptr;
	for (QWidget *w = pane; w != nullptr; w = w->parentWidget())
		if ((group = dynamic_cast<MuxPaneGroup *>(w)) != nullptr)
			break;
	if (group == nullptr)
		return;
	if (group->isExpandable()) {                            // S4 @008df80d(0x30!=0)
		// cast<TerminalWidget>(pane)→ "kill-pane -t %1"(FUN_0083f1f0)→
		//   FUN_0083eaa6(+0x160 门)→ FUN_00910898(TerminalWidget idx13
		//   tmuxCommandWritten)—— MuxPaneView 无 +0x160 tmux 位、信号面
		//   未落库 → cited(同 sendSelectPane 先例,不发明)。
		return;                                             // 008df832-f(cast 空直返路径)
	}
	// S5:expandable==0 — stack 摘页(FUN_005ab2cc(group->tabGroup, idx, 1))
	TabGroup *tabs = group->tabGroup();
	const int idx = tabs->stackIndexOf(pane);               // 008df8d2(5ab6c2)
	if (idx != -1) {                                        // 008df8d7
		QWidget *w = tabs->stackWidgetAt(idx);              // 005ab2d6(4bc640 widget)
		if (w != nullptr) {                                 // 005ab2df-e2
			if (w->close())                                 // 005ab2ec-f4(4c1d80 close)
				w->deleteLater();                           // 005ab2fd-300
			tabs->stack()->removeWidget(w);                 // 005ab305-10(4c28d0 removeWidget)
		}
	}
	if (tabs->count() != 0)                                 // S6 @008df8ec-f7(5abbda)
		return;
	// S7:tabCount==0 → singleShot(0) 深腿 — cited(0x28B 闭包/FUN_008de260
	//   链未建模,见头注;不发明)。
}

// === onFocusChanged(QWidget*,QWidget*) ===
// 转写 FUN_008e0bb2(0028:27798,1323B)。信号两实参全程未消费
//   (槽内焦点锚 = this->focusWidget() @008e0ca6,反汇编勘正:
//   receiver = 0x20(%rsp) = this,非 qApp;connect 面 FUN_008dfee8
//   0028:27169)。
void MuxWindow::onFocusChanged(QWidget *old, QWidget *now)
{
	(void)old; (void)now;

	// S0-S1:更新禁更 @008e0c67 — 语料为 functor 对{this,FUN_008dfcd4,
	//   FUN_008dfd89}(metaobject 包装 0028:26974/26994)= rollback 面,
	//   直译语义:进槽 setUpdatesEnabled(false)(FUN_008dfd89),
	//   离槽 setUpdatesEnabled(true)(FUN_008dfd7c,0028:27054 体读 =
	//   mov $0x1 硬恢复 true,非旧值 — 原样保留)。Qt QScopedValueRollback
	//   无法无成员直绑 QWidget 伪属性 → 按二进制观測调用直译。
	setUpdatesEnabled(false);                         // FUN_008dfd89 @008e0c67

	// S2:焦点锚 @008e0ca6。语料 receiver = 0x20(%rsp) = this(MuxWindow):
	//   mov 0x20(%rsp),%rbx → mov %rbx,%rdi → call QWidget::focusWidget
	//   = win.focusWidget()(窗口失活后仍返回窗口内旧焦点件,Qt 语义;
	//   非 QApplication::focusWidget — 首读笔记按后者转写,已按反汇编
	//   勘正;此语义使槽在窗口失焦时 state 保持 Active = 原版行为)。
	QWidget *fw = focusWidget(); // QWidget::focusWidget(this) @008e0ca6

	// S3:findChildren<MuxPaneGroup*>(this,空名)@008e0ce8
	//   (qt_qFindChildren_helper,metaobject 011ac040,recursive=1)
	const QList<MuxPaneGroup *> groups = findChildren<MuxPaneGroup *>(QString());

	// S4-S6:组循环 @008e0d85-0f0d
	for (MuxPaneGroup *group : groups) {
		// S4:findChild<QTabBar*>(空名)@008e0e93;无 tab bar → 下一组
		QTabBar *bar = group->findChild<QTabBar *>(QString());
		if (bar == nullptr)
			continue;
		// S5:旧值 = property("state").toString() @008e0d85-d96;
		//   新值 = isAncestorOf(fw)?"Active":"" @008e0da5-dac
		//   (isAncestorOf 第二实参 Ghidra 丢 = fw 寄存器遗留)
		const QString oldState = bar->property("state").toString();
		const QString newState = bar->isAncestorOf(fw) ? QStringLiteral("Active")
		                                               : QStringLiteral("");
		// S6:不等 → setProperty + 样式刷新 @008e0df8-e26
		if (oldState != newState) {
			bar->setProperty("state", newState); // @008e0e06
			// s_king_refreshWidgetStyle(DAT_011c1ce0,bar,0)@008e0e26 —
			//   00752640(67B)真身已落 King::refreshWidgetStyle
			//   (src/Utility/ApplicationTheme.cpp);repaint=0 语料字面
			King::refreshWidgetStyle(bar, false); // @008e0e26
		}
	}

	// S8:焦点链回溯 @008e0f2e-fc6:isAncestorOf(fw) 门 → qcoreapp_self_get
	//   @008e0f3b(返回值弃)→ 从 fw 沿 parentWidget 上溯,
	//   dynamic_cast(QObject typeinfo→011a7470)命中即止(011a7470 =
	//   MuxPane typeinfo,MuxPaneView;链证 MuxPaneGroup.cpp 注)
	if (isAncestorOf(fw) && fw != nullptr) {           // @008e0f2e/0f40
		for (QWidget *w = fw; w != nullptr; w = w->parentWidget()) { // @008e0f59
			// dynamic_cast @008e0f75( QObject→011a7470);qobject_cast 直译
			auto *pane = dynamic_cast<MuxPaneView *>(w);
			if (pane == nullptr)
				continue;
			// S9:命中 pane @008e0f7f-10d2。
			//   ① +0x41/+0x40 BYTE 旗标双非零判定 @008e0f87-92(byte cmp;
			//     批 108 勘正:原按 QString isEmpty 建模 — asm 无 QString
			//     槽解引用,两 byte 原地 cmp)
			//   ② pane index 二次 cast @008e0f9e(011abb90→011a7470,
			//     011abb90 = MuxPane typeinfo)与 +0x48 比对 @008e0fb5
			//   ③ 同步 +0x48 = pane->+0x30 @008e10c7 → 发送腿(见下)
			//   ④ QPointer 存储 @008e0fc7-d4(getAndRef + pane 指针)
			if (m_f41 &&                                  // byte [win+0x41] @008e0f87
			    m_f40 &&                                  // byte [win+0x40] @008e0f92
			    m_f48 != pane->paneIndex()) {             // pane->+0x30 @008e0fb5
				m_f48 = pane->paneIndex();           // *(this+0x48) @008e10c7
				sendSelectPane(pane, m_f48);         // FUN_0083f830 @008e10ce
			}
			m_f78 = QPointer<MuxPaneView>(pane); // +0x78/0x80 @008e0fc7-d4
			break;                               // @008e0fda
		}
	}

	// S10:更新恢复 @008e1059 段(local_68 门 → FUN_008dfd7c 体读 =
	//   setUpdatesEnabled(true) @0028:27054;rollback 撤防直译)
	setUpdatesEnabled(true);                          // FUN_008dfd7c @008e1059-8f
}

// === MuxDesktop 转写面(仅消费偏移直读;类本体未复刻 — 铁律 6)===
// MuxDesktop(ctor s_MuxDesktop_8da51c,0028:22514,390B)未复刻,
// 转写消费面仅三处(FUN_008da01e 容器遍历 @0028:22186、
// mux_restorePaneSplitter @0026:29862、s_session__tmux_842414 构造挂载
// @0026:34862)。语料布局面:
//   SuperSession +0x1c8 QSharedPointer 数据槽 / +0x1d0 裸指针槽
//     (三连判解出 = QSharedPointer::data 惯式,@0083baf5-b10)。
//   MuxDesktop +0x38 QList 容器(shared_null;遍历面 FUN_008da01e)。
// 按 SuperSession 布局未公开 +0x1c8/+0x1d0 → 语料偏移直读(铁律 1)。
inline MuxDesktop *muxDesktopGet(SuperSession *s) // QSharedPointer 槽展开直译
{
	// *(s+0x1c8) 强指针数据非空且 *(s+0x1c8)+4 refcount 非 0 → *(s+0x1d0)
	//   (@0083baf5-b10/29930-39;QSharedPointer::data 惯式,零自研)。
	const char *base = reinterpret_cast<const char *>(s);
	const void *ref = *reinterpret_cast<void *const *>(base + 0x1c8); // @0083baf7
	if (ref == nullptr || *reinterpret_cast<const int *>(reinterpret_cast<const char *>(ref) + 4) == 0)
		return nullptr;                                  // @0083bafd(解出 0)
	return *reinterpret_cast<MuxDesktop *const *>(base + 0x1d0); // @0083bb02
}

// === findPane(MuxDesktop*,int) ===
// 转写 FUN_008da01e(0028:22186,84B):遍历 desktop->+0x38 QList 容器
//   (shared_null 形;迭代惯式 begin=*(c+8)/end=*(c+0xc)),节点首 8B
//   解引用得 item,*(item+4) 空壳跳过;*(item+0x10) = 面板(MuxPane),
//   面板 +0x30 == paneIndex → 返回该面板指针。消费面三处:0026:29501
//   (F0103 面板名串)、0026:29862(本函数)、0026:42850。desktop 类
//   未复刻(铁律 6)→ void* 传容器宿主,布局直读(见 muxDesktopGet 注)。
//   (同族 FUN_008da226(0028:22312,81B)= desktop 窗口 +0x44 匹配,
//   佐证 MuxWindow +0x44 消费面,MuxWindow.h 注随之勘正。)
//   MuxDesktop 前向声明仅作形参可读名(实参 = muxDesktopGet 解出)。
MuxPaneView *MuxWindow::findPane(void *desktop, int paneIndex)
{
	if (desktop == nullptr) // 容器判空 = 语料 QSharedPointer 槽展开面
		return nullptr;
	// 语料遍历直译:*(d+0x38) = QListData*;begin = base+0x10+begin*8,
	//   end = base+0x10+end*8;*(plVar5) = item(QSharedPointer 槽形态
	//   解引用一次),*(item+0x10) = MuxPane*;比对 *(pane+0x30)。
	const char *d = reinterpret_cast<const char *>(desktop);
	const char *c = *reinterpret_cast<const char *const *>(d + 0x38); // lVar1 = *(d+0x38) @008da190
	if (c == nullptr)
		return nullptr;                                  // 容器未挂(shared_null 形态)
	const qint64 beg = *reinterpret_cast<const int *>(c + 8);   // *(c+8) @008da19e
	const qint64 end = *reinterpret_cast<const int *>(c + 0xc); // *(c+0xc) @008da199
	const void *const *it = reinterpret_cast<const void *const *>(c + 0x10 + beg * 8); // @008da196
	const void *const *stop = reinterpret_cast<const void *const *>(c + 0x10 + end * 8);
	for (; it != stop; ++it) {                           // @008da198-d02
		const char *item = *reinterpret_cast<const char *const *>(it); // *(plVar5) @008da1a9
		if (item == nullptr ||
		    *reinterpret_cast<const int *>(item + 4) == 0) // *(item+4)==0 空壳 @008da1ae-b6
			continue;
		const char *paneP = *reinterpret_cast<const char *const *>(item + 0x10); // *(item+0x10) @008da1b4
		if (paneP != nullptr &&
		    paneIndex == *reinterpret_cast<const int *>(paneP + 0x30)) // *(pane+0x30) @008da1e3
			return reinterpret_cast<MuxPaneView *>(const_cast<char *>(paneP)); // @008da1e9
	}
	return nullptr;                                      // @008da19c
}

// === zoomedPane() ===
// 转写 FUN_008e0428(0028:27473,126B):lVar1 = FUN_005a24fc(*(this+0x70))
//   = m_f70->stackCurrentPage()(zoom 时 stack currentWidget,非 zoom → 0;
//   SplitterGroup 内联面);0 → 返 0;否则 qt_qFindChild_helper(lVar1,空名,
//   smo 011abde0 = MuxPaneView,recursive=1)= stackCurrentPage()->findChild
//   <MuxPaneView*>()。live 调用点 0084dd5a 宿主两处(@0084e155 zoom 拆解
//   腿/@0084eece zoomed 标题比对腿),宿主 5076B 未复刻 → 本批取面真身。
// QUIRKS #33 死腿闭环核对(只注记,不修):zoom 落位后 stackCurrentPage
//   = 占位页 ph(Qt5.15 本机 probe 同相;sgtest f1),ph 无 MuxPaneView
//   子件 → 本取面恒 0 → 宿主 @0084e151 unzoom 腿与 @0084eece " [Zoomed]"
//   追加腿双跳过 = 语料字面同相死路(unzoom 恢复仅余 toggleZoomPage
//   unzoom 腿,而该腿 cast null 已死 — #33 原样)。
MuxPaneView *MuxWindow::zoomedPane() const
{
	QWidget *cur = m_f70 != nullptr ? m_f70->stackCurrentPage()
	                                : nullptr; // FUN_005a24fc @008e042f
	if (cur == nullptr)                        // @008e0434-46
		return nullptr;
	return cur->findChild<MuxPaneView *>(QString()); // @008e045f(qt_qFindChild_helper smo 011abde0)
}

// === paneByIndex(int) ===
// 转写 FUN_008e0a72(0028:27741,303B):qt_qFindChildren_helper(this,空名,
//   smo 011abde0 = MuxPaneView,recursive=1)→ qlist detach 惯式 → 逐节点
//   *(pane+0x30) == param_2 线性扫,首命中释放表返回该 pane;扫尽 → 0。
//   live 调用点 0084dd5a 宿主 @0084e8b2(select/zoom 双旗腿),宿主未复刻
//   → 本批取面真身。
MuxPaneView *MuxWindow::paneByIndex(int paneIndex) const
{
	const QList<MuxPaneView *> panes = findChildren<MuxPaneView *>(QString()); // @008e0ab1
	for (MuxPaneView *pane : panes) {                  // @008e0b8e-c0(qlist 迭代直译)
		if (paneIndex == pane->paneIndex())            // *(pane+0x30) @008e0bb0
			return pane;                               // 首命中 @008e0bb6-b8
	}
	return nullptr;                                    // @008e0b47(扫尽)
}

// === setTitle(const QString&) ===
// 转写 FUN_008e03e4(0028:27444,57B):this+0x60 比对 operator== 相等即返
//   @008e03e4-c;不等 QString::operator= @008e03ee-f4 → FUN_0091e3c8
//   (0030:14120,39B,kuna 体读)= QMetaObject::activate(this,
//   PTR_staticMetaObject_011ac2a0,idx0,&this+0x60)= nameChanged(QString)
//   (MuxWindow smo 011ac2a0;信号名 = 池 0xce7e00 "MuxWindow/nameChanged/
//   name" 面)。
void MuxWindow::setTitle(const QString &title)
{
	if (m_f60 == title)                                 // operator== @008e03ec
		return;
	m_f60 = title;                                      // QString::operator= @008e03ee
	emit nameChanged(m_f60);                            // FUN_0091e3c8 @008e03fa(idx0)
}

// === hasNoPaneChild() ===
// 转写 FUN_008e012c(0028:27281,109B):qt_qFindChild_helper(this,空名,
//   smo 011abde0 = MuxPaneView,recursive=1)@008e0152 → 返回 0 非空判定
//   (CONCAT71(lVar1==0));子件表 refcount 惯式直译(体同 zoomedPane 对偶)。
bool MuxWindow::hasNoPaneChild() const
{
	return findChild<MuxPaneView *>(QString()) == nullptr; // @008e0152-99
}

// === detachWindow(void*,QWidget*) ===
// 转写 FUN_008d9fe0(0028:22169,62B):param_1 = desktop(MuxDesktop 未复刻
//   → void* 容器宿主直读,同 findPane 先例);+0x30 = MuxWindow 页容器
//   TabGroup 室(语料直读同 +0x38 容器先例)。FUN_005ab6c2(stackIndexOf)
//   @008d9fe7 → -1 早退 @008d9feb;FUN_005ab2cc(tab,idx,0)@008d9ff6
//   (0018:25074,73B:widget==0 早退;param_3=0 不走 close/deleteLater
//   腿 → 仅 QStackedWidget::removeWidget)→ QWidget::setParent(win,0)
//   @008da01c(页脱管)。
void MuxWindow::detachWindow(void *desktop, QWidget *win)
{
	const char *d = reinterpret_cast<const char *>(desktop);
	TabGroup *tabs = *reinterpret_cast<TabGroup *const *>(d + 0x30); // *(param_1+0x30) @008d9fe4
	if (tabs == nullptr)                                // 语料零判語料同相(空容器引用性)
		return;
	const int idx = tabs->stackIndexOf(win);            // FUN_005ab6c2 @008d9fe7
	if (idx == -1)
		return;                                         // @008d9feb
	QWidget *w = tabs->stackWidgetAt(idx);              // FUN_005ab2cc @008d9ff6(4bc640)
	if (w == nullptr)
		return;                                         // 005ab2d6-e2
	tabs->stack()->removeWidget(w);                     // 005ab305-10(param_3=0 腿)
	w->setParent(nullptr);                              // QWidget::setParent @008da01c
}


// === 宿主 0084dd5a 转写面辅助(FUN_008da226/008da1f0/008da072 承接面)===
// === retitleGroupPane(MuxPaneView*,const QMap<int,QString>&) ===
// 转写宿主 0x10 活性重题腿(0084ecf0-ef1a,asm 0084ed36-ef1a 窄段全读):
//   组上溯(pane 沿 *(w+8)+0x10 父链 __dynamic_cast→011abe10)@0084edc7-f4;
//   paneIndex = *(pane+0x30) @0084edfc;池 upperBound 形走查
//   (qMapLessThan 形 *d==1 门 @0084ee0a/[d+0x10] 树根走查 +0x18 键比对
//   @0084ee31-49;命中节点 +0x20 值串增 ref @0084ee9f-aa 区)→
//   "%1:%2"(0xc9d359).arg(R12D=组索引).arg(池值)@0084ee7c-9a;
//   zoomedPane(FUN_008e0428)==页 比对 @0084eecd → 命中 append
//   " [%1]".arg(QMetaObject::tr(smo 011a7c00,0xcb77bb "Zoomed"))
//   (" [%1]" 0xc8ad1c)@0084ef84-b6;页 +0x38 title operator!= 才
//   FUN_008de224(win+0x38 setTitle 同型,MuxPane 域 011abde0 smo
//   activate 面 FUN_0091ddb8)+ FUN_008df06e(组 tab 同步,批 100 面)
//   @0084eefd-0b。池生产者写侧(组名来源)未解 → 调用点 cited(不发明)。
void MuxWindow::retitleGroupPane(MuxPaneView *pane,
                                 const QMap<int, QString> &namePool)
{
	// 组上溯 @0084edc7-f4(dynamic_cast<MuxPaneGroup> 011abe10)
	MuxPaneGroup *group = nullptr;
	for (QWidget *w = pane; w != nullptr; w = w->parentWidget())
		if ((group = dynamic_cast<MuxPaneGroup *>(w)) != nullptr)
			break;
	if (group == nullptr)
		return;                                    // @0084ef1a
	const int paneIdx = pane->paneIndex();         // *(pane+0x30) @0084edfc
	// 池 upperBound 形 @0084ee00-4d(QMapDataBase 中序走查直译:
	//   键 <= paneIdx 左行,>paneIdx 右行;终节点键 <= paneIdx 才命中)
	auto it = namePool.upperBound(paneIdx);
	if (it == namePool.begin())
		return;                                    // @0084ef42(无前置键)
	--it;                                          // 命中前置节点 @0084ee49-53
	QString title = QStringLiteral("%1:%2")        // 0xc9d359 @0084ee7c
	                    .arg(paneIdx)              // @0084ee8d-9a
	                    .arg(it.value());          // 池值 @0084ee9f-b3
	if (zoomedPane() == pane) {                    // @0084eecd(FUN_008e0428)
		title += QStringLiteral(" [%1]").arg(tr("Zoomed")); // 0xc8ad1c + tr 0xcb77bb(smo 011a7c00 字面)
	}
	if (pane->title() != title) {                  // 页+0x38 比对 @0084eeff
		pane->setTitle(title);                     // FUN_008de224 @0084eefd
		const int idx = group->stackIndexOf(pane); // FUN_005ab6c2 @008df07e 同面
		if (idx != -1)                             // FUN_008df06e @008df083-6
			group->setTabTitle(idx, title);        // FUN_005ab09e @008df08e
	}
}

// === restorePaneSplitter — mux_restorePaneSplitter(0083ba78,903B)
//     分段真身(批 162 读体;0026.c 0083ba78 全读)逐段:
//   A 现组件核查 @0083ba80-c0:cur = dynamic_cast<MuxPaneGroup>(
//     splitter.widget(paneIndex))→ curPane = cur->currentPane()
//     (FUN_008de3b2 @0083baa8)→ cur && curPane && *(curPane+0x30)
//     == *(desc+0x18) → 有组腿 E;否则走 B-D。
//   B findPane 腿 @0083bac3-e2:pane = FUN_008da01e(desktop 三连解出,
//     desc+0x18)→ 0 即返 @0083bae5。
//   C 标题合成 @0083bb15-c7:"%1:%2"(from_ascii).arg(desc+0x18)
//     .arg(池值)— 池 = *(configHolder+0x50) QMap<int,QString>
//     (@0083bb27-d4 QMapDataBase 走查,upperBound 前置键形 —
//     retitleGroupPane 0084ee00-4d 同形直译;空池 = 空串残槽同相)。
//   D 无组腿 @0083bbd0-08:cur==0 → new MuxPaneGroup(1,desktop 解出)
//     (0x40 ctor)→ splitter.count()>paneIndex → replaceWidget
//     (paneIndex,组)/else addWidget(组)(插入序直译)@0083bb2c-36;
//     cur!=0 且 tabCount==1(FUN_008de59c @0083bbf5)→ currentPane +
//     detachPane @0083bbf5-f8;pane->setTitle(FUN_008de224
//     @0083bc03)+ 组 addTab(pane,0)(FUN_008de3e8 尾参 0 @0083bc08)。
//   E 有组腿 @0083bc46-98:同 C 合成 → pane->+0x38 title operator!=
//     (@0083bc52)→ setTitle + FUN_008df06e(cur,pane,title) 组 tab
//     同步(@0083bc78;stackIndexOf/setTabTitle 面 = retitleGroupPane
//     尾同面直译)。
//   深腿 cited:PaneDescriptor 0x28B 仅 +0x18 paneIndex 实证(结构注);
//     0x20 面板深展开消费端挂 5c 期 Pane 批;kitStartupSessions
//     splitter 流式表 cited 维持(批 158 分面)。
void MuxWindow::restorePaneSplitter(SuperSession *sessionHost, void *configHolder,
                                    unsigned int paneIndex, const PaneDescriptor &desc)
{
	QSplitter *sp = splitter();                      // 接收器 = splitter()
	MuxPaneGroup *cur = nullptr;
	MuxPaneView *curPane = nullptr;
	if (sp != nullptr) {                             // 语料 param_3 直用
		if (QWidget *w = sp->widget(paneIndex))      // A @0083ba80
			cur = dynamic_cast<MuxPaneGroup *>(w);   // __dynamic_cast 011abe10
		if (cur != nullptr)
			curPane = cur->currentPane();            // FUN_008de3b2 @0083baa8
	}
	const bool samePane = cur != nullptr && curPane != nullptr
	    && curPane->paneIndex() == static_cast<int>(desc.paneIndex); // +0x30==+0x18 @0083bab8
	void *desktop = nullptr;                         // @0083bac3 三连解
	MuxPaneView *pane = nullptr;
	if (samePane) {
		pane = curPane;
	} else {
		// 语料 param_1 直解(@0083bac3 mov 0x1c8(%r13) — 调用点恒非
		//   空);本仓测试桩传 null → 零判承接(detachWindow 同先例,
		//   桌面解不出 = pane 不寻 → 返)。
		if (sessionHost != nullptr) {
			desktop = muxDesktopGet(sessionHost);    // @0083bac3-f0
			if (desktop != nullptr)
				pane = findPane(desktop, static_cast<int>(desc.paneIndex)); // FUN_008da01e @0083bad9-e2
		}
		if (pane == nullptr)
			return;                                  // @0083bae5
	}
	// C 标题合成 @0083bb15-c7(池 = *(configHolder+0x50) QMap 本体
	//   @0083bb27;upperBound 前置键,空池 = 空串同相)
	QString poolValue;
	if (configHolder != nullptr) {
		const auto *pool = reinterpret_cast<const QMap<int, QString> *>(
		    reinterpret_cast<const char *>(configHolder) + 0x50); // *(param_2+0x50) @0083bb27
		auto it = pool->upperBound(static_cast<int>(paneIndex));
		if (it != pool->begin())
			poolValue = (--it).value();              // @0083bb4d-c7 前置节点
	}
	const QString title = QStringLiteral("%1:%2")    // from_ascii @0083bb15
	                          .arg(static_cast<int>(desc.paneIndex)) // @0083bb22
	                          .arg(poolValue);       // @0083bb4d-c7
	if (!samePane) {                                 // D 无组腿 @0083bbd0-08
		if (cur == nullptr) {
			cur = new MuxPaneGroup(/*expandable=*/1, // 0x40 ctor @0083bbd0
			    reinterpret_cast<QWidget *>(desktop));
			if (sp->count() > static_cast<int>(paneIndex))
				sp->replaceWidget(static_cast<int>(paneIndex), cur); // @0083bb2c
			else
				sp->addWidget(cur);                  // @0083bb36 插入序
		} else if (cur->tabCount() == 1) {           // FUN_008de59c @0083bbf5
			cur->detachPane(cur->currentPane());     // @0083bbf5-f8
		}
		pane->setTitle(title);                       // FUN_008de224 @0083bc03
		cur->addTab(pane, /*normal=*/false);         // FUN_008de3e8 尾参 0 @0083bc08
	} else {                                         // E 有组腿 @0083bc46-98
		if (curPane->title() != title) {             // +0x38 operator!= @0083bc52
			curPane->setTitle(title);                // FUN_008de224 @0083bc60
			const int idx = cur->stackIndexOf(pane); // FUN_008df06e 面 @0083bc78
			if (idx != -1)
				cur->setTabTitle(idx, title);        // FUN_005ab09e 同面
		}
	}
}

// === splitterRestoreStateShim(闭包体 FUN_0084b8ed,1336B)分面 ===// 闭包尾调 splitter_restoreState(0084b483 1079B,0026:40034 全读;
//   批 158 分面裁决):
//   类型注册面:0x28 "Tmux::SplitterWidget"(0xcb7a13 kuna 实读)/
//     0x20 面板类型(DAT_011c2438/243c 惰性注册)— Qt metatype 底座,
//     真库 QVariant::canConvert 同相承接。
//   几何恢复面(真身,真库委托):param_4 canConvert 0x28 →
//     FUN_008565c0 展取(0x28 POD = orientation 尾 int + QList 段
//     @+0x20)→ QSplitter::setOrientation/setChildrenCollapsible(0)
//     (@0084b582-95;asm 实读 RDI=R12=splitter)/0084bd7a QSplitter::
//     setSizes(sizes 归一 ×100000/Σ @0084bcd8-ec)/尾 QSplitter::
//     restoreState(008d33d1 kitStartupSessions 同面,QList 逐项)。
//   pane 树重建面(cited):项 canConvert 0x28 失败 → 0x20 面板 →
//     mux_restorePaneSplitter(0083ba78 903B,Pane 域;本仓 restore
//     PaneSplitter 转写面已在,PaneDescriptor 0x28B 深展开消费端
//     挂 5c 期 Pane 批);0x28 命中 → 子 QSplitter new+replaceWidget
//     递归闭包(@0084b830-59)。
//   落点形态:宿主 0084e268 闭包以 std::function 回调(sp + 列表段),
//     本 shim 承接回调几何腿;深腿不发明(铁律 6)。
static void splitterRestoreStateShim(QSplitter *sp, const QByteArray &states)
{
	// 语料分面:states = QDataStream 段头序 — 0084b483 表项为
	//   QVariant(0x28 POD)非 QByteArray;QSplitter::restoreState
	//   面在 008d33d1(逐项 QByteArray)与 008d329f(尾单段)。
	//   shim 按尾单段面直喂(0084b483 尾 QSplitter::restoreState
	//   同相 — 整段一喂,项级分派在 pane 树 cited 腿)。
	if (!states.isEmpty())
		sp->restoreState(states);                    // 几何面 = 真库委托(0084b483 尾面)
	// pane 树重建面(0x20→mux_restorePaneSplitter / 0x28→递归闭包)
	//   — 批 162:消费端真身 = MuxWindow::restorePaneSplitter
	//   (0083ba78 分段,A-E 段见上);shim 输入为 QByteArray 流式段
	//   (语料 0084b483 输入 = QVariant 0x28 POD 项级分派,非流式表)
	//   → 项级分派维持 cited(铁律 6;真库 restoreState 几何腿同相)。
}

static bool muxWindowPermLess(const QVariant &a, const QVariant &b); // S4 比较器(宿主区)
static int paneLineHeightInt(MuxPaneView *);        // 005b86c0 桥(cited)
static double paneLineHeightDbl(MuxPaneView *);     // 005b68ce 桥(cited)
static void paneScrollBy(MuxPaneView *, int, int);  // vt+0x1a8 桥(cited)
static void muxSplitterMovedTimerSlot(MuxWindow *win); // 008e1125 槽体(本批真身)

// === muxSplitterMovedTimerSlot — FUN_008e1125(0028:28001,411B;asm
//   008e1125-008e12c0 全读,批 175 槽体真身)。connectImpl 胶水形态:
//   参数 1 = 闭包标识(1 = timeout 派发;0 = 闭包析构 operator delete
//   0x18),参数 2 = 闭包 {0..0x10:win @+0x10}(@008e13a-8e1560 胶水
//   面直译;本仓 lambda 捕 win 同相)。逐段:
//   T0 闭包卫:param_1==0 → delete(param_2,0x18) 直返 @008e112a-d
//     (lambda 析构臂;本仓 lambda 生命周期 Qt 承接,不落)。
//   T1 表尾滚动卫:@008e1138 **(uint*)(win+0x30) = QList end-beg
//     (@008e113a 裸读);≤1 → 直返 @008e113b**(表 ≤1 节点无差分对)。
//   T2 detach ×2 惯式:FUN_008e1ac0(win+0x30,end-beg)@008e1141/56
//     (199B,0028:28447 = QList copy 节点 0x20 逐项 +0x10 refcount
//     ++ 直译;本仓 QList<quint64> 值拷贝同相 — 表 detach 面)。
//   T3 迭代窗:it = beg(@008e1150 [d+0x30][beg*2+4] uint* 形)→
//     end(@008e1158 [3] 位)→ 步进 +0x10(2×uint8;@008e11xx 循环尾)。
//   T4 节点活门:@008e118e-f9 节点 +0x10 强指针非空 && +0x14 refcount
//     非 0 && +0x18 pane 非空(四重合取,asm 直读;本仓 QPointer 非
//     空同相——PanePosNode 活判定批 162 形)。
//   T5 差分除法:pos2-pos1(@008e119b piVar5[1]/[0] = pos2/pos1)→
//     vertical(@008e11a3 char 位)→ 纵腿除 FUN_005b86c0(pane)(int
//     行高:005b5d68 vt+0x1c0(pane+0x58 editor,cmd 0x75ae)→
//     QVariant::toInt — pane 中央编辑器行高);横腿除 FUN_005b68ce
//     (double 同形 cmd 0x75a9 行高 max)。int 截断 @008e11c8/f1。
//   T6 滚动消费:@008e11fb 差非 0 → flag = pos2>pos1(sil 0<v5)→
//     vertical 时 flag+=2(@008e1201-07,cVar10+2 = axis 映射:
//     0=横上 1=横下 2=纵上 3=纵下 — PLAN 0x75b5 axis 1=纵/2=横
//     对位勘正:语料此面 flag 直接为 vtable 轴参,不另译)→
//     pane 活门再证(@008e120a-19 ub 不可达腿照录)→ |差| @008e121e
//     → **(*(pane vt)+0x1a8)(pane, flag, |diff|)** @008e1226-2d
//     (vt+0x1a8 滚动消费,MuxPane 域未复刻 — cited 承接,铁律 6)。
//   T7 表释放(尾 @008e1240-c0):win+0x30 ← shared_null @008e1263-6a
//     → 旧表 FUN_008e1720(29B,0028:28299 = QList unref → 0 时
//     FUN_008dfda4(127B,0028:27094)逐节点 0x10 refcount-- + delete
//     0x20 + QListData::dispose)→ 临时 local_30/38 同对释放。
//     本仓 = 表清空 + 逐节点 delete(QPointer 活判定同相)。
static void muxSplitterMovedTimerSlot(MuxWindow *win)
{
	if (win->table30().size() <= 1)                      // T1 @008e113a-b(end-beg≤1)
		return;
	const QList<quint64> tbl = win->table30();           // T2 detach ×2 惯式值拷贝
	                                                     //   (FUN_008e1ac0 @008e1141/56)
	for (quint64 raw : tbl) {                            // T3 @008e1150 循环
		auto *n = reinterpret_cast<PanePosNode *>(raw);
		if (n->pane.isNull())                            // T4 活门 @008e118e-f9
			continue;
		MuxPaneView *pane = n->pane.data();              // +0x18
		int diff = n->pos2 - n->pos;                     // T5 pos2-pos1 @008e119b
		if (n->vertical)                                 // +0x8 char 位 @008e11a3
			diff /= paneLineHeightInt(pane);             // FUN_005b86c0(cmd 0x75ae)
		else
			diff = static_cast<int>(static_cast<double>(diff) / paneLineHeightDbl(pane)); // FUN_005b68ce(0x75a9)
		if (diff == 0)                                   // @008e11fb
			continue;
		int flag = 0 < diff ? 1 : 0;                     // sil @008e11fb-d
		if (n->vertical)                                 // @008e1201-07(+2 轴映射)
			flag += 2;
		if (diff < 0)                                    // @008e121e
			diff = -diff;
		paneScrollBy(pane, flag, diff);                  // T6 vt+0x1a8(cited)
	}
	win->table30().clear();                              // T7 shared_null 归位 @008e1263
	for (quint64 raw : tbl)                              // FUN_008dfda4 逐节点释放
		delete reinterpret_cast<PanePosNode *>(raw);
}

// paneLineHeight{Int,Dbl}/paneScrollBy — MuxPane 域桥(cited 承接):
//   语料链 008e11c8 区 → FUN_005b86c0/005b68ce(005b5d68 22B =
//   *(pane+0x58 editor) vt+0x1c0(cmd,…) 属性查询 cmd 0x75ae 行高 int /
//   0x75a9 行高 max double,批 64 面)→ 本仓 MuxPaneView 中央编辑器
//   槽(+0x40)无 SCI 分派面 → 桥返回 1/1.0(除法中性元 — 差分比
//   = 原始 pos 差,vtable 面 cited 时行为同相);滚动消费 vt+0x1a8
//   MuxPane 未复刻 → no-op 桥(差分旗/幅值已按语料算毕,仅消费腿
//   空缺,铁律 6 不发明 SCI 面)。(桥体落前向声明区之后,AGENTS 坑 3。)

// === muxSplitterMoved(MuxWindow*,int,int) — lambda 体 ===
// 分段真身(008e12c0 951B,asm 008e12c0-8e14f6 全读;批 158):
//   S0 卫:@008e12d1 +0x41 byte==0 → 返;@008e12da param_3(index)<1 → 返。
//   S1 sender:QObject::sender()(0x4bcd80)@008e12fa → 空 → 返;
//     widget(index-1)(0x4bca30)@008e130f → 空 → 返;
//     orientation(0x4be150)@008e131f 存栈。
//   S2 取面:qt_qFindChildren_helper(w,空名,smo 011abde0,recursive=1)
//     @008e1367(MuxPaneView 全域扫)。
//   S3 极值 pane:@008e13e9-40c 两两 QWidget::mapToGlobal(0x75bd66 同型
//     — 0x4c... 族 vtable +0x1c 槽面)极值选取(orientation==1 纵比 x 低
//     位 dword;否则比 y 高位);胜者 pane 存 pQVar15。
//   S4 表重排 @008e1450-8e +0x30 QList 表 detach ×2(0x20 节点拷贝面
//     FUN_008e1ac0)→ 遍历:节点 +0x10 强指针活 && +0x18==胜者 →
//     节点+4 ← param_2(pos;QVariant 头 int 位直写 @008e14a2)→ 命中
//     旗 QVar14 — 批 162 真身(节点型 PanePosNode,值面直译)。
//   S5 未命中腿:@008e1550 ExternalRefCountData::getAndRef(胜者)→
//     orientation==2 重读(@008e1567)→ 节点 0x20 结构 {pos,pos,
//     refcount,pane}(CONCAT44(param_2,param_2) 双 int + bool 纵横位
//     @local_50)→ FUN_008e19f0(115B,0028:28411 = QList append 0x20
//     节点直译)追加 @008e159c-af — 批 162 真身(QPointer 承接活判定)。
//   S6 QTimer 腿:@008e14f6 +0x38 空 → operator_new(0x20)+QTimer(this)
//     存 +0x38 → connectImpl(timeout,FUN_008e1125 胶水,Qt 直连)
//     @008e15e0-f6;尾 QTimer::start(0)(0x4bf8e0 ESI=0 字面)
//     — 批 162 单发/周期面真身;槽体 FUN_008e1125(411B)批 175
//     真身(muxSplitterMovedTimerSlot,逐段注见函数体)。
// fwd: 静态函数集中前向声明区(AGENTS.md 坑 3)

// paneLineHeight{Int,Dbl}/paneScrollBy 桥体 — MuxPane 域(cited 承接):
//   语料链 008e11c8 区 → FUN_005b86c0/005b68ce(005b5d68 22B =
//   *(pane+0x58 editor) vt+0x1c0(cmd,…) 属性查询 cmd 0x75ae 行高 int /
//   0x75a9 行高 max double,批 64 面)→ 本仓 MuxPaneView 中央编辑器
//   槽(+0x40)无 SCI 分派面 → 桥返回 1/1.0(除法中性元 — 差分比
//   = 原始 pos 差,vtable 面 cited 时行为同相);滚动消费 vt+0x1a8
//   MuxPane 未复刻 → no-op 桥(差分旗/幅值已按语料算毕,仅消费腿
//   空缺,铁律 6 不发明 SCI 面)。
static int paneLineHeightInt(MuxPaneView *) { return 1; }
static double paneLineHeightDbl(MuxPaneView *) { return 1.0; }
static void paneScrollBy(MuxPaneView *, int, int) {}

static void muxSplitterMoved(MuxWindow *win, int pos, int index,
                             QWidget *w0)
{
	if (!win->isTmuxBranch())                        // S0 +0x41 byte @008e12d1
		return;
	if (index < 1)                                   // @008e12da(param_3<1)
		return;
	// 语料 = QObject::sender() 直呼(0x4bcd80;lambda 捕 win 语境 →
	//   sender 落 win 本体)。Qt 语义:splitterMoved 信号发射时 win 的
	//   sender() = 发射 splitter。我方 lambda 闭包无 sender 面 → 按语料
	//   connect 目标直取(connect 第三参 w;批 157 S5 connect 面 @0084e5fd
	//   receiver = win)—— 以 win->findChild 取面等价承接不发明:
	//   语料 sender 消费仅 widget(index-1)/orientation 两读。
	QSplitter *sender = w0 ? qobject_cast<QSplitter *>(w0->parentWidget())
	                         : win->findChild<QSplitter *>(); // S1 @008e12fa(driver 直调时 sender 承接 = win 下首 splitter)
	if (sender == nullptr)
		return;
	QWidget *w = sender->widget(index - 1);          // @008e130f(ESI=index-1)
	if (w == nullptr)
		return;
	const int orientation = sender->orientation();   // @008e131f
	const QList<MuxPaneView *> panes =               // S2 @008e1367
	    w->findChildren<MuxPaneView *>(QString());
	QWidget *best = nullptr;                         // S3 极值 @008e13e9-40c
	for (QWidget *p : panes) {
		if (best == nullptr) {                       // 首件直胜 @008e13d6 形
			best = p;
			continue;
		}
		const QPoint a = p->mapToGlobal(QPoint());       // vt+0x1c 面 @008e13e9
		const QPoint b = best->mapToGlobal(QPoint());    // @008e13f9
		if (orientation == 1) {                      // 纵:比 y(低位 dword)
			if (a.y() < b.y())
				best = p;
		} else if (a.x() < b.x()) {                  // 横:比 x(高位 dword)
			best = p;
		}
	}
	if (best == nullptr)                             // @008e1432
		return;
	// S4 表重排 @008e1450-8e(批 162 真身):win+0x30 节点表 detach ×2
	//   惯式(QList detach 真库承接;节点拷贝 FUN_008e1ac0 面)→ 遍历:
	//   节点 +0x10 强指针活 && +0x18==best → +0x4←pos @008e14a2
	//   (QVariant 头 int 位直写)→ 命中旗 QVar14 @008e14e2。
	bool hit = false;                                // QVar14 @008e14e2
	for (quint64 raw : win->table30()) {             // @008e14b1-e1 迭代直译
		auto *n = reinterpret_cast<PanePosNode *>(raw);
		if (n->pane.data() == best) {                // 活判定同相(见结构注)
			n->pos2 = pos;                           // +0x4←pos @008e14a2
			hit = true;
		}
	}
	if (!hit) {                                      // S5 未命中腿 @008e1550-af
		// getAndRef(胜者)(Qt 私有)→ QPointer 承接(见结构注);
		// 节点 {pos,pos,refcount,pane} @008e19f0(115B,0028:28411
		// = QList append 0x20 节点直译)追加;纵横位 orientation==2
		// @008e1567。
		auto *n = new PanePosNode;
		n->pane = static_cast<MuxPaneView *>(best);
		n->pos = pos;                                // CONCAT44(pos,pos)
		n->pos2 = pos;                               // @008e159c-af
		n->vertical = (orientation == 2);            // @008e1567
		win->table30().append(reinterpret_cast<quint64>(n)); // FUN_008e19f0
	}
	// S6 QTimer 腿 @008e14f6-f6(批 162 单发/周期面真身):+0x38 懒建
	//   QTimer(this,parent=win)+ connectImpl(timeout,FUN_008e1125 胶水,
	//   Qt 直连)@008e15e0-f6 → 尾 start(0)(0x4bf8e0 ESI=0 字面)。
	//   槽体 FUN_008e1125(411B)批 175 真身 = muxSplitterMovedTimerSlot。
	if (win->timerSlot38() == 0) {                   // *(win+0x38) 空 @008e14f6
		QTimer *t = new QTimer(win);                 // QTimer(win) @008e15e0
		// FUN_008e1125 胶水 timeout 派发臂(param_1=1,闭包 win @+0x10)
		//   → 槽体批 175 真身(表差分 → 滚动消费 vt+0x1a8 → 表释放,
		//   逐段注见 muxSplitterMovedTimerSlot)。
		QObject::connect(t, &QTimer::timeout, win,
		    [win]() { muxSplitterMovedTimerSlot(win); },
		    Qt::DirectConnection);                   // Qt 直连 @008e15f6
		win->setTimerSlot38(reinterpret_cast<quint64>(t)); // *(win+0x38)
	}
	reinterpret_cast<QTimer *>(win->timerSlot38())->start(0); // @008e15f6
}

// muxSplitterMovedDriver — S5 接线 lambda 体直调面(宿主 connectImpl
//   @0084e5fd 目标;w0 消费 = sender 承接,见 muxSplitterMoved S1 注)。
// 批 175 timer 槽直调出口(测试/驱动消费 muxSplitterMovedTimerSlot,
//   非 inline 可见面 — 与本函数同判例):
void muxSplitterMovedTimerSlotDriver(MuxWindow *win)
{
	muxSplitterMovedTimerSlot(win);                  // 008e1125 体直调面
}

void muxSplitterMovedDriver(MuxWindow *win, int pos, int index)
{
	muxSplitterMoved(win, pos, index, nullptr);      // w0=null → sender 兜底
}

// findWindowByIndex — FUN_008da278(0028:22336,29B)= FUN_008da226
//   (0028:22312,81B:遍历 desktop+0x30 容器 TabGroup 页,页 cast
//   MuxWindow(011ac070)→ +0x44==param_2 → 返回 index)非 -1 →
//   FUN_008da1f0(0028:22295,53B:stackWidgetAt → __dynamic_cast
//   011ac070)。
static MuxWindow *findWindowByIndex(void *desktop, int windowIndex)
{
	const char *d = reinterpret_cast<const char *>(desktop);
	TabGroup *tabs = *reinterpret_cast<TabGroup *const *>(d + 0x30); // *(desktop+0x30) @008da231
	if (tabs == nullptr)                                // 容器未挂(shared_null 形态,语料零判承接)
		return nullptr;
	int hit = -1;                                       // FUN_008da226 @008da236-d02
	const int count = tabs->count();                    // FUN_005abbda @008da23c
	for (int i = 0; i < count; ++i) {                   // @008da242-6a
		QWidget *page = tabs->stackWidgetAt(i);         // FUN_008da1f0 @008da248(4bc640)
		if (page == nullptr)
			continue;
		auto *w = dynamic_cast<MuxWindow *>(page);      // __dynamic_cast 011ac070 @008da24e
		if (w != nullptr && windowIndex == w->windowIndex()) // +0x44 @008da266
			{ hit = i; break; }                         // @008da26c
	}
	if (hit == -1)                                      // @008da27f
		return nullptr;
	QWidget *page = tabs->stackWidgetAt(hit);           // FUN_008da1f0 @008da1f4
	return dynamic_cast<MuxWindow *>(page);             // __dynamic_cast @008da1fa
}

// setWindowIndex/setAuxFields/windowIndex — 语料 +0x44/+0x4c/+0x50 直译面
//   (写点宿主 0084e705/71c/726;+0x44 消费点 = FUN_008da226 序键)
int MuxWindow::windowIndex() const { return m_f44; }        // *(win+0x44) @008da266
void MuxWindow::setWindowIndex(int idx) { m_f44 = idx; }    // @0084e705
void MuxWindow::setAuxFields(int f4c, int f50)              // @0084e71c/26
{
	m_f4c = f4c;                                        // dword [win+0x4c] @0084e71c
	m_f50 = f50;                                        // dword [win+0x50] @0084e726
}

// moveWindowTab — FUN_008da1bc(0028:22279,32B,asm 8da1bc-8da1ea 全读;
//   批 175 升真):
//   idx = FUN_005ab6c2(*(win+0x30))(0018:25321 = stack +0x60 indexOf)
//     @008da1cb → -1 直返 @008da1d0-d9;
//   尾 FUN_005ab2c2(*(win+0x30),idx,order)(0018:25064,9B =
//     tabBar(+0x58)->moveTab(index,order))@008da1ea 尾跳。
//   live 调用点:宿主 S4 重排腿 @0084ebd1(唯一,order = 遍历序+1
//     LEA EDX,[RBP+0x1] @0084ebcb)。
static void moveWindowTab(MuxDesktop *desktop, MuxWindow *win, int order)
{
	TabGroup *tabs = *reinterpret_cast<TabGroup *const *>(
	    reinterpret_cast<const char *>(desktop) + 0x30); // *(win+0x30) @008da1c7
	if (tabs == nullptr)                                // 语料零判承接(shared_null)
		return;
	const int idx = tabs->stackIndexOf(win);            // FUN_005ab6c2 @008da1cb
	if (idx == -1)                                      // @008da1d0
		return;
	tabs->tabBar()->moveTab(idx, order);                // FUN_005ab2c2 @008da1ea
}

// insertWindowPage — FUN_008da072(0028:22220,314B):desktop+0x30 容器
//   TabGroup → FUN_005abf12(insertPageBack)(页=win,标题=win+0x60,
//   QIcon() 空,tooltip 空)@008da0c4 → assignTabProperty(idx,
//   "Normal"(param_4!=0)/"Pinned"(==0))@008da126。
static void insertWindowPage(void *desktop, int tabOrder, MuxWindow *win, bool normal)
{
	const char *d = reinterpret_cast<const char *>(desktop);
	TabGroup *tabs = *reinterpret_cast<TabGroup *const *>(d + 0x30); // *(param_1+0x30) @008da0bd
	if (tabs == nullptr)                                // 语料零判承接
		return;
	const int idx = tabs->insertPageBack(win, win->windowTitle(), // FUN_005abf12 @008da0c4
	                                      QIcon(), QString());
	tabs->tabBar()->assignTabProperty(idx, normal ? QStringLiteral("Normal") // @008da126
	                                              : QStringLiteral("Pinned"));
}

// desktopWindows — S5 findChildren<MuxWindow>(smo 011ac2a0)承接面
//   (@0084e46c 语料 = qt_qFindChildren_helper(desktop 解出,空名,smo,
//   recursive=1);容器 = desktop+0x30 TabGroup 页遍历,MuxDesktop 未
//   复刻 → 容器遍历直读同 findPane 先例)。
static QList<MuxWindow *> desktopWindows(void *desktop)
{
	QList<MuxWindow *> out;
	const char *d = reinterpret_cast<const char *>(desktop);
	TabGroup *tabs = *reinterpret_cast<TabGroup *const *>(d + 0x30); // *(desktop+0x30) @0084e479 区
	if (tabs == nullptr)
		return out;                                     // shared_null 空 — 语料同相
	const int count = tabs->count();
	for (int i = 0; i < count; ++i) {                   // @0084e4e0-631
		QWidget *page = tabs->stackWidgetAt(i);         // 语料节点直读同面
		if (auto *w = dynamic_cast<MuxWindow *>(page))  // smo cast 面 @0084e566
			out.append(w);
	}
	return out;
}

// === muxOnTmuxWindowsChanged(SuperSession*,const QList<QVariant>&) ===
// 转写 FUN_0084dd5a(0026:41621,5076B,asm 0084dd5a-0084f002 全读;
//   触发 = Screen 信号 28 tmuxWindowsChanged(QList<QVariant>),
//   安装器 s_window_caretStyle_8464ec @0026:37972 connectImpl —
//   docs/SCREEN-SIGNALS.md idx28 表)。语料为自由函数(param_1 = 会话
//   宿主,param_2 = QList<QVariant>*);本仓库 Screen 信号面未落库
//   (src/Sessions/Screen.h 无 Q_OBJECT)→ 落 MuxWindow 静态驱动,
//   供 5c 期信号接线批引用;本批消费真身面 = 宿主取窗/建窗/标题腿。
// 逐段:
//   S0 desktop 三连解 @0084de20-43(*s+0x1c8 强指针 + refcount + *s+0x1d0
//     裸指针,muxDesktopGet 同型)→ 死即整段返 @0084e67f。
//   S1 焦点锚 byte:qcoreapp_self_get(值弃 @0084def6)→
//     QApplication::focusWidget(0x4c2590)@0084defb → null → byte 1
//     @0084df03(0x84e69b 置 [RSP+0x97]=1 腿);非 null → QWidget::
//     isAncestorOf(desktop 解出)(0x4c2a40)@0084df2e → byte 存 [RSP+0x97]。
//   S2 遍历腿 @0084df3a-e0(list 迭代惯式 begin=+0x10+beg*8/end):
//     QVariant→0x58 POD 展取 FUN_00856af2(0026:48432)@0084dfe4
//     ([0]=id int @+4 本仓消费面 = local_98._4_4_ 即 POD+0x4? 语料
//     POD +0x1b4 = id 读 — 本批按 QVariant 直接取 int id 承接)。
//     win = FUN_008da278(desktop,id)(0028:22336:FUN_008da226 +0x44 序
//     键查 → FUN_008da1f0 页 cast)@0084df84/0084e015。
//     标题合成 @0084e031-f3:"%1:%2%3"(0xcb77b3).arg(arg3=[RSP+0x110]
//     上次值).arg(arg2).arg(title 残槽)—— 语料三 arg 面直译:
//     arg(id)(long).arg(local_80=[RSP+0x30] 0x58 POD +0x38 段?)
//     .arg(local_58 +0x20 段)— Ghidra 丢参按 kuna 勘补:仅首 arg(id)
//     与尾 arg(字符串)实证 → 本仓按 "%1:%2%3".arg(id).arg(prev)
//     .arg(prev2) 字面链承接,空值 = 空 QString(铁律 1 字面转写)。
//     win==0 建窗腿 @0084e6bf-e75:operator_new(0x88)→
//     s_MuxWindow_8e0938(win,1,desktop 解出)@0084e6f9(tmuxBranch=1)→
//     +0x44←id @0084e705 → setTitle(win,标题)@0084e710 →
//     +0x4c←[RSP+0x1c0]@0084e71c → +0x50←[RSP+0x1b8]@0084e726 →
//     FUN_008da072(desktop,id+1,win,1)(0028:22220 = TabGroup
//     insertPageBack+assignTabProperty("Normal");尾参 1)@0084e752。
//     win!=0 旗标腿 @0084e0c3-df99(flags byte = POD 头字节):
//     bit1(0x2)|bit5(0x20) → FUN_008da296(desktop,win,标题)
//     (0028:22353 = FUN_008e03e4 setTitle + FUN_005ab09e
//     setTabTitle)@0084e106;bit6(0x40) → +0x4c←[RSP+0x1c0]
//     @0084e11e;bit1 → +0x50←[RSP+0x1b8]@0084e130 并记 local_1b2
//     ([RSP+0x96] = 重排挂起旗)@0084e13a;
//     bit2(0x4)|bit31(负,即 POD 头字节带 0x4 或负号位)→ 拆 zoom 腿
//     @0084e151:FUN_008e0428(win) zoomedPane 非空 →
//     FUN_008e04ae(win,pane,0)(unzoom)@0084e15e-66 →
//     sp = FUN_008e01ac(win)@0084e16e 非空 → findChildren<QSplitter>
//     (空名)@0084e268 → 闭包 restoreState 批 158 shim
//     (splitterRestoreStateShim:几何面真库委托/pane 树 cited);
//     子 splitter 清扫腿
//     @0084e2f1-e3d2:遍历页,页子件无 QObject 父(@0084e2fa
//     *(page+8)+0x10==0)→ deleteLater @0084e6b5;有 QWidget 孙全
//     非 QSplitter(dynamic_cast 0x11b8958)→ 同 deleteLater。
//     bit0(0x10)腿 @0084dfab → findChildren<MuxPaneView>(smo
//     011abde0)@0084ed36 → 组上溯(dynamic_cast<MuxPaneGroup>
//     011abe10)@0084edea → QMap<int,QString> 组名池 upperBound 形
//     (@0084ee00-4d,QMapDataBase 走查)→ "%1:%2"(0xc9d359)
//     .arg(组索引).arg(池值)@0084ee7c-b3 → zoomedPane==页 比对
//     @0084eecd → " [%1]".arg(tr 0xcb77bb "Zoomed") 追加
//     @0084ef84-b6 → 页+0x38 不等 → FUN_008de224 setTitle +
//     FUN_008df06e 组同步 @0084eefd-0b。
//     本段(0x10 活性重题腿)批 158 真身 = MuxWindow::retitleGroupPane
//     (池生产者写侧未解 → 池经形参承载,调用点仍 cited)。批 162
//     生产者写侧读体定案:s_window_visible_layout FUN_0087b76a
//     (3244B)解析 tmux 控制行("window_visible_layout"/
//     "window_raw_flags" 等,0087b9fb 区 split(';')→indexOf(':')
//     键值链 @0087c282-3d2)→ 每 0x58 窗口 POD +0x50 = QVariant
//     (QMap<int,QString> paneId→paneName 池,v39→v6[0x50] 拷贝
//     @0087c2fc-30e)→ 尾 emit 经 FUN_0091939c activate(smo
//     011aa220,idx 11)= windowsChanged(QList<QVariant>)(Tmux 宿主
//     面)→ Screen 信号 28 tmuxWindowsChanged 桥接面(SCREEN-SIGNALS
//     表)。⚠ 语料宿主读侧 0x10 腿池槽 [RSP+0x200] 全函数无写点
//     (0084ee00/ef5a/ef74 三读,字节级扫描证)→ 原版读未初始化槽
//     = 原版 bug(铁律 2 原封不修)→ 调用点维持 cited(池传播链
//     不可达,不发明承接)。
//   S3 尾扫腿 @0084e7d1(第二遍同 list):win 再查 FUN_008da278
//     @0084e83c;bit2|负 → 组摘腿 @0084e854-8a2:sp = FUN_008e01ac
//     非空 → findChildren<MuxPaneGroup>(smo 011ac040)@0084e9cd →
//     遍历 @0084ea2b-52:FUN_008de59c(group)==0(空组)→
//     FUN_008e01b6(win,group)(0028:27463 = +0x70 removePage thunk
//     本仓 SplitterGroup::removePage 同面)@0084ea42。
//     id([RSP+0x1bc])!= -1 且 paneByIndex 命中 @0084e8ae-b6:
//     '*' 旗(FUN_00876f8e = POD+0x40 串 indexOf('*')0027:19483)→
//     FUN_008e034a(win,pane,[RSP+0x97],pane->+0x30)(0028:27416 =
//     组上溯 select-pane 焦点腿 FUN_008df51c + setFocus)@0084e8db;
//     'Z' 旗(FUN_00876fd6 indexOf('Z')0027:19507)且 bit2|负 →
//     FUN_008e04ae(win,pane,1)(zoom)@0084e907。
//     bit5 且 '*' → FUN_008da43c(desktop,win,win->+0x44)(0028:22467 =
//     +0x4c←param_3!= -1 门 + FUN_005ab6cc 组同步)@0084e94d。
//   S4 重排腿 @0084ea9d(local_1b2 且 list 非空)批 158 壳级真身:
//     new int[n] 归序 0..n-1(@0084eae0-b0)→ sort 族深腿 cited
//     (FUN_0084c145 7044B introsort/0084beec 384B 堆排/0084c0b3 146B
//     插入序/0084c06c 71B 上浮/0084be6a 122B 比较器 = QVariant 双展取
//     FUN_00856af2 后 int<int @0026:40337;排序键 POD 序字段未实证)
//     → 逐 id:FUN_008da278 → FUN_008da1bc(desktop,win,序+1)→
//     FUN_005ab6c2(stackIndexOf)→ FUN_005ab2c2(QTabBar::moveTab)
//     @0084ebd1;桌面解出活判定 = session +0x1c8 强指针槽(同
//     muxDesktopGet 面,@0084ebb9-d0 asm 实读;死 → 该窗跳过)。
//     批 162 升真身:比较器 0084be6a(122B)+ 归序门/数组面落码
//     (muxWindowPermLess/muxWindowsReorder,见函数体);introsort
//     体 0084c145 7044B + moveTab 0084da1bc cited(std::sort 承接
//     同 introsort 语义,libstdc++ 真库委托判例同 yaml-cpp 面)。
//     批 175 moveTab 腿升真:FUN_008da1bc(32B,asm 8da1bc-8da1ea 全读)
//     = stackIndexOf(FUN_005ab6c2,+0x60 indexOf)非 -1 →
//     FUN_005ab2c2(9B,0018:25064)= tabBar(+0x58)->moveTab(index,
//     order)——本仓 TabGroup::stackIndexOf + tabBar()->moveTab 同面
//     落 moveWindowTab(见函数体);插入序序+1(LEA EDX,[RBP+1]
//     @0084ebcb)。
//   S5 splitterMoved 接线腿 @0084e402-637:desktop 活 →
//     findChildren<MuxWindow>(smo 011ac2a0)@0084e46c → 遍历 →
//     findChildren<QSplitter>(空名,GOT 0x11b8f70)@0084e518 →
//     QObject::connectImpl(splitter,QSplitter::splitterMoved,win,
//     lambda FUN_008e12c0,胶水 FUN_00852930,type 0x80)@0084e5fd
//     (lambda 批 158:S0-S3 几何/取面真身,S4-S6 表值+定时器 cited)。
void muxOnTmuxWindowsChanged(SuperSession *sessionHost, const QList<QVariant> &windows)
{
	void *desktop = muxDesktopGet(sessionHost);         // S0 @0084de20-43
	if (desktop == nullptr)
		return;                                         // @0084e67f(整段返)
	// S1 焦点锚 byte([RSP+0x97])
	qint8 focusAnchor;
	QWidget *fw = QApplication::focusWidget();          // 0x4c2590 @0084defb
	if (fw == nullptr)
		focusAnchor = 1;                                // @0084df03(0x84e69b 置 1 腿)
	else
		focusAnchor = static_cast<qint8>(
		    reinterpret_cast<QWidget *>(desktop)->isAncestorOf(fw)); // 0x4c2a40 @0084df2e
	// S2 主遍历(list 惯式直译)
	QString prevTail;                                   // [RSP+0x110] 链尾 arg 槽(语料值域未解字面承接)
	for (const QVariant &entry : windows) {             // @0084df3a-e0
		// FUN_00856af2 POD 展取:语料 0x58 POD;本仓消费面 = id int
		// (POD+0x4? — 语料 [RSP+0x1b4] = id 读点)与头 flags byte。
		const int id = entry.toInt();                   // local_98._4_4_ = [RSP+0x1b4] @0084dfe4
		const quint8 flags = 0;                         // [RSP+0x1b0] 头字节 @0084df99(byte 门)
		                                                //   批 158 旗标字节布局定案(实读):0x58 POD
		                                                //   头 = FUN_00876ee6 初始化 0x2f(74B,
		                                                //   0027:19430 全读)= byte0 0x2f + qw 双 -1
		                                                //   + 三 shared_null + 0/0x80000000 + 三容器
		                                                //   空槽;生产者写侧 = s_window_visible_layout
		                                                //   _87b76a(3244B)byte 差分位(0x7f 掩码族
		                                                //   @0087c282-c3b3:bit0/1=xy 变位,bit2/3/5
		                                                //   =三串不等,bit6=int 差,bit7='Z' 旗
		                                                //   FUN_00876fd6,bit4=池名差)→ 布局 =
		                                                //   全 byte 位旗(bit0-7),无 0/1 之外整值
		                                                //   写;消费点写侧实证同相(宿主 0084df99
		                                                //   只 byte 门)。批 157 wave-2"0 直译"
		                                                //   按实读定案:**旗标腿不升** — 生产者
		                                                //   87b76a 3244B >500B 且 pane 域 diff 面
		                                                //   未建模 → 维持 0 路径(语料可变旗全走
		                                                //   同 0 门;登记 PHASE5)。
		const QString title = QStringLiteral("%1:%2%3") // 0xcb77b3 @0084e031
		                          .arg(id)              // QString::arg(long) @0084e069
		                          .arg(prevTail)        // @0084e085
		                          .arg(prevTail);       // @0084e0a6(残槽同源字面)
		MuxWindow *win = findWindowByIndex(desktop, id); // FUN_008da278 @0084df84/015
		if (win == nullptr) {                           // 建窗腿 @0084e6bf
			win = new MuxWindow(/*tmuxBranch=*/1,       // s_MuxWindow_8e0938(win,1,…)
			    reinterpret_cast<QWidget *>(desktop));  // @0084e6f9(desktop 解出直传)
			win->setWindowIndex(id);                    // +0x44←id @0084e705
			win->setTitle(title);                       // FUN_008e03e4 @0084e710
			win->setAuxFields(0, 0);                    // +0x4c/+0x50←[RSP+0x1c0/0x1b8] @0084e71c/26
			                                            //   (POD 源值未解 → 0 字面 — wave-2)
			insertWindowPage(desktop, id + 1, win, 1);  // FUN_008da072 @0084e752(normal=1)
			continue;                                   // @0084e757→df99→dfa1→dfb1(旗 0 全跳)
		}
		// win!=0 旗标腿 @0084e0c3(语料 flags byte 全 0 路径直译:
		//   bit1/5/6/2/0x10 全空 → 残槽析构 + 下一项)
		(void)flags;                                    // 语料字面:未解 POD 头字节 — wave-2
		(void)focusAnchor;                              // S9 同步面焦点锚(仅消费于旗腿)
	}
	// S3 尾扫/S4 重排/S5 接线:语料旗标门全走 0 路径(同上 flags cited);
	//   S4 重排腿批 162 落值面(gate+归序+比较器,见下)、S5 接线腿与
	//   flags 无关 — live:
	// S4 重排腿 @0084ea9d-ebd1:local_1b2 重排挂起旗(bit1 腿写
	//   @0084e13a,置 0 @0084df69;旗腿 cited → 本仓恒 false 门同相)+
	//   list 非空 → 归序数组 new int[n] 0..n-1(@0084eae0-b0)→
	//   FUN_0084c145 introsort(7044B cited,std::sort 承接)+ 比较器
	//   FUN_0084be6a 真身 → 逐序 findWindowByIndex → FUN_008da1bc
	//   moveTab(序+1)——批 175 升真:moveWindowTab(stackIndexOf
	//   非 -1 → tabBar()->moveTab);桌面活判定 = session +0x1c8
	//   强指针槽(@0084ebb9-d0;死 → 该窗跳过,muxDesktopGet 同面)。
	const bool reorderPending = false;               // [RSP+0x96] @0084df69 置 0
	if (reorderPending && !windows.isEmpty()) {      // @0084ea9d 门(恒关同相)
		QList<int> perm;                             // new int[n] @0084eae0
		for (int i = 0; i < windows.size(); ++i)     // 0..n-1 @0084eae7-b0
			perm.append(i);
		std::sort(perm.begin(), perm.end(),          // FUN_0084c145 体 cited
		    [&windows](int x, int y) {
			    return muxWindowPermLess(windows[x], windows[y]); // 0084be6a 真身
		    });
		for (int i = 0; i < perm.size(); ++i) {      // 逐序 @0084eb9f-d1
			MuxWindow *w = findWindowByIndex(desktop, perm[i]); // FUN_008da278
			if (w != nullptr && muxDesktopGet(sessionHost) != nullptr) // @0084eba4/ebb9-d0
				moveWindowTab(reinterpret_cast<MuxDesktop *>(desktop), w,
				              i + 1);                        // FUN_008da1bc @0084ebd1
		}
	}
	// S5 splitterMoved 接线 @0084e402-637
	const QList<MuxWindow *> wins =
	    desktopWindows(desktop);                        // findChildren(smo 011ac2a0)@0084e46c
	for (MuxWindow *w : wins) {                         // @0084e4e0-631
		const QList<QSplitter *> sps = w->findChildren<QSplitter *>(QString()); // @0084e518
		for (QSplitter *sp : sps)                       // @0084e566-611
			QObject::connect(sp, &QSplitter::splitterMoved, w, // connectImpl @0084e5fd
			        [w, w0 = w](int pos, int index) {
				muxSplitterMoved(w, pos, index, w0);    // FUN_008e12c0 批 158:S0-S3 真身/S4-S6 cited
			},
			Qt::QueuedConnection);                      // type 0x80 = Qt::QueuedConnection
	}
}

// 窗口序比较器 — FUN_0084be6a(122B,0026:40337)真身:双 QVariant
//   展取(FUN_00856af2 0026:48432 → 0x58 注册型 POD 直读 +0x8 int
//   @0084c4b2 区 local_f0/local_154._4_4_;非注册 → QVariant::convert
//   int,失败 = 无序)→ int<int。本仓 0x58 POD 未建模 → convert int
//   腿承接(toInt 同相)。批 175 无效 QVariant 夹具实测(验收 3):
//   a/b 同为无效 QVariant 时语料腿:两展取均 convert 失败 → POD 走
//   FUN_00876ee6 初始臂(asm 876f0d dword[+0x30]=0,可比 int 槽
//   初始 0)→ 0<0 false;toInt 腿:0<0 false — **同相**(invalid 对
//   invalid 双 false 零差);混合腿 a 有效 b 无效:语料 b POD +0x8
//   = 0 → a_int<0,toInt 同相。夹具 = sgtest k2;注记闭环,cited
//   差异挂账撤。
static bool muxWindowPermLess(const QVariant &a, const QVariant &b)
{
	return a.toInt() < b.toInt();                    // @0084be9e-b06 convert 腿
}

