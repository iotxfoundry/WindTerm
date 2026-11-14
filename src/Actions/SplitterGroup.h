#pragma once

#include <QSplitter>
#include <QStackedLayout>
#include <QWidget>

// SplitterGroup —— 语料 QWidget 子类(Phase 4c mp2,W3 定案;mp 笔记
//   "仓库缺"翻案:语料不缺)。
// 语料落点:
//   ctor            FUN_005a2314(79B,decomp-part-0018.c:18539)
//   装配            FUN_005a2266(158B,0018:18513)
//   加页            FUN_005a225c(9B,0018:18503)= QSplitter::addWidget(+0x30)
//   metaObject      008f6c66(0029:5235)→ staticMetaObject 01198400;
//   qt_metacast     008f6c7e(strcmp "SplitterGroup")
// 信号面(staticMetaObject 01198400 解码):方法数 0(纯容器,零信号零槽);
//   "showIndexRequested/hideIndexRequested" 串 @0xcc7af8 属旁邻 Splitter 类
//   (非本类,勿挂)。
// 结构:QStackedLayout(+0x38)为页容器,QSplitter(+0x30,Qt::Vertical,
//   setChildrenCollapsible=false)为其中唯一页。
// 批 148 余项差集三态定案(批 118 已落槽体除外;kuna xrefs + 全二进制
//   call/jmp/rip-rel 扫描双源):
//   removePage      FUN_005a29e6(690B)→ 真身(本批落,.cpp 逐段锚);
//   装配 spacing/margins 两 cited 腿 → 升真身(import 符号实证);
//   FUN_005a23d0(283B 两 pane 互换)→ 定案:零调用点孤儿死代码
//     (call/jmp/rip-rel/.data 全零命中;不落码,原样保留);
//   King::insertPane 005a277a(596B)+ thunk 008e041e(9B)→ 定案:孤儿链
//     (thunk 零调用点 → insertPane 唯一调用点即 orphan;不落码);
//   moc 三件 008f6c66/8f6c7e/8f6cc0 + dtor 四件 008f6cc6/8f6ce3/8f6d04/
//     8f6d33 → 定案由 moc/编译器生成同构(Q_OBJECT methods=0 + 隐式 dtor,
//     语料 dtor 仅尾调 QWidget::~QWidget 与隐式同相);
//   FUN_008e01b6(15B MuxWindow thunk +0x70→removePage)/008e0428(126B
//     findChild<MuxPane*> zoomed)/008e0a72(findChildren<MuxPane*>)→
//     归辖 MuxWindow 面,live(0084dd5a/008e01c6);本批不落(闭包腿 S7
//     cited 决定同面),挂账现役队列。
//   functor 胶水 005a21f0/221a/2244/2251 → toggleZoomPage 内联已落(批 106)。
class SplitterGroup : public QWidget {
    Q_OBJECT

public:
    explicit SplitterGroup(QWidget *parent);   // FUN_005a2314

    void addPage(QWidget *w);                  // FUN_005a225c
    QSplitter *splitter() const { return m_f30; } // 语料 +0x30(FUN_008e01ac 对侧取面)
    // FUN_005a23c6(0018:18578,9B,反汇编勘定):*(this+0x40)!=0 —— +0x40 消费点
    //   随批 106 定案(005a2518 占位页槽/008e01a2 zoom 判定),批 103 前"未读"注作废。
    bool isZoomed() const { return m_f40 != 0; } // FUN_005a23c6(9B)
    // FUN_005a24fc(0018:18632,27B,asm 全读):zoom 时 stack(+0x38)
    //   currentWidget,否则 0。
    QWidget *stackCurrentPage() const { return isZoomed() ? m_f38->currentWidget() : nullptr; } // FUN_005a24fc
    // FUN_005a2518(0018:18651,585B,asm 全读):zoom 页切换(param_3=zoom)。
    //   逐段转写见 .cpp; Fun_005a236c 焦点深潜(setFocus ActiveWindowFocusReason)。
    void toggleZoomPage(QWidget *page, bool zoom); // FUN_005a2518
    // FUN_005a29e6(0018:18817,690B,asm 005a29e6-005a2c9b 全读;批 148):
    //   摘页 + splitter 收缩(页 close→hide→setParent(0)→deleting dtor;
    //   父 splitter 空 → 递归上卷;剩 1 页 → 与上父 splitter 合并;
    //   ≥2 页 → 邻页吸收 handleWidth+本页 size,removeAt,setSizes);
    //   尾 FUN_005a236c 焦点深潜。语料调用点 = MuxWindow thunk
    //   FUN_008e01b6(+0x70 面,批 148 归辖注记见 .cpp)。
    void removePage(QWidget *page);            // FUN_005a29e6

private:
    QSplitter *m_f30;          // 语料 +0x30
    QStackedLayout *m_f38;     // 语料 +0x38
    QWidget *m_f40;            // 语料 +0x40(zoom 占位页槽;消费点 FUN_005a23c6/FUN_005a2518
                               //   ——批 106 勘正:原注 quint64"未读"系消费点未解)
};
