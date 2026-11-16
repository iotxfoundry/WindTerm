#pragma once

#include <QFileDialog>
#include <QString>

// FileDialogFaces.h — 两个文件选择对话框(都派生自 **QFileDialog**,各一个字段)。
//
// | 类 | 基类(dtor 末句) | dtor | deleting | 字段 |
// |---|---|---|---|---|
// | FileDialog      | **QFileDialog** | 0x008fa5e6(86B) | 0x008fa4d2(92B) | +0x30 |
// | ModemFileDialog | **QFileDialog** | 0x00904662(86B) | 0x00904718(92B) | +0x30 |
//
// 两者 **dtor 逐字节同构**(86B,同样只碰 +0x30),且副 vptr 也都是
// `PTR_FUN_0119cc50` ⇒ 是同一模板的两个实例化产物,只是用途不同
// (普通文件选择 / 调制解调器传输用的文件选择)。
//
// metacall 均 5B 纯转发 ⇒ 0 条自有信号槽。
//
// ⚠ **ModemFileDialog 与 ZMODEM 传输相关** —— 但注意它只是"选文件"的对话框,
//   真正的传输在 Sessions/Transfers/Modem 族里(已落)。别把两者混为一谈。
//
// 出处(entry 地址逐一列,真身):
//   FileDialog      dtor 0x008fa5e6 / deleting 0x008fa4d2
//                   metaObject 0x008fa472 / metacast 0x008fa48a / vt6 0x005564a6(87B)
//   ModemFileDialog dtor 0x00904662 / deleting 0x00904718
//                   metaObject 0x009045aa / metacast 0x009045c2

class FileDialogFace : public QFileDialog {
	Q_OBJECT
public:
	explicit FileDialogFace(QWidget *parent = nullptr);
	~FileDialogFace() override; // 0x008fa5e6
private:
	QString m_f30; // +0x30
};

class ModemFileDialogFace : public QFileDialog {
	Q_OBJECT
public:
	explicit ModemFileDialogFace(QWidget *parent = nullptr);
	~ModemFileDialogFace() override; // 0x00904662
private:
	QString m_f30; // +0x30
};
