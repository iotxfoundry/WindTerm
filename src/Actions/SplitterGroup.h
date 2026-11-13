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

private:
    QSplitter *m_f30;          // 语料 +0x30
    QStackedLayout *m_f38;     // 语料 +0x38
    QWidget *m_f40;            // 语料 +0x40(zoom 占位页槽;消费点 FUN_005a23c6/FUN_005a2518
                               //   ——批 106 勘正:原注 quint64"未读"系消费点未解)
};
