#include "SuperKeymap.h"

#include <QByteArray>
#include <QHash>
#include <QKeyEvent>
#include <QApplication>
#include <QCoreApplication>
#include <QFrame>
#include <QKeySequence>
#include <QJSValue>

#include <cstring>

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
//   *out = 0;槽空/槽 use==1 → 复用现有(*out 保持 0,§6-§8 跳过);
//   否则新建 0xb8 节点(布局 4622-4643)+ 0x18 ctrl(PTR_FUN_011895b0,
//   use++ 4649-4651)+ +0x60 self/+0x68 ctrl(4652-4659)换入槽;
//   *out = 旧根(use 已 ++ 持有,4609-4618),槽换新后旧根 FUN_0067fae4
//   释放面由调用方走查收尾承载(§6-§8 后 use-- 复位)。
//   ctrl 块(PTR_FUN_011895b0/_Sp_counted_base)属语料运行时 —— cited —
//   wave-2:ctrl 不落地,+0x68 置空(use/use-- 原子计数保留语义承载)。
static TrieNode *trieNodeGetOrCreate(TrieNode **slot)
{
	TrieNode *snap = nullptr;   // *param_1 = 0(4604)
	if (*slot != nullptr) {   // 4605
		if ((*slot)->use == 1)   // 4606:use==1 → 复用直返
			return snap;
		// 4609-4614:LOCK;旧根 use++(持有)
		(*slot)->use += 1;
		snap = *slot;   // 4615-4616:*param_1 = 旧根
	}
	// 4622-4643:0xb8 节点新建(布局逐字段;std 成员 ctor 承载零值)
	TrieNode *node = new TrieNode;
	node->payloadSelf = node;   // 4652:+0x60 = self
	// 4645-4659:0x18 ctrl + +0x68 挂接 —— cited — wave-2(ctrl 块不落地)
	// 4664-4668:*param_2 = 新节点(槽换入)
	*slot = node;
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
	// 62676-62680:+0x68 ctrl 释放(refcounted_vt_destroy)—— cited — wave-2
	node->payloadCtrl = nullptr;
}

// §7(62844-62871,LAB_006761d1)真身:root payload 对插入 child 树2。
//   键 = {payload raw@+0x60, ctrl@+0x68}(62847-62848);ctrl 非空 →
//   weak++(62849-62853,LOCK *(ctrl+0xc)+=1 —— ctrl 块属 shared/JS 面,
//   cited — wave-2);FUN_006857f4 get_insert_hint(比较读 value.second,
//   命中位非空才插,62856)→ operator_new(0x30)(62864)+ 值写 +0x20/+0x28
//   (62865-62866)+ _Rb_tree_insert_and_rebalance(62869)+ +0x58++
//   (62870);未插入 → 持键释放(62872-62886 weak--/两段释放 —— cited)。
static void trieRefChildInsert(TrieNode *root, TrieNode *child)
{
	if (child == root)   // 62846:p_Var41 != p_Var14 门
		return;
	// 62849-62853:ctrl 非空 weak++ —— ctrl cited(块不落地,占位注记)
	const auto key = std::make_pair(reinterpret_cast<void *>(root),
	                                root->payloadCtrl);
	auto r = child->refTree.insert(key);   // 62854 FUN_006857f4 同形
	if (r.second) {                       // 62856-62857:命中位非空才插
		                                  //   (62864 operator_new(0x30)+
		                                  //   62869 rebalance 由 insert 承载)
		child->refCount += 1;             // 62870:+0x58 侧挂计数++
	} else {
		// 62872-62886:未插入 → 持键释放(weak-- → 0 → _M_release
		//   vptr+0x18==FUN_0067a2a0 ? vptr+8 : vptr+0x18)—— cited — wave-2
	}
}

// §8(62928-63130,LAB_00676681)真身:root 树2 死引用裁剪。
//   从 begin 起逐项 use-CAS 活体探活(63051-63064,_Sp_counted_base use@+8
//   CAS 环 —— weak_ptr::lock 形):ctrl 空或探活失败 → erase(63075
//   _Rb_tree_rebalance_for_erase)+ 换出节点 ctrl weak--(63078-63091,
//   cited)+ operator_delete(0x30)(63092)+ +0x58--(63093);探活成功
//   → 持有并判 63015 退出式:活体 raw(*node+0x20)≠ 当前 child 即停
//   (local_248=p_Var14,63012;km2 §8 裁剪判式定案)。held 持有释放
//   (63096-63120)随循环退出承载。ctrl 引用计数操作 cited — wave-2。
static void triePruneDeadRefs(TrieNode *root, TrieNode *child)
{
	// 63007-63012:遍历对持有(rbtree_refShared begin 持有 62887-62896;
	//   held = {raw, ctrl};ctrl 引用计数 cited — wave-2,块不落地 →
	//   持有释放(63096-63120)不落码,判式形状按语料保留)
	for (auto it = root->refTree.begin(); it != root->refTree.end();) {
		void *ctrl = it->second;                 // 63020:*(node+0x28)
		// 63051-63064:CAS 环(use@+8 活体探活;中途归零 → 探活失败)
		//   —— ctrl cited — wave-2:块不落地,探活恒不可行 → 按语料
		//   死路径承载(erase + 计数--)
		bool alive = false;   // CAS 承载(ctrl 块缺失 → 按死裁)
		if (ctrl == nullptr || !alive) {         // 63021 空 / 探活失败
			// 换出节点 ctrl weak-- → 0 → _M_release 两段(63078-63091,
			//   vptr+0x18==FUN_0067a2a0 哨兵 ? vptr+8 : vptr+0x18)
			//   —— ctrl cited — wave-2(块不落地)
			it = root->refTree.erase(it);        // 63075 rebalance_for_erase
			root->refCount -= 1;                 // 63093:+0x58--
			continue;
		}
		// 63065-63068:CAS 成功 → 持有 {raw, ctrl};63015 退出式:
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
	KeymapChildGroup snapGroup = snap->group;   // COW:children ref 承载;
	                                            // 3 槽 ref++ ctrl cited
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

// FUN_0067500e(9978B,decomp-part-0020.c 62391-63957)15 段,P3 勘察
// §3 地图逐段转写。本批裁决:走查体执行前提 = Trie 根(entry+0x08 槽,
// 语料 *(lVar7+8)),该槽由装载翼 onig 编译腿(00678295-006783fe →
// FUN_00687320 换入)建立 —— 该腿在案 cited — wave-2,根槽恒空 →
// §4 首门(00675296:根空或 *(根+0x78)==0 即出)短路全部走查体,
// 与批 72 骨架行为一致(匹配恒未竟,不产生伪结果)。因此本批落点 =
// ①谓词/分发等跨段辅助真身(0075debe/0066a116/编解码,上方);
// ②§5-§10 真身化(批 75,km2 §6-8 定案,辅助真身上方);
// ③其余段逐句注记(行号锚,装载腿落地后按此转写):
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
//       +0x70 use、+0x78..+0xb0 槽)挂 shared ctrl(PTR_FUN_011895b0)
//       换入;use 减到 0 → FUN_0067fae4(82B)→ FUN_0067faa0(67B)
//       递归子树回收 + 字段复位(+0x10/18/20/28/60/68)。
//   §5(62636-62662)节点获取/复位:trieNodeGetOrCreate(FUN_00681a40
//       真身,上方)/ trieNodeReset(LAB_006759bf+FUN_0067fae4 真身)。
//   §6/§7/§8(62662-63130)真身化(批 75,km2 定案):§6 = trieGroupSwapIn
//       (组快照整组 std::swap 换入;树1 克隆腿 cited);§7 = trieRefChildInsert
//       (std::set<pair,CtrlLess> 插入 + +0x58++);§8 = triePruneDeadRefs
//       (use-CAS 活体探活裁剪,ctrl cited);换出旧根收尾 trieNodeReset。
//   §9(63131-63281)记录向量:recordSinkAcquire 真身(local_90 0x38 容器
//       承载 = KeymapRecordSink;容量 = payload+0xa8 预算 + [+0xb0] + 1;
//       记录 0x28B/条 = KeymapMatchRecord {rep,tail,flag,pad,rep2,flag2};
//       首配下限 0x100(00676e4b));宿主历史链消费腿 cited。
//   §10(63282-63342)×1.5 扩容(63296-63303 double 乘 + 9.22e18 溢出钳)
//       = recordSinkAcquire 真身内;旧链卸挂(63330-63335)真身内。
//   §11(63350-63360)FUN_00683c80(554B)克隆 payload 列表 → 记录
//       挂链(local_98);plVar27 = *(节点+0x78) → 虚调 vtable+0x10
//       (plVar27,&local_268) 返回 bool = 匹配谓词(00675f2c 调用形,
//       谓词类属未解 —— cited);false → 叶记录 {record[0]=record[3],
//       record[1]=token 尾指针}(00675f31);true → FUN_0067e4c2
//       (215B,0021.c 1035-1064)入本地树(+0x20/+0x30/+0x50 域写 +
//       +0x70 子链递归传播)。
//   §12(63361-63516)— cited — wave-2:when 条件 JS 腿(entry
//       +0x40/+0x48 = lVar7+0x30/0x38 域,mask 0x3fffffff →
//       canConvert→toString→trimmed(00676ecf-00676f03)→
//       FUN_00767a70(38B,引擎门 +0x48)取 QJSValue → isCallable?
//       → FUN_0067cd71 metatype 注册(107B,DAT_011c18dc)→
//       QVariant 缓存回写 → FUN_0067e011(260B)取回 →
//       FUN_0076745c(104B)求值 → isBool→toBool;bVar17 一次性门)。
//   §13(63517-63654)命中分发(LAB_00675e70):FUN_00767d08(38B)
//       建 QJSValue 结果对象(JS 面 cited);逐记录 setProperty
//       (fromUcs4 键名,00675ef6-00675f28);count 门:tokenIdx==1 &&
//       repeatable(+0x20,lVar7+0x10 读形)&& flags&0x14 →
//       wcstol(tokens[0],"stoi")(006776f7 门);FUN_006745b0 清输入
//       缓冲(00677258);entry.actionType(+0x28,lVar7+0x18 读形)
//       ==1 → payload.toString() + count>1 时 number 前插 0067752a-
//       0067754a → FUN_0075debe 合成键事件(00677553,真身上方);
//       否则 count 次循环:==0 → 00674442 cast → payload.toByteArray
//       → FUN_007682c0 → 0066a116(006772d0,真身上方);payload
//       QVariant mask(+0x38)&0x3fffffff → FUN_00767a70 取 callable +
//       FUN_0076745c 直调(JS 面 cited);result=2(006776f2 前)。
//   §14(63655)LAB_00675d97:result=1;bVar18=true;非末 token 续。
//   §15(63888-63957)收尾(LAB_00675dbd/00675dcb/006751ce):
//       result==2 → sp release + FUN_0067e2c0(210B)本地树回收 +
//       返回;bVar18(前缀)且 mode!=2 → FUN_0067df30(125B)
//       {槽项 wstring,sp} append 记录弦清单;否则 mode==2 →
//       QList::erase 当前槽项(learn 命中移除,00677071-00677170);
//       游标推进 → 下一槽项。
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
		// §4(62638-62662)首门(00675296):Trie 根 = entry+0x08 槽
		//    (语料 *(lVar7+8);onig 编译腿换入,cited — wave-2 未建)
		//    ——根空或根谓词槽 *(根+0x78)==0 即出。
		TrieNode *root = entry.trieRoot;   // 62643:*(lVar7 + 8)
		if (root == nullptr || root->group.pred == nullptr)
			break;   // §4 门 → 走查体(§5-§13)整体短路(装载腿 cited)
		// §5(62659)FUN_00681a40(&local_3d8,lVar7+8):获取/换入走查
		//    节点(snap = 旧根 use++ 持有,或空 = 复用腿 §6-§8 跳过)
		TrieNode *snap = trieNodeGetOrCreate(&entry.trieRoot);
		root = entry.trieRoot;   // 62661:p_Var41 = 换入后根
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
		//    owner = token rep(63268 local_250 = p_Var8);§11 叶写/
		//    谓词虚调(cited — wave-2)消费此向量。
		KeymapRecordSink sink;   // 63146-63211
		out.sink = &sink;        // §13 消费面挂出(cited — wave-2)
		const ushort t0 = tokens.isEmpty() ? 0 : tokens[0].at(0).unicode();
		(void)recordSinkAcquire(sink, root->group.xA8, root->group.xB0,
		                        reinterpret_cast<const wchar_t *>(
		                            static_cast<uintptr_t>(t0)));
		// §12-§15(63361-63957)— cited — wave-2(when JS 腿/命中分发/
		//    收尾)—— 走查体保持注记级,见函数头逐段落点。
		return out.result;   // 装载腿 cited(Trie 根未建)恒 0(不伪造 1/2)
	}
	return out.result;
}
