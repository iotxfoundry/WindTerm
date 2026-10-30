#pragma once

#include <QJSEngine>
#include <QJSValue>
#include <QMap>
#include <QObject>
#include <QString>

// JS 引擎(批 32):语料 JsEngine 类(QObject 派生,metaObject
// 008fd850;evaluate 体 0064abb2/0064af3c;newQObject 0064b0d0)。
// 标准行为委托真 QJSEngine(混合架构边界,同 libssh/yaml-cpp 策略)。
// 动作表装载 = wind_actions_build(00667102):遍历 wind.actions
// map → script trimmed → evaluate 注册(名字 = 动作名,错误上下文
// 同 FUN_0064abb2 的 "%1".arg 命名法)。
class JsEngine : public QObject {
    Q_OBJECT

public:
    static JsEngine &instance();

    // 装载 wind.actions(JSONC map:{name:{text,script}});返回
    // 注册成功的动作数(重复调用 = 重载)
    int loadActions(const QString &path);
    int actionCount() const { return m_actions.size(); }
    bool hasAction(const QString &name) const;

    // 动作调用:存储的箭头函数 + 可选 action 实参(MuxPane 键流,
    // s_MuxPane_64b102);返回脚本结果;异常时返回 undefined
    QVariant runAction(const QString &name, QObject *actionArg = nullptr);

    // 桥对象注入(globalObject.setProperty ← newQObject;原版
    // application/window 等桥 = 应用层装配,Phase 4c)
    void installBridge(const QString &name, QObject *obj);

    // 通用脚本面(evaluate + 源码名字上下文,FUN_0064abb2)
    QVariant runScript(const QString &source, const QString &name);

private:
    Q_DISABLE_COPY(JsEngine)
    JsEngine() = default;
    QJSEngine m_engine;
    QMap<QString, QJSValue> m_actions;
};
