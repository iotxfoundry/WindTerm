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

private:
    QSplitter *m_f30;          // 语料 +0x30
    QStackedLayout *m_f38;     // 语料 +0x38
    quint64 m_f40;             // 语料 +0x40 ← 0(消费点未读 cited)
};
