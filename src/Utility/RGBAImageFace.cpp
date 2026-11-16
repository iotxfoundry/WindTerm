// RGBAImageFace.cpp — RGBA 位图(非 QObject)。

#include "Utility/RGBAImageFace.h"

// 出处:RTTI "RGBAImage";无 QMetaObject(非 QObject 派生)。
// 语料名 RGBAImage_metaObject(0x00952430,29B)实为析构体,见头注。
RGBAImageFace::RGBAImageFace() = default;

// 0x00952430(29B)析构真身:vptr 复位 → +0x18 像素块 operator_delete → 返回。
// deleting(语料名 RGBAImage_qt_metacast,0x0095244e,23B):
//   + operator_delete(this, **0x30**)。
RGBAImageFace::~RGBAImageFace() = default;
