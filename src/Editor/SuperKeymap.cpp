#include "SuperKeymap.h"

#include <QByteArray>
#include <QHash>
#include <QKeyEvent>
#include <QApplication>
#include <QCoreApplication>
#include <QFrame>
#include <QKeySequence>
#include <QJSValue>
#include <QJSValueList>

#include "Actions/JsEngine.h"

#include <cstring>
#include <cerrno>
#include <cwchar>
#include <stdexcept>
#include <string>

// ── 键码双向编解码(DAT_011c1960)─────────────────────────────
// 语料体全文可读(00674206 204B / 00674b1e 431B,decomp-part-0020.c
// 61673-62282;表数据运行期惰性生成,无静态内容可读 —— 非查表函数,
// 真身化即转写读写算法本身)。

namespace {
struct KeymapCodecTable {
	// DAT_011c1960 形:{u32 锁@0, QList<uint> 槽表@8, trie root@0x10}
	// (FUN_006741ec 26B,_INIT_62 初始化 0016.c 13587-13588)。
	// 成员名避 Qt `slots` 宏(qobjectdefs.h `#define slots Q_SLOTS`)。
	QList<uint> keySlots;     // +8:槽序→键码(00674206 读侧权威)
	QHash<uint, int> byKey;   // +0x10 trie(FUN_006804ac 701B 机械)的
	                          //   键→槽等价承载 —— 契约:命中返槽值,
	                          //   未命中 append 槽表并占新槽(62270-62284)
};
KeymapCodecTable &codecTable()   // DAT_011c1960 全局静态(_INIT_62)
{
	static KeymapCodecTable t;
	return t;
}
}  // namespace

// 00674206(204B)语料转写(006742d2 14B thunk → 本体;行号 = 0020.c):
//   (int)code < 0xff → 原样(61685);槽序 = code - 0xff(61688);
//   越界 → 0x1ffffff(61690);否则槽表[序](61694/61709,QList
//   detach 机械 61698-61708 = Qt5 值语义承载)。
uint keymapKeyForward(uint code)
{
	if ((int)code < 0xff)
		return code;
	const int idx = (int)code - 0xff;   // 61688
	const KeymapCodecTable &t = codecTable();
	if (idx >= t.keySlots.size())
		return 0x1ffffff;   // 61690 门
	return t.keySlots.at(idx);
}

// 00674b1e(431B)语料转写(00674cce 14B thunk → 本体;行号 = 0020.c):
//   key < 0xff → 原样(62187);key == 0x1ffffff → 0xffff(62190);
//   trie 命中 → entry 值 + 0xff(62281);未命中 → 槽表 append(key)
//   (62272)+ trie 插(key, 槽序)(62275)→ 槽序 + 0xff(62276);
//   槽表 ≥ 0xff00 → 0xffff(62270 门,饱和上限)。
uint keymapKeyReverse(int key)
{
	if (key < 0xff)
		return (uint)key;   // 62187
	if (key == 0x1ffffff)
		return 0xffff;      // 62190
	KeymapCodecTable &t = codecTable();
	const auto it = t.byKey.constFind((uint)key);
	if (it != t.byKey.cend())
		return (uint)(it.value() + 0xff);   // 62281:+0x14 值 + 0xff
	const int idx = t.keySlots.size();
	if (idx >= 0xff00)
		return 0xffff;   // 62270 iVar2 < 0xff00 门
	t.keySlots.append((uint)key);        // 62272 qlist_uint_append
	t.byKey.insert((uint)key, idx);      // 62275 FUN_006804ac(key, 槽序)
	return (uint)(idx + 0xff);           // 62276
}

// 语料内部:FUN_0067db40(60B,QList 容量确保)/ FUN_0067ce4c(49B,
// 槽交换销毁)/ FUN_0067ce30(项销毁走查)—— Qt QListData 管理形,
// Qt5 QList 原生等价操作承载(同源等价,非缺口)。

// FUN_00674456(87B)— cited — wave-2:FUN_00674442 mainPane 静态对象
// cast(PTR_staticMetaObject_011a6c00)+ mainPane_currentWidgetCast +
// status_showMessage(widget,msg,kind,0xfa,timeout = kind==3 ? 3000 : 0)
// (0067445b-0067447e 语料)。mainPane 面未转写 → 占位空实现。
static void statusFeedback(const QString &msg, int kind)
{
	Q_UNUSED(msg)
	Q_UNUSED(kind)
}

// FUN_00674cdc keys_parseAngleNotation(753B,decomp-part-0020.c
// 62295-62390)语料转写。角括号记法 → 键序列编码:
// 正则 "(?<!\\?P|\\?)<([^>]*)>"(00674d20 字面)循环;captured 名内
// 别名 replace("<"→"less" 00674e45 / ">"→"great" 00674e8b /
// "enter"→"return" 00674ed3;第四组 "cancel" 的 repl 实参寄存器未解
// —— cited — wave-2,同块字面 "less\0great\0return\0cancel"@00c91c5b);
// QKeySequence(name)[0](00674f2a),param_3=1 → &0x9fffffff
// (屏蔽 0x60000000);0/0x1ffffff → capturedEnd 推进;否则
// FUN_00674cce(14B thunk → FUN_00674b1e 431B 键码→槽反向)→
// replace(pos,len,槽字符) → +1 推进(00674f6b-00674f7d,真身化);
// 尾 toUcs4 → wstring(00674f83-00674fb2;QString 承载同域)。
static QString keysParseAngleNotation(QString keys, bool maskReserved)
{
	const QRegularExpression re(QStringLiteral("(?<!\\?P|\\?)<([^>]*)>"));
	keys = keys.trimmed();   // 00674d33
	int i = 0;
	forever {
		const QRegularExpressionMatch ms = re.match(keys, i);   // 00674de7
		if (!ms.hasMatch()) {
			i = keys.size();   // 00674def 循环出口
			break;
		}
		// captured 实参寄存器未注(00674e18);组 1(括号内名)为归纳落点
		QString name = ms.captured(1);
		name.replace(QLatin1String("<"), QLatin1String("less"));      // 00674e45
		name.replace(QLatin1String(">"), QLatin1String("great"));     // 00674e8b
		name.replace(QLatin1String("enter"), QLatin1String("return")); // 00674ed3
		// 00674f0b replace("cancel", <repl 未解>)— cited — wave-2
		const QKeySequence seq(name);   // 00674f14
		uint code = seq[0];             // 00674f2a
		if (maskReserved)
			code &= 0x9fffffff;   // param_3 屏蔽 0x60000000
		if (code == 0 || code == 0x1ffffff) {
			i = ms.capturedEnd();   // 00674f6a
		} else {
			// 00674f6b:FUN_00674cce(62287-62292,thunk)键码→槽字符(真身化,
			// undefined2 截断 = QChar(u16) 承载)
			const uint nameChar = keymapKeyReverse((int)code);
			keys.replace(ms.capturedStart(), ms.capturedLength(), QChar(nameChar));
			i = ms.capturedStart() + 1;   // 00674f7d
		}
		if (i >= keys.size())   // 00674f8b 循环门
			break;
	}
	return keys;
}

// 00674648(161B)语料转写:
//   QObject(parent) → vtable → +0x10 槽列表(FUN_0067db7c,容量 2)
//   → +0x18 = QRegularExpression("meta\\+|\\+meta",
//   CaseInsensitive)(006746b9 字面实证)
SuperKeymap::SuperKeymap(QObject *parent)
	: QObject(parent)
	, m_metaRe(QStringLiteral("meta\\+|\\+meta"),
	           QRegularExpression::CaseInsensitiveOption)
{
	m_slots.reserve(2);   // FUN_0067db7c(+0x10,2)
}

// 0067461a(45B)语料转写:FUN_0067db40(+0x10)容量确保 →
// FUN_0067ce4c(mode 槽)清 —— 语料裸寻址无守卫;此处按容器界
// 增长到位再清(容量确保语义,勿增行为)
void SuperKeymap::reset(int mode)
{
	while (m_slots.size() <= mode)
		m_slots.append(QList<KeymapEntry>());   // FUN_0067db40 容量确保
	m_slots[mode].clear();   // FUN_0067ce4c(mode 槽清)
}

// ── 装载翼 ──────────────────────────────────────────────

// FUN_00678a56(4985B,decomp-part-0020.c 64556-65110)骨架转写:
// 条目循环(QList begin/end 00678a5f)逐项 toMap(00678ac2)→
// FUN_00677d7e(engine,map,mode);尾段 = 内联 QMap 析构走查
// (64565+ 解构链,Qt5 值语义自动承载,非缺口)。
void SuperKeymap::loadEntries(const QVariantList &list, int mode)
{
	for (const QVariant &item : list) {
		parseEntry(item.toMap(), mode);   // 00678ac8 → 00677d7e
	}
}

// FUN_00677d7e(3031B,decomp-part-0020.c 64157-64555)骨架转写
// (大函数分级:条目字段提取/位掩码/节点域落位;深腿 cited):
void SuperKeymap::parseEntry(const QVariantMap &map, int mode)
{
	// 1. map["keys"](qmap_lower_bound_find,00677dbe)→ toString(00677e12)
	const QString keys = map.value(QStringLiteral("keys")).toString();
	// 2. meta 正则预检(engine +0x18;命中 → 整条弃,goto 00677f67)
	if (keys.contains(m_metaRe))
		return;
	// 3. 0x50 节点(operator_new(0x50)00677eb0,vtable PTR_FUN_01189508)
	KeymapEntry entry;
	// 4. 角括号编码(00677efd;param_3=1 → 屏蔽 0x60000000)
	entry.keysEncoded = keysParseAngleNotation(keys, true);
	// 5. 编码空 → 弃(00677fb3 门:keys wstring len != 0 才续)
	if (entry.keysEncoded.isEmpty())
		return;
	// 6. map["modes"](64243 qstring_assign_from_ascii 字面 —— 批 55
	//    「语料无 modes 串」被本函数推翻)split(',',behavior=1
	//    SkipEmptyParts,00678023)
	const QStringList modes = map.value(QStringLiteral("modes"))
	                              .toString()
	                              .split(QLatin1Char(','), Qt::SkipEmptyParts);
	if (modes.isEmpty()) {
		entry.modesMask = 0x1f;   // 0067803b:空 modes → 全模式位
	} else {
		// 006780f4-00678155:逐项 trimmed 精确比较 → 位或
		for (const QString &m : modes) {
			const QString t = m.trimmed();
			if (t == QLatin1String("widget"))
				entry.modesMask |= 1;   // 0067811a
			else if (t == QLatin1String("normal"))
				entry.modesMask |= 2;   // 00678134
			else if (t == QLatin1String("command"))
				entry.modesMask |= 4;   // 0067814e
			else if (t == QLatin1String("remote"))
				entry.modesMask |= 8;   // 00678168
			else if (t == QLatin1String("local"))
				entry.modesMask |= 0x10;   // 00678182
		}
		// 掩码 0(全未知词)→ 弃(0067806c 前门 else → LAB_006780b2)
		if (entry.modesMask == 0)
			return;
	}
	// 7. onig 编译腿(00678295-006783fe:locale facet "space"/"alnum"/
	//    "upper" FUN_0067ed05 + onig_checkParens + FUN_0067fb80 →
	//    FUN_00687320 换入节点 +0x18)— cited — wave-2
	//    (regexSource 留空,不伪造编译产物)
	// 8. action/map/script 三名循环(00678436 名表;首个命中者胜 →
	//    LAB_00678588 出循环;无名命中 → +0x28 保持 ctor 初值 0)
	static const char *kNames[] = {"action", "map", "script"};
	for (const char *name : kNames) {
		const auto it = map.constFind(QLatin1String(name));
		if (it == map.cend())
			continue;
		// 006787d1:toByteArray().trimmed() → 节点 +0x30 payload 换入
		entry.payload = it->toByteArray().trimmed();
		// 00678801:qstrcmp 序 → +0x28(action=0/map=1/script=2)
		entry.actionType = qstrcmp(name, "action") == 0
		                       ? 0
		                       : (qstrcmp(name, "map") != 0 ? 2 : 1);
		break;
	}
	// 9. map["when"](DAT_00c91ca5 字面)→ +0x40 无条件 assign(006785ae)
	entry.when = map.value(QStringLiteral("when"));
	// 10. map["repeatable"] toBool → +0x20(00678618)
	entry.repeatable = map.value(QStringLiteral("repeatable")).toBool();
	// 11. 入槽:FUN_0067db40(engine+0x10)容量确保 → FUN_0067de60
	//     (槽基 + mode*8 + 数据,0067868d)append 节点;插入门 =
	//     编码非空(00678679 toByteArray 段,与 5 同判)
	while (m_slots.size() <= mode)
		m_slots.append(QList<KeymapEntry>());   // FUN_0067db40
	m_slots[mode].append(entry);   // FUN_0067de60
}

// ── 匹配翼辅助真身 ─────────────────────────────────────────
// js_actionFire(006697b2)ActionFactory.cpp 57 行定义,外部链接
// (头文件未声明)—— 0066a116 转写所需的既有面。
void js_actionFire(QVariant &out, QObject *target, const char *jsFuncName,
                   const QJSValue &arg);

// FUN_0075debe(529B,decomp-part-0023.c 27155-27232)语料转写:
// 合成键事件对投递焦点 widget。param_1(qApp)体零消费(0075e0c4
// unreachable 移除),签名落 (keys)。体:keys_parseAngleNotation
// 再解析(27177,param_3=1)→ ucs4 走查(27193-27194)→
// 每字符:006742d2 正解码(27210)→ mods = code & 0x7e000000
// (27211)→ base = code - mods(27213)→ 可打印门 [0x20,0x7e]
// ∪ [0xa0,0x15f](27214)→ text = QChar(base)(27216)→
// QKeyEvent(type=6 KeyPress)(27220,autorep=0,count=1)+
// QKeyEvent(type=7 KeyRelease)(27224)→ 双双 postEvent(focusWidget)
// (27228/27231,qcoreapp_self_get ×2;priority=0 默认档)。
static void synthKeyEvents(const QString &keys)
{
	const QString encoded = keysParseAngleNotation(keys, true);   // 27177
	const QVector<uint> ucs = encoded.toUcs4();                   // 27193
	for (const uint ch : ucs) {
		const uint code = keymapKeyForward(ch);      // 27210 FUN_006742d2
		const uint mods = code & 0x7e000000u;        // 27211
		const uint base = code - mods;               // 27213
		QString text;   // 27212 shared_null
		if ((base - 0x20) < 0x5f || (base - 0xa0) < 0x60)   // 27214 门
			text = QString(QChar(base));             // 27216
		auto *press = new QKeyEvent(QEvent::KeyPress, (int)base,
		                            Qt::KeyboardModifiers(mods), text,
		                            false, 1);                    // 27220
		auto *release = new QKeyEvent(QEvent::KeyRelease, (int)base,
		                              Qt::KeyboardModifiers(mods), text,
		                              false, 1);                  // 27224
		// 语料 receiver = qcoreapp_self_get()×2 + focusWidget(27228/
		// 27231;QWidget* → QObject* 上行承载)
		QWidget *fw = QApplication::focusWidget();
		QCoreApplication::postEvent(fw, press);    // 27228
		QCoreApplication::postEvent(fw, release);  // 27231
	}
}

// FUN_0066a116(49B,0020.c 52844-52856)语料转写:uVar1 =
// actionFactory_getOrCreate(param_2,param_3)→ js_actionFire
// (param_1,param_2,uVar1,param_4);调用上下文 FUN_007682c0(18B,
// 0023.c 34690-34697):0066a116(out, *(castHost+0x60), …)。
// *(+0x60) 目标 = mainPane 面(00674442 cast 011a6c00)未转写
// (cited),非空才进(语料 cast 恒成功;我方 face 缺 → 空即短路,
// 勿造目标);getOrCreate(语料带 target 实参,批 35
// ActionFactory::getOrCreate(QByteArray)单参面)工厂实例归属未接线
// → 槽注记保留,fire 腿转写。
static void keymapActionFire(QVariant &out, QObject *target,
                             const QByteArray &actionName,
                             const QJSValue &jsArg)
{
	if (target == nullptr)
		return;   // *(mainPane+0x60) 面 cited — wave-2
	// actionFactory_getOrCreate(actionName)→ QAction(工厂实例未接线,
	// 槽注记;js_actionFire 内部走 target property("data") 面等价)
	Q_UNUSED(actionName)
	// js_actionFire(out, target, action, jsArg)(0066a116 +0x10)
	js_actionFire(out, target, "state", jsArg);
}

// ── 匹配翼 ──────────────────────────────────────────────

// js_actionFire(006697b2)—— 定义在 ActionFactory.cpp(外部链接),
// 0066a116 转写调用面(本文件上方已 extern 声明)。

// FUN_006777e6(1347B,decomp-part-0020.c 63958-64156;语料误名
// s_basic_string__substr_6777e6)语料转写:增量按键喂入。
// param_4==0 早退(006777f3)—— 引用形参数恒在,门注记略。
int SuperKeymap::feedKey(KeymapInputRecord &record, uint key, int flags)
{
	record.m_buffer.append(QChar(key));   // 0067775c:+8 wstring append(1,param_2)
	const QString &buf = record.m_buffer;
	const int len = buf.size();   // uVar4
	// 0067777a-006777b1:flags∈{4,0x10} 时扫前导 ASCII 数字
	// (首字符 '0' → 0 短路,00677799;非 0x30..0x39 即停)
	int digits = 0;
	if (flags == 4 || flags == 0x10) {
		while (digits < len) {
			const ushort c = buf.at(digits).unicode();
			if (c < '0' || c > '9')
				break;
			if (c == '0' && digits == 0) {
				digits = 0;   // 00677799
				break;
			}
			++digits;
		}
	}
	const bool chord = digits == len || digits + 1 == len;   // local_dd(006778ad)
	// token 向量(006779e2-00677a2d):{buf 克隆, digits==0 ? buf 克隆
	// : buf.substr(digits)}(FUN_00674702 dup / FUN_006748b6 substr)
	QVector<QString> tokens{buf, digits == 0 ? buf : buf.mid(digits)};
	MatchOut out;
	out.flags = static_cast<quint32>(flags);   // local_dc[0] = param_3
	out.ctxWhen = this;                        // 语料 *[1] = this(006777e6 local_c8)
	out.ctxDispatch = this;                    // 语料 *[2] = this(local_c0/mainPane cast 面 cited)
	out.record = &record;                      // 语料 *[3] = param_4(local_e8)
	int result = 0;                            // local_cc = 0
	if (!chord) {
		// 00677c4d:非弦态仅试记录弦清单(mode=2,learn 槽)
		matchTrie(out, record.m_chords, tokens, 2);
		result = out.result;
		if (result == 2) {
			// LAB_00677c20(00677c39):完全命中 → 空串状态反馈 kind 0
			statusFeedback(QStringLiteral(""), 0);   // FUN_00674456
		}
	} else if (digits != len || (flags != 4 && flags != 0x10)) {
		// 00677acf / 00677b0f:弦态 ×3 链的 slot0/slot1 腿
		// (FUN_0067db40 容量确保后裸寻址,语料)
		while (m_slots.size() < 2)
			m_slots.append(QList<KeymapEntry>());
		matchTrie(out, m_slots[0], tokens, 0);   // 00677acf(slot0)
		result = out.result;
		if (result != 2) {
			matchTrie(out, m_slots[1], tokens, 1);   // 00677b0f(slot1)
			result = out.result;
		}
		if (result == 2) {
			statusFeedback(QStringLiteral(""), 0);   // LAB_00677c20 共享
		}
	} else {
		result = 1;   // 00677b1f:纯 count 前缀(全数字 + flags∈{4,0x10})
	}
	if (result != 2) {
		// FUN_006742e0(322B)键码序列→toString 拼接(可打印直拼)
		// — cited — wave-2(keysStr 空占位)
		const QString keysStr;
		if (result == 0) {
			if (!chord || digits != 0) {
				// tr 串@0x00c92230(语料字面);kind=3(3000ms 档)
				statusFeedback(QObject::tr("The key combination (%1) is not a command.")
				                   .arg(keysStr),
				               3);   // FUN_00674456(00677b9e)
			}
			record.clearBuffer();   // FUN_006745b0(00677bb8)
		} else if (result == 1) {
			// tr 串@0x00c92260(语料字面);kind=1
			statusFeedback(QObject::tr("(%1) was pressed. Waiting for more keys...")
			                   .arg(keysStr),
			               1);   // FUN_00674456(00677cdb)
		}
	}
	// 尾(00677d3e):result==0 → 返回 local_dd^1;否则 1
	return result == 0 ? (chord ? 0 : 1) : 1;
}

// ── 走查体辅助真身(§5-§10)────────────────────────────────

// FUN_00681a40(392B,0021.c 4594-4671)语料转写:§5 节点获取/复位。
//   *param_1(返回槽) = 0;param_2 槽空 → 新建直挂;槽非空且节点
//   use==1 → 复用直返(*param_1 保持 0,§6-§8 跳过);否则旧根
//   use++ 持有(*param_1 = 旧根),槽换新后旧根 FUN_0067fae4 释放面
//   由调用方走查收尾承载(§6-§8 后 use-- 复位)。
//   km3 ctrl 落地:0x18 ctrl 块 = xpressive 编译产物(boost 边界
//   EXT-BOUNDARY,块体不伪造 —— 编译腿 cited — wave-2);shared_ptr
//   承载 = 标准库委托(_Sp_counted_base use/weak 计数面同构)。
//   4649-4651 LOCK use++ → shared_ptr 强引用持有 +0x68;编译产物本体
//   永不解引(空 delete 形,块仅计数)。
//   语料节点 use(+0x70,4609-4614 LOCK++)= "走查中" 计数:它数的是
//   FUN_0067fae4 62665 侧释放者;本转写按语料原样保留 +0x70 裸计数
//   (持有面 4615 换手由 snap 返回承载),槽头 shared_ptr 仅承载
//   节点生命周期(语料槽换入 *param_2 = pvVar3 等价)。
static TrieNode *trieNodeGetOrCreate(std::shared_ptr<TrieNode> *slot)
{
	TrieNode *snap = nullptr;   // *param_1 = 0(4604)
	if (slot->get() != nullptr) {   // 4605:*param_2 != 0
		if (slot->get()->use == 1)   // 4606:use==1 → 复用直返
			return snap;
		// 4609-4614:LOCK;旧根 use++(持有)
		slot->get()->use += 1;
		snap = slot->get();   // 4615-4616:*param_1 = 旧根
	}
	// 4622-4643:0xb8 节点新建(布局逐字段;std 成员 ctor 承载零值)
	TrieNode *node = new TrieNode;
	// 4645-4651:0x18 ctrl 产出 + LOCK use++ → +0x68 挂接(4652-4659
	//   self/ctrl 换入)—— ctrl 块体 cited — wave-2,shared_ptr 空承载
	node->payloadCtrl = KeymapCtrlPtr(new int(0), [](int *p) { delete p; });
	node->payloadSelf = node;   // 4652:+0x60 = self
	// 4664-4668:*param_2 = 新节点(槽换入;旧根释放随 shared_ptr 赋值)
	*slot = std::shared_ptr<TrieNode>(node);
	return snap;   // 4670
}

// LAB_006759bf(62664-62681)+ FUN_0067fae4(82B,0021.c 2217-2245)承载:
//   use-- → 0 → 树1 走查回收(FUN_0067faa0 2219-2213:右子递归 + 左链迭代,
//   节点 +0x28 值 ctrl refcounted_vt_destroy —— ctrl cited,键树条目释放
//   随 std::set 析构承载)+ 字段复位(+0x10/18/20/28 = 树1 空、+0x60/+0x68)。
static void trieNodeReset(TrieNode *node)
{
	if (node == nullptr)
		return;
	node->use -= 1;   // 62665-62668(LOCK;use--)+ 2217-2228(FUN_0067fae4)
	if (node->use != 0)
		return;   // 2229-2231
	node->keyTree.clear();          // 62670 + FUN_0067faa0 树1 回收
	node->keyTree = {};             // 62671-62674:树1 复位(0021.c 2232-2236
	                                //   parent/left/right/count 复位形)
	// 树2 不复位 —— FUN_0067fae4(0021.c 2232-2243)仅 +0x10/18/20/28/
	//   +0x60/+0x68 域,不含树2(语料原样;裁剪由 §8 承担)。
	node->payloadSelf = nullptr;    // 62675:+0x60 = 0(2237)
	// 62676-62680:+0x68 ctrl 释放(refcounted_vt_destroy)—— shared_ptr
	//   强引用释放 = 标准库 _M_release(计数→0 → dispose),ctrl 块体
	//   (boost 产物)cited — wave-2
	node->payloadCtrl = nullptr;
}

// §7(62844-62871,LAB_006761d1)真身:root payload 对插入 child 树2。
//   键 = {payload raw@+0x60, ctrl@+0x68}(62847-62848);ctrl 非空 →
//   weak++(62849-62853,LOCK *(ctrl+0xc)+=1);FUN_006857f4
//   get_insert_hint(比较读 value.second,命中位非空才插,62856)→
//   operator_new(0x30)(62864)+ 值写 +0x20/+0x28(62865-62866)+
//   _Rb_tree_insert_and_rebalance(62869)+ +0x58++(62870);未插入 →
//   持键释放(62872-62886 weak--/两段释放)。
//   km3 weak 腿:weak++ = std::weak_ptr 弱引用拷贝(同 _Sp_counted_base
//   weak@+0xc 计数,标准库委托);weak-- = 持键 weak_ptr 析构自动 --
//   (两段释放语义:weak→0 → deleter 承载在最后强引用侧)。
static void trieRefChildInsert(TrieNode *root, TrieNode *child)
{
	if (child == root)   // 62846:p_Var41 != p_Var14 门
		return;
	// 62849-62853:ctrl 非空 → weak++(weak_ptr 拷贝 = LOCK *(ctrl+0xc)+=1
	//   标准库委托);键第二位 = weak 载形(树2 weak 载形同构)
	std::pair<void *, std::weak_ptr<void>> key(
	    reinterpret_cast<void *>(root),
	    std::weak_ptr<void>(root->payloadCtrl));
	auto r = child->refTree.insert(key);   // 62854 FUN_006857f4 同形
	if (r.second) {                       // 62856-62857:命中位非空才插
		                                  //   (62864 operator_new(0x30)+
		                                  //   62869 rebalance 由 insert 承载)
		child->refCount += 1;             // 62870:+0x58 侧挂计数++
	} else {
		// 62872-62886:未插入 → 持键释放:weak_ptr 析构(weak--
		//   标准库委托;→ 0 → 两段释放的 delete 侧随最后强引用)
	}
}

// §8(62928-63130,LAB_00676681)真身:root 树2 死引用裁剪。
//   从 begin 起逐项 use-CAS 活体探活(63051-63064,_Sp_counted_base use@+8
//   CAS 环 —— weak_ptr::lock 形):ctrl 空或探活失败 → erase(63075
//   _Rb_tree_rebalance_for_erase)+ 换出节点 ctrl weak--(63078-63091)
//   + operator_delete(0x30)(63092)+ +0x58--(63093);探活成功
//   → 持有并判 63015 退出式:活体 raw(*node+0x20)≠ 当前 child 即停
//   (local_248=p_Var14,63012;km2 §8 裁剪判式定案)。held 持有释放
//   (63096-63120)随循环退出承载。
//   km3 探活落地:语料 CAS 环 = weak_ptr::lock(use@+8);我方
//   weak_ptr.lock() 非空 = 活体(use_count>0 时原子锁定成功 = CAS 同义;
//   中途归零 → lock 返回空 = 探活失败)—— 模拟形态与语料
//   _Sp_counted_base::_M_add_ref_copy 裸 CAS 的差异:标准库原子封装,
//   语义同构;erase 换出节点 weak--(63078-63091)= 被 erase 值析构。
static void triePruneDeadRefs(TrieNode *root, TrieNode *child)
{
	// 63007-63012:遍历对持有(rbtree_refShared begin 持有 62887-62896;
	//   held = {raw, ctrl};持有/释放 63096-63120 = 局部 shared_ptr
	//   构造/析构承载)
	for (auto it = root->refTree.begin(); it != root->refTree.end();) {
		const std::weak_ptr<void> &ctrl = it->second;  // 63020:*(node+0x28)
		// 63051-63064:CAS 环(use@+8 活体探活;中途归零 → 探活失败)
		//   = weak_ptr::lock 标准库委托
		const KeymapCtrlPtr held = ctrl.lock();   // CAS 探活
		if (ctrl.expired() || !held) {            // 63021 空 / 探活失败
			// 换出节点 ctrl weak-- → 0 → _M_release 两段(63078-63091):
			//   erase 弹出的 pair 析构 = weak_ptr 释放(标准库委托)
			it = root->refTree.erase(it);        // 63075 rebalance_for_erase
			root->refCount -= 1;                 // 63093:+0x58--
			continue;
		}
		// 63065-63068:CAS 成功 → 持有 {raw, ctrl}(held);63015 退出式:
		//   活体 raw ≠ 当前 child(local_248 = p_Var14)→ 停(LAB_006755fd)
		if (it->first != reinterpret_cast<void *>(child))
			return;
		++it;   // 63016:_Rb_tree_increment
	}
}

// §6(62662-62843)真身:子表组快照换入(km2 §6 定案:
// `snap = node->group; std::swap(...)` 形)。
//   snap(use++ 持有的旧根)非空且 ≠ 新根 →
//   ① 62702-62717 树1 极值下行克隆(FUN_00686134 掉参)+ 62718-62719
//      FUN_00683ad6 整树换空/FUN_0067faa0 释放换出 —— cited — wave-2
//      (km2:掉参未逐句核,该腿保持注记);
//   ② 62720-62779 snap 组拷贝:3 槽 ref++(62720-62737,ctrl cited)+
//      children COW 深拷(62738-62777,rep[-8]++/clone —— Qt COW 承载)+
//      +0xa8/+0xb0 裸拷(62778-62779);
//   ③ 62781-62797 FUN_00683ad6(p_Var41,&local_1c8)+ 八槽逐字段交换
//      = 整组 std::swap;
//   ④ 62795-62836 换出组释放:children ref--(62807-62812 FUN_00673ecc
//      wstring rep--;Qt COW 由临时析构承载)+ 缓冲 operator_delete
//      (62813-62815)+ 三槽释放(+0x88/+0x80 use@+8 vptr+8 dispose
//      62816-62833、+0x78 qslotobject_release_destroy2 62834-62836,
//      ctrl cited)+ 62837-62839 refcounted_vt_destroy(local_160);
//   ⑤ 62840-62841 FUN_006809c0/FUN_0067faa0 旧树收尾(批 72 测绘,cited)。
static void trieGroupSwapIn(TrieNode *root, TrieNode *snap)
{
	// ① 树1 克隆/交换/回收(62702-62719)—— cited — wave-2
	//   (FUN_00686134 掉参腿,km2 §6 极值下行保持注记)
	// ② 组快照拷贝(62720-62779)
	//    3 槽 ref++(62720-62737):slotA/slotB use@+8、pred ref@+4
	//    —— 语料裸计数;我方组域槽仍为裸指针(谓词/槽身份未解,cited
	//    — wave-2 不伪造),children COW 由 QVector 拷贝承载。
	KeymapChildGroup snapGroup = snap->group;
	// ③ 整组交换(62781-62797:八槽逐字段交换 = 组结构 swap)
	std::swap(root->group, snapGroup);
	// ④ 换出组(现居 snapGroup)释放(62795-62836):
	//    children 元素 wstring rep--/clone 回收 —— Qt QVector 析构承载;
	//    缓冲 operator_delete(62813-62815)随容器析构;
	//    三槽释放 ctrl cited — wave-2(62816-62836)
	snapGroup = KeymapChildGroup{};   // 旧组析构承载
	// ⑤ 旧树收尾(62840-62841)—— cited — wave-2
}

// §9-10(63131-63379)真身:记录宿主 + 记录向量扩容。
//   宿主空 → operator_new(0x38)(63148)+ 自指链头(63159-63160)+
//   strong++(63161-63163);容量:需求 n = [+0xa8] + [+0xb0] + 1
//   (63245);当前向量(宿主内联缓存@+8..+0x20)容不下 →
//   首配 max(n,0x100)(63257-63259)/增长 ×1.5(63296-63297,double 乘
//   + 9.22e18 溢出钳 63298-63303 —— qAllocMore 签名,非 std::vector ×2)
//   → 新 0x28 节点 + 新缓冲(operator_new(n*0x28))+ 逐条初始化
//   {owner,owner,0,0,owner,0}(63267-63275)+ 双向链接(63330-63335:
//   node[3]=旧链头;旧+0x18=新)+ 旧链换出挂历史(63219-63242)。
//   写入条 = payload+0xb0(63381:begin + [+0xb0]*5)。
static KeymapMatchRecord *recordSinkAcquire(KeymapRecordSink &sink,
                                            quint64 xA8, quint64 xB0,
                                            const wchar_t *owner)
{
	const quint64 need = xB0 + 1 + xA8;   // 63245:lVar43 + 1 + plVar27[0x15]
	// 63254:当前向量容量门(lVar28*0xcccccccd 魔数 = (bytes/8)/5 → 0x28/条)
	if (sink.cap < need) {
		quint64 newCap;
		if (sink.curNode == nullptr) {   // 63256:无历史节点(首次)
			newCap = 0x100;              // 63257
			if (0xff < need)
				newCap = need;           // 63258-63259
		} else {
			// 63296-63297:×1.5(double 乘)
			double grown = static_cast<double>(sink.cap) * 1.5;
			if (9.223372036854776e+18 <= grown)   // 63298:溢出钳
				newCap = static_cast<quint64>(grown - 9.223372036854776e+18)
				         ^ 0x8000000000000000ULL;   // 63299(语料位形)
			else
				newCap = static_cast<quint64>(grown);   // 63302
			if (newCap < need)   // 63304
				newCap = need;
		}
		// 63308:新 0x28 节点 {begin,end,cap,next,prev}(63195-63204 析构二链:
		//   0x28 节点链 delete 走查 + 另一链 delete(·,0xe0)尺寸矛盾未解)
		struct HistNode {
			KeymapMatchRecord *begin;
			KeymapMatchRecord *end;
			KeymapMatchRecord *cap;
			HistNode *next;
			HistNode *prev;
		};
		HistNode *node = new HistNode;   // 63262 operator_new(0x28)承载
		// 63312:operator_new(newCap * 0x28)新缓冲 + 63313-63323 逐条初始化
		KeymapMatchRecord *buf = new KeymapMatchRecord[newCap];
		for (quint64 i = 0; i < newCap; ++i) {
			buf[i].rep = owner;       // 63316
			buf[i].tail = owner;      // 63317
			buf[i].flag = false;      // 63318
			buf[i].pad = 0;           // 63319
			buf[i].rep2 = owner;      // 63320
			buf[i].flag2 = false;     // 63321
		}
		node->begin = buf;                          // 63326
		node->end = buf + need;                     // 63327:puVar34+uVar39*5
		node->cap = buf + newCap;                   // 63329:puVar46
		node->prev = static_cast<HistNode *>(sink.curNode);   // 63330:node[3]=旧
		node->next = nullptr;                       // 63331:uVar29(旧+0x20 形)
		if (sink.curNode != nullptr)
			static_cast<HistNode *>(sink.curNode)->next = node;   // 63332-63335
		sink.curNode = node;                        // 63283:宿主+8 换节点
		sink.begin = buf;                           // 63284:+0x10
		sink.end = buf + need;                      // 63285:+0x18
		sink.cap = newCap;                          // 63286:+0x20
		// 63219-63242 旧内联缓冲链挂历史(宿主身份未解,消费腿 cited;
		//   旧缓冲由旧 0x28 节点链持有 —— 63195-63204 析构走查随宿主)
	}
	// 63381:写入条 = begin + [+0xb0]*5(写入下标由 §11 消费,cited)
	return sink.begin != nullptr ? sink.begin + xB0 : nullptr;
}

// km3 §13 count 门真身(63557-63590,LAB_00675e70 段):wcstol
// tokens[0] = std::stoi 全语义语料转写 —— errno 保存/清零(63560-
// 63562);endptr==起点 → __throw_invalid_argument("stoi")(63567-
// 63569 LAB_006776f7);errno==0x22(ERANGE)或 (u64)(count+
// 0x80000000)>0xffffffff → __throw_out_of_range("stoi")(63572-
// 63575);errno==0 → 恢复原值(63577-63579)。默认 count=1(63583)。
// 调用腿(§13 分发体内,count 消费 0067752a/006776f7)随 §11-13 落地批。
static int keymapEntryCountFromToken(const wchar_t *rep)
{
	const int saved = errno;   // 63560-63561:iVar23 = *piVar35
	errno = 0;                 // 63561-63562:*piVar35 = 0
	const wchar_t *end = nullptr;
	const long v = std::wcstol(rep, const_cast<wchar_t **>(&end), 10);   // 63563
	if (rep == end)
		throw std::invalid_argument("stoi");   // 63566-63569
	if (errno == 0x22 /*ERANGE*/ ||
	    static_cast<unsigned long long>(v + 0x80000000L) > 0xffffffffULL)
		throw std::out_of_range("stoi");   // 63572-63575
	if (errno == 0)
		errno = saved;   // 63577-63579(errno==0 恢复)
	return static_cast<int>(v);   // 63580 iVar22
}

// ── 走查体辅助真身(§11-§15,km3 批)────────────────────────

// FUN_00683c80(554B,decomp-part-0021.c 6747-6818)语料转写:
// vector<pair<wstring,X>> 赋值克隆 —— 目标容量 < 源(6772)→ 新缓冲
// operator_new(uVar2)(6788)+ FUN_00683bd0 逐元素 wstring 拷贝(6791);
// 旧元素 wstring rep--/释放(6792-6802 FUN_00673ecc,非共享串判断
// `!= &DAT_011c5118`);复用段逐元素 wstring::assign + X 拷贝
// (6805-6814)。语料元素 wstring = COW rep++;我方 children =
// QVector<QPair<QString,void*>>,QVector 拷贝 = COW ref++(同契约承载,
// 批 75 注记;元素级 wstring 拷贝 = 隐式共享同构)。
static QVector<QPair<QString, void *>> trieChildrenClone(
    const QVector<QPair<QString, void *>> &src)
{
	return src;   // 6772-6818(COW 同契约;元素 {rep,X} 逐项拷贝语义)
}

// §11 本地匹配树节点 —— FUN_0067e4c2 param_1 布局转写(0021.c 1035-
// 1064;matchTrie local_108 栈宿主,+0x00..+0x18 由 62543-62549 初始化):
//   +0x18 已置 byte(62543 local_238 形)/ +0x20 token rep / +0x28 已置
//   / +0x30 rep2 / +0x38 值 / +0x40 已置 / +0x48 已置 / +0x50 值2
//   / +0x58 tail / +0x60 已置 / +0x68 子链哨兵(空 = 自指,62544
//   local_a0 形)/ +0x70 子链头。
//   查找对 = {+0x00 容量,+0x08 向量基址}(FUN_00673dec 129B,0020.c
//   61341-61351 读体:越界 → 静态空节点 DAT_011c19d0(三连 0 形);
//   否则 end + idx*0x28)—— 本批 vectors 承载按值索引,不伪造 0x28
//   布局;查表基址/容量由挂链腿(cited)维护。
struct LocalMatchNode {
	quint64 cap = 0;                       // +0x00(FUN_00673dec param_1)
	QVector<LocalMatchNode> vec;           // +0x08(FUN_00673dec param_2)
	bool touched1 = false;                 // +0x18
	const void *rep = nullptr;             // +0x20
	bool touched2 = false;                 // +0x28
	const void *rep2 = nullptr;            // +0x30
	const void *value1 = nullptr;          // +0x38
	bool touched3 = false;                 // +0x40
	bool touched4 = false;                 // +0x48
	const void *value2 = nullptr;          // +0x50
	const void *tail = nullptr;            // +0x58
	bool touched5 = false;                 // +0x60
	LocalMatchNode *childSent = nullptr;   // +0x68(空 = 自指,62544)
	LocalMatchNode *childHead = nullptr;   // +0x70
};

// FUN_00673dec(129B,0020.c 61341-61351)语料转写:idx 越界(容量门
// 61345 `*param_1 <= param_3`)→ 静态空节点(DAT_011c19c0 三连守卫
// 61343-61350 = DAT_011c19d0/d8/e0 零初始化);否则 end + idx*0x28。
// 我方 vectors 按 [] 越界抛/UB,故越界臂落 nullptr 承载静态空节点
// (消费侧判空同形 —— 静态零节点消费 = 空值,同契约)。
static LocalMatchNode *localMatchNodeAt(LocalMatchNode &host, quint64 idx)
{
	if (host.cap <= idx)   // 61345
		return nullptr;    // 61346-61351(静态零节点空值承载)
	return &host.vec[(int)idx];   // 61352:end + idx*0x28
}

// FUN_0067e4c2(215B,0021.c 1035-1064)语料转写:本地匹配树写体。
//   +0x20 = token rep(1041);+0x18 已置(1042-1043);FUN_00673dec
//   查找 ×2(1047-1049)→ 值;+0x30 = rep(1050)/ +0x38 = 查得值
//   (1051)/ +0x40 = (查得 != rep)(1052);+0x28 已置(1053-1054);
//   查得+8(1055-1056)→ +0x50 = 第二查得+8(1057-1058)/ +0x58 =
//   tail(1059)/ +0x60 = (第二查得+8 != tail)(1060-1061);+0x48 已置
//   (1062-1063);子链递归传播(1064-1066:+0x70 头走查,哨兵 +0x68 止,
//   逐子 +0x10 偏移递归同参)。
static void trieMatchInsert(LocalMatchNode &node, const void *rep,
                            const void *tail)
{
	node.rep = rep;                                  // 1041
	if (!node.touched1)                              // 1042
		node.touched1 = true;                        // 1043
	LocalMatchNode *hit1 = localMatchNodeAt(node, 0);   // 1047 FUN_00673dec
	LocalMatchNode *hit2 = localMatchNodeAt(node, 0);   // 1048-1049
	node.rep2 = rep;                                 // 1050
	node.value1 = hit1 != nullptr ? &hit1->cap : nullptr;   // 1051(*plVar3)
	node.touched3 = hit1 != rep;                     // 1052
	if (!node.touched2)                              // 1053
		node.touched2 = true;                        // 1054
	node.value2 = hit2 != nullptr ? &hit2->cap : nullptr;   // 1055-1057(+8)
	node.tail = tail;                                // 1058-1059
	node.touched5 = (node.value2 != tail);           // 1060-1061
	if (!node.touched4)                              // 1062
		node.touched4 = true;                        // 1063
	// 1064-1066:子链递归(语料 lVar6+0x10 = 子节点宿主 +0x10;我方
	//   子节点 = vectors 元素整体 —— 挂链腿 cited,子链恒空 → 零迭代;
	//   哨兵判 = childHead == nullptr 空,语料 +0x68 自指同义)
	for (LocalMatchNode *c = node.childHead;
	     c != nullptr; c = c->childSent)
		trieMatchInsert(*c, rep, tail);
}

// FUN_0067e2c0(210B,0021.c 889-926)语料转写:本地匹配树回收。
//   +0xb8/+0xc0 children 向量(890-904:非共享串 rep-- + operator_delete)
//   → FUN_0067d840(+0x88,*(+0x98))(905,容器卸挂)→ +0x80 ctrl
//   vptr+8 dispose(906-913)→ +0x78 非空 → FUN_0067e1ed(914-915)
//   → +0x68/+0x70 子链走查(916-927:逐子摘链 → 子 +0x10 递归回收 →
//   operator_delete(0xe0) 子块)。
//   我方本地树 = 栈宿主 + vectors(挂链腿 cited — wave-2,宿主 +0x78/
//   +0x80/+0x88/+0xb8 域未建):容器/vectors 析构 = 栈展开承载,
//   子链恒空 → 走查零次;本函数落真身形(子链臂按语料保留)。
static void trieLocalTreeFree(LocalMatchNode &node)
{
	// 890-904:children 向量释放 —— vectors 析构承载(栈展开)
	// 905:FUN_0067d840 容器卸挂 —— 同上
	// 906-913/914-915:ctrl/FUN_0067e1ed —— 宿主域 cited — wave-2
	// 916-927:子链走查递归(挂链恒空;臂形按语料保留)
	node.childHead = node.childSent;   // 917-919:摘链尾态(哨兵对齐)
}

// FUN_00767d08(38B,0023.c 34430-34437)语料转写:QJSValue result
// 对象门 —— 引擎 *(host+0x48) 空 → QJSValue(undefined)(34436);
// 非空 → FUN_0064b0be = JsEngine::newObject 委托(34432,批 68 面)。
static QJSValue jsNewObjectGate(JsEngine *engine)
{
	if (engine == nullptr)
		return QJSValue(QJSValue::UndefinedValue);   // 34436
	return engine->newObject();                      // 34432 FUN_0064b0be
}

// §13 取值腿(63520-63524,km3):FUN_00673dec(&local_100,&local_f8,
// child.second)链查找 → 空 → DAT_011c5118 空串 / 非空 → FUN_0067fa14
// (129B,0021.c 2162-2190)取值(wstring{begin,end} 拷贝,空区间 →
// 空 wstring)→ fromUcs4 → QString(我方 QString 直载同构)。
// 查找键 = child.second(挂链域未解 —— cited — wave-2:查找宿主
// local_100/local_f8 挂链态未建,恒空臂 = 空串承载)。
static QString trieMatchNodeValue(const LocalMatchNode &,
                                  void *key)
{
	Q_UNUSED(key)   // 挂链查找臂 cited — wave-2 → 恒空串(空值同形)
	return QString();   // 63522:DAT_011c5118 空串承载
}

// §12 JS 引擎门三件(km3:引擎 face = FUN_00674442(mainPane cast
// 011a6c00)+0x48 槽;mainPane 面 cited — wave-2 → 我方宿主恒空 →
// 走语料空臂,勿造宿主):
// FUN_00674442(20B,0020.c 61786)同形 cast 转写 —— 语料返回 cast 面;
// 我方 MatchOut.ctxWhen(ctxDispatch)无 +0x48 引擎槽 → nullptr。
static JsEngine *keymapEngineCast(QObject *host)
{
	Q_UNUSED(host)   // 00674442 cast 面 cited — wave-2(mainPane 未转写)
	return nullptr;
}

// FUN_00767a70(38B,0023.c 34205-34216)语料转写:引擎 *(host+0x48)
// 空 → QJSValue(undefined)(34214);非空 → FUN_0064af3c =
// JsEngine::evaluateStrict 委托(34211,批 68 重做面)。
static QJSValue jsEvaluateGate(JsEngine *engine, const QString &code)
{
	if (engine == nullptr)
		return QJSValue(QJSValue::UndefinedValue);   // 34214
	return engine->evaluateStrict(code);             // 34211 FUN_0064af3c
}

// FUN_0076745c(104B,0023.c 33962-33978)语料转写:引擎 *(host+0x48)
// 空 → QJSValue(true)(33976);非空 → callable 拷贝(33970)→
// FUN_0064ab5e(76B,0020.c 29907-29919)= callWithInstance(undefined
// instance 承载,29915-29918;批 68 JsEngine::call 同体旧形)。
static QJSValue jsCallGate(JsEngine *engine, const QJSValue &callable,
                           const QJSValueList &args)
{
	if (engine == nullptr)
		return QJSValue(true);   // 33976
	// FUN_0064ab5e:QJSValue(undefined) instance + callWithInstance(args)
	// (Qt5 callWithInstance 非 const,拷贝承载)
	QJSValue fn = callable;   // 33970:QJSValue::QJSValue(local_30, param_3)
	return fn.callWithInstance(QJSValue(QJSValue::UndefinedValue),
	                           args);   // 29915-29918
}

// FUN_0067cd71(107B,0020.c 69768-69781)读体转写:DAT_011c18dc 惰性
// 注册 —— 非零即返(69772);零 → normalizedType(69774)+ registerNormalizedType
// (69776,dtor = QJSValue 析构,ctor = FUN_0066b36f 34B,尺寸 8,旗标
// 0x103)→ qt_byte_array_unref(69778)→ DAT_011c18dc = id(69780)。
// 我方 QJSValue 已有 Qt 元系统注册(Q_DECLARE_METATYPE(QJSValue),
// qMetaTypeId 惰性归一注册 = 同一注册契约承载,dtor/ctor/尺寸由 Qt
// 头生成面提供 —— 非自研,标准委托)。
static int jsMetatypeRegister()
{
	static int s_id = 0;   // DAT_011c18dc
	if (s_id != 0)
		return s_id;   // 69772
	s_id = qMetaTypeId<QJSValue>();   // 69774-69780(注册契约同构)
	return s_id;
}

// FUN_0067e011(260B,0021.c 763-804)读体转写:when QVariant 缓存取回。
//   DAT_011c18dc 零 → 注册(765-770,同 FUN_0067cd71 体)+ userType 比较
//   (771-773);命中(缓存已存 QJSValue)→ constData 直拷 QJSValue
//   (777-780);未命中 → QJSValue(undefined)(787)+ QVariant::convert
//   (param_2 → metaType id,789)失败 → 保持 undefined(790-792)/
//   成功 → 转换产物移出(793-796)。
static QJSValue jsValueCacheFetch(const QVariant &cached)
{
	const int id = jsMetatypeRegister();   // 765-770
	if (cached.userType() == id) {         // 771-773/776-779
		return *static_cast<const QJSValue *>(cached.constData());   // 778-779
	}
	QJSValue out(QJSValue::UndefinedValue);   // 787
	QVariant v = cached;                      // 789 convert 源
	if (v.convert(id))                        // 789
		out = v.value<QJSValue>();            // 793-796(转换产物移出)
	return out;                               // 790-798
}

// FUN_0067df30(125B,0021.c 716-747)语料转写:记录弦清单 append。
//   槽容 < 2 → QListData::append(6722)否则 FUN_0067dc90(detach_grow
//   0x7fffffff,1 = 尾部扩一,6731)→ 槽项 operator_new(0x10)(6726/
//   6744)→ {raw@0, ctrl@8} 拷入(6746-6748)+ ctrl 非空 LOCK use++
//   (6749-6753,+8 计数 = shared_ptr 拷贝形)。
//   km3 §15:我方 ctrl = shared_ptr 承载(批 79)→ 槽项 = KeymapEntry
//   拷贝,ctrl use++ = entry.trieRoot shared_ptr 强引用拷贝(标准库
//   _M_add_ref_copy 同构);QList 尾插 = QList::append 承载。
static void triePrefixChordAppend(QList<KeymapEntry> &chords,
                                  const KeymapEntry &item)
{
	chords.append(item);   // 6717-6747(raw+ctrl 拷入 + ctrl use++)
}

// FUN_0067500e(9978B,decomp-part-0020.c 62391-63957)15 段,P3 勘察
// §3 地图逐段转写。km3 裁决:走查体执行前提 = Trie 根(entry+0x08 槽,
// 语料 *(lVar7+8)),该槽由装载翼 xpressive 编译腿(00678295-006783fe →
// FUN_00687320 换入;km3 勘正:onig → boost::xpressive 编译腿,boost
// 边界 EXT-BOUNDARY)建立 —— 该腿在案 cited — wave-2,根槽恒空 →
// §4 首门(00675296:根空或 *(根+0x78)==0 即出)短路全部走查体,
// 与批 72 骨架行为一致(匹配恒未竟,不产生伪结果)。ctrl = shared_ptr
// 承载(km3:§5/§7/§8 计数面闭环,见上方真身);因此本批落点 =
// ①谓词/分发等跨段辅助真身(0075debe/0066a116/编解码,上方);
// ②§5-§15 真身化(批 75 + km3 批:§11 谓词腿/§12 when 腿/§13 分发/
//   §14 哨兵/§15 收尾,辅助真身上方;未解面 cited 注记在段内);
// ③逐句行号锚(装载腿落地后已可运行,谓词/挂链两 cited 腿接入后闭环):
//   §1(62391-62616)局部初始化:out 指针数组形(feedKey 已填)。
//   §2(62617-62635)外层槽循环(LAB_00675222):QList detach
//       (FUN_0067e3dc)→ 槽项{shared_ptr@0, ctrl@8} → sp ref++
//       (0067523b);游标步进 +2 = 16B 元素步进(006751e5)。
//   §3(62636)模式门:modesMask(+0x24)& flags,不满足 → 下一项。
//   §4(62638-62662)token 循环(LAB_00675296/755b6/755e2):根空或
//       根谓词槽(+0x78)空即出(00675296);末 token 出
//       (LAB_006755b6:local_4a8+1==lVar26);tokenIdx==1 &&
//       flags∈{2,8} 早退(006755e2);token0==token1 wmemcmp 短路
//       (code_r0x00675e23,空串亦短路)。
//   §5  节点获取/复位:FUN_00681a40(392B,0021.c 4594-4647)—— 根空
//       或 *(根+0x70)==1 直返现有;否则新建 0xb8 节点(00681b0a-
//       00681b7a 布局:+0x18/+0x20/+0x28/+0x48/+0x50 Rb 头自指、
//       +0x70 use、+0x78..+0xb0 槽)挂 shared ctrl(PTR_FUN_011895b0,
//       km3:shared_ptr 承载即闭环,块体 boost 边界不伪造)换入;
//       use 减到 0 → FUN_0067fae4(82B)→ FUN_0067faa0(67B)
//       递归子树回收 + 字段复位(+0x10/18/20/28/60/68)。
//   §5(62636-62662)节点获取/复位:trieNodeGetOrCreate(FUN_00681a40
//       真身,上方)/ trieNodeReset(LAB_006759bf+FUN_0067fae4 真身)。
//   §6/§7/§8(62662-63130)真身化(批 75 + km3 ctrl 闭环):§6 = trieGroupSwapIn
//       (组快照整组 std::swap 换入;树1 克隆腿 cited);§7 = trieRefChildInsert
//       (std::set<weak 载形,CtrlLess> 插入 = weak++ + +0x58++);§8 =
//       triePruneDeadRefs(weak_ptr::lock 活体探活裁剪 —— km3 shared_ptr
//       侧闭环,语料 _Sp_counted_base CAS 的标准库同构);换出旧根收尾
//       trieNodeReset(+0x68 ctrl 强引用释放 = _M_release 委托)。
//   §9(63131-63281)记录向量:recordSinkAcquire 真身(local_90 0x38 容器
//       承载 = KeymapRecordSink;容量 = payload+0xa8 预算 + [+0xb0] + 1;
//       记录 0x28B/条 = KeymapMatchRecord {rep,tail,flag,pad,rep2,flag2};
//       首配下限 0x100(00676e4b));宿主历史链消费腿 cited。
//   §10(63282-63342)×1.5 扩容(63296-63303 double 乘 + 9.22e18 溢出钳)
//       = recordSinkAcquire 真身内;旧链卸挂(63330-63335)真身内。
//   §11(63423-63443)谓词腿 —— 本批真身:FUN_00683c80 children 克隆
//       (trieChildrenClone)+ FUN_0067e4c2 本地树入树(trieMatchInsert)+
//       FUN_00673dec 查找(localMatchNodeAt);谓词虚调(**(*plVar27)+0x10)
//       类身份未解(QSlotObjectBase 子类,VTABLE-MAP 批)→ cited,叶写
//       门 local_238(63004 挂链态,挂链宿主未解)→ cited。
//   §12(63444-63516)when 腿 —— 本批真身:FUN_00767a70/0076745c 引擎门
//       (jsEvaluateGate/jsCallGate,空臂 = undefined/true)+ FUN_0067e011
//       (jsValueCacheFetch)+ FUN_0067cd71(jsMetatypeRegister);
//       引擎宿主 FUN_00674442 cast 面 cited;bVar17 每槽项一次门。
//   §13(63517-63654)命中分发(LAB_00675e70)—— 本批:FUN_00767d08
//       result 对象(jsNewObjectGate)→ 逐克隆元素 result[tokenRep] =
//       节点值串(fromUcs4+setProperty,63536-63540);count 门真身
//       keymapEntryCountFromToken(63557-63590)接线;FUN_006745b0 清
//       输入缓冲;actionType 三路(synthKeyEvents/keymapActionFire
//       真身上方 + JS callable 腿 = §12 门族);§13 入门 local_100/
//       写入条 flag/DAT_011c19e0(挂链/静态命中块,未解)→ cited。
//   §14(63655 + 63876-63886)LAB_00675d97:result=1;bVar18=true;
//       非末 token 续 → LAB_006755e2;code_r0x00675e23 哨兵:tokens[1]
//       空(_Rep 长域 0)或 wmemcmp(tokens[0],tokens[1]) 相等 → §15,
//       不等 → 回 §4 走查头 —— 真身(wmemcmp = QString==同契约)。
//   §15(63888-63957)收尾(LAB_00675dbd/00675dcb/006751ce/006751e5)
//       —— 本批真身:bVar18 且 result==2 → FUN_0067e2c0 本地树回收
//       (trieLocalTreeFree)+ 返回;bVar18 且 mode!=2 → FUN_0067df30
//       前缀 append(triePrefixChordAppend);!bVar18 且 mode==2 →
//       FUN_0067e3dc detach + 槽项释放 + QListData::erase learn 移除
//       (QList::erase 同构承载);游标推进 = 循环 ++(LAB_006751e5
//       槽项两段释放随 Qt 容器析构)。
// ── §15(63888-63957)收尾(LAB_00675dbd;游离函数承载 = goto 落点
// 跨槽循环作用域,C++ goto 不能跨变量初始化 —— 语料标签流同构转写,
// continue/游标臂由返回值表达:0=走查完下一槽项,1=learn erase 已做)
static int matchTrieFinalize(MatchOut &out, QList<KeymapEntry> &slotList,
                             int si, bool prefixHit, LocalMatchNode &walkTree,
                             int mode)
{
	KeymapEntry &entry = slotList[si];   // 当前槽项(§15 消费形)
	if (prefixHit) {   // LAB_00675dbd 63887:bVar18(前缀命中)
		// LAB_00675dcb 63889
		if (out.result == 2) {
			// 63890-63894:sp release(_M_release)+ FUN_0067e2c0
			// 本地树回收 + return(真身:trieLocalTreeFree)
			trieLocalTreeFree(walkTree);
			return 2;   // 63896 LAB_0067720d:result==2 终态(调用方 return)
		}
		if (mode != 2) {   // 63898
			// 63899-63900:FUN_006741e2(*(param_1[3]))(4B 前缀清单
			// getter = record->m_chords)→ FUN_0067df30 append
			triePrefixChordAppend(out.record->m_chords, entry);
		}
	} else if (mode == 2) {
		// LAB_006751ce(63903-63915,learn 命中移除):FUN_0067e3dc
		// detach(90B,Qt QList detach 同构)→ 当前槽项释放
		// {raw@0, ctrl@8}(63908-63913:_M_release + operator_delete
		// 0x10 —— shared_ptr 析构承载)→ QListData::erase(param_2)
		// (63914)= learn 命中移除槽项;游标回退重对齐算术
		// (63911-63917)由调用方 si-1 承载(erase 后 ++ 对齐)
		slotList.removeAt(si);   // 63914 QListData::erase 同构
		return 1;   // → LAB_006751e5:调用方 si-=1 后下一槽项
	}
	// LAB_006751e5(63916-63918):槽项 sp 两段释放(use→weak→0)
	// + 游标 +2 → LAB_00675222 下一槽项 —— QList<KeymapEntry> 按值
	// 承载的槽项析构 = 循环 ++it(标准委托同构,批 75 注记)
	return 0;
}

int SuperKeymap::matchTrie(MatchOut &out, QList<KeymapEntry> &slotList,
                           const QVector<QString> &tokens, int mode)
{
	// §1(62391-62616)局部初始化:out 指针数组形已由 feedKey 填;
	//    local_408 = 槽游标(列表 detach FUN_0067e3dc 逐项)
	out.result = 0;
	// §2(62617-62635)外层槽循环头(LAB_00675222):QList detach
	//    (FUN_0067e3dc)→ 槽项{shared_ptr@0, ctrl@8} → sp ref++;
	//    语料元素 = 16B pair,游标步进 +2(006751e5)—— 我方按值
	//    QList<KeymapEntry> 同为逐元素 ++。
	for (int si = 0; si < slotList.size(); ++si) {
		KeymapEntry &entry = slotList[si];
		// §3(62636)模式门:modesMask(+0x24)& 旗标;不满足 → 下一槽项
		if ((entry.modesMask & out.flags) == 0)
			continue;
		// 62640:token 向量空门(lVar26 != 0)→ 下一槽项
		if (tokens.isEmpty())
			continue;
		bool whenPassed = false;   // bVar17(§12 每槽项一次门,62643)
		bool prefixHit = false;    // bVar18(§14/§15 前缀旗,62644)
		int tokenIdx = 0;          // local_4a8(62642)
		LocalMatchNode walkTree;   // local_108 栈宿主(§11 本地树)
		// token 循环壳(LAB_00675296 迭代面;continue = 下一 token);
		// 走查体入内层作用域 —— goto 落点(§15)不跨局部初始化
		for (;;) {
			{   // 走查体作用域(goto finalize 从内跳出到域外标签,不跨初始化)
			// §4(62638-62662)token 循环(LAB_00675296):根空或谓词槽
			//    *(根+0x78)==0 → LAB_006755b6(下一 token/出 —— 语料逐
			//    token 判,非槽项短路;km3 §4)。Trie 根 = entry+0x08 槽
			//    (xpressive 编译腿换入 —— boost 边界 cited — wave-2 未建);
			//    装载腿语义:root 恒空 → 每 token 走 LAB_006755b6 → §15
			//    收尾下一槽项,与批 72/79 短路行为一致(结果恒 0,不伪造)。
			if (!entry.trieRoot || entry.trieRoot->group.pred == nullptr) {
				// LAB_006755b6(62645):本地树头复位 + token 推进门
				if (tokenIdx + 1 == tokens.size()) {   // 62646 末 token
					goto finalize;                   // → LAB_00675dbd
				}
				++tokenIdx;                          // 62648 LAB_006755e2
				if (tokenIdx == 1) {                 // 62649
					if (out.flags != 2 && out.flags != 8) {
						// code_r0x00675e23 哨兵(63876-63886):tokens[1]
						// _Rep 长域判空 + wmemcmp(tokens[0],tokens[1])
						// —— QString == = 长判 + 内容比(同契约)
						if (tokens[1].isEmpty() || tokens[0] == tokens[1]) {
							goto finalize;   // → LAB_00675dbd
						}
						continue;            // → LAB_00675296 续走查
					}
					goto finalize;   // flags∈{2,8} → LAB_00675dbd
				}
				continue;   // → LAB_00675296
			}
			// §5(62659)FUN_00681a40(&local_3d8,lVar7+8):获取/换入走查
			//    节点(snap = 旧根 use++ 持有,或空 = 复用腿 §6-§8 跳过)
			TrieNode *snap = trieNodeGetOrCreate(&entry.trieRoot);
			TrieNode *root = entry.trieRoot.get();   // 62661:p_Var41 = 换入后根
			if (snap != nullptr && snap != root) {
				// §6(62662-62843)组快照整组 std::swap 换入(树1 克隆腿 cited)
				trieGroupSwapIn(root, snap);
				// §7(62842-62871)树1 遍历:条目值 raw@+0x20 = 旧根子节点,
				//    逐个把本根 payload 对插入其树2(键树装载 cited → 空树
				//    循环零次,判式按语料保留)
				for (const auto &kv : root->keyTree) {
					auto *child = static_cast<TrieNode *>(kv.first);   // 62845
					if (child == nullptr)
						continue;
					trieRefChildInsert(root, child);   // §7 LAB_006761d1
					triePruneDeadRefs(root, child);    // §8 LAB_00676681
				}
				// 收尾(63876-63879 → 63125-63129):FUN_00686cb0 交叉审计
				//    (cited — wave-2)→ 旧根复位(LAB_006759bf)
				trieNodeReset(snap);
			}
			// §9-10(63131-63379)记录向量真身:宿主 0x38(local_90 承载)+
			//    容量门/×1.5 扩容 + 写入条 = begin + [+0xb0](63381);
			//    owner = 当前 token rep(63268 local_250 = p_Var8);语料
			//    rep = wstring 指针,我方 QString 承载(QChar 数据指针
			//    同域;wchar_t* 形 = KeymapMatchRecord 语料域)。§11 叶写/
			//    谓词虚调消费此向量;§13 以克隆 rep 消费(63536-63540)。
			KeymapRecordSink sink;   // 63146-63211
			out.sink = &sink;        // §13 消费面挂出(cited — wave-2)
			QString token = tokens[tokenIdx];              // 62569 p_Var8
			// 62570 p_Var3 = token 尾指针(tokTail;谓词叶写臂 cited 消费,
			//   悬伏注记形 —— 变量省略,QChar* 同域)
			const wchar_t *owner = reinterpret_cast<const wchar_t *>(
			    static_cast<const void *>(token.constData()));
			(void)recordSinkAcquire(sink, root->group.xA8, root->group.xB0, owner);
			// ── §11(63423-63443)谓词腿 ─────────────────────────
			// 63423:FUN_00683c80(&local_50, 节点+0x12×8)children 克隆
			const QVector<QPair<QString, void *>> cloned =
			    trieChildrenClone(root->group.children);   // 63423
			// 63425-63441:local_98 记录挂链 splice(FUN_0067e45e 100B 消费)
			//    —— 挂链宿主 local_210/local_98 身份未解 —— cited — wave-2
			// 63426:写入条[3] = token rep(rep2 先行写;§13 前)
			// KeymapMatchRecord 写入条 = begin + [+0xb0]*5(recordSinkAcquire
			// 返回面,悬伏指针形态;挂链 cited → 直写臂保持注记形):
			if (sink.begin != nullptr) {
				KeymapMatchRecord &rec = sink.begin[root->group.xB0];   // 63383
				rec.rep2 = owner;                       // 63426 local_260[3]=p_Var8
			}
			// 63427-63428:plVar27 = *(根+0x78) → 虚调 vtable+0x10(plVar27,
			// &local_268)返 bool —— 谓词对象 = QSlotObjectBase 子类,vtable
			// 无名(类身份未解,VTABLE-MAP 批)—— cited — wave-2:不伪造
			// 调用;语料 false → 叶写(63430 门 local_238 = 挂链态,亦 cited)
			// / true → FUN_0067e4c2 入本地树(真身)。谓词批接入前两臂按
			// 63430 门未解态短路(不入树不叶写,0x238 臂保持注记)。
			// bool matched = 谓词虚调;false → 叶写 rec.rep = rec.rep2;
			//   rec.tail = tokTail;rec.flag = false(63439-63443);
			// true → trieMatchInsert(walkTree, owner, tokTail);   // 63443
			// ── §12(63444-63516)when 条件腿(bVar17 每槽项一次门)──
			if (!whenPassed) {                              // 63444
				if ((entry.when.userType() & 0x3fffffff) != 0) {   // 63445
					bool consumed = false;                  // cVar20(63453/63483)
					if (entry.when.canConvert(QMetaType::QString)) {   // 63446
						const QString expr = entry.when.toString().trimmed();
						if (!expr.isEmpty()) {              // 63450 len 门
							JsEngine *eng = keymapEngineCast(out.ctxWhen);
							QJSValue v = jsEvaluateGate(eng, expr);   // 63453 FUN_00767a70
							if (!v.isCallable()) {        // 63456
								consumed = v.isBool() ? v.toBool()
								                      : false;   // 63457-63462
							} else {
								jsMetatypeRegister();     // 63463 FUN_0067cd71
								// 63464-63474:QVariant(metaType, QJSValue)
								// 缓存回写 entry.when(+0x30/+0x38;
								//   语料 QVariant(int type, const void*)
								//   = Qt5 fromValue 同构造面)
								entry.when =
								    QVariant::fromValue<QJSValue>(v);
							}
						}
					}
					// LAB_00676fcd(63477):注册 → canConvert → 取回 → 求值
					jsMetatypeRegister();                   // 63478
					if (entry.when.canConvert(jsMetatypeRegister())) {   // 63480
						QJSValue cached = jsValueCacheFetch(entry.when);   // 63481 FUN_0067e011
						JsEngine *eng = keymapEngineCast(out.ctxWhen);
						QJSValue r = jsCallGate(eng, cached, QJSValueList());
						if (r.isBool() && r.toBool())       // 63488-63489
							whenPassed = true;              // → LAB_00676c5f
					}
					if (!whenPassed && !consumed) {         // 63495 cVar20==0
						// → LAB_00675dbd(§15 收尾;bVar18 false)
						goto finalize;                      // 63496
					}
				}
				whenPassed = true;                          // LAB_00676c5f 63499
			}
			// ── §13(63517-63654)命中分发(LAB_00675e70)──────────
			// 入门(63503-63506):本地树头 local_100 空 && 静态块 DAT_011c19e0
			// 零 → 前缀路;写入条 flag(63509 local_f8[2])非零或树头非空
			// → 命中路 —— local_100/挂链/DAT_011c19c0 静态块身份未解
			// —— cited — wave-2(树头空 = 谓词臂未接入态)。
			// (语料:local_100==0 且 e0==0 → LAB_00675d97 前缀;否则命中路)
			const bool hitPath =
			    walkTree.touched1;   // local_100 非空承载(树写体已接,cited 门)
			if (hitPath) {
				// 63508:FUN_00767d08(38B,0023.c 34430)result 对象门
				JsEngine *eng = keymapEngineCast(out.ctxDispatch);
				QJSValue result = jsNewObjectGate(eng);   // FUN_00767d08
				// 63511-63531:逐克隆元素 → result[tokenRep] = 节点值串
				for (const auto &child : cloned) {
					// 63518-63524:FUN_00673dec(&local_100,&local_f8,
					//   child.second)链查找 → 空 → DAT_011c5118 空串 /
					//   非空 → FUN_0067fa14 取值(129B wstring 拷贝面)
					const QString valueStr = trieMatchNodeValue(
					    walkTree, child.second);   // 63520-63524
					// 63525-63527:fromUcs4(值)→ QJSValue(我方 QString 直载)
					QJSValue jsValue(valueStr);
					// 63528-63531:fromUcs4(child.rep)→ setProperty(result,
					//   键, 值)= result[tokenRep] = 节点值串(Ghidra
					//   setProperty 丢值参,键值序以语料二 fromUcs4 为准,km3)
					result.setProperty(child.first, jsValue);
				}
				// ── count 门(63557-63590)────────────────────────
				int count = 1;   // 63583 默认
				if (tokenIdx == 1 && entry.repeatable && (out.flags & 0x14) != 0) {
					// 63558:p_Var3 = tokens[0] 尾即 wcstol 源;我方
					// QString → std::wstring(wchar 同域)后进真身
					const std::wstring w = tokens[0].toStdWString();
					count = keymapEntryCountFromToken(w.c_str());   // 63559-63581
				}
				// 63592:FUN_006745b0(*(param_1[3]))清输入缓冲(106B 真身
				// 已备:KeymapInputRecord::clearBuffer)
				out.record->clearBuffer();   // 63592
				// ── actionType 三路分发(63594-63652)────────────────
				if (entry.actionType == 1) {   // 63594 ==1:map → 合成键
					QString s = entry.payload.toString();   // 63595
					if (count > 1) {   // 63599
						s.insert(0, QString::number(count));   // 63600-63605
					}
					synthKeyEvents(s);   // 63607 FUN_0075debe(qApp 宿主形)
				} else {
					for (; count > 0; --count) {   // 63609 count 次循环
						if (entry.actionType == 0) {   // 63611 ==0:action fire
							JsEngine *tgt = keymapEngineCast(out.ctxDispatch);
							QByteArray bytes = entry.payload.toByteArray();
							QVariant fireOut;   // 63616 local_388(弃)
							keymapActionFire(fireOut, tgt, bytes, result);   // 63617 FUN_007682c0
						} else {                       // 63622 ==2:JS callable
							if ((entry.payload.userType() & 0x3fffffff) != 0) {
								if (entry.payload.canConvert(QMetaType::QString)) {
									JsEngine *eng2 = keymapEngineCast(out.ctxWhen);
									QJSValue c = jsEvaluateGate(
									    eng2, entry.payload.toString());   // 63635 FUN_00767a70
									if (c.isCallable()) {   // 63639
										jsMetatypeRegister();   // 63641 FUN_0067cd71
										// 63642-63652:缓存回写 entry.payload
										// (+0x20/+0x28,QVariant(metaType,
										//   QJSValue)= fromValue 同构造面)
										entry.payload =
										    QVariant::fromValue<QJSValue>(c);
									}
								}
								// 63653 前直调段:注册 → canConvert → 取回 →
								// args QList = [result](FUN_005454b0 130B)→
								// FUN_0076745c 直调(结果不消费);每轮循环
								// 重取(语料原样,不优化,km3)
								jsMetatypeRegister();
								if (entry.payload.canConvert(jsMetatypeRegister())) {
									QJSValue cached =
									    jsValueCacheFetch(entry.payload);   // FUN_0067e011
									JsEngine *eng3 = keymapEngineCast(out.ctxDispatch);
									QJSValueList args;
									args.append(result);   // 63640 FUN_005454b0
									jsCallGate(eng3, cached, args);   // 63642 FUN_0076745c
								}
							}
						}
					}
				}
				out.result = 2;   // 63653 写 *(param_1[6])
				goto finalize;    // → LAB_00675dcb(§15 result==2 臂)
			}
			// ── §14(63655)LAB_00675d97:未竟前缀 ──────────────────
			out.result = 1;   // 63656
			prefixHit = true;   // 63656 bVar18 = true
			if (tokenIdx + 1 != tokens.size()) {   // 63657 → LAB_006755e2
				++tokenIdx;
				if (tokenIdx == 1) {
					if (out.flags != 2 && out.flags != 8) {
						// code_r0x00675e23 哨兵(63876-63886):_Rep 长域
						// 判空 + wmemcmp —— 我方 QString == 同契约
						// (长度先判 + 内容比较 = wmemcmp 语义)
						if (tokens[1].isEmpty() || tokens[0] == tokens[1]) {
							goto finalize;   // → LAB_00675dbd
						}
						continue;   // → LAB_00675296(§4 走查头续循环)
					}
					goto finalize;   // flags∈{2,8} → LAB_00675dbd
				}
				continue;   // → LAB_00675296
			}
			goto finalize;   // 末 token → LAB_00675dbd
			}   // 走查体作用域闭合(goto 不跨本域初始化)
			finalize:;   // 域外标签(§4/§12 失败/§13 命中/§14 末 token 落点)
			// ── §15(63888-63957)收尾(LAB_00675dbd)─────────────────
			// 语料标签流(finalize → §15 → 下一槽项)以返回值表达:
			// 0 = 下一槽项(游标 ++),1 = learn erase 已做(si-=1 后下一),
			// 2 = result==2 终态(直接返回)。
			{
				const int fin = matchTrieFinalize(out, slotList, si, prefixHit,
				                                  walkTree, mode);
				if (fin == 2)
					return out.result;   // 63896 LAB_0067720d
				if (fin == 1) {
					si -= 1;   // 63911-63917:游标回退重对齐(循环 ++ 对齐)
				}
			}   // fin 作用域闭合(repeat 迭代不跨 const int 初始化)
			continue;   // LAB_006751e5:→ 下一槽项(游标 ++ 由外层 for 承载)
		}   // token 循环壳尾
	}
	return out.result;
}

