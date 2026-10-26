#include "LogDialog.h"

#include <QButtonGroup>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QVBoxLayout>

#include "core/WindConfig.h"

LogDialog::LogDialog(QObject *settingsHost, QWidget *parent)
    : QDialog(parent)
    , m_host(settingsHost)
    , m_filePath(new QLineEdit(this))
    , m_pattern(new QLineEdit(this))
    , m_printable(new QRadioButton(tr("&Printable output"), this))    // 0xc9d67c
    , m_all(new QRadioButton(tr("&All session output"), this))        // 0xc9d68e
    , m_overwrite(new QRadioButton(tr("&Overwrite log file"), this))  // 0xc9d6a2
    , m_append(new QRadioButton(tr("&Append log file"), this))        // 0xc9d6b6
{
    setWindowTitle(tr("Log Dialog")); // 0xc9d724
    setAttribute(Qt::WA_DeleteOnClose); // 0x006b874c

    // 0x006b765e 初值：无键回退 path "%n_%Y-%m-%d_%H-%M-%S.log" /
    // pattern "[%Y-%m-%d %H:%M:%S] %v" / type=2(Printable) / option=1(Overwrite)
    const WindConfig &cfg = WindConfig::instance();
    m_filePath->setText(cfg.valueToString(QStringLiteral("session.userLogFilePath"),
                                          QStringLiteral("%n_%Y-%m-%d_%H-%M-%S.log")));
    m_pattern->setText(cfg.valueToString(QStringLiteral("session.userLogPattern"),
                                          QStringLiteral("[%Y-%m-%d %H:%M:%S] %v")));

    // 0x006b765e：两组 QButtonGroup；type==0xe→All else Printable；option==2→Append else Overwrite
    auto *typeGroup = new QButtonGroup(this);
    typeGroup->addButton(m_printable);
    typeGroup->addButton(m_all);
    (cfg.valueToDouble(QStringLiteral("session.userLogType"), 2.0) == 14.0 ? m_all : m_printable)
        ->setChecked(true);
    auto *optionGroup = new QButtonGroup(this);
    optionGroup->addButton(m_overwrite);
    optionGroup->addButton(m_append);
    (cfg.valueToDouble(QStringLiteral("session.userLogOption"), 1.0) == 2.0 ? m_append : m_overwrite)
        ->setChecked(true);

    // 0x006b765e：QFormLayout[ "Log &file:", "Log &pattern:", "Log type:", "Log option:" ]
    //（0xc9d6f5/0xc9d700/0xc9d70e/0xc9d718），LabelAlignment=AlignRight，末行 stretch
    auto *typeRow = new QHBoxLayout;
    typeRow->addWidget(m_printable);
    typeRow->addWidget(m_all);
    typeRow->addStretch();
    auto *optionRow = new QHBoxLayout;
    optionRow->addWidget(m_overwrite);
    optionRow->addWidget(m_append);
    optionRow->addStretch();

    auto *form = new QFormLayout;
    form->setLabelAlignment(Qt::AlignRight);
    form->addRow(tr("Log &file:"), m_filePath);
    form->addRow(tr("Log &pattern:"), m_pattern);
    form->addRow(tr("Log type:"), typeRow);
    form->addRow(tr("Log option:"), optionRow);

    // 0x006b765e：标准 Ok|Cancel（无自定义字）
    auto *box = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(box, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(box, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *layout = new QVBoxLayout(this);
    layout->addLayout(form);
    layout->addWidget(box);
    m_filePath->setFocus(); // 0x006b765e：setFocus(+0x40)
}

QString LogDialog::filePath() const
{
    return m_filePath->text();
}

QString LogDialog::pattern() const
{
    return m_pattern->text();
}

int LogDialog::logType() const
{
    return m_all->isChecked() ? 14 : 2; // 0x006b888e
}

int LogDialog::logOption() const
{
    return m_append->isChecked() ? 2 : 1; // 0x006b888e
}

void LogDialog::accept()
{
    // 0x006b888e：写回 session.userLog* 四键后 accept。
    // 骨架 WindConfig 无写回接口（挂账：需增 setter 或直写 user.config）。
    QDialog::accept();
}

void LogDialog::open(QWidget *parent)
{
    LogDialog dialog(nullptr, parent);
    dialog.exec();
}
