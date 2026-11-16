#pragma once

#include <QWidget>

// CategoryPageFace — 分类页(QWidget 派生,**零字段**)。
//
// 出处:RTTI "CategoryPage";dtor 0x006ec240(29B)/deleting 0x006ec27e(47B)
//   —— dtor 只有 vptr 复位 + QWidget 析构两行 ⇒ 零自有字段。
//
// ⚠ **本类是"触发器设置页"族里唯一还没建模的一个**。
//   `TriggerPageFace.h` 里已落 6 个具体页(ConnectionTriggerPage /
//   CustomLinkTriggerPage / CustomMenuTriggerPage / PlaySoundTriggerPage /
//   ShowTooltipTriggerPage / RunCommandTriggerPage / SendTextTriggerPage),
//   本类不在其中 —— 它属于**分类选择页**(Category*),不是触发器页。
//   两族名字相近、职责不同,建之前务必先 grep:
//     grep -rn "class CategoryPageFace" src/
//
// 建立前的查重记录(必留):
//   `coverage.py --what CategoryPage` → 无既有实现;
//   `grep -rl "class CategoryPageFace" src/` → 空。
class CategoryPageFace : public QWidget {
	Q_OBJECT
public:
	explicit CategoryPageFace(QWidget *parent = nullptr);
	~CategoryPageFace() override; // 0x006ec240
};
