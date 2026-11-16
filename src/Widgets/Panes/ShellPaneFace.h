#pragma once

#include <QMap>
#include <QString>

#include "Widgets/Panes/KitPaneFace.h"

// ShellPaneFace — Shell/命令器面板(KitPane 直接派生,2 条槽 / 0 信号)。
//
// 出处:RTTI "ShellPane";QMetaObject 0x011a6680
// (rev=8,class="ShellPane",methods=2,**signals=0**,props=0,
//  superdata=0x011ab900 = **KitPane**);
// sizeof = **0x60**(deleting 0x0090bb30 的 operator_delete(_,0x60));
// dtor 0x0090bcd2(130B)/deleting 0x0090bb30(143B);
// 槽分发 0x0090ba9a(56B);metacast 0x0090ba58 / metacall 0x0090bad2(93B)。
//
// 两条槽(串表实读):
//   #0 addCommander(?)   → s_session_color_7503a0(this, 实参) 出参 int(颜色)
//   #1 commanderCount()  → FUN_0074ffde() 出参 int
//
// 字段(dtor 实读):**+0x58 QMap<?>** —— 唯一自有字段,
//   dtor 里引用计数归零后 QMapDataBase::freeTree(根节点)+ freeData。
//   (其余偏移全来自基类链;deleting 的 0x60 与 +0x58 字段位置自洽。)
class ShellPaneFace : public KitPaneFace {
	Q_OBJECT

public:
	explicit ShellPaneFace(QWidget *parent = nullptr);
	~ShellPaneFace() override; // 0x0090bcd2

public slots:
	int addCommander(const QString &name); // #0
	int commanderCount();                  // #1

private:
	QMap<QString, void *> m_commanders58; // +0x58
};
