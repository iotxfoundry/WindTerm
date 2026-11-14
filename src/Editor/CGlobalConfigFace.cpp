#include "CGlobalConfigFace.h"

#include <QByteArray>
#include <QFile>
#include <yaml-cpp/yaml.h>

// 批 140 — 两腿 Meyers 单例体(库内唯一副本,判例
// CTerminalConfig::instance();头内 inline static 跨 DSO 会双副本,
// 破坏 menu() 两窗同身份断言面)。

// FUN_005df8d6(121B,0019.c:15746):CEditorConfig Meyers
// DAT_011c1300(guard DAT_011c12e8 + atexit FUN_005dfc04)。
CEditorConfigFace *CEditorConfigFace::instance()
{
	static CEditorConfigFace cfg;
	return &cfg;
}

// FUN_00809d78(121B,0025.c:43289):CTerminalConfig Meyers face 视图
// DAT_011c2220(guard DAT_011c2208 + atexit FUN_0080a0ba;值面真单例
// 同址,KitWindowFactory.cpp terminalConfigAsFace 注记)。
// 批 142 双 Meyers 合一:CTerminalConfigFace 不再有独立 Meyers —
// face 面由 CTerminalConfig 私有基承载(CTerminalConfig::face()),
// 两个静态对象合为一。

// ======== 批 142:yaml 装载腿真身化 ========
// 委托真 yaml-cpp 解析(EXT-BOUNDARY/ConfigBridge 判例:实现不逆向);
// 装载编排/树挂接/遍历面 = FUN_008a99de/008aa39e/008a971e/s_FilterEdit_
// 8a9d3c 转写。装载语义 = 键值进 groups(+0x28)/views(+0x60)handler
// 面,与 groupNames()(+0xa8 读面;真身批 140)/menu 查建腿闭环。

// SharedConfigHandlerFace::appendChild — FUN_008accc8(324B,0027.c:66458):
// new 子节点(QVariant 键 ← QByteArray @008acc1a 前段,即 FUN_008aabae
// 尾段 DAT_011c2560==0 分支逐字段拷贝)+ 父指针写位(@008acc82
// local_70[5]=param_2)→ children 末位插入(cap 判 @008acd16,重配腿
// FUN_008ac9d0 299B cited — 语义 = 末位插入,growth 因子语料未读)。
SharedConfigHandlerFace *SharedConfigHandlerFace::appendChild(const QByteArray &key)
{
	SharedConfigHandlerFace *child = new SharedConfigHandlerFace; // operator_new(0x38) @008accf0
	child->m_value = key;                    // QVariant(QByteArray) @008acc1a 分支
	child->m_parent = this;                  // local_70[5]=param_2 @008acc82
	if (m_end == m_cap) {                    // @008acd16 → FUN_008ac9d0 重配
		const int n = static_cast<int>(m_end - m_begin); // 语料 lVar5/8 面
		const int cap = static_cast<int>(m_cap - m_begin);
		SharedConfigHandlerFace **nb = new SharedConfigHandlerFace *[cap ? cap * 2 + 4 : 4];
		for (int i = 0; i < n; ++i)          // 旧元素搬移(@008acd2x 段)
			nb[i] = m_begin[i];
		delete[] m_begin;
		m_begin = nb;
		m_end = nb + n;
		m_cap = nb + (cap ? cap * 2 + 4 : 4); // growth 因子 cited(FUN_008ac9d0 未读)
	}
	*m_end++ = child;                        // *puVar6=local_70; end++ @008acd20
	return child;                            // 返回迭代器 face(iter+8=子节点同相)
}

// SharedConfigHandlerFace::clearChildren — FUN_008aaae2(126B,0027.c:64240):
// 逐子递归 + 析构 + operator_delete;end 回退 begin(begin/cap 保留)。
void SharedConfigHandlerFace::clearChildren()
{
	for (SharedConfigHandlerFace **p = m_begin; p != m_end; ++p) {
		(*p)->clearChildren();               // FUN_008aaae2(puVar2) 递归
		delete *p;                           // dtor + operator_delete
	}
	m_end = m_begin;                         // *(+0x10)=*(+0x8) @008aaae2 尾
}

// yaml 装载腿公共编排 — FUN_008a99de(800B,0027.c:63432)骨架:
// S1 路径(FUN_008a58f0)→ S2 yaml_loadFile(失败透传 false)→ S3
// FUN_008aaae2 清 handler 树 → S4 顶层 sequence 逐元素:组名(元素首标量)
// 挂 handler @008a9b2b → 元素体下钻转写(Groups=FUN_008a971e 六百 B、
// Views=s_FilterEdit_8a9d3c 1489B,kind 位面族在案)。
static void loadViewsElement(const YAML::Node &arr, SharedConfigHandlerFace *parent);
static void loadGroupsElement(const YAML::Node &arr, SharedConfigHandlerFace *parent); // fwd: 静态先声明
static bool yamlLoadInto(const QString &path, SharedConfigHandlerFace *root,
                         bool viewsLeg)
{
	QFile f(path);                           // yaml_loadFile 内 QFile 面
	if (!f.open(QIODevice::ReadOnly))
		return false;                        // cVar5='\0' 直返腿 @008a9a6a
	YAML::Node doc;
	try {
		doc = YAML::Load(f.readAll().constData()); // 真库委托(ConfigBridge 判例)
	} catch (const YAML::Exception &) {
		return false;                        // loadFile 失败腿同相
	}
	if (doc.Type() != YAML::NodeType::Sequence)
		return false;                        // json_size==0/FUN_00aef7f0 门 @008a9a50-9a
	root->clearChildren();                   // FUN_008aaae2(+0x28/+0x60) @008a9add/@008aa49d
	for (const auto &item : doc) {           // s_vector__reserve + do-while @008a9b0d
		if (!item.IsDefined())
			continue;                        // json_valueFind miss 门(@008a9b6e 值缺省)
		// 组名 = 元素唯一键(menu.config 顶层元素形 { "Kit" : [...] } —
		// 键名即组名;语料 s_vector__reserve_af3a20 取 map 键集 @00af3d03 腔)
		QString groupName;
		YAML::Node groupValue;                   // FUN_00af4760(根值,"键")下钻结果
		if (item.IsMap()) {
			for (const auto &kv : item) {
				groupName = QString::fromUtf8(kv.first.Scalar().c_str()); // QByteArray::operator= @008a9b21
				groupValue = kv.second;      // json_valueFind 命中槽 @00af4760(lVar4+0x30)
				break;                       // 首键(语料取首标量同相)
			}
		} else {
			groupName = QString::fromUtf8(item.Scalar().c_str());
		}
		SharedConfigHandlerFace *grp = root->appendChild(groupName.toUtf8()); // FUN_008accc8 @008a9b2b/@008aa4e1
		// 元素体下钻(批 147):FUN_008a971e(Groups)/s_FilterEdit_8a9d3c
		// (Views)— param_3 = grp 节点(挂子父腔 param_3[0]=**(+8))。
		if (viewsLeg)
			loadViewsElement(groupValue, grp);   // s_FilterEdit_8a9d3c @008aa556
		else
			loadGroupsElement(groupValue, grp);  // FUN_008a971e @008a9b96
	}
	return true;
}

// ======== 批 147:树深下钻真身化 ========
// 元素体二级转写(菜单配置树:顶层组 → 元素 {kind: 名} 列表 → Menu 节点
// 三级 "Actions" 子序列递归)。

// FUN_008a971e(646B,0027.c:63338)Groups 元素体下钻 — param_2 = 组值
// array,每元素(map)按唯一 kind 键判别:
//   "Action" → kind=3(@008a9836 低 nibble|3),名 = "Action" 键值缺省
//     DAT_00cb99b6(空 BA @008a9840 get_string_default);"Menu" → kind=2
//     (@008a9910),名 = "Menu" 键值;递归腿:值对象挂 children(@008a9873
//     FUN_008accc8 父 = param_3[0] 节点)后 kind==2 → 取 "Actions" 键
//     (@008a9990)递归本函数(子序列,子节点父 = 新挂节点);"Separator" →
//     kind=0 + 名空(@008a98ca-8f clear)。非三键元素(如 "Actions" 子序列
//     外的裸标量)→ FUN_00aef800 map 门跳过(@008a97c6)。
// 返回恒 1(@008a99e8 尾;装载腿不消费返回值,循环计数透传面)。
static int elemKindOfGroups(const YAML::Node &el, QByteArray &name,
                            SharedConfigHandlerFace *parent)
{
	// kind 判别 = 元素 map 的唯一键字面(语料 json_assign_cstring+FUN_00aef040
	// 相等链 @008a9789-91a;"Action"→3 / "Menu"→2 / "Separator"→0)
	if (const YAML::Node a = el["Action"]) { // json_valueFind @008a9789
		name = QByteArray(a.Scalar().c_str()); // get_string_default("Action",空) @008a9836-51
		return 3;                              // local_d8 & 0xf0 | 3 @008a982c
	}
	if (const YAML::Node m = el["Menu"]) {   // @008a98ca
		name = QByteArray(m.Scalar().c_str()); // @008a9910-2b
		return 2;                              // | 2 @008a991c
	}
	if (const YAML::Node s = el["Separator"]) { // @008a993b
		name.clear();                          // QByteArray::clear @008a9943
		return 0;                              // & 0xf0(=0)@008a993e
	}
	return -1; // 无 kind 键(非 menu 元素)— 装载腿 map 门已滤,防御位
}

static void loadGroupsElement(const YAML::Node &arr, SharedConfigHandlerFace *parent);

// 全函数序 = FUN_008a971e:size 门(@008a976a)+ array 门(@008a9771)→
// 逐元素 copy(map 门 @008a97c6)→ 三 kind 分支 → 挂子(@008a9873)→
// Menu 腿 "Actions" 递归(@008a9990)。
static void loadGroupsElement(const YAML::Node &arr, SharedConfigHandlerFace *parent)
{
	if (arr.Type() != YAML::NodeType::Sequence) // json_size!=0 + FUN_00aef7f0(array 门)
		return;
	for (const auto &el : arr) { // do-while uVar6<size @008a97d3-99a
		if (el.Type() != YAML::NodeType::Map)
			continue;                            // FUN_00aef800 map 门 @008a97c6
		QByteArray name;                          // local_e8 shared_null @008a977d
		const int kind = elemKindOfGroups(el, name, parent);
		if (kind < 0)
			continue;
		SharedConfigHandlerFace *child = parent->appendChild(name); // FUN_008accc8 @008a9873
		child->setKind(kind);                     // local_d8 位面入值对象
		if (kind == 2) {                          // (local_d8 & 0xf)==2 @008a9880
			YAML::Node acts;                       // json_assign_cstring("Actions") @008a9990
			if (const YAML::Node n = el["Actions"])
				acts = n;                          // InvalidNode 卫(yaml-cpp 真库缺键
			                                       //   抛型 — 语料 json_valueFind 返 0
			                                       //   缺省,同相直返空)
			loadGroupsElement(acts, child);        // FUN_008a971e(param_1,"Actions",local_98)
		}
	}
}
// s_FilterEdit_8a9d3c(1489B,0027.c:63575)Views 元素体下钻 — 七 kind 位面:
//   Action 3(@008a9dcf)/ ToolBar 2(@008aa09a)/ Label 4(@008aa150)/
//   Separator 0(@008aa1e0,名 = 键值 asCString 缺省 "" @008aa218-38 —
//   注意:与 Groups 腿 Separator 名空不同!)/ Spacer 1(@008aa250)/
//   AddressBar 5(@008aa28c)/ FilterEdit 6(@008aa2b4)。
//   Action 附加腿:Menu/Popup 名 → 值对象 +0x8 槽(local_e0)+ bit3
//   (@008a9e70 置 / @008aa138);Columns 高 nibble(@008a9ea8);高 nibble
//   为 0 且 popup 名空 → 1,bit3 置 → +1(@008a9eb8-f0 装载内省腿);
//   Style → QMetaEnum keyToValue(cited — 无 "Style" 键真配置,恒 -1→0)。
static void loadViewsElement(const YAML::Node &arr, SharedConfigHandlerFace *parent)
{
	if (arr.Type() != YAML::NodeType::Sequence) // json_size + array 门 @008a9d68-70
		return;
	for (const auto &el : arr) { // while uVar7<size @008a9d7e-02b
		if (el.Type() != YAML::NodeType::Map)
			continue;                            // FUN_00aef800 map 门 @008aa01d
		QByteArray name;                          // local_e8 @008a9d8d
		int kind = -1;
		// 七键判别链(@008aa01d-2b4 顺序:Action→ToolBar→Label→Separator→
		//   Spacer→AddressBar→FilterEdit)
		if (const YAML::Node n = el["Action"]) { // @008a9dcf 腿
			name = QByteArray(n.Scalar().c_str()); // get_string_default("Action") @008a9de4-fc
			kind = 3;                              // | 3 @008a9dd4
		} else if (const YAML::Node n2 = el["ToolBar"]) { // @008aa09a
			name = QByteArray(n2.Scalar().c_str()); // @008aa0ab-c3
			kind = 2;                              // | 2 @008aa0a0
		} else if (const YAML::Node n3 = el["Label"]) { // @008aa150
			name = QByteArray(n3.Scalar().c_str()); // @008aa194-1ac
			kind = 4;                              // | 4 @008aa156
		} else if (el["Separator"]) {            // @008aa1e0
			const YAML::Node s = el["Separator"];  // 键值名腿(Separator 名非空!)
			name = QByteArray(s.Scalar().c_str()); // asCString 缺省 "" @008aa218-38
			kind = 0;                              // & 0xf0 @008aa1e6
		} else if (el["Spacer"]) {               // @008aa250
			name.clear();                          // @008aa252
			kind = 1;                              // | 1 @008aa256
		} else if (el["AddressBar"]) {           // @008aa28c
			name.clear();                          // @008aa28e
			kind = 5;                              // | 5 @008aa292
		} else if (el["FilterEdit"]) {           // @008aa2b4
			name.clear();                          // @008aa2b6
			kind = 6;                              // | 6 @008aa2ba
		}
		if (kind < 0)
			continue; // 无七键(真配置无此形态;map 门防御同相)
		SharedConfigHandlerFace *child = parent->appendChild(name); // FUN_008accc8 @008a9fe2-6
		child->setKind(kind);                     // local_d8 位面入值对象
		if (kind == 3) {                          // Action 附加腿
			// Menu/Popup 名(@008a9e15-e6):hasKey "Menu" 优先,否则 "Popup";
			// 名入值对象 +0x8 槽(local_e0);bit3:Menu 置 @008a9e70,Popup
			// 路清 @008aa138(语料清位;值槽已写 — 读面只看名字槽,旗怪癖注记)。
			if (const YAML::Node mn = el["Menu"]) { // json_hasKey("Menu") @008a9e15
				child->setPopup(QByteArray(mn.Scalar().c_str())); // @008a9e50-6c + bit3 置
			} else if (const YAML::Node pn = el["Popup"]) { // @008aa0e3
				child->setPopup(QByteArray(pn.Scalar().c_str())); // @008aa10f-2b(bit3 清态,
				                             //   setPopup 置旗与语料清位相悖 — popup
				                             //   读面名字槽权威,旗位怪癖入 QUIRKS 注记)
			}
			// Columns 高 nibble(@008a9e87-f0):get_string_default("Columns")
			// → asUInt;真配置无 "Columns" 键 → 0。
			unsigned char cols = 0;
			if (const YAML::Node cn = el["Columns"])
				cols = (unsigned char)cn.as<int>(); // json_asUInt @008a9ea4
			// 高 nibble 内省腿(@008a9eb8-f0):cols==0 → popup 名空 ? 1 :
			//   (bit3 清 ? 3 : 1)— cVar1 = (-((d7&8)==0) & 2) + 1 精确转写
			//   (bit3 清 → -(1)&2=2 → +1=3;bit3 置 → -(0)&2=0 → +1=1)。
			if (cols == 0) {
				if (child->popupName().isEmpty())
					cols = 1;                        // size==0 腿 @008a9eb8-c4
				else
					cols = (unsigned char)(1 + (child->popupFlag() ? 0 : 2)); // (-f&2)+1
			}
			child->setColumns(cols);
			// Style 腿(@008a9f12-af):QMetaEnum keyToValue — cited(King
			//   QMetaEnum 注册面不在本库;真配置无 "Style" 键 → -1→0 缺省同相)。
		}
	}
}

// 0x14 char 二进制实读)。
bool CGlobalConfigFace::loadGroups()
{
	return yamlLoadInto(configPath("/configs/menu.config", 20), &m_groups, false);
}

// FUN_008aa39e — Views 腿(tail = DAT_00cb9d40 QString 槽:size 0x17,
// 数据 "/configs/toolbar.config" 22 字符 — fromLatin1(tail,22) 尾差一位
// 怪癖原样(批 140 0x17 字面;strace openat "toolbar.confi" 实证);+0x60 handler)。
bool CGlobalConfigFace::loadViews()
{
	// DAT_00cb9d40 实读:size 槽 0x17(23),数据 "/configs/toolbar.config"
	// 22 字符 + NUL — 语料 QString::fromLatin1 尾差一位(批 140 0x17 腿
	// 原样;strace 实证 openat 路径尾截 "toolbar.confi" = 原版怪癖原样,
	// 不修 — 装载腿工具栏文件名 22 字符截断)。
	return yamlLoadInto(configPath("/configs/toolbar.confi", 22), &m_views, true);
}

// FUN_008aa896(78B,0027.c:64033):vt+0x18 vcall & vt+0x28 vcall
// (reopen.history 读腿 cited)四路 AND。yaml 两腿真身化后 =
// loadGroups & loadViews(& vt 槽 cited 恒真 — 空表语义,不发明)。
bool CGlobalConfigFace::ensureLoaded()
{
	const bool vt18 = true;  // cited — vt+0x18 槽体未转写(不发明)
	const bool vt28 = true;  // cited — vt+0x28 reopen.history 槽体未转写
	return vt28 & vt18 & loadGroups() & loadViews(); // uVar4 & uVar1 & uVar3 & uVar2 @008aa8d5
}
