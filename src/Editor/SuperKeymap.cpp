#include "SuperKeymap.h"

#include <QByteArray>
#include <QKeySequence>

#include <cstring>

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
// FUN_00674cce(14B thunk → FUN_00674b1e 431B 键码→名反向,DAT_011c1960
// 写侧未解)— cited — wave-2 → replace(pos,len,名字符) → +1 推进;
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
			// FUN_00674cce 键码→名反向 — cited — wave-2(stub 返 0;
			// 复刻表后回填,届时 replace 真实名)
			const uint nameChar = 0;   // cited stub
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

// ── 匹配翼 ──────────────────────────────────────────────

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
		matchTrie(out, m_slots.at(0), tokens, 0);   // 00677acf(slot0)
		result = out.result;
		if (result != 2) {
			matchTrie(out, m_slots.at(1), tokens, 1);   // 00677b0f(slot1)
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

// FUN_0067500e(9978B,decomp-part-0020.c 62391-63957)15 段骨架
// (P3 勘察 §3;深腿 cited —— Trie 内部布局未全解:节点 +0x70 use
// 计数/+0x78..+0x88 shared 槽/+0x90..+0x98 子键向量/+0x58 计数;
// +0x78 虚调目标类属未解,见勘察「未解」条)
int SuperKeymap::matchTrie(MatchOut &out, const QList<KeymapEntry> &slotList,
                           const QVector<QString> &tokens, int mode)
{
	// §1(62391-62616)局部初始化:out{+0 flags,+2 键 QVariant,+3 缓冲,
	//    +6 结果};param_2 = 槽列表;param_3 = token 向量;local_408 = 槽游标
	out.result = 0;
	// §2(62617-62635)外层槽循环头(LAB_00675222):QList detach
	//    (FUN_0067e3dc)→ 槽项{shared_ptr@0, ctrl@8} → sp ref++;
	//    语料游标步进 +2(006751e5)
	for (int si = 0; si < slotList.size(); si += 2) {
		const KeymapEntry &entry = slotList.at(si);
		// §3(62636)模式门:modesMask(+0x24)& 旗标;不满足 → 下一槽项
		if ((entry.modesMask & out.flags) == 0)
			continue;
		// §4(62638-62662)token 循环(LAB_00675296/755b6/755e2):Trie
		//    子树空(*(子+0x78)==0)跳出;tokenIdx==1 && flags∈{2,8}
		//    早退;token0==token1 wmemcmp 重复键短路(code_r0x00675e23)
		for (int ti = 0; ti < tokens.size(); ++ti) {
			Q_UNUSED(ti)
			// §5(62664-62736)节点获取/复位:FUN_00681a40(lVar7+8)取当前
			//    Trie 节点(+0x70 use 计数);减到 0 → FUN_0067faa0 子树回收
			//    + 字段复位(+0x18/20/28/60/68)— cited — wave-2
			// §6(62737-62843)子表快照:节点 +0x78/+0x80/+0x88 三 shared 槽
			//    + +0x90/+0x98 vector<pair<wstring,payload>> 深拷贝后经
			//    FUN_00683ad6 整组换入(FUN_006857f4 段尾)— cited — wave-2
			// §7(62844-62925)LAB_006761d1:map 节点遍历;FUN_006857f4
			//    (p+0x30)查找 → _Rb_tree_insert_and_rebalance 新子键;
			//    +0x58 计数++ — cited — wave-2
			// §8(62928-63130)双树裁剪循环:第二棵 Rb_tree(+0x30 系)增量
			//    对齐,引用不匹配者 _Rb_tree_rebalance_for_erase +
			//    operator_delete(共享 payload refcount CAS;FUN_0067a2a0
			//    vt 比对哨兵)【归纳待逐句核】— cited — wave-2
			// §9(63131-63281)记录向量构建:local_90 新建 0x38 容器(Rb 头
			//    +vector);节点 payload(+0x60)+[0x15]/[0x16] 定容量;
			//    0x28B/条 {owner,flag,owner} 填充 — cited — wave-2
			// §10(63282-63342)向量 ×1.5 扩容重分配(LAB_00676af5)
			//    — cited — wave-2
			// §11(63350-63360)FUN_00683c80 克隆 payload 列表 → 记录挂链;
			//    plVar27=node+0x78 → 虚调 (+0x10)(plVar27,&local_268) 返回
			//    bool = 匹配谓词(虚调目标类属未解)false→记入叶;
			//    true→FUN_0067e4c2 入本地树【归纳待逐句核】— cited — wave-2
			// §12(63361-63516)JS 条件腿(仅未命中过):entry+0x38 mask
			//    &0x3fffffff → QVariant→String→trimmed → FUN_00767a70 取
			//    QJSValue → isCallable? → FUN_0067cd71(JS 引擎)求值 →
			//    结果 QVariant 缓存回 entry+0x30/+0x38 → 二次 FUN_0076745c
			//    isBool→toBool → bVar17=true — cited — wave-2(pane JS
			//    上下文未接)
			// §13(63517-63654)命中动作分发(LAB_00675e70):guard
			//    DAT_011c19c0;FUN_00767d08 建 QJSValue 结果对象,逐记录
			//    setProperty(fromUcs4 键名);ti==1 && entry+0x10 &&
			//    flags&0x14 → wcstol(count 前缀,"stoi");FUN_006745b0 清
			//    输入缓冲;entry+0x18==1 → FUN_0075debe(qApp,str)= 合成
			//    QKeyEvent 投递焦点 widget(宏/直通);否则按 count 次循环:
			//    entry+0x18==0 → FUN_007682c0 → FUN_0066a116 =
			//    actionFactory_getOrCreate + js_actionFire(+0x60 动作串);
			//    entry+0x20 QVariant → JS callable 求值调用;result=2
			//    — cited — wave-2
		}
		// §14(63655)LAB_00675d97 未竟前缀:result=1;bVar18=true;续
		//    token 循环(归属 Trie 行走,cited —— 骨架不产生伪结果)
		// §15(63888-63957)收尾:result==2 → sp release;mode!=2 →
		//    FUN_0067df30 清缓冲;mode==2(LAB_006751ce)→ QList::erase
		//    当前槽项(learn 模式匹配后移除);游标+2 → 下一槽项
		//    (LAB_00675222)
	}
	return out.result;   // 骨架:深腿未落,恒 0(不伪造 1/2)
}
