#ifndef APPLICATIONTHEME_H
#define APPLICATIONTHEME_H

#pragma once

#include <QList>
#include <QObject>

class QTimer;
class QWidget;

// ApplicationTheme —— DAT_011c1ce0 单例 cited 档(p3_notes_kg §4;铁律 6)。
// 初值链:_INIT_90(decomp-part-0016.c:13896)→ DAT_011c1ce0 =
// FUN_007538f6()(121B,0023:18668,__cxa_guard 懒建)→
// FUN_00753706(&DAT_011c1d20)(470B,0023:18597)= new ApplicationTheme:
//   vtable=ApplicationTheme → +0x10/+0x18/+0x20 QList shared_null ×3 →
//   +0x28 new QTimer(单发腿)/+0x50 new QTimer(节流腿),两 timer
//   timeout 各 connect functor(FUN_00754f46 / FUN_00753550 — 槽体
//   未读,cited — wave-2);__cxa_atexit(FUN_00753ac8,&DAT_011c1d20)
//   (ApplicationTheme_dtor 312B 撤 timer/清表 — Qt5 父子所有权承接)。
// 存储槽 DAT_011c1d20 / 守卫 DAT_011c1d08 / 取消门 DAT_011c1d78 < -1
// → return 0(静态局部形态无取消门 — 平台语义,注明不照抄)。
// 布局缺口 +0x30..0x4f 未解 — wave-2(本档无二进制布局契约,不补位)。
// 消费面:语料 218 处读 DAT_011c1ce0,面型六类(p3_notes_kg §4)。
// 与 King 枚举类零关系(qmo_extract:King metaobject methods=[]、45 枚举
// = KingEnums.h 权威);本类无 staticMetaObject 语料实证 → 不加
// Q_OBJECT,零 moc 面。
class ApplicationTheme : public QObject {
public:
	explicit ApplicationTheme(QObject *parent = nullptr);   // FUN_00753706 锚(0023:18597)

	// FUN_007538f6(0023:18668)guard 懒建单例(DAT_011c1ce0 句柄)
	static ApplicationTheme *instance();

private:
	QList<void *> m_f10;         // +0x10 QList shared_null @00753706 域(消费面未解,cited)
	QList<void *> m_f18;         // +0x18 QList shared_null(cited)
	QList<void *> m_f20;         // +0x20 QList shared_null(cited)
	QTimer *m_f28;               // +0x28 new QTimer(单发腿;connect functor 00754f46 — cited)
	QTimer *m_f50;               // +0x50 new QTimer(节流腿;connect functor 00753550 — cited)
};

// s_king_refreshWidgetStyle(00752640,67B,decomp-part-0023.c:17850)真身:
// style() → unpolish(虚表 0x68)→ polish(虚表 0x60)→ 条件 repaint。
// 语料 param_1(theme = DAT_011c1ce0)体内被弃(QWidget::style() 折叠
// this = param_2)— theme 参运行时弃用,签名不载(p3_notes_kg §3;
// kit 样式族 0017:19251 等 10 处调用后续真身化同用此函数,不必挂单例)。
namespace King {
void refreshWidgetStyle(QWidget *widget, bool repaint);
}

#endif // APPLICATIONTHEME_H
