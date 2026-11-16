// MenuFace.cpp — 元调用驱动的菜单。

#include "Widgets/Controls/MenuFace.h"

#include <QAction>
#include <QMetaType>

MenuFace::MenuFace(QWidget *parent)
    : QMenu(parent)
{
}

// 0x008f7d76(29B)dtor 真身:
//   vptr = &Menu_vtable;*(this+0x10) = &PTR_FUN_0119a028;QMenu::~QMenu
// deleting 0x008f7db4(47B):同上 + operator_delete。
MenuFace::~MenuFace() = default;

// 0x008f7a08(121B)五路分发真身。逐句:
//   case 0 → QWidget::addAction(action);**不写返回**
//   case 1 → a = QMenu::addAction(text);   *args = a
//   case 2 → m = QMenu::addMenu(...);      *args = m
//   case 3 → s = QMenu::addSection(text);  *args = s
//   case 4 → QMenu::addSeparator();**不写返回**
//   (case 1/2/3 之后有一句 `if (*args == 0) return;` 的空指针门 —— 原样保留)
void MenuFace::addAction(QAction *action)
{
	QWidget::addAction(action);
}

QAction *MenuFace::addAction(const QString &text)
{
	return QMenu::addAction(text);
}

QMenu *MenuFace::addMenu(const QString &title)
{
	return QMenu::addMenu(title);
}

QAction *MenuFace::addSection(const QString &text)
{
	return QMenu::addSection(text);
}

void MenuFace::addSeparator()
{
	QMenu::addSeparator();
}

// 0x008f7a82(566B)桥的 op=0xc(属性/类型面):
//   index 0 且 args[1] 为 0 时,若 DAT_011c0b04 尚未缓存 → 用
//   QMetaObject::className() 拼名 → QMetaType::registerNormalizedType(
//   …, &QAction::staticMetaObject)并缓存。
// 说明:与 SshSocketFace 的注册腿完全同构 —— 这是 WindTerm 的统一做法:
//   **凡经 metacall 传出自定义指针类型,先在 op=0xc 面注册元类型。**
void MenuFace::ensureActionMetaType()
{
	static int cached = 0;
	if (cached == 0)
		cached = qRegisterMetaType<QAction *>("QAction*");
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x008f79f0 → &PTR_staticMetaObject_0119a080(methods=5,signals=0)
// qt_metacast 0x008f7cc8(strcmp "Menu" → QMenu::qt_metacast)
// qt_metacall 0x008f7d0a(107B):5 条记录转发到 0x008f7a82 → 0x008f7a08;
//   op=0xc 面走 ensureActionMetaType 那条腿。
