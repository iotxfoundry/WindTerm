// SuperFolderFace.cpp — 文件夹抽象基座。

#include "Sessions/Transfers/SuperFolderFace.h"

// 出处:QMetaObject 0x011ac960(class="SuperFolder",methods=0);
// ctor 无独立语料条目,仅转发 QObject 基构造。
SuperFolderFace::SuperFolderFace(QObject *parent)
    : QObject(parent)
{
}

SuperFolderFace::~SuperFolderFace() = default;
