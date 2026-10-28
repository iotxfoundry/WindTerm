#ifndef TERMINALVIEW_H
#define TERMINALVIEW_H

#pragma once

// 终端视图渲染面(Phase 4b 渲染层)。数据源 = TerminalCore 格子:
// 行=core->row(y)(Row.length 格),字符=Row.attrArray u16 UCS-2 字头
// (e2eterm 同源),SGR=cell+0x18 u64(Screen::applySgr 位义:
// bit0 bold/1 faint/2 italic/3 underline/4 d-underline/6 blink/
// 7 inverse/8 conceal/9 strike/10 overline;14..37 fg RGB24;
// 38 fg-bright;39..62 bg RGB24;63 bg-bright)。调色板经
// Screen::paletteColor(+0xd0 容器);空表回落 16 色 xterm 默认。
// 刷新 = TermViewFace::viewWrite(语料 vtable+0x70 通道)→ update()。

#include "TermViewFace.h"

#include <QWidget>

class Screen;

class TerminalView : public QWidget, public TermViewFace
{
	Q_OBJECT

public:
	explicit TerminalView(QWidget *parent = nullptr);

	void setScreen(Screen *screen);
	Screen *screen() const { return m_screen; }

	QSize sizeHint() const override;

	// TermViewFace(语料 vtable+0x70 写回通道 / +0x78 通知通道)
	void viewWrite(const QByteArray &data) override;
	void viewNotify(void *sender, long long arg) override;

protected:
	void paintEvent(QPaintEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;
	void keyPressEvent(QKeyEvent *event) override;

Q_SIGNALS:
	void keyText(const QString &text);   // 键入 → TerminalWidget::write

private:
	int cellWidth() const;
	int cellHeight() const;
	void drawCells(QPainter &p, const QRect &clip);

	Screen *m_screen = nullptr;
};

#endif // TERMINALVIEW_H
