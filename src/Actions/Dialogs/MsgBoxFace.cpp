// MsgBoxFace.cpp — 富文本消息框族(批 317)
#include "Actions/Dialogs/MsgBoxFace.h"

#include <QCheckBox>
#include <QFileInfo>
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

	// 三行(行拼 = FUN_00615ad0,批 324 真身)
	const QString row1 = msgBoxRow(QObject::tr("File name"), name);   // 0xc90200
	const QString row2 = msgBoxRow(QString(), remotePath);            // tr(0xc9d3fe) cited
	const QString row3 = msgBoxRow(QObject::tr("Remote path"), third); // 0xc9020a

	QString body = QStringLiteral("<pre>%1<br><table>").arg(row1); // 0xc90228
	body += row2 + row3; // 表行
	body += QString::fromUtf8(""); // 0xc8a3c9 尾串(cited)

	QCheckBox *check = nullptr;
	int icon = 1;
	int buttons = 0x1c000;
	if (!watcher) { // @00615e4x
		icon = 3;
		buttons = 0x400;
		check = new QCheckBox(QObject::tr("Stop watching this file")); // 0xc90216
	}

	box->setAttribute(static_cast<Qt::WidgetAttribute>(0x37), true); // @00615f27
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

// file_showErrorBox(820B,0017.c:51861)真身:
//   @00579ba0 +0x88/+0x90 前置门(vcall+0x70 != 默认且为真);
//   @00579c1c 目标路径 endsWith('/') → 去掉末字符;
//   @00579c6a 逐项(cs=1 indexOf)判定:isDir 且 != 目标 且目标含该项 →
//     QListData::remove(子目录剔除);
//   @00579cd7 表非空 → new QMessageBox(parent)(0x30)→
//     setAttribute(0x37,1)@00579ce9 → setWindowTitle(tr("Copy")
//     0xcba936)@00579d1a → setText(tr(0xc8a740).arg(路径))@00579d57 →
//     setIcon(2 = Warning)@00579d7f → setDetailedText(join '
')@00579d9f →
//     vt+0x1a0(this)(cited:show/exec 面)。
QMessageBox *fileShowErrorBox(QWidget *parent, const QStringList &paths,
                              const QString &path)
{
	QString target = path;
	if (target.endsWith(QLatin1Char('/'))) // @00579c1c
		target.chop(1);
	QStringList keep;
	for (const QString &item : paths) { // @00579c6a 子目录剔除
		if (QFileInfo(item).isDir() && item != target
		    && target.contains(item, Qt::CaseInsensitive))
			continue;
		keep.append(item);
	}
	if (keep.isEmpty())
		return nullptr;
	auto *box = new QMessageBox(parent); // @00579cd7(0x30)
	box->setAttribute(Qt::WA_DeleteOnClose, true); // 0x37 @00579ce9
	box->setWindowTitle(QObject::tr("Copy"));      // 0xcba936 @00579d1a
	box->setText(QObject::tr("The destination folder is a subfolder of the "
	                         "source folder:\n%1").arg(target)); // 0xc8a740
	box->setIcon(QMessageBox::Warning); // 2 @00579d7f
	box->setDetailedText(keep.join(QLatin1Char('\n'))); // @00579d9f
	// vt+0x1a0(this)@00579dba — cited(展示面)
	return box;
}

// FUN_00615ad0(281B)真身:
//   @00615ad0 模板 = "<tr><td>%1:</td><td><b>%2</b></td></tr>"(0xc901f8 邻);
//   @00615b0d QString::replace(值, 0xca2286 "&<" → 0xc901fb "&lt;")(语义
//     cited:两串直读,Ghidra 实参序未定)→ argToQString(模板, 2 参) →
//   append 到输出。
QString msgBoxRow(const QString &label, const QString &value)
{
	QString v = value;
	v.replace(QStringLiteral("&<"), QStringLiteral("&lt;")); // cited(实参序待核)
	return QStringLiteral("<tr><td>%1:</td><td><b>%2</b></td></tr>").arg(label, v);
}
