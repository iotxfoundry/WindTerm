// ToolbarWidgetActions.cpp — 六个零字段工具栏动作(逐字节同构,见头注)。

#include "Actions/ToolbarWidgetActions.h"

// 出处:六个类的 dtor 都是 19B(vptr 复位 + QWidgetAction::~QWidgetAction),
// deleting 都是 37B(+ operator_delete(_, 0x10))。
// ctor 无独立 entry(内联在调用点),仅转发基构造。

GroupWidgetActionFace::GroupWidgetActionFace(QObject *parent) : QWidgetAction(parent) { }
GroupWidgetActionFace::~GroupWidgetActionFace() = default;

UnitWidgetActionFace::UnitWidgetActionFace(QObject *parent) : QWidgetAction(parent) { }
UnitWidgetActionFace::~UnitWidgetActionFace() = default;

IntervalWidgetActionFace::IntervalWidgetActionFace(QObject *parent) : QWidgetAction(parent) { }
IntervalWidgetActionFace::~IntervalWidgetActionFace() = default;

TargetsWidgetActionFace::TargetsWidgetActionFace(QObject *parent) : QWidgetAction(parent) { }
TargetsWidgetActionFace::~TargetsWidgetActionFace() = default;

CountWidgetActionFace::CountWidgetActionFace(QObject *parent) : QWidgetAction(parent) { }
CountWidgetActionFace::~CountWidgetActionFace() = default;

EditWidgetActionFace::EditWidgetActionFace(QObject *parent) : QWidgetAction(parent) { }
EditWidgetActionFace::~EditWidgetActionFace() = default;
