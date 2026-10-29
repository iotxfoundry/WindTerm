#ifndef EXT_FMT_FACE_H
#define EXT_FMT_FACE_H

#pragma once

// 外部库边界接口(声明层,无实现)——fmt 格式化面。
// 依据:inc/fmt/include/fmt/format.h(原版静态嵌入的 fmt API 子集:
// format/append 两个最常用形状)。实现待格式化调用点转写后
// 委托真 fmt;此处仅固定调用形状。

#include <string>
#include <string_view>

namespace ext {
namespace fmt {

// fmt::format(fmt, args...) 主形状(转写调用点出现即扩展重载)
std::string format(std::string_view fmtStr, const std::string &a0);
std::string format(std::string_view fmtStr, long long a0);
std::string format(std::string_view fmtStr, int a0);

} // namespace fmt
} // namespace ext

#endif // EXT_FMT_FACE_H
