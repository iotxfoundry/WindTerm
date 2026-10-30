#ifndef SUPERKEYMAP_H
#define SUPERKEYMAP_H

#pragma once

#include <QRegularExpression>
#include <QStringList>
#include <QObject>

// SuperKeymap —— 语料转写(批 46;铁律 6)。
// 语料:FUN_00674648(161B,ctor)—— QObject(parent)→
//   SuperKeymap_vtable → +0x10 = 列表(FUN_0067db7c init,2)→
//   +0x18 = QRegularExpression("meta\\+|\\+meta", CaseInsensitive)
//   (006746b9 字面实证)。
// 引擎复位 FUN_0067461a(45B):FUN_0067db40(+0x10)→
//   FUN_0067ce4c(+0x10 + mode*8 + *(+0x10+0x10))。
// 装载器 s_wind_keymaps_768854(00768854)见 KeymapEngine。
// 匹配体:语料函数未定位(cited — wave-2 挂账,PHASE5 批 46)。
class SuperKeymap : public QObject {
    Q_OBJECT

public:
    explicit SuperKeymap(QObject *parent = nullptr);   // FUN_00674648

    // FUN_0067461a(45B):mode 索引切换(mode*8 寻址)
    void reset(int mode);

    const QRegularExpression &metaRegex() const { return m_metaRe; }   // +0x18

private:
    QStringList m_sources;                    // +0x10(FUN_0067db7c init,2)
    QRegularExpression m_metaRe;              // +0x18 "meta\+|\+meta"
};
#endif // SUPERKEYMAP_H
