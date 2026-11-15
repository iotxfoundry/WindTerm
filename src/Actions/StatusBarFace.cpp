// StatusBarFace.cpp — 语料状态栏子类三段转写(批 196)
// 语料:decomp-part-0018.c(18966/19022/21306)+ /opt ELF asm 实参核。
#include <QLabel>
#include <QStyle>
#include <QTimer>

#include "Actions/StatusBarFace.h"

// FUN_005a2d26(252B,0018.c:18966)ctor:
//   QStatusBar(parent)@005a2d2e → 字段清零 +0x30/+0x38/+0x40 @005a2d6x
//   → objectName "StatusBar" @005a2d9a → setSizePolicy(QSizePolicy
//   编码值 0x5d0000)@005a2dbd → setSizeGripEnabled(false)@005a2dc7(esi=0)
//   → setContentsMargins(font.pointSize(),0,font.pointSize(),0)@005a2df4
//   (esi/ecx 皆 = QFont::pointSize()@005a2dd4/005a2de3,edx/r8d=0)。
StatusBarFace::StatusBarFace(QWidget *parent)
	: QStatusBar(parent) // @005a2d2e
{
	setObjectName(QStringLiteral("StatusBar")); // @005a2d9a
	// setSizePolicy(QSizePolicy(0x5d0000 编码值))@005a2dbd — 语料立即数
	//   直录;QSizePolicy 位域打包序未取证 → cited 不落,防发明策略值。
	setSizeGripEnabled(false); // @005a2dc7(esi=0)
	const int ps = font().pointSize(); // @005a2dd4/005a2de3(两次同值)
	setContentsMargins(ps, 0, ps, 0); // @005a2df4(left,top,right,bottom)
	// +0x40 int = 0 @005a2d6x — 消费面未取证,cited 不落。
}

// FUN_005a2e58(654B,0018.c:19022)消息显示:
//   timer=+0x38;timeout<1 → timer?stop(vtable+0x20)@005a2e70,+0x38=0;
//   else → timer 惰建(QTimer(this)@005a301f + timeout→FUN_005a6552
//   connect@005a3034)+ start(timeout);
//   old = FUN_005a2e32(this)@005a2e60(+0x30 非空 → QLabel::text(),否则空);
//   text 空 → tr("Ready")@005a2ec8(0xc8b211);label 惰建(QLabel(this)
//   @005a2f89 + insertPermanentWidget(0,label)@005a2f9f);setText@005a2edd;
//   old != text → messageChanged(text)@005a2f7x。
void StatusBarFace::showFaceMessage(const QString &text, int timeoutMs)
{
	if (timeoutMs < 1) { // @005a2e60 param_3 < 1
		if (m_timer != nullptr)
			m_timer->stop(); // vtable+0x20 @005a2e70
		m_timer = nullptr; // @005a2e7x
	} else {
		if (m_timer == nullptr) { // 惰建 @005a2e8x
			m_timer = new QTimer(this); // @005a301f
			connect(m_timer, SIGNAL(timeout()), this,
			        SLOT(onMessageTimeout())); // @005a3034
		}
		m_timer->start(timeoutMs); // QTimer::start(int)
	}
	const QString old = m_label != nullptr ? m_label->text() : QString(); // @005a2e60
	const QString shown = text.isEmpty() ? tr("Ready") : text; // @005a2ec8(0xc8b211)
	if (m_label == nullptr) {         // 惰建 @005a2f7x
		m_label = new QLabel(this);   // @005a2f89
		insertPermanentWidget(0, m_label); // @005a2f9f
	}
	m_label->setText(shown); // @005a2edd
	if (shown != old)        // operator== @005a2efx
		emit messageChanged(shown); // @005a2f7x
}

// FUN_005a6552(325B,0018.c:21306)超时槽:
//   +0x38 非空 → stop(vtable+0x20)@005a6562;+0x38=0 @005a6570;
//   +0x30 空 → return;否则 setText(tr("Ready"))@005a65aa(0xc8b211) →
//   FUN_005a620e(this,"Normal")@005a6609(cited 状态串腿)→
//   messageChanged(空串)@005a6636。
void StatusBarFace::onMessageTimeout()
{
	if (m_timer != nullptr)
		m_timer->stop(); // @005a6562
	m_timer = nullptr;   // @005a6570
	if (m_label == nullptr)
		return; // @005a657a
	m_label->setText(tr("Ready")); // @005a65aa
	setFaceMessageLevel(QStringLiteral("Normal")); // @005a6609(FUN_005a620e)
	emit messageChanged(QString()); // @005a6636
}

// s_king_refreshWidgetStyle(67B,0023.c:17850)真身:style()->unpolish(w)
//   (vt+0x68)@0x75265e → style()->polish(w)(vt+0x60)@0x75266a →
//   repaint 位非 0 → w->repaint()。首参语料未消费(rdi 被 rsi 覆盖)。
static void kingRefreshWidgetStyle(QWidget *widget, bool repaint)
{
	QStyle *st = widget->style(); // @0x75264d
	st->unpolish(widget);         // vtable +0x68 @0x75265e
	st->polish(widget);           // vtable +0x60 @0x75266a
	if (repaint)
		widget->repaint();        // @0x75267x
}

// FUN_005a620e(787B,0018.c:21177)消息级别染色真身(asm 0x5a620e-0x5a6549):
//   old = property("messageLevel").toString()@0x5a623a(名 0xd0dfa6 实读);
//   ready = tr("Ready")@0x5a6270;labelText = +0x30?text():"" @0x5a6280;
//   labelText == ready → level 清空 @0x5a628b-2ae;level == old → 返回
//   @0x5a62bd;否则 setUpdatesEnabled(false)@0x5a6317 → setProperty
//   ("messageLevel", 空?QVariant():QVariant(level))@0x5a6345 →
//   findChildren<QWidget>(递归)@0x5a6380 逐个 refreshStyle(repaint=0)
//   @0x5a63e9 → 本件 refreshStyle @0x5a6407 → setUpdatesEnabled(true)
//   @0x5a6414。
void StatusBarFace::setFaceMessageLevel(const QString &level)
{
	const QString old = property("messageLevel").toString(); // @0x5a623a
	const QString ready = tr("Ready");                       // @0x5a6270
	const QString labelText = m_label != nullptr ? m_label->text() : QString(); // @0x5a6280
	QString next = level;
	if (labelText == ready) // @0x5a628b
		next.clear();
	if (next == old) // @0x5a62bd
		return;
	setUpdatesEnabled(false); // @0x5a6317(esi=0)
	setProperty("messageLevel", next.isEmpty() ? QVariant() : QVariant(next)); // @0x5a6345
	const QList<QWidget *> kids = findChildren<QWidget *>(); // @0x5a6380(递归=1)
	for (QWidget *w : kids)
		kingRefreshWidgetStyle(w, false); // @0x5a63e9(edx=0)
	kingRefreshWidgetStyle(this, false);  // @0x5a6407(edx=0)
	setUpdatesEnabled(true);              // @0x5a6414(esi=1)
}
