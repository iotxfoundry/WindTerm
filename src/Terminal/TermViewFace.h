#ifndef TERMVIEWFACE_H
#define TERMVIEWFACE_H

#pragma once

#include <QByteArray>
#include <QVector>

// 终端视图写回通道。语料:Screen::writeBackToView(FUN_007e66c6 尾)
// 经视图对象 vtable+0x70 推数据(+0x78 为第二通道)。本重建面以
// 抽象基类表达该槽:视图对象实现 viewWrite;布局偏移本身属原生
// 视图层,不在重建面内。
class TermViewFace
{
public:
	virtual ~TermViewFace() = default;
	virtual void viewWrite(const QByteArray &data) = 0;
	virtual void viewNotify(void *sender, long long arg) { Q_UNUSED(sender); Q_UNUSED(arg); }
};

#endif // TERMVIEWFACE_H
