#include "KitGroup.h"

// ctor 0x008bb360：仅 QMainWindow(parent, Qt::Widget 嵌入)——装配全在宿主
// （KitWindow_setupBars 0x008bade2：setMenuWidget/setCentralWidget/addToolBar）
KitGroup::KitGroup(QWidget *parent)
    : QMainWindow(parent, Qt::Widget)
{
}
