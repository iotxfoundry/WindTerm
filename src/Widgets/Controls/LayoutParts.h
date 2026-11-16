#pragma once

#include <QProxyStyle>
#include <QVBoxLayout>
#include <QWidget>

// LayoutParts.h — 三个"自研 Qt 子类"(全部零字段)。
//
// 判据:dtor 19–29B(只有 vptr 复位 + 基类析构),deleting 用
// operator_delete(_, N) 且 N 等于基类本身尺寸 ⇒ **零自有字段**。
//
// | 类 | 基类 | sizeof | 说明 |
// |---|---|---|---|
// | WidgetContainer | **QWidget** | 0x30 | 纯容器,副 vptr 0x01184638 |
// | VBoxLayout      | **QVBoxLayout** | 0x20 | 副 vptr 0x01184388;vt15 6B |
// | ProxyStyle      | **QProxyStyle** | — | dtor 19B,最薄 |
//
// **这三个是 WindTerm 对 Qt 的"空壳子类"**:自己不加字段、不加槽,
// 只换 vptr。副作用是**类型可辨识** —— 用 `qobject_cast<WidgetContainer*>`
// 就能和普通 QWidget 区分开。Completer / HighlightTextBarAction 里那个
// "WidgetContainer_vtable" 就是本类(它们的 createWidget 会造一个它)。
//
// 出处(entry 地址逐一列,真身):
//   WidgetContainer dtor 0x0055c86a / deleting 0x0055c8a8
//   VBoxLayout      dtor 0x00551e24 / deleting 0x00551e62 / vt15 0x00551e18(6B)
//   ProxyStyle      dtor 0x005a1b72 / deleting 0x005a1b86

class WidgetContainerFace : public QWidget {
	Q_OBJECT
public:
	explicit WidgetContainerFace(QWidget *parent = nullptr);
	~WidgetContainerFace() override; // 0x0055c86a
};

class VBoxLayoutFace : public QVBoxLayout {
	Q_OBJECT
public:
	explicit VBoxLayoutFace(QWidget *parent = nullptr);
	~VBoxLayoutFace() override; // 0x00551e24
};

class ProxyStyleFace : public QProxyStyle {
	Q_OBJECT
public:
	explicit ProxyStyleFace(QObject *parent = nullptr);
	~ProxyStyleFace() override; // 0x005a1b72
};
