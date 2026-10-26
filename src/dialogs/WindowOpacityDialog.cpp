#include "WindowOpacityDialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

#include "core/WindConfig.h"

WindowOpacityDialog::WindowOpacityDialog(QWidget *parent)
    : QDialog(parent)
    , m_box(new QDialogButtonBox(QDialogButtonBox::Close, this)) // 0x200000=Close
    , m_percent(new QLabel(this))
    , m_slider(new QSlider(Qt::Horizontal, this))
{
    setWindowTitle(tr("Window Opacity")); // 0xca0270
    setAttribute(Qt::WA_DeleteOnClose); // 0x00704dd2

    // 0x00704b32：初值 = global get("application.windowOpacity", 1.0) × 100；
    // 范围 min/max/step 常量被 Ghidra 丢参——仅 value()/100 可证（任务书 1-100，挂账）
    const int initial = int(WindConfig::instance()
                                .valueToDouble(QStringLiteral("application.windowOpacity"), 1.0)
                            * 100.0);
    m_slider->setRange(1, 100);
    m_slider->setValue(initial);

    // 0x0070496e：valueChanged→0x007048a0(预览文案)+0x00704840(即时落窗)；Close→reject
    connect(m_slider, &QSlider::valueChanged, this, [this](int value) {
        // 0x007048a0：10→"Transparent"（0xca2400），100→"Opaque"（0xc9d532），否则数值
        if (value == 10)
            m_percent->setText(tr("Transparent"));
        else if (value == 100)
            m_percent->setText(tr("Opaque"));
        else
            m_percent->setText(QString::number(value / 100.0, 'f', 2));
        // 0x00704840：clamp(10..100)/100.0 → 0x0075d79c 即时应用到 app 窗；
        // 骨架仅对 parent 窗预览（全局 setter 挂账）
        const int clamped = qBound(10, value, 100);
        if (auto *w = parentWidget())
            w->setWindowOpacity(clamped / 100.0);
    });
    connect(m_box, &QDialogButtonBox::rejected, this, &QDialog::reject); // Close=rejected

    // 0x00704b32：h[slider, label] 一行 + QFormLayout(DontWrapRows) 行 "Window opacity:"（0xc9f00f）
    auto *row = new QHBoxLayout;
    row->addWidget(m_slider);
    row->addWidget(m_percent);
    auto *form = new QFormLayout;
    form->addRow(tr("Window opacity:"), row);

    auto *layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(m_box);

    setOpacity(initial);
}

double WindowOpacityDialog::opacity() const
{
    return m_slider->value() / 100.0; // 0x00704e96
}

void WindowOpacityDialog::setOpacity(int value)
{
    if (value == 10)
        m_percent->setText(tr("Transparent"));
    else if (value == 100)
        m_percent->setText(tr("Opaque"));
    else
        m_percent->setText(QString::number(value / 100.0, 'f', 2));
}

void WindowOpacityDialog::open(QWidget *parent)
{
    WindowOpacityDialog dialog(parent);
    dialog.exec();
    if (auto *w = parent)
        w->setWindowOpacity(1.0); // 拒绝/关闭时还原预览（原版经 finished 回执，骨架近似挂账）
}
