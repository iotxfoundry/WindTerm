#pragma once

#include <QString>
#include <QTreeView>

// TreeViewFace — 树视图基座(QTreeView 派生)。
//
// 出处:RTTI "TreeView";QMetaObject 0x0119dc40
// (rev=8,class="TreeView",methods=4,**signals=2 props=1**,superdata=0);
// **语料无 TreeView 的独立函数 entry**(ctor/dtor 全部内联在派生类里),
// 所以本类只能落元接口,字段布局不可得 —— 按铁律 6 不落玄字段。
//
// 元接口(串表实读):
//   #0 modelChanged()        信号
//   #1 filterChanged()       信号
//   #2 onFilterChanged(...)  槽
//   #3 resizeColumnToContents(...) 槽
//   prop singleLine —— 与 ListView 的 `singleLine` 同名同形(同样不占新字段)
class TreeViewFace : public QTreeView {
	Q_OBJECT

public:
	explicit TreeViewFace(QWidget *parent = nullptr);

signals:
	void modelChanged();  // #0
	void filterChanged(); // #1

public slots:
	void onFilterChanged(const QString &filter); // #2
	void resizeColumnToContents();               // #3
};
