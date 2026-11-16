// AddressBarFace.cpp —— 从 Widgets/Faces 拆出(按 UI 架构归位)
#include "Widgets/Bars/AddressBarFace.h"

// FUN_005211fe(162B,0016.c:15189)AddressBar ctor 真身:
//   基 BreadCrumb ctor → vtable 换 AddressBar → objectName "AddressBar"
//   @00521242-57 → FUN_00521178(134B):connect(edit, FUN_008f826e →
//   this, FUN_005247c5)(edit 类未建模 → 接线 cited 不落)。
AddressBarFace::AddressBarFace(QWidget *parent)
	: BreadCrumbFace(parent) // FUN_00548546 @005211fe
{
	setObjectName(QStringLiteral("AddressBar")); // @00521242-57
	// connect(edit30(), 信号 FUN_008f826e, this, FUN_005247c5)@00521178 — cited。
}
