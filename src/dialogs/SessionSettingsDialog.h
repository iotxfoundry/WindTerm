#pragma once

#include <QDialog>
#include <QVariantMap>

class QComboBox;
class QLineEdit;
class QStackedWidget;

// 新建/编辑会话（原版完整设置树 Session/Appearance/Behavior… 多分类挂账，核心字段先行）。
// ctor entry 空=新建，非空=编辑（字段预填+未编辑键保留）。
// shortcut: 密码入加密凭据库(原版体系未逆),对话框不存密码
class SessionSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SessionSettingsDialog(QWidget *parent = nullptr,
                                   const QVariantMap &entry = QVariantMap());

    QVariantMap entryValue() const;

public slots:
    void accept() override;

private:
    QWidget *createSshPage();
    QWidget *createShellPage();
    QWidget *createSerialPage();
    QWidget *createTelnetPage();

    QVariantMap m_base;   // 编辑态原条目（entryValue 从此拷贝再覆盖）
    QLineEdit *m_label;
    QLineEdit *m_group;
    QComboBox *m_protocol;
    QStackedWidget *m_pages;
    QMap<QString, QLineEdit *> m_edits;   // 按键名取页字段（target/port/arguments…）
    QMap<QString, QComboBox *> m_combos;  // Serial 下拉字段
};
