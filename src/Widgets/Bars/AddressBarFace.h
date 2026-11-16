#pragma once


#include "Widgets/Bars/BreadCrumbFace.h"

// AddressBarFace — 语料 AddressBar(BreadCrumb 子类,toolbar kind 5)基面。
// ctor FUN_005211fe(162B,0016.c:15189):
//   BreadCrumb ctor(FUN_00548546)@005211fe → vtable AddressBar →
//   objectName "AddressBar"@00521242-57 → FUN_00521178(134B)接线:
//   connect(edit, 信号 FUN_008f826e(smeta 0119a540 = edit 类)→ this,
//   FUN_005247c5)@00521178。
class AddressBarFace : public BreadCrumbFace {
	Q_OBJECT
public:
	explicit AddressBarFace(QWidget *parent = nullptr); // FUN_005211fe
};
