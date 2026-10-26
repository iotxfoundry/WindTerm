// LoginAuthForm — SSH keyboard-interactive 认证页（深逆 0x00592e5a/0x00594366/0x00595e52/
// 0x005941e2/0x005961b0 照搬）：
// - 认证页=QWidget 内 QFormLayout（objectName "Keyboard Interactive"），setRowWrapPolicy(2)
//   （=WrapAllRows，原版值 2）
// - 两阶段：无 prompts 时占位 QLabel "Retrieving prompts, please wait..."；prompts 到达
//   （信号驱动）→QTimer::singleShot(0) 插行；与旧表逐项比对相同则跳过（防重复）
// - name+instruction 合并一个 QLabel（原版合并顺序静态不可分辨——name 在前即可）
// - 逐 prompt 一行：label=prompt 文本，field=QLineEdit setEchoMode(Password)
//   （echo 标志读后丢弃，全部掩码——0x00629dea 实证）
// - returnPressed 焦点推进相邻输入行；最后一行回车=QDialogButtonBox accepted 语义（0x005941e2）
// - collect()（0x005961b0）：遍历 FieldRole QLineEdit（非输入行跳过——原版跳前两个
//   name/instruction 行），key=labelForField 文本 trimmed，value=text()，同 key 覆盖
// shortcut: Login Wizard 壳未建,auth 页以 QDialog 承载(0x00592e5a 结构照搬),wizard 迁移挂账
#pragma once

#include <QMap>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QWidget>

class QFormLayout;
class QLabel;
class QLineEdit;

class LoginAuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginAuthForm(QWidget *parent = nullptr);

    // prompts 到达（worker 信号驱动）：与旧表逐项比对相同则跳过；不同→singleShot(0) 插行
    void setPrompts(const QString &name, const QString &instruction, const QStringList &prompts);

    // 0x005961b0 收集：QMap<trimmed(label), text()>，同 key 覆盖
    QMap<QString, QString> collect() const;

    // 焦点推进（0x005941e2）：相邻输入行；最后一行→accepted 信号（测试驱动用）
    void advanceFocus(QLineEdit *from);

signals:
    void accepted(); // 最后一行回车 = QDialogButtonBox accepted 语义（0x005941e2）

private:
    void rebuildRows(); // QTimer::singleShot(0) 落点（0x00594366 延迟插行）

    QFormLayout *m_form;
    QVector<QLineEdit *> m_fields; // 输入行序（焦点推进链）
    QString m_name;
    QString m_instruction;
    QStringList m_prompts;
};
