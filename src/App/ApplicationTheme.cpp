#include "ApplicationTheme.h"

#include <QGuiApplication>
#include <QScreen>
#include <QStyle>
#include <QTimer>
#include <QWidget>

// === ApplicationTheme(QObject*) ===
// 转写 FUN_00753706(470B,0023:18597):QList shared_null ×3(+0x10/+0x18
// /+0x20)= 默认构造承接;+0x28/+0x50 两 QTimer new(单发腿/节流腿 —
// 0023:18597 命名;单发标志位 pQVar2[0x1c]|=1 的 QTimer 内部槽未建模 —
// 不发明;dtor 面 = Qt5 父子所有权承接);timeout connectImpl 真身两腿:
// @007537d7-cc 槽 = FUN_00754f46、@00753823-d4 槽 = FUN_00753550
// (connectImpl 第三参上下文 = 本体)— Qt5 面 = connect(timer,
// &QTimer::timeout, this, 槽成员)。__cxa_atexit 尾(dtor
// FUN_00753ac8,312B;ApplicationTheme_dtor @18695 两腿虚收)= Qt5
// 父子所有权承接(timers parented to this)。
ApplicationTheme::ApplicationTheme(QObject *parent)
	: QObject(parent)
	, m_f10()                  // +0x10 QList shared_null @0075372e(消费面未解,cited)
	, m_f18()                  // +0x18 QList shared_null @00753736(cited)
	, m_f20()                  // +0x20 QList shared_null @0075373e(cited)
	, m_f28(new QTimer(this))  // +0x28 new QTimer @0075376b-7e(单发腿)
	, m_f50(new QTimer(this))  // +0x50 new QTimer @00753797-aa(节流腿)
{
	// +0x30..+0x48 四槽 ← 0 @00753746-56(消费面未解 — cited;本档无
	//   二进制布局契约,不补位)
	// timeout connectImpl 槽接线(FUN_00754f46 @007537d7 / FUN_00753550
	//   @00753823)— 已真身化
	connect(m_f28, &QTimer::timeout, this, &ApplicationTheme::clearClosedSidebars);
	connect(m_f50, &QTimer::timeout, this, &ApplicationTheme::throttleRelease);
}

// === instance() ===
// FUN_007538f6(121B,0023:18668)转写:__cxa_guard 单例(存储槽
// DAT_011c1d20,守卫 DAT_011c1d08)→ FUN_00753706(&DAT_011c1d20)。
// 取消门 DAT_011c1d78 < -1 → return 0:静态局部形态无对应(平台
// 语义)→ 恒返实例,判定不可照抄 — 注明。
ApplicationTheme *ApplicationTheme::instance()
{
	static ApplicationTheme s_theme;   // 存储槽 DAT_011c1d20
	return &s_theme;                   // DAT_011c1ce0 句柄
}

// === clearClosedSidebars() ===
// 转写 FUN_00754f46(331B,0023:19682)+0x28 单发腿 timeout 槽(331B 全读):
//   S0 0023:19688-93:QGuiApplication::screens() 取屏列表(qcoreapp_self_get
//     句柄在体内被弃;空表起底);
//   S1 0023:19697-733:倒序遍历 +0x20 QList(end-1 → 0):
//     d->ref>1 detach 卫(FUN_007583a0 0023:22244 @19705/19730 — Qt5
//       隐式共享承接);
//     节点(0x20 块)首字节门(19710)→ 节点 +0x10 存 QScreen*
//       (FUN_00758710 0023:22474 = QList 指针扫描,19715)已不在
//       screens → QObject::disconnect(screen,0,this,0)@19721;
//     FUN_007525da(node)(34B @17790:节点 +0x18 子对象(0x70)→
//       FUN_009b9c0e 61B 0032:53427 析构链 + operator delete(0x70))
//       + operator delete(node,0x20)@19724-25;
//     QListData::remove @19733(removeAt;d>1 detach 卫同上);
//   S2 0023:19740:FUN_00752a6c(18B @18050)= s_application_themeGui_75292c
//     (0075292c)+ s_application_themeText_7529cc(007529cc):全局仓
//     (DAT_011c1240)setProperty "application.themeGui"/"themeText" →
//     SuperApplication 信号 2(FUN_0090e084 0029:31560)— 私有仓槽
//     未落,不发明 — cited — wave-2;
//   S3:局部屏表 dispose = RAII 承接(无面)。
void ApplicationTheme::clearClosedSidebars()
{
	const QList<QScreen *> screens = QGuiApplication::screens();   // @00754f56 区(取屏)
	for (int i = m_f20.size() - 1; i >= 0; --i) {                  // 倒序 @00754f9d-19740
		char *node = static_cast<char *>(m_f20.at(i));             // *(d+0x10+i*8)@19709
		                                                           // (0x20 块,字段落点实证/类型未命名 — 偏移直读承接)
		if (node[0] != '\0') {                                     // *pcVar3 首字节门 @19710
			QScreen *screen =
			    *reinterpret_cast<QScreen **>(node + 0x10);        // 节点 +0x10(19721 disconnect 源)
			if (screens.contains(screen))                              // FUN_00758710 扫描 @19715/00755013
				QObject::disconnect(screen, nullptr, this, nullptr);   // 0023:19721
			// FUN_007525da(node)@19724:节点 +0x18 子对象(0x70)析构链
			//   FUN_009b9c0e(0032:53427)未读 — 类型未命名,dtor/delete
			//   面不可写 — cited — wave-2
			::operator delete(node, size_t(0x20));                     // operator delete(node,0x20)@19725
			m_f20.removeAt(i);                                         // QListData::remove @19733
		}
	}
	// FUN_00752a6c(this)@19740 = application.themeGui/themeText 全局仓
	//   属性发布(s_application_themeGui_75292c 0075292c /
	//   s_application_themeText_7529cc 007529cc)— cited — wave-2(见上 S2)
	// screens dispose = RAII(无面)
}

// === throttleRelease() ===
// FUN_00753550(437B,0023:18501)+0x50 节流腿 timeout 槽 — cited — wave-2:
// 体 = this->+0x40 分支容器递归释放面(0023:18507-83:节点链遍历 +
// QArrayData 引用计数增减 + vtable 0x20 虚收 @18536-9)+ FUN_00757f08
// (456B @21977,递归释放墙 @18580-3)→ 尾 +0x40 = 0 @18585-6。
// 容器/节点类型未解(+0x40 本档无布局契约不补位),Qt5 C++ 面不可
// 同构落码 — 宁可空缺(铁律 6)。
void ApplicationTheme::throttleRelease()
{
	// FUN_00753550 — cited — wave-2(见上)
}

// === King::refreshWidgetStyle ===
// s_king_refreshWidgetStyle(00752640,67B,decomp-part-0023.c:17850)真身:
//   QStyle *s = QWidget::style(w)@00752652
//   vtable 0x68 = QStyle::unpolish(QWidget*)@0075265e(Qt5 虚表 12/13 槽
//     核对:0x60=polish/0x68=unpolish;语料先 0x68 后 0x60 = 动态属性
//     换肤标准序,p3_notes_kg §3)
//   vtable 0x60 = QStyle::polish(QWidget*)@00752667
//   param_3 != 0 → QWidget::repaint(w)@00752675
void King::refreshWidgetStyle(QWidget *widget, bool repaint)
{
	QStyle *st = widget->style();   // QWidget::style @00752652
	st->unpolish(widget);           // vtable 0x68 @0075265e
	st->polish(widget);             // vtable 0x60 @00752667
	if (repaint)
		widget->repaint();          // QWidget::repaint @00752675
}
