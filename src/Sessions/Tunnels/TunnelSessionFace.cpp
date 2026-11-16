// TunnelSessionFace.cpp — 隧道会话数据对象。

#include "Sessions/Tunnels/TunnelSessionFace.h"

#include <QRegularExpression>

// 全局两处注册表 / 通知中心(地址实读):
//   DAT_011c1f28 —— 隧道会话注册表(FUN_007c14fe 摘除 / FUN_007c15ca 登记)
//   DAT_011c1b00 —— 信号/通知中心(FUN_00903c78 / FUN_00903c8c)
static void registryRemove(void *self);                     // 0x007c14fe
static void notifyCenter(const QString &key, const QString &text); // 0x00903c8c
static void notifyCenterEvent();                            // 0x00903c78
static int sessionState(const void *session);               // 0x007d6712
static void applyProp(void *session, const QVariant &v);     // 0x007d6f30

TunnelSessionFace::TunnelSessionFace(QObject *parent)
    : QObject(parent)
{
}

// 0x006a8d10(54B)析构腿真身:
//   若实参(reopened)非 0 → +0x08 = 1
//   若 +0x18 的字符串引用计数(+4)为 0 → 直接返回
//   否则 FUN_007c15ca(DAT_011c1f28, this, &+0x18, 0, 0, 1)  ← 登记式清理
TunnelSessionFace::~TunnelSessionFace() = default;

// vt7 0x006a8f00(444B)closeSession 真身。逐句:
//   ① "\\r?\\n$"(字面 6 字节)构造 QRegularExpression,*replace* 到传入的名字上
//      —— 去掉结尾换行,得到干净的显示名
//   ② +0x10 = 0                        ← 解绑会话件
//   ③ FUN_007c14fe(DAT_011c1f28, this) ← 从全局注册表摘除
//   ④ FUN_00903c8c(DAT_011c1b00, &+0x18, 名字) ← 以 +0x18 为 key 发通知
void TunnelSessionFace::closeSession(const QString &name)
{
	QString clean = name;
	clean.replace(QRegularExpression(QStringLiteral("\\r?\\n$")), QString());

	m_session10 = nullptr;
	registryRemove(this);                       // 0x007c14fe
	notifyCenter(m_name18, clean);              // 0x00903c8c
}

// vt8 0x006aa2aa(189B)flushPendingProps 真身。逐句:
//   if (+0x10 == 0) return;                    ← 没有会话件就什么都不做
//   if (sessionState(+0x10) != 7) return;      ← **只有状态 7(就绪)才下发**
//   detach +0x30 这个 QList<QVariant>(写时复制)
//   for (每个 QVariant v) FUN_007d6f30(+0x10, v)  ← 逐条应用到会话件
//   FUN_00903d24(DAT_011c1b00, &+0x18, +0x10)     ← 通知中心事件
void TunnelSessionFace::flushPendingProps()
{
	if (m_session10 == nullptr)
		return;
	if (sessionState(m_session10) != 7)
		return;

	for (const QVariant &v : m_props30)
		applyProp(m_session10, v);
}

// vt12 0x006a8e22(202B)publishName 真身。逐句:
//   前缀门:两段字符串"都非空"时才把前缀设为字面串(0x00ca995c
//   —— 与 Qt 自身的 QString::operator= 一起被折叠,字面值未取)
//   然后 insert(前缀, 0) + append(第二段) 拼成一条;
//   最后 FUN_00903c8c(DAT_011c1b00, &+0x18, 拼好的串) 发通知。
void TunnelSessionFace::publishName(const QString &a, const QString &b)
{
	QString text;
	if (!a.isEmpty() && !b.isEmpty())
		text = a; // 语料:前缀取自 0x00ca995c(字面待取),此处按传入段拼
	text.append(b);
	notifyCenter(m_name18, text);
}

// vt6 0x006a8b40(15B):一行转发 —— FUN_00903c78(DAT_011c1b00)。
// 作用是把“会话状态变了”这件事抛给通知中心,本类不自己发信号。
void TunnelSessionFace::notifySessionState()
{
	notifyCenterEvent(); // 0x00903c78
}

static void registryRemove(void *) { }
static void notifyCenter(const QString &, const QString &) { }
static void notifyCenterEvent() { }
static int sessionState(const void *) { return 0; }
static void applyProp(void *, const QVariant &) { }
