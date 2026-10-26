#include "MouseEncode.h"

#include <QByteArray>
#include <QString>
#include <QtGlobal>

// 分支证据地址均指 0x7ebdfc 函数体内（objdump 核对，格式串见 reference/full/
// decomp-part-0025.c:22573 起）。注意运动事件在进入分支前 uVar14 已 +0x20（运动位，
// 0x7ec5e7 区域 main 分派段——SGR 分支直接消费 uVar14，位级已由 R37 校准）；
// X10/1005/1015 分支各自再 +0x20——非 SGR 形态的运动编码=cb+64，属原版行为照搬。
QByteArray MouseEncode::body(Dialect dialect, int cb, int x, int y, bool sgrSuffixM)
{
    switch (dialect) {
    case Dialect::X10: {
        // 0x7ec5e7-0x7ec634：'M%c%c%c'——cb+0x20 字节；坐标 +0x21 clamp 255
        // （cmp $0xfe→超界落 0xff）。序=cb,y,x（param_5=y 先于 param_4=x，同 SGR 序）
        const char cy = char(qMin(y + 0x21, 0xff));
        const char cx = char(qMin(x + 0x21, 0xff));
        return QByteArray("M") + char(cb + 0x20) + cy + cx;
    }
    case Dialect::Utf8:
        // 0x7ec3e3-0x7ec45e：QString("M%1%2%3") arg 链——序与 SGR/R37 同构（cb,y,x）；
        // 码点 UTF-8 编码，坐标>255 天然多字节（1005 定义），无 clamp
        return QString(QStringLiteral("M%1%2%3"))
            .arg(QString(QChar(cb + 0x20)))
            .arg(QString(QChar(y + 0x21)))
            .arg(QString(QChar(x + 0x21)))
            .toUtf8();
    case Dialect::Urxvt:
        // 0x7ec707-0x7ec716："%d;%d;%dM"——cb+0x20、y+1、x+1 十进制（无前导字母）
        return QByteArray::number(cb + 0x20) + ';' + QByteArray::number(y + 1) + ';'
            + QByteArray::number(x + 1) + 'M';
    case Dialect::Sgr:
        // 0x7ec253 段："<%d;%d;%d%c"——cb 原值、y+1、x+1；后缀 press/dblclick/wheel='M'
        //（uVar15==2/0x1f）release/motion='m'（骨架 sendMouseEvent pressSuffix 同源）
        return QByteArray("<") + QByteArray::number(cb) + ';' + QByteArray::number(y + 1)
            + ';' + QByteArray::number(x + 1) + (sgrSuffixM ? 'M' : 'm');
    }
    return QByteArray();}
