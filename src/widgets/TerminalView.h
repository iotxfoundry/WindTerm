#pragma once

#include <QWidget>

class Session;
class QContextMenuEvent;
class QPlainTextEdit;
class ScreenModel;
class VtParser;

class TerminalView : public QWidget
{
    Q_OBJECT

public:
    explicit TerminalView(const QString &sessionName, QWidget *parent = nullptr);
    ~TerminalView() override;

    void attachSession(Session *session);
    Session *session() const { return m_session; }

    // quickbar "Send Text" 命令（0x56d890）：文本直接写入会话
    void sendText(const QString &text);

signals:
    // 0x84005a TerminalWidget/0x834f2c TerminalView contextMenuEvent → MainWindow 弹 View Popup
    void contextMenuRequested(const QPoint &globalPos, Qt::KeyboardModifiers mods);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private:
    void appendSystemMessage(const QString &text);
    void renderScreen();

    QPlainTextEdit *m_gutter;
    QPlainTextEdit *m_main;
    Session *m_session;
    ScreenModel *m_screen;
    VtParser *m_parser;
};
