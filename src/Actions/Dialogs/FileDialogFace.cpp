// FileDialogFace.cpp — 保存文件对话框封装(批 322)
#include "Actions/Dialogs/FileDialogFace.h"

#include <QDir>
#include <QFileDialog>
#include <QFileInfo>

// save_file_dialog_exec(1412B,0023.c:38885)真身(结构面):
//   @0076fb16 静态目录缓存(DAT_011c1dc8,空 BA 初值);
//   @0076fb47 QFileInfo(path);@0076fb69 fileName();@0076fb71 exists();
//   存在 → @0076ff69 absolutePath() 作起始目录;不存在 → 缓存目录;
//   QFileDialog 面(过滤器/覆盖确认/重试循环)cited。
QString saveFileDialogExec(QWidget *parent, const QString &path,
                           const QString &filter)
{
	static QByteArray s_lastDir; // DAT_011c1dc8(共享串缓存)
	const QFileInfo fi(path);    // @0076fb47
	const QString name = fi.fileName(); // @0076fb69
	QString dir;
	if (fi.exists()) // @0076fb71
		dir = fi.absolutePath(); // @0076ff69
	else
		dir = QString::fromUtf8(s_lastDir);
	if (dir.isEmpty())
		dir = QDir::homePath();
	// QFileDialog::getSaveFileName(parent, 标题, dir + '/' + name, filter)
	//   + 覆盖确认/循环重试 — cited(1412B 余段)。
	QString selected = QFileDialog::getSaveFileName(
	    parent, QString(), dir + QLatin1Char('/') + name, filter);
	if (!selected.isEmpty()) {
		s_lastDir = QFileInfo(selected).absolutePath().toUtf8(); // 缓存写面(cited)
	}
	return selected;
}
