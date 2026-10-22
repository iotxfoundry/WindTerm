#pragma once

#include <QDialog>

class QLineEdit;

class MasterPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MasterPasswordDialog(QWidget *parent = nullptr);

public slots:
    void accept() override;

private:
    QLineEdit *m_passwordEdit;
};
