#pragma once

#include <QDialog>

class QLineEdit;

class SessionSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SessionSettingsDialog(QWidget *parent = nullptr);

public slots:
    void accept() override;

private:
    QLineEdit *m_nameEdit;
};
