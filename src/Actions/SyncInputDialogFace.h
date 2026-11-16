#pragma once

#include <QDialog>
#include <QString>

// SyncInputDialogFace — 语料 **SyncInputDialog**(批 424)。
//
// ctor FUN_0072abce(239B,0022.c:...) asm 实测:
//   QDialog(parent, 0) → vtable **SyncInputDialog_vtable** + 副 011a44b0 →
//   **+0x60 = int 0** / **+0x68 = 空 QString** →
//   setWindowTitle(tr("Sync Input")(0xc89b32)) → setAttribute(0x37, true) →
//   buildMain()(FUN_00729f1e,3005B)+ buildExtra()(FUN_00729616,867B)→
//   QTimer::singleShot(0, 闭包 FUN_0072b69e)。
class SyncInputDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit SyncInputDialogFace(QWidget *parent = nullptr);

	void buildMain();   // FUN_00729f1e(3005B) — 结构段
	void buildExtra();  // FUN_00729616(867B) — 结构段

protected:
	int m_f60 = 0;        // +0x60
	QString m_f68;        // +0x68
};
