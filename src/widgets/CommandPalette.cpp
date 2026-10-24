#include "widgets/CommandPalette.h"

#include <QApplication>
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QFileInfo>
#include <QIODevice>
#include <QKeyEvent>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QMenuBar>
#include <QPushButton>
#include <QRegularExpression>
#include <QShowEvent>
#include <QShortcut>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QDir>
#include <QFile>
#include <algorithm>

#include "core/ActionRegistry.h"
#include "core/Assets.h"
#include "core/JsonText.h"
#include "core/LocaleManager.h"
#include "core/ScriptHost.h"
#include "core/ThemeManager.h"
#include "widgets/ActionIcons.h"

#ifdef WINDTERM_HAVE_QJSENGINE
#include <QJSEngine>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QQmlEngine>
#endif

namespace {

// 0x5431c6 prefixMatch：prefix 末字符字母数字先补空格+text.startsWith 区分大小写
bool prefixMatches(const QString &text, const char *prefix)
{
    QString p = QString::fromLatin1(prefix);
    if (!p.isEmpty() && p.at(p.size() - 1).isLetterOrNumber())
        p += QLatin1Char(' ');
    return text.startsWith(p, Qt::CaseSensitive);
}

// 0x583e8e 全匹配语义：f 逐字符 escape 以 ".*" 连接并 ^…$ 锚定→capturedLength==条目全长。
// 大小写不敏感为简化（原 pattern 构造未逆明——挂账）
QRegularExpression fuzzyWholeRegExp(const QString &f)
{
    QString pattern = QStringLiteral("^");
    for (const QChar &c : f)
        pattern += QRegularExpression::escape(c) + QStringLiteral(".*");
    pattern += QLatin1Char('$');
    return QRegularExpression(pattern, QRegularExpression::CaseInsensitiveOption);
}

} // namespace

CommandPalette::CommandPalette(ActionFactory factory, QWidget *parent)
    : QFrame(parent)
    , m_factory(std::move(factory))
{
    // 0x5403f6 ctor：objectName/attr 0x37(WA_DeleteOnClose)/Frame 6+0x30/autoFillBackground(false)
    setObjectName(QStringLiteral("CommandPalette"));
    setAttribute(Qt::WA_DeleteOnClose);
    setAutoFillBackground(false);
    setFrameShadow(QFrame::Sunken);
    setFrameShape(QFrame::StyledPanel); // decomp setFrameShape(6)=StyledPanel
    m_focusSnapshot = QApplication::focusWidget(); // +0x60 快照（先于 searchEdit 抢焦点）
    buildUi();
    // 0x5403f6 尾段：installEventFilter(parent)→vt6 宿主 Resize 跟随重定位
    if (parentWidget())
        parentWidget()->installEventFilter(this);
}

void CommandPalette::buildUi()
{
    // 0x53e936 s_BackwardButton 段：searchEdit(+0x48)+CountLabel(+0x58)+BackwardButton(+0x38)+ListView(+0x50)
    m_searchEdit = new QLineEdit(this);
    m_searchEdit->setFocus(Qt::ActiveWindowFocusReason); // 原版 setFocus(3)

    m_countLabel = new QLabel(this);
    m_countLabel->setObjectName(QStringLiteral("CountLabel"));

    // 原版 SideButton（QPushButton 子类 flat 0x58d562）；tooltip tr 串 0xca795e 读不出，
    // 骨架用 tr("Backward")（挂账）——"text (快捷键)"，快捷键=Return（0x53e9cf KeySequence(0xd)）
    m_backwardButton = new QPushButton(this);
    m_backwardButton->setObjectName(QStringLiteral("BackwardButton"));
    m_backwardButton->setFlat(true);
    m_backwardButton->setIcon(ActionIcons::iconFor(QStringLiteral("king::left"),
                                                   ThemeManager::instance().currentTheme()));
    m_backwardButton->setToolTip(tr("Backward") + QStringLiteral(" (%1)").arg(
        QKeySequence(Qt::Key_Return).toString(QKeySequence::NativeText)));
    m_backwardButton->hide();
    // QShortcut(Return, ctx3=WidgetWithChildrenShortcut)→click（0x53eb3d/0x53eb4e）
    auto *returnShortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    returnShortcut->setContext(Qt::WidgetWithChildrenShortcut);
    connect(returnShortcut, &QShortcut::activated, m_backwardButton, &QPushButton::click);
    connect(m_backwardButton, &QPushButton::clicked, this, [this] { goBack(); });

    // 0x583bac ListView_ctor：iconSize 默认、行上限夹 1..9（构造设 9）、clicked=activated 同链
    m_listView = new QListView(this);
    m_listView->setResizeMode(QListView::Adjust);                       // setResizeMode(1)
    m_listView->setSelectionBehavior(QAbstractItemView::SelectRows);    // setSelectionBehavior(1)
    m_listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(m_listView, &QAbstractItemView::clicked, m_listView, &QAbstractItemView::activated);

    auto *row = new QHBoxLayout;
    row->addWidget(m_backwardButton);
    row->addWidget(m_searchEdit, 1);
    row->addWidget(m_countLabel);
    auto *lay = new QVBoxLayout(this);
    lay->addLayout(row);
    lay->addWidget(m_listView);

    m_model = new QStandardItemModel(this);
    m_listView->setModel(m_model);

    connect(m_searchEdit, &QLineEdit::textChanged, this, &CommandPalette::onTextChanged);
    connect(m_listView, &QAbstractItemView::activated, this, &CommandPalette::dispatch);
    // 0x5436ce Esc 过滤证据仅在 ListView；searchEdit 同款为骨架扩展
    m_listView->installEventFilter(this);
    m_searchEdit->installEventFilter(this);

    // 0x53e2f0 focusOut：焦点离开且新焦点非面板子孙且非 QMenuBar→close（空焦点不关）
    connect(qApp, &QApplication::focusChanged, this, [this](QWidget *, QWidget *now) {
        if (!isVisible() || now == nullptr || isAncestorOf(now)
            || qobject_cast<QMenuBar *>(now))
            return;
        close();
    });
}

// palette JS 宿主注入（0x54334c mode7：panel 脚本经 MainWindow 的 ScriptHost 引擎求值——
// QJSValue 不可跨 QJSEngine，必须共享同一实例）。宿主就绪即扫 palettes 目录（数据文件
// 一手证据：global/palettes/*.palette → assets/palettes/ 同源拷贝）。
void CommandPalette::setScriptHost(ScriptHost *host)
{
#ifdef WINDTERM_HAVE_QJSENGINE
    m_scriptHost = host;
    loadPalettes();
#else
    Q_UNUSED(host);
#endif
}

// 0x53fc54 CommandPalette_open：清历史+基准 mode3+prefix 补空格段+设初值
void CommandPalette::open(const QString &prefix)
{
    m_history.clear(); // 0x53fab6 段
    m_baseMode = 3;    // +0x71 = 3
    QString p = prefix;
    if (!p.isEmpty() && p.at(p.size() - 1).isLetterOrNumber())
        p += QLatin1Char(' '); // 0x53fc78 补空格段
    if (m_searchEdit->text() != p)
        m_searchEdit->setText(p); // 触发 textChanged→前缀路由
    else
        onTextChanged(p);         // 同值手动走链（0x53fcab）
}

// 0x54334c onTextChanged：仅历史栈 <2（无下钻）才做前缀路由
void CommandPalette::onTextChanged(const QString &text)
{
    if (m_history.size() < 2) {
        // 已在 palette 模式且 trigger 仍匹配：filterEvent（0x54334c JS 分支——进入后
        // textChanged 走过滤链，仅新 trigger 才重新 enter）
        if (m_activePalette && m_mode == 7 && text.startsWith(m_activePalette->trigger)) {
            m_filterText = text;
            applyFilter(); // filterEvent→items 重建
            return;
        }
        m_mode = 0;
        // mode7 palette trigger 前缀路由（0x54334c filterEvent JS 分支：trigger 匹配即
        // 切 palette 模式，优先于默认 mode3——palette 文件一手证据）
        PaletteDef *def = paletteMatch(text);
        if (def) {
            m_activePalette = def;
            switchMode(7, text); // mode7=palette 文件模式（前缀字符 DAT 未逆的 keyMode 项）
            return;
        }
        m_activePalette = nullptr;
        if (prefixMatches(text, ">"))
            switchMode(1, text);   // ">"→全部 action
        else if (prefixMatches(text, "m"))
            switchMode(2, text);   // "m"→mux/tmux 词过滤
        else
            switchMode(m_baseMode ? m_baseMode : 3, text); // 空前缀恒匹配尾段（0x5434e2）
    } else {
        applyFilter(); // 已下钻：filterEvent JS（0x5433a4）未接——挂账，直接重过滤
    }
}

// 0x542e86 s_KeyMode：模式分派+清历史+压栈重建
void CommandPalette::switchMode(int mode, const QString &text)
{
    // 旧 keyMode leaveEvent JS（0x542eca）未逆——挂账
    m_mode = mode;
    m_filterText = text; // FUN_005836a6 缓存过滤文本
    m_history.clear();   // 0x53fab6 清历史
    switch (mode) {
    case 7: // palette 文件模式：enterEvent JS→items 建 model（0x54334c JS 分支链）
        if (m_activePalette) {
            const QString filter = text.mid(m_activePalette->trigger.size());
            enterPalette(*m_activePalette, filter);
        }
        break;    case 2:
        buildList({QStringLiteral("mux"), QStringLiteral("tmux")}); // 0x542f1b 词表
        break;
    // mode 4/5/6（地址类/会话标题格式）前缀字符 DAT 常量读不出——挂账不实现
    case 1: // ">" 全部 action
    case 3: // Anything 默认——静态前缀映射 0x53feaa 未逆，列表=动作集（挂账）
    default:
        buildList({});
        break;
    }
}

// 0x541896 actionid_to_menu_title：遍历 ActionRegistry；词表过滤=id 首段（'.' 前）
// lowercase 在表内（0x541a57）；text 剥 "&(?!&)"。原版标题由 id 推导+": "拼接（camelCase
// 分割 0x541958）——骨架直用 wind.actions text，未走 locale（挂账）
void CommandPalette::buildList(const QStringList &idWords)
{
    m_fullIds.clear();
    m_fullTexts.clear();
    static const QRegularExpression ampersand(QStringLiteral("&(?!&)"));
    const QStringList ids = ActionRegistry::instance().actionIds();
    for (const QString &id : ids) {
        if (!idWords.isEmpty()
            && !idWords.contains(id.section(QLatin1Char('.'), 0, 0).toLower()))
            continue;
        QString text = ActionRegistry::instance().actionText(id);
        if (text.isEmpty())
            continue; // 0x541f17 空 title 丢弃
        text.replace(ampersand, QString());
        m_fullIds.append(id);
        m_fullTexts.append(text);
    }
    // 0x53f00a param_5=1：压历史栈 {全量条目, text, mode}
    m_history.append({m_fullIds, m_fullTexts, m_searchEdit->text(), m_mode});
    applyFilter();
}

// 0x583e8e listFilter_applyRegExp + 0x664cd0 proxy_filterAccepts 简化：
// 模糊整串正则（capturedLength==全长才保留）+ QString::compare 序（0x6660fb6/0x666282a
// 打分公式未逐行逆明——挂账简化）+ 取前 m_maxRows（0x6664bfd）；原 proxy invalidate 链简化为
// 单模型直接重建（挂账）
void CommandPalette::applyFilter()
{
    // mode7 palette：filterable=false 语义=不做本地过滤（items 由 JS filterEvent 全权决定，
    // 两 palette 文件均 filterable:false——一手证据）。textChanged→filterEvent→items 重建
#ifdef WINDTERM_HAVE_QJSENGINE
    if (m_mode == 7 && m_activePalette) {
        runPaletteEvent(QStringLiteral("filterEvent"), m_filterText.mid(m_activePalette->trigger.size()));
        return;
    }
#endif
    QString f = m_filterText;
    if (m_mode == 1 && f.startsWith(QLatin1Char('>')))
        f.remove(0, 1);
    else if (m_mode == 2 && f.startsWith(QStringLiteral("m ")))
        f.remove(0, 2);
    f = f.trimmed(); // 0x583f2c trimmed

    const QRegularExpression re = fuzzyWholeRegExp(f);
    QVector<int> kept;
    for (int i = 0; i < m_fullTexts.size(); ++i) {
        if (!f.isEmpty()) {
            const auto m = re.match(m_fullTexts.at(i));
            if (!m.hasMatch() || m.capturedLength() != m_fullTexts.at(i).size())
                continue; // 0x583e8e：整串全匹配才保留
        }
        kept.append(i);
    }
    std::sort(kept.begin(), kept.end(), [this](int a, int b) {
        return m_fullTexts.at(a).compare(m_fullTexts.at(b), Qt::CaseInsensitive) < 0;
    });
    if (kept.size() > m_maxRows)
        kept.resize(m_maxRows); // 0x6664bfd 取前 N

    m_model->removeRows(0, m_model->rowCount());
    for (int i : kept) {
        auto *item = new QStandardItem(m_fullTexts.at(i));
        item->setData(m_fullIds.at(i), Qt::UserRole); // 原 role 1=data
        const QIcon ic = ActionIcons::iconFor(
            m_fullIds.at(i), ActionRegistry::instance().actionIcon(m_fullIds.at(i)),
            ThemeManager::instance().currentTheme());
        if (!ic.isNull())
            item->setIcon(ic); // 原 role 0x101=icon（骨架映射 DecorationRole）
        item->setData(1, Qt::UserRole + 8); // 原 role 0x108=kind；重建恒 1=action
        m_model->appendRow(item);
    }
    // 0x53e806 countChanged：CountLabel=行数+BackwardButton 显隐=历史栈>1
    m_countLabel->setNum(m_model->rowCount());
    m_backwardButton->setVisible(m_history.size() > 1);
    m_listView->setCurrentIndex(m_model->index(0, 0)); // 首行选中（0x53ecd4 链）
    adjustSize();
}

// 0x53fd52 goBack：弹栈恢复 {model,text,mode}；单层栈 size<2 直返
void CommandPalette::goBack()
{
    if (m_history.size() < 2)
        return;
    m_history.removeLast();
    const HistoryEntry &top = m_history.last();
    m_mode = top.mode;
    m_filterText = top.text;
    m_fullIds = top.ids;
    m_fullTexts = top.texts;
    const QSignalBlocker blocker(m_searchEdit); // 原版 filterline_setText 不走 textChanged 链
    m_searchEdit->setText(top.text);
    applyFilter();
}

// 0x5436e2 script_fireEvent kind 表：重建项恒 kind1=action → QAction::activate(Trigger)。
// kind3 会话部件激活（0x5b91a8）/kind5 文本回填下钻无数据源——挂账
void CommandPalette::dispatch(const QModelIndex &index)
{
#ifdef WINDTERM_HAVE_QJSENGINE
    if (m_mode == 7 && m_activePalette) { // kind7 palette：Enter→commitEvent（0x5436e2 kind 表）
        runPaletteEvent(QStringLiteral("commitEvent"),
                        m_filterText.mid(m_activePalette->trigger.size()));
        m_activePalette = nullptr; // commit 链终点（closeEvent 的 leave 不再触发——
                                   // goto-line commit 已 removeRegister，重复 leave 误还原滚动）
        close();
        return;
    }
#endif
    if (!index.isValid() || index.data(Qt::UserRole + 8).toInt() != 1 || !m_factory)
        return;
    if (QAction *action = m_factory(index.data(Qt::UserRole).toString())) {
        action->activate(QAction::Trigger);
        action->deleteLater();
    }
}

// 0x5401d6：宽=宿主宽 44%（+1 取整）夹 contentsRect、水平居中、贴上缘
void CommandPalette::reposition()
{
    QWidget *host = parentWidget();
    if (!host)
        return;
    int w = qRound((host->width() + 1) * 0.44);
    w = qMin(w, host->contentsRect().width() + 1);
    adjustSize();
    resize(w, height());
    move((host->width() - w) / 2, 0);
}

void CommandPalette::showEvent(QShowEvent *event)
{
    reposition(); // 骨架在 show 算位（原版 ctor+vt6 宿主 Resize 跟随——两处均接）
    QFrame::showEvent(event);
}

void CommandPalette::closeEvent(QCloseEvent *event)
{
    // 0x544126 closeEvent：mode7 leaveEvent JS（palette 挂账解除：Esc/焦点离开→还原链）
#ifdef WINDTERM_HAVE_QJSENGINE
    if (m_activePalette)
        runPaletteEvent(QStringLiteral("leaveEvent"),
                        m_filterText.mid(m_activePalette->trigger.size()));
    m_activePalette = nullptr;
#endif
    setVisible(false); // 先落焦点链，防 restoreFocus 触发 focusChanged 递归 close
    if (QWidget *snap = m_focusSnapshot.data()) {
        if (snap->isVisibleTo(window()))
            snap->setFocus(Qt::OtherFocusReason);
        // else 原版回退 0x767b4a 激活主窗格——骨架无对应机制（挂账）
    }
    event->accept();
}

bool CommandPalette::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == parentWidget() && event->type() == QEvent::Resize)
        reposition(); // vt6：宿主 Resize 跟随（0x008f65e0 CommandPalette_vt6）
    else if (event->type() == QEvent::KeyPress
             && static_cast<QKeyEvent *>(event)->key() == Qt::Key_Escape) {
        close(); // 0x5436ce：Esc→close
        return true;
    }
    return QFrame::eventFilter(watched, event);
}

#ifdef WINDTERM_HAVE_QJSENGINE
// ═══ mode7 palette 文件模式（global/palettes/*.palette 一手证据落地）═══
// 加载：Assets::dir()/palettes/*.palette；文件结构 {trigger,comment,filterable,events,script}
// ——script 是 (event,filter,selection)=>{…} 签名（返回 items 数组）。实测两文件裸换行在
// "script" 字符串内（同 wind.actions 控制字符陷阱）——复用 JsonText 净化后 QJsonDocument 解析。
void CommandPalette::loadPalettes()
{
    m_palettes.clear();
    if (!m_scriptHost)
        return;
    QDir dir(Assets::dir() + QStringLiteral("/palettes"));
    for (const QFileInfo &fi : dir.entryInfoList({ QStringLiteral("*.palette") }, QDir::Files)) {
        QFile f(fi.absoluteFilePath());
        if (!f.open(QIODevice::ReadOnly))
            continue;
        const QJsonDocument doc = QJsonDocument::fromJson(
            JsonText::replaceControlCharsInStrings(JsonText::stripLineComments(f.readAll())));
        if (!doc.isObject())
            continue;
        const QJsonObject o = doc.object();
        PaletteDef def;
        def.trigger = o.value(QStringLiteral("trigger")).toString();
        def.filterable = o.value(QStringLiteral("filterable")).toBool(false);
        for (const QString &ev : o.value(QStringLiteral("events")).toString()
                                        .split(QLatin1Char(','), Qt::SkipEmptyParts))
            def.events.append(ev.trimmed());
        // 0x54334c 链：script 串经 ScriptHost 共享引擎 evaluate（"use strict" 前缀同 runInit）
        QJSValue script = m_scriptHost->evaluateScript(
            o.value(QStringLiteral("script")).toString(), fi.fileName());
        if (def.trigger.isEmpty() || !script.isCallable())
            continue;
        def.script = script;
        m_palettes.append(def);
    }
}

// trigger 前缀路由（0x54334c：text.startsWith(trigger) 切 palette 模式；区分大小写同 prefixMatch）
CommandPalette::PaletteDef *CommandPalette::paletteMatch(const QString &text) const
{
    for (const PaletteDef &def : m_palettes) {
        if (!def.trigger.isEmpty() && text.startsWith(def.trigger, Qt::CaseSensitive))
            return const_cast<PaletteDef *>(&def);
    }
    return nullptr;
}

// enterEvent：调 script(event,filter,selection)→items 建 model（0x54334c JS 分支进入段）
void CommandPalette::enterPalette(PaletteDef &def, const QString &filter)
{
    QJSValueList args;
    args.append(QJSValue(QStringLiteral("enterEvent")));
    args.append(QJSValue(filter));
    args.append(QJSValue(QJSValue::UndefinedValue)); // selection 未逆明取值——挂账
    QJSValue items = def.script.call(args);
    setItemsFromJs(items);
}

// filterEvent/leaveEvent/commitEvent 分发（0x54334c filterEvent 分支 + closeEvent leave +
// dispatch commit——事件名查 events 表防线外注入；返回值仅 filter/commit 建 model 需求，
// leaveEvent 无 items 原版语义如此——goto-line leaveEvent 只还原滚动）
void CommandPalette::runPaletteEvent(const QString &event, const QString &filter)
{
    if (!m_activePalette || !m_activePalette->events.contains(event))
        return;
    QJSValueList args;
    args.append(QJSValue(event));
    args.append(QJSValue(filter));
    args.append(QJSValue(QJSValue::UndefinedValue));
    QJSValue items = m_activePalette->script.call(args);
    if (event != QLatin1String("leaveEvent"))
        setItemsFromJs(items);
}

// items[{title,subtitle,icon}] → model（kind7 项：title=显示列、subtitle→ToolTipRole 骨架
// 映射、icon→king:: 名直查 ActionIcons；role 0x108=7 与 dispatch kind 分支对齐）
void CommandPalette::setItemsFromJs(const QJSValue &items)
{
    m_model->removeRows(0, m_model->rowCount());
    m_fullIds.clear();
    m_fullTexts.clear();
    const int len = items.property(QStringLiteral("length")).toInt();
    for (int i = 0; i < len; ++i) { // 全量建行；ListView 呈现上限由视图侧滚动承载
        const QJSValue it = items.property(static_cast<quint32>(i));
        const QString title = it.property(QStringLiteral("title")).toString();
        auto *item = new QStandardItem(title);
        const QString subtitle = it.property(QStringLiteral("subtitle")).toString();
        if (!subtitle.isEmpty())
            item->setToolTip(subtitle);
        const QString icon = it.property(QStringLiteral("icon")).toString();
        if (!icon.isEmpty()) {
            const QIcon ic = ActionIcons::iconFor(icon, icon,
                                                  ThemeManager::instance().currentTheme());
            if (!ic.isNull())
                item->setIcon(ic);
        }
        item->setData(7, Qt::UserRole + 8); // kind7=palette item（0x5436e2 kind 表）
        m_model->appendRow(item);
    }
    // CountLabel=行数（0x53e806）；palette 无 Backward 下钻语义——栈保持空
    m_countLabel->setNum(m_model->rowCount());
    m_backwardButton->setVisible(false);
    m_listView->setCurrentIndex(m_model->index(0, 0));
    adjustSize();
}
#endif // WINDTERM_HAVE_QJSENGINE
