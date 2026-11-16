// OutlinePaneFace.cpp — 大纲/符号面板。

#include "Widgets/Panes/OutlinePaneFace.h"

// 下列被调件全部来自 OutlinePane 自己的实现区(0x0074xxxx),尚未逐个转写;
// 按 §5 锚入口,槽体只保留"调谁 + 出参形状",语义待该区开批。
void outline_pane_connect();                        // case 0
void outline_collectVisibleText(QString *out, QWidget *self); // case 3

OutlinePaneFace::OutlinePaneFace(QWidget *parent)
    : KitPaneFace(parent)
{
}

// 0x0090b020(244B)dtor 真身:
//   vptr = &OutlinePane_vtable;*(this+0x10) = &PTR_FUN_011a60f0;
//   +0x70 intrusive 计数件:intrusive_ptr 释放语义两跳
//        (+1 计数减一 → 归零且 vtable+0x10 非 FUN_00575d12 时调用它
//         → +0xc 弱计数减一 → 归零时走 std::_Sp_counted_base::_M_destroy
//           或 vtable+0x18 释放器)
//   +0x50 引用计数件:计数减一,归零 operator_delete
//   vptr → &PTR_FUN_011ab6b8(基类 vtable);*(this+0x10) = &DAT_011ab8b0
//   → QWidget::~QWidget
// deleting 0x0090b30c(253B):同上 + operator_delete(_, size)。
OutlinePaneFace::~OutlinePaneFace() = default;

// 0x0090ae9a(279B)槽分发真身:switch(index) 0..9,逐条见头文件表。
// 其中 case 2/3/4 共用同一段出参搬运(语料 joined_r0x0090af7a):
//   取 *args 指向的 QString,与本地结果交换(local_10 = old),再析构 old。
void OutlinePaneFace::updateKitView() { outline_pane_connect(); }         // case 0
void OutlinePaneFace::tryShowOutlineTree() { /* FUN_0074644a() cited */ } // case 1
void OutlinePaneFace::copy() { /* FUN_00746b00(&s,this) cited */ }        // case 2
void OutlinePaneFace::copyOutput() { /* outline_collectVisibleText cited */ } // case 3
void OutlinePaneFace::copyToTerminal() { /* FUN_00746b46(&s,this) cited */ } // case 4
void OutlinePaneFace::execute() { /* FUN_00746bfe() cited */ }            // case 5
void OutlinePaneFace::executeRepeatedly() { /* FUN_00746ce4() cited */ }  // case 6
void OutlinePaneFace::gotoSymbol() { /* FUN_00748510() cited */ }         // case 7
bool OutlinePaneFace::hasSelection() const { return false; }              // case 8(cited)
void OutlinePaneFace::preview() { /* FUN_007478c6() cited */ }            // case 9

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject → &staticMetaObject(0x011a6140),superdata = 0x011ab900(KitPane)
// qt_metacast 0x0090ae58(strcmp "OutlinePane")
// qt_metacall 0x0090afc4(91B):10 条槽全部转发到上面的 switch
