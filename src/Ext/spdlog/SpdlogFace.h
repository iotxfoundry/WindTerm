#ifndef EXT_SPDLOG_FACE_H
#define EXT_SPDLOG_FACE_H

#pragma once

// 外部库边界接口(声明层,无实现)——spdlog 日志面。
// 依据:inc/spdlog/include/spdlog/{logger.h,common.h}(原版静态
// 嵌入的 spdlog API 子集,取终端日志用到的最小面)。
// 实现 = 待 logger 面(FUN_007c1b92 族)转写后委托真 spdlog 或
// no-op sink;本头文件仅固定调用形状,防逆向漂入库实现。

#include <string>

namespace ext {
namespace spdlog {

enum level_enum
{
    trace = 0,
    debug = 1,
    info = 2,
    warn = 3,
    err = 4,
    critical = 5,
    off = 6,
    n_levels
};

// logger.h 的 sink 面(终端日志用到的子集):name/level/log/flush。
// 真版为 shared_ptr<sink> 向量 + formatter 每 sink 私有——本面收拢
// 为单 sink 形状,转写需要多 sink 时再扩。
class LoggerFace
{
public:
    virtual ~LoggerFace() = default;

    virtual void setName(const std::string &name) = 0;
    virtual const std::string &name() const = 0;
    virtual bool shouldLog(int lvl) const = 0;
    virtual void log(int lvl, const std::string &msg) = 0;
    virtual void flush() = 0;
};

} // namespace spdlog
} // namespace ext

#endif // EXT_SPDLOG_FACE_H
