#pragma once

#include <QDialog>
#include <QString>

// TunnelDialogFace — 隧道(端口转发)配置对话框。
//
// 出处:RTTI "TunnelDialog";QMetaObject 0x011a4ee0
// (**methods=0 / signals=0 / props=0 / superdata=0** —— 无元接口);
// sizeof = **0xc0**(deleting 0x009099c8 的 operator_delete(_,0xc0));
// dtor 0x00909a7c(82B)/deleting 0x009099c8(88B);
// 装配/收尾 0x009097b0(535B);metacast 0x00909768;
// metacall 0x009097aa(5B,纯转发 QDialog::qt_metacall)。
//
// 字段(dtor 实读):**只有 +0xb8 一个 QString** ——
//   dtor 里引用计数归零后走 0x009097b0(535B)的收尾腿,再 QDialog 析构。
//   其余偏移全来自 QDialog/基类链;0xc0 与 +0xb8 自洽。
class TunnelDialogFace : public QDialog {
	Q_OBJECT

public:
	explicit TunnelDialogFace(QWidget *parent = nullptr);
	~TunnelDialogFace() override; // 0x00909a7c

private:
	QString m_fb8; // +0xb8
};
