#pragma once

#include <QList>
#include <QObject>

// ToolsFace — 工具注册表(QObject 派生,容器只有一个列表)。
//
// 出处:RTTI "Tools";QMetaObject 0x0119f720
// (rev=8,class="Tools",methods=2,**signals=2**,props=0,superdata=0);
// sizeof = **0x18**(deleting 0x008fd81c 的 operator_delete(_,0x18));
// dtor 0x008fd7f8(36B)/deleting 0x008fd81c(49B);
// 列表清理腿 0x008fd6e0(279B);metacast 0x008fd570 / metacall 0x008fd5d8(93B)。
//
// 两条信号(串表实读):#0 `toolAdded` / #1 `toolRemoved`
//
// 字段:+0x10 QList<ToolPtr> —— 元素是**侵入式引用计数指针**:
//   dtor 里每元素走 +8 处的计数块(计数 -1,归零先调 vtable+0x10 的析构,
//   再减 +0xc 的弱计数,归零走 vtable+0x18 的释放器)—— 与 std::_Sp_counted_base
//   同形,也与 OutlinePane 的 +0x70 件同构。
//
// 附带一处元信息:qt_metacast 除了 strcmp "Tools",还会拿
// **"QList<ToolPtr>"** 做比较(0xf 次逐字符)—— 说明 Tools 把自己的列表类型
// 也注册进了元类型系统,是可以经元调用传出的。
class ToolsFace : public QObject {
	Q_OBJECT

public:
	explicit ToolsFace(QObject *parent = nullptr);
	~ToolsFace() override; // 0x008fd7f8

signals:
	void toolAdded();   // #0
	void toolRemoved(); // #1

private:
	QList<void *> m_tools10; // +0x10(元素为侵入式计数指针)
};
