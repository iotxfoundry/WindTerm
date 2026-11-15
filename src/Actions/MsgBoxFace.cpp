// MsgBoxFace.cpp — 富文本消息框族(批 317)
#include "MsgBoxFace.h"

#include <QCheckBox>
#include <QMessageBox>

// msgbox_buildRich(918B,0019.c:55557)真身(结构面):
//   @00615d26 new QMessageBox(nullptr);
//   @00615d6a 行1 = tr("File name")(0xc90200) + name;
//   @00615dc1 行2 = tr(<0xc9d3fe>) + remotePath;
//   @00615e0e 行3 = tr("Remote path")(0xc9020a) + third;
//     (三行均经 FUN_00615ad0(行拼) — cited)
//   @00615e4x watcher == 0 → 文案 tr(0xc90048)("A remote file has been
//     modified....")+ icon 3 + buttons 0x400 + 复选 tr("Stop watching
//     this file")(0xc90216);
//   @00615e5d watcher != 0 → 文案 tr(0xc900a0)("This remote file cannot be
//     uploaded...")+ icon 1 + buttons 0x1c000;
//   @00615exx 正文 = "<pre>%1<br><table>"(0xc90228).arg(行)+ 表行 +
//     fromUtf8(0xc8a3c9) 尾;
//   @00615f27 setAttribute(0x37=WA_DeleteOnClose,1);
//   @00615f3x setWindowFlags(flags | 0x40000);
//   @00615f4x setText/setWindowTitle(tr("Upload File") 0xc90241)/
//     setIcon(icon)/setStandardButtons(buttons)/setCheckBox(check);
//   @00615fxx 主屏 availableSize → setMinimumSize;vt+0x1a0 尾;activateWindow。
QMessageBox *msgboxBuildRich(const QString &name, const QString &remotePath,
                             const QString &third, bool watcher, QWidget *parent)
{
	auto *box = new QMessageBox(nullptr); // @00615d26

	// 三行文案(行拼 FUN_00615ad0 未转写 → 以 "标签: 值" 形式承载,cited)
	const QString row1 = QObject::tr("File name") + QStringLiteral(": ") + name;
	const QString row2 = remotePath; // tr(0xc9d3fe) 标签面 cited
	const QString row3 = QObject::tr("Remote path") + QStringLiteral(": ") + third;

	QString body = QStringLiteral("<pre>%1<br><table>").arg(row1); // 0xc90228
	body += row2 + row3; // 表行拼接(cited:表头/单元格格式面未转写)
	body += QString::fromUtf8(""); // 0xc8a3c9 尾串(cited)

	QCheckBox *check = nullptr;
	int icon = 1;
	int buttons = 0x1c000;
	if (!watcher) { // @00615e4x
		icon = 3;
		buttons = 0x400;
		check = new QCheckBox(QObject::tr("Stop watching this file")); // 0xc90216
	}

	setAttribute(box, static_cast<Qt::WidgetAttribute>(0x37), true); // @00615f27
	box->setWindowFlags(box->windowFlags() | Qt::WindowFlags(0x40000));
	box->setText(body);
	box->setWindowTitle(QObject::tr("Upload File")); // 0xc90241
	box->setIcon(static_cast<QMessageBox::Icon>(icon));
	box->setStandardButtons(
	    static_cast<QDialogButtonBox::StandardButtons>(buttons));
	if (check != nullptr)
		box->setCheckBox(check);
	Q_UNUSED(parent); // 语料 parent 面为 0(new QMessageBox(0))
	return box;
}
