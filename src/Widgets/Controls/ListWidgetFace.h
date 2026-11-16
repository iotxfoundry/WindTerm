#pragma once

#include <QListWidget>

// ListWidgetFace — 带自定义键位/滚动条联动的列表件(QListWidget 派生)。
//
// 出处:RTTI "ListWidget";QMetaObject 0x01199bc0
// (rev=8,class="ListWidget",methods=1,**signals=1**,props=0,superdata=0);
// dtor 0x0055e8ce(677B)/deleting 0x0055eb7c(23B,operator_delete(_,**0x58**));
// eventFilter = vt6 0x0055f314(347B);metacast 0x008f774c / metacall 0x008f778e(87B)。
//
// 信号(串表实读):#0 `itemsRemoved()`      发射器 0x008f7708(16B,activate idx 0)
//
// 字段:
//   +0x38 QObject *  被监听的按键来源件(eventFilter 里比对 watched)
//   +0x40 void *     一个"面包屑/匹配器"结构(dtor 实读):
//        [+0x13] 与 [+0xf]/[+0xc]/[+0x9] 各是一个可直接 operator_delete 的块;
//        [+0x8] 处是 QList<QStringMatcher*>(元素对象 0x418 字节,
//        逐个 QStringMatcher::~QStringMatcher + operator_delete(_,0x418))
//        [+0x3] 处另有一个 QListData(同样 dispose)
class ListWidgetFace : public QListWidget {
	Q_OBJECT

public:
	explicit ListWidgetFace(QWidget *parent = nullptr);
	~ListWidgetFace() override; // 0055e8ce

signals:
	void itemsRemoved(); // #0 0x008f7708

protected:
	bool eventFilter(QObject *watched, QEvent *event) override; // vt6 0x0055f314

private:
	QObject *m_keySource38 = nullptr; // +0x38
	void *m_crumb40 = nullptr;        // +0x40
};
