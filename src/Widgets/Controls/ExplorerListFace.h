#pragma once

// ExplorerList — s_ExplorerList_55456a(291B):vtable **ExplorerList_vtable**;字段 **+0x10**/**+0x30**/**+0x60**。

#include <QWidget>

class ExplorerListFace : public QWidget {
	Q_OBJECT
public:
	explicit ExplorerListFace(QWidget *parent = nullptr);

protected:
	QWidget *m_f30 = nullptr; // +0x30
	QWidget *m_f60 = nullptr; // +0x60
};
