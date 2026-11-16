// OutputPaneFace.cpp — 输出面板。

#include "Widgets/Panes/OutputPaneFace.h"

OutputPaneFace::OutputPaneFace(QWidget *parent)
    : KitPaneFace(parent)
{
}

// 0x00748a66(29B)dtor 真身:
//   vptr = &PTR_FUN_011ab6b8(KitPane vtable);*(this+0x10) = &DAT_011ab8b0;
//   QWidget::~QWidget —— **本类零字段**,所以 dtor 里没有任何字段释放。
// deleting 0x00748a8a(23B):同上 + operator_delete(this, 0x48)。
OutputPaneFace::~OutputPaneFace() = default;

// 槽体(0x0074xxxx / 0x0090xxxx 区,尚未逐条转写;按 dispatch 逐条锚入口):
void OutputPaneFace::clearText(const QVariant &v) { Q_UNUSED(v); }  // 0x00749422
void OutputPaneFace::clearText() { clearText(QVariant()); }         // 默认实参腿
QString OutputPaneFace::currentTool() { return QString(); }         // 0x00749878
void OutputPaneFace::locateMessage(const QVariant &v) { Q_UNUSED(v); } // 0x0074a1ea
void OutputPaneFace::locateMessage() { locateMessage(QVariant()); }
void OutputPaneFace::nextMessage() { }                              // cited
void OutputPaneFace::showTool(const QVariant &v) { Q_UNUSED(v); }    // cited
QVariant OutputPaneFace::tools() { return QVariant(); }             // cited
QString OutputPaneFace::toolText(const QVariant &v) { Q_UNUSED(v); return QString(); } // cited

// metasurface:metaObject 0x00909df0 → &PTR_staticMetaObject_011a56c0;
// qt_metacast 0x00909fae(strcmp "OutputPane" → KitPane::qt_metacast);
// qt_metacall 0x00909ff0(93B):9 条记录转发到 0x00909e08;
//   语料门写作 `param_2 != 0 || 8 < param_3`,即只处理 op=0 且 index ≤ 8,
//   超出直接 return(与其它类的 index-9 回退写法不同,原样保留)。
