#pragma once

#include <QWidget>

class QComboBox;
class QFormLayout;
class QGroupBox;
class QLabel;
class QVBoxLayout;

// PasteSettingsPageFace — 语料"粘贴"设置分类页(批 318)。
// 函数名 pasteDialog_6dfd9e(1221B,0022.c:..."s_terminal_altScreen_
//   pasteDialog_6dfd9e"),实为 **CategoryPage 子类**(vtable CategoryPage
//   @006dfdc4,0x38 字节):三 QGroupBox + 一 QLabel + 配置读。
// 装配序:
//   @006dfdc4 CategoryPage(parent) → +0x30 = 0;
//   @006dfe2a 组1 = QGroupBox(tr(<0xc9ed8a> "Features"));
//   @006dfe69 组2 = QGroupBox(tr("Mouse Actions")(0xc9e86c));
//   @006dfea8 组3 = QGroupBox(tr("Paste Dialog")(0xc9e87a));
//   @006dfee9 标签 = QLabel(tr("When pasting multiple lines...")(0xc9e887));
//   @006dff12 配置读 s_terminal_autoComplete_preselectBestM_6dcc80(
//     parent,"terminal.rightClickAction",空串)(cited 读面)。
class PasteSettingsPageFace : public QWidget {
	Q_OBJECT
public:
	explicit PasteSettingsPageFace(QWidget *parent = nullptr); // 006dfd9e
	void setupUi();

private:
	QVBoxLayout *m_vbox = nullptr;   // 页根布局(cited 装配腿)
	QGroupBox *m_group1 = nullptr;   // 组1"Features"
	QGroupBox *m_group2 = nullptr;   // 组2"Mouse Actions"
	QGroupBox *m_group3 = nullptr;   // 组3"Paste Dialog"
	QLabel *m_label = nullptr;       // "When pasting multiple lines..."
	QFormLayout *m_form = nullptr;   // 行布局(cited)
	QComboBox *m_rightClickCombo = nullptr; // "terminal.rightClickAction" 选择器
	QWidget *m_localModeW = nullptr;        // terminal.localModeEnabled 面
	QWidget *m_screenPasteW = nullptr;      // terminal.screen.pasteDialog 面
	QWidget *m_altPasteW = nullptr;         // terminal.altScreen.pasteDialog 面
};
