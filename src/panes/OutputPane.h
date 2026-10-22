#pragma once

#include <QPlainTextEdit>

class OutputPane : public QPlainTextEdit
{
    Q_OBJECT

public:
    explicit OutputPane(QWidget *parent = nullptr);
};
