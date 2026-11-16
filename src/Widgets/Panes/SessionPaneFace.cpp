// SessionPaneFace.cpp — 会话列表面板。

#include "Widgets/Panes/SessionPaneFace.h"

// 出处:QMetaObject 0x011a5960(class="SessionPane",methods=10,signals=0,
// superdata=0x011ab900 KitPane);ctor 内联在调用点,仅转发基构造。
SessionPaneFace::SessionPaneFace(QWidget *parent)
    : KitPaneFace(parent)
{
}

// 0x0090a2be(29B)dtor 真身:
//   vptr = &PTR_FUN_011ab6b8(KitPane vtable);*(this+0x10) = &DAT_011ab8b0;
//   QWidget::~QWidget —— 零字段。
// deleting 0x0090a2fc(47B):同上 + operator_delete(this, 0x68)。
SessionPaneFace::~SessionPaneFace() = default;

// 槽体(0x0073xxxx / 0x0074xxxx 区,尚未逐条转写;按 dispatch 锚入口):
void SessionPaneFace::duplicate() { }                 // 0x00740472
void SessionPaneFace::open() { }                      // view_deleteSelectedRows()
bool SessionPaneFace::hasSelection() { return false; } // 0x0073cdaa
void SessionPaneFace::importExternalSessions(const QVariant &v) { Q_UNUSED(v); } // 0x007400aa
void SessionPaneFace::moveTo() { }                    // 0x0073eb92
void SessionPaneFace::newSession() { }                // 0x0073cdc4
void SessionPaneFace::remove() { }                    // sessions_deleteSel()
QVariant SessionPaneFace::property(const QVariant &a, const QVariant &b)
{ Q_UNUSED(a); Q_UNUSED(b); return QVariant(); }      // sessionpane_connect_rows
QVariant SessionPaneFace::property(const QVariant &a) { Q_UNUSED(a); return QVariant(); }
QVariant SessionPaneFace::property() { return QVariant(); }

// metasurface:metaObject 0x0090a050 → &PTR_staticMetaObject_011a5960;
// qt_metacast 0x0090a068(strcmp "SessionPane" → KitPane::qt_metacast);
// qt_metacall 0x0090a260(93B):10 条记录转发到 0x0090a0aa;
//   超出则返回 (index - 10)。
