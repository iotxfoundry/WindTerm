// UCS4 终端 cell 宽度——0x005f5450 utf8_decode_char_width 深逆照搬；
// 接入点 ScreenModel（光标前进/换行/占位）——按主 agent 放行
#pragma once

namespace CharWidth {

// 原版解码+宽度一体；骨架解码(VtParser)与宽度分两步，接在解码后码点上
int widthOfChar(unsigned int cp);

} // namespace CharWidth
