#pragma once

#include <QColor>
#include <QFrame>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QList>
#include <QMap>
#include <QString>
#include <QStackedWidget>
#include <QTabBar>
#include <QTimer>
#include <QToolButton>
#include <QVariant>

// TabBar —— 语料 QTabBar 子类(Phase 4c mp2,W3 定案)。
// 语料落点:
//   ctor            s_TextLabel_5a859a(605B,decomp-part-0018.c:23040)
//   tab 增挂        FUN_005a7800(759B,0018:22372)
//   关闭钮开关      FUN_005a84f6(163B,0018:22994)
//   currentChanged  FUN_005a8376(383B,0018:22922)→ 依赖 QTabBarPrivate
//                   私有 API(Qt 私有类不入库)→ 槽体 cited
//   信号面          staticMetaObject 01197f40(stringdata 0xcc7900):
//                   idx0 tabLayoutChanged()(QMetaObject 解码权威)
// 成员槽(语料字节位):
//   +0x30 bool(+0x31 bool)/+0x38 QString("None")/+0x40/+0x48/+0x50 int
//   +0x58 QLabel("TextLabel",隐藏)/+0x60/+0x68/+0x70 三 QList(自定义节点
//   0x10/0x18 字节,表示 cited)/+0x78 空
class TabBar : public QTabBar {
    Q_OBJECT

public:
    explicit TabBar(QWidget *parent);                                    // s_TextLabel_5a859a

    int insertTabWithMeta(int index, const QString &title,
                          const QIcon &icon);                            // FUN_005a7800
    void assignTabProperty(int index, const QString &value);             // FUN_005a8818(真身批 208)
    void setCloseButtonsVisible(bool on);
    // s_TabGroupButton_5aba4e(352B,0018:25724)组按钮文本:
    //   findChild<QToolButton>("TabGroupButton",递归)空 → 返;
    //   setText(text)+ setToolTip(tr("Group %1").arg(text))(0xca1863 实读)。
    void updateGroupButton(const QString &text);                                // FUN_005a84f6(真身批 208)
    // setTabText(int,QString)— FUN_005ab09e(0018:24913,218B)落点:
    //   FUN_005a6fbe 取 +0x58 tabBar index 旧文 → 比对相等即返 →
    //   FUN_005a7c74(+0x58,index,title)写新文(写函数 cited — wave-2)。
    void setTabText(int index, const QString &title);                    // FUN_005ab09e
    // FUN_005a6ca6(83B,0018:21853)页色取值:list(+0x60)[index] 命中 →
    //   该项 QColor;越界/负 → 默认(语料 0xffff00000000/0/0 缺省结构)。
    QColor tabColor(int index) const;
    // FUN_005a6d00(65B,0018:21888)页状态取值:+0x68 表[index] 命中 →
    //   该 QVariant(引用计数增);越界/负 → 无效 QVariant。
    QVariant tabStateAt(int index) const;
    // FUN_005ab180(21B,0018:24960 邻)页文:QTabBar::tabText 包装。
    QString tabTextAt(int index) const;
    // FUN_005a6fbe(213B,0018:22015)节点标题读面:
    //   index 越界 → 空;节点标题(+0x08 面)→ withMnemonics 且节点 +0x10 非空
    //   → 追加 0xca0e1c 串(cited)。
    QString nodeTitleAt(int index, bool withMnemonics) const;
    // FUN_005a7c74(308B,0018:22566)节点标题写:
    //   越界返;tabbar_buildPropHash(节点属性哈希,cited)+ FUN_005a690e
    //   (合并体,cited)→ 表 detach → FUN_005a6ab0(写节点,cited)。
    void setNodeTitle(int index, const QString &title);
    // s_FirstNine_5a6b5a(113B,0018:21759)助记符序号门:
    //   +0x38 模式串 == "All" → true;index < 10 → (模式 == "FirstNine");
    //   否则 false。ctor 初值 "None"。
    bool isMnemonicIndex(int index) const;
    // FUN_005a6b1c(62B,0018:21740)展开态恢复:
    //   私有位 +0x1c8(d)为 0 → 返;否则 +0x213 = !expanding();
    //   setExpanding(+0x213)(实参 Ghidra 丢,cited)。
    void restoreExpandingState();
    // FUN_005a7db8(495B,0018:22727)节点摘除:index 越界返;+0x60/+0x68/+0x70
    //   三表各自 remove(index)(语料为节点指针+QListData::remove;
    //   本面值承载等价)。
    void removeTabNodes(int index);
    // tabbar_assignMnemonics(756B,0018.c:22061)助记符指派:
    //   逐页 text = tabTextAt(i)(005a6fbe,含助记符腿);s_FirstNine_5a6b5a
    //   命中 → 前缀 "%1."(i+1);标题变化 → releaseShortcut +
    //   grabShortcut(QKeySequence::mnemonic(text)) + setShortcutEnabled。
    //   快捷键 id 存节点 +0x04、标题存节点 +0x08(本面以 m_mnemonicIds
    //   QStringList/ids 承接,cited 映射)。
    void assignMnemonics();
    // FUN_005a7b66(269B,0018:22507)页色设置:越界返;+0x60 表补齐默认 →
    //   旧值 != 新值才写 → 尾重绘。
    void setTabColor(int index, const QColor &color);
    // FUN_005a81c6(134B,0018:22507 邻)侧钮重排:
    //   side = style()->pixelMetric(0x5d);与 +0x40 不同 →
    //   逐页:旧侧 setTabButton(i,旧,0) + 新侧 setTabButton(i,新,btn);
    //   +0x40 = side。
    void relayoutSideButtons();
    QList<QColor> m_colors60; // 语料 +0x60(QList<QColor*> 节点面,本波值承载)

signals:
    void tabLayoutChanged();                                             // activate idx0(01197f40)

private slots:
    // FUN_005a6c62(68B,0018:22015 邻)侧钮点击:
    //   sender 逐 i 与 tabButton(i) 比对命中 → emit tabCloseRequested(i)。
    void onSideButtonClicked();
    void onCurrentChanged(int index);                                    // FUN_005a8376(真身批 283)
    void onTabMoved(int from, int to);                                   // FUN_005a7fa7(cited)

private:
    // 批 208 私有件(QTabBar 公开 API 面,非 Qt 私有结构):
    QToolButton *sideButtonAt(int index) const;   // FUN_005a6c0e(84B):tabButton+cast
    void setSideButton(int index, QWidget *w);    // FUN_005a824c(290B):状态门 + setTabButton
    QToolButton *makeCloseButton(int index);      // FUN_005a6d42(552B)头段:CloseButton 钮

    bool m_f30;        // 语料 +0x30(FUN_005a84f6 参数 1 起步)
    bool m_f31;        // 语料 +0x31 ← 1(s_TextLabel_5a859a @005a85e8)
    QString m_f38;     // 语料 +0x38 ← "None"(助记模式;s_FirstNine_5a6b5a 消费)
    int m_f40;         // 语料 +0x40 ← 1
    int m_f48;         // 语料 +0x48 ← 0
    int m_f50;         // 语料 +0x50 ← 0
    QLabel *m_f58;     // 语料 +0x58:new QLabel(this,"TextLabel") → hide()
    // 语料 tab 节点(+0x60 表,0x10 字节):FUN_005a7800 @005a7a34 初值
    //   `*node = 0xffff00000000; *(u32*)(node+8) = 0; *(u16*)(node+0xc) = 0`。
    struct TabNode {
        quint64 f0 = 0xffff00000000ull; // 合并流余量(初值实证)
        quint32 f8 = 0;                 // +0x08
        quint16 fc = 0;                 // +0x0c
    };
    QList<TabNode> m_f60; // 语料 +0x60(节点表)
    QStringList m_titles60;   // 节点 +0x08 标题面(映射承载)
    QList<int> m_shortcutIds; // 节点 +0x04 快捷键 id 面
    quint8 m_dirty1c8 = 0;    // 私有位 +0x1c8(展开态需恢复标记)
    quint8 m_saved213 = 0;    // 私有位 +0x213(保存值)
    QList<QVariant> m_f68; // 语料 +0x68(QVariant 列表,FUN_005a8818 消费,cited)
    QList<QVariant> m_f70; // 语料 +0x70(0x18 字节节点,表示 cited — wave-2)
    void *m_f78;       // 语料 +0x78 ← 0
};

// TabGroup —— 语料 QFrame 子类(非 QTabWidget)。
//   ctor            s_TabGroup_5af896(295B,0018:28725)
//   全装配          s_TabScrollRightButton_5aec28(3050B,0018:28375;
//                   名取自函数开头滚动钮面,实际 = TabGroup 全装配)
//   切换            FUN_005aa7b0(62B,0018:24492):count 越界检查 →
//                   QStackedWidget::setCurrentIndex(+0x60) → FUN_008fb5ac
//                   (activate 信号0 = tabActivated)
//   页挂            FUN_005abe1c(237B,0018:25913)/FUN_005abf12(22B,0018:25960)
//   悬停表          FUN_005ad4a6(270B,0018:26917)
// 成员槽(语料字节位):+0x30 int(单字节语义)/+0x38 QMap/+0x40 int(-1)
//   +0x48 QTimer*(悬停)/+0x50 int shape/+0x54 int flag
//   +0x58 TabBar*/+0x60 QStackedWidget*/+0x70/0x78 滚动钮
//   +0x80/0x88 TabBar 内滚动 QToolButton/+0xa0 QHBoxLayout
//   +0x68/0x69 双 bool(ctor 0x0101)
// 信号面(staticMetaObject 0119dea0,stringdata 0xccacd8,QMetaObject
//   解码权威,索引 = activate 实证):idx0 tabActivated(int) idx1
//   tabAddRequested() idx2 tabBlankRequested() idx3 tabCloseRequested(int)
//   idx4 tabDuplicateRequested(int,bool onlySshChannel) idx5
//   tabGroupRequested() idx6 tabRenameRequested(int) idx7 closeRequested()
//   idx8 configRequested() idx9 expandRequested(bool)。
// 属性 tabPosition(TabPosition)/tabShape(TabShape)及枚举注册
//   (North0/South1/West2/East3;Rounded0/Triangular1)的 getter 语料
//   未定位 → Q_PROPERTY/枚举 moc 注册整体 omitted(cited — wave-2),
//   值域记录于 docs。声明序 = activate 索引序(moc 对齐)。
class TabGroup : public QFrame {
    Q_OBJECT

public:
    explicit TabGroup(QWidget *parent);                                  // s_TabGroup_5af896

    QStackedWidget *stack() const { return m_f60; }                      // FUN_005ab6e8(0018:25355)
    TabBar *tabBar() const { return m_f58; }                             // FUN_005ab6e2(0018:25349)
    int count() const { return m_f58->count(); }                         // FUN_005abbda(0018:25772)
    QWidget *currentWidget() const { return m_f60->currentWidget(); }    // FUN_005ab316(0018:25098)
    QWidget *stackWidgetAt(int i) const { return m_f60->widget(i); }     // FUN_005abbd0(0018:25762)
    int stackIndexOf(QWidget *w) const { return m_f60->indexOf(w); }     // FUN_005ab6c2(0018:25321)
    // setTabTitle(int,QString)— FUN_005ab09e(0018:24913)归辖面:
    //   this+0x58 TabBar setTabText(真身见 TabBar::setTabText)。
    void setTabTitle(int index, const QString &title) { m_f58->setTabText(index, title); } // FUN_005ab09e

    int insertPage(int index, QWidget *page, const QString &title,
                   const QIcon &icon, const QString &tooltip);           // FUN_005abe1c
    int insertPageBack(QWidget *page, const QString &title,
                       const QIcon &icon, const QString &tooltip);       // FUN_005abf12
    // FUN_005ac8d0(191B,0018:26480)换页:old = stack->widget(index);
    //   old 空或 == 新页 → 返;blockSignals(on)→ old deleteLater →
    //   insertWidget(index,新)@005ac91a → removeWidget(old)→
    //   index <= 旧当前页 → setCurrentIndex(旧当前页)@005ac98x →
    //   blockSignals(off)。
    void replacePage(int index, QWidget *page);

    QToolButton *createButton(const QString &name, bool grabFocus);      // s_TabGroupButton_5acc3e(0018:26645)
    QToolButton *createToolButton(QWidget *parent, const QString &name,
                                  const QString &text,
                                  const QString &icon);                  // FUN_005acaba(0018:26598)

    void setHoverTimer(double seconds);                                  // FUN_005ad4a6
    void setTabShapeMode(int mode);                                      // FUN_005ab88a(0018:25502)
    // 008b9b3e(9B)/008b9bf4(18B):组级页色存取(+0x38 TabBar 转发)。
    void setTabColor(int index, const QColor &color);
    QColor tabColor(int index) const;
    // 005ab5a8(13B,0018:25234邻)组级关闭钮开关(+0x58 TabBar 转发)。
    void setCloseButtonsVisible(bool on);
    void setDocumentMode(bool on) { m_f58->setDocumentMode(on); }        // FUN_005ac652(0018:26334)
    void setAutoHide(bool on) { m_f58->setAutoHide(on); }                // FUN_005ab89c(0018:25523)
    void setUsesScrollButtons(bool on);                                  // FUN_005ac522(0018:26271)
    void setMovable(bool on) { m_f58->setMovable(on); }                  // FUN_005aba04(0018:25618)
    void setTabsClosable(bool on);                                       // FUN_005ab8b4(0018:25543)
    void setDrawBase(bool on) { m_f58->setDrawBase(on); }                // FUN_005ac8b4(0018:26460)
    void setExpanding(bool on) { m_f58->setExpanding(on); }              // FUN_005ac8c2(0018:26470)

signals:
    void tabActivated(int index);                                        // idx0(FUN_008fb5ac)
    void tabAddRequested();                                              // idx1(FUN_008fb548)
    void tabBlankRequested();                                            // idx2(FUN_008fb55c)
    void tabCloseRequested(int index);                                   // idx3(FUN_008fb5e0)
    void tabDuplicateRequested(int index, bool onlySshChannel);          // idx4(FUN_008fb64c)
    void tabGroupRequested();                                            // idx5(FUN_008fb570)
    void tabRenameRequested(int index);                                  // idx6(FUN_008fb616)
    void closeRequested();                                               // idx7(FUN_008fb584)
    void configRequested();                                              // idx8(FUN_008fb598)
    void expandRequested(bool expanding);                                // idx9(FUN_008fb690)

private slots:
    void onCurrentChanged(int index);                                    // FUN_005aa7b0
    void onTabMoved(int from, int to);                                   // FUN_005aa72a(0018:24464)
    void onWidgetRemoved();                                              // FUN_005aa720→FUN_005a7db8(cited)
    void onTabLayoutChanged();                                           // FUN_005ab7d8(cited)
    void onTabCloseRequested(int index);                                 // FUN_008fb5e0 转发
    void showAfterInsert();                                              // FUN_005aa7ee(0018:24506)
    void onHoverTimeout();                                               // FUN_005aa91e(cited)

private:
    void fullAssemble();                                                 // s_TabScrollRightButton_5aec28
    void applyTabShape();                                                // FUN_005ab814(0018:25397 起)

    int m_f30;                     // 语料 +0x30(单字节语义:005abe98/005aa7ee)
    QMap<QString, QVariant> m_f38; // 语料 +0x38(QMapDataBase::shared_null;键值型未解 cited)
    int m_f40;                     // 语料 +0x40 ← -1(悬停待切 index;FUN_005aa91e
                                   //   hover 面 @005aa92e 判 !=-1 后 setCurrentIndex)
    QTimer *m_f48;                 // 语料 +0x48(悬停 QTimer,FUN_005ad4a6 落点)
    int m_f50;                     // 语料 +0x50(tabPosition 位;FUN_005ab814)
    int m_f54;                     // 语料 +0x54(Triangular flag;FUN_005ab814)
    TabBar *m_f58;                 // 语料 +0x58
    QStackedWidget *m_f60;         // 语料 +0x60
    bool m_f68;                    // 语料 +0x68 ← 1(ctor 0x0101 低字节;FUN_005ab7d8/FUN_005ac522)
    bool m_f69;                    // 语料 +0x69 ← 1(ctor 0x0101 高字节)
    QToolButton *m_f70;            // 语料 +0x70(左滚钮 TabScrollLeftButton)
    QToolButton *m_f78;            // 语料 +0x78(右滚钮 TabScrollRightButton)
    QToolButton *m_f80;            // 语料 +0x80(tr("Scroll Left") 子钮)
    QToolButton *m_f88;            // 语料 +0x88(tr("Scroll Right") 子钮)
    quint64 m_f90;                 // 语料 +0x90 ← 0(消费点未读 cited)
    quint64 m_f98;                 // 语料 +0x98 ← 0(消费点未读 cited)
    QHBoxLayout *m_fa0;            // 语料 +0xa0
};
