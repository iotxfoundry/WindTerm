#include "MuxWindow.h"

#include "MuxPaneGroup.h"
#include "MuxPaneView.h"
#include "SplitterGroup.h"
#include "../Sessions/SuperSession.h"
#include "../Utility/ApplicationTheme.h"

#include <QApplication>
#include <QBoxLayout>
#include <QMap>
#include <QSplitter>
#include <QTabBar>
#include <QVBoxLayout>

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

// === restorePaneSplitter(SuperSession*,void*,uint,const PaneDescriptor&) ===
// 转写 mux_restorePaneSplitter(0026:29862,903B)。语料为自由函数
//   (会话宿主*、配置容器 param_2、QSplitter* param_3、页序 param_4、
//   面板描述符 param_5);QSplitter 在调用点以 FUN_008e01ac(muxWindow)
//   形态取自本类(s_session__tmux_842414 @0026:34862 同面)→ 归属本类。
void MuxWindow::restorePaneSplitter(SuperSession *sessionHost, void *configHolder,
                                    unsigned int paneIndex, const PaneDescriptor &desc)
{
	QSplitter *sp = splitter();                       // = param_3(调用点 FUN_008e01ac)
	QWidget *w = sp->widget(static_cast<int>(paneIndex)); // QSplitter::widget @0083ba93
	MuxPaneGroup *group = dynamic_cast<MuxPaneGroup *>(w); // __dynamic_cast 011abe10 @0083baa1
	MuxPaneView *cur = (group != nullptr) ? group->currentPane() : nullptr; // FUN_008de3b2 @0083bab4
	// @0083bab4-c0:currentPane 非空 && pane->+0x30 == desc.paneIndex
	//   (param_5+0x18;描述符字段唯一实证消费面)
	const bool paneMismatch =
	    (cur == nullptr) || (cur->paneIndex() != desc.paneIndex); // @0083bac0
	if (!paneMismatch) {
		// 语料 else 分支 @0083bcf5-bdf0:标题比对 → 不等则改题。
		// 标题 = "%1:%2".arg(desc.paneIndex).arg(map 上界值):
		//   param_2+0x50 为 QMapDataBase*,+0x10 = header.left(root),
		//   节点 +0x08 left/+0x10 right/+0x18 key(int)/+0x20 value
		//   (QMapNode 布局实证;遍历 = QMap::upperBound 内联,else
		//   分支 @0083bd63-c,lowerBound 形 @0083bb27-d4)。
		QMap<int, QString> titles;
		if (configHolder != nullptr)
			titles = *static_cast<const QMap<int, QString> *>(configHolder); // *(param_2+0x50) @0083bd63
		const QString title = QStringLiteral("%1:%2")     // from_ascii @0083bcf5-ff
		                          .arg(desc.paneIndex)    // QString::arg(long) @0083bd03
		                          .arg(titles.upperBound(desc.paneIndex).value()); // 内联遍历 @0083bd10-d8b(无命中 = 空 shared_null)
		if (cur->title() != title) {                      // operator==(pane+0x38) @0083bdcf
			cur->setTitle(title);                         // FUN_008de224 @0083bdd9
			// FUN_008df06e(group,pane,title)(0028:26161,53B):
			//   FUN_005ab6c2(+0x38)(stackIndexOf(pane))== -1 早退 →
			//   FUN_005ab09e(+0x58,index,title)(QTabBar::setTabText
			//   换题;0018:24913 体读 = 比对旧值不等才写)。
			const int idx = group->stackIndexOf(cur);     // FUN_005ab6c2 @008df076
			if (idx != -1)                                // @008df07d
				group->setTabTitle(idx, title);           // FUN_005ab09e @008df083
		}
		return;
	}
	// 会话宿主 QSharedPointer 槽展开 @0083baf5-b10(*param_1+0x1c8 三连判,
	//   同型 FUN_0083be38:30023)→ session 直入;FUN_008da01e(desktop,
	//   desc.paneIndex)@0083bb0e 查面板(本类 findPane,84B 真身;
	//   desktop = muxDesktopGet 解出,见上方转写面注);
	//   返回 0 直接 return @0083bb1a。
	// 勘正:FUN_008da01e 返回 = 面板(MuxPane),非窗口——
	//   遍历容器 *(d+0x38) 节点首槽 *(item) 再 deref item+0x10 得
	//   面板指针,比对键 = 面板 +0x30(paneIndex);命中消费面
	//   FUN_008de224(面板标题)/FUN_008de3e8(加 tab)均为面板面
	//   → 返回 MuxPaneView*(非窗口)。
	MuxPaneView *pane = findPane(muxDesktopGet(sessionHost), desc.paneIndex); // FUN_008da01e(uVar8,param_5+0x18)@0083bb0e
	if (pane == nullptr)
		return;                                       // @0083bb1a(命中 0 即返)
	// 标题合成同 else 分支("%1:%2".arg().arg(map 上界值)lowerBound 形
	//   @0083bb5d-bdd0;无命中 = shared_null 空串)
	QMap<int, QString> titles;
	if (configHolder != nullptr)
		titles = *static_cast<const QMap<int, QString> *>(configHolder); // *(param_2+0x50) @0083bb27
	const QString title = QStringLiteral("%1:%2")     // from_ascii @0083bb5d-61
	                          .arg(desc.paneIndex)    // QString::arg(long) @0083bb6a
	                          .arg(titles.upperBound(desc.paneIndex).value()); // 内联遍历 @0083bb78-d1f
	// MuxPaneGroup 构造第二参 parent = QSharedPointer 解出对象(uVar8)
	//   @0083baf5-b10/29935-39(= muxDesktopGet(sessionHost))。
	if (group == nullptr) {
		group = new MuxPaneGroup(true, reinterpret_cast<QWidget *>(muxDesktopGet(sessionHost))); // s_MuxPaneGroup_8dece0(pvVar5,1,uVar8)@0083bc91-99
		                                              //   (0x40;expandable=1 实证 0026:29939 同面;parent = desktop
		                                              //   QSharedPointer 解出对象,MuxDesktop 未复刻 →
		                                              //   语料 QWidget* 形参直传 reinterpret_cast)
		const int count = sp->count();                // QSplitter::count @0083bca4
		if (static_cast<int>(paneIndex) < count) {
			sp->replaceWidget(static_cast<int>(paneIndex), group); // QSplitter::replaceWidget @0083bcb2
		} else {
			sp->addWidget(group);                     // QSplitter::addWidget @0083bd4c
		}
	} else {
		// 语料 @0083bc10-82:FUN_008de59c(group)==1 时
		//   FUN_008dedae(group,FUN_008de3b2)(拆当前 tab 页,62B,
		//   0028:25986)@0083bdea-ff — detachPane 已落(本批)
		if (group->tabCount() == 1) {                 // FUN_008de59c @0083bdea
			group->detachPane(group->currentPane());  // FUN_008dedae @0083bdf2
		}
	}
	pane->setTitle(title);                            // FUN_008de224 @0083bdff
	// FUN_008de3e8(group,pane,0)(加 tab;normal=0 → "Pinned")@0083be03
	group->addTab(pane, /*normal=*/false);            // 批 77 已落;语料 0 = "Pinned"
}

