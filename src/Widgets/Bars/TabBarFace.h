#pragma once

#include <QList>
#include <QSize>
#include <QString>
#include <QTabBar>

// TabBarFace — 终端标签栏(QTabBar 派生,带高亮框与"仅选中页显示关闭按钮")。
//
// 出处:RTTI "TabBar";QMetaObject 0x01197f40
// (rev=8,class="TabBar",methods=1,**signals=1**,**props=3**,superdata=0);
// sizeof = **0x80**(deleting 0x008f6a66 的 operator_delete(_,0x80));
// dtor 0x008f68fc(113B);event = vt5 0x005a8aa0(141B);
// 属性桥 0x008f6618(153B);metacall 0x008f66f4(166B);metacast 0x008f66b2。
//
// 信号(串表实读):#0 `tabLayoutChanged()`  发射器 FUN_008f6608
//
// 三条属性(串表真名 + 桥的读写偏移实读):
//   #0 highlightTopLeft                QSize → 字段 +0x44
//   #1 highlightBottomRight            QSize → 字段 +0x4c
//   #2 showSelectedTabCloseButtonOnly  bool  → 字段 +0x30
//   (写 #1 时语料是 `*(u32*)(+0x4c)=v[1]; *(u32*)(+0x50)=v[0]`
//    —— 两个分量按**反序**落库,已原样保留)
//
// 其余字段(dtor 实读):
//   +0x38 QString
//   +0x60 QList<16 字节元素>(清理腿 0x008f67a0 逐个 operator_delete(_,0x10))
//   +0x68 QSharedDataPointer(qt_shared_data_unref)
//   +0x70 QList<8 字节元素>(清理腿 0x008f67fc,元素 +0x10 处还有一个
//        8 字节引用计数件,逐个释放后再 QListData::dispose)
class TabBarFace : public QTabBar {
	Q_OBJECT

	Q_PROPERTY(QSize highlightTopLeft MEMBER m_topLeft44)
	Q_PROPERTY(QSize highlightBottomRight MEMBER m_bottomRight4c)
	Q_PROPERTY(bool showSelectedTabCloseButtonOnly MEMBER m_closeOnly30)

public:
	explicit TabBarFace(QWidget *parent = nullptr);
	~TabBarFace() override; // 0x008f68fc

signals:
	void tabLayoutChanged(); // #0

protected:
	bool event(QEvent *event) override; // vt5 0x005a8aa0

	// 属性面:op=1 读 / op=2 写,index 0..2
	void metaDispatch(int op, int index, void **args);

private:
	bool m_closeOnly30 = false;     // +0x30
	QString m_f38;                  // +0x38
	QSize m_topLeft44;              // +0x44
	QSize m_bottomRight4c;          // +0x4c
	QList<void *> m_f60;            // +0x60
	void *m_shared68 = nullptr;     // +0x68
	QList<void *> m_f70;            // +0x70
};
