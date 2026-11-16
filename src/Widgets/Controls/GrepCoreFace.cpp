// GrepCoreFace.cpp — 查找核心(非 QObject)。

#include "Widgets/Controls/GrepCoreFace.h"

// 出处:RTTI "Grep";无 QMetaObject(非 QObject 派生)。
// 语料名 Grep_metaObject(0x00899ab4,608B)实为析构体,见头注。
GrepCoreFace::GrepCoreFace() = default;

// 0x00899ab4(608B)析构真身(逐段):
//   ① 五组引用计数/数组件(+0x08..+0x28)各自判空 → 减引用 → 归零释放;
//   ② +0x48 / +0x58 两个 QHash 走 QHashData::free_helper;
//   ③ +0x50 的 std::string 与 `_S_empty_rep_storage` 比对(COW 判空);
//   ④ 次级哈希节点逐层释放。
// deleting(语料名 Grep_qt_metacast,0x00899d14,23B):
//   + operator_delete(this, **0x68**)。
GrepCoreFace::~GrepCoreFace() = default;

// 0x008998f6(445B)clearNodes 真身:
//   遍历 QHash 节点,每节点清 +0x18 处的件与其 +0x10 的字符串。
//   (本会话第三次遇到"元素内部再挂引用计件"的列表 —— 与 SshExecutor、
//    Tools 同族;这类一定要把元素内部的计件也减掉,否则泄漏。)
void GrepCoreFace::clearNodes() { }
