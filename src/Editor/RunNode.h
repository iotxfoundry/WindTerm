#ifndef RUNNODE_H
#define RUNNODE_H

#pragma once

// 风格游程值类型(逆向锚:runstyles_runnode_init @0096bac0,66B;
// FUN_0096be24/0096bd82 成对;0096bbb4/0096beb4/0096bed4 判定)。
// 布局(字节偏移):
//   +0x00 u32  style<<1 | flag(bit0)      样式域夹 [0,0x3fffffff]
//   +0x08 s64  pos                        -1 = 无效节点
//   +0x10 f64  width                      -1.0(&DAT_bff0000000000000)=未设

#include <QtGlobal>

struct RunNode
{
	quint32 styleWord = 0;
	qint64 pos = -1;
	double width = -1.0;

	bool isValid() const { return pos >= 0; }          // FUN_0096bbb4:~pos>>63
	int style() const { return (int)(styleWord >> 1); }
	bool flag() const { return (styleWord & 1u) != 0; }

	static RunNode make(qint64 p, int style, bool flag)
	{
		RunNode n;
		if (style < 0)
			style = 0;
		if (style > 0x3fffffff)
			style = 0x3fffffff;
		n.styleWord = ((quint32)style << 1) | (flag ? 1u : 0u);
		n.pos = p;
		n.width = -1.0;
		return n;
	}
};

// 位置区间对(FUN_0096bd82 init / FUN_0096be24 merge:out={B,A} 逆序)
struct RunPair
{
	quint32 flags = 0;
	RunNode first;
	RunNode second;

	bool complete() const                       // FUN_0096beb4
	{
		return first.isValid() && second.isValid();
	}
	qint64 length() const                       // FUN_0096bed4:|a-b|
	{
		const qint64 d = first.pos - second.pos;
		return d < 0 ? -d : d;
	}
};

#endif // RUNNODE_H
