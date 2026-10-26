#pragma once

#include <QVBoxLayout>
#include <QWidget>

class TerminalView;

// P7b：tmux pane 容器（0x8de1a8 语义最小重建）：QPROPERTY name(nameChanged 信号)
// +paneId(int)；内容=TerminalView（原版 MuxPane 内嵌 TerminalWidget，重建直接以 view
// 做内容，见 F 节）。addChildWidget 语义由 setView 承担。
class MuxPane : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit MuxPane(int paneId, QWidget *parent = nullptr);

    int paneId() const { return m_paneId; }
    QString name() const { return m_name; }
    void setName(const QString &name)
    {
        if (m_name == name)
            return;
        m_name = name;
        emit nameChanged(m_name);
    }

    TerminalView *view() const { return m_view; }
    // 0x8de1a8 addChildWidget 语义：旧子 deleteLater→addWidget+setFocusProxy
    void setView(TerminalView *view);

signals:
    void nameChanged(const QString &name);

private:
    QVBoxLayout *m_layout;
    TerminalView *m_view = nullptr;
    int m_paneId;
    QString m_name;
};
