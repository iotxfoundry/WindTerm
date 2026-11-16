// CrumbEditFace.cpp —— 从 Widgets/Faces/BreadCrumbFace 拆出(按 UI 架构归位)
#include "Widgets/Controls/CrumbEditFace.h"

// FUN_0054d22a(197B,0017.c:19741)激活切换真身:
//   @0054d22a +0x74 = active;!active → +0xb8 QTimer::start();
//   active → QLineEdit::text() + setSelection(0);
//   cursor = QCursor(active ? 4(IBeam) : 0(Arrow)) → setCursor;
//   setAttribute(2, !active) → update()。
void CrumbEditFace::setActive(bool active)
{
	m_flags74 = active ? 1 : 0; // +0x74
	if (!active) {
		if (m_timerB8 != nullptr)
			m_timerB8->start(); // @0054d24x
	} else {
		text();
		setSelection(0); // @0054d25d
	}
	setCursor(QCursor(active ? Qt::IBeamCursor : Qt::ArrowCursor)); // @0054d278
	setAttribute(static_cast<Qt::WidgetAttribute>(2), !active);     // 2 = 语料立即数
	update();
}