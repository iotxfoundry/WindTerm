#include "TerminalView.h"
#include "Screen.h"
#include "TerminalCore.h"

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

	// 调色板:Screen::paletteColor(+0xd0 容器,4B 步长);未配置回落
	const bool paletteReady = m_screen->m_palette != 0;

	p.fillRect(event->rect(), QColor(kDefaultBg));

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
			quint32 sgr = 0;
			if (row->cells)
				sgr = *(const quint32 *)((const char *)row->cells +
				                         (size_t)x * 0x20 + 0x18);
			quint32 fg = kDefaultFg;
			quint32 bg = kDefaultBg;
			if (paletteReady) {
				fg = (quint32)m_screen->paletteColor(
				    (int)((sgr >> 14) & 0xff));
				bg = (quint32)m_screen->paletteColor(
				    (int)((sgr >> 39) & 0xff));
			}
			if (sgr & (1ULL << 7)) {   // inverse
				qSwap(fg, bg);
			}
			const QRect cell(x * cw, y * chh, cw, chh);
			if (bg != kDefaultBg)
				p.fillRect(cell, QColor(bg & 0xffffff));
			const ushort u = heads[x];
			if (u == 0 || u == (ushort)' ')
				continue;
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
		}
	}

	// 光标框(Screen::currentLine/currentColumn;实心块随 caretStyle)
	const int cx = m_screen->currentColumn() * cw;
	const int cy = m_screen->currentLine() * chh;
	p.save();
	p.setCompositionMode(QPainter::RasterOp_SourceXorDestination);
	p.setPen(QColor(0xffffff));
	p.drawRect(cx, cy, cw - 1, chh - 1);
	p.restore();
}

void TerminalView::drawCells(QPainter &p, const QRect &clip)
{
	Q_UNUSED(p);
	Q_UNUSED(clip);   // (预留拆分;当前绘制在 paintEvent 内联)
}
