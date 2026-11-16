#pragma once

#include <QWidget>

// FileViewFace — 文件视图(QWidget 派生,4 条信号全部是"请求"式)。
//
// 出处:RTTI "FileView";QMetaObject 0x0119c7c0
// (rev=8,class="FileView",methods=4,**signals=4**,props=0,superdata=0);
// sizeof = **0xc0**(deleting 0x008fa15c 的 operator_delete(_,0xc0));
// dtor 0x008f9dc0(308B)/deleting 0x008fa15c(328B);
// 信号桥 0x008f9c68(183B);metacast 0x008f9d20 / metacall 0x008f9d62(93B)。
//
// 四条信号(串表实读;形参个数按桥的 switch 逐个实读):
//   #0 copyDirectoryPathToTerminalRequested()          0 参 → 0x008f9bc8
//   #1 sortIndicatorChanged(int column, int order)     2 参 → 0x008f9bec
//   #2 syncTerminalFolderModeChanged(bool)             1 参(字节)→ 0x008f9c30
//   #3 syncTerminalFolderRequested()                   0 参 → 0x008f9bd8
//
// 字段(dtor 实读;释放顺序**从高到低**,且引用计数件的释放是
// "减一到 0 → operator_delete" 的标准语义):
//   +0x60 引用计数件
//   +0x88 引用计数件
//   +0xa0 引用计数件
//   +0xb0 引用计数件
//   (另有 +0x10 为第二 vptr)
class FileViewFace : public QWidget {
	Q_OBJECT

public:
	explicit FileViewFace(QWidget *parent = nullptr);
	~FileViewFace() override; // 0x008f9dc0

signals:
	void copyDirectoryPathToTerminalRequested();            // #0
	void sortIndicatorChanged(int column, int order);        // #1
	void syncTerminalFolderModeChanged(bool on);             // #2
	void syncTerminalFolderRequested();                      // #3

private:
	void *m_f60 = nullptr; // +0x60
	void *m_f88 = nullptr; // +0x88
	void *m_fa0 = nullptr; // +0xa0
	void *m_fb0 = nullptr; // +0xb0
};
