#pragma once

#include <QFrame>
#include <QPointer>

class QAction;
class QLabel;
class QMenu;
class SftpTransfer;
class TransferCenter;

// 原版 TransferLabel（0x8f17c0 元对象/TransferBar_createLabel 0x5850c6 建链）：单任务行——
// QFrame + 路径名（elide 30 空格宽,0x58722a 0x1e 门）+ 内嵌 ActionButton（king::up/down
// 方向箭头）+ 下拉菜单（暂停/恢复/移除——0x61b176/0x61b206/0x61b2a8 收口）。
// 刷新（0x58722a s_transfer_currentItemName）：weightPercent==100 → 完成语
// （"%1 %2"=%1 动词 downloaded/uploaded+名称）+失败红字 `<font color="red">%1 %2</font>`+
// 30s 后 deleteLater（QTimer::singleShotImpl(30000) 实证）；运行→"Time left: %1"
// （0xc8ab43 段）；Paused→图标换 king::paused；tooltip=属性 map HTML 表（0x617aea）。
// label destroyed 无剩余 → bar close（0x585c8f qFindChildren TransferLabel 空→close）。
class TransferLabel : public QFrame
{
    Q_OBJECT

public:
    // direction=true=上传（king::up 箭头）/false=下载（king::down）
    TransferLabel(TransferCenter *center, const QString &path, bool upload,
                  QWidget *parent = nullptr);

    QString path() const { return m_path; }
    // 0x58722a 原样复刻：按属性 map 刷文案/图标/tooltip；100% 且无失败→30s 自删
    void refresh();

signals:
    void lastLabelClosed(); // 0x585c8f：无剩余 TransferLabel → bar close

protected:
    // 0x585c8f：destroyed 链等效——析构时若无剩余行则收 bar
    ~TransferLabel() override;

private:
    void openMenu(); // ActionButton 下拉：暂停/恢复/移除

    TransferCenter *m_center;
    QString m_path;
    bool m_upload;
    QLabel *m_icon = nullptr;   // pie 图/状态图标位
    QLabel *m_text = nullptr;   // elide 30 空格宽文本 + 状态后缀
    QAction *m_pauseAction = nullptr; // 文案随状态 Pause/Resume（wind.actions TransferPane.Pause）
    QMenu *m_menu = nullptr;
    bool m_completed = false;
};
