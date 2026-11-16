#pragma once

#include <QVariant>
#include <QWidget>

// MuxPaneGroupFace — 分屏组(QWidget 派生,10 条槽 / 0 信号)。
//
// 出处:RTTI "MuxPaneGroup";QMetaObject 0x011ac040
// (rev=8,class="MuxPaneGroup",methods=10,**signals=0**,props=0,superdata=0);
// sizeof = **0x40**(deleting 0x0091e34c 的 operator_delete(_,0x40));
// dtor 0x0091e30e(29B)/deleting 0x0091e34c(47B)
//   —— dtor 只做 vptr 复位 + QWidget 析构 ⇒ **零字段**;
// 槽分发 0x0091e118(313B);metacast 0x0091e26e / metacall 0x0091e2b0(93B)。
//
// 十条槽(串表真名按索引;renameMuxPane 三条 = 默认实参重载):
//   #0 breakMuxPane()          → 0x008de576
//   #1 isMuxPaneZooming()      → 0x008def36 出参 bool
//   #2 renameMuxPane(?, str)   → mux_renamePaneDialog(this, int, str)
//   #3 renameMuxPane(?, ?)
//   #4 renameMuxPane(...)
//   #5 resizeMuxPane(...)
//   #6 selectMuxPane(...)
//   #7 splitMuxPane(...)
//   #8 swapMuxPane(...)
//   #9 toggleMuxPaneZoom(...)
class MuxPaneGroupFace : public QWidget {
	Q_OBJECT

public:
	explicit MuxPaneGroupFace(QWidget *parent = nullptr);
	~MuxPaneGroupFace() override; // 0x0091e30e

public slots:
	void breakMuxPane();                  // #0
	bool isMuxPaneZooming();              // #1
	void renameMuxPane(int id, const QString &name); // #2
	void renameMuxPane(int id);                       // #3
	void renameMuxPane();                             // #4
	void resizeMuxPane(const QVariant &v);            // #5
	void selectMuxPane(const QVariant &v);            // #6
	void splitMuxPane(const QVariant &v);             // #7
	void swapMuxPane(const QVariant &v);              // #8
	void toggleMuxPaneZoom(const QVariant &v);        // #9
};
