#include "FocusModeDialog.h"

#include <QCheckBox>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QTabBar>
#include <QVBoxLayout>

#include "core/WindConfig.h"
FocusModeDialog::FocusModeDialog(QWidget *parent)
    : QDialog(parent)
    , m_tabBar(new QTabBar(this))
    , m_stack(new QStackedWidget(this))
    , m_showDialog(new QCheckBox(tr("&Show this dialog when focus mode starts"), this)) // 0xc9d5c0
{
    setWindowTitle(tr("Focus Mode")); // 0xc9d5b2
    setAttribute(Qt::WA_DeleteOnClose); // 0x006b6676

    // 0x006b639e：TabBar autoHide；两页页名 "Editor"/"Terminal"（0x006b6156 addTab），
    // 页内容=FUN_007667fa 按页名查 mode 工厂（骨架静态近似：空页挂账）；
    // 行嵌套 Ghidra 歧义挂账：mainV=[tabBar, v[stack, h[checkbox, stretch, box]]]（tabs-top 常规摆法）
    m_tabBar->setAutoHide(true);
    m_tabBar->addTab(QStringLiteral("Editor"));
    m_tabBar->addTab(QStringLiteral("Terminal"));
    m_stack->addWidget(new QWidget(this));
    m_stack->addWidget(new QWidget(this));
    // 挂账：TabBar currentChanged→StackedWidget 页切换的 connect 证据未逐行逆明（0x006b6782 jumptable 不可恢复）
    connect(m_tabBar, &QTabBar::currentChanged, m_stack, &QStackedWidget::setCurrentIndex);

    auto *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this); // 0x400400
    connect(box, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(box, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *bottom = new QHBoxLayout;
    bottom->addWidget(m_showDialog);
    bottom->addStretch();
    bottom->addWidget(box);

    auto *inner = new QVBoxLayout;
    inner->addWidget(m_stack);
    inner->addLayout(bottom);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_tabBar);
    layout->addLayout(inner);

    // checkbox 初值（0x006b639e setupUi 不设初值；键名 wind.config:24 实证）
    m_showDialog->setChecked(WindConfig::instance()
                                 .valueToDouble(QStringLiteral("focusMode.openFocusModeDialog"), 1.0)
                             != 0.0);
}

void FocusModeDialog::open(QWidget *parent)
{
    FocusModeDialog dialog(parent);
    dialog.exec();
}
