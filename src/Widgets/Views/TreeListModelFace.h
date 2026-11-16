#pragma once

#include <QObject>

// TreeListModelFace — 文件树模型的 Q_OBJECT 基座。
//
// 出处:QMetaObject 0x011a05e0(rev=8,**class="TreeListModel"**,
// methods=0,signals=0,props=0,**superdata=0** ⇒ 直接派生 QObject)。
//
// 由来:FileSystemItem 自身没有 Q_OBJECT,它的 metaObject 转调
// `&PTR_staticMetaObject_011a05e0`(0x0090304c,24B),而该表的类名是
// "TreeListModel" —— 这就是 FileSystemItem 的真实 Q_OBJECT 基类。
// 本类当前只承载元对象身份,成员全在派生层。
class TreeListModelFace : public QObject {
	Q_OBJECT

public:
	explicit TreeListModelFace(QObject *parent = nullptr);
};
