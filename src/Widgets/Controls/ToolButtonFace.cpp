// ToolButtonFace.cpp — 富文本工具栏按钮。

#include "Widgets/Controls/ToolButtonFace.h"

#include <QFontMetrics>
#include <QMenu>
#include <QTextDocument>
#include <QTextOption>

ToolButtonFace::ToolButtonFace(QWidget *parent)
    : QToolButton(parent)
{
}

// 0x008fbb66(29B)dtor 真身:
//   vptr = &ToolButton_vtable;*(this+0x10) = &PTR_FUN_0119e0c0;
//   QToolButton::~QToolButton
// (说明:+0x38 QTextDocument 的释放不在本 dtor 内 —— 它以 this 为父对象,
//  走 QObject 父子链;语料如此,如实保留)
ToolButtonFace::~ToolButtonFace() = default;

// 0x005d4eb2(141B)ensureDoc 真身。逐句:
//   +0x38 为空 → new QTextDocument(this)(0x10)
//     → defaultTextOption();wrapMode 高 4 位清 0(setWrapMode(NoWrap))
//     → setUndoRedoEnabled(false)→ setDefaultTextOption(opt)
//     → setDocumentMargin(0.0)
//   → setHtml(html)
// ⚠ setHtml / setUndoRedoEnabled 的实参被 Ghidra 折叠(踩坑 18):
//   setHtml 按调用形态取传入的 html,setUndoRedoEnabled 取 false(布尔腿)。
void ToolButtonFace::ensureDoc(const QString &html)
{
	if (m_doc38 == nullptr) {
		m_doc38 = new QTextDocument(this);
		QTextOption opt = m_doc38->defaultTextOption();
		opt.setWrapMode(QTextOption::NoWrap); // 高 4 位清 0
		m_doc38->setUndoRedoEnabled(false);
		m_doc38->setDefaultTextOption(opt);
		m_doc38->setDocumentMargin(0.0);
	}
	m_doc38->setHtml(html);
}

// vt14 0x005d5588(229B)sizeHint 真身:
//   base = QToolButton::sizeHint();
//   +0x38 为空 → 直接返回 base
//   否则:QStyleOptionToolButton opt;initStyleOption(&opt);
//     doc->setHtml(opt.text);doc->setDefaultFont(opt.font);
//     width += doc->idealWidth() - fm.horizontalAdvance(opt.text)
//   (语料:`(base.width + idealWidth) - advance` 一次算术,高度沿用 base)
// ⚠ setHtml/setDefaultFont/horizontalAdvance 三处实参折叠 —— 按 initStyleOption
//   填好的 opt.text / opt.font 复原(踩坑 18,绘制批次可回 asm 复核)。
QSize ToolButtonFace::sizeHint() const
{
	QSize sz = QToolButton::sizeHint();
	if (m_doc38 == nullptr)
		return sz;

	QStyleOptionToolButton opt;
	initStyleOption(&opt);

	QTextDocument *doc = const_cast<QTextDocument *>(m_doc38);
	doc->setHtml(opt.text);
	doc->setDefaultFont(opt.font);

	const QFontMetrics fm(opt.font);
	const int advance = fm.horizontalAdvance(opt.text);
	sz.setWidth(sz.width() + int(doc->idealWidth()) - advance);
	return sz;
}

// 0x005d4f90(54B)setText 真身:
//   mightBeRichText(text) 为真 → ensureDoc(text)(0x005d4eb2)
//   → QAbstractButton::setText(text)
void ToolButtonFace::setText(const QString &text)
{
	m_richHtml = text;
	if (Qt::mightBeRichText(text))
		ensureDoc(text);
	QAbstractButton::setText(text);
	emit textChanged();
}

// 0x008fb9e8(196B)属性桥真身。逐句(op=1 读 / op=2 写):
//   读 index 0 → *(int*)(this+0x30)                       (elideMode)
//   读 index 1 → dynamic_cast<Menu*>(QToolButton::menu())  (0x005d4f50,49B)
//   读 index 2 → QAbstractButton::text()                   (+ 引用计数换出)
//   写 index 0 → *(int*)(this+0x30) = v;update()          (0x005d4f82,8B)
//   写 index 1 → QToolButton::setMenu(v)                   (0x005d4f8a,5B)
//   写 index 2 → setText(v)                                (0x005d4f90)
void ToolButtonFace::metaDispatch(int op, int index, void **args)
{
	if (args == nullptr)
		return;

	if (op == 1) {
		if (index == 0) {
			*reinterpret_cast<int *>(args) = m_elideMode30;
		} else if (index == 1) {
			*reinterpret_cast<void **>(args) = dynamic_cast<QMenu *>(menu());
		} else if (index == 2) {
			*reinterpret_cast<QString *>(args) = QAbstractButton::text();
		}
		return;
	}

	if (op == 2) {
		void *const src = *reinterpret_cast<void **>(args);
		if (index == 0) {
			m_elideMode30 = *static_cast<int *>(src);
			update();
		} else if (index == 1) {
			setMenu(static_cast<QMenu *>(src));
		} else if (index == 2) {
			setText(*static_cast<QString *>(src));
		}
	}
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x008fb9d0 → &PTR_staticMetaObject_0119e100
// qt_metacast 0x008FBAAC → strcmp("ToolButton") → QToolButton::qt_metacast
// qt_metacall 0x008FBAEE → 属性 1..3 与 0xb 转发给 metaDispatch,连带
//   4/5/6/7/8(QAbstractButton 的 clicked/toggled 族)只做下标回退。
