#pragma once

#include <QDialog>

class QComboBox;
class QStackedWidget;
class QTreeWidget;

// R51 设置中心（0x006ea66e SettingDialog_ctor / 0x006ea37a buildUi / 0x006e9cd8 页树，
// docs/cracked-rules.md R51）：
// QVBox[H[CategoryTree(NoFrame/单选/不可编辑) | QStackedWidget]
//      ‖ H[提示 QLabel(暗橙 "* Requires a restart to take affect") | QDialogButtonBox(Close→reject)]]；
// min=屏 45%×75%（0x75c132 dialog_min_size_fix 0.45/0.75）；WA_DeleteOnClose(attr 0x37)。
class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    // 0x008cc4a0 openSettings 链：new SettingDialog→WA_DeleteOnClose→QTimer::singleShot(0) 后 exec 归属
    // 主 agent 接线 window.openSettings；此处仅提供静态入口（模态 exec，Close→reject）
    static void open(QWidget *parent = nullptr);

    explicit SettingDialog(QWidget *parent = nullptr);

private slots:
    void switchPage(const QString &path);

private:
    QWidget *createApplicationPage();   // 0x006e912e
    QComboBox *createThemeCombo(QWidget *parent); // 0x006e93dc 段（0x0075db80 枚举+即时应用）
    QWidget *createAppearancePage();    // themeGui combo（0x006e93dc 段）
    QWidget *createProxyPage();         // 0x006dd770/0x006dd0cc 段（简化实页）
    QWidget *createTabsPage();          // 0x006e4dbe
    QWidget *createTerminalPage();      // 0x006dfa0e（Mouse Tracking 子页）
    QWidget *createPlaceholderPage(const QString &path);

    QTreeWidget *m_tree = nullptr;
    QStackedWidget *m_stack = nullptr;
};
