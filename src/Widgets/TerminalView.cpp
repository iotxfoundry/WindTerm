#include "TerminalView.h"
#include "Screen.h"
#include "TerminalCore.h"

#include <QKeyEvent>
#include <QPainter>
#include <QResizeEvent>

namespace {
// xterm 默认 16 色(调色板未配置时回落;index 0..15)
const quint32 kDefaultPalette[16] = {
	0x000000, 0xcd0000, 0x00cd00, 0xcdcd00, 0x0000ee, 0xcd00cd, 0x00cdcd,
	0xe5e5e5, 0x7f7f7f, 0xff0000, 0x00ff00, 0xffff00, 0x5c5cff, 0xff00ff,
	0x00ffff, 0xffffff,
};
const quint32 kDefaultFg = 0xe5e5e5;
const quint32 kDefaultBg = 0x000000;
} // namespace

TerminalView::TerminalView(QWidget *parent)
	: QWidget(parent)
{
	// 等宽字面(原版经字体配置;重建面取平台等宽,尺寸随 metrics)
	QFont f(QStringLiteral("Monospace"));
	f.setStyleHint(QFont::TypeWriter);
	f.setPixelSize(16);
	setFont(f);
	setAttribute(Qt::WA_OpaquePaintEvent);
	setAutoFillBackground(false);
}

void TerminalView::setScreen(Screen *screen)
{
	m_screen = screen;
	updateGeometry();
	update();
}

QSize TerminalView::sizeHint() const
{
	if (!m_screen || !m_screen->m_core)
		return QWidget::sizeHint();
	return QSize(m_screen->m_core->columnCount() * cellWidth(),
	             m_screen->m_core->rowCount() * cellHeight());
}

void TerminalView::viewWrite(const QByteArray &data)
{
	Q_UNUSED(data);
	update();   // 语料:写回通道即重绘触发
}

void TerminalView::viewNotify(void *sender, long long arg)
{
	Q_UNUSED(sender);
	Q_UNUSED(arg);
	update();   // FUN_007e673c 通道:通知即重绘
}

int TerminalView::cellWidth() const
{
	return qMax(1, fontMetrics().horizontalAdvance(QLatin1Char('M')));
}

int TerminalView::cellHeight() const
{
	return qMax(1, fontMetrics().height());
}

void TerminalView::resizeEvent(QResizeEvent *event)
{
	// 视图尺寸 → 行列(FUN_007e5688 resizeScreen 路径)
	QWidget::resizeEvent(event);
	if (!m_screen)
		return;
	const int cols = qMax(1, width() / cellWidth());
	const int rows = qMax(1, height() / cellHeight());
	m_screen->resizeScreen(rows, cols, 0);
}

void TerminalView::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	if (!m_screen || !m_screen->m_core) {
		p.fillRect(event->rect(), QColor(kDefaultBg));
		return;
	}
	TerminalCore *core = m_screen->m_core;
	const int cw = cellWidth();
	const int chh = cellHeight();
	const QFontMetrics fm(fontMetrics());

	p.fillRect(event->rect(), QColor(kDefaultBg));

	// SGR 位 = 解析期已消费的 RGB 色值(applySgr:paletteColor 结果
	// 直存 14..37 fg / 39..62 bg);0 = 默认
	const int y0 = event->rect().top() / chh;
	const int y1 = qMin(core->rowCount() - 1, event->rect().bottom() / chh);
	for (int y = y0; y <= y1; ++y) {
		struct Row *row = core->row(y);
		if (!row)
			continue;
		const unsigned short *heads =
		    (const unsigned short *)row->attrArray;
		const int n = qMin(row->length, core->columnCount());
		for (int x = 0; x < n; ++x) {
			const ushort u = heads[x];
			if (u == 0xffff)
				continue;   // 宽字符尾格(e2eterm 锚:0xffff trail)
			quint32 sgr = 0;
			if (row->cells)
				sgr = *(const quint32 *)((const char *)row->cells +
				                         (size_t)x * 0x20 + 0x18);
			quint32 fg = (quint32)((sgr >> 14) & 0xffffff);
			quint32 bg = (quint32)((sgr >> 39) & 0xffffff);
			if (fg == 0)
				fg = kDefaultFg;
			if (bg == 0)
				bg = kDefaultBg;
			if (sgr & (1ULL << 7)) {   // inverse
				qSwap(fg, bg);
			}
			// 宽字符占双格(widthFromTables==2);字形自然宽渲染
			const int span =
			    (m_screen && u != 0 && m_screen->widthFromTables(u) == 2)
			        ? 2
			        : 1;
			const QRect cell(x * cw, y * chh, cw * span, chh);
			if (bg != kDefaultBg)
				p.fillRect(cell, QColor(bg & 0xffffff));
			if (u == 0 || u == (ushort)' ') {
				if (span == 2)
					++x;   // 尾格已随跨度消费
				continue;
			}
			QFont f = font();
			f.setBold((sgr & 1) != 0);
			p.setFont(f);
			p.setPen(QColor(fg & 0xffffff));
			p.drawText(cell, Qt::AlignLeft | Qt::AlignTop |
			                     Qt::TextSingleLine,
			            QString(QChar(u)));
			const int w = fm.horizontalAdvance(QChar(u));
			if (sgr & (1 << 3))   // underline
				p.drawLine(cell.left(), cell.bottom(),
				           cell.left() + w - 1, cell.bottom());
			if (sgr & (1 << 9))   // strike
				p.drawLine(cell.left(), cell.top() + chh / 2,
				           cell.left() + w - 1,
				           cell.top() + chh / 2);
			if (span == 2)
				++x;   // 跳过尾格(heads[x+1]=0xffff)
		}
	}

	// 光标(Screen::currentLine/currentColumn;DECSCUSR 1-2 块 /
	// 3-4 下划线 / 5-6 竖条;闪烁面后续)
	const int cx = m_screen->currentColumn() * cw;
	const int cy = m_screen->currentLine() * chh;
	const int cs = core->cursorStyle();
	p.save();
	p.setCompositionMode(QPainter::RasterOp_SourceXorDestination);
	p.setPen(QColor(0xffffff));
	if (cs >= 5) {   // bar:左缘竖条
		p.drawRect(cx, cy, 2, chh - 1);
	} else if (cs >= 3) {   // underline:底部横条
		p.drawRect(cx, cy + chh - 3, cw - 1, 2);
	} else {   // block(0/1/2 默认)
		p.drawRect(cx, cy, cw - 1, chh - 1);
	}
	p.restore();
}

void TerminalView::keyPressEvent(QKeyEvent *event)
{
	// 键盘 → 写链(TerminalWidget::write → vt14 → writeText)。
	// 临时通道:打印字符/Enter/Backspace(通用);全键位随
	// 键表配置面(wind.config keymap,Phase 4a)接线
	QString t = event->text();
	if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
		t = QStringLiteral("\r");
	else if (event->key() == Qt::Key_Backspace)
		t = QStringLiteral("\x7f");
	if (!t.isEmpty())
		Q_EMIT keyText(t);
}

void TerminalView::drawCells(QPainter &p, const QRect &clip)
{
	Q_UNUSED(p);
	Q_UNUSED(clip);   // (预留拆分;当前绘制在 paintEvent 内联)
}
