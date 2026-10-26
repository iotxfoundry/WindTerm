#include "AppletBar.h"

#include <QDir>
#include <QFile>
#include <QRegularExpression>

#include "core/Assets.h"
#include "core/LocaleManager.h"
#include "core/ScriptHost.h"

// 0x00526a7c AppletBar_setObjectName：基类 StatusBar_ctor（名 "StatusBar"+sizeGrip off+
// contentsMargins）→改 objectName "AppletBar"→setWindowTitle(King_title 0x008a1106→"Applet Bar"）
AppletBar::AppletBar(QWidget *parent)
    : StatusBar(parent)
{
    setObjectName(QStringLiteral("AppletBar"));
    setWindowTitle(LocaleManager::instance().tr(QStringLiteral("Applet Bar")));
}

// 0x0084a755 首段 FUN_005b97cc 语义（scheme→.appletbar import 列表）：vendor 实文
// terminal/schemes/<scheme>/<scheme>.appletbar="import:" 下 YAML 列表项。skeleton assets
// 无 schemes/（scheme 体系未建）→文件不存在恒空=AppletBar 空态（R55 指令）。
QStringList AppletBar::schemeAppletbarImports(const QString &schemeName)
{
    if (schemeName.isEmpty())
        return {};
    QFile file(Assets::dir() + QStringLiteral("/terminal/schemes/%1/%1.appletbar").arg(schemeName));
    if (!file.open(QIODevice::ReadOnly))
        return {};
    QStringList files;
    const QRegularExpression item(QStringLiteral("^\\s*-\\s*(\\S+)"));
    // 轻量行解析（非严格 YAML；原版经 YAML 节点表——格式面同 vendor 实文）
    for (const QByteArray &line : file.readAll().split('\n')) {
        const auto m = item.match(QString::fromUtf8(line));
        if (m.hasMatch())
            files.append(m.captured(1));
    }
    return files;
}

// 0x0084a755 中段（0084a86f 分派+0084a8d5 逆序循环 QString::indexOf("sysmon")!=-1 删）：
// Shell→shell.sysmon / SSH→ssh.sysmon；false→逆序剔除含 "sysmon" 的项；其余 pane 名不触碰
// （cVar4 未赋值即跳过剔除段）。开关值读 uiconfigs/session.config（vendor 默认 true/false）。
QStringList AppletBar::filterPaneApplets(const QStringList &files, const QString &paneName,
                                         bool shellSysmon, bool sshSysmon)
{
    bool enabled;
    if (paneName == QLatin1String("Shell"))
        enabled = shellSysmon;
    else if (paneName == QLatin1String("SSH"))
        enabled = sshSysmon;
    else
        return files;
    if (enabled)
        return files;
    QStringList out = files;
    for (int i = out.size() - 1; i >= 0; --i) // 逆序（原版 do-while 自尾向首）
        if (out.at(i).contains(QLatin1String("sysmon")))
            out.removeAt(i);
    return out;
}

// 0x005284d6 appletbar_loadFiles：逐文件相对路径→FUN_00526be0 <appDir>/terminal/applets/
// 前缀拼接→0x00526ffa applet_load_script_info 取 name/uuid/type/init→同 statusbar 条目
// populate 路径（addPermanentWidget+runInit）。
void AppletBar::loadFiles(const QStringList &files, ScriptHost *host)
{
    QVariantList applets;
    const QString root = Assets::dir() + QStringLiteral("/terminal/applets/");
    for (const QString &f : files) {
        // 0x0052844b QDir::isRelativePath→前缀拼接；绝对路径原样
        const QString path = QDir::isRelativePath(f) ? root + f : f;
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly))
            continue;
        // applet 文件=顶层 "key: value" 行 + "init: |-" 块标量（缩进体）。骨架自产面：
        // 仅提取本表用到的键（原版 QYAML 节点表 0x00526ffa 全键；name/uuid 骨架未消费）
        QString type, init;
        bool inInit = false;
        for (const QByteArray &raw : file.readAll().split('\n')) {
            const QString line = QString::fromUtf8(raw).remove('\r');
            if (inInit) {
                if (line.startsWith(QLatin1String("  ")) || line.isEmpty())
                    init += line + QLatin1Char('\n');
                else
                    inInit = false;
            } else if (line.startsWith(QLatin1String("init:"))) {
                inInit = true;
                init = line.mid(5).remove(QStringLiteral("|-")).trimmed();
            } else if (line.startsWith(QLatin1String("type:"))) {
                type = line.mid(5).trimmed();
            }
        }
        if (type.isEmpty())
            continue;
        QVariantMap map;
        map.insert(QStringLiteral("type"), type);
        map.insert(QStringLiteral("init"), init.trimmed());
        applets.append(map);
    }
    populate(applets, host); // 同 0x005a4432 工厂+0x005a3156 runInit 链
}

// 0x0084a755 pane_sysmon_applet_load 全序：scheme import 列表→sysmon 开关过滤（shell/ssh
// 键，uiconfigs/session.config vendor 默认 shell=true/ssh=false）→KitPane_ensureAppletBar
// →appletbar_loadFiles。原版由 pane 会话类型切换异步触发（functor deleteLater 收尾）；
// 骨架调用点未建（无 per-pane session 切换链）——同步面供测试与后续接线。
void AppletBar::loadForPane(const QString &paneName, ScriptHost *host, KitPane *pane)
{
    // 开关门读 session.config（uiconfigs vendor 原文 37/47 行：shell.sysmon=true/ssh.sysmon=false）
    const auto readSwitch = [this](const char *key) {
        QFile f(Assets::dir() + QStringLiteral("/config/uiconfigs/session.config"));
        if (!f.open(QIODevice::ReadOnly))
            return true; // 原版读不到=默认 true（0084a88f cVar4 赋值路径）
        // 非严格 JSON（BOM/注释容错走 stripLineComments 同表）；轻量文本查找键
        for (const QByteArray &line : f.readAll().split('\n'))
            if (line.contains(key)) {
                const QString s = QString::fromUtf8(line);
                return !s.contains(QLatin1String("false"));
            }
        return true;
    };
    QStringList files = schemeAppletbarImports(QString());
    // scheme 名未接入（切换点挂账，skeleton assets 无 schemes/）——恒空；开关门+ensure+loadFiles
    // 全序保留（0x0084a755 静态结构），数据接通后自动生效
    files = filterPaneApplets(files, paneName, readSwitch("shell.sysmon"), readSwitch("ssh.sysmon"));
    if (files.isEmpty())
        return; // 0x0084a98d uVar9!=uVar8 空表不建 AppletBar
    if (pane) {
        if (AppletBar *bar = KitPane_ensureAppletBar(pane))
            bar->loadFiles(files, host);
        return;
    }
    loadFiles(files, host);
}

// 0x005bf49e KitPane_ensureAppletBar：qFindChild_helper（空名 AppletBar 类型）找既有；
// 无→layout() dynamic_cast<QVBoxLayout>→new AppletBar(pane)+addWidget(bar,0)。
// 函数在 KitPane.cpp（R55 段）——桩此处不定义（链接面声明于头，实现附 KitPane.cpp 尾）。
