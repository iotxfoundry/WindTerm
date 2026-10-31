#pragma once

#include <QString>
#include <QWidget>

// MuxPaneView —— 语料 MuxPane 面板 widget(QWidget)真身(Phase 4c,mp lane)。
// 命名避让:src/Actions/MuxPane.h(批 50 壳;批 71 勘误后为主窗口宿主语义)
//   已占 "MuxPane" 类名,本类随笔记 §5 定名 MuxPaneView(记 QUIRKS)。
// 语料落点:
//   ctor            s_MuxPane_8de0c0(202B,decomp-part-0028.c:25440)
//   setCentralView  FUN_008de1a8(124B,0028:25489)
//   布局装配        FUN_008de052(86B,0028:25410,QVBoxLayout + setLayout)
//   计数器          FUN_008de0b0(16B,0028:25425,DAT_011be6c8 −1)
//   vt 族           PTR_FUN_011abbb8(与 TextView/ScintillaEditWatcher 同族
//                   —— MuxPane 为 TextView/EditorView 等面板基类)
// Ghidra 语料中 *(this)=011abbb8 / *(this+0x10)=011abd90 为 C++ vtable
//   表示,不落成员;真实成员仅 +0x30/+0x34/+0x38/+0x40。
// bootstrap 接线(paneMeta = &MuxPaneView::staticMetaObject 持有者,
//   s_MuxPane_64b102 批 39 链)在既有 0064b102 收编面注入,不在此重复。

// MuxPane::Type 枚举(QMetaObject 权威值域未提取,笔记 §未解)→ int 别名
using MuxPaneType = int;

class MuxPaneView : public QWidget {
    Q_OBJECT

public:
    explicit MuxPaneView(QWidget *parent, MuxPaneType type); // s_MuxPane_8de0c0(param_1,param_2,param_3)
    void setCentralView(QWidget *view);                      // FUN_008de1a8

private:
    int m_f30;                    // 语料 +0x30:FUN_008de0b0 返回值落点(DAT_011be6c8 计数;值语义未解,cited — wave-2)
    MuxPaneType m_type;           // 语料 +0x34:param_2(MuxPane::Type)
    QString m_title;              // 语料 +0x38:shared_null 起步;setter 面 = FUN_008de224(cited — wave-2,不在本批写域)
    QWidget *m_central = nullptr; // 语料 +0x40:central 槽(ctor 置 0)
};
