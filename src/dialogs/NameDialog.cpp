#include "NameDialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

NameDialog::NameDialog(Mode mode, const QString &name, QWidget *parent)
    : QDialog(parent)
    , m_prompt(new QLabel(this))
    , m_box(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this))
    , m_edit(new QLineEdit(this))
{
    // 0x006bd7f6：标题 "Create/Rename <name>"（0xc9da96/0xc9da27 + 0xd992f9 空格拼接）
    setWindowTitle((mode == Mode::Create ? tr("Create") : tr("Rename")) + QLatin1Char(' ') + name);
    // 0x006bd50c：提示 arg(name)（0xc9da79 新建）；0x006bd960 切换改名串（0xc9daa4）
    m_prompt->setText(mode == Mode::Create
                          ? tr("Enter a name for the new %1.").arg(name)
                          : tr("Enter a new name for \"%1\".").arg(name));

    // 0x006bd50c：QVBoxLayout[ QLabel, QFormLayout(&Name: → edit), QDialogButtonBox(Ok|Cancel) ]
    auto *form = new QFormLayout;
    form->addRow(tr("&Name:"), m_edit); // 0xc9da9d

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(m_prompt);
    layout->addLayout(form);
    layout->addWidget(m_box);

    // 0x006bd34a：accepted→accept / rejected→reject；0x006bdced：textChanged→OK 门控（非空才 enabled）
    connect(m_box, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(m_box, &QDialogButtonBox::rejected, this, &QDialog::reject);
    connect(m_edit, &QLineEdit::textChanged, this, [this](const QString &text) {
        m_box->button(QDialogButtonBox::Ok)->setEnabled(!text.isEmpty());
    });
    m_box->button(QDialogButtonBox::Ok)->setEnabled(!m_edit->text().isEmpty());

    // 0x006bd7f6：setAttribute(WA_DeleteOnClose) → 堆分配使用
    setAttribute(Qt::WA_DeleteOnClose);
}

QString NameDialog::text() const
{
    return m_edit->text();
}

void NameDialog::open(QWidget *parent, const QString &title, const QString &label,
                      const QString &defaultText, std::function<void(QString)> onOk)
{
    NameDialog dialog(Mode::Create, QString(), parent);
    dialog.setWindowTitle(title);
    dialog.m_prompt->setText(label);
    dialog.m_edit->setText(defaultText);
    if (dialog.exec() == QDialog::Accepted && onOk)
        onOk(dialog.text());
}
