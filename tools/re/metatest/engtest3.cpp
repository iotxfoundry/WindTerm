// 渲染冒烟:TerminalView 离屏绘制(TerminalCore→格子→像素)
#include "Screen.h"
#include "TerminalCore.h"
#include "TerminalView.h"
#include <QApplication>
#include <QImage>
#include <cstdio>

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	TerminalCore core;
	core.resizeCore(24, 80);
	core.m_flags |= 0x02;
	Screen s;
	s.m_core = &core;
	s.m_history = new TerminalCore();
	s.m_history->resizeCore(24, 80);
	s.writeText("hello", 5);
	s.writeText("\x1b[31mRED\x1b[0m", 12);

	TerminalView view;
	view.setScreen(&s);
	view.resize(640, 400);
	view.show();
	QImage img = view.grab().toImage();
	printf("img=%dx%d\n", img.width(), img.height());

	// 1) 非单色(背景+文字+光标至少两色)
	QRgb first = img.pixel(0, 0);
	int distinct = 0;
	for (int y = 0; y < img.height(); y += 7)
		for (int x = 0; x < img.width(); x += 7)
			if (img.pixel(x, y) != first)
				distinct++;
	printf("distinct>0: %s (%d)\n", distinct > 0 ? "OK" : "FAIL", distinct);

	// 2) 首行前 5 格有墨(字形像素 != 背景)
	int inked = 0;
	for (int x = 0; x < 5; x++)
		for (int yy = 2; yy < 14; yy++)
			if (img.pixel(x * 10 + 2, yy) != first)
				inked++;
	printf("glyph ink: %s (%d cells sampled)\n",
	       inked > 0 ? "OK" : "FAIL", inked);

	// 3) viewWrite 通道不崩 + 行列自适应
	s.writeBackToView(QByteArray("x"));
	s.notifyViewArg(0);
	s.resizeScreen(10, 40, 0);
	printf("post-resize %dx%d core=%dx%d OK\n", view.width(),
	       view.height(), core.columnCount(), core.rowCount());

	// 4) SGR 31 → 红字(applySgr 存 RGB 色值;RED 在末行)
	s.writeText("\r\n\x1b[31mRED", 10);
	QImage img2 = view.grab().toImage();
	int reds = 0;
	for (int y = 0; y < img2.height(); y += 2) {
		for (int x = 0; x < 200; ++x) {
			const QRgb px = img2.pixel(x, y);
			if (qRed(px) > 0x80 && qGreen(px) < 0x60
			    && qBlue(px) < 0x60)
				reds++;
		}
	}
	printf("SGR red ink: %s (%d px)\n", reds > 3 ? "OK" : "FAIL", reds);
	return (distinct > 0 && inked > 0 && reds > 3) ? 0 : 1;
}
