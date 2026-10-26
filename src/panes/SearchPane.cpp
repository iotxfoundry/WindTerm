#include "SearchPane.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSettings>
#include <QShortcut>
#include <QSignalMapper>
#include <QToolButton>
#include <QVBoxLayout>

#include "core/LocaleManager.h"
#include "core/ThemeManager.h"
#include "widgets/KingIcons.h"
#include "widgets/TerminalView.h"

namespace {
// 选项表（0x74d90c 顺序）：matchRegex/matchCase/matchWholeWord/searchSelection/
// searchIncremental/searchWrap/searchContext——全部 checkable；无 scope 项
const QStringList kOptions = {
    QStringLiteral("matchRegex"), QStringLiteral("matchCase"), QStringLiteral("matchWholeWord"),
    QStringLiteral("searchSelection"), QStringLiteral("searchIncremental"),
    QStringLiteral("searchWrap"), QStringLiteral("searchContext"),
};
} // namespace

SearchPane::SearchPane(QWidget *parent)
    : KitPane(parent, QStringLiteral("SearchPane"))
    , m_findCombo(new QComboBox(this))
{
    // find 历史（0x74f5ac：QSettings property find/where——重建 QSettings 简化）
    m_findCombo->setEditable(true);
    m_findCombo->setObjectName(QStringLiteral("FindEdit"));
    QSettings settings;
    m_findCombo->addItems(settings.value(QStringLiteral("find.history")).toStringList());

    auto *mapper = new QSignalMapper(this);
    connect(mapper, static_cast<void (QSignalMapper::*)(int)>(&QSignalMapper::mappedInt),
            this, [this](int index) {
        QPushButton *b = m_optionButtons.value(index);
        if (!b)
            return;
        b->setChecked(!b->isChecked()); // 全部 checkable 切换
        emit optionsChanged();
        // searchSelection 切换即以选区执行（0x74d90c 选项钮语义——执行链 0x74f5ac）
        if (kOptions.at(index) == QLatin1String("searchSelection"))
            emitFind(false);
    });
    auto *optionRow = new QHBoxLayout;
    for (int i = 0; i < kOptions.size(); ++i) {
        auto *b = new QPushButton(kOptions.at(i), this);
        b->setFocusPolicy(Qt::NoFocus);
        b->setCheckable(true);
        connect(b, &QPushButton::clicked, mapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
        mapper->setMapping(b, i);
        optionRow->addWidget(b);
        m_optionButtons.append(b);
    }

    auto *closeButton = new QToolButton(this);
    closeButton->setIcon(KingIcons::icon(QStringLiteral("close"), ThemeManager::instance().currentTheme()));
    closeButton->setAutoRaise(true);
    connect(closeButton, &QToolButton::clicked, this, &QWidget::hide);

    // 7 QToolButton 图标条（RTL 布局插入=倒序 append 后翻转——视觉在右；QShortcut
    // Alt+X/C/W/N/I/O/T WindowShortcut→click）
    static const char kShortcuts[] = "XCWNIOT";
    auto *iconRow = new QHBoxLayout;
    for (int i = kOptions.size() - 1; i >= 0; --i) { // RTL：倒序插入
        auto *tb = new QToolButton(this);
        tb->setIcon(KingIcons::icon(kOptions.at(i), ThemeManager::instance().currentTheme()));
        tb->setCheckable(true);
        tb->setToolTip(kOptions.at(i));
        auto *sc = new QShortcut(QKeySequence(QStringLiteral("Alt+%1").arg(QLatin1Char(kShortcuts[i]))), this);
        sc->setContext(Qt::WindowShortcut);
        connect(sc, &QShortcut::activated, tb, &QToolButton::click);
        connect(tb, &QToolButton::toggled, this, [this](bool) { emit optionsChanged(); });
        iconRow->addWidget(tb);
        m_iconButtons.append(tb);
    }

    connect(m_findCombo->lineEdit(), &QLineEdit::returnPressed, this, [this]() { emitFind(false); });

    auto *row = new QHBoxLayout;
    row->addWidget(m_findCombo, 1);
    row->addLayout(optionRow);
    row->addWidget(closeButton);
    row->addLayout(iconRow);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(4, 4, 4, 4);
    layout->addLayout(row);
}

SearchPane::Options SearchPane::options() const
{
    Options o;
    const auto byName = [this](const char *name) -> QAbstractButton * {
        const QString n = QLatin1String(name);
        for (QPushButton *b : m_optionButtons)
            if (b->text() == n)
                return b;
        return nullptr;
    };
    if (auto *b = byName("matchRegex"))
        o.regex = b->isChecked();
    if (auto *b = byName("matchCase"))
        o.caseSensitive = b->isChecked();
    if (auto *b = byName("matchWholeWord"))
        o.wholeWord = b->isChecked();
    if (auto *b = byName("searchWrap"))
        o.wrap = b->isChecked();
    return o;
}

QString SearchPane::pattern() const
{
    return m_findCombo->currentText();
}

void SearchPane::focusFindEdit()
{
    if (auto *edit = m_findCombo->lineEdit())
        edit->setFocus(Qt::OtherFocusReason);
    m_findCombo->setFocus(Qt::OtherFocusReason);
}

// 执行链（0x74f5ac/0x74d488）：pattern 存+历史更新→执行→状态栏 4s 消息→视图回调
void SearchPane::emitFind(bool backward)
{
    const QString pattern = m_findCombo->currentText();
    if (pattern.isEmpty())
        return;
    QSettings settings;
    QStringList history = settings.value(QStringLiteral("find.history")).toStringList();
    history.removeAll(pattern);
    history.prepend(pattern);
    while (history.size() > 20)
        history.removeLast();
    settings.setValue(QStringLiteral("find.history"), history);
    if (m_findCombo->findText(pattern) < 0)
        m_findCombo->addItem(pattern);

    bool useSelection = false;
    for (QPushButton *b : m_optionButtons) {
        if (b->text() == QLatin1String("searchSelection"))
            useSelection = b->isChecked();
    }
    emit patternChanged(pattern);
    emit findRequested(useSelection, backward);
}
