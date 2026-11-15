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
#include <QByteArray>
#include <QDateTime>
#include <QElapsedTimer>
#include <QList>
#include <QString>
#include <QTimeZone>
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

// 批 161:'h'(host)/'n'(name)自有 token 腿升真 —— spdlog 实现不逆向
// (铁律/EXT-BOUNDARY):自有 token 用 face 层字面替换承接(语料引擎 =
// token 记录 + QByteArray::replace 偏移簿记,非 spdlog custom_flag_formatter
// 通道 —— 语料 %h/%n 不经 spdlog formatter,是 buildLeg 对文件名/行
// pattern 的前置替换,见 FUN_007c24c8 体)。
//
// session_state 0x48B 窄面(007c4a30,597B)字段布局(ctor 写点):
//   +0x00 QByteArray  行缓冲(pattern 渲染目标;init 先 realloc 0x100)
//   +0x08 QList<void*> token 记录(node 0x10:0x0=char/0x4=pos/0x8=
//                      oldLen/0xc=lastVal,FUN_007c4980 append 面)
//   +0x10 long long   基准 msecs(QDateTime::setMSecsSinceEpoch @init)
//   +0x18 long long   init msecs(QDateTime::currentMSecsSinceEpoch)
//   +0x20 long long   上次 msecs(FUN_007c5970 去重键)
//   +0x28 QDateTime   分钟锚(@007c61b6 addMSecs/setTime 截秒)
//   +0x40 int         秒余(param_2 - +0x10 拆秒)
//   +0x44 int         毫秒余
// 深依赖(QDateTime token 表引擎 FUN_007c5970 2712B/QTimeZone displayName
// /QLocale)cited —— 本面承接 init 字段面 + 'h'/'n' 替换腿(%A..%z 时间
// token 族仍 cited,登记不渲染)。
// 'h' 腿(@007c27d5 卫/@007c2864 replace):label(=virtualLabel,q+0x10
// 协议槽)空 → "UnknownIP";'n' 腿(@007c2931):name(label 参后段
// toUtf8,本面 = target 名参)直替换。替换簿记(@007c5882 同构):
// pos 累加 delta + replace(pos,oldLen,val)+ oldLen 换新。
struct SessionTokenState
{
	QByteArray buf;                        // +0x00 行缓冲
	struct Token { char c; int pos; int oldLen; int lastVal; };
	QList<Token> tokens;                   // +0x08 记录面(0x10 节点同构)
	long long baseMsecs = 0;               // +0x10(init 置 @007c4ad4 setMSecs)
	long long initMsecs = 0;               // +0x18(@007c4aa6 currentMSecs)
	long long lastMsecs = -1;              // +0x20(init 0xffffffffffffffff)
	int secPart = 0;                       // +0x40(5970 拆秒;cited 引擎槽)
	int msecPart = 0;                      // +0x44

	// 007c4a30(597B)窄面:init 字段序(qt 语料写点照抄;时间 token
	// 渲染引擎 5970 深依赖 cited —— 记录但不在 init 渲染)
	void init(const QByteArray &pattern)
	{
		buf.clear();                       // @007c4b26 QByteArray::clear
		buf.reserve(0x100);                // @007c4b3a reallocData 0x100
		tokens.clear();                    // @007c4aec 换新 + FUN_007c4440 清
		const long long now = QDateTime::currentMSecsSinceEpoch(); // @007c4aa6
		initMsecs = now;
		QElapsedTimer el;                  // @007c4aab QElapsedTimer::start
		el.start();
		baseMsecs = now;                   // @007c4ad4 setMSecsSinceEpoch
		lastMsecs = -1;                    // init 0xffffffffffffffff @+0x20
		// pattern 走查(@007c4bc7-4c02):'%%'→'%';%A..%z 时间族 →
		// token 记录(007c4980 面);%z → tz displayName(007c4bc7
		// toUtf8 append;深依赖 cited → 记 token);其余逐字 append。
		for (int i = 0; i < pattern.size();) {
			const char c = pattern[i];
			if (c != '%' || i + 1 >= pattern.size()) {
				buf.append(c);             // @007c4bdb
				++i;
				continue;
			}
			const char n = pattern[i + 1];
			if (n == '%') {
				buf.append('%');           // @007c4bf4
				i += 2;
			} else if (isTimeToken(n)) {
				tokens.append({n, buf.size(), 2, 0}); // @007c4980 node
				buf.append("  ");          // 占位 2 字节(语料 %X 两字节)
				i += 2;
			} else {
				buf.append(c);             // default @007c4bc0:逐字(语料
				++i;                       //   只前进 1;不吞首字节,原样)
			}
		}
	}
	static bool isTimeToken(char n)
	{
		switch (n) {
		case 'A': case 'B': case 'C': case 'H': case 'I': case 'M':
		case 'S': case 'Y': case 'a': case 'b': case 'd': case 'e':
		case 'h': case 'm': case 'n': case 'p': case 'v': case 'z':
			return true;
		}
		return false;
	}

	// 'h' 腿(@007c27d5 卫 + @007c2864 replace):host 空 → "UnknownIP"
	bool applyHost(const QString &hostLabel)
	{
		return replaceToken('h',
		    hostLabel.isEmpty() ? QByteArrayLiteral("UnknownIP")
		                        : hostLabel.toUtf8());
	}
	// 'n' 腿(@007c2931):name 直替换
	bool applyName(const QString &name) { return replaceToken('n', name.toUtf8()); }

	// 替换簿记(FUN_007c5882,223B 同构):pos 累加 + replace +
	// oldLen 换新(@007c5875 换新腿)
	bool replaceToken(char which, const QByteArray &val)
	{
		int delta = 0;
		for (Token &t : tokens) {
			t.pos += delta;                // @007c58a0 偏移簿记
			if (t.c != which)
				continue;                  // @007c58a4 非本 token 腿
			buf.replace(t.pos, t.oldLen, val);   // @007c58b4
			if (t.oldLen != val.size())    // @007c58bd
				delta += val.size() - t.oldLen;
			t.oldLen = val.size();         // @007c58c2
		}
		return true;
	}
};

// cited ③ 行 pattern 腿(@007c34c8-3500):session_state 行 pattern
// (param_8;空 → "[%Y-%m-%d %H:%M:%S] %v" 字面 @007c3500)→ formatter
// 重设(local 时型;真库委托 pattern_formatter,set_formatter 同
// FUN_005f5bc0 调面)。返回 false = null 卫/异常(语料 pattern 腿
// 失败不中断建腿,cited)。
inline bool applyLinePattern(void *loggerRaw, const QString &linePattern)
{
	if (!loggerRaw)
		return false;
	try {
		static_cast<spdlog::logger *>(loggerRaw)->set_formatter(
		    std::make_unique<spdlog::pattern_formatter>(
		        linePattern.isEmpty()
		            ? std::string("[%Y-%m-%d %H:%M:%S] %v")
		            : linePattern.toStdString(),
		        spdlog::pattern_time_type::local, std::string("\n")));
	} catch (...) {
		return false;
	}
	return true;
}

// 批 161:state 下行窄面 —— 行 pattern 解析产 token state(007c4a30
// init 窄面;真实例 0x48B 由调用侧持有,见 SpdlogLeg.state)。
inline bool initLineState(SessionTokenState &state, const QString &linePattern)
{
	state.init(linePattern.isEmpty()
	               ? QByteArrayLiteral("[%Y-%m-%d %H:%M:%S] %v")
	               : linePattern.toUtf8());
	return true;
}

} // namespace Ext

#endif // EXT_SPDLOGFACE_H
