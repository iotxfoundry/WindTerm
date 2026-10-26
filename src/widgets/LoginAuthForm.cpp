#include "widgets/LoginAuthForm.h"

#include <QFormLayout>
#include <QLabel>
#include <QLayoutItem>
#include <QLineEdit>
#include <QTimer>

LoginAuthForm::LoginAuthForm(QWidget *parent)
    : QWidget(parent)
{
    // 0x00592e5a：QFormLayout objectName "Keyboard Interactive"，rowWrapPolicy=2
    m_form = new QFormLayout(this);
    m_form->setObjectName(QStringLiteral("Keyboard Interactive"));
    m_form->setRowWrapPolicy(QFormLayout::RowWrapPolicy(2)); // WrapAllRows（原版常量 2）
    // 占位：prompts 未到时 "Retrieving prompts, please wait..."
    auto *wait = new QLabel(tr("Retrieving prompts, please wait..."), this);
    m_form->addRow(wait);
    m_fields.reserve(4);
}

void LoginAuthForm::setPrompts(const QString &name, const QString &instruction,
                               const QStringList &prompts)
{
    // 与旧表逐项比对相同则跳过（防重复，0x00594366）
    if (name == m_name && instruction == m_instruction && prompts == m_prompts)
        return;
    m_name = name;
    m_instruction = instruction;
    m_prompts = prompts;
    QTimer::singleShot(0, this, &LoginAuthForm::rebuildRows);
}

void LoginAuthForm::rebuildRows()
{
    // 清旧行重建（新一轮 prompts——0x00629dea rc==3 再入时"prompts 表比对后插新行"）
    while (m_form->rowCount() > 0) {
        const QFormLayout::TakeRowResult row = m_form->takeRow(0);
        delete row.labelItem;
        delete row.fieldItem;
    }
    m_fields.clear();
    // name+instruction 合并一个 QLabel（顺序不定，静态不可分辨——name 在前即可）
    QString head = m_name;
    if (!m_instruction.isEmpty())
        head += (head.isEmpty() ? QString() : QStringLiteral("\n")) + m_instruction;
    if (!head.isEmpty())
        m_form->addRow(new QLabel(head, this));
    for (const QString &p : m_prompts) {
        auto *label = new QLabel(p, this);
        auto *field = new QLineEdit(this);
        field->setEchoMode(QLineEdit::Password); // echo 标志读后丢弃，全部掩码（0x00629dea）
        m_form->addRow(label, field);
        // returnPressed 焦点推进链（0x005941e2）
        connect(field, &QLineEdit::returnPressed, this, [this, field] { advanceFocus(field); });
        m_fields.append(field);
    }
    if (!m_fields.isEmpty())
        m_fields.first()->setFocus();
}

QMap<QString, QString> LoginAuthForm::collect() const
{
    // 0x005961b0：遍历 rowCount，itemAt(i, FieldRole)→QLineEdit，key=labelForField
    // 文本 trimmed，value=text()，同 key 覆盖
    QMap<QString, QString> out;
    for (int i = 0; i < m_form->rowCount(); ++i) {
        QLayoutItem *fieldItem = m_form->itemAt(i, QFormLayout::FieldRole);
        auto *field = fieldItem ? qobject_cast<QLineEdit *>(fieldItem->widget()) : nullptr;
        if (!field)
            continue; // 非输入行（name/instruction 行等）跳过
        const QLabel *label = qobject_cast<QLabel *>(m_form->labelForField(field));
        if (!label)
            continue;
        out.insert(label->text().trimmed(), field->text()); // QMap insert=同 key 覆盖
    }
    return out;
}

// 焦点推进（returnPressed→advanceFocus）：焦点到相邻输入行；最后一行→accepted
// （0x005941e2 语义：最后行回车=QDialogButtonBox accepted）
void LoginAuthForm::advanceFocus(QLineEdit *from)
{
    const int idx = m_fields.indexOf(from);
    if (idx >= 0 && idx + 1 < m_fields.size()) {
        m_fields.at(idx + 1)->setFocus();
        return;
    }
    emit accepted();
}
