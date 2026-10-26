#pragma once

#include "KitPane.h"

class QLineEdit;
class QPlainTextEdit;

class ShellPane : public KitPane
{
    Q_OBJECT

public:
    explicit ShellPane(QWidget *parent = nullptr);

private:
    QLineEdit *m_commandEdit;
    QPlainTextEdit *m_outputEdit;
};
