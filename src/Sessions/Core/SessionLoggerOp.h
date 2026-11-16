#ifndef EXT_SPDLOGFACE_H
#define EXT_SPDLOGFACE_H

// SessionLoggerOp — **WindTerm 自己的会话日志构建腿**(A 类,已逆向)。
// 不是 spdlog 的代码:spdlog 只作为 sink/logger 容器被调用(第三方,不逆向);
// 本文件转写的是语料 FUN_007c24c8 建腿、FUN_007c4a30/FUN_007c5970 的
// **自研 token 时间格式化引擎**(语料 %h/%n/%A..%z 不经 spdlog formatter,
// 是 buildLeg 对 pattern 的前置替换 + 记录簿记)。
// 归属:Sessions/Core(与 SuperSessionPrivate::SessionLogger 同链),
// 2026-11-16 从 src/Ext/SpdlogFace.h 迁出 —— 放 Ext/ 会被误当成第三方接口面。
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
// 真盘写截停:sink 以 null_sink 承接(ext-boundary 使用规则 3
// no-op sink 判例)——文件/轮转形态实参由本面登记,行为面 cited。
#include <chrono>
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
#include <spdlog/details/log_msg.h>

namespace LoggerOp {

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
	// 真盘写由 null_sink 截停(ext-boundary 规则 3)
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
// (铁律/ext-boundary):自有 token 用 face 层字面替换承接(语料引擎 =
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
// 深依赖(QDateTime token 表引擎 FUN_007c5970/QTimeZone displayName
// /QLocale)—— 批 165:5970 渲染腿真身(见 renderTimeTokens);深
// QDateTime 时区面('%z' displayName)批 176 升真(init %z 腿直 append —
// 真库 timeZone().displayName(OffsetName) 承接;语料 007c4bc7 case 0x7a
// toUtf8 append 逐字面)。
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
	long long secPart = 0;                       // +0x40(5970 拆秒)
	int msecPart = 0;                            // +0x44
	QDateTime m_anchor;                          // +0x28 分钟锚(@007c4ab3 setMSecs)
	QElapsedTimer m_elapsed;                     // 语料 QElapsedTimer(@007c4aab)

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
		m_elapsed = el;
		m_elapsed = el;
		baseMsecs = now;                   // @007c4ad4 setMSecsSinceEpoch
		m_anchor.setMSecsSinceEpoch(now);  // @007c4ab3(锚 = now)
		lastMsecs = -1;                    // init 0xffffffffffffffff @+0x20
		// pattern 走查(@007c4bc7-4c02):'%%'→'%';%A..%z 时间族 →
		// token 记录(007c4980 面);%z → tz displayName 直 append
		// (32644-32652:toUtf8_helper append;批 176 升真 — 语料 32578
		// QTimeZone::displayName(anchor.timeZone(), QLocale()) 逐字面,
		// 真库 QDateTime::timeZone()+QTimeZone::displayName 承接);
		// 其余逐字 append。
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
			} else if (n == 'z') {
				// %z 腿(@007c4bc7 case 0x7a,32644-32652 逐字面):
				// displayName(tz) toUtf8 直 append(非 token;语料
				// 32578 QTimeZone::displayName(anchor.tz,QLocale(),
				// OffsetName) — 批 176 真库 QDateTime 承接面)
				buf.append(m_anchor.timeZone().displayName(
				    m_anchor, QTimeZone::OffsetName).toUtf8());   // @007c4bc7 append
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

	// 批 165:%A..%z 时间 token 渲染引擎真身(FUN_007c5970 2712B,
	// decomp-part-0024.c:33151 转写;语料 Qt 面 → 真库承接面):
	// 参数序 = (msecs,0 → QElapsedTimer 重算 | msgLen | msg 字节)。
	// 【去重/秒拆段 @007c5976-6365】msecs==+0x20 → 整体跳过(token 不动);
	// delta = msecs - +0x10;delta==0 → bVar4=false 仅记账;>0:59999 门
	// (> → 分钟锚刷新 @007c637f-63fe:锚 addMSecs(delta)→ setHMS(h,m,0)
	// 截秒 → +0x10=锚 epoch;bVar4=true @007c63fe)→ secPart=+0x40=
	// delta/1000,msecPart=+0x44=delta%1000(@007c6322-6357 magic 除)。
	// 写 +0x20=msecs(@007c59b3)。token 遍历前置 pos 累加 delta
	// (@007c6257-625f:pcVar2+4 += local_84);oldLen=+8 作 replace 长,
	// lastVal=+0xc 作同值卫(@007c4c56 init node:{c,pos,0,-1} 实读:
	// movabs 0xffffffff00000000 → +8=0/+0xc=-1;批 161 树占位腿保原样
	// ——怪癖候选登记,勿顺手改)。
	// 【token 语义映射(case 体 + rodata 串实证 .rodata@0xca09xx)】
	//   'A'→"dddd" 全周名 @007c616c/ca0967;'a'→"ddd" 缩周 @ca0968
	//   'B'→"MMMM" 全月名 @007c622e/ca09a6;'b'→"MMM" 缩月 @ca09a7
	//   'p'→"AP" @007c5a8b/ca0a3f(hour>11 卫 @007c5aaf cmp 0xb setg)
	//   'Y'→QByteArray::number(year) rightJustified(4,'0') @007c5d88
	//   'C'→year%100 rJ(2,'0') @007c611a;'d'→day rJ(2,'0') @007c5ce8
	//   'm'→month rJ(2,'0') @007c5ba6;'H'→hour rJ(2,'0') @007c603b
	//   'I'→hour%12 rJ(2,'0') @007c5f9c;'M'→minute rJ(2,'0') @007c5ebf
	//   'S'→secPart rJ(2,'0') @007c5e23;'e'→msecPart rJ(3,'0')
	//       @007c5c28(宽 3!批 165 实读 0x7c5c28 mov $0x3,%edx)
	//   'v'→msg 直替换(免锚;oldLen 换 msgLen + lastVal 清 0)
	//   'h'/'n' 自有腿不在 5970(007c6570/007c5882 独立引擎)
	//   'z' → 5970 无 case(跳表 @0xca7444 'z'=0x7c5a6e 直落下一 token;
	//        init 已渲染 displayName 字节)
	// 【锚卫】A/B/C/H/I/M/Y/d/m/p case 先 bVar4 门(分钟锚刷新当次才
	// 重渲染,@007c5fee-6300 系 cmpb $0,0x2b(%rsp));S/e 免锚(拆秒即值)。
	// 【同值卫】锚族 = lastVal != 产出字段才渲染 + lastVal 换字段值
	// (@007c6199 cmp %eax,0xc(%rbx) 系);渲染产物替换@pos+delta 累计
	// (007c5882 同构簿记 @LAB_007c62eb/5c72)。
	// 真库承接:语料 QDateTime::toString("dddd" 等)/QDate::day 族 =
	// 本面直接用 QDateTime 字段产同值字节(spdlog flags 同相已证批 155;
	// 产物 = 字符串对账,时区面 = local,深 QDateTime tz cited)。
	long long renderTimeTokens(long long msecs, int msgLen, const QByteArray &msg)
	{
		bool anchorRefreshed = false;              // 0x2b(%rsp) bVar4
		if (msecs == 0) {                          // @007c636a:QElapsedTimer 重算
			msecs = initMsecs + m_elapsed.elapsed();
		}
		if (msecs == lastMsecs) {                  // @007c5997 去重门
			return (long long)(intptr_t)this;      // 语料 return param_1
		}
		unsigned long long delta =                 // uVar10 @007c59a4
		    (unsigned long long)(msecs - baseMsecs);
		if (delta != 0) {                          // @007c59a8 jne
			anchorRefreshed = delta > 59999;       // @007c6314 cmp 0xea5f ja
			if (delta > 59999) {                   // @007c637f 分钟锚刷新
				QDateTime anchor = m_anchor.addMSecs((qint64)delta);
				m_anchor = anchor;                 // @007c6396-63a0 换锚
				const QTime at = anchor.time();    // @007c63b3
				m_anchor.setTime(QTime(at.hour(), at.minute(), 0)); // @007c63dc 截秒
				baseMsecs = m_anchor.toMSecsSinceEpoch();  // @007c63ef-63f4
				delta = (unsigned long long)(msecs - baseMsecs);
				anchorRefreshed = true;            // @007c63fe movb $1
			}
			const long long secs = (long long)(delta / 1000);  // @007c632f magic 除
			msecPart = (int)((long long)delta - secs * 1000);  // @007c6353 +0x44
			secPart = (int)secs;                   // @007c6357 +0x40
		} else {
			anchorRefreshed = false;               // @007c631d
		}
		lastMsecs = msecs;                         // @007c59b3 +0x20
		// token 遍历(@007c5a16-5a77):pos 累加 delta + 跳表分派
		int cumDelta = 0;                          // local_84
		const QDateTime now = m_anchor;            // 语料 QDateTime::date/time 源
		const QDate d = now.date();
		const QTime t = now.time();
		for (Token &tk : tokens) {
			tk.pos += cumDelta;                    // @007c5a1e-5a21
			switch (tk.c) {                        // 跳表 @0xca7444(5970 版)
			case 'A': case 'a': {                  // @007c616c
				if (!anchorRefreshed || tk.lastVal == d.day())
					break;                         // @007c5fee 卫臂
				const int day = d.day();
				replaceAt(tk, now.toString(tk.c == 'A' ? "dddd" : "ddd")
				                   .toUtf8(), cumDelta);   // @007c61d4-6228
				tk.lastVal = day;                  // @007c6300
				break;
			}
			case 'B': case 'b': {                  // @007c622e
				if (!anchorRefreshed || tk.lastVal == d.month())
					break;
				replaceAt(tk, now.toString(tk.c == 'B' ? "MMMM" : "MMM")
				                   .toUtf8(), cumDelta);   // @007c6296
				tk.lastVal = d.month();
				break;
			}
			case 'C': {                            // @007c608d
				if (!anchorRefreshed) break;
				const int y = d.year() % 100;      // @007c60de-60ee
				if (tk.lastVal == y) break;
				replaceAt(tk, QByteArray::number(y).rightJustified(2, '0'),
				          cumDelta);
				tk.lastVal = y;
				break;
			}
			case 'H': {                            // @007c5fee
				if (!anchorRefreshed) break;
				const int h = t.hour();
				if (tk.lastVal == h) break;
				replaceAt(tk, QByteArray::number(h).rightJustified(2, '0'),
				          cumDelta);
				tk.lastVal = h;
				break;
			}
			case 'I': {                            // @007c5f11
				if (!anchorRefreshed) break;
				const int h12 = t.hour() % 12;     // @007c5f68-5f72 %12
				if (tk.lastVal == h12) break;
				replaceAt(tk, QByteArray::number(h12).rightJustified(2, '0'),
				          cumDelta);
				tk.lastVal = h12;
				break;
			}
			case 'M': {                            // @007c5e72
				if (!anchorRefreshed) break;
				const int mm = t.minute();
				if (tk.lastVal == mm) break;
				replaceAt(tk, QByteArray::number(mm).rightJustified(2, '0'),
				          cumDelta);
				tk.lastVal = mm;
				break;
			}
			case 'S': {                            // @007c5df3(免锚)
				if (tk.lastVal == secPart) break;
				replaceAt(tk, QByteArray::number(secPart).rightJustified(2, '0'),
				          cumDelta);
				tk.lastVal = secPart;
				break;
			}
			case 'Y': {                            // @007c5d3a
				if (!anchorRefreshed) break;
				const int y = d.year();
				if (tk.lastVal == y) break;
				replaceAt(tk, QByteArray::number(y).rightJustified(4, '0'),
				          cumDelta);
				tk.lastVal = y;
				break;
			}
			case 'd': {                            // @007c5c9a
				if (!anchorRefreshed) break;
				const int day = d.day();
				if (tk.lastVal == day) break;
				replaceAt(tk, QByteArray::number(day).rightJustified(2, '0'),
				          cumDelta);
				tk.lastVal = day;
				break;
			}
			case 'e': {                            // @007c5bf8(免锚;宽 3)
				if (tk.lastVal == msecPart) break;
				replaceAt(tk, QByteArray::number(msecPart).rightJustified(3, '0'),
				          cumDelta);
				tk.lastVal = msecPart;
				break;
			}
			case 'm': {                            // @007c5b58
				if (!anchorRefreshed) break;
				const int month = d.month();
				if (tk.lastVal == month) break;
				replaceAt(tk, QByteArray::number(month).rightJustified(2, '0'),
				          cumDelta);
				tk.lastVal = month;
				break;
			}
			case 'p': {                            // @007c5a8b
				if (!anchorRefreshed) break;
				const int pm = t.hour() > 11 ? 1 : 0;   // @007c5aaf cmp 0xb setg
				if (tk.lastVal == pm) break;
				replaceAt(tk, now.toString("AP").toUtf8(), cumDelta);
				tk.lastVal = pm;
				break;
			}
			case 'v': {                            // @007c5a3a(免锚)
				buf.replace(tk.pos, tk.oldLen, msg);   // @007c5a4d
				if (msgLen != tk.oldLen) {     // @007c5a52-5a63
					cumDelta += msgLen - tk.oldLen;
				}
				tk.oldLen = msgLen;
				tk.lastVal = 0;                // @007c5a67 四字节清 0
				break;
			}
			default:                               // @007c5a6e('z'/未知直落)
				break;
			}
		}
		return (long long)(intptr_t)this;          // 语料 return param_1
	}

	// 替换簿记(@LAB_007c62eb/5c72 同构):replace + 长差累计 + oldLen 换新
	void replaceAt(Token &tk, const QByteArray &out, int &cumDelta)
	{
		buf.replace(tk.pos, tk.oldLen, out);
		if (out.size() != tk.oldLen) {             // @007c62eb-62f5
			cumDelta += out.size() - tk.oldLen;
		}
		tk.oldLen = out.size();
	}
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

// 批 165:5970 调面窄面(007c1f2c(131B,0024.c:30854)同构):logger 行
// 面 +0x38 非 0 → renderTimeTokens(state,msgLen,msg)。真库承接腿:
// pattern_formatter format 一条样例消息取产物(行为级真身;m_runtimeMsecs
// 由 SessionLogger 侧记账)。真盘写仍 null_sink 截停。
inline QByteArray formatSampleLine(void *loggerRaw, SessionTokenState &state,
                                   long long msecs, const QByteArray &msg)
{
	if (loggerRaw) {
		state.renderTimeTokens(msecs, msg.size(), msg);   // 007c1d40 调面
		auto *lg = static_cast<spdlog::logger *>(loggerRaw);
		spdlog::details::log_msg sample(lg->name(), spdlog::level::info,
		                                spdlog::string_view_t(msg.constData(),
		                                              size_t(msg.size())));
		sample.time = std::chrono::system_clock::time_point(
		    std::chrono::milliseconds(msecs));            // msg.time 对位
		// 独立 pattern_formatter 承接(语料 formatter = buildLeg set 的
		// "%v"/行 pattern;logger 无 formatter 读面 —— 以默认行 pattern
		// 重建取产物,format 语义同 FUN_005f611c 面)
		spdlog::pattern_formatter fmt("[%Y-%m-%d %H:%M:%S] %v",
		                              spdlog::pattern_time_type::local,
		                              std::string("\n"));
		spdlog::memory_buf_t dest;
		fmt.format(sample, dest);
		return QByteArray(dest.data(), int(dest.size()));
	}
	return state.buf;
}

} // namespace LoggerOp

#endif // EXT_SPDLOGFACE_H
