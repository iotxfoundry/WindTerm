#ifndef EDITORCONTEXT_H
#define EDITORCONTEXT_H

#pragma once

// 编辑器上下文状态模型(重建侧命名字段;语料为 0x00a1-00a3 区 handler
// 写入的多 KB 对象,偏移见注释)。Phase 3 按命令逐字段补齐;软复位
// (session_view_soft_reset)与视图刷新(vtable+0xa0)腿在 Phase-4
// 视图装配时接线。

#include <QString>
#include <QVariant>
#include <QVariantList>
#include "RunNode.h"

class EditorContext
{
public:
	// --- hex 查看器(0x759a/0x759e;FUN_00a28e7c/00a30c2e)---
	int hexBase = 10;            // +0x1120(合法域 2..0x24)
	QString hexBaseStr = "255";  // +0x1124(FUN_007c4392 number(0xff))
	bool hexMode = false;        // +0x1128

	// --- 边栏(0x7597;FUN_00a1fd8c)---
	bool marginTrackChange = false;  // +0x113a

	// --- margin 链(0x7591/7594/7595;FUN_00a4bc60)---
	QVariantList margins;            // margin 定义对象列(QList 语义)
	bool marginFlag1ab = false;      // +0x1ab
	bool marginFlag1ac = false;      // +0x1ac
	bool marginFlag1ad = false;      // +0x1ad
	bool marginFlag1ae = false;      // +0x1ae
	void removeMargin(const QString &name)
	{
		// FUN_00a4bc60(387B):按名移除,后续元素前移
		// (语料的逐字段搬移即 QList 压缩语义)
		for (int i = 0; i < margins.size(); ++i) {
			const QVariantMap m = margins.at(i).toMap();
			if (m.value("name").toString() == name) {
				margins.removeAt(i);
				return;
			}
		}
	}
	void clearMarginFlags()
	{
		// 0x7595(inline):四标志清零(+0x1ab..+0x1ae)
		marginFlag1ab = marginFlag1ac = marginFlag1ad = marginFlag1ae = false;
	}

	// --- pair 高亮/片段(0x7583/75b4/75b5/75ba)---
	int pairHighlightUnmatched = 0;  // FUN_00a10c68 置 2(枚举)
	bool snippetMode = false;        // FUN_00926ebc(+0x1098)状态位

	// --- 视口/滚动(0x75b2-75b5;FUN_00a169cc/00a167ac 对)---
	int viewportFlag2c = 0;          // 视口对象 +0x2c 字节(0x75b4 写)

	// --- margin 元数据(0x7567/7568)---
	double marginWidth = 0;          // +0x1a2(double)
	QList<int> marginIcons;          // +0x1b4(QList<int>;0x7568 重建)

	// --- 样式剥离(0x7558;FUN_00a26756 尾)---
	bool bufferStyleFlag = false;    // +0x1098 buffer 样式收集标志
	quint64 pairCacheFc0 = 0;        // +0xfc0(剥离时清零)
	quint64 pairCacheFc8 = 0;        // +0xfc8

	// --- buffer/状态簇(0x7556-0x7564;+0x1098 buffer / +0xed8 状态)---
	bool isSuperBuffer = false;      // +0xf8 动态类型 cast(00927ec8)
	QString bufferString;            // 0x755a(vt+0x58 虚调用 — cited)
	bool bufferModeB = false;        // 0x755b(+0xf8 对象置换 0x48B — cited)
	quint32 stateEd8 = 0;            // bit1=0x755c/7561 布尔 bit2=脏 bits3+=ms
	quint32 valDd0 = 0;              // +0xdd0(0x7563 set)
	int val1ba = 0;                  // 0x755f 查询
	double val1bb = 0;               // 0x7560 查询(double)

	// --- 尾块状态(0x75d0-0x75ff;disp 24100-24518)---
	bool flag1bc = false;            // 0x75d7 查询 / 0x75db 写(+soft_reset)
	int fontScale = 0;               // doc+0x14(00a218dc);0x75d9 夹 [0,10000]
	bool flag210 = false;            // 0x75e0(+00a2cea8 刷新 cited)
	bool flag1083 = false;           // 0x75e2 查询
	bool flag1082 = false;           // 0x75f1(+009502de 传播 cited+soft_reset)
	quint32 remoteCaretFlag = 0;     // +0xedc(0x75e6 "line.caret.remote" 特例)
	quint64 bufField158 = 0;         // buffer+0x158(0x75f3 查询)
	quint64 bufField160 = 0;         // buffer+0x160(0x75f2 查询/0x75f4 写,<0→-1)
	quint32 modeEnum2c0 = 0;         // 0x75f5(00925ae4;(v&~4)!=3 时缓存 -1)
	long long bufObjField = -1;      // 0x75f9 查询(00927170:obj+0x20)/0x75ff 写
	QByteArray timestampFormat;      // 0x75fc(00927216:indexOf('z') 探测)
	bool timestampHasZ = false;
	QByteArray timestampLongFormat;  // 0x75fe

	// --- runnode 面(+0x1068 块光标锚;写入=块编辑路径 00a2a2xx)---
	RunNode blockNode;               // 当前块样式节点(0096bbc6/00a2a2xx 写)
	quint32 bufField148 = 0;         // buffer+0x148(0x75ec hex 模式选)

	// --- 语义动作 ---
	void setHexBase(int base)
	{
		// FUN_00a28e7c:值域 2..0x24;变更时刷新 baseStr 并在
		// hexMode 开启时触发重算(FUN_00a28c70)+ soft_reset — cited
		if (hexBase == base || (unsigned)(base - 2) >= 0x23)
			return;
		hexBase = base;
		hexBaseStr = "255";   // 语料:number(0xff) 固定值 — QUIRKS
		// if (hexMode) { FUN_00a28c70; session_view_soft_reset; } — cited
	}
	void setHexMode(bool on)
	{
		// FUN_00a30c2e(247B):置位 + 模式相关重配置尾 — cited
		hexMode = on;
	}
	void setMarginTrackChange(bool on)
	{
		// FUN_00a1fd8c:变更时 vtable+0xa0 视图刷新 — cited
		marginTrackChange = on;
	}
};

#endif // EDITORCONTEXT_H
