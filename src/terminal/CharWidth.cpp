#include "terminal/CharWidth.h"

namespace CharWidth {

// 0x005f5450 区间表：全内联比较照搬
int widthOfChar(unsigned int cp)
{
    if (cp < 0x1100)
        return 1;

    if ((cp >= 0x1100 && cp <= 0x115F)
        || cp == 0x2329 || cp == 0x232A
        || (cp >= 0x2E80 && cp <= 0xA4CF && cp != 0x303F)
        || (cp >= 0xAC00 && cp <= 0xD7A3)
        || (cp >= 0xF900 && cp <= 0xFAFF)
        || (cp >= 0xFE10 && cp <= 0xFE19)
        || (cp >= 0xFE30 && cp <= 0xFE6F)
        || (cp >= 0xFF00 && cp <= 0xFF60)
        || (cp >= 0xFFE0 && cp <= 0xFFE7)
        || (cp >= 0x1F300 && cp <= 0x1F64F)
        || (cp >= 0x1F900 && cp <= 0x1F9FF)
        || (cp >= 0x20000 && cp <= 0x2FFFD))
        return 2;

    // ≥0x30000 平面掩码式字面照抄：((cp & 0xfffeffff) - 0x20000) <= 0xFFFD
    // （bit16 折叠使 0x30000/0x3FFFD 命中宽、0x40000 窄；边界真值未运行时验证，静态照抄）
    if (cp >= 0x30000 && ((cp & 0xfffeffffu) - 0x20000u) <= 0xFFFDu)
        return 2;

    // FE0F/200D 无特判（自然窄）；肤色 1F3FB-1F3FF 终端 cell 层无零宽逻辑
    // （仅编辑器字体宽链 0x0066c318 有——终端不做，此处=2 区间自然覆盖）
    return 1;
}

} // namespace CharWidth
