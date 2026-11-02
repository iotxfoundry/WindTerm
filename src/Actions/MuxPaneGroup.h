#pragma once

#include <QWidget>

class TabGroup;
class MuxPaneView;
class QToolButton;

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

private:
    void attachChildWidgets();                           // s_tabbar_doubleClickAction_8de936
    void connectGroupSignals();                          // FUN_008de5a6

    void confirmCloseCurrentPane();                      // FUN_008dfa8c(0028:26729)
    void showConfigMenu();                               // s_MuxPaneGroup_8de2d4(0028:25588;cited)
    void focusCurrentPane();                             // FUN_008defbc(0028:26100)
    void onTabBlankRequested();                          // FUN_008df5f8 链(0028:26480;cited)
    void closeCurrentPane(int index);                    // FUN_008dfa76(0028:26716)
    void renamePane(int index);                          // FUN_008df466(0028:26325;cited)

    bool m_f30;          // 语料 +0x30(expandable)
    TabGroup *m_f38;     // 语料 +0x38(TabGroup "PaneGroup" 槽)
};
