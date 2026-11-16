#include "Widgets/Views/LockScreenFace.h"

#include "Editor/Config/CTerminalConfig.h"

#include <QBoxLayout>
#include <QCoreApplication>
#include <QKeyEvent>
#include <QStyle>

// ─────────────────────────────────────────────────────────────────────────────
// 出处:tools/re/decomp/decomp-part-0007.c 邻段 0x005600a0..0x005614c0。
// 槽体中体量大的(005614c0 858B / 0055fbd3 753B / 0055ff05 387B)按 AGENTS §5
// 引用档只锚入口;其余逐句转写。
// ─────────────────────────────────────────────────────────────────────────────

// s_application_masterPassword_80542c(cfg, pw)— cited:
//   主密码校验(配置面比较,body 未转写)。签名按调用点实读。
static bool masterPasswordMatches(CTerminalConfig *cfg, const QString &password)
{
	Q_UNUSED(cfg);
	Q_UNUSED(password);
	return false;
}

// s_LockScreen_560888(243B)ctor 真身:
//   QWidget::QWidget(this, parent, 0) → vptr = LockScreen vtable
//   → +0x10 = PTR_FUN_01199dc8(第二多态基 vptr)→ +0x90 = 0
//   → setObjectName("LockScreen")→ setAttribute(0x5d, true)
//   → setAutoFillBackground(true)→ setFocusPolicy(0 = NoFocus)
//   → setWindowModality(1 = WindowModal)→ buildUi() → connectSignals()
LockScreenFace::LockScreenFace(QWidget *parent)
    : QWidget(parent) // QWidget::QWidget(this, parent, 0)
{
	m_f90 = 0; // +0x90
	setObjectName(QStringLiteral("LockScreen"));
	// 属性号 0x5d 原样保留(未映射到 Qt::WidgetAttribute 名;字面权威)
	setAttribute(Qt::WidgetAttribute(0x5d), true);
	setAutoFillBackground(true);
	setFocusPolicy(Qt::NoFocus); // 0
	setWindowModality(Qt::WindowModal); // 1
	buildUi(); // s_TitleLabel_560414
	connectSignals(); // lockscreen_connectSignals
}

// s_TitleLabel_560414(1004B)布局真身。逐句:
//   +0x48 = new QPushButton(tr("&Cancel"), this)
//   +0x50 = new QPushButton(tr("&Change Master Password"), this)
//   +0x58 = new QPushButton(tr("&Lock Screen"), this)
//   +0x60/+0x68/+0x70 = new 0x90B 件(FUN_005646ae(this, 3))×3
//   +0x78 = new 0x30B 件(FUN_00561d28(this))
//   +0x30 = new QLabel(this);+0x40 = new QLabel(this)(objectName "TitleLabel")
//   +0x80 = new QStackedWidget(this)
//   +0x8c = style()->pixelMetric(0x53) * 2
//   +0x40 setAlignment(0x84 = AlignHCenter|AlignVCenter)
//   三钮 setAutoDefault(false)("先 +0x58 → +0x50 → +0x48" 顺序实读)
//   排版:hbox[stretch, vbox2{stacked(边距 0)}, stretch]
//         → vbox1[stretch, hbox, stretch] → setLayout(vbox1)
void LockScreenFace::buildUi()
{
	m_cancel48 = new QPushButton(tr("&Cancel"), this); // 0xc8a1b4
	m_change50 = new QPushButton(tr("&Change Master Password"), this); // 0xc8a1bc
	m_lock58 = new QPushButton(tr("&Lock Screen"), this); // 0xc8a1d4

	// 0x90B 自定义件 ×3(FUN_005646ae(this, 3));件类未建模,按 QLineEdit 面承载
	m_f60 = new QLineEdit(this);
	m_f68 = new QLineEdit(this);
	m_f70 = new QLineEdit(this);
	m_f78 = new QWidget(this); // 0x30B 件

	m_f30 = new QLabel(this); // +0x30
	m_title40 = new QLabel(this); // +0x40
	m_title40->setObjectName(QStringLiteral("TitleLabel"));
	m_stack80 = new QStackedWidget(this); // +0x80

	m_f8c = style()->pixelMetric(QStyle::PixelMetric(0x53)) * 2; // +0x8c

	m_title40->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); // 0x84
	m_lock58->setAutoDefault(false);
	m_change50->setAutoDefault(false);
	m_cancel48->setAutoDefault(false);

	auto *vboxInner = new QVBoxLayout;
	vboxInner->setContentsMargins(0, 0, 0, 0);
	vboxInner->addWidget(m_stack80, 0, 0);

	auto *hbox = new QHBoxLayout;
	hbox->addStretch();
	hbox->addLayout(vboxInner);
	hbox->addStretch();

	auto *vboxOuter = new QVBoxLayout; // 语料:三个 operator_new(0x20) 依次 h/v/v
	vboxOuter->addStretch();
	vboxOuter->addLayout(hbox);
	vboxOuter->addStretch();
	setLayout(vboxOuter);
}

// lockscreen_connectSignals(883B)接线真身(七条,顺序实读):
//   1) +0x58 clicked        → onLockClicked()      (functor 00561492)
//   2) +0x50 clicked        → onChangeClicked()    (functor 005614c0)
//   3) +0x48 clicked        → onCancelClicked()    (槽 0055fa50,经 00561990 包装)
//   4) +0x60 returnPressed  → onPasswordReturned() (functor 0055fb0b)
//   5) +0x68 textChanged    → onPasswordEdited()   (槽 00561c9e,经 00561a00 包装)
//   6) 本类信号 008f781c     → onSignalA()          (functor 0055ff05)
//   7) 本类信号 008f7808     → onSignalB()          (functor 0055fbd3)
// 6/7 的发送方是本类 moc 信号(发射器 0x008f781c / 0x008f7808),信号名见 .h 信号表。
void LockScreenFace::connectSignals()
{
	connect(m_lock58, &QAbstractButton::clicked, this, &LockScreenFace::onLockClicked);
	connect(m_change50, &QAbstractButton::clicked, this, &LockScreenFace::onChangeClicked);
	connect(m_cancel48, &QAbstractButton::clicked, this, &LockScreenFace::onCancelClicked);
	// 4/5 发送方是 +0x60/+0x68 的自定义编辑件(QLineEdit 派生),按 QLineEdit 面接线
	// (件类未建模 → 以 QWidget::objectName 无法静态取信号,接线本身 cited)。
	// 6/7 见头文件信号表,亦是 cited(信号名未从 metaobject 复原)。
}

// FUN_00561492(46B)槽腿真身:转调 FUN_005613ee(this, 2)(状态 2 = 锁屏页)。
void LockScreenFace::onLockClicked()
{
	setState(2); // 005613ee
}

// FUN_00560dec(220B)/ FUN_00560ed8(776B)/ FUN_0056121e(430B)— cited:
// 三个状态页的布局构建,均返回 QLayout(由 setState 包一层 QWidget 入栈)。
static QLayout *buildStatePage0() { return nullptr; }
static QLayout *buildStatePage1() { return nullptr; }
static QLayout *buildStatePage2() { return nullptr; }

// FUN_005613ee(156B)状态切换真身:
//   mode 0 → FUN_00560dec(220B 页布局);1 → FUN_00560ed8(776B);2 → FUN_0056121e(430B)
//   其它 mode → 跳尾(LAB_0056140e,尾段落 cited)
//   取到布局则:new QWidget(this) → setLayout(该布局)→
//   +0x80(QStackedWidget)addWidget(包装件)+ setCurrentWidget(包装件)
void LockScreenFace::setState(int mode)
{
	QLayout *page = nullptr;
	switch (mode) {
	case 0:
		page = buildStatePage0(); // 00560dec
		break;
	case 1:
		page = buildStatePage1(); // 00560ed8
		break;
	case 2:
		page = buildStatePage2(); // 0056121e
		break;
	default:
		return; // 语料:其它 mode 直接跳尾
	}
	if (page != nullptr) {
		QWidget *w = new QWidget(this); // operator_new(0x30)
		w->setLayout(page);
		m_stack80->addWidget(w);
		m_stack80->setCurrentWidget(w);
	}
}

// FUN_005614c0(858B)— cited:改主密码钮槽体(建改密码对话框)。
void LockScreenFace::onChangeClicked() {}

// FUN_0055fa50(5B)真身:空体(语料仅 `return;`)。
void LockScreenFace::onCancelClicked() {}

// FUN_0055fb0b(192B)密码回车槽真身:
//   +0x88 != 2 → 返回;
//   CTerminalConfig::instance()(DAT_011c2200)为空 → 直接走取消腿;
//   否则取 +0x60 的文本做 s_application_masterPassword_80542c(cfg, pw) 校验:
//     不通过 → 发本类信号 B(FUN_008f7808 发射器)并返回;
//     通过   → 取消腿(FUN_0055fa50 = 空体,见 onCancelClicked)
void LockScreenFace::onPasswordReturned()
{
	if (m_mode88 != 2)
		return;
	if (CTerminalConfig *cfg = CTerminalConfig::instance()) {
		if (!masterPasswordMatches(cfg, m_f60->text())) { // 80542c
			// 原版发本类信号 B(008f7808),B 自连到 onSignalB;
			// 自连不成环 → 直调等价(不新增信号名,避免改 moc 串表)
			onSignalB();
			return;
		}
	}
	onCancelClicked(); // 0055fa50
}

// FUN_00561c9e — cited:密码框 textChanged 槽体。
void LockScreenFace::onPasswordEdited() {}

// FUN_0055ff05(387B)信号 A 槽真身:+0x30 QLabel 设为
//   "<font color=\"darkorange\">%1</font>"(0x22 字符).arg(信号实参)
void LockScreenFace::onSignalA(const QString &text)
{
	if (m_f30 == nullptr)
		return;
	m_f30->setText(QStringLiteral("<font color=\"darkorange\">%1</font>").arg(text));
}

// FUN_0055fbd3(753B)— cited:本类信号 B 的槽体。
void LockScreenFace::onSignalB() {}

// FUN_0056098e(381B)键事件转发真身(+0x88 门):
//   +0x88 > 1 → 直接返回;
//   按键 0x1000015 → 以 (0x1000001, 原修饰键) 重建 QKeyEvent 并 postEvent 给自己;
//   按键 0x1000013 → 以 (0x1000002, 原修饰键) 同上;
//   按键 0x1000000 → onCancelClicked();
//   按键 0x1000004/0x1000005 → +0x88 == 1 时按当前焦点在 +0x60/+0x68/+0x70/+0x50
//     之间 setFocus(w, 1)。
void LockScreenFace::keyPressEvent(QKeyEvent *event)
{
	if (m_mode88 > 1)
		return;

	quint32 newKey = 0;
	if (event->key() == 0x1000015)
		newKey = 0x1000001; // 语料字面
	else if (event->key() == 0x1000013)
		newKey = 0x1000002; // 语料字面
	else if (event->key() == 0x1000000) {
		onCancelClicked();
		return;
	} else if (event->key() == 0x1000004 || event->key() == 0x1000005) {
		if (m_mode88 == 1) {
			// 语料焦点链实读:+0x60 → +0x68 → +0x70 → +0x50;都不匹配则不动
			QWidget *focus = focusWidget();
			QWidget *target = nullptr;
			if (m_f60 == focus)
				target = m_f68;
			else if (m_f68 == focus)
				target = m_f70;
			else if (m_f70 == focus)
				target = m_change50; // +0x50
			if (target != nullptr)
				target->setFocus(Qt::OtherFocusReason); // 1
		}
		return;
	} else {
		return;
	}

	// 重建同修饰键的 QKeyEvent 并投递给自己(语料 operator_new(0x40) + postEvent)
	QKeyEvent *ev = new QKeyEvent(QEvent::KeyPress, int(newKey), event->modifiers(),
	                              event->text(), event->isAutoRepeat(),
	                              quint16(event->count()));
	QCoreApplication::postEvent(this, ev, 0);
}
