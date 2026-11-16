// SyncInputDialogFace.cpp — 同步输入对话框(批 424)
#include "Widgets/Dialogs/SyncInputDialogFace.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QListWidget>
#include <QStackedWidget>
#include <QTabBar>

// FUN_0072abce(239B)ctor 真身
SyncInputDialogFace::SyncInputDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @0072abce
{
	setWindowTitle(QStringLiteral("Sync Input"));          // tr(0xc89b32)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);     // @0072ac5b
	buildMain();                                           // @FUN_00729f1e(3005B)
	buildExtra();                                          // @FUN_00729616(867B)
	// QTimer::singleShot(0, this, 闭包 FUN_0072b69e)@0072acxx — cited
}

// FUN_00729f1e(3005B)主装配真身(建造部分)
void SyncInputDialogFace::buildMain()
{
	auto *combo = new QComboBox(this);            // +0x30(0x30)
	auto *tabs = new QTabBar(this);               // +0x40(0x30)
	auto *stack = new QStackedWidget(this);       // +0x48(0x30)
	auto *list = new QListWidget(this);           // +0x58(0x48,FUN_0055e356(0x201))
	auto *box = new QDialogButtonBox(             // +0x38(0x30,Ok|Cancel)
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	m_combo30 = combo; m_tabBar40 = tabs; m_stack48 = stack;
	m_list58 = list; m_listView50 = list;         // +0x50 = w+0x40(同族子件)
	m_buttons38 = box;

	// combo 三项(data → 文案,顺序即语料插入序:2 / 1 / 3)
	combo->addItem(QStringLiteral("Sessions In Current Window"), 2); // 0xca1824
	combo->addItem(QStringLiteral("Sessions In All Windows"), 1);     // 0xca183f
	combo->addItem(QStringLiteral("Sessions In Group %1"), 3);        // 0xca1857
	// 其余(标签 "Joined:" / "Channel" / 布局 / 页签填充) — cited
}

// FUN_00729616(867B)副装配 — 结构段(cited)
void SyncInputDialogFace::buildExtra() {}

// FUN_0072acce(774B)收集所选会话真身(结构段)
QList<QObject *> SyncInputDialogFace::collectSessions()
{
	QList<QObject *> out;
	auto *stack = qobject_cast<QStackedWidget *>(m_stack48);   // +0x48
	if (stack == nullptr)
		return out;
	const int n = stack->count();                              // @QStackedWidget::count
	for (int i = 0; i < n; ++i) {
		QWidget *page = stack->widget(i);                      // @QStackedWidget::widget
		if (page == nullptr)
			continue;
		// 页类型 0x11995d0;页 +0x40 = QListWidget(cited 类型面)
		auto *list = qobject_cast<QListWidget *>(page->findChild<QListWidget *>());
		if (list == nullptr)
			continue;
		for (int k = 0; k < list->count(); ++k) {
			QListWidgetItem *it = list->item(k);
			if (it == nullptr)
				continue;
			QObject *obj = it->data(Qt::UserRole).value<QObject *>(); // data(0x100)
			if (obj != nullptr && !out.contains(obj))          // QMap 去重
				out.append(obj);
		}
	}
	return out;
}
