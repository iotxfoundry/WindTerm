#pragma once

#include <QString>

#include "Widgets/Bars/ButtonBarPanelFace.h"

// PlainTextEditPanelFace — 纯文本编辑面板(ButtonBarPanel 派生,加 2 条信号)。
//
// 出处:RTTI "PlainTextEditPanel";QMetaObject 0x01195800
// (rev=8,class="PlainTextEditPanel",methods=2,**signals=2**,
//  superdata=0x01193440 = **ButtonBarPanel**);
// sizeof = **0x70**(deleting 0x006f8b16 的 operator_delete(_,0x70));
// eventFilter = vt6 0x00533c18(130B)。
//
// **本批纠正一处语料名错位(重要)**:
//   语料把 **PlainTextEditPanel 的四个成员** 挂在了 `TriggerActionEditPanel`
//   名下 —— dtor 0x006f82c6(88B)、metacall 0x008f10c2(93B)、
//   分发 0x008f105a(104B)、eventFilter 0x00533c18(130B)。
//   判据三条:
//     ① 0x006f82c6 的 vptr 写 `&PTR_..._011955f8`,而其 vt0 指向的
//        metaObject 返回的表类名是 **"PlainTextEditPanel"**;
//     ② 它末尾把 vptr 落回 **ButtonBarPanel_vtable**,与 superdata 一致;
//     ③ 真正的 `TriggerActionEditPanel_dtor`(0x006f8a92,29B)只有
//        vptr 复位 + QFrame 析构 + operator_delete(_, **0x70**) ——
//        名字对、内容也对,是另一个类。
//
// 两条信号(串表实读):
//   #0 namedCaptureGroupsChanged(...)   —— 命名捕获组变化(正则)
//   #1 regexValidated(...)              —— 正则校验结果
//
// eventFilter 语义(vt6 实读):
//   门:watched == +0x38 且 KeyPress(6) 且 key == **0x1000007**
//   然后两步:0x005339d6(this, 2) 通过 → 0x005339ea(this, 2, event) 返回非 0
//   才 0x008ef7fc(this) + event->accept();否则落 QObject::eventFilter。
//   (这是"Ctrl+某键 → 交给第 2 号处理器"的转发,键码是 WindTerm 自有枚举)
class PlainTextEditPanelFace : public ButtonBarPanelFace {
	Q_OBJECT

public:
	explicit PlainTextEditPanelFace(QWidget *parent = nullptr);
	~PlainTextEditPanelFace() override; // 0x006f82c6

signals:
	void namedCaptureGroupsChanged(const QString &groups); // #0
	void regexValidated(bool valid);                       // #1

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 0x00533c18

private:
	void *m_shared50 = nullptr; // +0x50
	QString m_f58;              // +0x58
	QString m_f60;              // +0x60
};
