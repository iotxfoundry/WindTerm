// EnvDialogFace.cpp — 环境变量对话框装配转写(批 313)
#include "EnvDialogFace.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QPlainTextEdit>
#include <QProcessEnvironment>

// envDialog_setupUi(1109B,0021.c:42909)装配真身:
//   @006b3124 +0x48 = new QPlainTextEdit(this)(0x30 字节);
//   @006b3140 +0x40 = combo_makeSearchCombo(this)(0x48 字节);
//   @006b315c +0x30 = new QDialogButtonBox(this)(0x30 字节);
//   @006b3179 QFormLayout(0x20);@006b31xx FUN_0075d6e8(app,this)(cited);
//   @006b31cx setMinimumWidth/setMinimumHeight(实参 Ghidra 折叠 → cited);
//   @006b31fx setWordWrapMode(+0x48, 3 = WrapAnywhere)@006b32xx;
//   @006b3203 systemEnvironment().keys() → 逐项入组合框(后续体 cited)。
EnvDialogFace::EnvDialogFace(QWidget *parent)
	: QDialog(parent)
{
	setupUi(); // 语料 ctor 未定位 → 构造即装配(cited)
}

void EnvDialogFace::setupUi()
{
	m_edit48 = new QPlainTextEdit(this); // @006b3124(0x30)
	m_combo40 = new QComboBox(this);     // @006b3140(combo_makeSearchCombo 壳)
	m_buttons30 = new QDialogButtonBox(this); // @006b315c(0x30)
	auto *form = new QFormLayout();      // @006b3179(0x20)
	Q_UNUSED(form);                      // 行装配腿 cited(后续体未转写)
	// FUN_0075d6e8(app, this)@006b31xx — cited(对话框公共腿)
	// setMinimumWidth/Height(实参折叠)— cited
	m_edit48->setWordWrapMode(QTextOption::WrapAnywhere); // 3 @006b32xx
	const QStringList keys = QProcessEnvironment::systemEnvironment().keys(); // @006b3203
	// keys 逐项入组合框(+ 后续过滤/排序腿)— cited(体未转写)
	Q_UNUSED(keys);
}
