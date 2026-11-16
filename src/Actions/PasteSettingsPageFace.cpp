// PasteSettingsPageFace.cpp — 粘贴设置分类页装配(批 318)
#include "PasteSettingsPageFace.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QVariant>

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
	// 右键动作选择器:配置 "terminal.rightClickAction"(preselectBestM 读面 cited)
	//   三项(值/标签逐条实读 @006dff4e/006dffa2/006dfff6):
	//   ShowMenu→"Show menu"(0xc9e8a4)、PasteText→"Paste text"(0xc9e8ae)、
	//   CopyOrPasteText→"Copy text if selected, otherwise paste text"(0xc9f6a8)。
	m_rightClickCombo = new QComboBox(this);
	m_rightClickCombo->addItem(tr("Show menu"), QStringLiteral("ShowMenu"));
	m_rightClickCombo->addItem(tr("Paste text"), QStringLiteral("PasteText"));
	m_rightClickCombo->addItem(tr("Copy text if selected, otherwise paste text"),
	                           QStringLiteral("CopyOrPasteText"));
	// 三个配置背衬控件(FUN_006dcb1e(parent, tr, 键)@006e0050/006e008f/006e00ce):
	//   "terminal.localModeEnabled"(tr "Enable &local mode" 0xc9e8b9)、
	//   "terminal.screen.pasteDialog"(tr "Show paste dialog on the &main
	//     screen" 0xc9f6d8)、"terminal.altScreen.pasteDialog"(tr "...&alternate
	//     screen" 0xc9f700)— 控件工厂体 cited。
	// 三 FormLayout 装配(asm 0x6e0157-0x6e01c8 逐实参):
	//   @0x6e0157 form?->addRow(form3);
	//   @0x6e0171 tr("&Right click:")(0xc9e8cc)→ @0x6e0184
	//     form4->addRow(标签, 选择器)(rdx = 选择器);
	//   @0x6e0199/@0x6e01a9/@0x6e01b6 form5->addRow(三配置件);
	//   @0x6e01c8 host->setLayout(vbox)/(0x6e01cd) 页根。
	m_form4 = new QFormLayout();          // @006e0109
	m_form5 = new QFormLayout();          // @006e0122
	m_form4->setRowWrapPolicy(QFormLayout::WrapLongRows); // 2
	if (m_rightClickCombo != nullptr)
		m_form4->addRow(tr("&Right click:"), m_rightClickCombo); // @0x6e0184
	for (QWidget *w : {m_localModeW, m_screenPasteW, m_altPasteW})
		if (w != nullptr)
			m_form5->addRow(w); // @0x6e0199-0x6e01b6
	setLayout(m_vbox);                  // @0x6e01c8
}
