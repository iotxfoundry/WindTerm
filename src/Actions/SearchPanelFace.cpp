// SearchPanelFace.cpp — 搜索面板 apply(批 398)
#include "Actions/SearchPanelFace.h"

#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

// searchpanel_apply(1716B)真身(结构段)
int SearchPanelFace::apply()
{
	if (!m_dirty80)                       // @0055025c(+0x80 == 0 → 跳过)
		return 0;
	m_dirty80 = false;                    // @0055026x(清脏)

	// BreadEdit 刷新(BreadEdit_h54efb6)+ 清装饰(FUN_0054e850)@0055026x — cited

	const QRegularExpression re(m_pattern);        // 面板搜索串(cited)
	const QRegularExpressionMatchIterator it = re.globalMatch(QString()); // @005503xx
	int hits = 0;
	while (it.hasNext()) {                          // @005504xx
		const QRegularExpressionMatch m = it.next();
		const int start = m.capturedStart();        // 区间起点
		const int end = m.capturedEnd();            // 区间终点
		// 区间 → 装饰层:FUN_005514b0 / FUN_00551370 / FUN_00551430 — cited
		Q_UNUSED(start);
		Q_UNUSED(end);
		++hits;
	}
	// 编辑器虚槽 BreadEdit_vt6 应用高亮 @005508xx — cited
	return hits;
}
