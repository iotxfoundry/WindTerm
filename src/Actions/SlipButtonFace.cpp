// SlipButtonFace.cpp — SlipButton(自绘拨动开关)。
// 语料名对应:ctor 反编译器误命名 overlay_makeBusyWidget(005659d4)。

#include "Actions/SlipButtonFace.h"

#include <QApplication>
#include <QSizePolicy>
#include <QTimer>
#include <QFontMetrics>
#include <QLabel>
#include <QMenu>
#include <QPainterPath>
#include <QStyle>
#include <QStyleOption>
#include <QWidgetAction>

#include <cstring>

// ───────────── 被调件(按 §5 锚入口) ─────────────
// QStyle::sizeFromContents 在本二进制 vt 槽 0xe8;语义按 Qt5 同名函数复原。
// QStyle::contentsType 实参为字面 0(CT_None),非折叠。

// ───────────── ctor ─────────────
// 005659d4(513B,语料名 overlay_makeBusyWidget —— 名不副实,实为本类 ctor):
//   QWidget::QWidget(this, parent, 0);vptr = SlipButton_vtable;
//   *(this+0x10) = PTR_FUN_0119d5c8(第二 vptr)
//   +0x30:低 3 位清零后置入 (on & 1)
//   +0x34 = 4;+0x38 = 空 QString;+0x40 = 空 QVariant;
//   +0x48 = 0x80000000;+0x50/+0x54 = 0 / -1;+0x58 = variant
//   +0x60 QBrush("#007ACC")  +0x68 QBrush("#A52A2A")
//   +0x70 QBrush(Qt::white)  +0x78 QBrush("#444444")  +0x80 QBrush()
//   +0x88/+0x90/+0x98 = 0
//   setCursor(Qt::PointingHandCursor = 0xd);setSizePolicy(0 = Preferred)
//   QTimer::singleShot(0, this, → 00565dc0(this))(见 00565f3a)
SlipButtonFace::SlipButtonFace(QWidget *parent, bool on, int variant)
    : QWidget(parent) // QWidget::QWidget(this, parent, 0)
    , m_flag30(on)
{
	setCursor(Qt::PointingHandCursor); // QCursor(0xd)
	setSizePolicy(QSizePolicy::Preferred); // 语料 setSizePolicy(0),折叠实参

	// 颜色默认值(字面取自语料 .rodata 串表,符号名已去 '#' 前缀)
	m_checkedColor = QBrush(QColor(QStringLiteral("#007ACC")));
	m_errorColor = QBrush(QColor(QStringLiteral("#A52A2A")));
	m_handleColor = QBrush(Qt::white); // QBrush(3,1) = GlobalColor 3
	m_uncheckedColor = QBrush(QColor(QStringLiteral("#444444")));
	m_warningColor = QBrush();

	m_f58 = variant;

	// 延后一拍重建路径(00565f3a 的回调 = FUN_00565dc0)
	QTimer::singleShot(0, this, [this]() { updatePath(); });
}

// 00565c0e(202B)dtor 真身:
//   vptr 复位 → +0x88 QPainterPath 释放(operator_delete(_,8))
//   → 五个 QBrush 逆序析构(+0x80/+0x78/+0x70/+0x68/+0x60)
//   → +0x40 QVariant → +0x38 QString → QWidget::~QWidget
SlipButtonFace::~SlipButtonFace() = default;

// SlipButton_vt14(00565f64,350B)sizeHint 真身。
// 逐句:ensurePolished → 以 "x" 量字(QFontMetrics::size(TextShowMnemonic,
// "x", nullptr))→ 铺进 QStyleOptionButton.rect → QStyle::sizeFromContents(
// ct=0, &opt, QSize(w,h), this)→ 与 qApp->globalStrut() 取各边最大
// (语料为两次比较,Ghidra 折叠了返回值高位;expandedTo 同语义)
// → 若 +0x58 == 0 则高度改用字体行高(00565d00)。
QSize SlipButtonFace::sizeHint() const
{
	ensurePolished();
	const QFontMetrics fm(font());
	const QSize ts = fm.size(Qt::TextShowMnemonic, QStringLiteral("x"), 0, nullptr);

	QStyleOptionButton opt;
	opt.rect = QRect(QPoint(0, 0), ts);

	QSize sz = style()->sizeFromContents(QStyle::CT_None, &opt, ts, const_cast<SlipButtonFace *>(this));
	sz = sz.expandedTo(QApplication::globalStrut());

	if (m_f58 == 0)
		sz.setHeight(fontHeightOf(const_cast<SlipButtonFace *>(this)));
	return sz;
}

// 00565d00(146B)真身:用同一字体量 "x" 的行高(QFontMetrics::size 的
// 高度分量,语料取返回 QSize 的高 32 位)。
int SlipButtonFace::fontHeightOf(QWidget *w)
{
	const QFontMetrics fm(w->font());
	return fm.size(Qt::TextShowMnemonic, QStringLiteral("x"), 0, nullptr).height();
}

// 00565da6(25B)真身:控件高减去字体行高 = 竖向余量。
// 语料取 d_ptr +0x20 / +0x18(QRect 的 bottom/top),即 height()。
int SlipButtonFace::verticalSlack(QWidget *w)
{
	return (w->height() - 1 + 1) - fontHeightOf(w);
}

// 00565dc0(359B)updatePath 真身(结构段):
//   旧 +0x88 释放 → new QPainterPath(8B)→ setFillRule(1 = WindingFill)
//   → addEllipse ×2 → addRect ×1(胶囊轨道 + 圆钮)
//   前两句先调 00565d00(量字)与 00565da6(竖向余量),返回值未参与后续算术。
// ⚠ addEllipse/addRect 的 QRectF 实参被 Ghidra 折叠 —— 绘制批次落地时
//   须回 asm 取寄存器(踩坑 18);此处仅保留调用序与个数。
void SlipButtonFace::updatePath()
{
	fontHeightOf(this);          // 00565d00
	verticalSlack(this);         // 00565da6

	delete m_path88;
	m_path88 = new QPainterPath;
	m_path88->setFillRule(Qt::WindingFill); // 1

	// cited:三个图形的 QRectF 实参折叠(见上 ⚠)
	m_path88->addEllipse(QRectF());
	m_path88->addEllipse(QRectF());
	m_path88->addRect(QRectF());
}

// 008fae78(52B)/ 008faeac(55B)真身:两个信号发射器。
//   QMetaObject::activate(this, &staticMetaObject, 0 或 1, 载荷)
//   载荷 = 一个字节(信号声明 argc = 0,该字节为语料缓冲残留,原样透传)。
void SlipButtonFace::emitSignalAt(int index, uchar payload)
{
	Q_UNUSED(payload);
	if (index == 0)
		emit clicked();
	else if (index == 1)
		emit toggled();
}

// 008faee4(460B)QMetaObject 桥真身。逐句:
//   op=0  发信号:index 0 → 008fae78(clicked),index 1 → 008faeac(toggled)
//   op=10 反查:args[1] 指向 {fn, 0};fn==008fae78 → *args = 0;
//         fn==008faeac → *args = 1(其余不动)
//   op=1  读属性:index 0..4 → 字段 +0x60/+0x70/+0x68/+0x78/+0x80,
//         按语料 14 字节整体拷出(源 = *(this+off) + 8,即 QBrush 私有区),
//         字节布局未复原 —— 原样转写为 memcpy
//   op=2  写属性:index 同序,QBrush clone 换入(copy-and-swap)
void SlipButtonFace::metaDispatch(int op, int index, void **args)
{
	// 属性索引 → 字段偏移(注意 0..4 不是递增偏移)
	static const int kOff[5] = { 0x60, 0x70, 0x68, 0x78, 0x80 };

	if (op == 0) {
		if (index == 0 || index == 1)
			emitSignalAt(index, args ? *reinterpret_cast<uchar *>(args[1]) : 0);
		return;
	}
	if (op == 10) {
		// 语料:args[1] 是 {fn, 0} 结构;fn 命中 008fae78 / 008faeac 时
		// 把信号号(0 / 1)写回 *args。两个发射器在本文件以 emitSignalAt
		// 统一,故此处只保留字面判定骨架(发射器地址比对 = cited)。
		if (args == nullptr)
			return;
		void *fn = *reinterpret_cast<void **>(args[1]);
		if (fn == nullptr)
			return;
		// cited:发射器函数地址 0x008fae78 / 0x008faeac 的比对
		return;
	}
	if (index < 0 || index > 4)
		return;

	QBrush *slot = reinterpret_cast<QBrush *>(reinterpret_cast<char *>(this) + kOff[index]);
	if (op == 1) {
		// 语料:从 *(this+off) 的私有区 +8 起拷 14 字节
		const char *src = *reinterpret_cast<const char *const *>(slot) + 8;
		char *dst = reinterpret_cast<char *>(args);
		memcpy(dst, src, 4);
		memcpy(dst + 4, src + 4, 8);
		memcpy(dst + 12, src + 12, 2);
		return;
	}
	if (op == 2 && args != nullptr) {
		const QBrush incoming(*reinterpret_cast<const QBrush *>(args));
		QBrush old(*slot);
		*slot = incoming;
		(void)old;
	}
}

// 00565f3a(42B)真身:QTimer::singleShot 闭包清理 +
//   回调用例(1 = 调用 00565dc0(捕获的 this),0 = 释放 0x18 闭包)。
//   已由 ctor 的 singleShot 承载(见上)。

// ───────────── 批 338:菜单行构建 ─────────────
// slipButton_makeMenu(1023B,0021.c:40319)真身(结构段):
//   @006af0f5 QMenu(0x30);
//   @006af144 tr(0xc9d3fb) → @006af152 QWidgetAction(0x30)+vtable
//     SlipButtonAction → +0x18 QLabel(0x30) → +0x20 overlay_makeBusyWidget
//     (0xa0) → +0x28 QWidget(0x30) → QLabel::setBuddy(+0x18)。
//   addAction/connect/弹出余段 cited。
QMenu *SlipButtonFace::makeMenu(QWidget *parent)
{
	auto *menu = new QMenu(parent);     // @006af0f5(0x30)
	auto *row = new QWidgetAction(menu); // @006af152(0x30)
	auto *label = new QLabel(row);       // +0x18(0x30)
	// +0x20 = SlipButtonFace(0xa0)—— 名 overlay_makeBusyWidget(实为本类 ctor)
	// +0x28 = QWidget(0x30)—— 行容器(cited)
	row->setDefaultWidget(label);
	menu->addAction(row);
	return menu;
}

// ───────────── moc 生成面(出处:QMetaObject 元数据) ─────────────
// SlipButton_metaObject(008fae60,24B)= 返回 &PTR_staticMetaObject_0119d620
//   (无动态元对象时);SlipButton_qt_metacast(008fb0b0,66B)= strcmp("SlipButton")
//   → QWidget::qt_metacast;qt_metacall(008fb0f2,176B)= 转 008faee4 桥;
//   SlipButton_vt15(005660d6,5B)= jmp vt14(sizeHint)。
