// FileDialogFaces.cpp — 两个文件选择对话框(见头注对照表)。

#include "Widgets/Dialogs/FileDialogFaces.h"

// 出处:两者 metacall 均 5 字节纯转发;ctor 均内联在调用点。

// dtor 0x008fa5e6(86B)真身:唯一字段 +0x30 QString 减引用 → QFileDialog 析构;
// deleting 0x008fa4d2(92B)真身。
FileDialogFace::FileDialogFace(QWidget *parent) : QFileDialog(parent) { }
FileDialogFace::~FileDialogFace() = default;

// dtor 0x00904662(86B)真身:**与 FileDialog 的 dtor 逐字节同构**;
// deleting 0x00904718(92B)真身。
ModemFileDialogFace::ModemFileDialogFace(QWidget *parent) : QFileDialog(parent) { }
ModemFileDialogFace::~ModemFileDialogFace() = default;
