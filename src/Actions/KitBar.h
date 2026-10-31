#pragma once

#include <QToolBar>

class QWidget;

// KitBar —— 语料 QToolBar 子类(五级装配链 L1 附件;MainWindow+0x50)。
// 语料落点:
//   ctor            FUN_008b31b6(420B,decomp-part-0027.c:71172)
//   尾装            FUN_008b3178(62B,0027:71156):layout() 非空 →
//                   setContentsMargins/setSpacing(Ghidra 实参折叠 — cited)
//   标题            King::registerBarsAndPanes(&out,"KitBar")→
//                   setWindowTitle(out)@008b3287(King 面未落库 → cited)
//   类型            vtable KitBar_vtable(ctor *param_1 实证);
//                   dynsym 深腿 FUN_008b346e(9743B,0027:71330,未读)
// 成员槽:+0x30 QList(shared_null;节点 0x14 字节 pair(FUN_008b337e 按
//   int 键查 +8 offset 对象/FUN_008b33c2 按 QString 键查),表示 cited —
//   wave-2)/+0x38/+0x40 ← 0(消费点未读 cited)。
// 深腿登记:FUN_008b346e(9743B,0027:71330)= MainWindow 页挂面
//   s_HistoryHints_7664a2(0023:33200)尾调(KitBar,index,…)—
//   体量 9.7KB 且下行层未开 → 整体 cited(引用档)。
class KitBar : public QToolBar {
    Q_OBJECT

public:
    explicit KitBar(QWidget *parent);   // FUN_008b31b6

private:
    void tailAssemble();                // FUN_008b3178

    QList<quint64> m_f30;  // 语料 +0x30(QListData::shared_null;pair 节点型
                           //   = 契约 cited — wave-2,FUN_008b337e/008b33c2 查询面)
    quint64 m_f38;         // 语料 +0x38 ← 0(消费点未读 cited — wave-2)
    quint64 m_f40;         // 语料 +0x40 ← 0(消费点未读 cited — wave-2)
};
