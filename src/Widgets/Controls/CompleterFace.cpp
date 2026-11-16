#include "Widgets/Controls/CompleterFace.h"

#include <QListView>
#include <QBoxLayout>
#include <QCoreApplication>

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

// Completer_vt6(0x00551ada,642B)— cited:事件过滤全链(键/鼠标/焦点)。
bool CompleterFace::eventFilter(QObject *watched, QEvent *event)
{
	return QWidget::eventFilter(watched, event);
}
