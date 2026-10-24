#pragma once

#include <QAction>
#include <QMenu>
#include <QObject>
#include <QString>

#ifdef WINDTERM_HAVE_QJSENGINE
#include <QJSEngine>
#include <QJSValue>
#endif

class QTimer;
class TerminalView;

#ifdef WINDTERM_HAVE_QJSENGINE

// window 宿主对象（0x0064b102 newQObject(window) 面向 JS 的 Q_INVOKABLE 面）。
// 本 config（statusbar.config）用到的面：setInterval/findAction/createMenu/lockScreen；
// 超出面（activeMuxPane/activeText/openCommandPalette/runAction/…）挂账。
class ScriptWindow : public QObject
{
    Q_OBJECT

public:
    explicit ScriptWindow(QObject *parent = nullptr);

    // 0x0064b102 面：window.setInterval(obj, cb, ms)——QTimer 单实例挂 obj，timeout→cb.call()
    // （2000ms 时钟 applet 用；原版同签名，见 window metaobject setInterval/callback/milliseconds）
    Q_INVOKABLE void setInterval(QObject *obj, const QJSValue &callback, int milliseconds);

    // palette JS 面（goto-line.palette `let text = window.activeText`——活动终端 view 代理，
    // 与 ScriptTerminal::view() 同源 0x8d9764 焦点链）
    Q_PROPERTY(QObject *activeText READ activeText CONSTANT)
    QObject *activeText() const;

    // wind.actions 查找机制：返回已注册 QAction（"Terminal.SchemeList" 需存在）。
    // shortcut: 原版 Terminal.SchemeList 是动态 scheme 列表 action（text=() => schemeNames，
    // script=setScheme 0x56d890 链），此处返回弹出 SchemeManager::schemeNames 菜单的占位
    // checkable action，动态 text/script 绑定挂账（wind.actions script 求值引擎未实现）
    Q_INVOKABLE QObject *findAction(const QString &name);

    // scheme 按钮 menu（0x0064b102 createMenu，window metaobject "createMenu → Menu*"）。
    // 原版返回名为 Menu 的脚本包装类——QMenu::addAction 非 moc 槽 JS 不可调；骨架用
    // QMenu 子类补 Q_INVOKABLE addAction(QObject*)（is-a QMenu → button.menu 赋值直通）
    Q_INVOKABLE QObject *createMenu(QObject *button);

    // 0x0064b102 lockScreen：Q_UNIMPLEMENTED 挂账（原版锁屏链未逆明）
    Q_INVOKABLE void lockScreen();

signals:
    // 活动终端 view 变更（原版 window viewActivated 面由 TerminalWindow 驱动；
    // 骨架在 MuxPaneGroup stack currentChanged 处转发）
    void viewActivated(QObject *view);
};

// Menu 脚本面（原版 window metaobject createMenu 返回类型名 "Menu*"）：QMenu 子类 +
// Q_INVOKABLE addAction——QMenu::addAction(QString)/QWidget::addAction(QAction*) 均非 moc
// 槽，QJSEngine newQObject 面不可调（实测 TypeError），子类槽补齐
class ScriptMenu : public QMenu
{
    Q_OBJECT

public:
    using QMenu::QMenu;
    Q_INVOKABLE void addAction(QObject *action)
    {
        if (auto *a = qobject_cast<QAction *>(action))
            QMenu::addAction(a);
    }
    // 0x76cb16：ScriptMenu 同主菜单挂 aboutToShow（scheme 按钮菜单 Terminal.SchemeList
    // 子项状态刷新链；createMenu 返回后由调用方逐 action 补 state 属性，挂账）
    void hookUpdate()
    {
        connect(this, &QMenu::aboutToShow, this, [this] {
            for (QAction *action : actions())
                emit action->changed(); // 无 state 属性时为空操作；刷新文本由 ScriptWindow 链挂账
        });
    }
};

// terminal 脚本终端代理（0x0064b102 defineProperties(this,{terminal:get window.terminal})——
// global `terminal` 经 window.terminal getter 暴露；骨架直接注入同名对象）。
// 本 config 用到的面：view()/activeView()/viewActivated；schemeNames/keyMode 写路径挂账。
class ScriptTerminal : public QObject
{
    Q_OBJECT

public:
    explicit ScriptTerminal(QObject *parent = nullptr);

    // 当前活动 TerminalView（无→nullptr；原版 0x8d9764 焦点 view 链的骨架等价）
    Q_INVOKABLE QObject *view();
    Q_INVOKABLE QObject *activeView() { return view(); }

signals:
    void viewActivated(QObject *view);
};

// QJSEngine 宿主（0x0064b102 QJSEngineHost_ctor）：
// installExtensions(All)（TranslationExtension→qsTr）+ globalObject 注入
// King 枚举（KeyMode/ToolButtonPopupMode 等 Q_ENUM 面的 JS 常量）+ application（占位挂账）
// + window + terminal；runInit()=0x005a3156 statusbar_runInit。
class ScriptHost : public QObject
{
    Q_OBJECT

public:
    explicit ScriptHost(QObject *parent = nullptr);
    ~ScriptHost() override;

    ScriptWindow *window() const { return m_window; }
    ScriptTerminal *terminal() const { return m_terminal; }

    // 0x005a3156：evaluate("'use strict;'+init") → isCallable → newQObject(widget)
    // (CppOwnership) → callWithInstance(undefined,[widget])；isError→qWarning 一次（骨架自检面，
    // 原版静默）
    void runInit(QObject *widget, const QString &init);

    // 0x669086：action property("state")（wind.actions state JS 串）求值缓存 + callWithInstance
    // ([action])——JS 闭包内直接改 action.checked/checkable/enabled
    Q_INVOKABLE void updateActionState(QObject *action);

    // palette script 求值面（0x54334c mode7：CommandPalette 经宿主引擎求值 *.palette
    // script——QJSValue 不可跨 QJSEngine，必须共享本实例）。isError→qWarning+返回 Invalid。
    QJSValue evaluateScript(const QString &source, const QString &context = QString());

private:
    QJSEngine m_engine;
    ScriptWindow *m_window;
    ScriptTerminal *m_terminal;
};

#else // !WINDTERM_HAVE_QJSENGINE

// Qt5Qml 缺席时的空壳（StatusBar 降级为硬编码渲染）
class ScriptWindow : public QObject
{
    Q_OBJECT
public:
    explicit ScriptWindow(QObject *parent = nullptr) : QObject(parent) {}
signals:
    void viewActivated(QObject *view);
};

class ScriptTerminal : public QObject
{
    Q_OBJECT
public:
    explicit ScriptTerminal(QObject *parent = nullptr) : QObject(parent) {}
    Q_INVOKABLE QObject *view() { return nullptr; }
    Q_INVOKABLE QObject *activeView() { return nullptr; }
signals:
    void viewActivated(QObject *view);
};

class ScriptHost : public QObject
{
    Q_OBJECT
public:
    explicit ScriptHost(QObject *parent = nullptr) : QObject(parent) {}
    ScriptWindow *window() const { return &m_window; }
    ScriptTerminal *terminal() const { return &m_terminal; }
    void runInit(QObject *widget, const QString &init) { Q_UNIMPLEMENTED(); }
    // 降级无引擎：0x669086 面保留空实现（签名对齐，行为挂账）
    Q_INVOKABLE void updateActionState(QObject *) {}
private:
    ScriptWindow m_window;
    ScriptTerminal m_terminal;
};

#endif // WINDTERM_HAVE_QJSENGINE
