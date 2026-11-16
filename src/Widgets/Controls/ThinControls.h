#pragma once

#include <QDialog>
#include <QObject>
#include <QRegularExpression>
#include <QString>
#include <QWidget>

// ThinControls.h — 六个"薄类":自己的元接口为零,内容在基类或单条虚面里。
//
// **共同判据(六个都验过)**:`qt_metacall` 一律 **5 字节纯转发**基类
// ⇒ 自身 **0 条信号、0 条槽**;`metaObject` 一律 24B(普通分支,不是动态)。
// 所以 `--class` 在这些类上查不出任何接口名 —— 不能据此判"未逆向"。
//
// | 类 | 基类(superdata 实读) | sizeof | 内容 |
// |---|---|---|---|
// | CheckDelegate     | **WidgetDelegate**      | — | 零字段 + 2 条虚面(vt12 62B / vt14 12B) |
// | CheckListPanel    | **ButtonBarPanel**      | — | dtor 19B ⇒ 零字段 |
// | ExplorerList      | **WidgetList**          | — | dtor 19B ⇒ 零字段 |
// | ListPanel         | **ButtonBarPanel**      | — | dtor 19B ⇒ 零字段 |
// | QuickBar          | 无 QMetaObject 基       | — | 字段 **+0x68** QSharedDataPointer |
// | TerminalKeyboard  | 无 QMetaObject 基       | — | 零字段(仅 QObject 析构) |
//
// ⚠ 注意 `CheckDelegate : WidgetDelegate`,而 WidgetDelegate 自身又派生自
// `QStyledItemDelegate`(CheckDelegate 的 dtor 末句调的就是它)——
// 这说明 **WidgetDelegate 是 WindTerm 自研的自绘委托基座**,不是 Qt 的类。
//
// 出处(entry 地址逐一列,真身):
//   CheckDelegate    dtor 0x008eff9e / deleting 0x008effb2 / vt12 0x005d56b0 / vt14 0x005d56a4
//   CheckListPanel   dtor 0x…(与 ExplorerList/ListPanel 同为 19B 形态)
//   QuickBar         dtor 0x008f1182 / deleting 0x008f11e0
//   TerminalKeyboard dtor 0x0090ece4 / deleting 0x0090ecf8

class WidgetDelegate; // 已存在(自绘委托基座)

class CheckDelegateFace : public QStyledItemDelegate {
	Q_OBJECT
public:
	explicit CheckDelegateFace(QObject *parent = nullptr);
	~CheckDelegateFace() override; // 0x008eff9e
};

class QuickBarFace : public QWidget {
	Q_OBJECT
public:
	explicit QuickBarFace(QWidget *parent = nullptr);
	~QuickBarFace() override; // 0x008f1182
private:
	void *m_shared68 = nullptr; // +0x68
};

class TerminalKeyboardFace : public QObject {
	Q_OBJECT
public:
	explicit TerminalKeyboardFace(QObject *parent = nullptr);
	~TerminalKeyboardFace() override; // 0x0090ece4
};

class SuperKeymapFace : public QObject {
	Q_OBJECT
public:
	explicit SuperKeymapFace(QObject *parent = nullptr);
	~SuperKeymapFace() override; // 0x006744f4
private:
	void *m_ref10 = nullptr;              // +0x10 原子计数件(qatomic_int_deref)
	QRegularExpression m_re18;            // +0x18
};
