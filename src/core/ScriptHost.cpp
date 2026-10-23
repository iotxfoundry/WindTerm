#include "ScriptHost.h"

#ifdef WINDTERM_HAVE_QJSENGINE

#include <QAction>
#include <QDebug>
#include <QCursor>
#include <QJSEngine>
#include <QMenu>
#include <QTimer>
#include <QtQml>

#include "widgets/TerminalView.h"
#include "core/SchemeManager.h"

ScriptWindow::ScriptWindow(QObject *parent)
    : QObject(parent)
{
}

// 0x0064b102 window.setInterval：QTimer 单实例挂 obj，timeout→cb.call()
// （QJSValue 按堆持——QTimer 存活期内回调有效；timer 父挂 obj 随其销毁）
void ScriptWindow::setInterval(QObject *obj, const QJSValue &callbackIn, int milliseconds)
{
    if (!obj || !callbackIn.isCallable())
        return;
    QJSValue callback = callbackIn;
    auto *timer = new QTimer(obj);
    timer->setInterval(milliseconds);
    auto *holder = new QJSValue(callback);
    QObject::connect(timer, &QTimer::timeout, timer, [holder] { holder->call(); });
    QObject::connect(obj, &QObject::destroyed, timer, [holder] { delete holder; });
    timer->start();
}

QObject *ScriptWindow::findAction(const QString &name)
{
    // shortcut: 仅 "Terminal.SchemeList" 有骨架面——原版为动态 scheme 列表 action
    // （wind.actions:976 text=() => schemeNames / script=activeMuxPane.setScheme），
    // 动态 text/script 求值引擎未实现：返回弹出 schemeNames 菜单的占位 action（0x56d890 链待接）
    if (name != QLatin1String("Terminal.SchemeList")) {
        qWarning() << "ScriptWindow::findAction: no skeleton face for" << name;
        return nullptr;
    }
    auto *action = new QAction(this);
    action->setText(name);
    auto *menu = new QMenu;
    for (const QString &scheme : SchemeManager::instance().schemeNames()) {
        QAction *schemeAction = menu->addAction(scheme);
        // shortcut: setScheme 应用配色挂账（SchemeManager 无切换存储，TerminalView scheme 链未接）
        connect(schemeAction, &QAction::triggered, this, [] { Q_UNIMPLEMENTED(); });
    }
    connect(action, &QAction::triggered, this, [action, menu] {
        menu->exec(QCursor::pos());
    });
    return action;
}

QObject *ScriptWindow::createMenu(QObject *button)
{
    // 0x0064b102：createMenu → Menu*(parent QWidget*)；ScriptMenu is-a QMenu 挂 button
    return new ScriptMenu(qobject_cast<QWidget *>(button));
}

void ScriptWindow::lockScreen()
{
    Q_UNIMPLEMENTED(); // 原版锁屏链（0x0064b102 lockScreen 面存在）未逆明，挂账
}

ScriptTerminal::ScriptTerminal(QObject *parent)
    : QObject(parent)
{
}

QObject *ScriptTerminal::view()
{
    // 原版 0x8d9764：焦点 terminal → termview；骨架：MuxPaneGroup stack 当前 view
    if (TerminalView *view = TerminalView::activeView())
        return view;
    return nullptr;
}

ScriptHost::ScriptHost(QObject *parent)
    : QObject(parent)
    , m_window(new ScriptWindow(this))
    , m_terminal(new ScriptTerminal(this))
{
    // 0x0064b102 QJSEngineHost_ctor：
    QJSValue undefinedValue; // QJSValue() 无参=undefined（installExtensions 的 scope 参数面）
    m_engine.installExtensions(QJSEngine::AllExtensions, undefinedValue);

    // King 枚举对象：Q_ENUM KeyMode(0x00542e86) + ToolButtonPopupMode 面
    // （0xccbc40 metaobject：UnknownMode=0/WidgetMode=1/NormalMode=2/CommandMode=4/
    //  RemoteMode=8/LocalMode=16/AnyMode=31；InstantPopup=2）。原版经 newQMetaObject(King)+freeze，
    // 骨架静态注入等值常量（MuxPane 枚举无骨架面，挂账）
    QJSValue king = m_engine.evaluate(
        QStringLiteral("({"
                       "UnknownMode: 0, WidgetMode: 1, NormalMode: 2, CommandMode: 4,"
                       " RemoteMode: 8, LocalMode: 16, AnyMode: 31,"
                       " InstantPopup: 2, MenuButtonPopup: 1, DelayedPopup: 0"
                       "})"));
    king.setProperty(QStringLiteral("LocalMode"), QJSValue(16));
    king.setProperty(QStringLiteral("RemoteMode"), QJSValue(8));
    king.setProperty(QStringLiteral("InstantPopup"), QJSValue(2));
    m_engine.globalObject().setProperty(QStringLiteral("King"), king);

    // application 占位（原版 newQObject(qApp)；骨架无 application 脚本面，空对象挂账）
    m_engine.globalObject().setProperty(
        QStringLiteral("application"), m_engine.newObject());

    // window/terminal 注入 + CppOwnership（0x0064b0d0 newQObject+setObjectOwnership(0)——
    // 0=CPlusPlusOwnership；骨架的 setObjectOwnership(widget,CppOwnership) 等价）
    QQmlEngine::setObjectOwnership(m_window, QQmlEngine::CppOwnership);
    m_engine.globalObject().setProperty(QStringLiteral("window"), m_engine.newQObject(m_window));
    QQmlEngine::setObjectOwnership(m_terminal, QQmlEngine::CppOwnership);
    // 0x0064b102 defineProperties(this,{terminal: get window.terminal})——global `terminal`
    // 经 window.terminal 暴露；骨架直接注入同名对象（JS 面等价）
    m_engine.globalObject().setProperty(QStringLiteral("terminal"), m_engine.newQObject(m_terminal));
}

ScriptHost::~ScriptHost() = default;

// 0x005a3156 statusbar_runInit：
// evaluate("'use strict;'+init") → isCallable → newQObject(widget)+CppOwnership
// → callWithInstance(undefined, [widget])；isError→qWarning（原版静默，骨架自检输出一次）
void ScriptHost::runInit(QObject *widget, const QString &init)
{
    // 原版 FUN_0064af3c："use strict;" 字面量与 init 源串直接拼接后 evaluate——整体为一个
    // script；'"use strict";\n' 使严格模式指令序言生效且 init 表达式可求值
    QJSValue callable = m_engine.evaluate(QStringLiteral("\"use strict\";\n") + init);
    if (!callable.isCallable())
        return;
    QJSValue widgetValue = m_engine.newQObject(widget);
    QQmlEngine::setObjectOwnership(widget, QQmlEngine::CppOwnership);
    QJSValueList args;
    args.append(widgetValue);
    QJSValue result = callable.callWithInstance(QJSValue(QJSValue::UndefinedValue), args);
    if (result.isError())
        qWarning() << "statusbar init error:" << result.toString();
}

#else // !WINDTERM_HAVE_QJSENGINE
// 降级路径全在头文件（无 QJSEngine 时 ScriptHost 为空壳）
#endif
