#pragma once

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
    void assignTabProperty(int index, const QString &value);             // FUN_005a8818(cited)
    void setCloseButtonsVisible(bool on);                                // FUN_005a84f6
    // setTabText(int,QString)— FUN_005ab09e(0018:24913,218B)落点:
    //   FUN_005a6fbe 取 +0x58 tabBar index 旧文 → 比对相等即返 →
    //   FUN_005a7c74(+0x58,index,title)写新文(写函数 cited — wave-2)。
    void setTabText(int index, const QString &title);                    // FUN_005ab09e

signals:
    void tabLayoutChanged();                                             // activate idx0(01197f40)

private slots:
    void onCurrentChanged(int index);                                    // FUN_005a8376(cited)
    void onTabMoved(int from, int to);                                   // FUN_005a7fa7(cited)

private:
    bool m_f30;        // 语料 +0x30(FUN_005a84f6 参数 1 起步)
    bool m_f31;        // 语料 +0x31 ← 1(s_TextLabel_5a859a @005a85e8)
    QString m_f38;     // 语料 +0x38 ← "None"(助记模式;s_FirstNine_5a6b5a 消费)
    int m_f40;         // 语料 +0x40 ← 1
    int m_f48;         // 语料 +0x48 ← 0
    int m_f50;         // 语料 +0x50 ← 0
    QLabel *m_f58;     // 语料 +0x58:new QLabel(this,"TextLabel") → hide()
    QList<QVariant> m_f60; // 语料 +0x60(自定义 tab 节点,表示 cited — wave-2)
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

    QToolButton *createButton(const QString &name, bool grabFocus);      // s_TabGroupButton_5acc3e(0018:26645)
    QToolButton *createToolButton(QWidget *parent, const QString &name,
                                  const QString &text,
                                  const QString &icon);                  // FUN_005acaba(0018:26598)

    void setHoverTimer(double seconds);                                  // FUN_005ad4a6
    void setTabShapeMode(int mode);                                      // FUN_005ab88a(0018:25502)
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
    int m_f40;                     // 语料 +0x40 ← -1(语义未解 cited — wave-2)
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
