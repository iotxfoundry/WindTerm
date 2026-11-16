#pragma once

#include <QDialog>

// OneKeyDialogFace — 一键执行配置对话框(QDialog 派生)。
//
// 出处:RTTI "OneKeyDialog";QMetaObject 0x011a1860
// (**methods=0 / signals=0 / props=0**);
// sizeof = **0xd8**(deleting 0x00904a06 的 operator_delete(_,0xd8));
// dtor 0x009049a2(49B)/deleting 0x00904a06(62B);
// metacast 0x0090495a / metacall 0x0090499c(5B,纯转发)。
//
// 字段(dtor 实读):**+0xd0 一个子对象**(走 FUN_00659460 释放),
// 与 0xd8 的尺寸自洽(+0xd0 起 8 字节,收到 0xd8)。
class OneKeyDialogFace : public QDialog {
	Q_OBJECT

public:
	explicit OneKeyDialogFace(QWidget *parent = nullptr);
	~OneKeyDialogFace() override; // 0x009049a2

private:
	char m_fd0[0x08] = {}; // +0xd0 子对象(类型未复原)
};
