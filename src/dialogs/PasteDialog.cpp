#include "PasteDialog.h"

#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFontMetrics>
#include <QHBoxLayout>
#include <QLabel>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include <QVBoxLayout>

PasteDialog::PasteDialog(const QString &text, QWidget *parent)
    : QDialog(parent)
    , m_result(Paste)
    , m_text(text)
    , m_tabSpaces(new QCheckBox(tr("C&onvert tab to spaces:"), this)) // 0xc9df3f
    , m_crlfToCr(new QCheckBox(tr("Co&nvert CRLF and LF to CR"), this)) // 0xc9df57
    , m_tabWidth(new QSpinBox(this))
    , m_stats(new QLabel(this))                       // +0x68
    , m_preview(new QPlainTextEdit(this))             // +0x70
{
    setWindowTitle(tr("Paste")); // 0xc9df92
    // 0x006caf18：setAttribute(WA_DeleteOnClose) → 堆分配使用
    setAttribute(Qt::WA_DeleteOnClose);

    // 0x006ca94a：编辑区（NoWrap）+ 底行 [tab 复选, 间距, stretch, 按钮盒]（行嵌套 Ghidra 歧义，挂账）
    m_preview->setPlainText(m_text);
    m_preview->setLineWrapMode(QPlainTextEdit::NoWrap); // setLineWrapMode(0)

    // 0x006ca94a：QPushButton(icon king::start, "&Send Line By Line") 以 AcceptRole 入盒；
    // OK 按钮改字 "&Paste"（0xc9df91）；Cancel 标准（0xc8a1b4）
    auto *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    auto *sendLine = new QPushButton(tr("&Send Line By Line"), this); // 0xc9df7e
    box->addButton(sendLine, QDialogButtonBox::AcceptRole);
    box->button(QDialogButtonBox::Ok)->setText(tr("&Paste"));
    connect(box, &QDialogButtonBox::clicked, this, [this, box, sendLine](QAbstractButton *button) {
        // 0x006ca260：Send Line By Line→2；OK→1；各自 accept
        m_result = (button == sendLine) ? SendLineByLine : Paste;
        accept();
    });
    connect(box, &QDialogButtonBox::rejected, this, &QDialog::reject);

    // 0x006ca94a：SpinBox 默认态（Ghidra 参数丢失挂账：范围/初值，仅下限 1 可证）
    m_tabWidth->setMinimum(1);
    // 0x006ca2de：valueChanged → tabStopDistance = value × ' ' 宽
    connect(m_tabWidth, qOverload<int>(&QSpinBox::valueChanged), this, [this](int value) {
        const int advance = m_preview->fontMetrics().horizontalAdvance(QLatin1Char(' '));
        m_preview->setTabStopDistance(value * advance);
    });

    // 0x006ca710：textChanged → 0x006ca36a 单发 QTimer(0) → 0x006ca4f8 统计刷新
    connect(m_preview, &QPlainTextEdit::textChanged, this, [this] { QTimer::singleShot(0, this, [this] { refreshStats(); }); });

    auto *row = new QHBoxLayout;
    row->addWidget(m_tabSpaces);
    row->addWidget(m_tabWidth);
    row->addStretch();
    row->addWidget(box);

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_preview);
    layout->addLayout(row);
    layout->addWidget(m_crlfToCr); // 0x006ca94a 尾段 addWidget(this_01, +0x40)
    layout->addWidget(m_stats);    // 0x006ca94a：统计行
    refreshStats();
}

void PasteDialog::showEvent(QShowEvent *event)
{
    // 0x006ca438：显示时刷新统计 + 焦点给 OK
    QDialog::showEvent(event);
    refreshStats();
    if (auto *box = findChild<QDialogButtonBox *>())
        box->button(QDialogButtonBox::Ok)->setFocus();
}

void PasteDialog::refreshStats()
{
    // 0x006ca4f8：document→toPlainText；行数 0x006ca484（\n 计 1，\r 计 1，\r\n 合并，
    // 空文本=1）；字符数=QString size；模板 "&Text: %1 lines, %2 characters"（0xc9df20）
    const QString text = m_preview->document()->toPlainText();
    int lines = 1;
    for (int i = 0; i < text.size(); ++i) {
        const QChar ch = text.at(i);
        if (ch == QLatin1Char('\n')) {
            ++lines;
        } else if (ch == QLatin1Char('\r') && i + 1 < text.size()
                   && text.at(i + 1) == QLatin1Char('\n')) {
            ++lines;
            ++i;
        } else if (ch == QLatin1Char('\r')) {
            ++lines;
        }
    }
    m_stats->setText(tr("&Text: %1 lines, %2 characters").arg(lines).arg(text.size()));
}

void PasteDialog::open(QWidget *parent, const QString &text,
                       std::function<void(const QString &, int mode)> onPaste)
{
    PasteDialog dialog(text, parent);
    const int result = dialog.exec();
    if (result == QDialog::Accepted && onPaste)
        onPaste(dialog.m_preview->toPlainText(), int(dialog.result()));
}
