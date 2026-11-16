#pragma once

#include <QAbstractListModel>
#include <QSortFilterProxyModel>
#include <QString>
#include <QStyledItemDelegate>

// ModelFaces.h — 三个模型基座 + 自绘委托基座。
//
// **语料名又整族错位一格**(与 FileSystemItem 族同模式):
//   名为 `WidgetDelegate_dtor`(0x008eff00,66B)的实为 **CheckEditor::qt_metacast**
//   名为 `ListModel_dtor`(0x008ff152,66B)的实为 **ListModel::qt_metacast**
//   名为 `SortFilterProxyModel_dtor`(0x008ff042,66B)的实为
//     **SortFilterProxyModel::qt_metacast**
//   判据:三个 66B 函数体都是 strcmp 形式,末句各调 QWidget /
//   QAbstractListModel / QSortFilterProxyModel 的 qt_metacast。
//
// | 类 | 基类(metaobject superdata / metacast 末句) | methods | 备注 |
// |---|---|---|---|
// | WidgetDelegate     | **QStyledItemDelegate** | 0 | 自研自绘委托基座 |
// | ListModel          | **QAbstractListModel**  | 0 | 零元接口 |
// | SortFilterProxyModel | **QSortFilterProxyModel** | 1 | 有 1 条槽 |
// | HtmlListModel      | (superdata=0)           | 0 | UndoModel 的基类(0x011995a0) |
//
// SortFilterProxyModel 的清空腿 0x00663faa(39B)逐句:
//   +0x30 != +0x38 → +0x38 = +0x30(把游标收回起点);
//   +0x10 = **-1**;+0x18 = 0;+0x20 = 0。
//   ⇒ +0x30/+0x38 是一对游标,+0x10 是"无效索引"哨兵(-1 而非 0)。
//
// 出处(entry 地址逐一列,真身):
//   WidgetDelegate       dtor/删除 由 CheckEditor 的 metacast 占名(见上),
//                        本体按 superdata 判为 QStyledItemDelegate 派生
//   ListModel            同上;dtor_deleting 0x008ff194(5B,纯转发桩)
//   SortFilterProxyModel 同上;清空 0x00663faa(39B)真身
//   HtmlListModel        metaObject 0x008f7466(24B)/ metacast 0x008f7498(104B)
//                        / metacall 0x008f7500(5B)

class WidgetDelegateFace : public QStyledItemDelegate {
	Q_OBJECT
public:
	explicit WidgetDelegateFace(QObject *parent = nullptr);
	~WidgetDelegateFace() override;
};

class ListModelFace : public QAbstractListModel {
	Q_OBJECT
public:
	explicit ListModelFace(QObject *parent = nullptr);
	~ListModelFace() override;
};

class SortFilterProxyModelFace : public QSortFilterProxyModel {
	Q_OBJECT
public:
	explicit SortFilterProxyModelFace(QObject *parent = nullptr);
	~SortFilterProxyModelFace() override;

	void resetCursor(); // 0x00663faa(39B)

private:
	qint64 m_sentinel10 = -1; // +0x10(无效索引哨兵)
	void *m_f18 = nullptr;    // +0x18
	void *m_f20 = nullptr;    // +0x20
	char *m_cursorBegin30 = nullptr; // +0x30
	char *m_cursorEnd38 = nullptr;   // +0x38
};

class HtmlListModelFace : public QAbstractListModel {
	Q_OBJECT
public:
	explicit HtmlListModelFace(QObject *parent = nullptr);
	~HtmlListModelFace() override;
};
