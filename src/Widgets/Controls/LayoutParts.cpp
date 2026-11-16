// LayoutParts.cpp — 三个自研 Qt 空壳子类(见头注对照表)。

#include "Widgets/Controls/LayoutParts.h"

// 出处:三者 dtor 均 19–29B 真身(deleting 用 operator_delete(_, 基类尺寸))
// ⇒ 零自有字段;ctor 均内联在调用点,只转发基构造。

// dtor 0x0055c86a(29B)真身 → QWidget;deleting 0x0055c8a8(47B)。
WidgetContainerFace::WidgetContainerFace(QWidget *parent) : QWidget(parent) { }
WidgetContainerFace::~WidgetContainerFace() = default;

// dtor 0x00551e24(29B)真身 → QVBoxLayout;deleting 0x00551e62(47B,_,0x20);
// vt15 0x00551e18(6B)真身:一行转发。
VBoxLayoutFace::VBoxLayoutFace(QWidget *parent) : QVBoxLayout(parent) { }
VBoxLayoutFace::~VBoxLayoutFace() = default;

// dtor 0x005a1b72(19B)真身 → QProxyStyle;deleting 0x005a1b86(37B)。
ProxyStyleFace::ProxyStyleFace(QObject *parent) : QProxyStyle() { Q_UNUSED(parent); }
ProxyStyleFace::~ProxyStyleFace() = default;
