#pragma once

#include <QPointer>
#include <QVector>
#include <QWidget>

#include "transfer/TransferLabel.h"

class QHBoxLayout;
class QToolButton;
class TransferCenter;

// 原版 TransferBar（initUi 0x5858fe/createButtons 0x585528/createLabel 0x5850c6）：
// [TransferLabel(逐个 insertWidget 0), stretch, OpenButton, CloseButton]，HBox margins 0。
// 懒建触发=TransferCenter taskEvent(kind 0)（每任务一行 TransferLabel——0x5850c6 实证
// TransferLabel_ctor(path,bar)+insertWidget(layout,0)+show）。label destroyed 无剩余→
// bar close（0x585c8f：qt_qFindChildren_helper(TransferLabel) 空→QWidget::close）。
// OpenButton("Show All" 0xc8aa78)→关 bar+开 TransferPane（0x585f10）。
// 刷新（0x58722a）：taskEvent(4)→对应行 label refresh（100% 完成语/红失败/30s 自删）。
class TransferBar : public QWidget
{
    Q_OBJECT

public:
    explicit TransferBar(QWidget *parent = nullptr);

    // 懒建装配点：连 TransferCenter 信号（MainWindow/测试调用一次）
    void hookTransferCenter(TransferCenter *center);

protected:
    void showEvent(QShowEvent *event) override;

private:
    TransferLabel *labelFor(const QString &path) const;
    void createLabel(const QString &path, bool upload); // 0x5850c6 createLabel 同构
    void refreshLabel(const QString &path);             // 0x58722a 刷新链落点

    QHBoxLayout *m_layout;
    QToolButton *m_openButton;
    QToolButton *m_closeButton;
    QPointer<TransferCenter> m_center;
    // 行键→上传方向（label 由 findChildren 取;方向建后不可变,存副表）
    QHash<QString, bool> m_uploadByPath;
};
