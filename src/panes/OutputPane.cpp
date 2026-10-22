#include "OutputPane.h"

OutputPane::OutputPane(QWidget *parent)
    : QPlainTextEdit(parent)
{
    setReadOnly(true);
    setPlainText(QStringLiteral("[output placeholder]\n[output placeholder]\n[output placeholder]"));
}
