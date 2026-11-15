// ProfileDirDialogFace.cpp — 配置目录选择框装配(批 321)
#include "ProfileDirDialogFace.h"

#include <QButtonGroup>
#include <QDir>
#include <QHBoxLayout>
#include <QLabel>
#include <QRadioButton>
#include <QVBoxLayout>

// dirCompareDialog(1695B,0021.c:60991)装配真身(头部):
//   @006ce8e3 HBox/@006ce8f8 VBox;
//   @006ce90x QDir::toNativeSeparators(两路径实参);
//   @006ce93a +0x38 = QButtonGroup(this);
//   @006ce958 +0x60 = QLabel(this);@006ce976 +0x58 = QLabel(this);
//   @006ce9ba +0x68 = QLabel(tr("Please select your profile directory that
//     will be used to store user preferences.")(0xc9e098), this);
//   候选单选 + 路径行 + QDialogButtonBox(1695B 余段)— cited。
ProfileDirDialogFace::ProfileDirDialogFace(QWidget *parent)
	: QDialog(parent)
{
	setupUi();
}

void ProfileDirDialogFace::setupUi()
{
	m_hbox = new QHBoxLayout(); // @006ce8e3
	m_vbox = new QVBoxLayout(); // @006ce8f8
	m_group38 = new QButtonGroup(this); // @006ce93a(0x10)
	m_label60 = new QLabel(this);       // @006ce958
	m_label58 = new QLabel(this);       // @006ce976
	m_label68 = new QLabel(
	    tr("Please select your profile directory that will be used to store "
	       "user preferences."),
	    this); // 0xc9e098 @006ce9ba
	// 候选:"&Application Directory"(0xc9e0f0)/"&Home Directory"(0xc9e10e)
	//   与 " - %1" 路径模板(0xc9e106)— 单选/QDir 面 cited(余段未转写)。
}
