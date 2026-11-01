#pragma once

#include <QIcon>
#include <QList>
#include <QMetaObject>
#include <QString>
#include <QToolBar>
#include <QVariant>

class QButtonGroup;
class QToolButton;
class QWidget;

// KitBar —— 语料 QToolBar 子类(五级装配链 L1 附件;MainWindow+0x50)。
// 语料落点:
//   ctor            FUN_008b31b6(420B,decomp-part-0027.c:71172)
//   尾装            FUN_008b3178(62B,0027:71156):layout() 非空 →
//                   setContentsMargins/setSpacing(Ghidra 实参折叠 — cited)
//   标题            King::registerBarsAndPanes(&out,"KitBar")→
//                   setWindowTitle(out)@008b3287(King 面未落库 → cited)
//   addKit          FUN_008b346e(9743B,0027:71330)= 工具栏按钮装配面,
//                   唯一调用者 s_HistoryHints_7664a2(0023:33200,
//                   +0x50=KitBar,+0x58=QStackedWidget)—— 真身化(见 .cpp)
//   QMetaObject     0x11aaea0(revision 8,methodCount=1@idx4;信号
//                   kitActivated(int)@0xce43e0 字符串区 —— 二进制实证)
// 成员槽:+0x30 QList(节点 0x18{int index,QString title,QWidget* btn};
//   FUN_008b5d90 append/FUN_008b5ae0 detach_grow/FUN_008b2fbc 析构实证,
//   FUN_008b337e/008b33c2 查询消费)/+0x38 FUN_008b305c 惰性 spacer
//   (addWidget 返回,批 77 "消费点未读" 结案)/+0x40 惰性 QButtonGroup
//   (addKit S9 实证)。另证基上成员 +0x60 = actionFactory 指针
//   (FUN_00767b36,9B,消费)—— 布局缺口 +0x48..0x58 未解,暂不入
//   成员表(cited — wave-2)。
class KitBar : public QToolBar {
    Q_OBJECT

public:
    explicit KitBar(QWidget *parent);   // FUN_008b31b6

    // FUN_008b346e(9743B,0027:71330):King kit 按钮装配唯一入口
    void addKit(int index, const QString &title, const QString &iconName);

    QToolButton *buttonForIndex(int index) const;                // FUN_008b337e(67B)
    QToolButton *buttonForTitle(const QString &title) const;     // FUN_008b33c2(100B)
    void setCheckedByIndex(int index, bool checked);             // FUN_008b3426(36B)
    void setCheckedByTitle(const QString &title, bool checked);  // FUN_008b344a(36B)

signals:
    // 信号 0(emit 面 FUN_0091a518(51B)→ QMetaObject::activate;
    //   static_metacall FUN_0091a54c(58B)/qt_metacall@0091a5c8 ——
    //   moc 承接,methodCount=1 与语料 metaobject 对齐)
    void kitActivated(int index);

private:
    void tailAssemble();                // FUN_008b3178
    QToolButton *makeToolButton(const QString &text, const QString &toolTip,
                                const QIcon &icon, bool checkable); // FUN_008b30f2(126B)
    void addKitButtonToBar(QWidget *btn, bool force);               // FUN_008b305c(141B)

    // +0x30 节点型(0x18:int/QString/QWidget*,FUN_008b5d90 实证)
    struct KitEntry
    {
        int index;
        QString title;
        QToolButton *button;
    };

    QList<KitEntry> m_f30;  // +0x30
    QWidget *m_f38;         // +0x38(惰性 spacer 的 addWidget 返回,FUN_008b305c)
    QButtonGroup *m_f40;    // +0x40(惰性互斥组,addKit S9)
};
