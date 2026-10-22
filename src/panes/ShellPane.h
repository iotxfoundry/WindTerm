#pragma once

#include <QWidget>

class QLineEdit;
class QPlainTextEdit;

class ShellPane : public QWidget
{
    Q_OBJECT

public:
    explicit ShellPane(QWidget *parent = nullptr);

private:
    QLineEdit *m_commandEdit;
    QPlainTextEdit *m_outputEdit;
};
