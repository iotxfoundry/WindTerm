#pragma once

#include <QHash>
#include <QObject>
#include <QVariant>

class QAction;
class QJSValue;

// 动作工厂 + wind.actions 装配 —— 语料转写(铁律 6,批 35)。
// 语料函数族(协议五元组之外的动作子系统):
//   actionFactory_getOrCreate 00665dc2(856B):名字 trim → 工厂表
//     (corpus factory+0x10 = QHash<QByteArray,QAction*>)查 → 缺则
//     new QAction + setText(name) + connectImpl(QAction::triggered →
//     FUN_0066a148,functor 壳 0066b3a0)→ 插表
//   FUN_0066613a(2882B):条目应用,四键依序 script/icon/text/tooltip
//     —— script:toString().trimmed(),空 → setEnabled(false),
//     非空 → QAction::setData(script);icon:toString 非空 →
//     theme_icon_load_svg(00756cd6)→ setIcon + setProperty
//     ("iconFile",s);text/tooltip:toString().trimmed().toUtf8()
//     → QMetaObject::tr(QObject 上下文)→ setText/setToolTip
//   wind_actions_build 00667102(7702B):根 map 空守卫(+0x10)→
//     迭代(key→toUtf8,value→toMap)→ FUN_0066613a
//   s_wind_actions_76b7c0(457B):文件装载入口(wind_actions_build
//     双源调用:global + user)
// 触发执行 = FUN_0066a148(103B):sender() → QAction →
//   js_actionFire(006697b2,2282B —— 下一批转写,本批 cited 桩)
class ActionFactory : public QObject {
    Q_OBJECT

public:
    explicit ActionFactory(QObject *parent = nullptr);

    // 00665dc2:名字查/建 QAction(触发已接 0066a148 处理链)
    QAction *getOrCreate(const QByteArray &name);

    // 00667102:wind.actions 根 map 装配(条目数)
    int build(const QVariantMap &root);

    // s_wind_actions_76b7c0:文件装载入口(JSONC)
    int loadActionsFile(const QString &path);

private:
    void applyEntry(QAction *action, const QVariantMap &entry);   // 0066613a
    QHash<QByteArray, QAction *> m_actions;   // 工厂表(corpus +0x10)
};

// js_actionState 00669086(1739B)—— 语料转写(批 37):
// action->property("dynamic")(名串 @0x11821e8 实证)→ QAction*
// 门(DAT_011c0b04 一次注册)→ linked->property(propName)→
// action->setProperty(propName, …)状态镜像(@006697xx 尾)
void js_actionState(QAction *action, const char *propName);
