// ZeroFieldDialogs.cpp — 八个零字段对话框(见头注对照表)。

#include "Widgets/Dialogs/ZeroFieldDialogs.h"

// 出处:八者的 QMetaObject 均 methods=0 signals=0、metacall 均 5 字节纯转发;
// ctor 均内联在调用点,只转发基构造。
// 八者 dtor 均 29B 真身(= vptr 复位 + 基类析构两行)⇒ 零自有字段;
// deleting 均 47B 真身(= 再加 operator_delete(_, size))。

BreadMenuFace::BreadMenuFace(QWidget *parent) : QMenu(parent) { }
BreadMenuFace::~BreadMenuFace() = default;                 // 0x008f8714 → QMenu

DefaultEditorDialogFace::DefaultEditorDialogFace(QWidget *parent) : QDialog(parent) { }
DefaultEditorDialogFace::~DefaultEditorDialogFace() = default; // 0x00905276

EnvironmentDialogFace::EnvironmentDialogFace(QWidget *parent) : QDialog(parent) { }
EnvironmentDialogFace::~EnvironmentDialogFace() = default;   // 0x00905378

FocusModeDialogFace::FocusModeDialogFace(QWidget *parent) : QDialog(parent) { }
FocusModeDialogFace::~FocusModeDialogFace() = default;       // 0x009054dc

HighlightTextDialogFace::HighlightTextDialogFace(QWidget *parent) : QDialog(parent) { }
HighlightTextDialogFace::~HighlightTextDialogFace() = default; // 0x00904406

MasterPasswordDialogFace::MasterPasswordDialogFace(QWidget *parent) : QDialog(parent) { }
MasterPasswordDialogFace::~MasterPasswordDialogFace() = default; // 0x00904508

TextMarkDialogFace::TextMarkDialogFace(QWidget *parent) : QDialog(parent) { }
TextMarkDialogFace::~TextMarkDialogFace() = default;         // 0x00908fbc

FontPreviewWidgetFace::FontPreviewWidgetFace(QWidget *parent) : QLineEdit(parent) { }
FontPreviewWidgetFace::~FontPreviewWidgetFace() = default;   // 0x008f0a7c → **QLineEdit**
