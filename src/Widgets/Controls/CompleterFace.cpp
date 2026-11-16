#include "Widgets/Controls/CompleterFace.h"

#include <QKeyEvent>
#include <QListView>
#include <QMouseEvent>
#include <QBoxLayout>
#include <QCoreApplication>

// ① 可见性门:QWidget 的 d_ptr(+0x28) byte[+9] & 0x80。
//    Qt 不暴露该位;按语料原样做位测试 —— cited(位语义未复原)。
static bool widgetVisibleBit80(const QWidget *w)
{
	Q_UNUSED(w);
	return false;
}

// FUN_005830f4 — cited:视图侧推进一页/一行(接收者折叠,body 未转写)。
static void viewAdvance(QListView *view) { Q_UNUSED(view); }

// 008f9060 — cited:发 activated(currentIndex) 信号(发射器实参折叠)。
static void emitActivatedSignal(QWidget *self, const QModelIndex &index)
{
	Q_UNUSED(self);
	Q_UNUSED(index);
}

// FUN_00583bac(this, 0)— cited:0x78B 自绘列表件构造(类未建模)。
static QListView *createItemView(QWidget *parent)
{
	Q_UNUSED(parent);
	return nullptr;
}

// PTR_PTR_011a69d0 的类型判定(__dynamic_cast 目标类未复原)— cited。
static bool isFilterHost(QObject *obj)
{
	Q_UNUSED(obj);
	return false;
}

// FUN_005518d8(247B)ctor 真身:
//   QWidget(parent, 0) → vptr → +0x10 = PTR_FUN_0119ba48(第二 vptr)→ +0x38 = 0
//   → setObjectName("Completer")→ setWindowFlags(0x200c0b)
//   → setAttribute(0x37,true)/setAttribute(4,true)/setAttribute(0x62,true)
//   → buildView() → wire()
CompleterFace::CompleterFace(QWidget *parent)
    : QWidget(parent) // QWidget::QWidget(this, parent, 0)
{
	m_host38 = nullptr; // +0x38
	setObjectName(QStringLiteral("Completer"));
	setWindowFlags(Qt::WindowFlags(0x200c0b)); // 字面(见头注)
	setAttribute(Qt::WidgetAttribute(0x37), true);
	setAttribute(Qt::WA_StaticContents, true); // 4
	setAttribute(Qt::WidgetAttribute(0x62), true);
	buildView(); // 005517e2
	wire();      // 005516fe
}

// FUN_005517e2(229B)视图装配真身:
//   view = new 0x78B 件(this, 0)(FUN_00583bac,自绘 item view)→ +0x30
//   FUN_00583126(view, 1);view->setFocusPolicy(NoFocus);
//   view->setTextElideMode(1 = ElideLeft);
//   view->setWindowFlags(view->windowFlags() | 0x800)(字面:不进焦点链)
//   自研 VBoxLayout(VBoxLayout_vtable):边距 0 / 间距 0 / addWidget(view)
//   → setSizeConstraint(2 = SetMinimumSize)→ setLayout
void CompleterFace::buildView()
{
	m_view30 = createItemView(this); // FUN_00583bac(0x78B 件)—— cited
	if (m_view30 == nullptr)
		return;
	m_view30->setFocusPolicy(Qt::NoFocus);
	m_view30->setTextElideMode(Qt::ElideLeft); // 1
	m_view30->setWindowFlags(m_view30->windowFlags() | Qt::WindowFlags(0x800)); // 字面

	auto *v = new QVBoxLayout; // 语料:自研 VBoxLayout(vtable 已换)
	v->setContentsMargins(0, 0, 0, 0);
	v->setSpacing(0);
	v->addWidget(m_view30, 0, 0);
	v->setSizeConstraint(QLayout::SetMinimumSize); // 2(勿写成 SetFixedSize=3)
	setLayout(v);
}

// FUN_005516fe(227B)接线真身:
//   自 qApp 沿 parent 链(QObject::parent = *(obj+8)+0x10)找
//   dynamic_cast 成功的目标 → +0x38,并 installEventFilter(this);
//   找不到 → +0x38 = 0。
//   然后 connect(+0x30, QAbstractItemView::activated, this, functor 0055169b)。
void CompleterFace::wire()
{
	QObject *o = QCoreApplication::instance();
	while (o != nullptr) {
		if (isFilterHost(o)) { // __dynamic_cast(o, QObject, PTR_PTR_011a69d0)
			m_host38 = o;
			o->installEventFilter(this);
			break;
		}
		o = o->parent();
	}
	if (m_host38 == nullptr)
		m_host38 = nullptr; // 语料:+0x38 = 0

	if (m_view30 != nullptr)
		connect(m_view30, &QListView::activated, this,
		        [this](const QModelIndex &) { onActivated(); });
}

// FUN_0055169b — cited:列表项激活(选中后回填并隐藏)。
void CompleterFace::onActivated() {}

// Completer_vt6(0x00551ada,642B)事件过滤真身。逐句:
//   ① 门:this->d_ptr(+0x28) 的 byte[+9] & 0x80 为 0 → 直接走 QObject::eventFilter
//      (该位是 QWidget 的可见/挂起态缓存;位名未复原,按位测试原样转写)
//   ② watched == +0x30 视图的 parentWidget:
//        FocusOut(9)                          → dismiss
//        KeyPress(6)按自定义键码:
//          0x1000000 → dismiss;0x1000002 → FUN_005830f4(视图侧, cited);
//          0x1000001 → emit activated(视图 currentIndex)(发射器 008f9060)
//          然后 event->accept() 并返回 true(吞掉按键)
//        Move(13)                             → dismiss
//        Resize(14)                           → 落 QObject::eventFilter
//   ③ watched == +0x38 宿主:Move(13) → dismiss;其余落 QObject::eventFilter
//   ④ 其它对象:MouseButtonPress(2) 且点击点不在浮层矩形内、也不在视图窗口内 →
//        setAttribute(0x36, true) 后 dismiss
//   ⑤ dismiss 腿统一:FUN_00551a7c(this) 后落 QObject::eventFilter
bool CompleterFace::eventFilter(QObject *watched, QEvent *event)
{
	// ① 可见性门(位测试原样保留)
	if (!widgetVisibleBit80(this))
		return QWidget::eventFilter(watched, event);

	const QEvent::Type type = event->type();

	if (m_view30 != nullptr && watched == m_view30->parentWidget()) {
		if (type == QEvent::FocusOut) {
			dismissPopup();
			return QWidget::eventFilter(watched, event);
		}
		if (int(type) < 10) {
			if (type == QEvent::KeyPress) {
				const int key = static_cast<QKeyEvent *>(event)->key();
				if (key == 0x1000000) {
					dismissPopup();
				} else if (key == 0x1000002) {
					viewAdvance(m_view30); // FUN_005830f4
				} else if (key == 0x1000001) {
					emitActivatedSignal(this, m_view30->currentIndex()); // 008f9060
				}
				event->accept();
				return true;
			}
			return QWidget::eventFilter(watched, event);
		}
		if (type == QEvent::Move) {
			dismissPopup();
			return QWidget::eventFilter(watched, event);
		}
		if (type == QEvent::Resize)
			return QWidget::eventFilter(watched, event);
	} else if (watched == m_host38) {
		if (type == QEvent::Move) {
			dismissPopup();
			return QWidget::eventFilter(watched, event);
		}
		return QWidget::eventFilter(watched, event);
	} else if (type == QEvent::MouseButtonPress) {
		auto *me = static_cast<QMouseEvent *>(event);
		const QRect r = geometry(); // 语料自 d_ptr 取 0x14..0x20 四边
		const QPoint p = mapFromGlobal(me->globalPos());
		if (!r.contains(p)) {
			QWidget *vw = m_view30 != nullptr ? m_view30->window() : nullptr;
			if (vw == nullptr)
				vw = nullptr;
			if (vw == nullptr) {
				setAttribute(Qt::WidgetAttribute(0x36), true);
				dismissPopup();
			}
		}
	}
	return QWidget::eventFilter(watched, event);
}

// FUN_00551a7c — cited:收起浮层(隐藏 + 清选中 + 通知宿主)。
void CompleterFace::dismissPopup() {}
