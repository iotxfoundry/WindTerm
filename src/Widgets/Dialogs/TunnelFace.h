#pragma once

#include <QByteArray>
#include <QList>

// TunnelFace — 语料隧道配置行模型(批 325)。
// TunnelDialog_h9097b0(535B,0029.c:27447) **不是**对话框构建,而是
//   隧道行表析构:按 0x48 字节步长遍历行,逐行释放五个 QByteArray 成员
//   (+0x00/+0x08/+0x10/+0x20/+0x38,析构序实证)。
// 行 = 隧道配置项(字段语义未逐个取证 → 仅按偏移承载,cited)。
struct TunnelRow {
	QByteArray f00; // +0x00
	QByteArray f08; // +0x08
	QByteArray f10; // +0x10
	QByteArray f20; // +0x20
	QByteArray f38; // +0x38
	// 行总长 0x48(其余字节为标量面,cited)
};

using TunnelRowList = QList<TunnelRow>;
