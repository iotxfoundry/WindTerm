#pragma once

#include <QDialog>

class QComboBox;
class QDialogButtonBox;
class QLineEdit;
class QWidget;

// TextMarkDialogFace — 语料 TextMarkDialog(批 438)。
//
// ctor FUN_006f1036(175B,0022:18703) asm 实测:
//   QDialog(parent, 0)@006f1043 → vtable TextMarkDialog_vtable + 副 011a4730 →
//   setWindowTitle(tr("Text Mark")(0xc9faaa))@006f1089 →
//   setAttribute(0x37, WA_DeleteOnClose, 1)@006f10b1 →
//   **search_page_build_layout(param_1)@006f10b9** →
//   **options_connectSignals(param_1)@006f10c1**(cited:006edc90,0022:16933)。
//
// 批 191 曾在 SettingsFace 里重复建模同一 ctor 与 search_page_build_layout,
// 2026-11-16 已归位到本类(同一个二进制类只应有一份实现)。
class TextMarkDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TextMarkDialogFace(QWidget *parent = nullptr);

private:
	// FUN_006f09ba(1498B,0022:18501)布局结构面真身:
	//   QVBoxLayout→QFormLayout×2→QGroupBox tr"Match"/tr"Style"→
	//   +0x38 TriggerActionEditPanel(0xe000)→+0x48 QLineEdit→
	//   +0x50/+0x58/+0x60 ColorButton×3→+0x68 searchCombo(14 项)→
	//   +0x70 preview→+0x30 QDialogButtonBox(Ok|Cancel)→tabOrder 链→
	//   singleShot(0,this) setFocus(+0x40,3)→FUN_0075c132(0,0) 仅
	//   setSizeGripEnabled(1)。
	void searchPageBuildLayout();

	QDialogButtonBox *m_buttons = nullptr; // +0x30(0x400400 Ok|Cancel)
	QWidget *m_panel = nullptr;            // +0x38 TriggerActionEditPanel(cited 壳)
	QWidget *m_panelField = nullptr;       // +0x40(panel+0x40 转发)
	QLineEdit *m_pattern = nullptr;        // +0x48
	QWidget *m_textColor = nullptr;        // +0x50 ColorButton(cited)
	QWidget *m_bgColor = nullptr;          // +0x58 ColorButton(cited)
	QWidget *m_lineColor = nullptr;        // +0x60 ColorButton(cited)
	QComboBox *m_searchCombo = nullptr;    // +0x68
	QLineEdit *m_preview = nullptr;        // +0x70 FontPreviewWidget(cited 壳)
};
