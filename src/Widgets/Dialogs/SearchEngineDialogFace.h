#pragma once

#include <QDialog>

// SearchEngineDialogFace — 搜索引擎配置对话框。
//
// 出处:RTTI "SearchEngineDialog";QMetaObject 0x011a4000
// (**methods=0 / signals=0 / props=0 / superdata=0**);
// sizeof = **0x58**(deleting 0x00905d9a 的 operator_delete(_,0x58));
// dtor 0x00905d5c(29B)/deleting 0x00905d9a(47B)
//   —— 只有 vptr 复位 + QDialog 析构 ⇒ **零自有字段**(0x58 全来自基类链);
// metacast 0x00905d14 / metacall 0x00905d56(5B,纯转发)。
class SearchEngineDialogFace : public QDialog {
	Q_OBJECT

public:
	explicit SearchEngineDialogFace(QWidget *parent = nullptr);
	~SearchEngineDialogFace() override; // 0x00905d5c
};
