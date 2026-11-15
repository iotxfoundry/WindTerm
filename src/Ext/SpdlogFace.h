#ifndef EXT_SPDLOGFACE_H
#define EXT_SPDLOGFACE_H

// 批 151(M15-②):spdlog 1.9.2 真库委托面(EXT-BOUNDARY:外库实现
// 不逆向,只落 WindTerm 侧调面)。include 按 TU 局部接线(CMake
// set_source_files_properties;全局 -I 与 Scintilla/Qt 头冲突实测
// 6k 错,见 CMakeLists 批前注)。
//
// 语料调面源(0024.c FUN_007c24c8 腿体):
//   建腿② @007c3751-3388:param_6<1 → 基础 file sink(operator_new
//   0x48;logfile_open @007c38e5,append=param_5 bit0);else → 轮转
//   sink(0x68:base @+0x30/maxsize = min(param_6,0x3fffff)<<10
//   @007c3035/max_files=1 @+0x40/fstat 初值 @+0x48);logger =
//   operator_new(200)(PTR_FUN_011868c8 @007c3921)+ FUN_007c44a4
//   sink 绑定 + FUN_007c4cf0 registry instance + logger_register_unique
//   00612a90 → +0x38 logger*(p_Var18+0x10 @007c39ac)/+0x40 持有块
//   (p_Var18 @007c39b7)。
//   formatter③前段 @007c3388-3499:pattern_formatter("%v", local,
//   "\n")→ set_formatter FUN_005f5bc0。
// 真盘写截停:sink 以 null_sink 承接(EXT-BOUNDARY 使用规则 3
// no-op sink 判例)——文件/轮转形态实参由本面登记,行为面 cited。
#include <memory>
#include <string>
#include <QString>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/null_sink.h>
#include <spdlog/pattern_formatter.h>

namespace Ext {

struct SpdlogLeg
{
	void *loggerRaw = nullptr;         // 语料 +0x38(logger*)
	std::shared_ptr<void> loggerOwn;   // 语料 +0x40(200B logger 持有块)
	bool rotating = false;             // param_6>=1 腿(@007c2f9a else 臂)
	long long maxBytes = 0;            // 轮转实参 lVar9<<10(@007c3035)
};

inline SpdlogLeg buildSessionLogger(bool rotating, const QString &name,
                                    long long rotateBytes)
{
	SpdlogLeg leg;
	leg.rotating = rotating;
	// @007c3035:lVar9 = 0x3fffff if param_6 >= 0x400000 else param_6
	leg.maxBytes = (rotateBytes < 0x400000 ? rotateBytes : 0x3fffff) << 10;
	// sink 形态登记(真形态 = basic/rotating file sink,实参照上注);
	// 真盘写由 null_sink 截停(EXT-BOUNDARY 规则 3)
	std::shared_ptr<spdlog::sinks::sink> sink =
	    std::make_shared<spdlog::sinks::null_sink_mt>();
	auto lg = std::make_shared<spdlog::logger>(name.toStdString(), sink);
	// formatter @007c3388-3499:"%v" + "\n"(local 时型)
	lg->set_formatter(std::make_unique<spdlog::pattern_formatter>(
	    "%v", spdlog::pattern_time_type::local, std::string("\n")));
	// registry FUN_007c4cf0 + logger_register_unique 00612a90 调面
	try {
		spdlog::register_logger(lg);
	} catch (...) {
		// 重名:语料 register 失败不中断建腿(logger 仍存 +0x38/+0x40)
	}
	leg.loggerRaw = lg.get();
	leg.loggerOwn = lg;
	return leg;
}

// FUN_007c1b92(31B,0024.c:30539)冲刷调面:logger vtable+0x20 =
// spdlog logger::flush(null sink 下为 no-op,不打盘)
inline void flushSessionLogger(void *loggerRaw)
{
	if (loggerRaw)
		static_cast<spdlog::logger *>(loggerRaw)->flush();
}

} // namespace Ext

#endif // EXT_SPDLOGFACE_H
