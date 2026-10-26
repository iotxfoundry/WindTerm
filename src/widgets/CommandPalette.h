// CommandPalette — 命令面板（P3，深逆批 2026-10-24）。
// 原版 QFrame 弹层：ctor 0x5403f6（objectName/非模态 WA_DeleteOnClose/Frame
// StyledPanel(6)+Sunken(0x30)/autoFillBackground(false)/+0x60 焦点快照）、
// 布局 0x53e936（searchEdit+CountLabel+BackwardButton+ListView）、
// textChanged 前缀路由 0x54334c/0x5431c6（">"=mode1 全部 action、"m"=mode2
// mux/tmux 词过滤、默认 mode3 Anything——mode4/5/6/7 前缀字符 DAT 常量读不出，不实现挂账）、
// 数据源 0x541896 actionid_to_menu_title（菜单标题+text 剥 "&(?!&)"）、
// 过滤 0x583e8e/0x664cd0（整串全匹配+compare 打分排序——打分公式未逐行逆明，简化挂账）、
// 键盘 0x5436ce（ListView Esc→close）/0x53e2f0（focusChanged 焦点离开 close）、
// 焦点还原 0x53e3e4、历史栈 0x53fd52（重建无子菜单下钻——栈结构保留仅一层）、
// 执行分派 0x5436e2 kind 表（重建项恒 kind1=action → QAction::activate(Trigger)；
// kind3 会话部件 0x5b91a8/kind5 文本回填无数据源——挂账）。
// 简化挂账：原版 CommandListModel+QSortFilterProxyModel（proxy invalidate/取前 N）简化为
// 单 QStandardItemModel 直接重建；BackwardButton 原版嵌在 SearchEdit 内部 hbox——骨架平铺 HBox。
#pragma once

#include <QFrame>
#include <QPointer>
#include <QString>
#include <functional>

#ifdef WINDTERM_HAVE_QJSENGINE
#include <QJSValue>
#include <QVariantList>
#include <QVariantMap>
#endif

class QCloseEvent;
class QEvent;
class QLabel;
class QLineEdit;
class QListView;
class QAction;
class QStandardItemModel;
class QJSEngine;

class CommandPalette : public QFrame
{
    Q_OBJECT

public:
    // actionId → 接线好的 QAction（原版 actionFactory_getOrCreate 0x665dc2 共享缓存——
    // 骨架经 MainWindow::makeAction 临时新建，激活即弃）
    using ActionFactory = std::function<QAction *(const QString &actionId)>;

    // palette JS 宿主注入（0x54334c mode7 script_fireEvent 链：panel 脚本经
    // scriptHost.evaluate 求值；MainWindow 传入共享 ScriptHost 的引擎——QJSValue 跨引擎禁用）
    void setScriptHost(class ScriptHost *host);

    explicit CommandPalette(ActionFactory factory, QWidget *parent = nullptr);

    // 0x53fc54 open：清历史+基准 mode3+prefix 末字符字母数字补空格+设初值（触发路由链）
    void open(const QString &prefix);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void showEvent(QShowEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    void buildUi();                                 // 0x53e936
    void onTextChanged(const QString &text);        // 0x54334c
    void switchMode(int mode, const QString &text); // 0x542e86
    void buildList(const QStringList &idWords);     // 0x541896 actionid_to_menu_title
    void applyFilter();                             // 0x583e8e/0x664cd0 简化
    void goBack();                                  // 0x53fd52
    void dispatch(const class QModelIndex &index);  // 0x5436e2
    void reposition();                              // 0x5401d6 宽 44% 居中贴上缘
#ifdef WINDTERM_HAVE_QJSENGINE
    // ═══ mode7 palette 文件模式（global/palettes/*.palette 一手证据；深逆 0x54334c
    // filterEvent JS 分支 + script_fireEvent kind7——前缀字符 DAT 未逆的 mode7 即此链）═══
public:
    struct PaletteDef
    {
        QString trigger;
        bool filterable = false;
        QStringList events;   // "enterEvent, leaveEvent, …" 逗号表
        QJSValue script;      // evaluate 缓存（可调用）；事件时 call(event, filter, selection)
    };

private:
    void loadPalettes(); // global/palettes/*.palette 扫描（数据文件一手证据，骨架 assets 同名目录）
    PaletteDef *paletteMatch(const QString &text) const; // trigger 前缀路由
    void enterPalette(PaletteDef &def, const QString &filter);   // enterEvent→items
    void runPaletteEvent(const QString &event, const QString &filter);  // filter/leave/commit 分发
    void setItemsFromJs(const QJSValue &items); // items[{title,subtitle,icon}]→model（kind7）

    ScriptHost *m_scriptHost = nullptr;
    QVector<PaletteDef> m_palettes;
    PaletteDef *m_activePalette = nullptr; // 当前 palette 模式（mode7 等效，+0x70 表另路）
#endif

    ActionFactory m_factory;
    QLineEdit *m_searchEdit = nullptr;
    QLabel *m_countLabel = nullptr;
    class QPushButton *m_backwardButton = nullptr;
    QListView *m_listView = nullptr;
    QStandardItemModel *m_model = nullptr;

    // 历史栈（0x53fd52 {model,text,item,mode}——骨架单模型，栈存全量条目快照，仅一层）
    struct HistoryEntry
    {
        QStringList ids;
        QStringList texts;
        QString text;
        int mode = 0;
    };
    QVector<HistoryEntry> m_history;
    QStringList m_fullIds;    // 当前模式全量条目（原 CommandListModel 内容）
    QStringList m_fullTexts;
    QString m_filterText;     // listView filter +0x40 缓存（0x5836a6）
    int m_mode = 0;           // +0x70
    int m_baseMode = 0;       // +0x71
    int m_maxRows = 9;        // ListView 行上限（构造设 9，原 setter 0x583b8a 夹 1..9）
    QPointer<QWidget> m_focusSnapshot; // +0x60：打开时 focusWidget 快照
};
