#pragma once

#include <QString>

class QWidget;

// FileDialogFace — 语料文件对话框封装族(批 322)。
// save_file_dialog_exec(1412B,0023.c:38885):
//   @0076fb16 静态目录缓存 DAT_011c1dc8(空 BA 初值 + atexit 释放);
//   @0076fb47 QFileInfo(path) → fileName()@0076fb69 → exists()@0076fb71;
//   存在 → absolutePath()@0076ff69 作为起始目录;不存在 → 缓存目录;
//   随后 QFileDialog 面(过滤器/覆盖确认/重试)— cited(余段未逐句核对)。
QString saveFileDialogExec(QWidget *parent, const QString &path,
                           const QString &filter);
