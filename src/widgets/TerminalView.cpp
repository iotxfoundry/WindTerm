#include "TerminalView.h"

#include <QApplication>
#include <QClipboard>
#include <QContextMenuEvent>
#include <QFontMetricsF>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QScrollBar>

#include "core/Session.h"
#include "core/SchemeManager.h"
#include "core/ScreenModel.h"
#include "core/ThemeManager.h"
#include "core/VtParser.h"
#include "core/WindConfig.h"

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
        const bool atBottom = verticalScrollBar()->value() >= verticalScrollBar()->maximum();
        m_parser->feed(data);
        updateScrollRange();
        if (atBottom) // 新输出锚底；用户上滚回看时不强拉
            verticalScrollBar()->setValue(verticalScrollBar()->maximum());
        // shortcut: 增量行级重画(原版脏行范围)挂账,先全量保正确
        viewport()->update();
        emit caretPositionChanged();
    });

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

// 选区（0xa3e5ca：3px 位移阈值起选）
void TerminalView::mousePressEvent(QMouseEvent *event)
{
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
