#pragma once

#include <QDialog>
#include <QString>

class QListWidgetItem;
class QIcon;

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
	// 行结构(由 s_king__tunnelDynamicActive_6a2c16 + makeRowItem 交叉实读):
	//   +0x10 QString 名称(item 文本 & 提示)/ **+0x18 int kind**
	//   (1 = Dynamic / 2 = Local / 3 = Remote)/ +0x20 QString 标志(空 → Active)/
	//   +0x30 int 协议(1/2)。
	struct TunnelRow {
		char f00[0x10] = {};
		QString name10;      // +0x10
		int kind18 = 0;      // +0x18
		char pad1c[4] = {};
		QString flag20;      // +0x20
		char f28[8] = {};
		int proto30 = 0;     // +0x30
		char f34[4] = {};
		QString f38;         // +0x38(行内引用计数对象;析构逐行释放)
	};

	// FUN_0072d056(147B)协议填充:`s_session_protocol_80b1d8(全局配置,
	//   +0x48 下拉, "SSH")` —— 由全局会话配置填协议表(键 "SSH" 实读)。
	void fillProtocols();

	// FUN_0072f007(53B)ctor 的 singleShot 落点:
	//   ① FUN_0072d056(this)(协议填充)② FUN_0072edfe(this)(521B 初始装载)。
	void initialLoad();

	// FUN_0072d0f2(242B)整行复位(= SettingsPageFace::resetRow 的同源真身):
	//   !enable 时逐件清:+0x50 clear / +0x58 与 +0x48 setCurrentIndex /
	//   +0x70 与 +0x68 setValue / +0x60 clear / +0x38 与 +0x40 setChecked /
	//   +0x98 FUN_0056672a(…,0,0,0) / **+0x30 QLabel::clear()**。
	void resetRow(bool enable);

	// FUN_0072edfe(521B,0022.c:55065)行表装载:
	//   src = FUN_006a4d90(DAT_011c1b00)(全局隧道表);与 +0xb8 不同 → 引用
	//   计数换手(旧表 FUN_0072b9ca 释放);随后按 **0x48 步长**扩容
	//   (qlist72_realloc)并逐行落表。
	//   ⇒ +0xb8 = QList<0x48 行>(与本类行结构一致)。
	void reloadRows();

	// FUN_0072b9ca(535B,0022.c:53017)行表析构:
	//   按 **0x48 步长**遍历 +0x10 起各行;逐行释放其 +0x38(引用计数对象);
	//   末 QArrayData::deallocate(list, 0x48, 8)。
	static void destroyRows(QList<TunnelRow> &rows);

	// s_king__tunnelDynamicActive_6a2c16(431B)**名不副实**=行图标:
	//   标志(+0x20)为空 → 按 kind 取
	//     `king::tunnelDynamicActive` / `king::tunnelLocalActive` /
	//     `king::tunnelRemoteActive`;
	//   否则 → `king::tunnelDynamic` / `king::tunnelLocal` /
	//     `king::tunnelRemote`;(同族另有 `…Error` 三支)
	//   再按 +0x30 协议分支;图标经 ThemeIcons::loadSvg。
	static QIcon rowIcon(const TunnelRow &row);

	static QListWidgetItem *makeRowItem(const TunnelRow &row);

protected:
	QList<TunnelRow> m_rowsB8;        // +0xb8(0x48 步长行表)
	QWidget *m_label30 = nullptr;     // +0x30(**QLabel** —— 批 417 勘正:FUN_0072d0f2 调 QLabel::clear)
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
