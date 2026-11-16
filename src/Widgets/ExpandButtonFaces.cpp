// ExpandButtonFaces.cpp — 展开钮两类(批 491)
#include "ExpandButtonFaces.h"

// s_ExpandButton_5984be(1021B)ctor
ExpandButtonFace::ExpandButtonFace(QWidget *parent)
	: QWidget(parent)
{
	// +0x30(三角)/ +0x38(标题)/ +0x40(容器)三件装配 — cited
}

// s_ExpandButton_5ab32a(584B)ctor
ExpandToggleFace::ExpandToggleFace(QWidget *parent)
	: QWidget(parent)
{
	// 无自有字段:切换行为 + 信号面 — cited
}
