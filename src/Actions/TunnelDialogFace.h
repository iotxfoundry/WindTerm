#pragma once

#include <QDialog>
#include <QString>

class QListWidgetItem;

// TunnelDialogFace — 语料 **TunnelDialog**(批 415 归属勘定完成)。
//
// ctor FUN_0072cf44(257B,0022.c:53750) asm 实测:
//   QDialog(parent, 0) → vtable **TunnelDialog_vtable** + 副 011a4e90 →
//   +0x80 = 0 / +0xa0 = 0 / +0xb8 = 空 QString →
//   setWindowTitle(tr("Tunnels")(0xc9d337)) → setAttribute(0x37, true) →
//   **buildUi()(s_king__tunnelDynamic_72c08e,3404B)** →
//   **wire()(dialog_connectAcceptReject,0072bbe2,935B)** →
//   QTimer::singleShot(0, 闭包 FUN_0072f007)。
//
// ⚠ 归属勘正(批 415):3404B 建造函数与 935B 接线函数**都属本类**。
//   本仓库此前把 935B 接线记在 SettingsPageFace 名下(批 258),
//   并把 3404B 的字段表也记到 SettingsPageFace(批 414)—— 二者来源实为本类;
//   SettingsPageFace 的字段模型**待收尾期复核**(不在此擅改,避免连带破坏)。
class TunnelDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TunnelDialogFace(QWidget *parent = nullptr); // FUN_0072cf44

	void buildUi();  // s_king__tunnelDynamic_72c08e(3404B) — 字段表见 .cpp
	void wire();     // dialog_connectAcceptReject(0072bbe2,935B)

	// FUN_0072bf8a(219B,0022.c:53235)行 → 列表项:
	//   item = new QListWidgetItem(0x30, row+0x10 /*名*/, 0, 0);
	//   icon = s_king__tunnelDynamicActive_6a2c16(row) →
	//     **setData(1 /*DecorationRole*/, icon)**;
	//   **setData(3 /*ToolTipRole*/, row+0x10)**;
	//   **setData(0x101, QVariant(row))** —— 行指针存在 0x101 角色里。
	static QListWidgetItem *makeRowItem(const void *row);

protected:
	QObject *m_grid30 = nullptr;      // +0x30(QGridLayout)
	QWidget *m_check38 = nullptr;     // +0x38(QCheckBox)
	QWidget *m_check40 = nullptr;     // +0x40(QCheckBox)
	QWidget *m_combo48 = nullptr;     // +0x48(QComboBox)
	QWidget *m_edit50 = nullptr;      // +0x50(QLineEdit)
	QWidget *m_combo58 = nullptr;     // +0x58(QComboBox)
	QWidget *m_edit60 = nullptr;      // +0x60(QLineEdit)
	QWidget *m_spin68 = nullptr;      // +0x68(QSpinBox)
	QWidget *m_spin70 = nullptr;      // +0x70(QSpinBox)
	QWidget *m_buttons78 = nullptr;   // +0x78(QDialogButtonBox)
	QObject *m_f80 = nullptr;         // +0x80(ctor 清 0)
	QWidget *m_label88 = nullptr;     // +0x88(QLabel)
	QWidget *m_label90 = nullptr;     // +0x90(QLabel)
	QWidget *m_busy98 = nullptr;      // +0x98(0xa0 遮挡)
	QWidget *m_textA0 = nullptr;      // +0xa0(ctor 清 0)
	QWidget *m_listA8 = nullptr;      // +0xa8(0x48 列表)
	QWidget *m_listB0 = nullptr;      // +0xb0(0x48 列表)
};
