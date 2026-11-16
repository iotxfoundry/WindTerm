#ifndef WIDGETS_CONTROLS_COMPLETEMODELFACE_H
#define WIDGETS_CONTROLS_COMPLETEMODELFACE_H

#pragma once

// CompleteModel — 补全列表的数据模型(三层容器展平成单列行数)。
// RTTI 类名 "CompleteModel";rowCount 虚面 vt15 = 0x00955d70(85B);
// dtor 0x00955856(1282B,含逐行释放,暂 cited)。
//
// 字段:+0x18 指向一个三层容器,容器内三组 (begin,end) 各为 8 字节步长的指针数组:
//   [+0x30,+0x40) / [+0x48,+0x68) / [+0x58,+0x50)   ← 注意第三组是反序布局

#include <QAbstractListModel>

class CompleteModelFace : public QAbstractListModel {
	Q_OBJECT

public:
	explicit CompleteModelFace(QObject *parent = nullptr);
	~CompleteModelFace() override; // 00955856

	int rowCount(const QModelIndex &parent = QModelIndex()) const override; // 00955d70

private:
	void *m_holder18 = nullptr; // +0x18 三层容器
};

#endif // WIDGETS_CONTROLS_COMPLETEMODELFACE_H
