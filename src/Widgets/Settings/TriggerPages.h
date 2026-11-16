#pragma once

#include <QDialog>
#include <QWidget>

// TriggerPages.h — 触发器设置的四页 + 两个小件(全部**零字段**)。
//
// 六个类的 dtor 一律 **29B**(vptr 复位 + 基类析构两行)、deleting 47B,
// QMetaObject 有/无非关键(**这一族全是装配体,元接口在页基类上**);
// 判据统一:dtor 29B ⇒ 零自有字段,内容全在内联的装配腿里。
//
// | 类 | 基类(dtor 末句) | dtor | deleting |
// |---|---|---|---|
// | TriggerActionWidget     | **QWidget** | 0x006f65be | 0x006f65fc |
// | TriggerActionDialog     | **QDialog** | 0x006f651e | 0x006f655c |
// | ShowTooltipTriggerPage  | **QWidget** | 0x006f6b5e | 0x006f6b9c |
// | RunCommandTriggerPage   | **QWidget** | 0x006f6a1e | 0x006f6a5c |
// | SendTextTriggerPage     | **QWidget** | 0x006f6abe | 0x006f6afc |
// | CategoryPage            | **QWidget** | 0x006ec240 | 0x006ec27e |
//
// ⚠ 注意 **TriggerActionDialog 的基类是 QDialog**,其余五个是 QWidget。
//   「Trigger*」一族里 QWidget / QDialog / QFrame 三种基类都出现过,
//   不能按前缀推基类。
//
// ⚠ 另注:本文件**只落"零字段 + 基类"这条事实**,没有落各自的元接口 ——
//   因为这一族真正常用的是 `TriggerPageFace`(已存在)提供的那套;
//   这四个 Page 是它的**具体页**,元接口为 0 或全继承。
//   要落页内控件时与 TriggerPageFace 一起开批。

class TriggerActionWidgetFace : public QWidget {
	Q_OBJECT
public:
	explicit TriggerActionWidgetFace(QWidget *parent = nullptr);
	~TriggerActionWidgetFace() override; // 0x006f65be
};

class TriggerActionDialogFace : public QDialog {
	Q_OBJECT
public:
	explicit TriggerActionDialogFace(QWidget *parent = nullptr);
	~TriggerActionDialogFace() override; // 0x006f651e
};

class ShowTooltipTriggerPageFace : public QWidget {
	Q_OBJECT
public:
	explicit ShowTooltipTriggerPageFace(QWidget *parent = nullptr);
	~ShowTooltipTriggerPageFace() override; // 0x006f6b5e
};

class RunCommandTriggerPageFace : public QWidget {
	Q_OBJECT
public:
	explicit RunCommandTriggerPageFace(QWidget *parent = nullptr);
	~RunCommandTriggerPageFace() override; // 0x006f6a1e
};

class SendTextTriggerPageFace : public QWidget {
	Q_OBJECT
public:
	explicit SendTextTriggerPageFace(QWidget *parent = nullptr);
	~SendTextTriggerPageFace() override; // 0x006f6abe
};

class CategoryPageFace : public QWidget {
	Q_OBJECT
public:
	explicit CategoryPageFace(QWidget *parent = nullptr);
	~CategoryPageFace() override; // 0x006ec240
};
