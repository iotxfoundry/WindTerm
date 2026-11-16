#pragma once

#include <QObject>

// SuperProtocolFace — 协议抽象基座(QObject 派生)。
//
// 出处:RTTI "SuperProtocol";dtor 无独立 entry(被派生类内联);
// 分发 0x007a2732(156B);metaObject 0x007a27ce(88B,带 className 分支);
// metacast 0x007a2826(23B)。
//
// 字段(分发 0x007a2732 实读):
//   +0x10 可替换指针 —— 该腿先存旧值再写入新值(swap 语义);
//   +0x1c int;+0x20 void*(交给 0x00a81502 的第三/第二实参)
//
// 注:metaObject 是 88B(不是常见的 24B)—— 说明它实现了动态元对象分支
//   (QObjectData::dynamicMetaObject),即支持运行期附加属性。
class SuperProtocolFace : public QObject {
	Q_OBJECT

public:
	explicit SuperProtocolFace(QObject *parent = nullptr);

	void swapDelegate(void *next); // 0x007a2732(156B)

private:
	void *m_delegate10 = nullptr; // +0x10
	int m_f1c = 0;                // +0x1c
	void *m_f20 = nullptr;        // +0x20
};
