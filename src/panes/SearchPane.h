#pragma once

#include "KitPane.h"

class QComboBox;
class QPushButton;
class QToolButton;

// 原版 SearchPane（0x74efe6 族）重建：find 历史 QComboBox（可编辑）+ 7 选项 QPushButton
// （QSignalMapper）+ CloseButton + 7 QToolButton（king:: 图标，RTL 插入，Alt+X/C/W/N/I/O/T
// 快捷键）；选项表 0x74d90c：matchRegex/matchCase/matchWholeWord/searchSelection/
// searchIncremental/searchWrap/searchContext——全部 checkable，无 scope 项。
// 执行链 0x74f5ac/0x74d488：pattern 存+历史更新（QSettings find/where）→执行→状态栏 4s 消息
// →视图回调。信号 patternChanged/optionsChanged。
// shortcut: FileGrep 跨会话搜索+::Find Result 视图挂账(0x5eac66)
class SearchPane : public KitPane
{
    Q_OBJECT

public:
    explicit SearchPane(QWidget *parent = nullptr);

    // FindOptions 构造（TerminalView 侧结构）；只含匹配引擎消费的字段
    struct Options
    {
        bool regex = false;
        bool caseSensitive = false;
        bool wholeWord = false;
        bool wrap = true;
    };
    Options options() const;
    QString pattern() const;

    // showPane 聚焦点（原版显示后聚焦 find 编辑框——Text.Find showPane 语义）
    void focusFindEdit();

signals:
    void patternChanged(const QString &pattern);
    void optionsChanged();
    // 执行（Return/选项钮触发）：参数=useSelection（searchSelection 选项在位时 true）
    void findRequested(bool useSelection, bool backward);

private:
    void emitFind(bool backward);

    QComboBox *m_findCombo;
    // 7 选项钮（顺序=0x74d90c 选项表）；7 QToolButton 同序（图标条）
    QVector<QPushButton *> m_optionButtons;
    QVector<QToolButton *> m_iconButtons;
};
