#pragma once

#include <QDialog>
#include <functional>

class QCheckBox;
class QLabel;
class QPlainTextEdit;
class QSpinBox;

// 0x006caf18 ctor / 0x006ca94a setup（s_king__start_6ca94a）/ 0x006ca710 connect /
// 0x006ca4f8 统计刷新 / 0x006ca484 行数统计 / 0x006ca2de tab 宽 / 0x006ca36a 单发 QTimer /
// 0x006ca260 按钮分派 / 0x006ca438 showEvent。
class PasteDialog : public QDialog
{
    Q_OBJECT

public:
    // 0x006caf18：m_result 初值 1；0x006ca260：OK(改字 "&Paste")→1，"&Send Line By Line"→2
    enum Result { Paste = 1, SendLineByLine = 2 };

    PasteDialog(const QString &text, QWidget *parent = nullptr);

    Result result() const { return static_cast<Result>(m_result); }

    // 接线面：模态弹出；接受后回调 (整段文本, 模式)，行拆分由调用方按模式处理。
    static void open(QWidget *parent, const QString &text,
                     std::function<void(const QString &, int mode)> onPaste);

protected:
    void showEvent(QShowEvent *event) override; // 0x006ca438

private:
    void refreshStats(); // 0x006ca4f8

    int m_result = Paste;        // +0x30
    QString m_text;              // +0x38（ctor 参数存入，setPlainText 用）
    QCheckBox *m_tabSpaces;      // +0x48 "&Convert tab to spaces:"
    QCheckBox *m_crlfToCr;       // +0x40 "Convert CRLF and LF to CR"
    QSpinBox *m_tabWidth;        // +0x50
    QLabel *m_stats;             // +0x68
    QPlainTextEdit *m_preview;   // +0x70
};
