#pragma once

#include <QDialog>
#include <QObject>
#include <QString>
#include <QWidget>

// SimpleDialogs.h — 四个**零元接口**的小对话框/页。
//
// 为什么放一个文件:四者的 JSON 元对象全是
// `methods=0 / signals=0 / props=0 / superdata=0` —— 没有任何槽或信号,
// 全部信息只在 dtor 的字段释放里。它们同层(Widgets/Dialogs 或 Wizard 页)、
// 同性质(纯装配体),按 §1.1「同组同层」归一处。
//
// 共同点(四个都验证过):metacall 一律 **5 字节纯转发**基类,说明确实零记录。
// ⇒ 这类类 **`--class` 查不出任何东西**,不能用"查不到信号"推断"未逆向"。
//
// | 类 | 基类 | sizeof | 自有字段 |
// |---|---|---|---|
// | NameDialog      | QDialog  | 0x58 | +0x38 QString |
// | PasswordDialog  | QDialog  | 0x70 | +0x58 / +0x60 QString |
// | MaskDialog      | **QWidget** | 0xb0 | +0x30 QString |
// | InsertFilePage  | QObject  | 0x10 | **零字段** |
//
// 注意 MaskDialog 的基类是 **QWidget 不是 QDialog**(dtor 调 QWidget::~QWidget)
// —— 名字带 Dialog 但实现是遮罩控件,按代码不按名字。
// InsertFilePage 是 QObject 且尺寸 0x10 = QObject 本身体积 ⇒ 纯身份页。
//
// 出处(entry 地址逐一列):
//   NameDialog     dtor 0x009048ea / deleting 0x009047d6
//   PasswordDialog dtor 0x00765350 / deleting 0x00765466
//   MaskDialog     dtor 0x007050a6 / deleting 0x00705102
//   InsertFilePage dtor 0x0091e874 / deleting 0x0091e888

class NameDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit NameDialogFace(QWidget *parent = nullptr);
	~NameDialogFace() override; // 0x009048ea
private:
	QString m_f38; // +0x38
};

class PasswordDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit PasswordDialogFace(QWidget *parent = nullptr);
	~PasswordDialogFace() override; // 0x00765350
private:
	QString m_f58; // +0x58
	QString m_f60; // +0x60
};

class MaskDialogFace : public QWidget {
	Q_OBJECT
public:
	explicit MaskDialogFace(QWidget *parent = nullptr);
	~MaskDialogFace() override; // 0x007050a6
private:
	QString m_f30; // +0x30
};

class InsertFilePageFace : public QObject {
	Q_OBJECT
public:
	explicit InsertFilePageFace(QObject *parent = nullptr);
	~InsertFilePageFace() override; // 0x0091e874
};
