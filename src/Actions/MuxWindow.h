#pragma once

#include <QList>
#include <QPointer>
#include <QString>
#include <QWidget>

class QSplitter;
class SplitterGroup;
class MuxPaneView;
class SuperSession;
struct PaneDescriptor;   // 定义在 MuxWindow.cpp(布局不进产品头,见 restorePaneSplitter 注)

// MainWindow 装配锚(五级装配链 L1;不落 MainWindow 类 —— 宿主语义 =
// 现 MuxPane 壳承载,批 71 勘误;仅记址):
//   装配            FUN_007662e6(109B,decomp-part-0023.c:33100;触发点 =
//                   mainWindow_connectSignals 0076b9ec @0023:36614 第 3 步
//                   FUN_0076663e 之后):
//                     new KitBar(FUN_008b31b6 @0027:71172)→ 宿主+0x50
//                     new QStackedWidget(宿主)→ 宿主+0x58 @0076631e
//                     QMainWindow::addToolBar(宿主,1,+0x50)(实参 1 照语料)
//                     QMainWindow::setCentralWidget(第二实参 Ghidra 丢 — cited)
//                     QWidget::hide()(初始隐藏 @00766348)
//   页挂 stack      s_HistoryHints_7664a2(244B,0023:33200)=
//                   QStackedWidget::addWidget(+0x58)+ param_3 时
//                   setCurrentIndex + FUN_008b346e(+0x50 KitBar,index,…)
//                   (9743B 深腿 cited — 见 KitBar.h)
//   关闭扫描        FUN_007660e6(171B,0023:32991):遍历 +0x58 stack 页
//                   dynamic_cast<KitWindow>(011ab390)→ QWidget::close。

// MuxWindow —— 语料 QWidget 子类(Phase 4c mp2,W3 定案;五级装配链 L2b)。
// 语料落点:
//   ctor            s_MuxWindow_8e0938(289B,decomp-part-0028.c:27695)
//   装配            FUN_008dffa0(134B,0028:27199):new QVBoxLayout →
//                   new SplitterGroup(this)(FUN_005a2314 @0018:18539)→
//                   存 +0x70 → addWidget → setLayout
//   焦点接线        FUN_008dfee8(183B,0028:27169):qcoreapp
//                   QApplication::focusChanged → 本类槽(lambda dynsym
//                   _ZN9MuxWindow14onFocusChangedEP7QWidgetS1_E;槽体
//                   FUN_008e0bb2 1323B @0028:27798,批 92 真身落码)
//   splitter 取面   FUN_008e01ac(9B,0028:27319)= *(+0x70)->+0x30
//   zoom 判定       FUN_008e01a2(9B,0028:27309)= FUN_005a23c6(+0x70)
//                   (消费面 FUN_008df5f8 已在 MuxPaneGroup.cpp cited;不落)
//   页挂/恢复       mux_restorePaneSplitter(0083ba78,0026:29862)→
//                   本类 restorePaneSplitter(见下)
//   类型            typeinfo "9MuxWindow"(011ac070 → name @0xce7d30,
//                   ELF .data.rel.ro 实证;metaObject 真身 011ac040;
//                   staticMetaObject PTR_staticMetaObject_011ac2a0,
//                   ctor tr 引用 @008e099e → Q_OBJECT 实证)
// 成员槽:+0x30 QList(shared_null)/+0x38 ← 0/+0x40 QString(param_2 标题)/
//   +0x44/+0x48 int ← -1(ctor 8B 写覆盖两 int;+0x48 消费点 = 槽体
//   S9 @008e0fb5,pane index 缓存)/+0x58 QString(session 串槽,
//   s_session__tmux_842414 写入面 "session::tmux")/+0x60 QString(tr)/
//   +0x68 parent/+0x70 SplitterGroup*/+0x78/+0x80 = QPointer<MuxPane>
//   双槽(槽体 S9 @008e0fc7-d4 存储)。
// 注:mp 笔记 §5 "FUN_008dfee8 = +0x78/0x80 初始化" 系猜测 —— 体读
//   (0028:27169)实为 focusChanged connect;+0x78/0x80 消费点 = 槽体 S9。
class MuxWindow : public QWidget {  // 批 91 K3 勘误闭环:成员槽位语义定案(008e0bb2 全读测绘)
  //  +0x48 = select-pane index 缓存(pane->+0x30)
  //  +0x78/+0x80 = QPointer<MuxPane> 双槽(命中 pane 消费点落定)
  //  +0x44 = 窗口序号键(消费点 FUN_008da226 @0028:22312 按序查窗口;
  //          勘正于 findPane 批,原注「仅 ctor -1 无消费点」随之作废)

    Q_OBJECT

public:
    MuxWindow(const QString &title, QWidget *parent);          // s_MuxWindow_8e0938

    QSplitter *splitter() const;                               // FUN_008e01ac(+0x70→+0x30;体见 .cpp)

    // FUN_0083f830(0026:32772,105B)归辖落点:"select-pane -t %1"
    //   .arg(paneIndex)→ FUN_0083eaa6(pane)(tmux 发送门;链见 .cpp, cited)
    void sendSelectPane(MuxPaneView *pane, int paneIndex);

    // FUN_008da01e(0028:22186,84B)归辖落点:会话宿主 desktop 面板容器
    //   按面板 +0x30 序号查 MuxPane(消费面 = mux_restorePaneSplitter
    //   @0026:29862 / FUN_0083b240 @0026:29501 / 0026:42850);desktop
    //   类未复刻 → void* 容器宿主直读(体见 .cpp)
    static MuxPaneView *findPane(void *desktop, int paneIndex);

    // mux_restorePaneSplitter(903B,0026:29862)。语料为自由函数:
    // (会话宿主*、配置容器、QSplitter*、页序、面板描述符*);QSplitter
    // 形参在调用点以 FUN_008e01ac(muxWindow) 形态取自本类
    // (s_session__tmux_842414 @0026:34862 同面)→ 落为本类方法,
    // 接收器 = splitter()。
    // 四形参强类型化(勘察 /tmp/opencode/p3_notes_rs2.md N3 方案):
    //   param_1 消费面仅 *param_1+0x1c8(QSharedPointer 槽 +0x1c8/+0x1d0
    //     三连判同型,FUN_0083be38:30023 同面)→ SuperSession*
    //     (SuperSession 已落库 src/Sessions/SuperSession.h);
    //   param_2 消费面仅 *(param_2+0x50) QMap<int,QString> upperBound
    //     内联 @0083bb27-d4;配置类未解 → void* 保留(铁律 6:无落点退 cited);
    //   param_5 = 0x28B POD 描述符(QVariant 经 FUN_00856450 0026:48104
    //     canConvert 提取;唯一实证字段 +0x18 int pane 序号;类名未解)
    //     → 匿名局部 POD,定义在 MuxWindow.cpp,不进产品头(铁律 6)。
    void restorePaneSplitter(SuperSession *sessionHost, void *configHolder,
                             unsigned int paneIndex, const PaneDescriptor &desc);

private slots:
    void onFocusChanged(QWidget *old, QWidget *now);           // FUN_008e0bb2(0028:27798;批 92 真身)

private:
    void muxWindowAssemble();                                  // FUN_008dffa0
    void connectFocusChanged();                                // FUN_008dfee8

    QList<quint64> m_f30;   // 语料 +0x30(QListData::shared_null;节点型未解 cited)
    quint64 m_f38;          // 语料 +0x38 ← 0(消费点未读 cited — wave-2)
    QString m_f40;          // 语料 +0x40/0x41 ← param_2(标题;拷贝构造展开)
    int m_f44;              // 语料 +0x44 ← -1(消费点 = FUN_008da226 窗口序号键
                                  //   @0028:22312;勘正于 findPane 批 — 非未解)
    int m_f48;              // 语料 +0x48(消费点 008e0fb5:pane index 缓存 vs pane->+0x30)
    QString m_f58;          // 语料 +0x58(session 串槽;写入面 cited)
    QString m_f60;          // 语料 +0x60 ← QMetaObject::tr(0xc8c60e;字面 cited)
    QWidget *m_f68;         // 语料 +0x68 ← param_3(parent)
    SplitterGroup *m_f70;   // 语料 +0x70(FUN_008dffa0 落点)
    QPointer<MuxPaneView> m_f78; // 语料 +0x78/0x80 QPointer<MuxPane> 双槽
                                 //   (消费点 008e0fc7-d4:getAndRef + pane 指针)
};
