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
static bool yamlLoadInto(const QString &path, SharedConfigHandlerFace *root,
                         bool /*viewsLeg*/)
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
		if (item.Type() != YAML::NodeType::Map && item.Type() != YAML::NodeType::Scalar)
			continue;                        // FUN_00aef800 map 门 @008a9b21
		// 组名 = FUN_008a58f0 selfName 腿对位?非 — 元素名串直接挂:
		// 组键 = 元素唯一键(menu.config 顶层元素形 { "Kit" : [...] } —
		// 键名即组名)
		QString groupName;
		if (item.Type() == YAML::NodeType::Map) {
			for (const auto &kv : item) {
				groupName = QString::fromUtf8(kv.first.Scalar().c_str()); // QByteArray::operator= @008a9b21
				break;                       // 首键(语料取首标量同相)
			}
		} else {
			groupName = QString::fromUtf8(item.Scalar().c_str());
		}
		root->appendChild(groupName.toUtf8()); // FUN_008accc8(+0x28/+0x60,键) @008a9b2b/@008aa4e1
	}
	return true;
}

// FUN_008a99de — Groups 腿(tail = "/configs/menu.config" DAT_00cb9da0,
// 0x14 char 二进制实读)。
bool CGlobalConfigFace::loadGroups()
{
	return yamlLoadInto(configPath("/configs/menu.config", 20), &m_groups, false);
}

// FUN_008aa39e — Views 腿(tail = "/configs/toolbar.config" DAT_00cb9d40,
// 0x17 char 二进制实读;+0x60 handler)。
bool CGlobalConfigFace::loadViews()
{
	return yamlLoadInto(configPath("/configs/toolbar.config", 22), &m_views, true);
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
