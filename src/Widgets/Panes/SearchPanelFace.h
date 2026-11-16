#pragma once

#include <QObject>
#include <QString>

class QTextEdit;
class QRegularExpression;

// SearchPanelFace — 语料搜索面板的"应用搜索"腿(批 398)。
//
// searchpanel_apply(1716B,0017.c:...) 实测(结构):
//   @0055025c **+0x80 == 0 → 直接跳到收尾**;否则 +0x80 = 0(清脏标志);
//   @0055026x BreadEdit 刷新(BreadEdit_h54efb6);空 QIcon + 长串(0xab)预清;
//   @005502c1 FUN_0054e850(this, 0, 0, …)(清装饰/选择面,cited);
//   @005503xx 正则:**QRegularExpression::globalMatch** 定位全部命中;
//   @005504xx 逐命中(QRegularExpressionMatchIterator hasNext/next):
//     start = capturedStart() / end = capturedEnd() → 组装区间;
//     区间经 FUN_005514b0(6 处)/FUN_00551370/FUN_00551430 落到装饰层(cited);
//   @005508xx 编辑器虚槽 BreadEdit_vt6 应用(高亮刷新)。
//   ⇒ 面板自身只存 **+0x80 = 待应用标志**;搜索文本/正则来自面板字段(cited)。
class SearchPanelFace : public QObject {
	Q_OBJECT
public:
	// 应用当前搜索到编辑器(返回命中数;0 = 无命中)
	int apply();

	bool dirty80() const { return m_dirty80; }      // +0x80
	void setDirty(bool on) { m_dirty80 = on; }

protected:
	bool m_dirty80 = false;   // +0x80(待应用标志)
	QString m_pattern;        // 搜索串(面板字段,cited)
};
