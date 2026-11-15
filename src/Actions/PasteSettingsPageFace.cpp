// PasteSettingsPageFace.cpp — 粘贴设置分类页装配(批 318)
#include "PasteSettingsPageFace.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QVBoxLayout>

// 006dfd9e(1221B)装配真身(结构段):
//   @006dfdc4 CategoryPage(parent)(0x38)+0x30 = 0;
//   @006dfe2a/+006dfe69/+006dfea8 三 QGroupBox(tr 0xc9ed8a/0xc9e86c/0xc9e87a)
//   @006dfee9 QLabel(tr 0xc9e887);
//   @006dff12 配置读 terminal.rightClickAction(cited);
//   后续行/单选/复选装配腿 cited(1221B 余段)。
PasteSettingsPageFace::PasteSettingsPageFace(QWidget *parent)
	: QWidget(parent)
{
	setupUi();
}

void PasteSettingsPageFace::setupUi()
{
	m_group1 = new QGroupBox(tr("Features"), this);       // @006dfe2a(0xc9ed8a)
	m_group2 = new QGroupBox(tr("Mouse Actions"), this);  // @006dfe69(0xc9e86c)
	m_group3 = new QGroupBox(tr("Paste Dialog"), this);   // @006dfea8(0xc9e87a)
	m_label = new QLabel(tr("When pasting multiple lines..."), this); // @006dfee9
	m_vbox = new QVBoxLayout();  // 页根布局(cited:装配序未逐句核对)
	m_form = new QFormLayout();  // 行布局(cited)
	// s_terminal_autoComplete_preselectBestM_6dcc80(parent,
	//   "terminal.rightClickAction", 空串)@006dff12 — cited(读面)。
	// 行/单选/复选装配(1221B 余段)— cited。
}
