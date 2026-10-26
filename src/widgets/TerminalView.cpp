#include "TerminalView.h"

#include <QApplication>
#include <QClipboard>
#include <QContextMenuEvent>
#include <QFontMetricsF>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QRegularExpression>
#include <QScrollBar>
#include <algorithm>

#include "core/LocalSession.h"
#include "core/Session.h"
#include "core/SchemeManager.h"
#include "core/ScreenModel.h"
#include "core/ThemeManager.h"
#include "core/VtParser.h"
#include "core/WindConfig.h"
#include "tmux/Tmux.h"

namespace {

// 键→序列映射（xterm 编码）。appCursor=DECCKM(mode 1)：方向/HOME/END 发 SS3 形态；
// mods=xterm 修饰位（Shift=1/Alt=2/Ctrl=4，参数 = 1+mods）：Ctrl+←→ 词跳、Shift+方向选择区
QByteArray keyToSequence(int key, int mods, bool appCursor)
{
    const bool mod = mods != 0;
    auto csi = [mod, mods](const char *suffix) {
        return mod ? QByteArrayLiteral("\x1b[1;") + QByteArray::number(1 + mods) + suffix
                   : QByteArrayLiteral("\x1b[") + suffix;
    };
    auto tilde = [mod, mods](int n) {
        return mod ? QByteArrayLiteral("\x1b[") + QByteArray::number(n) + ';'
                       + QByteArray::number(1 + mods) + '~'
                   : QByteArrayLiteral("\x1b[") + QByteArray::number(n) + '~';
    };
    switch (key) {
    case Qt::Key_Up:        return appCursor && !mod ? QByteArrayLiteral("\x1bOA") : csi("A");
    case Qt::Key_Down:      return appCursor && !mod ? QByteArrayLiteral("\x1bOB") : csi("B");
    case Qt::Key_Right:     return appCursor && !mod ? QByteArrayLiteral("\x1bOC") : csi("C");
    case Qt::Key_Left:      return appCursor && !mod ? QByteArrayLiteral("\x1bOD") : csi("D");
    case Qt::Key_Home:      return appCursor && !mod ? QByteArrayLiteral("\x1bOH") : csi("H");
    case Qt::Key_End:       return appCursor && !mod ? QByteArrayLiteral("\x1bOF") : csi("F");
    case Qt::Key_Insert:    return tilde(2);
    case Qt::Key_Delete:    return tilde(3);
    case Qt::Key_PageUp:    return tilde(5);
    case Qt::Key_PageDown:  return tilde(6);
    case Qt::Key_F1:        return mod ? QByteArrayLiteral("\x1bO1;") + QByteArray::number(1 + mods) + 'P'
                                       : QByteArrayLiteral("\x1bOP");
    case Qt::Key_F2:        return mod ? QByteArrayLiteral("\x1bO1;") + QByteArray::number(1 + mods) + 'Q'
                                       : QByteArrayLiteral("\x1bOQ");
    case Qt::Key_F3:        return mod ? QByteArrayLiteral("\x1bO1;") + QByteArray::number(1 + mods) + 'R'
                                       : QByteArrayLiteral("\x1bOR");
    case Qt::Key_F4:        return mod ? QByteArrayLiteral("\x1bO1;") + QByteArray::number(1 + mods) + 'S'
                                       : QByteArrayLiteral("\x1bOS");
    case Qt::Key_F5:        return tilde(15);
    case Qt::Key_F6:        return tilde(17);
    case Qt::Key_F7:        return tilde(18);
    case Qt::Key_F8:        return tilde(19);
    case Qt::Key_F9:        return tilde(20);
    case Qt::Key_F10:       return tilde(21);
    case Qt::Key_F11:       return tilde(23);
    case Qt::Key_F12:       return tilde(24);
    default:
        return {};
    }
}

// scheme 缺失时回退（与 attachSession 的 ScreenModel 缺省一致）
QColor schemeColor(const QString &name, const QColor &fallback)
{
    const QColor color = SchemeManager::instance().color(name);
    return color.isValid() ? color : fallback;
}

} // namespace

// 选区色叠加（scheme "text.selection"，缺省 #805050FF 半透明矩形）
QColor TerminalView::selectionColor() const
{
    QColor c = SchemeManager::instance().color(QStringLiteral("text.selection"));
    if (!c.isValid())
        c = QColor(QStringLiteral("#805050FF"));
    return c;
}

TerminalView::TerminalView(const QString &sessionName, QWidget *parent)
    : QAbstractScrollArea(parent)
    , m_session(nullptr)
    , m_screen(nullptr)
    , m_parser(nullptr)
{
    Q_UNUSED(sessionName); // 占位内容已删（NoSessions），参数保留兼容调用方
    // 原版 TextView（MuxPane 终端区）以类名挂 objectName（0x005c6d16），驱动 gui.theme TextView 规则
    setObjectName(QStringLiteral("TextView"));
    viewport()->setAttribute(Qt::WA_OpaquePaintEvent);
    viewport()->setFocusPolicy(Qt::StrongFocus);
    setFrameShape(QFrame::NoFrame);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // 终端字体：text.fontFamily1/fontSize（0xa52aa8 cell 度量源）
    m_font = QFont(WindConfig::instance().valueToString(QStringLiteral("text.fontFamily1"),
                                                        QStringLiteral("Roboto Mono")));
    m_font.setPointSizeF(WindConfig::instance().valueToDouble(QStringLiteral("text.fontSize"), 10));
    m_font.setFixedPitch(true);
    setFont(m_font);

    const QFontMetricsF fm(m_font);
    m_cellW = qMax<qreal>(1.0, fm.horizontalAdvance(QLatin1Char('W')));
    m_cellH = qMax<qreal>(1.0, fm.lineSpacing());

    // 光标闪烁（caret_blinkTimer 0xa63550：text.caretBlink/caretPeriod/caretShape 配置键）
    m_caretBlink = WindConfig::instance().valueToDouble(QStringLiteral("text.caretBlink"), 1.0) != 0.0;
    m_caretShape = int(WindConfig::instance().valueToDouble(QStringLiteral("text.caretShape"), 0));
    const qreal period = WindConfig::instance().valueToDouble(QStringLiteral("text.caretPeriod"), 1.0);
    m_caretTimer.setInterval(int(qBound<qreal>(0.1, period, 5.0) * 1000));
    connect(&m_caretTimer, &QTimer::timeout, this, [this]() {
        if (!m_screen || !m_screen->cursorVisible())
            return;
        m_caretOn = !m_caretOn;
        // 块样式+光标行可见才 blink（0xa63550）；仅重画光标 cell 微区
        const QRect r = cursorCellRect();
        if (r.isValid())
            viewport()->update(r.adjusted(-1, -1, 1, 1));
    });
    if (m_caretBlink)
        m_caretTimer.start();
}

TerminalView::~TerminalView()
{
    delete m_parser;
    delete m_screen;
}

void TerminalView::attachSession(Session *session)
{
    m_session = session;
    if (!m_session)
        return;

    delete m_parser;
    delete m_screen;

    m_defaultFg = schemeColor(QStringLiteral("terminal.ansiWhite"), QColor(QStringLiteral("#e3e3dd")));
    m_defaultBg = schemeColor(QStringLiteral("line.background"), QColor(QStringLiteral("#272822")));

    // window.scrollbackLimit(原版键,0x7cc8aa;默认值未逆,1000 缺省)
    m_screen = new ScreenModel(24, 80, m_defaultFg, m_defaultBg,
                               WindConfig::instance().valueToString(
                                   QStringLiteral("window.scrollbackLimit"), QStringLiteral("1000")).toInt());
    m_parser = new VtParser(m_screen);
    m_systemMessage.clear();
    m_selAnchor = m_selEnd = QPoint(-1, -1);

    viewport()->setFocus();
    applyResize();

    // 0xa64cea 数据流：output→feed→重绘
    connect(m_session, &Session::output, this, [this](const QByteArray &data) {
        if (m_tmux) {
            // 输出分流（0x7e9a32）：tmux control 流喂 Tmux，透传行经 vtOutput 回流
            m_tmux->feedData(data);
            return;
        }
        const bool atBottom = verticalScrollBar()->value() >= verticalScrollBar()->maximum();
        m_parser->feed(data);
        updateScrollRange();
        if (atBottom) // 新输出锚底；用户上滚回看时不强拉
            verticalScrollBar()->setValue(verticalScrollBar()->maximum());
        // shortcut: 增量行级重画(原版脏行范围)挂账,先全量保正确
        viewport()->update();
        emit caretPositionChanged();
    });

    // tmux control 模式检测（0x7e9a06 挂账谓词；仅 LocalSession 参数判定）
    if (auto *ls = qobject_cast<LocalSession *>(session); ls && ls->tmuxControl())
        enableTmuxMode();

    connect(m_session, &Session::finished, this, [this]() {
        m_systemMessage = tr("[进程已退出]");
        viewport()->update();
    });
}

void TerminalView::sendText(const QString &text)
{
    if (m_session)
        m_session->write(text.toUtf8());
}

// ── P7b：tmux pane 视图（0x8de1a8 内嵌 TerminalWidget 语义）──

// 无会话建屏：attachSession 屏建段同款（scheme 缺省色+scrollbackLimit；无 parser 不建——
// pane 视图 VT 由 feedVtData 喂，VtParser 仅在有屏时构造）
void TerminalView::ensureScreenModel(int cols, int rows)
{
    if (m_screen) {
        resizeScreen(cols, rows);
        return;
    }
    m_defaultFg = schemeColor(QStringLiteral("terminal.ansiWhite"), QColor(QStringLiteral("#e3e3dd")));
    m_defaultBg = schemeColor(QStringLiteral("line.background"), QColor(QStringLiteral("#272822")));
    m_screen = new ScreenModel(rows, cols, m_defaultFg, m_defaultBg,
                               WindConfig::instance().valueToString(
                                   QStringLiteral("window.scrollbackLimit"),
                                   QStringLiteral("1000")).toInt());
    m_parser = new VtParser(m_screen);
    applyResize();
    updateScrollRange();
}

// 参数序对齐视图面（cols, rows）；ScreenModel 侧 (rows, cols)
void TerminalView::resizeScreen(int cols, int rows)
{
    if (!m_screen)
        return;
    m_screen->resizeScreen(rows, cols);
    applyResize();
    updateScrollRange();
    viewport()->update();
    emit screenSizeChanged();
}

// screenCaptured 整缓冲替换（0x877610 链）：reset 清滚回/模式后逐行 printText 重建——
// newline 在底行使溢出行自然沉 scrollback（scrollUp 语义）
void TerminalView::loadScreen(const QStringList &lines)
{
    if (!m_screen || !m_parser)
        return;
    m_selAnchor = m_selEnd = QPoint(-1, -1);
    m_screen->reset();
    for (int i = 0; i < lines.size(); ++i) {
        m_screen->printText(lines.at(i));
        m_screen->carriageReturn();
        if (i + 1 < lines.size())
            m_screen->newline();
    }
    updateScrollRange();
    verticalScrollBar()->setValue(verticalScrollBar()->maximum());
    viewport()->update();
    emit caretPositionChanged();
}

// tmux 输出回灌（MuxDesktop feedPaneView）：与 vtOutput 直通同管线
void TerminalView::feedVtData(const QByteArray &data)
{
    if (!m_parser)
        return;
    const bool atBottom = verticalScrollBar()->value() >= verticalScrollBar()->maximum();
    m_parser->feed(data);
    updateScrollRange();
    if (atBottom)
        verticalScrollBar()->setValue(verticalScrollBar()->maximum());
    viewport()->update();
    emit caretPositionChanged();
}

// 活动屏逐行纯文本（测试断言面）
QString TerminalView::plainText() const
{
    if (!m_screen)
        return QString();
    QStringList lines;
    for (int r = 0; r < m_screen->rows(); ++r) {
        QString line;
        for (int c = 0; c < m_screen->cols(); ++c)
            line += m_screen->cellAt(r, c).ch;
        lines.append(line);
    }
    return lines.join(QLatin1Char('\n'));
}

// tmux control 模式挂载（0x7e9a06：new Tmux 挂 +0x188+connect+emit entered——
// 骨架无 entered 信号面，挂账）；命令入口 view->tmux()->sendCommand。
void TerminalView::enableTmuxMode()
{
    if (m_tmux || !m_session)
        return;
    m_tmux = new Tmux(this);
    m_tmux->setWriter([this](const QByteArray &b) { m_session->write(b); });
    // 活动 pane 输出直喂 VT（0x7e6b64 显示中 pane 路径；与直通同管线）
    connect(m_tmux, &Tmux::vtOutput, this, [this](const QByteArray &data) {
        const bool atBottom = verticalScrollBar()->value() >= verticalScrollBar()->maximum();
        m_parser->feed(data);
        updateScrollRange();
        if (atBottom)
            verticalScrollBar()->setValue(verticalScrollBar()->maximum());
        viewport()->update();
        emit caretPositionChanged();
    });
    // %exit（0x7e9a1e）：销毁 Tmux+屏显 [exited(: reason)]，残余直通 VT
    connect(m_tmux, &Tmux::exited, this, [this](const QString &reason) {
        auto *t = m_tmux;
        m_tmux = nullptr;
        const QByteArray msg = reason.isEmpty()
                                 ? QByteArrayLiteral("[exited]\r\n")
                                 : "[exited: " + reason.toUtf8() + "]\r\n";
        m_parser->feed(msg);
        const QByteArray rest = t->takeBuffer();
        t->deleteLater();
        m_parser->feed(rest);
        viewport()->update();
        emit tmuxModeExited(); // P7b：宿主恢复 TerminalView 显示
    });
    // shortcut: tmux-256color DA 应答挂账(terms 文件,DA 65 身份),P7b
    m_tmux->start();
    // P7b：GUI 挂载点（MainWindow::attachMuxDesktop 经此信号接 MuxDesktop，0x8d9be0 链）
    emit tmuxModeEntered();
}

TerminalView *TerminalView::activeView()
{
    // 0x8d9764 焦点终端链骨架等价：焦点 widget 沿父链找 TerminalView
    for (QWidget *w = QApplication::focusWidget(); w; w = w->parentWidget())
        if (auto *view = qobject_cast<TerminalView *>(w))
            return view;
    return nullptr;
}

int TerminalView::caretLine() const
{
    // ScreenModel cursorY（0 基）；statusbar.config JS 侧 '+1'
    return m_screen ? m_screen->cursorY() : 0;
}

int TerminalView::caretLineOffset() const
{
    return m_screen ? m_screen->cursorX() : 0;
}

// ═══ palette JS API 面（*.palette 一手证据：goto-line.palette 用到的 text.* 契约）═══

// text.lineCount：全文行数（滚回+屏行——scrollTop 定位/上界语义）
int TerminalView::lineCount() const
{
    if (!m_screen)
        return 0;
    return (m_screen->alternateScreen() ? 0 : m_screen->scrollback().size()) + m_screen->rows();
}

// text.gotoLine(line-1)：0 基跳行（commitEvent 链）——目标行滚入视口（scroll 定位，
// scrollback 覆盖区纯滚动）+caret 移动（CSI d 等价 ScreenModel moveCursor 'd'，仅目标在
// 活动屏内时）
void TerminalView::gotoLine(int line)
{
    if (!m_screen)
        return;
    const int clamped = qBound(0, line, lineCount() - 1);
    verticalScrollBar()->setValue(qBound(0, clamped, verticalScrollBar()->maximum()));
    const int scrollbackCount = m_screen->alternateScreen() ? 0 : m_screen->scrollback().size();
    const int inScreen = clamped - scrollbackCount;
    if (inScreen >= 0) {
        m_screen->moveCursor('d', inScreen + 1);
        emit caretPositionChanged();
    }
    viewport()->update();
}

// text.selectionStartP()：选区起始全局位置——骨架无原版位置编解码，简化为 caret 绝对行
// 位置（goto-line 仅经 lineFromPosition 取当前行，caret 行语义等效——挂账注明）
int TerminalView::selectionStartP() const
{
    return caretLine();
}

QString TerminalView::scheme() const
{
    // SchemeManager 当前值（scheme.theme 全局单值；per-view 切换挂账）
    return ThemeManager::instance().currentTheme();
}

// 会话持久化 uuid（0x8bbab6 url="$<uuid>"）；无会话→空串
QString TerminalView::sessionUuid() const
{
    return m_session ? m_session->uuid() : QString();
}

// 0xa52aa8 horizontalAdvance 懒填缓存
qreal TerminalView::advanceOf(QChar ch)
{
    const quint32 code = ch.unicode();
    if (m_advanceCache.contains(code))
        return m_advanceCache.value(code);
    // shortcut: 双宽判定阈值近似(原版逐字符 UCS4 表),异常字体场景再补
    const qreal w = QFontMetricsF(m_font).horizontalAdvance(ch);
    m_advanceCache.insert(code, w);
    return w;
}

// 尺寸协商（0xa52aa8 等效：QFontMetrics cell 度量→rows/cols）：
// ScreenModel 扩缩+Session::resize（pty TIOCSWINSZ 链）+screenSizeChanged
void TerminalView::applyResize()
{
    const int rows = qMax(1, int(viewport()->height() / qMax<qreal>(1.0, m_cellH)));
    const int cols = qMax(1, int(viewport()->width() / qMax<qreal>(1.0, m_cellW)));
    m_windowRows = rows;
    m_windowColumns = cols;
    if (m_screen)
        m_screen->resizeScreen(rows, cols);
    if (m_session)
        m_session->resize(rows, cols);
    // statusbar.config JS 面：screenSizeChanged 驱动 Window %1×%2 applet
    emit screenSizeChanged();
}

void TerminalView::resizeEvent(QResizeEvent *event)
{
    QAbstractScrollArea::resizeEvent(event);
    const QFontMetricsF fm(m_font);
    m_cellW = qMax<qreal>(1.0, fm.horizontalAdvance(QLatin1Char('W')));
    m_cellH = qMax<qreal>(1.0, fm.lineSpacing());
    applyResize();
    updateScrollRange();
}

void TerminalView::updateScrollRange()
{
    if (!m_screen)
        return;
    // 滚回=scrollback 行 + 屏行（1049 alt 屏无滚回，VT 语义）
    const int total = (m_screen->alternateScreen() ? 0 : m_screen->scrollback().size()) + m_screen->rows();
    const int page = qMax(1, int(viewport()->height() / qMax<qreal>(1.0, m_cellH)));
    verticalScrollBar()->setRange(0, qMax(0, total - page));
    verticalScrollBar()->setPageStep(page);
    verticalScrollBar()->setValue(verticalScrollBar()->maximum()); // 新输出锚底
}

// 0xa64cea editor_paint_line_colors：垂直滚动 [scrollOffset,+可见行)，行来自
// scrollback 或活动屏；逐 cell 画 bg→文本（逐 cell 保正确，run 合并优化挂账）
void TerminalView::paintEvent(QPaintEvent *)
{
    QPainter p(viewport());
    p.setFont(m_font);
    const QColor defaultBg = m_screen ? m_screen->cellAt(0, 0).bg.isValid()
                                            ? m_screen->cellAt(0, 0).bg
                                            : m_defaultBg
                                      : m_defaultBg;
    p.fillRect(viewport()->rect(), defaultBg);
    if (!m_screen)
        return;

    const qreal cw = qMax<qreal>(1.0, m_cellW);
    const qreal ch = qMax<qreal>(1.0, m_cellH);
    const int scrollOffset = verticalScrollBar()->value();
    const int backLines = m_screen->alternateScreen() ? 0 : m_screen->scrollback().size();
    const int totalLines = backLines + m_screen->rows();
    const int firstLine = scrollOffset;
    const int lastLine = qMin(totalLines, firstLine + qMax(1, int(viewport()->height() / ch)));

    // 选区规范化（行序/列序修正）
    QPoint s0 = m_selAnchor, s1 = m_selEnd;
    if (s0.x() < 0 || s1.x() < 0)
        s0 = s1 = QPoint(-1, -1);
    else if (s0.y() > s1.y() || (s0.y() == s1.y() && s0.x() > s1.x()))
        qSwap(s0, s1);
    const QColor selColor = selectionColor();

    for (int line = firstLine; line < lastLine; ++line) {
        const int y = int((line - firstLine) * ch);
        for (int col = 0; col < m_screen->cols(); ++col) {
            const Cell cell = line < backLines ? m_screen->scrollback().at(line).value(col)
                                               : m_screen->cellAt(line - backLines, col);
            const QRectF cellRect(col * cw, y, cw, ch);

            QColor fg = cell.fg.isValid() ? cell.fg : m_defaultFg;
            QColor bg = cell.bg.isValid() ? cell.bg : defaultBg;
            if (cell.reverse)
                qSwap(fg, bg); // reverse=交换 fg/bg

            const bool selected = s0.x() >= 0
                && (line > s0.y() || (line == s0.y() && col >= s0.x()))
                && (line < s1.y() || (line == s1.y() && col <= s1.x()));
            if (selected) {
                // 选区色叠加（scheme text.selection，缺省 #805050FF 半透明）
                p.fillRect(cellRect, selColor);
            } else {
                p.fillRect(cellRect, bg);
            }

            // 高亮层叠加（选区层之后；40% 半透明与 text.selection 同管线注释——0x75c7 槽族，
            // paint 层叠顺序挂账）
            for (const HighlightSpan &h : m_highlights) {
                if (h.line == line && col >= h.colStart && col <= h.colEnd) {
                    QColor hc = h.color;
                    hc.setAlpha(102); // 40%
                    p.fillRect(cellRect, hc);
                    break;
                }
            }

            if (cell.bold) {
                QFont f = m_font;
                f.setBold(true);
                p.setFont(f);
            }
            p.setPen(fg);
            const QChar c = cell.ch;
            if (!c.isNull() && c != QLatin1Char(' ')) {
                p.drawText(cellRect, Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, QString(c));
            }
            if (cell.underline)
                p.drawLine(QPointF(cellRect.left(), y + ch - 1), QPointF(cellRect.right(), y + ch - 1));
            if (cell.bold)
                p.setFont(m_font);
        }
    }

    // 系统提示行（视图层元素，弱化灰；与滚回旧内容同色系）
    if (!m_systemMessage.isEmpty() && lastLine >= totalLines) {
        p.setPen(schemeColor(QStringLiteral("terminal.ansiBrightBlack"), QColor(QStringLiteral("#666666"))));
        p.drawText(QRectF(0, (m_screen->rows() - 1) * ch, viewport()->width(), ch),
                   Qt::AlignRight | Qt::AlignVCenter, m_systemMessage);
    }

    // 光标覆盖式绘制（caret_rect_render 0xa64838：先背景条再画文本，非 xor）；
    // 形态 text.caretShape：0 block（反色整 cell）/1 line（左缘竖条）/2 rectangle（边框）/3 underline（底缘条）
    if (m_screen->cursorVisible() && m_caretOn) {
        const QRect r = cursorCellRect();
        if (r.isValid()) {
            if (m_caretShape == 0)
                drawBlockCaret(p, r);
            else if (m_caretShape == 1)
                p.fillRect(r.left(), r.top(), 2, r.height(), m_defaultFg);
            else if (m_caretShape == 2)
                p.drawRect(r.adjusted(0, 0, -1, -1));
            else
                p.fillRect(r.left(), r.bottom() - 1, r.width(), 2, m_defaultFg);
        }
    }
}

// block：反色填充整 cell 再重画字符（覆盖式，0xa64838 模型）
void TerminalView::drawBlockCaret(QPainter &p, const QRect &r)
{
    p.save();
    p.fillRect(r, m_defaultFg);
    if (m_screen) {
        const Cell cell = m_screen->cellAt(m_screen->cursorY(), m_screen->cursorX());
        // 反色：字符用原背景色画在前景条上
        p.setPen(cell.bg.isValid() ? cell.bg : m_defaultBg);
        const QChar c = cell.ch;
        if (!c.isNull() && c != QLatin1Char(' '))
            p.drawText(QRectF(r), Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, QString(c));
    }
    p.restore();
}

// 光标 cell 矩形（viewport 坐标）：绝对行=scrollback+cursorY 映射进可见范围
QRect TerminalView::cursorCellRect() const
{
    if (!m_screen)
        return QRect();
    const int backLines = m_screen->alternateScreen() ? 0 : m_screen->scrollback().size();
    const int line = backLines + m_screen->cursorY();
    const int scrollOffset = verticalScrollBar()->value();
    const int visibleRows = qMax(1, int(viewport()->height() / qMax<qreal>(1.0, m_cellH)));
    if (line < scrollOffset || line >= scrollOffset + visibleRows)
        return QRect();
    return QRect(int(m_screen->cursorX() * m_cellW), int((line - scrollOffset) * m_cellH),
                 qMax(2, int(m_cellW)), qMax(2, int(m_cellH)));
}

// viewport 像素 → cell（col, 绝对行=viewport 行+scrollOffset）
QPoint TerminalView::cellFromPos(const QPoint &viewportPos) const
{
    if (!m_screen)
        return QPoint(-1, -1);
    const int col = int(viewportPos.x() / qMax<qreal>(1.0, m_cellW));
    const int row = int(viewportPos.y() / qMax<qreal>(1.0, m_cellH)) + verticalScrollBar()->value();
    return QPoint(qBound(0, col, m_screen->cols() - 1),
                  qBound(0, row, m_screen->scrollback().size() + m_screen->rows() - 1));
}

QChar TerminalView::charAtLine(int line, int col) const
{
    if (!m_screen || col < 0 || col >= m_screen->cols())
        return QChar();
    const int backLines = m_screen->alternateScreen() ? 0 : m_screen->scrollback().size();
    const Cell cell = line < backLines && line >= 0 ? m_screen->scrollback().at(line).value(col)
                                                    : m_screen->cellAt(line - backLines, col);
    return cell.ch;
}

QString TerminalView::selectedText() const
{
    if (!hasSelection() || !m_screen)
        return QString();
    QPoint s0 = m_selAnchor, s1 = m_selEnd;
    if (s0.y() > s1.y() || (s0.y() == s1.y() && s0.x() > s1.x()))
        qSwap(s0, s1);
    QString text;
    for (int line = s0.y(); line <= s1.y(); ++line) {
        if (line > s0.y())
            text += QLatin1Char('\n');
        const int endCol = line == s1.y() ? s1.x() : m_screen->cols() - 1;
        for (int col = line == s0.y() ? s0.x() : 0; col <= endCol; ++col)
            text += charAtLine(line, col);
        while (text.endsWith(QLatin1Char(' ')))
            text.chop(1);
    }
    return text;
}

void TerminalView::copySelection()
{
    if (hasSelection())
        QApplication::clipboard()->setText(selectedText());
}

void TerminalView::pasteClipboard()
{
    const QString text = QApplication::clipboard()->text();
    if (text.isEmpty())
        return;
    // bracketedPaste（ScreenModel 已跟踪 2004）：包 \x1b[200~ ... \x1b[201~
    const QByteArray bytes = (m_screen && m_screen->bracketedPaste())
                                 ? QByteArrayLiteral("\x1b[200~") + text.toUtf8() + QByteArrayLiteral("\x1b[201~")
                                 : text.toUtf8();
    if (m_session)
        m_session->write(bytes);
}

// 现有 eventFilter 键盘逻辑（keyToSequence/DECCKM/修饰键）迁移为 keyPressEvent（viewport focus）
void TerminalView::keyPressEvent(QKeyEvent *event)
{
    if (!m_session) {
        QAbstractScrollArea::keyPressEvent(event);
        return;
    }

    switch (event->key()) {
    case Qt::Key_C:
        if ((event->modifiers() & Qt::ControlModifier) && hasSelection()) {
            // 简化：有选区 Ctrl+C 复制选区，无选区落通用 text() 路径发 \x03（xterm 习惯）；
            // Ctrl+Shift+C/Copy 动作挂账
            copySelection();
            m_selAnchor = m_selEnd = QPoint(-1, -1);
            viewport()->update();
            return;
        }
        break;
    case Qt::Key_V:
        if (event->modifiers() & Qt::ControlModifier) {
            pasteClipboard();
            return;
        }
        break;
    case Qt::Key_Insert:
        if (event->modifiers() & Qt::ShiftModifier) {
            pasteClipboard();
            return;
        }
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        m_session->write(QByteArrayLiteral("\r"));
        return;
    case Qt::Key_Backspace:
        m_session->write(QByteArrayLiteral("\x7f"));
        return;
    case Qt::Key_Tab:
        m_session->write(QByteArrayLiteral("\t"));
        return;
    case Qt::Key_Escape:
        m_session->write(QByteArrayLiteral("\x1b"));
        return;
    default:
        break;
    }

    const int mods = ((event->modifiers() & Qt::ShiftModifier) ? 1 : 0)
                   | ((event->modifiers() & Qt::AltModifier) ? 2 : 0)
                   | ((event->modifiers() & Qt::ControlModifier) ? 4 : 0);
    QByteArray data = keyToSequence(event->key(), mods, m_screen && m_screen->mode(1) /* DECCKM */);
    if (data.isEmpty() && !event->text().isEmpty())
        data = event->text().toUtf8();
    if (!data.isEmpty()) {
        m_session->write(data);
        return;
    }
    QAbstractScrollArea::keyPressEvent(event);
}

// 鼠标上报（mouse_sgr_encode 0x7f298e 对齐）：DECSET 1000/1002/1003 + 1006(SGR) 时
// 事件编码上报终端，本地选区禁用；滚轮在 1000 模式也上报（64+0/1）
static int mouseReportMode(const ScreenModel *screen)
{
    if (!screen)
        return 0;
    if (screen->mode(1003))
        return 1003;
    if (screen->mode(1002))
        return 1002;
    if (screen->mode(1000))
        return 1000;
    return 0;
}

void TerminalView::sendMouseEvent(QEvent::Type type, Qt::MouseButton button,
                                  Qt::MouseButtons buttons, Qt::KeyboardModifiers mods,
                                  const QPoint &pos)
{
    const int mode = mouseReportMode(m_screen);
    if (!mode || !m_session)
        return;
    int cb = -1;
    bool pressSuffix = true;
    if (type == QEvent::MouseButtonPress || type == QEvent::MouseButtonDblClick) {
        cb = button == Qt::LeftButton ? 0 : button == Qt::MiddleButton ? 1 : button == Qt::RightButton ? 2 : -1;
    } else if (type == QEvent::MouseButtonRelease) {
        cb = button == Qt::LeftButton ? 0 : button == Qt::MiddleButton ? 1 : 2;
        pressSuffix = false;
    } else if (type == QEvent::MouseMove && (mode == 1003
               || (mode == 1002 && buttons != Qt::NoButton))) {
        // 运动事件：cb=(btn|3|mods)+32（0x7ebdfc 恒加 32 运动位），后缀 'm' 非 'M'
        const int btn = buttons & Qt::LeftButton ? 0 : buttons & Qt::MiddleButton ? 1
                      : buttons & Qt::RightButton ? 2 : 3;
        cb = btn + 32;
        pressSuffix = false;
        // 同格去重（0x7ebdfc：与上次坐标相同丢弃）
        const QPoint cell0 = cellFromPos(pos);
        if (cell0 == m_lastMouseCell)
            return;
        m_lastMouseCell = cell0;
    }
    if (cb < 0)
        return;
    // 修饰键位（0x7ebdfc 位级实证）：Shift=4 / Meta=8 / Ctrl=16 —— Alt 不编码
    const int mod = ((mods & Qt::ShiftModifier) ? 4 : 0)
                  | ((mods & Qt::MetaModifier) ? 8 : 0)
                  | ((mods & Qt::ControlModifier) ? 16 : 0);
    const QPoint cell = cellFromPos(pos);
    if (cell.x() < 0)
        return;
    // SGR 形态（0x7ebdfc '<%d;%d;%d%c'：坐标 1 基）；X10/1005/1015 形态挂账
    // shortcut: X10/UTF8(1005)/1015 形态未实现,SGR(1006) 为现代应用标准形态
    m_session->write(QByteArrayLiteral("\x1b[<") + QByteArray::number(cb + mod) + ';'
                     + QByteArray::number(cell.y() + 1) + ';' + QByteArray::number(cell.x() + 1)
                     + (pressSuffix ? 'M' : 'm'));
}

void TerminalView::wheelEvent(QWheelEvent *event)
{
    if (mouseReportMode(m_screen) && m_session) {
        // 滚轮（0x7ebdfc 位级）：delta 只取符号——>0→64(上)/<0→65(下)/==0 丢弃；每事件恒 1 条
        const int delta = event->angleDelta().y();
        if (delta != 0) {
            const int mod = ((event->modifiers() & Qt::ShiftModifier) ? 4 : 0)
                          | ((event->modifiers() & Qt::MetaModifier) ? 8 : 0)
                          | ((event->modifiers() & Qt::ControlModifier) ? 16 : 0);
            const int cb = (delta > 0 ? 64 : 65) + mod;
            const QPoint cell = cellFromPos(event->pos());
            m_session->write(QByteArrayLiteral("\x1b[<") + QByteArray::number(cb) + ';'
                             + QByteArray::number(qMax(1, cell.y() + 1)) + ';'
                             + QByteArray::number(qMax(1, cell.x() + 1)) + 'M');
        }
        event->accept();
        return;
    }
    QAbstractScrollArea::wheelEvent(event);
}

// 选区（0xa3e5ca：3px 位移阈值起选）
void TerminalView::mousePressEvent(QMouseEvent *event)
{
    sendMouseEvent(event->type(), event->button(), event->buttons(), event->modifiers(), event->pos());
    if (mouseReportMode(m_screen)) {
        event->accept();
        return; // 上报模式不本地选区
    }
    if (event->button() != Qt::LeftButton) {
        QAbstractScrollArea::mousePressEvent(event);
        return;
    }
    m_pressPos = event->pos();
    m_selecting = true;
    if (hasSelection()) {
        m_selAnchor = m_selEnd = QPoint(-1, -1);
        viewport()->update();
    }
}

void TerminalView::mouseMoveEvent(QMouseEvent *event)
{
    sendMouseEvent(event->type(), event->button(), event->buttons(), event->modifiers(), event->pos());
    if (mouseReportMode(m_screen)) {
        event->accept();
        return;
    }
    if (!m_selecting) {
        QAbstractScrollArea::mouseMoveEvent(event);
        return;
    }
    // 拖选 3px 阈值（0xa3e5ca）
    if (!hasSelection() && (event->pos() - m_pressPos).manhattanLength() < 3)
        return;
    m_selAnchor = m_selEnd = cellFromPos(event->pos());
    viewport()->update();
}

// 双击=词选（连续非空白 alnum_）
void TerminalView::mouseDoubleClickEvent(QMouseEvent *event)
{
    const QPoint cell = cellFromPos(event->pos());
    if (cell.x() < 0 || !m_screen) {
        mousePressEvent(event);
        return;
    }
    const auto isWordChar = [this, line = cell.y()](int col) {
        const QChar c = charAtLine(line, col);
        return c.isLetterOrNumber() || c == QLatin1Char('_');
    };
    if (isWordChar(cell.x())) {
        int left = cell.x(), right = cell.x();
        while (left > 0 && isWordChar(left - 1))
            --left;
        while (right < m_screen->cols() - 1 && isWordChar(right + 1))
            ++right;
        m_selAnchor = QPoint(left, cell.y());
        m_selEnd = QPoint(right, cell.y());
    } else {
        m_selAnchor = m_selEnd = cell;
    }
    m_selecting = true;
    m_pressPos = event->pos();
    viewport()->update();
}

void TerminalView::mouseReleaseEvent(QMouseEvent *event)
{
    sendMouseEvent(event->type(), event->button(), event->buttons(), event->modifiers(), event->pos());
    if (mouseReportMode(m_screen)) {
        event->accept();
        return;
    }
    if (event->button() == Qt::LeftButton) {
        m_selecting = false;
        // 双击词选后拖动扩展
        if (event->buttons() & Qt::LeftButton)
            m_selEnd = cellFromPos(event->pos());
    }
    QAbstractScrollArea::mouseReleaseEvent(event);
}

// 0x84005a/0x834f2c：原版按事件位置 + 修饰键弹 pane 菜单，节名由 MainWindow 拼 "View Popup"
void TerminalView::contextMenuEvent(QContextMenuEvent *event)
{
    emit contextMenuRequested(event->globalPos(), event->modifiers());
    event->accept();
}

void TerminalView::appendSystemMessage(const QString &text)
{
    m_systemMessage = text;
    viewport()->update();
}

// ═══ P4 终端搜索/高亮 ═══

// 全局文本位置 = line*10000+col（实现最简：cols<10000 恒成立；0x75c7 槽面 start/end 语义，
// 方法体未 dump 挂账——原版真编码未逆明）
QPair<int, int> TerminalView::posToCell(int pos) const
{
    return { pos / 10000, pos % 10000 };
}

void (*TerminalView::statusMessageHandler)(TerminalView *, const QString &, int) = nullptr;

namespace {
// 颜色名→QColor（原版 HighlightTextBar 8 色表中的命名色；Qt 命名色直映）
QColor highlightColorByName(const QString &name)
{
    static const QHash<QString, QColor> table = {
        { QStringLiteral("Red"), QColor(Qt::red) },
        { QStringLiteral("Orange"), QColor(QStringLiteral("#ffa500")) },
        { QStringLiteral("Yellow"), QColor(Qt::yellow) },
        { QStringLiteral("Green"), QColor(Qt::green) },
        { QStringLiteral("Royalblue"), QColor(QStringLiteral("royalblue")) },
        { QStringLiteral("Cyan"), QColor(Qt::cyan) },
        { QStringLiteral("Purple"), QColor(QStringLiteral("purple")) },
    };
    return table.value(name);
}
} // namespace

void TerminalView::setHighlightRange(int start, int end, const QString &colorName)
{
    const QColor color = highlightColorByName(colorName);
    if (!color.isValid() || !m_screen)
        return;
    QPair<int, int> s = posToCell(qMin(start, end));
    QPair<int, int> e = posToCell(qMax(start, end));
    if (e.first != s.first)
        return; // 跨行高亮原版由调用方逐行拆分；骨架单行语义（挂账 0x75c7）
    const int colStart = qBound(0, s.second, m_screen->cols() - 1);
    const int colEnd = qBound(0, e.second, m_screen->cols() - 1);
    if (colEnd < colStart)
        return;
    m_highlights.append({ s.first, colStart, colEnd, color });
    viewport()->update();
}

void TerminalView::clearHighlightRange(int pos)
{
    QPair<int, int> cell = posToCell(pos);
    m_highlights.erase(std::remove_if(m_highlights.begin(), m_highlights.end(),
                                      [&cell](const HighlightSpan &h) {
        return h.line == cell.first && cell.second >= h.colStart && cell.second <= h.colEnd;
    }), m_highlights.end());
    viewport()->update();
}

// 单行内从 col 起匹配 pattern；命中回填结束列。regex/case/wholeWord 选项生效。
bool TerminalView::matchAt(int line, int col, int *colEnd) const
{
    if (!m_screen || m_findPattern.isEmpty() || col >= m_screen->cols())
        return false;
    // 逐 cell 取行文本（与 selectedText 同管线；空白尾随裁掉）
    QString text;
    for (int c = 0; c < m_screen->cols(); ++c)
        text += charAtLine(line, c);
    while (text.endsWith(QLatin1Char(' ')))
        text.chop(1);
    if (m_findOptions.regex) {
        QRegularExpression::PatternOptions opts = QRegularExpression::NoPatternOption;
        if (!m_findOptions.caseSensitive)
            opts |= QRegularExpression::CaseInsensitiveOption;
        QRegularExpression re(m_findPattern, opts);
        if (!re.isValid())
            return false;
        QRegularExpressionMatch m = re.match(text, col);
        if (!m.hasMatch() || m.capturedStart() != col)
            return false; // 锚定 col：逐位置推进由 findImpl 驱动
        *colEnd = m.capturedEnd();
        return true;
    }
    Qt::CaseSensitivity cs = m_findOptions.caseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive;
    int at = text.indexOf(m_findPattern, col, cs);
    if (at != col)
        return false; // 同上：只认 col 处命中
    if (m_findOptions.wholeWord) {
        const auto isWord = [this, line](int c) {
            const QChar ch = charAtLine(line, c);
            return ch.isLetterOrNumber() || ch == QLatin1Char('_');
        };
        if ((at > 0 && isWord(at - 1)) || (at + m_findPattern.size() < text.size() && isWord(at + m_findPattern.size())))
            return false;
    }
    *colEnd = at + m_findPattern.size();
    return true;
}

// find 核心（B 节语义）：从当前光标/选区端起向下/上扫滚回+活动屏全文本；wrap 回绕；
// 命中→选区+滚动+状态栏；未命中→"未找到"
bool TerminalView::findImpl(bool backward, bool useSelection)
{
    if (!m_screen || m_findPattern.isEmpty()) {
        if (statusMessageHandler)
            statusMessageHandler(this, tr("未找到"), 4000);
        return false;
    }
    if (useSelection) {
        const QString sel = selectedText();
        if (!sel.isEmpty())
            m_findPattern = sel; // wind.actions 语义：选区即 pattern
    }
    const int backLines = m_screen->alternateScreen() ? 0 : m_screen->scrollback().size();
    const int totalLines = backLines + m_screen->rows();
    // 起点：有选区从选区尾(next)/头(previous)，否则从光标；再进一步=先经再比（含端点后一格）
    int startLine, startCol;
    if (hasSelection()) {
        QPoint s0 = m_selAnchor, s1 = m_selEnd;
        if (s0.y() > s1.y() || (s0.y() == s1.y() && s0.x() > s1.x()))
            qSwap(s0, s1);
        startLine = backward ? s0.y() : s1.y();
        startCol = backward ? s0.x() : s1.x();
    } else {
        startLine = backLines + m_screen->cursorY();
        startCol = m_screen->cursorX();
    }
    const auto advance = [this, totalLines](int &line, int &col, bool back) {
        if (back) {
            if (col > 0) { --col; return true; }
            if (line > 0) { --line; col = INT_MAX; return true; }
            return false;
        }
        if (++col >= m_screen->cols()) { ++line; col = 0; return line < totalLines; }
        return true;
    };
    // 先走一步再比对（起点自身不重复命中；wrap 由 searchWrap 控制）
    int line = startLine, col = startCol;
    bool wrapped = false;
    while (true) {
        if (!advance(line, col, backward)) {
            if (!m_findOptions.wrap || wrapped)
                break;
            wrapped = true;
            if (backward) { line = totalLines - 1; col = INT_MAX; }
            else { line = 0; col = 0; }
            continue;
        }
        col = qMin(col, m_screen->cols() - 1);
        int matchEnd = 0;
        if (matchAt(line, qMax(col, 0), &matchEnd)) {
            // 命中：设选区到匹配处+滚动定位（scrollbar 值=匹配行-视口半高，B 节）+状态栏
            m_selAnchor = QPoint(qMax(col, 0), line);
            m_selEnd = QPoint(matchEnd - 1, line);
            viewport()->update();
            const int page = qMax(1, int(viewport()->height() / qMax<qreal>(1.0, m_cellH)));
            verticalScrollBar()->setValue(qBound(0, line - page / 2, verticalScrollBar()->maximum()));
            if (statusMessageHandler)
                statusMessageHandler(this, QStringLiteral("找到 1 处"), 4000); // N 计数简化挂账
            return true;
        }
    }
    if (statusMessageHandler)
        statusMessageHandler(this, tr("未找到"), 4000);
    return false;
}

void TerminalView::findNext(bool useSelection) { findImpl(false, useSelection); }

void TerminalView::findPrevious(bool useSelection) { findImpl(true, useSelection); }

// 选区规范化锚点（测试断言用；s0=排序后起点）
QPoint TerminalView::selectionAnchor() const
{
    if (!hasSelection())
        return QPoint(-1, -1);
    QPoint s0 = m_selAnchor, s1 = m_selEnd;
    if (s0.y() > s1.y() || (s0.y() == s1.y() && s0.x() > s1.x()))
        qSwap(s0, s1);
    return s0;
}

// HighlightTextBar 落点：选区→逐行 highlight span（0x55c246 toggled 语义；
// shortcut: 原版 selToRange 全局位置换算未逆明，按选区 (line,col) 对直接拆行——最简且清晰）
void TerminalView::highlightSelection(const QString &colorName)
{
    if (!hasSelection() || !m_screen)
        return;
    QPoint s0 = m_selAnchor, s1 = m_selEnd;
    if (s0.y() > s1.y() || (s0.y() == s1.y() && s0.x() > s1.x()))
        qSwap(s0, s1);
    const QColor color = highlightColorByName(colorName);
    if (!color.isValid())
        return;
    for (int line = s0.y(); line <= s1.y(); ++line) {
        const int from = line == s0.y() ? s0.x() : 0;
        const int to = line == s1.y() ? s1.x() : m_screen->cols() - 1;
        if (to < from)
            continue;
        m_highlights.append({ line, from, to, color });
    }
    viewport()->update();
}
