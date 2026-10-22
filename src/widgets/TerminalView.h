#pragma once

#include <QWidget>

class LocalSession;
class QPlainTextEdit;
class ScreenModel;
class VtParser;

class TerminalView : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalView(const QString &sessionName, QWidget *parent = nullptr);
    ~TerminalView() override;

    void attachSession(LocalSession *session);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void appendSystemMessage(const QString &text);
    void renderScreen();

    QPlainTextEdit *m_gutter;
    QPlainTextEdit *m_main;
    LocalSession *m_session;
    ScreenModel *m_screen;
    VtParser *m_parser;
};
