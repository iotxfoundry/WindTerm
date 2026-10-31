#include "MuxWindow.h"

#include "MuxPaneGroup.h"
#include "SplitterGroup.h"

#include <QApplication>
#include <QBoxLayout>
#include <QSplitter>
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
	, m_f4c(-1)             // *(this+0x4c) = -1 @008e09aa
	, m_f58()               // *(this+0x58) = QArrayData::shared_null @008e09b2
	, m_f60()               // QMetaObject::tr(this+0x60,011ac2a0,0xc8c60e)@008e099e(字面 cited)
	, m_f68(parent)         // *(this+0x68) = param_3 @008e09a6
	, m_f70(nullptr)        // *(this+0x70) = 0 @008e09ae
	, m_f78(0)              // *(this+0x78) = 0 @008e09b6
	, m_f80(0)              // *(this+0x80) = 0 @008e09be
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
//   = FUN_008e0bb2(1323B,0028:27798,未读)→ cited — wave-2;
//   调用器 FUN_008e16a0(118B,0028:28254,Qt connectImpl 通用形态,2 参转发)。
void MuxWindow::connectFocusChanged()
{
	// connect(qApp, &QApplication::focusChanged, this, &MuxWindow::onFocusChanged)
	//   @008dff10-4c — 槽体 FUN_008e0bb2 未读,cited — wave-2:
	//   connect 接线本身语料实证(0028:27169),保留槽空体占位,
	//   信号源/实参面照语料(app 级 focusChanged → 本类)。
	connect(qApp, &QApplication::focusChanged,
	        this, &MuxWindow::onFocusChanged);
}

// === onFocusChanged(QWidget*,QWidget*) ===
// 语料 FUN_008e0bb2(0028:27798,1323B)— 未读,不发明。
void MuxWindow::onFocusChanged(QWidget *old, QWidget *now)
{
	(void)old; (void)now;
	/* FUN_008e0bb2 — cited — wave-2(1323B 未读,不发明) */
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

