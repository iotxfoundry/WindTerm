#pragma once

#include <QWidget>

#include "core/VtFilter.h"

class LocalSession;
class QPlainTextEdit;

class TerminalView : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalView(const QString &sessionName, QWidget *parent = nullptr);

    void attachSession(LocalSession *session);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void appendSystemMessage(const QString &text);

    QPlainTextEdit *m_gutter;
    QPlainTextEdit *m_main;
    LocalSession *m_session;
    VtFilter m_vtFilter;
};
