#ifndef UTILITY_FORMAT_H
#define UTILITY_FORMAT_H

#pragma once

// 数值/时长的显示格式化(文件传输进度条与统计共用)。
// 出处:反编译语料 FUN_006168b6(526B)/ FUN_00616636(603B),均为
// QString sret 的自由函数(无 this),故落为 Utility 自由函数。

#include <QString>

// FUN_006168b6(526B,0061.c)真身:
//   "%1:%2:%3".arg(ms/1000/3600).arg(..%3600/60, 2, 10, '0').arg(..%60, 2, 10, '0');
//   showMillis → 追加 ".%1".arg(ms%1000, 3, 10, '0');
//   不足 10 小时 → 前插 '0'(即 "H:MM:SS" 定宽)。
QString formatDuration(qlonglong ms, bool showMillis = false);

// FUN_00616636(603B,0061.c)真身:
//   < 1000        → QString::number(bytes),单位 "Bytes";
//   < 1000000     → QLocale().toString(bytes/1000.0)   + " KB";
//   < 1000000000  → QLocale().toString(bytes/1000000.0)  + " MB";
//   否则          → QLocale().toString(bytes/1e9)      + " GB";
//   末尾统一 " " + 单位。
QString formatByteCount(qlonglong bytes);

#endif // UTILITY_FORMAT_H
