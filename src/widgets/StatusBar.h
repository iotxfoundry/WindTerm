#pragma once

#include <QStatusBar>
#include <QVariantList>

class QLabel;
class ScriptHost;

// 原版 StatusBar（QStatusBar 子类→注册名 AppletBar，0x005a2d26 ctor / 0x00526a7c 改名；
// 0x00692766 KitWindow 装配点）：ctor setSizeGripEnabled(false)+setContentsMargins(字体 pt,0,pt,0)；
// 内容=常驻状态文本 label（insertPermanentWidget(0,stretch=1) 最左）+ statusbar.config applets
// （0x005a4432 applet_layout_widgets 真跑 JS init，QJSEngine 宿主 0x0064b102）。
class StatusBar : public QStatusBar
{
    Q_OBJECT

public:
    explicit StatusBar(QWidget *parent = nullptr);

    // 0x005a2e58 showMessageEx：设常驻文本 + timeout QTimer 超时恢复默认文本；
    // messageLevel 动态属性挂账（QSS QStatusBar[messageLevel=...] 规则，颜色刷新链未逆明）
    void showMessageEx(const QString &text, int timeoutMs = 0);

    // 0x005a4432/0x005a333e：setUpdatesEnabled(false/true) 包裹；逐项 toMap 按 type 分派：
    // button→QToolButton(TextOnly+AutoRaise, 无 objectName)；label→QLabel(InteractionFlags
    // TextSelectableByMouse|LinksAccessibleByMouse|LinksAccessibleByKeyboard + OpenExternalLinks
    // + PointingHandCursor)；progressBar/slider 无实现（原版仅比较）；addPermanentWidget(w,0)；
    // 然后 host->runInit(w, map["init"])（0x005a3156）
    void populate(const QVariantList &applets, ScriptHost *host);

private:
    QLabel *m_statusLabel = nullptr;   // 0x5a2e58 常驻状态文本 label（sb+0x30）
    QString m_defaultStatusText;       // 超时恢复文本（0x5a2e32：空→tr("Ready") 0xc8b211）
    class QTimer *m_messageTimer = nullptr;
};
