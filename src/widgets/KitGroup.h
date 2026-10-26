#pragma once

#include <QMainWindow>

// 原版中部单元（ctor 0x008bb360，KitGroup 独占 vtable/metaObject）：
// QMainWindow 子类嵌入为 root 中部列——menuWidget 槽=标签行(ViewGroup)、toolBar 区=KitBar、
// central=MuxPaneGroup 的 QStackedWidget。QToolBar 只占其宽 → 不横跨侧栏（嵌套天然隔离）。
// 内容由 MainWindow 装配（对应 setupBars 0x008bade2）
class KitGroup : public QMainWindow
{
    Q_OBJECT

public:
    explicit KitGroup(QWidget *parent = nullptr);
};
