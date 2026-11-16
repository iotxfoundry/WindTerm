#pragma once

#include <QDir>

#include "Sessions/Transfers/SuperFolderFace.h"

// LocalFolderFace — 本地目录(SuperFolder 派生,持一个 QDir)。
//
// 出处:RTTI "LocalFolder";sizeof = **0x60**
// (deleting 0x008e2cd6 的 operator_delete(_,0x60));
// dtor 0x008e2c9c(58B);QDir 释放腿 0x008e2c60(59B);
// 四条虚面:vt12 0x00642020(33B)/ vt13 0x00641efe(6B)/
// vt14 0x008e3078(**952B**)/ vt15 0x008e2e06(**593B**);
// 元对象 LocalFolder_vt0 0x0091e9dc(24B)。
//
// 字段:dtor 与释放腿都只碰 **+0x58 QDir*** ——
//   0x58 + 8 = 0x60 与 sizeof 自洽,⇒ **唯一字段**。
//
// 四条虚面:
//   vt12 0x00642020(33B):返回自身(取名字/路径,占位语义)
//   vt13 0x00641efe(**6B**):`return 1` —— 恒真(本地目录永远"存在")
//   vt14 0x008e3078(952B):列条目(大头)
//   vt15 0x008e2e06(593B):另一次目录操作
//
// ⚠ vt13 恒 `return 1` 与 SftpFolder 的 vt13"否则返回 1"**不是同一回事**:
//   本地版无条件 1,远端版是"会话不在时才 1"。同名虚面语义不同,别类推。
class LocalFolderFace : public SuperFolderFace {
	Q_OBJECT
public:
	explicit LocalFolderFace(QObject *parent = nullptr);
	~LocalFolderFace() override; // 0x008e2c9c

	QString name() const;   // vt12 0x00642020
	bool exists() const;    // vt13 0x00641efe(恒 1)
	QVariant list();        // vt14 0x008e3078(cited)
	QVariant reopen();      // vt15 0x008e2e06(cited)

private:
	QDir *m_dir58 = nullptr; // +0x58
};
