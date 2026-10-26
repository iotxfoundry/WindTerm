#pragma once

#include "StatusBar.h"

#include <QStringList>

class KitPane;
class ScriptHost;

// 原版 AppletBar（0x00526a7c）：StatusBar 子类——ctor 在 StatusBar_ctor 基础上改 objectName
// "AppletBar" + setWindowTitle(King_title→"Applet Bar")；QSS 类名对照见 R17（ThemeManager
// 改写表已含 AppletBar）。用途=pane 内部 applet 条（KitPane_ensureAppletBar 0x005bf49e 在
// pane 的 QVBoxLayout 找/建，非主窗底栏 0x008c9f8c）。
// 装载链=appletbar_loadFiles 0x005284d6：逐文件 相对路径→<appDir>/terminal/applets/
// （0x00526be0）→applet_load_script_info 0x00526ffa 解析 name/uuid/type/init →与
// statusbar.config 条目同形转 populate（同工厂+0x005a3156 runInit 链）。
class AppletBar : public StatusBar
{
    Q_OBJECT

public:
    explicit AppletBar(QWidget *parent = nullptr);

    // scheme facet 装载列表（0x0084a755 首段 FUN_005b97cc：scheme 的 .appletbar import 数组；
    // vendor 路径 terminal/schemes/<scheme>/<scheme>.appletbar，"import:" 下 "- path" 列表，
    // /opt 实文 cmd.appletbar="import:\n  - sysmon/windows/sysmon.applet"）。
    // skeleton assets 无 schemes/ 目录（scheme 概念未建）→空串/未知名恒空列表=AppletBar 空态。
    static QStringList schemeAppletbarImports(const QString &schemeName);

    // 0x0084a755 pane_sysmon_applet_load 开关门（纯函数便于测试）：pane 名 "Shell" 吃
    // shell.sysmon 开关、"SSH" 吃 ssh.sysmon；开关=false 或其余 pane 名→逆序剔除路径含
    // "sysmon" 的项（原版 QString::indexOf("sysmon")!=-1 删），开关=true 原样保留。
    static QStringList filterPaneApplets(const QStringList &files, const QString &paneName,
                                         bool shellSysmon, bool sshSysmon);

    // 0x005284d6/0x00526ffa：解析 vendor *.applet（顶层 "key: value" + "init: |-" 块标量），
    // 逐项转 QVariantMap 复用 populate（同工厂+runInit）。
    // shortcut: sysmon.applet 原文 JS 依赖 view.executeCommand/commandOutput/ready/disconnected
    // 桥——骨架 TerminalView 无此面，装载即 JS TypeError→qWarning；原生等效不实现（R55 指令，
    // executeCommand 桥逆明后接入）。
    void loadFiles(const QStringList &files, ScriptHost *host);

    // 0x0084a755 全序组合面：scheme import 列表→sysmon 开关过滤→KitPane_ensureAppletBar
    // →loadFiles。sysmon 键读 uiconfigs/session.config（vendor 默认 shell=true/ssh=false）。
    // 挂账：调用点=pane 会话类型切换异步链，骨架未建（无 per-pane session 上下文）；
    // scheme 名未接入（scheme 切换点挂账）→imports 现恒空。
    void loadForPane(const QString &paneName, ScriptHost *host, KitPane *pane);
};

// 0x005bf49e KitPane_ensureAppletBar：在 pane 子树找既有 AppletBar（无名 findChild），
// 无则 pane layout() dynamic_cast<QVBoxLayout>→new AppletBar(pane)+addWidget(stretch 0)；
// 已存在或无 QVBoxLayout→返回既有或 nullptr。定义在 KitPane.cpp（R55 段）。
AppletBar *KitPane_ensureAppletBar(KitPane *pane);
