#include "Utility/Format.h"

#include <QLocale>

// FUN_006168b6(526B)时长格式化真身(逐句):
//   iVar1 = (int)(ms / 1000);
//   "%1:%2:%3" → arg(iVar1/0xe10, w=0, fill=' ')
//              → arg((iVar1%0xe10)/0x3c, w=2, fill='0')
//              → arg(iVar1%0x3c,       w=2, fill='0')
//   showMillis → append ".%1".arg(ms%1000, w=3, fill='0')
//   iVar1 < 36000 → insert(0, '0')
QString formatDuration(qlonglong ms, bool showMillis)
{
	const int secs = int(ms / 1000); // iVar1 = ms/1000

	QString text = QStringLiteral("%1:%2:%3")             // 0xc9xxxx 邻近串
	                   .arg(secs / 3600)                  // 0xe10
	                   .arg((secs % 3600) / 60, 2, 10, QChar('0')) // 0x3c
	                   .arg(secs % 60, 2, 10, QChar('0'));
	if (showMillis)
		text += QStringLiteral(".%1").arg(ms % 1000, 3, 10, QChar('0'));
	if (secs < 36000) // 10 小时以内补前导 0
		text.insert(0, QChar('0'));
	return text;
}

// FUN_00616636(603B)字节数格式化真身(逐句):
//   unit 初值 "Bytes";three 档单位串实读 @0xc90278 "KB" / @0xc90275 "MB" /
//   @0xca9951 "GB";结果 = QLocale().toString(value) + ' ' + unit。
QString formatByteCount(qlonglong bytes)
{
	QString unit = QStringLiteral("Bytes");
	if (bytes < 1000) {
		return QString::number(bytes);
	}

	double value = double(bytes);
	if (bytes < 1000000) {
		value /= 1000.0;
		unit = QStringLiteral("KB"); // @0xc90278
	} else if (bytes < 1000000000) {
		value /= 1000000.0;
		unit = QStringLiteral("MB"); // @0xc90275
	} else {
		value /= 1000000000.0;
		unit = QStringLiteral("GB"); // @0xca9951
	}

	// 语料此处有 round(value) != value 的两支(QString::compare_helper 比较单位
	// 串后的精度调整),结果与分支均被反编译丢弃 —— cited,不猜。
	return QLocale().toString(value) + QChar(' ') + unit;
}
