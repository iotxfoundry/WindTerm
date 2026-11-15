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
// 成员槽:+0x30 QList(shared_null)/+0x38 ← 0/+0x40 BYTE ← 1 + +0x41 BYTE
//   ← param_2(asm 008e0980/84 byte 写;反编译 QString 型系误型,批 108
//   勘误;+0x41 调用点全过 0/1:0026:34935/35050、0028:23402/23425 = 0,
//   0026:41775 = 1)/+0x44/+0x48 int ← -1(ctor 8B 写覆盖两 int;+0x48
//   消费点 = 槽体 S9 @008e0fb5,pane index 缓存)/+0x58 QString(session
//   串槽,s_session__tmux_842414 写入面 "session::tmux")/+0x60 QString(tr)/
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
    // s_MuxWindow_8e0938:param_2 = +0x41 BYTE 旗标(asm 008e0984 byte 写;
    //   五调用点 0/1 字面,无 QString 形参 — 原"标题"建模勘误,批 108;
    //   默认 false = 调用点众数 0/1:0,0026:41775 = 1)
    explicit MuxWindow(bool tmuxBranch, QWidget *parent = nullptr);

    QSplitter *splitter() const;                               // FUN_008e01ac(+0x70→+0x30;体见 .cpp)

    // FUN_0083f830(0026:32772,105B)归辖落点:"select-pane -t %1"
    //   .arg(paneIndex)→ FUN_0083eaa6(pane)(tmux 发送门;链见 .cpp, cited)
    void sendSelectPane(MuxPaneView *pane, int paneIndex);

    // FUN_008e01a2(0028:27309,9B,asm 全读)= FUN_005a23c6(+0x70)
    //   (SplitterGroup 占位页槽非空;SplitterGroup::isZoomed 承接,
    //   批 106 勘定 +0x40 = zoom 占位页槽)。
    bool isZoomed() const;

    // 批 108 BYTE 双旗标只读取面(asm 读点直译;消费点见 .cpp):
    //   +0x41 读点 008e0f87(槽体 S9)/008dba16(FUN_008db9e4)/22972
    //   (FUN_008dadfa);+0x40 读点 008e0f92(槽体 S9)+0x41 门后。
    bool isTmuxBranch() const { return m_f41; }              // byte [win+0x41]
    bool isZoomGate() const { return m_f40; }                // byte [win+0x40]

    // FUN_008e04ae(0028:27504,1095B,asm 全读)。pane 关闭确认/zoom 切换
    //   归辖面(pane_confirmClose/008df5f8 消费):group 上溯(pane 父链 cast
    //   MuxPaneGroup 011abe10)→ stackCurrent 判定 → confirm 时标题追
    //   " [Zoomed]"(tr 0xcb77bb," [%1]" 0xc8ad1c)→ FUN_008df06e tab 同步 →
    //   FUN_005a2518 切换 → 尾 pane->setFocus(3)。gate 段(MuxWindow +0x40
    //   BYTE 旗标,ctor 8e0980/8e0984 与 8dfd9b/93 三源)本批勘正建模
    //   m_f40(bool;QScopedValueRollback 直译 = 清 0 → 尾置 1,见 .cpp)。
    //   逐段注见 .cpp。
    void setPaneZoom(MuxPaneView *pane, bool confirm);

    // pane_confirmClose(0028:26554,915B,asm 全读)归辖落点:this 上溯
    //   MuxWindow(011ac070)在 caller(MuxPaneGroup::confirmCloseCurrentPane
    //   /closeCurrentPane); QMessageBox::question(win,tr 0xcba54b,
    //   tr 0xcba508.arg(pane->title()),Yes|No=0x14000)==Yes(0x4000) 腿 →
    //   pane 关闭(展开见 .cpp);尾 tabCount==0 singleShot(0,0x28B 闭包
    //   FUN_008de260)深腿 cited。
    void confirmPaneClose(MuxPaneView *pane);

    // FUN_008da01e(0028:22186,84B)归辖落点:会话宿主 desktop 面板容器
    //   按面板 +0x30 序号查 MuxPane(消费面 = mux_restorePaneSplitter
    //   @0026:29862 / FUN_0083b240 @0026:29501 / 0026:42850);desktop
    //   类未复刻 → void* 容器宿主直读(体见 .cpp)
    static MuxPaneView *findPane(void *desktop, int paneIndex);

    // FUN_008e0428(0028:27473,126B)归辖落点:zoomed-pane 取面 —
    //   m_f70->stackCurrentPage()(FUN_005a24fc,非 zoom → 0)非空时
    //   qt_qFindChild_helper(空名,smo 011abde0 = MuxPaneView,recursive=1)。
    //   live 调用点:0084dd5a 宿主 @0084e155(zoom 拆解腿:非空 →
    //   FUN_008e04ae(win,pane,0) 先 unzoom)/@0084eece(zoomed 页标题
    //   " [Zoomed]" 追加比对腿)。
    MuxPaneView *zoomedPane() const;

    // FUN_008e0a72(0028:27741,303B)归辖落点:win 全域
    //   findChildren<MuxPaneView*>(空名,smo 011abde0)后按 pane->+0x30
    //   == paneIndex 线性扫首命中(qlist 迭代惯式直译,体见 .cpp)。
    //   live 调用点:0084dd5a 宿主 @0084e8b2(select/zoom 双旗腿:
    //   FUN_00876f8e → FUN_008e034a select-pane;FUN_00876fd6 →
    //   FUN_008e04ae(win,pane,1) zoom)。
    MuxPaneView *paneByIndex(int paneIndex) const;

    // FUN_008e03e4(0028:27444,57B)归辖落点:标题写面 — +0x60(m_f60)
    //   比对相等即返;不等赋值 + FUN_0091e3c8(0030:14120,39B)=
    //   QMetaObject::activate(this,smo 011ac2a0,idx0,&m_f60)=
    //   nameChanged(QString)(MuxWindow smo 池 0xce7e00 面:
    //   "MuxWindow/nameChanged/name")。live 调用点:宿主 0084dd5a
    //   @0084e710(建窗题)/s_session__tmux_842414 @0026:34900 区("tmux")。
    void setTitle(const QString &title);

    // FUN_008e012c(0028:27281,109B)归辖落点:空窗面 — findChild<
    //   MuxPaneView*>(空名,smo 011abde0,recursive)== 0 → 真
    //   (窗内无任何面板)。live 调用点:FUN_0083be38(0026:30051,
    //   detach 窗口腿守卫 — 窗无活面板 → 摘窗,深窗口树腿 cited)。
    bool hasNoPaneChild() const;

    // FUN_008d9fe0(0028:22169,62B)归辖落点:detach 窗口原语 — desktop
    //   +0x30 = MuxWindow 页容器 TabGroup(直读同 findPane +0x38 容器
    //   先例,MuxDesktop 未复刻铁律 6):FUN_005ab6c2(stackIndexOf)
    //   @008d9fe7 → -1 返 → FUN_005ab2cc(…,0)(0018:25074,param_3=0
    //   = 仅 removeWidget)@008d9ff6 → QWidget::setParent(win,0)
    //   @008da01c。live 调用点:FUN_0083be38 @0026:30058(空窗面守卫过
    //   → 本原语 + deleteLater)。
    static void detachWindow(void *desktop, QWidget *win);

    // 宿主 0084dd5a 直译面(+0x44 序号键读/写、+0x4c/+0x50 宿主后写):
    int windowIndex() const;                            // *(win+0x44)(FUN_008da226 键)
    void setWindowIndex(int idx);                       // @0084e705
    void setAuxFields(int f4c, int f50);                // @0084e71c/26(POD 源值未解 — wave-2)

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

signals:
    void nameChanged(const QString &title); // idx0(smo 011ac2a0;FUN_0091e3c8 发射面;
                                            //   setTitle/FUN_008e03e4 消费)

private slots:
    void onFocusChanged(QWidget *old, QWidget *now);           // FUN_008e0bb2(0028:27798;批 92 真身)

private:
    void muxWindowAssemble();                                  // FUN_008dffa0
    void connectFocusChanged();                                // FUN_008dfee8

    QList<quint64> m_f30;   // 语料 +0x30(QListData::shared_null;节点型未解 cited)
    quint64 m_f38;          // 语料 +0x38 ← 0(消费点未读 cited — wave-2)
    int m_f4c;              // 语料 +0x4c(宿主 0084dd5a 写点 @0084e71c/[RSP+0x1c0];
                            //   消费点未读 cited — wave-2;ctor 8B 写覆盖 +0x44/+0x48
                            //   两 int,本槽与 +0x50 同为宿主后写面)
    int m_f50;              // 语料 +0x50(宿主写点 @0084e726/[RSP+0x1b8] — bit1 旗标腿
                            //   @0084e12a 门后;消费点未读 cited — wave-2)
    bool m_f40 = true;      // 语料 +0x40 BYTE ← 1 @008e0980(写点 FUN_008dfd93 ←1
                            //   @008dfd96/FUN_008dfd9b ←0 @008dfd9e;读点槽体 S9
                            //   @008e0f92 byte cmp — 三源同证 BYTE;原 QString
                            //   m_f40 建模勘误,批 108)
    bool m_f41 = false;     // 语料 +0x41 BYTE ← param_2 @008e0984(ctor 实参全过
                            //   0/1;读点 008e0f87 byte cmp/FUN_008db9e4 008dba16
                            //   byte cmp/FUN_008dadfa 语料 22972 char cmp —
                            //   tmux window 分支旗标;批 108 勘误新增)
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
