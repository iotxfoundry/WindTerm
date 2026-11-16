#pragma once

#include <QIcon>
#include <QString>
#include <QStyledItemDelegate>
#include <QTableWidget>
#include <QWidget>

// DelegateControls.h — 委托/表格控件族(六个,全部薄类)。
//
// 判据:metacall 均 **5 字节纯转发** ⇒ 0 条自有槽;下表的信号是各自
// QMetaObject 里唯一的记录。superdata 一并实读。
//
// | 类 | superdata 实读 | sizeof/dtor | 唯一信号 | 字段 |
// |---|---|---|---|---|
// | CheckEditor        | 无(直接 QWidget/QObject 系) | dtor 29B | slipToggled | 零 |
// | EditDelegate       | 无 | dtor 66B | commitText | 有(见注) |
// | TransferDelegate   | 无 | dtor 36B | — | **+0x10 QIcon** |
// | TableWidget        | 无 | dtor 86B | — | **+0x38 QString** |
// | TablePanel         | **0x01193440 ButtonBarPanel** | dtor 66B | — | 有 |
// | TextMarkTablePanel | **0x011d880 TablePanel** | dtor 29B | — | 零 |
// | FileTree           | **0x0119dc40 TreeView** | dtor 29B | aboutToRename | 零 |
//
// 两处值得记:
// · **TextMarkTablePanel 的基链是三跳**:`TextMarkTablePanel → TablePanel →
//   ButtonBarPanel → QFrame`。superdata 逐跳读出来,不是两跳。
// · TransferDelegate 的 dtor 只有 36B:先 `QIcon::~QIcon(+0x10)` 再
//   `QStyledItemDelegate::~QStyledItemDelegate` ⇒ 唯一字段是 **QIcon**,
//   而且它是 **QStyledItemDelegate 直接派生**(不是经 WidgetDelegate)。
//   ⇒ **委托族并非全部派生自 WidgetDelegate**,CheckDelegate 才是。
//
// 出处(entry 地址逐一列,真身):
//   CheckEditor        dtor 0x008effd8 / deleting 0x008f0016 / vt0 0x008efe12
//   EditDelegate       dtor 0x008f1d7a / deleting 0x008f1dbc
//   TransferDelegate   dtor 0x008f9846 / deleting 0x008f986a / vt13 0x00574bd6(98B)
//   TableWidget        dtor 0x008f1662 / deleting 0x008f154e
//   TablePanel         dtor 0x008f16d2 / deleting 0x008f1714
//   TextMarkTablePanel dtor 0x008f171a / deleting 0x008f1758 / vt0 0x008f16ba
//   FileTree           dtor 0x008f9b0e / deleting 0x008f9b4c / h8fb472 0x008fb472(176B)

class ButtonBarPanelFace;
class TreeViewFace;

class CheckEditorFace : public QWidget {
	Q_OBJECT
public:
	explicit CheckEditorFace(QWidget *parent = nullptr);
	~CheckEditorFace() override; // 0x008effd8
signals:
	void slipToggled(bool on); // 唯一信号
};

class EditDelegateFace : public QStyledItemDelegate {
	Q_OBJECT
public:
	explicit EditDelegateFace(QObject *parent = nullptr);
	~EditDelegateFace() override; // 0x008f1d7a
signals:
	void commitText(const QString &text); // 唯一信号
};

class TransferDelegateFace : public QStyledItemDelegate {
	Q_OBJECT
public:
	explicit TransferDelegateFace(QObject *parent = nullptr);
	~TransferDelegateFace() override; // 0x008f9846
private:
	QIcon m_icon10; // +0x10
};

class TableWidgetFace : public QTableWidget {
	Q_OBJECT
public:
	explicit TableWidgetFace(QWidget *parent = nullptr);
	~TableWidgetFace() override; // 0x008f1662
private:
	QString m_f38; // +0x38
};
