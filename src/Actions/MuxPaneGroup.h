#pragma once

#include <QWidget>

class TabGroup;
class MuxPaneView;
class QToolButton;
class QMenu;

// MuxPaneGroup —— 语料 QWidget 子类(Phase 4c mp2,W3 定案)。
// 语料落点:
//   ctor            s_MuxPaneGroup_8dece0(189B,decomp-part-0028.c:25950)
//   子件装配        s_tabbar_doubleClickAction_8de936(874B,0028:25835;
//                   名取自函数开头引用的全局设置,实际 = PaneGroup 装配)
//   六条接线        FUN_008de5a6(912B,0028:25740)
//   页挂 addTab     FUN_008de3e8(373B,0028:25642;this 形态 = MuxPaneGroup
//                   ——经 +0x38 TabGroup 槽操作,归属本类)
//   页拆 detachPane FUN_008dedae(62B,0028:25986;批 93 真身落码)
//   计数            FUN_008de59c(9B,0028:25972)→ FUN_005abbda
// 成员槽:+0x30 expandable(bool,构造点实证 0026:29939 传 1)/
//   +0x38 TabGroup*(objectName "PaneGroup")。
class MuxPaneGroup : public QWidget {
    Q_OBJECT

public:
    MuxPaneGroup(bool expandable, QWidget *parent);      // s_MuxPaneGroup_8dece0(param_2=expandable)

    void addTab(MuxPaneView *page, bool normal);         // FUN_008de3e8
    void detachPane(MuxPaneView *page);                  // FUN_008dedae(0028:25986;addTab 对偶)
    int tabCount() const;                                // FUN_008de59c
    MuxPaneView *currentPane() const;                    // FUN_008de3b2(0028:25616)
    // 008b9b2a(9B)/008b9b34(9B):页数 = TabGroup::count(+0x38);
    //   当前页索引 = tabBar()->currentIndex()(tabbar_currentIndex 面)。
    int paneCountEx() const;        // 008b9b2a(FUN_005abbda(+0x38))
    int currentPaneIndexEx() const; // 008b9b34(tabbar_currentIndex(+0x38))

    // FUN_008b9890(149B,0027.c:76790)第 index 页:TabGroup(+0x38)
    //   stackWidgetAt(i)(FUN_005abbd0)→ cast 011925c8 → MuxPaneView;
    //   011ab930 腿(KitDock → FUN_008da7a8 取内层)cited。
    MuxPaneView *paneAtIndex(int index) const;
    // s_RenamedTitle_8bbab6(850B,0028.c:226)组会话帧(blobB 内 kind2 载荷):
    //   收集非空/非 "::" 前缀页 → <<调整后当前索引 <<项数 → 逐项
    //   <<Url(QString) <<会话态BA(KitView_vt9 cited) <<颜色(005aba32 cited)
    //   <<(owner=="Terminal" ? property("RenamedTitle") : 无)。
    QByteArray sessionTitleBlob() const;

    // FUN_008c5578(59B,0028.c:7611)页名:属性 "Url"(0xcb6fcc 实读)
    //   → toString(FUN_008c54a4 键读面)。
    static QString paneUrl(const MuxPaneView *pane);

    MuxPaneView *paneAtCurrentIndex() const;             // FUN_008def86(0028:26083;
                                                         //   stack widget(currentIndex) cast 面)

    // showConfigMenu 尾段三件(批 133 转写真身,公开 = 测试面):
    //   kitFindOrCreateGroupMenu = FUN_00692ef0(0021:18914,310B;S2 容器
    //     遍历腔 cited — 容器类未解 §未解 1)
    //   kitPopupConfigButton = FUN_005ac790(0018:26415,275B 全读)
    static QMenu *kitFindOrCreateGroupMenu(void *container,
                                           const QByteArray &name, QWidget *pane);
    static void kitPopupConfigButton(QWidget *pane, const QString &name,
                                     QMenu *menu);

    // 两个归辖转发面(FUN_008df06e 面板标题同步 @0028:26161 消费):
    //   FUN_005ab6c2 / FUN_005ab09e 均为 +0x38 TabGroup 槽操作
    //   (体在 .cpp — TabGroup 仅前置于本头)。
    int stackIndexOf(QWidget *w) const;                                            // FUN_005ab6c2(+0x38)
    void setTabTitle(int index, const QString &title);                             // FUN_005ab09e(+0x38)

private:
    void attachChildWidgets();                           // s_tabbar_doubleClickAction_8de936
    void connectGroupSignals();                          // FUN_008de5a6

    void confirmCloseCurrentPane();                      // FUN_008dfa8c(0028:26729;批 106 真身)
    void showConfigMenu();                               // s_MuxPaneGroup_8de2d4(0028:25588;批 133 真身)
    void focusCurrentPane();                             // FUN_008defbc(0028:26100)
    void onTabBlankRequested();                          // FUN_008df5f8(0028:26480;批 106 真身,tmux 腿 cited)
    void closeCurrentPane(int index);                    // FUN_008dfa76(0028:26716;批 106 真身)
    void renamePane(int index);                          // FUN_008df466(0028:26325;批 106 真身)

    bool m_f30;          // 语料 +0x30(expandable)
    TabGroup *m_f38;     // 语料 +0x38(TabGroup "PaneGroup" 槽)

public:
    // 语料字节位只读面(inline;消费点 = MuxWindow::confirmPaneClose
    //   S4 @008df80d 读 +0x30 分叉 / S5 读 +0x38 摘页 — 批 106 归辖)。
    bool isExpandable() const { return m_f30; }
    TabGroup *tabGroup() const { return m_f38; }
};
