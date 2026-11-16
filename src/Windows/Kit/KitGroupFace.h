#pragma once

#include <QMainWindow>
#include <QString>

// KitGroupFace — 分屏组窗口(QMainWindow 派生,4 信号 + 2 槽)。
//
// 出处:RTTI "KitGroup";QMetaObject 0x011ab360
// (rev=8,class="KitGroup",methods=6,**signals=4**,props=0,superdata=0);
// sizeof = **0x48**(deleting 0x0091b074 的 operator_delete(_,0x48));
// dtor 0x0091b128(86B)/deleting 0x0091b074(92B);
// 元接口桥 0x0091aca2(697B);metacast 0x0091af64 / metacall 0x0091afa6(109B)。
//
// 元接口(串表实读):
//   #0 tabBlankRequested(...)     4 条全是"标签页请求":空白 / 关闭 / 复制 / 重命名
//   #1 tabCloseRequested(...)
//   #2 tabDuplicateRequested(...)
//   #3 tabRenameRequested(...)
//   #4 viewCount()   槽
//   #5 name()        槽
//
// 字段(dtor 实读):**+0x30 QString**;0x30+8=0x38 但 sizeof 0x48 ——
//   语料 dtor 只碰 +0x30,故按"只有这一个字段"落;余量来自 QMainWindow 链。
//
// ⚠ 本类的 `KitGroup_map_freetree`(0x008bf498,**4449B**)与
//   `OneKeyCenter_map_freetree`(0x00659768,4449B)、
//   `ForwardingCenter_h5ee52a`(0x005ee52a,4449B)**字节级同尺寸** ——
//   这是同一个 `QMap<QString,QVariant>` 的 free-tree 模板实例化,
//   被三个类各实例化了一份。**4449B 不是类自己的逻辑,不要按类去逆向**。
//   遇到"多个类里有一个完全同尺寸的大函数",先按模板实例化处理。
class KitGroupFace : public QMainWindow {
	Q_OBJECT

public:
	explicit KitGroupFace(QWidget *parent = nullptr);
	~KitGroupFace() override; // 0x0091b128

signals:
	void tabBlankRequested(const QString &group);     // #0
	void tabCloseRequested(const QString &group);     // #1
	void tabDuplicateRequested(const QString &group); // #2
	void tabRenameRequested(const QString &group);    // #3

public slots:
	int viewCount();      // #4
	QString name() const; // #5

private:
	QString m_f30; // +0x30
};
