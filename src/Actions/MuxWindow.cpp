#include "MuxWindow.h"

#include "MuxPaneGroup.h"
#include "MuxPaneView.h"
#include "SplitterGroup.h"

#include <QApplication>
#include <QBoxLayout>
#include <QSplitter>
#include <QTabBar>
#include <QVBoxLayout>

// === MuxWindow(QString,QWidget*) ===
// 转写 s_MuxWindow_8e0938(0028:27695,289B):
//   QWidget::QWidget(param_1,param_3,0) → vtable=MuxWindow(011ac070 族)→
//   +0x30 QList(shared_null)→ +0x38 ← 0 → +0x40/0x41 ← param_2(标题)→
//   +0x44/+0x4c ← -1 → +0x58 串 shared_null → +0x60 = tr(0xc8c60e,
//   staticMetaObject 011ac2a0)→ +0x68 ← param_3 → +0x78/+0x80 ← 0 →
//   objectName("MuxWindow")@008e09f1 → FUN_008dffa0(装配)→
//   FUN_008dfee8(焦点接线)。
// (mp 笔记 §5 称 FUN_008dfee8 为 +0x78/0x80 初始化,体读证伪:
//   实为 focusChanged connect;见 MuxWindow.h 注。)
MuxWindow::MuxWindow(const QString &title, QWidget *parent)
	: QWidget(parent)
	, m_f30()               // *(this+0x30) = QListData::shared_null @008e0985
	, m_f38(0)              // *(this+0x38) = 0 @008e098d
	, m_f40(title)          // param_1[0x40]=1 / [0x41]=param_2 @008e0995-9a(拷贝构造展开)
	, m_f44(-1)             // *(this+0x44) = -1 @008e09a2
	, m_f48(-1)             // *(this+0x48) = -1 @008e09a6(ctor 8B 写覆盖 +0x44/+0x48 两 int)
	, m_f58()               // *(this+0x58) = QArrayData::shared_null @008e09b2
	, m_f60()               // QMetaObject::tr(this+0x60,011ac2a0,0xc8c60e)@008e099e(字面 cited)
	, m_f68(parent)         // *(this+0x68) = param_3 @008e09a6
	, m_f70(nullptr)        // *(this+0x70) = 0 @008e09ae
	, m_f78()               // *(this+0x78) = 0 / *(this+0x80) = 0 @008e09b6-be
	                        //   (QPointer<MuxPane> 默认构造 = 双槽清零,等价)
{
	setObjectName(QStringLiteral("MuxWindow")); // @008e09f1-a06
	muxWindowAssemble();     // FUN_008dffa0 @008e0a24-30
	connectFocusChanged();   // FUN_008dfee8 @008e0a34-40
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
//   (tmux 发送门;pane+0x160 tmux 位 / FUN_00910898 均未落库 → cited)。
// 语料形参 (pane, cmd);本类调用点仅 sendSelectPane 一处 → 归辖本类。
void MuxWindow::sendSelectPane(MuxPaneView *pane, int paneIndex)
{
	const QString cmd = QStringLiteral("select-pane -t %1").arg(paneIndex); // @0083f86e-f72
	// FUN_0083eaa6 @0083f87d:pane+0x160==1 && !cmd.isEmpty() →
	//   FUN_00910898 — cited — wave-2(MuxPaneView +0x160 tmux 位与
	//   FUN_00910898 发送面未落库,不发明)
	(void)pane; (void)cmd;
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
			// s_king_refreshWidgetStyle(DAT_011c1ce0 单例,bar,0)@008e0e26
			//   — cited — wave-2:体读 00752640(67B)= style()→vtable
			//   0x68/0x60 调 + r12 分叉 repaint;King 单例承载面
			//   (DAT_011c1ce0)未落库 → 不发明
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
			//   ① 标题 QString +0x40/+0x41 非空判定 @008e0f87-92
			//   ② pane index 二次 cast @008e0f9e(011abb90→011a7470,
			//     011abb90 = MuxPane typeinfo)与 +0x48 比对 @008e0fb5
			//   ③ 同步 +0x48 = pane->+0x30 @008e10c7 → 发送腿(见下)
			//   ④ QPointer 存储 @008e0fc7-d4(getAndRef + pane 指针)
			if (!m_f40.isEmpty() &&                      // [0x41]/[0x40] @008e0f87/0f92
			    m_f48 != pane->paneIndex()) {            // pane->+0x30 @008e0fb5
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

// === restorePaneSplitter(void*,void*,uint,void*) ===
// 转写 mux_restorePaneSplitter(0026:29862,903B)。语料为自由函数
//   (会话宿主*、配置容器 param_2、QSplitter* param_3、页序 param_4、
//   面板描述符 param_5);QSplitter 在调用点以 FUN_008e01ac(muxWindow)
//   形态取自本类(s_session__tmux_842414 @0026:34862 同面)→ 归属本类。
//   会话/配置形参(→ FUN_008da01e 查面板面、param_2+0x50 标题 map、
//   描述符 +0x18 序号)未落库 → void* 占位;两处标题 "%1:%2".arg 合成
//   与 FUN_008da01e 查询腿整体 cited。
void MuxWindow::restorePaneSplitter(void *sessionHost, void *configHolder,
                                    unsigned int paneIndex, void *paneDescriptor)
{
	QSplitter *sp = splitter();                       // = param_3(调用点 FUN_008e01ac)
	QWidget *w = sp->widget(static_cast<int>(paneIndex)); // QSplitter::widget @0083ba93
	MuxPaneGroup *group = dynamic_cast<MuxPaneGroup *>(w); // __dynamic_cast 011abe10 @0083baa1
	// 再核:group 非空时 FUN_008de3b2(currentPane)与描述符 +0x18 序号比对
	//   @0083bab4-c0(描述符未落库 → 比对面 cited,见下分支条件)
	const bool paneMismatch = (w == nullptr) || (group == nullptr) || (group->currentPane() == nullptr);
	//   || (*(int *)(paneDescriptor + 0x18) != *(int *)(currentPane + 0x30))
	//   @0083bac0 — cited — wave-2(paneDescriptor 布局未落库)
	if (!paneMismatch) {
		/* 语料 else 分支 @0083bcf5-bdd3:标题比对
		   operator==((pane+0x38),"%1:%2".arg(…)) → 不等则
		   FUN_008de224(setTitle)+ FUN_008df06e — 面板标题槽/
		   FUN_008df06e 未落库 → cited — wave-2 */
		return;
	}
	// FUN_008da01e(uVar8,desc+0x18)@0083bb0e(会话宿主查面板)— cited
	//   — wave-2(会话层未落库);返回 0 直接 return @0083bb1a。
	// 标题 "%1:%2".arg(desc+0x18).arg(map 上界值)@0083bb5d-bdd0 — cited
	//   — wave-2(配置容器标题 map 未落库;合成串仅在命中时复用)。
	if (group == nullptr) {
		// QWidget *parent = 会话宿主容器(*param_1+0x1c8 链)@0083baf5-b10 —
		//   cited — wave-2(会话层未落库;语料 parent = uVar8)
		group = new MuxPaneGroup(true, nullptr);      // s_MuxPaneGroup_8dece0(pvVar5,1,uVar8)@0083bc91-99
		                                              //   (0x40;expandable=1 实证 0026:29939 同面)
		const int count = sp->count();                // QSplitter::count @0083bca4
		if (static_cast<int>(paneIndex) < count) {
			sp->replaceWidget(static_cast<int>(paneIndex), group); // QSplitter::replaceWidget @0083bcb2
		} else {
			sp->addWidget(group);                     // QSplitter::addWidget @0083bd4c
		}
	} else {
		// 语料 @0083bc10-82:FUN_008de59c(group)==1 时
		//   FUN_008dedae(group,FUN_008de3b2)(拆当前 tab 页,62B,
		//   0028:25986)@0083bdea-ff — MuxPane* 文件本批禁改,
		//   FUN_008dedae 转写落点未入库 → cited — wave-2
		if (group->tabCount() == 1) { // FUN_008de59c @0083bdea
			/* FUN_008dedae(group,group->currentPane()) — cited — wave-2
			   (0028:25986;转写落 MuxPaneGroup 写域,本批禁碰) */
		}
	}
	// FUN_008de224(lVar4,local_60)(面板标题写入)+ FUN_008de3e8(group,
	//   lVar4,0)(加 tab;normal=0)— cited — wave-2(面板对象 lVar4 =
	//   FUN_008da01e 结果,会话层未落库;MuxPaneGroup::addTab 已落)
}

