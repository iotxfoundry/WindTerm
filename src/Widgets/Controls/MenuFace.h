#pragma once

#include <QMenu>

class QAction;

// MenuFace — 可被元调用驱动的菜单(QMenu 派生,**5 条槽 / 0 信号**)。
//
// 出处:RTTI "Menu";QMetaObject 0x0119a080
// (rev=8,class="Menu",methods=5,**signals=0**,props=0,superdata=0);
// dtor 0x008f7d76(29B)/deleting 0x008f7db4(47B);
// 槽分发 0x008f7a08(121B,`addX` 五路);桥 0x008f7a82(566B);
// metacast 0x008f7cc8 / metacall 0x008f7d0a(107B)。
//
// 五条槽(串表实读;不是新造 API,是**把 QMenu 的添加函数重新暴露成槽**,
// 好在元调用层(wind.actions / 脚本)里拼菜单):
//   #0 addAction(QAction *)              → QWidget::addAction,不返回值
//   #1 addAction(const QString &)        → QMenu::addAction,**返回新动作**
//   #2 addMenu(...)                      → QMenu::addMenu,**返回子菜单**
//   #3 addSection(const QString &)       → QMenu::addSection,**返回动作**
//   #4 addSeparator()                    → QMenu::addSeparator,不返回值
//
// 返回值传递方式(实读):`*args = 新对象` —— 即 "返回新建的那个" 一律
// 写回 args[0];#0 / #4 不写(语料直接 return)。
//
// 字段:无(dtor 只有 vptr 复位 + QMenu 析构两行)。
class MenuFace : public QMenu {
	Q_OBJECT

public:
	explicit MenuFace(QWidget *parent = nullptr);
	~MenuFace() override; // 0x008f7d76

public slots:
	void addAction(QAction *action);            // #0
	QAction *addAction(const QString &text);    // #1
	QMenu *addMenu(const QString &title);       // #2
	QAction *addSection(const QString &text);   // #3
	void addSeparator();                        // #4

private:
	// 0x008f7a82(566B)桥的 op=0xc 面:注册 QAction* 元类型
	// (registerNormalizedType(…, &QAction::staticMetaObject),结果缓存进
	//  DAT_011c0b04)。与 SshSocket 的注册腿同构 —— 自定义槽返回值必须先
	//  注册元类型,Qt 才允许经 metacall 传出。
	void ensureActionMetaType();
};
