#pragma once

#include <QDialog>
#include <QString>

class QLineEdit;

// 最小 SSH 连接对话框：host / user / port / password。
// parseSpec() 解析地址栏的 "ssh [user@]host[:port]"，供 MainWindow 预填。
class ConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDialog(QWidget *parent = nullptr);

    QString host() const;
    QString user() const;
    QString password() const;
    int port() const;

    void setSpec(const QString &user, const QString &host, int port);

    // 解析 "ssh [user@]host[:port]"；text 可以不带 "ssh " 前缀。
    // 返回是否解析出非空 host；user/port 缺省时分别置空/22。
    static bool parseSpec(const QString &text, QString *user, QString *host, int *port);

private:
    QLineEdit *m_host;
    QLineEdit *m_user;
    QLineEdit *m_port;
    QLineEdit *m_password;
};
