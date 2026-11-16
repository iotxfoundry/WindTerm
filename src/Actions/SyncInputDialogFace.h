#pragma once

#include <QDialog>
#include <QString>

// SyncInputDialogFace — 语料 **SyncInputDialog**(批 424)。
//
// ctor FUN_0072abce(239B,0022.c:...) asm 实测:
//   QDialog(parent, 0) → vtable **SyncInputDialog_vtable** + 副 011a44b0 →
//   **+0x60 = int 0** / **+0x68 = 空 QString** →
//   setWindowTitle(tr("Sync Input")(0xc89b32)) → setAttribute(0x37, true) →
//   buildMain()(FUN_00729f1e,3005B)+ buildExtra()(FUN_00729616,867B)→
//   QTimer::singleShot(0, 闭包 FUN_0072b69e)。
class SyncInputDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SyncInputDialogFace(QWidget *parent = nullptr);

	// FUN_00729f1e(3005B)主装配(建造部分逐对实测):
	//   **+0x30 = QComboBox(0x30)** / **+0x40 = QTabBar(0x30)** /
	//   **+0x48 = QStackedWidget(0x30)** /
	//   **+0x58 = new 0x48 + FUN_0055e356(w, 0x201)**(列表件,旗标 0x201;
	//   +0x50 = w+0x40)/ **+0x38 = QDialogButtonBox(0x30, 0x400400 Ok|Cancel)**;
	//   combo 三项(data → 文案,实读):
	//     2 → "Sessions In Current Window"(0xca1824)
	//     1 → "Sessions In All Windows"(0xca183f)
	//     3 → "Sessions In Group %1"(0xca1857)
	//   另有标签 tr("Joined:")(0xca181c)/ tr("Channel")(0xcb7054)/ title
	//   "Sync Input";按钮 Ok(0xc9e1cd)/Cancel(0xc8a1b5)。
	void buildMain();   // FUN_00729f1e(3005B)
	void buildExtra();  // FUN_00729616(867B) — 结构段

	// FUN_0072acce(774B)**收集所选会话**:
	//   遍历 +0x48 QStackedWidget 各页(count()/widget(i))→ 页 dynamic_cast 到
	//   typeinfo 0x11995d0 → 该页 **+0x40 = QListWidget** → 逐项
	//   item->data(0x100) → metatype 还原 → dynamic_cast 到 **0x11a8310**
	//   (会话/面板类)→ 收进 QMap 去重(键 = 指针)。
	QList<QObject *> collectSessions();

protected:
	QWidget *m_combo30 = nullptr;   // +0x30(QComboBox)
	QWidget *m_buttons38 = nullptr; // +0x38(QDialogButtonBox,0x400400)
	QWidget *m_tabBar40 = nullptr;  // +0x40(QTabBar)
	QWidget *m_stack48 = nullptr;   // +0x48(QStackedWidget)
	QWidget *m_listView50 = nullptr;// +0x50(列表件 +0x40)
	QWidget *m_list58 = nullptr;    // +0x58(0x48,FUN_0055e356(0x201))
	int m_f60 = 0;        // +0x60
	QString m_f68;        // +0x68
};
