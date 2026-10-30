#ifndef SUPERKEYMAP_H
#define SUPERKEYMAP_H

#pragma once

#include <QList>
#include <QRegularExpression>
#include <QVariant>
#include <QObject>

// SuperKeymap —— 语料转写(批 46/47;铁律 6)。
// 语料:FUN_00674648(161B,ctor)—— QObject(parent)→
//   SuperKeymap_vtable → +0x10 = 槽列表(FUN_0067db7c init,容量 2)→
//   +0x18 = QRegularExpression("meta\\+|\\+meta", CaseInsensitive)
//   (006746b9 字面实证)。
// 引擎复位 FUN_0067461a(45B):FUN_0067db40(+0x10)(容量确保)→
//   FUN_0067ce4c(+0x10 + mode*8 + *(+0x10+0x10))(mode 槽清,
//   FUN_0067ce4c 49B = 槽交换销毁;FUN_0067ce30 = 项销毁走查)。
// 匹配体:语料函数未定位(cited — wave-2 挂账,PHASE5 批 46)。
// 元素类型:语料不透明(槽内元素以 QVariant 承载,非猜测行为面)。
class SuperKeymap : public QObject {
    Q_OBJECT

public:
    explicit SuperKeymap(QObject *parent = nullptr);   // FUN_00674648

    // FUN_0067461a(45B):mode 索引槽清
    void reset(int mode);

    const QRegularExpression &metaRegex() const { return m_metaRe; }   // +0x18

private:
    QList<QVariant> m_slots;                 // +0x10(容量 2,FUN_0067db7c)
    QRegularExpression m_metaRe;             // +0x18 "meta\+|\+meta"
};
#endif // SUPERKEYMAP_H
