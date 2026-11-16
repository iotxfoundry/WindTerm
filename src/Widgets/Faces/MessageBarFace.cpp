// MessageBarFace.cpp — 语料 MessageBar ctor 转写(批 244)
#include "MessageBarFace.h"

#include "Actions/Menu/ThemeIcons.h"

#include <QAbstractButton>
#include <QPushButton>
#include <QStyle>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

// FUN_0059af30(262B,0018.c:14395)ctor:
//   @0059af30 QWidget(parent,0);vtable MessageBar;
//   @0059af5x +0x48 = 0;+0x50 &= 0xfc;+0x58 = shared_null;+0x60 = QListData 空;
//   @0059af9c objectName "MessageBar";
//   @0059afd9 setAttribute(0x5d,1);@0059afe? setAttribute(0x37,1)
//     (0x37 = WA_DeleteOnClose,与 TextMarkDialog 同值);
//   @0059affx setSizePolicy(0x5d0000)(与 FUN_005a2d26 状态栏 ctor **同一
//     立即数** — 双源;编码解码仍未取证,直录);
//   @0059b00x s_ExpandButton_5984be(this)+FUN_0059834c(this)
//     — 子件装配两腿未转写,cited 不落(铁律 6)。
MessageBarFace::MessageBarFace(QWidget *parent)
	: QWidget(parent, Qt::WindowFlags(0)) // @0059af30
{
	setObjectName(QStringLiteral("MessageBar")); // @0059af9c
	setAttribute(static_cast<Qt::WidgetAttribute>(0x5d), true); // @0059afd9
	setAttribute(Qt::WA_DeleteOnClose, true);                   // 0x37 @0059afe?
	// setSizePolicy(QSizePolicy(0x5d0000))@0059affx — 立即数直录,编码面
	//   未解码(与状态栏 ctor 同常量;解码后统一替换)。
	// s_ExpandButton_5984be(this)+FUN_0059834c(this):
	//   前者 1021B 子件装配(两按钮 +0x38/+0x40)cited;
	//   后者(接线)本批真身。
	assembleChildren(); // s_ExpandButton_5984be @0059afcx(批 257)
	wireButtons();      // FUN_0059834c @0059afcx
}

// FUN_0059834c(369B,0018.c:12556)三路接线真身:
//   @0059834c connect(+0x40, clicked, this, FUN_005981c1);
//   @0059838x connect(+0x38, clicked, this, FUN_0059ced9);
//   @005983fx connect(this, destroyed, this, FUN_0059814a)。
//   槽体两市句实证:0x005981c1 emit(0x80,"") + close();
//   0x0059ced9 = s_king__expand_59c9e2(this, !(+0x50 bit1))(cited);
//   0x0059814a = 父链 MuxPane → FUN_00767b4a(cited)。
void MessageBarFace::wireButtons()
{
	if (m_f40 != nullptr) {
		connect(m_f40, &QAbstractButton::clicked, this, [this]() {
			emitMessage(0x80, QString()); // @005981fc(FUN_008f7e38)
			close();                            // @00598249
		});
	}
	if (m_f38 != nullptr) {
		connect(m_f38, &QAbstractButton::clicked, this, [this]() {
			// FUN_0059ced9(58B):s_king__expand_59c9e2(this,
			//   !((+0x50 >> 1) & 1))
			setExpanded(((m_flags50 >> 1) & 1) == 0);
		});
	}
	connect(this, &QObject::destroyed, this, [this]() {
		/* FUN_0059814a:父链 cast MuxPane(011a69d0) → FUN_00767b4a(pane)
		   @0059814a — cited 不落 */
	});
}

// s_ExpandButton_5984be(1021B,0018.c:12599)装配真身:
//   @005984e1 +0x40 = new QToolButton(0);@0059850x +0x38 = new QToolButton(0);
//   @00598515 +0x30 = new QVBoxLayout();hbox = new QHBoxLayout();
//   @0059853x "CloseButton"/focusPolicy(0)/tooltip tr("Close")(0xc89b49);
//   @00598624 "ExpandButton"/focusPolicy(0)/tooltip tr("Expand")(0xc8afe8);
//   @005986cc icon = theme_icon_load_svg(app,"king::shrink","");
//   @00598743 vbox setContentsMargins/setSpacing(Ghidra 折叠→按 0,cited);
//   hbox 边距 = style()->pixelMetric(0x4e)/pixelMetric(0x50)@005987xx;
//   hbox->addLayout(vbox)@005987xx → addWidget(+0x38)→ addWidget(+0x40)
//   → this->setLayout(hbox)@005988xx。
void MessageBarFace::assembleChildren()
{
	m_f40 = new QToolButton(nullptr); // @005984e1
	m_f40->setObjectName(QStringLiteral("CloseButton")); // @00598577
	m_f40->setToolTip(tr("Close"));                      // 0xc89b49 @005985c2
	m_f40->setFocusPolicy(Qt::NoFocus);                  // @0059861x(esi=0)
	m_f38 = new QToolButton(nullptr); // @005984fc
	m_f38->setObjectName(QStringLiteral("ExpandButton")); // @00598624
	m_f38->setToolTip(tr("Expand"));                      // 0xc8afe8 @0059866f
	m_f38->setFocusPolicy(Qt::NoFocus);                   // @005986bx
	m_f38->setIcon(ThemeIcons::loadSvg(QStringLiteral("king::shrink"),
	                                   QString())); // @005986cc
	m_f30 = new QVBoxLayout(); // @00598515
	// vbox setContentsMargins/setSpacing 实参 Ghidra 折叠 → cited(按 0)
	auto *hbox = new QHBoxLayout(); // @0059852e
	const int m1 = style()->pixelMetric(static_cast<QStyle::PixelMetric>(0x4e)); // @005987xx
	const int m2 = style()->pixelMetric(static_cast<QStyle::PixelMetric>(0x50));
	hbox->setContentsMargins(m1, 0, m2, 0); // 四边实参取两 pixelMetric(折叠)
	hbox->addLayout(m_f30);   // @005987xx
	hbox->addWidget(m_f38);   // +0x38
	hbox->addWidget(m_f40);   // +0x40
	setLayout(hbox);          // @005988xx
}

// FUN_0059b046(393B,0018.c:14437)真身:
//   @0059b046 findChildren<QPushButton>(this, 空名, 递归=1);
//   逐项 QAbstractButton::text() == 参数 → 返回该项;遇空表 → 0。
QPushButton *MessageBarFace::findButtonByText(const QString &text) const
{
	const QList<QPushButton *> buttons = findChildren<QPushButton *>();
	for (QPushButton *b : buttons) {
		if (b->text() == text) // @0059b119 operator==
			return b;
	}
	return nullptr;
}

// FUN_008f7e38(56B,0028.c:6832)真身:
//   QMetaObject::activate(this, smo 0119a2e0, idx 0, args{int, QString})
//   → 本面 emit messageSignal(code, text)。
void MessageBarFace::emitMessage(int code, const QString &text)
{
	emit messageSignal(code, text); // 等价 activate idx0
}

// s_king__expand_59c9e2(882B,0018.c:15301)真身(结构面):
//   @0059c9e2 子件表 this+0x60(QList<QMap<QString,QVariant>>)逐项:
//     项["visible"] 更新(深面,cited);
//   @0059cbxx +0x38 钮 tooltip = expanded ? tr("Shrink")(0xc8b041)
//     : tr("Expand")(0xc8afe8)@0059cbxx → show()@0059ccxx;
//   @0059cc24 s_IconLabel_59b1e0(this)(图标/标签重排,cited)。
void MessageBarFace::setExpanded(bool expanded)
{
	// +0x60 子件表 "visible" 键面 — cited(深结构未转写)
	if (m_f38 != nullptr) {
		m_f38->setToolTip(expanded ? tr("Shrink") : tr("Expand")); // @0059cbxx
		m_f38->show();                                             // @0059ccxx
	}
	// s_IconLabel_59b1e0(this)@0059cc24 — cited。
}

// FUN_0059cd82(306B)真身:
//   @0059cdb3 id = map["id"](QMap 查,缺省无效 QVariant);
//   @0059ce34 +0x58 QString = 文案(键面未读全 → cited);
//   @0059ce3a FUN_0059ebe0(+0x60, map)(130B:= operator_new(8)+
//     qmap_detach_copy → 表 append 深拷贝);
//   @0059ce4a s_king__expand_59c9e2(this, (+0x50 >> 1) & 1)。
void MessageBarFace::applyItem(const QVariantMap &item)
{
	Q_UNUSED(item.value(QStringLiteral("id"))); // 语料读 "id" 后未落消费面(cited)
	m_items60.append(item);                     // FUN_0059ebe0 深拷贝 append 等价
	setExpanded(((m_flags50 >> 1) & 1) != 0);   // @0059ce4a
}
