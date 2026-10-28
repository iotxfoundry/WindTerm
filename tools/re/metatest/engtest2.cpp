#include "EditorEngine.h"
#include <QApplication>
#include <cstdio>
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	EditorEngine e;
	e.dispatch(2001, 5, QByteArray("hello"));          // SCI_ADDTEXT
	e.dispatch(0x75c4, 4);                             // WT setTabSize
	printf("tabSize=%lld len=%lld\n",
	       e.dispatch(0x75c1).toLongLong(),            // WT tabSize read
	       e.dispatch(2006).toLongLong());             // SCI_GETLENGTH
	QVariant m = e.dispatch(0x757e, QVariantList{"ell", 0, 5, 0, 1}); // indexOf
	printf("indexOf ell -> start=%lld\n", m.toMap()["start"].toLongLong());
	// --- 批 3:清格式/margin 元数据/视口滚动(Phase 3)---
	e.dispatch(0x75b4, 3);                             // 视口 +0x2c 标志
	printf("visLines=%d lineHeight=%d scrollMax=%lld pageStep=%d\n",
	       e.dispatch(0x75ad).toInt(),                 // FUN_00a20438
	       e.dispatch(0x75ae).toInt(),                 // +0xd04 行高
	       e.dispatch(0x75b2).toLongLong(),            // sb+0x30 max
	       e.dispatch(0x75b3).toInt());                // pageStep
	e.dispatch(0x75b5, 1, 0);                          // 纵向滚到行 0
	e.dispatch(0x75b5, 2, 12);                         // 横向 xoffset 12
	e.dispatch(0x7567, 12.5);                          // margin width +0x1a2
	e.dispatch(0x7568, QVariantList{1, -1, "x", 2});   // icons 过滤(-1/"x" 丢弃)
	e.dispatch(2001, 0, QByteArray("\nabc"));          // 附加文本供片段扫描
	printf("snippetOn=%d afterCancel=%d\n",
	       e.dispatch(0x75bc, true).toBool(),          // FUN_00a28efe
	       [&]{ e.dispatch(0x75ba); return e.dispatch(0x75bf).toBool(); }());
	e.dispatch(2001, 0, QByteArray("hello world"));    // 供 0x7558 选区剥离
	e.dispatch(0x7dd);                                 // SCI selectAll
	e.dispatch(0x7558);                                // 清格式 → 默认样式
	// --- 批 4:状态簇链(+0xed8 bit1/bit2/bits3+)---
	e.dispatch(0x7561, true);                          // bit1|bit2
	printf("bit1=%d ", e.dispatch(0x755c).toInt());    // -1
	e.dispatch(0x7564, 0.5);                           // 0.5s → 500ms
	printf("ms=%d ", e.dispatch(0x755d).toInt());      // 500
	e.dispatch(0x7563, 42);                            // +0xdd0 + bit2
	printf("collect5<%d> isSuper=%d\n",
	       e.dispatch(0x7559, QVariantList{1, 2}).toString().size(),
	       e.dispatch(0x7556).toBool());
	return 0;
}
