#pragma once

#include <QImage>

// RGBAImageFace — RGBA 位图(**非 QObject**,纯 C++ 类)。
//
// 出处:RTTI "RGBAImage";sizeof = **0x30**
// (语料名 `RGBAImage_qt_metacast` 0x0095244e 的 23B 函数实为 deleting 析构:
//  `operator_delete(param_1, 0x30)`);
// 语料名 `RGBAImage_metaObject`(0x00952430,29B)实为**析构体**
//   —— 首句写 `&RGBAImage_vtable`,后面释放一个字段。
// **本类无 QMetaObject**(非 QObject 派生)。
//
// 字段(dtor 实读):**+0x18 一个裸缓冲区**(`operator_delete(param_1[3])`)。
//   像素数据本体,无子结构 —— 说明它是"宽/高 + 一个 malloc 块"的平面格式。
class RGBAImageFace {
public:
	RGBAImageFace();
	~RGBAImageFace(); // 0x00952430

private:
	void *m_pixels18 = nullptr; // +0x18
};
