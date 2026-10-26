#pragma once

#include <QDialog>
#include <functional>

class QLabel;
class QLineEdit;
class QDialogButtonBox;

// 0x006bd7f6 ctor / 0x006bd50c layout / 0x006bd34a connect / 0x006bd960 setTexts /
// 0x006bdced OK 门控 lambda / 0x006bd94e text()。
// 原版 QLineEdit 为 searchEdit 定制样式（FUN_0058e0ce），骨架用普通 QLineEdit（挂账）。
class NameDialog : public QDialog
{
    Q_OBJECT

public:
    // 0x006bd7f6：标题 = tr("Create"/"Rename") + ' ' + name（0xd992f9 为单空格拼接串）；
    // 提示 = tr("Enter a name for the new %1.")（0xc9da79，新建）/
    //        tr("Enter a new name for \"%1\".")（0xc9daa4，改名，由 0x006bd960 切换）。
    enum class Mode { Create, Rename };

    NameDialog(Mode mode, const QString &name, QWidget *parent = nullptr);

    QString text() const; // 0x006bd94e

    // 接线面（菜单接线由主 agent 统一做）：模态弹出，接受时回调输入文本。
    static void open(QWidget *parent, const QString &title, const QString &label,
                     const QString &defaultText, std::function<void(QString)> onOk);

private:
    QLabel *m_prompt;        // +0x48
    QDialogButtonBox *m_box; // +0x40
    QLineEdit *m_edit;       // +0x50
};
