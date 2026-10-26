#pragma once

#include <QDialog>

class QLineEdit;
class QRadioButton;

// 0x006b874c ctor / 0x006b765e setup（s_session_userLogFilePath_6b765e）/
// 0x006b888e accept 落键 / 0x006b73a2 connect。
// 键名实证（accept 反编译）：session.userLogFilePath / userLogPattern /
// userLogOption / userLogType——非任务书预想的 session.log*。
class LogDialog : public QDialog
{
    Q_OBJECT

public:
    // 0x006b874c：标题 "Log Dialog"（0xc9d724，QDialog 上下文）；参数=宿主 QObject
    // （设置读写经其 global setting 接口，0x006b888e），骨架走 WindConfig 单例（挂账）。
    explicit LogDialog(QObject *settingsHost, QWidget *parent = nullptr);

    QString filePath() const;
    QString pattern() const;
    int logType() const;   // 2=Printable / 14=All（0x006b888e：checked→14 否则 2）
    int logOption() const; // 1=Overwrite / 2=Append（0x006b888e：Append checked→2）

    // 接线面（只读初值；accept 写回不足挂账——原版经宿主 FUN_0083d3d0 落 JSON）
    static void open(QWidget *parent);

protected:
    void accept() override; // 0x006b888e：写回四键 + QDialog::accept

private:
    QObject *m_host;             // +0x38
    QLineEdit *m_filePath;       // +0x40（原版为 filterline 定制件，骨架用 QLineEdit 挂账）
    QLineEdit *m_pattern;        // +0x48
    QRadioButton *m_printable;   // +0x50 "&Printable output"（0xc9d67c）→ 2
    QRadioButton *m_all;         // +0x58 "&All session output"（0xc9d68e）→ 14
    QRadioButton *m_overwrite;   // +0x68 "&Overwrite log file"（0xc9d6a2）→ 1
    QRadioButton *m_append;      // +0x60 "&Append log file"（0xc9d6b6）→ 2
};
