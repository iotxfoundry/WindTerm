#include "ApplicationTheme.h"

#include <QStyle>
#include <QTimer>
#include <QWidget>

// === ApplicationTheme(QObject*) ===
// FUN_00753706(470B,0023:18597)— 类壳锚,cited 档:QList shared_null
// ×3(+0x10/+0x18/+0x20)= 默认构造承接;两 QTimer 建序真身(+0x28 单发
// /+0x50 节流),timeout connect functor FUN_00754f46 / FUN_00753550
// 槽体未读 — cited — wave-2(不发明)。__cxa_atexit 尾(dtor
// FUN_00753ac8,312B)= Qt5 父子所有权承接(timers parented to this)。
ApplicationTheme::ApplicationTheme(QObject *parent)
	: QObject(parent)
	, m_f10()                     // +0x10 QList shared_null @00753706 域(消费面未解,cited)
	, m_f18()                     // +0x18 QList shared_null(cited)
	, m_f20()                     // +0x20 QList shared_null(cited)
	, m_f28(new QTimer(this))     // +0x28 new QTimer(单发腿)
	, m_f50(new QTimer(this))     // +0x50 new QTimer(节流腿)
{
	// FUN_00754f46 / FUN_00753550 timeout connect — cited — wave-2
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
