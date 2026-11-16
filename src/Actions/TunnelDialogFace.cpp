// TunnelDialogFace.cpp — 隧道对话框(批 415)
#include "TunnelDialogFace.h"

#include "ThemeIcons.h"

#include <QDialogButtonBox>
#include <QIcon>
#include <QListWidgetItem>
#include <QVariant>

// FUN_0072cf44(257B,0022.c:53750)ctor 真身
TunnelDialogFace::TunnelDialogFace(QWidget *parent)
	: QDialog(parent, Qt::WindowFlags(0)) // @0072cf44
{
	// vtable TunnelDialog_vtable / 副 011a4e90(C++ 自洽)
	m_f80 = nullptr;                      // +0x80
	m_textA0 = nullptr;                   // +0xa0
	setWindowTitle(QStringLiteral("Tunnels"));            // tr(0xc9d337)
	setAttribute(Qt::WA_DeleteOnClose /*0x37*/, true);    // @0072cfe3
	buildUi();                            // @s_king__tunnelDynamic_72c08e
	wire();                               // dialog_connectAcceptReject
	// QTimer::singleShot(0, this, 闭包 FUN_0072f007)@0072d0xx — cited
}

// s_king__tunnelDynamic_72c08e(3404B,0022.c:53270)建造真身(字段表):
//   **+0x30 = QGridLayout(0x20)** / +0x38 QCheckBox / +0x40 QCheckBox /
//   +0x48 QComboBox / +0x50 QLineEdit / +0x58 QComboBox / +0x60 QLineEdit /
//   +0x68 QSpinBox / +0x70 QSpinBox / +0x78 QDialogButtonBox /
//   +0x88 QLabel / +0x90 QLabel / +0x98 遮挡件(0xa0) /
//   +0xa8 0x48 列表件 / +0xb0 0x48 列表件。
//   (0x30/0x38/… = 字段偏移;逐对 operator_new 尺寸 + 构造类实测。)
void TunnelDialogFace::buildUi()
{
	m_grid30 = nullptr;                   // +0x30 QGridLayout — cited(建造体未逐句转写)
	m_check38 = m_check40 = nullptr;
	m_combo48 = m_combo58 = nullptr;
	m_edit50 = m_edit60 = nullptr;
	m_spin68 = m_spin70 = nullptr;
	m_buttons78 = nullptr;
	m_label88 = m_label90 = nullptr;
	m_busy98 = nullptr;
	m_listA8 = m_listB0 = nullptr;
}

// dialog_connectAcceptReject(935B,0022.c:53137)接线真身(结构段):
//   +0x78 "2accepted()"→"1accept()";+0x78 "2rejected()"→"1reject()";
//   +0xa8 信号 FUN_008ef798 → FUN_0072db3c;smeta FUN_0072f0b0;
//   +0xa8 信号 FUN_008ef7fc → FUN_0072e8d2;smeta FUN_0072f0b0;
//   +0x50 QLineEdit → FUN_0072e49a;+0x98 信号 FUN_008faeac → FUN_0072e4c8;
//   +0x58 QComboBox → FUN_0072eb15;smeta FUN_0072f120;FUN_0072bf8a 另两处。
void TunnelDialogFace::wire()
{
	if (m_buttons78 != nullptr) {
		connect(m_buttons78, &QDialogButtonBox::accepted, this, &QDialog::accept);
		connect(m_buttons78, &QDialogButtonBox::rejected, this, &QDialog::reject);
	}
	// 其余六路(体 FUN_0072db3c/0072e8d2/0072e49a/0072e4c8/0072eb15)— cited
}

// s_king__tunnelDynamicActive_6a2c16(431B,0021.c:...)行图标真身
QIcon TunnelDialogFace::rowIcon(const TunnelRow &row)
{
	QString name;
	if (row.flag20.isEmpty()) {                  // @006a2c2x(+0x20 size == 0)
		switch (row.kind18) {                     // +0x18
		case 1: name = QStringLiteral("king::tunnelDynamicActive"); break;
		case 2: name = QStringLiteral("king::tunnelLocalActive"); break;
		case 3: name = QStringLiteral("king::tunnelRemoteActive"); break;
		default: break;
		}
	} else {
		switch (row.kind18) {
		case 1: name = QStringLiteral("king::tunnelDynamic"); break;
		case 2: name = QStringLiteral("king::tunnelLocal"); break;
		case 3: name = QStringLiteral("king::tunnelRemote"); break;
		default: break;
		}
	}
	if (name.isEmpty())
		return QIcon();
	return ThemeIcons::loadSvg(name, QString()); // DAT_011c1ce0 主题
}

// FUN_0072bf8a(219B)行 → 列表项真身
QListWidgetItem *TunnelDialogFace::makeRowItem(const TunnelRow &row)
{
	auto *item = new QListWidgetItem(row.name10, nullptr);   // @0072bfb6(0x30,text = +0x10)
	item->setData(Qt::DecorationRole, rowIcon(row));          // @0072bfde(setData 1, icon)
	item->setData(Qt::ToolTipRole, row.name10);               // @0072c01f(setData 3)
	item->setData(0x101, QVariant::fromValue<quintptr>(
		reinterpret_cast<quintptr>(&row)));                   // @0072c048(setData 0x101 行指针)
	return item;
}
