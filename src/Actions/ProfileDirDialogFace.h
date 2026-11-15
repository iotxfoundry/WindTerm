#pragma once

#include <QDialog>

class QButtonGroup;
class QDialogButtonBox;
class QHBoxLayout;
class QLabel;
class QRadioButton;
class QVBoxLayout;

// ProfileDirDialogFace — 语料配置目录选择对话框(批 321)。
// 函数名 dirCompareDialog(1695B,0021.c:60991) **名不副实**:文案实证为
//   配置目录选择("Please select your profile directory that will be used
//   to store user preferences." 0xc9e098)。
// 装配序:
//   @006ce8e3 HBoxLayout(0x20);@006ce8f8 VBoxLayout(0x20);
//   @006ce90x QDir::toNativeSeparators(两路径);
//   @006ce93a +0x38 = QButtonGroup(this)(0x10);
//   @006ce958 +0x60 = QLabel(this);@006ce976 +0x58 = QLabel(this);
//   @006ce9ba +0x68 = QLabel(tr(0xc9e098), this);
//   候选串:"&Application Directory"(0xc9e0f0) / "&Home Directory"(0xc9e10e)
//     / " - %1" 模板(0xc9e106);QDialogButtonBox 收尾(cited)。
class ProfileDirDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit ProfileDirDialogFace(QWidget *parent = nullptr);
	void setupUi();

private:
	QButtonGroup *m_group38 = nullptr;  // +0x38
	QLabel *m_label58 = nullptr;        // +0x58
	QLabel *m_label60 = nullptr;        // +0x60
	QLabel *m_label68 = nullptr;        // +0x68
	QRadioButton *m_appDir = nullptr;   // "&Application Directory"(cited 槽)
	QRadioButton *m_homeDir = nullptr;  // "&Home Directory"(cited 槽)
	QHBoxLayout *m_hbox = nullptr;      // cited 槽
	QVBoxLayout *m_vbox = nullptr;      // cited 槽
};
