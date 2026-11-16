#pragma once

#include <QDialog>

// TriggerActionDialogFace — 语料 **TriggerActionDialog**(批 476)。
//
// **注意:本对话框不是"ctor 型",而是工厂型** ——
// FUN_006ff1a0(647B,0022.c:30666 邻) 内部 `new 0x48` 并返回指针,故不在
// "调 QDialog::QDialog 且写 vtable" 的 ctor 清单里(批 438 清单漏项,此处补)。
//
// 逐句实读:
//   dlg = new 0x48 + QDialog(parent, 0) → vtable **TriggerActionDialog_vtable**
//     + 副 0118bef0 →
//   setWindowTitle(**tr("Action")(0xc9fcf1)**)→ setAttribute(0x37, true) →
//   build()(FUN_006fe066,393B)+ body()(FUN_006f9f3c,**1369B**)→
//   connect(dlg, **QDialog::finished** → 闭包 impl **FUN_0070331a**
//     (捕获 dlg + 宿主))。
//   第二参数(param_2,char)控制模态/父显示面(cited)。
class TriggerActionDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TriggerActionDialogFace(QWidget *parent = nullptr);

	void build();   // FUN_006fe066(393B)
	// FUN_006f9f3c(1369B)**遍历 +0x38 容器的子件并逐页接线**:
	//   `findChildren<QWidget*>(this->+0x38, 递归=1)` → 逐件
	//   `dynamic_cast` 到 **typeinfo 0x1198430**(页类型)→ 命中者逐项 connect
	//   (闭包多枚;余段 cited)。
	void body();

protected:
	QWidget *m_body38 = nullptr; // +0x38(子件容器 = 页栈宿主)
};
