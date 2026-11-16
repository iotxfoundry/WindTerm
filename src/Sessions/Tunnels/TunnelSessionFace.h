#pragma once

#include <QList>
#include <QObject>
#include <QString>
#include <QVariant>

// TunnelSessionFace — 单个隧道会话的数据对象。
//
// 出处:RTTI "TunnelSession";sizeof = **0x38**
// (TunnelCenter 的列表清理腿 0x006a92b7 里 operator_delete(elem, 0x38));
// 虚面:vt6 0x006a8b40(15B)/ vt7 0x006a8f00(444B)/ vt8 0x006aa2aa(189B)/
//       vt12 0x006a8e22(202B)/ vt9..vt11 & vt13 各 1 字节(纯 `ret`,
//       编译器把空覆盖压成了裸返回 —— objdump 已核,不是 0 长函数);
// 析构腿 0x006a8d10(54B);会话装配 0x006a8b50(365B)。
//
// 字段(三条腿 + 清理腿交叉实读):
//   +0x08 u8      "已重连"标记(析构时若实参为真则置 1)
//   +0x10 void*   关联的会话件(0x007d6712 取其状态,== 7 表示就绪)
//   +0x18 QString 显示名(所有对外通知都用它做 key)
//   +0x28 QSharedDataPointer
//   +0x30 QSharedDataPointer
//   (+0x30 在 vt8 里被当作 QList<QVariant> 遍历 —— 见 vt8 注)
class TunnelSessionFace : public QObject {
	Q_OBJECT

public:
	explicit TunnelSessionFace(QObject *parent = nullptr);
	~TunnelSessionFace() override; // 0x006a8d10

	// vt7 0x006a8f00(444B)—— 收尾:规范化显示名 → 解绑 → 摘注册 → 通知
	void closeSession(const QString &name);

	// vt8 0x006aa2aa(189B)—— 会话就绪后把排队的属性逐个下发
	void flushPendingProps();

	// vt12 0x006a8e22(202B)—— 拼一条显示串并通知(带前缀门)
	void publishName(const QString &a, const QString &b);

protected:
	void notifySessionState(); // vt6 0x006a8b40(15B)

	quint8 m_reopened8 = 0;   // +0x08
	void *m_session10 = nullptr; // +0x10
	QString m_name18;         // +0x18
	void *m_shared28 = nullptr; // +0x28
	QList<QVariant> m_props30;  // +0x30
};
