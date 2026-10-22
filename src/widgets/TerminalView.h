#pragma once

#include <QWidget>

class QPlainTextEdit;

class TerminalView : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalView(const QString &sessionName, QWidget *parent = nullptr);

private:
    QPlainTextEdit *m_gutter;
    QPlainTextEdit *m_main;
};
