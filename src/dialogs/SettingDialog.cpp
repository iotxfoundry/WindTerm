#include "SettingDialog.h"

#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QDir>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QFrame>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGuiApplication>
#include <QHash>
#include <QScreen>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <functional>

#include "core/Assets.h"
#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "core/WindConfig.h"

// ═══ R51 深逆照搬（reference/full/decomp-part-0022.c；地址=0x 前缀）═══
// 0x006ea66e SettingDialog_ctor：QDialog(parent)→setWindowTitle(tr("Settings"))
//   （"Editor"→"Editor Settings" 0xc9f06b / "Terminal"→"Terminal Settings" 0xc9f07b /
//   其余→"Settings" 0xc9f084——window_name_strip 0x8c9e64 剥 "Window" 后传页名）
//   →setAttribute(0x37=WA_DeleteOnClose)→0x006ea37a buildUi→0x006dd310(buttonBox rejected→reject)。
// 0x006ea37a：QVBox[H[tree | stack] ‖ H[QLabel | buttonBox]]；
//   提示 QLabel = "<font color=\"darkorange\">" + "* " + tr("Requires a restart to take affect")
//   + "</font>"（0xc9f968/0xc9f003/0xc9d328 三段拼接）；
//   0x75c132 dialog_min_size_fix(0.45, 0.75)=min 屏 45%×75%+setSizeGripEnabled。
// 【证据修正挂账】R51 任务书"顶部搜索 QLineEdit"：0x006ea37a 反编译体无 QLineEdit/前缀图标——
//   实为 hint QLabel（darkorange=标签色非图标色）。搜索过滤链 0x006f5b42/0x6f60a8 归属
//   TabBar 型设置对话框（0x6f2036/0x6f2852），非本页树对话框。骨架按反汇编事实实现，
//   不实现任务书搜索框；若后续汇编复核出搜索框（calls-with-receivers 复核 0x6ea37a）再补。

namespace {

// tr key 复用 LocaleManager（en 原文=二进制 tr 表原文，0x 地址注释逐条挂）
QString tr(const char *en)
{
    return LocaleManager::instance().tr(QString::fromLatin1(en));
}

QWidget *categoryPage(const QString &path)
{
    // CategoryPage（0x6dfdc4/0x6dfa34 段 vtable 装配）：QWidget+页键(+0x30)
    auto *page = new QWidget;
    page->setProperty("categoryPath", path); // 0x006e995f setData(0x101)=页键（settings_tree_populate）
    auto *layout = new QVBoxLayout(page);
    layout->setContentsMargins(12, 12, 12, 12); // 0x6e46b4 style 常数近似（QStyle PM_*)
    return page;
}

QGroupBox *formGroup(const QString &title, QFormLayout **form, QWidget *parent)
{
    // 0x6dfa87/0x6dfe2a 段：QGroupBox(tr 标题, page)+QFormLayout 结构
    auto *group = new QGroupBox(title, parent);
    auto *f = new QFormLayout(group);
    f->setLabelAlignment(Qt::AlignRight); // 0x006e9515 setLabelAlignment(2=AlignRight)
    *form = f;
    return group;
}

// 0x006dcb1e settings_checkbox_create：QCheckBox+setText+读键 toBool+setChecked
//   +stateChanged→写回键（0x006e6fe1→startup_session_launch(param_4==0)→0x008cbb2e 键写回）
QCheckBox *boundCheckbox(const QString &label, const QString &key, QWidget *parent)
{
    auto *box = new QCheckBox(label, parent);
    box->setChecked(WindConfig::instance().valueToBool(key,
        key == QStringLiteral("terminal.mouseTracking.rightClick") ? false : true));
    // 缺省按 wind.config 实键值域（terminal.mouseTracking.rightClick=false 其余 true，
    // assets/config/wind.config:60-65）；非鼠键缺省走 toBool 默认 false 与 QVariant::toBool 一致
    QObject::connect(box, &QCheckBox::stateChanged, box, [box, key](int state) {
        WindConfig::instance().setValue(key, bool(state == Qt::Checked)); // bool 写回（int 2 态）
    });
    return box;
}

// 0x006dcc80 s_terminal_autoComplete_preselectBestM_6dcc80（settings_combo_create）：
//   建 combo（按页键读初值）+activated→写回（0x006e7056 段 connectImpl QComboBox::activated）
QComboBox *boundCombo(const QString &key, QWidget *parent)
{
    auto *combo = new QComboBox(parent);
    combo->setProperty("windKey", key); // 测试按键名取控件
    const QString current = WindConfig::instance().valueToString(key);
    if (!current.isEmpty())
        combo->setCurrentText(current); // 0x006dcd6c settings_get_string_value 初值
    QObject::connect(combo, QOverload<int>::of(&QComboBox::activated), combo,
                     [combo, key](int index) {
        WindConfig::instance().setValue(key, combo->itemData(index).toString());
    });
    return combo;
}

// 0x006dd348 settings_add_doublespinbox：QDoubleSpinBox+读键 toDouble+setValue
//   +valueChanged→写回（0x006e7421 段 connectImpl QDoubleSpinBox::valueChanged）
QDoubleSpinBox *boundDoubleSpin(const QString &key, double min, double max, double step,
                                QWidget *parent)
{
    auto *spin = new QDoubleSpinBox(parent);
    spin->setRange(min, max);          // 0x006dd348 setMinimum/Maximum
    spin->setAccelerated(true);        // 0x006dd3e8 setAccelerated
    spin->setSingleStep(step);         // 0x006e471c setSingleStep
    spin->setValue(WindConfig::instance().valueToDouble(key));
    QObject::connect(spin, qOverload<double>(&QDoubleSpinBox::valueChanged), spin,
                     [spin, key](double v) { WindConfig::instance().setValue(key, v); });
    return spin;
}

void addComboItem(QComboBox *combo, const QString &text, const QString &data)
{
    // 0x006dd7c7 combobox_insert_item(count(), tr(text), QVariant(data))
    combo->addItem(text, data);
}

} // namespace

SettingDialog::SettingDialog(QWidget *parent)
    : QDialog(parent)
{
    // 0x006ea66e：标题 tr（骨架顶层入口不传页名 → "Settings" 0xc9f084 分支）
    setWindowTitle(tr("Settings"));
    setAttribute(Qt::WA_DeleteOnClose); // 0x006ea72b setAttribute(0x37)

    // 0x006ea37a buildUi：外层 QVBox；H[tree | stack]=stretch 行；H[hint | buttonBox]
    m_tree = new QTreeWidget(this);
    // 0x006e9d2b 段 CategoryTree：FrameShape(0=NoFrame)+EditTriggers(0 不可编辑)
    //   +ExpandsOnDoubleClick(false)+SelectionMode(1 单选)
    m_tree->setFrameShape(QFrame::NoFrame);
    m_tree->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tree->setExpandsOnDoubleClick(false);
    m_tree->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tree->setHeaderHidden(true); // 0x0058c362 s_TreeView param_2 分支 setHeaderHidden
    m_tree->setRootIsDecorated(false);

    m_stack = new QStackedWidget(this);

    // 0x006e9cd8 settings_category_tree_create 页树照建（嵌套=Editor[Text(7),Widgets(2)]）：
    //   Application/Appearance/Editor[Text(Binary,Caret,Font,Highlight,Indentation,Line Ending,Wrap),
    //   Widgets(Filer,Quick Bar)]/Proxy/Search/Security/Tabs/Terminal[Auto Completion,
    //   Command History,Mouse Tracking]
    // settings_tree_populate 0x006e97f0：QVariant 列表递归（10=串建项/9=列表下钻）
    struct Node
    {
        const char *title;
        const QVector<Node> *children;
    };
    const QVector<Node> textChildren = {
        {"Binary", nullptr}, {"Caret", nullptr}, {"Font", nullptr}, {"Highlight", nullptr},
        {"Indentation", nullptr}, {"Line Ending", nullptr}, {"Wrap", nullptr}};
    const QVector<Node> widgetsChildren = {{"Filer", nullptr}, {"Quick Bar", nullptr}};
    const QVector<Node> editorChildren = {{"Text", &textChildren}, {"Widgets", &widgetsChildren}};
    const QVector<Node> terminalChildren = {{"Auto Completion", nullptr},
                                            {"Command History", nullptr},
                                            {"Mouse Tracking", nullptr}};
    const QVector<Node> pages = {
        {"Application", nullptr}, {"Appearance", nullptr}, {"Editor", &editorChildren},
        {"Proxy", nullptr},       {"Search", nullptr},     {"Security", nullptr},
        {"Tabs", nullptr},        {"Terminal", &terminalChildren}};

    // 实页装配（其余=占位 QWidget，不接数据不算挂账错——分批补）
    const QHash<QString, QWidget *> realPages = {
        {QStringLiteral("Application"), createApplicationPage()},
        {QStringLiteral("Appearance"), createAppearancePage()},
        {QStringLiteral("Proxy"), createProxyPage()},
        {QStringLiteral("Tabs"), createTabsPage()},
        {QStringLiteral("Terminal>Mouse Tracking"), createTerminalPage()},
    };

    // settings_tree_populate 0x006e97f0：QVariant 列表递归（10=串建项/9=列表下钻）
    std::function<void(const QVector<Node> &, QTreeWidgetItem *)> populate =
        [&](const QVector<Node> &nodes, QTreeWidgetItem *parent) {
            for (const Node &n : nodes) {
                QString path = parent
                    ? parent->data(0, Qt::UserRole).toString() + QStringLiteral(">") +
                          QString::fromLatin1(n.title)
                    : QString::fromLatin1(n.title);
                QTreeWidgetItem *item = new QTreeWidgetItem({tr(n.title)});
                item->setData(0, Qt::UserRole, path); // 0x006e995f setData(0x101)=页键
                (parent ? parent : m_tree->invisibleRootItem())->addChild(item);
                m_stack->addWidget(realPages.value(path, createPlaceholderPage(path)));
                if (n.children) {
                    populate(*n.children, item);
                    item->setExpanded(true); // 0x006ea1a3 expandAll
                }
            }
        };
    populate(pages, nullptr);

    auto *midRow = new QHBoxLayout;
    midRow->addWidget(m_tree, 1); // 0x006ea5b5 addWidget(tree,1)
    midRow->addWidget(m_stack, 2); // 0x006ea5bd addWidget(stack,2)

    // 提示 QLabel："<font color=\"darkorange\">" + "* " + tr + "</font>"（0x006ea492 段三段拼接）
    auto *hint = new QLabel(QStringLiteral("<font color=\"darkorange\">* ") +
                                tr("Requires a restart to take affect") +
                                QStringLiteral("</font>"),
                            this);

    auto *buttonBox = new QDialogButtonBox(QDialogButtonBox::Close, this);
    // 0x006ea541 QDialogButtonBox(0x200000=Close)+0x006ea57e setText(tr("Close") 0xc89b49)
    buttonBox->button(QDialogButtonBox::Close)->setText(tr("Close"));
    // 0x006dd310：buttonBox rejected→dialog reject
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *bottomRow = new QHBoxLayout;
    bottomRow->addWidget(hint, 1);      // 0x006ea5c5 addWidget(hint,0)——hint 占 stretch 位
    bottomRow->addWidget(buttonBox, 0); // 0x006ea5cd addWidget(buttonBox,0)

    auto *root = new QVBoxLayout(this);
    root->addLayout(midRow, 1);
    root->addLayout(bottomRow, 0);

    // 选中树项→stack 切页（0x006ebcc6 currentChanged→0x006e462a 取页键→0x006eb952 切栈）
    connect(m_tree, &QTreeWidget::currentItemChanged, this,
            [this](QTreeWidgetItem *cur, QTreeWidgetItem *) {
                if (cur)
                    switchPage(cur->data(0, Qt::UserRole).toString());
            });
    connect(m_tree, &QTreeWidget::itemActivated, this,
            [this](QTreeWidgetItem *item, int) {
                if (item)
                    switchPage(item->data(0, Qt::UserRole).toString());
            });

    // 0x006ea6db dialog_min_size_fix(0.45, 0.75)：min=屏 45%×75%
    const QScreen *screen = QGuiApplication::primaryScreen();
    const QSize size = screen ? screen->availableGeometry().size() : QSize(1280, 800);
    setMinimumWidth(int(size.width() * 0.45));
    setMinimumHeight(int(size.height() * 0.75));
    setSizeGripEnabled(true); // 0x0075c13a QDialog::setSizeGripEnabled

    m_tree->setCurrentItem(m_tree->topLevelItem(0)); // 初选 Application（0x006f5e88 段 item(0) 选中链）
}

void SettingDialog::open(QWidget *parent)
{
    // 0x008cc4a0：heap new+WA_DeleteOnClose（ctor 已设）→模态 exec（Close→reject 关闭即删）
    auto *dlg = new SettingDialog(parent);
    dlg->setAttribute(Qt::WA_DeleteOnClose);
    dlg->setWindowModality(Qt::ApplicationModal);
    dlg->exec();
}

void SettingDialog::switchPage(const QString &path)
{
    // 0x006eb952 panes_switchToWidget：按页键切栈
    for (int i = 0; i < m_stack->count(); ++i) {
        if (m_stack->widget(i)->property("categoryPath").toString() == path) {
            m_stack->setCurrentIndex(i);
            return;
        }
    }
}

QWidget *SettingDialog::createApplicationPage()
{
    // 0x006e912e s_application_language_6e912e：QGroupBox("Application" 0xca04b0)+
    //   [language combo(&Language: 0xc9eff8) | themeGui combo(&Theme: 0xc9f006，
    //   0x0075db80 枚举 themes 目录) | windowOpacity DSpin(0.1..1.0 step0.01)]，Form AlignRight
    auto *page = categoryPage(QStringLiteral("Application"));
    QFormLayout *form = nullptr;
    auto *group = formGroup(tr("Application"), &form, page);
    form->addRow(tr("&Language:"), boundCombo(QStringLiteral("application.language"), group));
    form->addRow(tr("&Theme:"), createThemeCombo(group)); // themeGui combo 在本页（0x006e93dc）
    form->addRow(tr("&Window opacity:"), boundDoubleSpin(QStringLiteral("application.windowOpacity"),
                                                         0.1, 1.0, 0.01, group));
    page->layout()->addWidget(group);
    return page;
}

QWidget *SettingDialog::createAppearancePage()
{
    // 0x006e93dc 段（Application 页内 &Theme: 行）：themes 目录枚举（0x0075db80→0x00753fc6
    //   entryList themes/+"default" 补位）；选择→Theme_loadGuiTheme 0x007567dc（含主题变更才 reload）
    //   →setStyleSheet。骨架复用 ThemeManager 同链。
    auto *page = categoryPage(QStringLiteral("Appearance"));
    QFormLayout *form = nullptr;
    auto *group = formGroup(tr("Appearance"), &form, page);
    auto *combo = createThemeCombo(group);
    form->addRow(tr("&Theme:"), combo);
    page->layout()->addWidget(group);
    return page;
}

QComboBox *SettingDialog::createThemeCombo(QWidget *parent)
{
    // 0x00753fc6：QDir(exeDir+"/../global/themes/")entryList(Dirs)+补 "default" 去重
    auto *combo = new QComboBox(parent);
    QDir themes(Assets::dir() + QStringLiteral("/themes"));
    QStringList names = themes.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    if (!names.contains(QStringLiteral("default")))
        names.prepend(QStringLiteral("default")); // 0x007540c2 补位 default
    for (const QString &name : names)
        combo->addItem(name, name);
    combo->setCurrentText(WindConfig::instance().valueToString(QStringLiteral("application.themeGui"),
                                                               QStringLiteral("dige-black")));
    // 选择→写键+即时应用（0x007567dc 主题变更才 load+setStyleSheet——骨架 ThemeManager 同链）
    connect(combo, QOverload<int>::of(&QComboBox::activated), combo, [combo](int index) {
        const QString name = combo->itemData(index).toString();
        WindConfig::instance().setValue(QStringLiteral("application.themeGui"), name);
        ThemeManager &tm = ThemeManager::instance();
        if (tm.currentTheme() != name && tm.loadTheme(name))
            tm.apply();
    });
    return combo;
}

QWidget *SettingDialog::createProxyPage()
{
    // 0x006dd770 s_application_proxy：application.proxy combo
    //   [None→"No proxy"/System→"System proxy"/Http→"Http proxy"/Socks5→"Socks v5 proxy"]+
    //   0x0084? 段 proxyDns checkbox（0x006e8785 settings_checkbox_create proxyDns）
    auto *page = categoryPage(QStringLiteral("Proxy"));
    QFormLayout *form = nullptr;
    auto *group = formGroup(tr("Proxy Settings"), &form, page); // 0xc9e603
    auto *combo = boundCombo(QStringLiteral("application.proxy"), group);
    addComboItem(combo, tr("No proxy"), QStringLiteral("None"));         // 0x006dd7c7
    addComboItem(combo, tr("System proxy"), QStringLiteral("System"));   // 0x006dd810
    addComboItem(combo, tr("Http proxy"), QStringLiteral("Http"));       // 0x006dd859
    addComboItem(combo, tr("Socks v5 proxy"), QStringLiteral("Socks5")); // 0x006dd8a2
    form->addRow(tr("Proxy &Type:"), combo); // 0xc9e5f8
    // 0x006e8785：proxyDns checkbox（"Proxy DNS" 行）
    form->addRow(boundCheckbox(tr("Proxy DNS"), QStringLiteral("application.proxyDns"), group));
    page->layout()->addWidget(group);
    return page;
}

QWidget *SettingDialog::createTabsPage()
{
    // 0x006e4dbe s_tabbar_selectionBehaviorOnRemove_6e4dbe（Tabs 页）：
    //   GroupBox("Tab Features" 0xc9ed86)+QFormLayout：
    //   hoverToSelect DSpin(0..60, "Activate the tab after &hovering:" 0xc9f8f0, suffix seconds
    //   0xca0a18+step1 0x3fb999999999999a special "Never" 0xc9ee54)；
    //   showSequenceNumbers combo("&Show the tab number on tabs:" 0xc9ed93；
    //   None/FirstNine/All→tr "None tabs"/"First nine tabs"/"All tabs" 0xc9edf3/fd/0d)；
    //   textElideMode combo("Tab text &elide mode:" 0xc9ee5f；Qt::TextElideMode 枚举键
    //   ElideLeft/Middle/Right/None→"No elide" 0xc9ee24/2d/38/45)
    auto *page = categoryPage(QStringLiteral("Tabs"));
    QFormLayout *form = nullptr;
    auto *group = formGroup(tr("Tab Features"), &form, page);

    auto *hover = boundDoubleSpin(QStringLiteral("tabbar.hoverToSelect"), 0.0, 60.0, 1.0, group);
    hover->setSuffix(QStringLiteral(" seconds")); // 0x006e560f FUN_006e471c suffix
    hover->setSpecialValueText(tr("Never"));      // 0x006e5654 specialValueText（0=关闭）
    form->addRow(tr("Activate the tab after &hovering:"), hover);

    auto *seq = boundCombo(QStringLiteral("tabbar.showSequenceNumbers"), group);
    addComboItem(seq, tr("None tabs"), QStringLiteral("None"));             // 0x006e518d
    addComboItem(seq, tr("First nine tabs"), QStringLiteral("FirstNine"));  // 0x006e51e5
    addComboItem(seq, tr("All tabs"), QStringLiteral("All"));               // 0x006e523d
    form->addRow(tr("&Show the tab number on tabs:"), seq);

    auto *elide = boundCombo(QStringLiteral("tabbar.textElideMode"), group);
    addComboItem(elide, tr("No elide"), QStringLiteral("ElideNone"));    // 0x006e52f3
    addComboItem(elide, tr("Elide left"), QStringLiteral("ElideLeft"));  // 0x006e5374
    addComboItem(elide, tr("Elide middle"), QStringLiteral("ElideMiddle")); // 0x006e53f8
    addComboItem(elide, tr("Elide right"), QStringLiteral("ElideRight"));   // 0x006e547c
    form->addRow(tr("Tab text &elide mode:"), elide);

    page->layout()->addWidget(group);
    return page;
}

QWidget *SettingDialog::createTerminalPage()
{
    // 0x006dfa0e s_terminal_mouseTracking_doubleClick_6dfa0e（Terminal>Mouse Tracking 子页）：
    //   GroupBox("Tracking Events" 0xc9e7fb)+QFormLayout 六 checkbox（move/wheel/click/
    //   doubleClick/middleClick/rightClick 0xc9e80b..59）——terminal.mouseTracking.* 全六键
    auto *page = categoryPage(QStringLiteral("Terminal>Mouse Tracking"));
    QFormLayout *form = nullptr;
    auto *group = formGroup(tr("Tracking Events"), &form, page);
    form->addRow(boundCheckbox(tr("&Move event"), QStringLiteral("terminal.mouseTracking.move"), group));
    form->addRow(boundCheckbox(tr("&Wheel event"), QStringLiteral("terminal.mouseTracking.wheel"), group));
    form->addRow(boundCheckbox(tr("&Click event"), QStringLiteral("terminal.mouseTracking.click"), group));
    form->addRow(boundCheckbox(tr("&Double click event"),
                               QStringLiteral("terminal.mouseTracking.doubleClick"), group));
    form->addRow(boundCheckbox(tr("&Middle click event"),
                               QStringLiteral("terminal.mouseTracking.middleClick"), group));
    form->addRow(boundCheckbox(tr("&Right click event"),
                               QStringLiteral("terminal.mouseTracking.rightClick"), group));
    page->layout()->addWidget(group);
    return page;
}

QWidget *SettingDialog::createPlaceholderPage(const QString &path)
{
    // 未逆明页占位（分批补——Editor/Text 子页 0x6e4798 族、Search/Security/Terminal 主页等）
    auto *page = new QWidget;
    page->setProperty("categoryPath", path);
    auto *layout = new QVBoxLayout(page);
    layout->addWidget(new QLabel(tr("Not implemented yet"), page));
    layout->addStretch();
    return page;
}

