// SimpleDialogs.cpp — 四个零元接口的小对话框(见头注对照表)。

#include "Widgets/Dialogs/SimpleDialogs.h"

// 出处:四者的 QMetaObject 均为 methods=0 / signals=0 / props=0 / superdata=0
// (NameDialog 0x011a15e0 / PasswordDialog 0x011a1ae0 /
//  MaskDialog 0x011a3b00 / InsertFilePage 0x011ac360);
// ctor 均内联在调用点,只转发基构造。

// dtor 0x009048ea(86B):vptr 复位 → +0x38 QString 减引用 → QDialog::~QDialog
// deleting 0x009047d6(92B):+ operator_delete(_, 0x58)
NameDialogFace::NameDialogFace(QWidget *parent) : QDialog(parent) { }
NameDialogFace::~NameDialogFace() = default;

// dtor 0x00765350(138B):vptr 复位 → +0x60/+0x58 两个 QString 减引用 → QDialog
// deleting 0x00765466(144B):+ operator_delete(_, 0x70)
PasswordDialogFace::PasswordDialogFace(QWidget *parent) : QDialog(parent) { }
PasswordDialogFace::~PasswordDialogFace() = default;

// dtor 0x007050a6(86B):vptr 复位 → +0x30 QString 减引用 → **QWidget**::~QWidget
// deleting 0x00705102(23B):+ operator_delete(_, 0xb0)
MaskDialogFace::MaskDialogFace(QWidget *parent) : QWidget(parent) { }
MaskDialogFace::~MaskDialogFace() = default;

// dtor 0x0091e874(19B):只有 QObject::~QObject —— 零字段
// deleting 0x0091e888(37B):+ operator_delete(_, 0x10)
InsertFilePageFace::InsertFilePageFace(QObject *parent) : QObject(parent) { }
InsertFilePageFace::~InsertFilePageFace() = default;
