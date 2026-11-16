#pragma once

#include <QDialog>
#include <QString>

class QTextEdit;

// HelpDialogFace — 语料 **VcXsrv 帮助对话框**(工厂型,批 478)。
//
// FUN_006ebd28(794B,0022.c:...) 逐句实读:
//   dlg = **new 0x30** + QDialog(parent, 0)(工厂型,故不在 ctor 清单里);
//   **QTextEdit(0x30)** 只读正文;
//   **QDialogButtonBox(0x30, 0x200000)** —— 0x200000 = **Close 单钮**;
//   QVBoxLayout(0x20);
//   路径 = `QCoreApplication::applicationDirPath()` +
//     **"/vendors/vcxsrv/help.md"**(convertFromAscii 实读)→ QFile 读入 →
//     setPlainText / setHtml(余段 cited)。
//   ⇒ 这是随包附带的 **VcXsrv 帮助/许可** 弹窗。
class HelpDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit HelpDialogFace(QWidget *parent = nullptr);

	void build();                  // FUN_006ebd28(794B)
	static QString helpFilePath(); // applicationDirPath + 固定相对路径

protected:
	QTextEdit *m_text30 = nullptr; // QTextEdit(0x30)
};
