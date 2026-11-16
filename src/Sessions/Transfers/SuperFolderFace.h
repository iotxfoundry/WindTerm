#pragma once

#include <QObject>

// SuperFolderFace — 文件夹抽象基座(本地 / SFTP 共用)。
//
// 出处:RTTI "SuperFolder";QMetaObject 0x011ac960
// (rev=8,class="SuperFolder",**methods=0 / signals=0 / props=0 / superdata=0**)
// —— 无元接口,纯身份基座。同族兄弟 `SuperFile`(0x011ac800)同样 methods=0。
//
// ⚠ 本构建里 superdata=0 出现在大量明显派生自 QWidget/QMenu 的类上
// (KitWindow / SlipButton / Menu …),所以 **superdata=0 不能当"无基类"用**;
// 只有非零 superdata 才是有信息的判据。此处按 QObject 承载。
class SuperFolderFace : public QObject {
	Q_OBJECT

public:
	explicit SuperFolderFace(QObject *parent = nullptr);
	~SuperFolderFace() override;
};
