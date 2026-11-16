#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QMenu>

// ZeroFieldDialogs.h — 八个**零字段**的对话框/菜单/输入件。
//
// 共同判据(八个全验过):dtor 一律 **29B**,内容只有
// "vptr 复位 + 基类析构"两行;`QMetaObject` 一律 methods=0 signals=0;
// `qt_metacall` 一律 5 字节纯转发。
// ⇒ **零自有字段、零信号、零槽**。所有内容在装配腿(内联,无独立 entry)。
//
// ⚠ 三处"按代码不按名字":
//   · **FontPreviewWidget 的基类是 QLineEdit**(dtor 调 QLineEdit::~QLineEdit),
//     名字带 Widget,实际是个输入框,不是预览控件基类;
//   · BreadMenu 的基类是 **QMenu**;
//   · 其余六个都是 QDialog。
//
// 出处(entry 地址逐一列,真身):
//   BreadMenu            dtor 0x008f8714 / deleting 0x008f8752 → QMenu
//   DefaultEditorDialog  dtor 0x00905276 / deleting 0x009052b4 → QDialog
//   EnvironmentDialog    dtor 0x00905378 / deleting 0x009053b6 → QDialog
//   FocusModeDialog      dtor 0x009054dc / deleting 0x0090551a → QDialog
//   HighlightTextDialog  dtor 0x00904406 / deleting 0x00904444 → QDialog
//   MasterPasswordDialog dtor 0x00904508 / deleting 0x00904546 → QDialog
//   TextMarkDialog       dtor 0x00908fbc / deleting 0x00908ffa → QDialog
//   FontPreviewWidget    dtor 0x008f0a7c / deleting 0x008f0aba → **QLineEdit**

class BreadMenuFace : public QMenu {
	Q_OBJECT
public:
	explicit BreadMenuFace(QWidget *parent = nullptr);
	~BreadMenuFace() override; // 0x008f8714
};

class DefaultEditorDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit DefaultEditorDialogFace(QWidget *parent = nullptr);
	~DefaultEditorDialogFace() override; // 0x00905276
};

class EnvironmentDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit EnvironmentDialogFace(QWidget *parent = nullptr);
	~EnvironmentDialogFace() override; // 0x00905378
};

class FocusModeDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit FocusModeDialogFace(QWidget *parent = nullptr);
	~FocusModeDialogFace() override; // 0x009054dc
};

class HighlightTextDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit HighlightTextDialogFace(QWidget *parent = nullptr);
	~HighlightTextDialogFace() override; // 0x00904406
};

class MasterPasswordDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit MasterPasswordDialogFace(QWidget *parent = nullptr);
	~MasterPasswordDialogFace() override; // 0x00904508
};

class TextMarkDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TextMarkDialogFace(QWidget *parent = nullptr);
	~TextMarkDialogFace() override; // 0x00908fbc
};

class FontPreviewWidgetFace : public QLineEdit {
	Q_OBJECT
public:
	explicit FontPreviewWidgetFace(QWidget *parent = nullptr);
	~FontPreviewWidgetFace() override; // 0x008f0a7c
};
