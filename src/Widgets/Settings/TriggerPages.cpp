// TriggerPages.cpp — 触发器设置四页 + 两个小件(见头注对照表)。

#include "Widgets/Settings/TriggerPages.h"

// 出处:六者 dtor 均 29B 真身(只有 vptr 复位 + 基类析构)⇒ 零自有字段;
// deleting 均 47B 真身;ctor 均内联在调用点,只转发基构造。
// 六个 dtor 地址逐一列在头注对照表里。

TriggerActionWidgetFace::TriggerActionWidgetFace(QWidget *parent) : QWidget(parent) { }
TriggerActionWidgetFace::~TriggerActionWidgetFace() = default;

TriggerActionDialogFace::TriggerActionDialogFace(QWidget *parent) : QDialog(parent) { }
TriggerActionDialogFace::~TriggerActionDialogFace() = default;

ShowTooltipTriggerPageFace::ShowTooltipTriggerPageFace(QWidget *parent) : QWidget(parent) { }
ShowTooltipTriggerPageFace::~ShowTooltipTriggerPageFace() = default;

RunCommandTriggerPageFace::RunCommandTriggerPageFace(QWidget *parent) : QWidget(parent) { }
RunCommandTriggerPageFace::~RunCommandTriggerPageFace() = default;

SendTextTriggerPageFace::SendTextTriggerPageFace(QWidget *parent) : QWidget(parent) { }
SendTextTriggerPageFace::~SendTextTriggerPageFace() = default;

CategoryPageFace::CategoryPageFace(QWidget *parent) : QWidget(parent) { }
CategoryPageFace::~CategoryPageFace() = default;
