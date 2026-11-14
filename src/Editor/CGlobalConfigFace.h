#ifndef CGLOBALCONFIGFACE_H
#define CGLOBALCONFIGFACE_H

#pragma once

// 批 140(M12-② 前半)— menu() 容器 face,KITWINDOW-RECON §未解 1 收口:
// showConfigMenu 虚调用 menu()(vtable 槽 62 +0x1f0)返回的是 Config 系
// 单例对象,非 QMenu:
//   - Editor 腿 FUN_005e97d2(39B,0019.c:22781):DAT_011c12e0 懒缓存 ←
//     FUN_005df8d6(121B,0019.c:15746,CEditorConfig Meyers;ctor
//     FUN_005df8ae 39B,0019.c:15734 = FUN_008a71e4 基构造 +
//     CEditorConfig_vtable 换写 + +0xa8 QList shared_null;typeinfo
//     "13CEditorConfig"@0xc8c5d0;sizeof 0xb0 = deleting dtor
//     FUN_005dfbec,0019.c:15937,operator_delete(0xb0))。
//   - Terminal 腿 FUN_00858fce(39B,0026.c:50296):DAT_011c2200 懒缓存 ←
//     FUN_00809d78(= CTerminalConfig::instance(),src/Editor 真单例已落库)。
// 两腿尾均 FUN_008aa896(DAT)后返回(78B,0027.c:64033:vt+0x18 vcall &
// vt+0x28 vcall(thunk_FUN_008aa6fc 同体直调)& FUN_008a99de yaml Groups
// 装载 & FUN_008aa39e yaml Views 装载,四路 AND)— 槽族/装载链本 face
// cited,不落(铁律 3)。
//
// 基类归属实读定案(任务书候选"SharedConfig"按语料勘正):两单例 ctor
// 首句均为 FUN_008a71e4(503B,0027.c:61300)= CGlobalConfig 基构造
// (vtable PTR_CGlobalConfig_vt14_01192550;写位 +0x10/+0x18 list 哨兵、
// +0x20=0、+0x28/+0x60 双 SharedConfigHandler(FUN_008aabae(param_1+5 /
// param_1+0xc) 后调用点覆写 vt9 @008a7251)、+0x98 FUN_008ace72 map 面、
// +0xa0 FUN_00a86142 0x18B 发射体)— CEditorConfig/CTerminalConfig
// IS-A CGlobalConfig(基构造 + vtable 换写形态,无歧义)。typeinfo
// "12SharedConfig"(0xc8c8b0)对应独立小类 SharedConfig(0x18B =
// {vt, QList@+0x08(FUN_005e8ed0 消偿,0019.c:22233), QMap@+0x10
// (qmap_freetree_variant_nodes 消偿)};dtor FUN_005e8f14 50B,
// 0019.c:22268)— 与 CGlobalConfig 继承链语料未证 → face 平铺落
// CGlobalConfig 名下,不发明继承树(铁律 6;任务书条款兑现)。

#include <QList>
#include <QString>
#include <QVariant>

// SharedConfigHandlerFace — 语料 handler 节点 face(容器 +0x28 消费面的
// 元素):基构造 FUN_008aabae(187B,0027.c:64298)= vptr@0 + children
// 三槽清零 + QVariant@+0x20(DAT_011c2560 钩或缺省拷贝);挂子
// FUN_008accc8(324B,0027.c:66458,new 0x38B 子节点 push 入
// {begin@+8,end@+0x10,cap@+0x18},满则 FUN_008ac9d0 重配);递归消偿
// FUN_008aaae2(126B,0027.c:64240);拷贝 FUN_008acb70(301B,0027.c:66397)。
// 键面实读:FUN_006926c2(164B,0021.c:18568)遍历 children 比较
// child+0x20 QVariant → d.ptr → QStringData{size@+4,offset@+0x10} 的串
// (memcmp 同长匹配)。vptr 槽位 face 不设(无虚消费);挂子/消偿/装载
// 链 cited,节点仅承载被读字段族。
class SharedConfigHandlerFace
{
public:
	SharedConfigHandlerFace() = default; // FUN_008aabae:全零 + QVariant 缺省

	SharedConfigHandlerFace *m_begin = nullptr; // children begin(语料 +0x08)
	SharedConfigHandlerFace *m_end = nullptr;   // children end(语料 +0x10;
	                                            //   容器视角 +0x38 = FUN_00692ef0
	                                            //   迭代终判读位)
	SharedConfigHandlerFace *m_cap = nullptr;   // children cap(语料 +0x18)
	QVariant m_value;                           // 键/值 QVariant(语料 +0x20;
	                                            //   QString 键面见 FUN_006926c2)
};

// CGlobalConfigFace — menu() 返回容器 face(两腿单例公共基,见头注)。
// 字段仅落两处被读面,其余语料写位 cited 注记(壳判例批 133/铁律 6):
//   +0x28 m_groups  — menu 分组 handler:FUN_00692ef0(310B,0021.c:18914)
//                     读容器 +0x28 取 handler、+0x38 取 children end 作
//                     迭代终判(K 效消费面同相);FUN_006926c2 遍历
//                     children 按键查(FUN_00692a70 命中取缓存 QMenu,
//                     1119B cited);未命中 tr+新建腿已真身(批 133)。
//   +0xa8 m_configEntries — 组名条目 QList(元素 = 0x120B entry 对象,
//                     名 char*@+8;消偿 CEditorConfig_vt7 遍历
//                     config_dtorFreeRegex+delete(0x120),0019.c:15852;
//                     config_dtorFreeRegex@009d092c,0032.c:70409)。
// cited 未落:+0x10/+0x18 list 哨兵、+0x20、+0x60 Views handler、
// +0x98 map 面、+0xa0 发射体(写位见 FUN_008a71e4 全读,头注)。
class CGlobalConfigFace
{
public:
	// FUN_005df958(316B,0019.c:15771;唯一调用点 FUN_005e97ba 24B,
	// 0019.c:22770,实参 = Editor 单例 DAT_011c12e0):遍历 +0xa8 QList,
	// 元素 entry+8 char* → QString::fromUtf8_helper(@005df9a3)→ 非空
	// (@005df99b,size!=0)且 startsWith("::",cs=1) 为假(@005dfa46-4a)
	// 才 append(@005dfa6f-83)。entry 对象/装载链(FUN_008aa39e/
	// s_FilterEdit_8a9d3c 各 800B)cited → 表运行期恒空,机制原样。
	QList<QString> groupNames() const
	{
		QList<QString> out; // *param_1 = shared_null @005df96a
		for (const void *entry : m_configEntries) { // *(param_2+0xa8) 遍历
			const char *raw = static_cast<const char *const *>(entry)[1]; // entry+8
			const QString name = QString::fromUtf8(raw); // @005df9a3
			if (!name.isEmpty() && !name.startsWith(QStringLiteral("::")))
				out.append(name); // @005dfa6f-83(非 "::" 前缀才收)
		}
		return out;
	}

protected:
	CGlobalConfigFace() = default; // FUN_008a71e4(基构造;字段写位见头注,
	                               //   未落成员 cited)
	~CGlobalConfigFace() = default;

	SharedConfigHandlerFace m_groups;    // 语料 +0x28(FUN_008a71e4 [5])
	QList<void *> m_configEntries;       // 语料 +0xa8(两 ctor 均 shared_null:
	                                     //   FUN_005df8ae [0x15]/FUN_00809b90
	                                     //   [0x15];元素 entry 对象 cited)
};

// CEditorConfigFace — Editor 腿单例(FUN_005df8d6 121B Meyers:双卫
// DAT_011c12e8/DAT_011c13b0 + __cxa_atexit FUN_005dfc04,0019.c:15746 —
// 函数局部 static 同构承载;ctor FUN_005df8ae 39B = FUN_008a71e4 基 +
// vtable 换写 + +0xa8 shared_null)。instance() 体在 CGlobalConfigFace.cpp
// (库内唯一副本;头内 inline static 会因跨 DSO 双副本破坏单例身份,
// CTerminalConfig::instance() 判例同型)。
class CEditorConfigFace : public CGlobalConfigFace
{
public:
	static CEditorConfigFace *instance(); // FUN_005df8d6(cpp 侧)

private:
	CEditorConfigFace() = default; // FUN_005df8ae(基构造 + 字段缺省同相)
};

// CTerminalConfigFace — Terminal 腿 menu() 视图(语料同一单例对象
// DAT_011c2220 = CTerminalConfig 值面先批落库 + CGlobalConfig 容器面;
// 两面共存见 KitWindowFactory.cpp terminalConfigAsFace 注记;ctor
// FUN_00809b90 432B,0025.c:43201 = FUN_008a71e4 基 + vtable 换写 +
// +0xa8 shared_null + 值面成员族)。Meyers FUN_00809d78(121B,
// 0025.c:43289)同 Editor 腿形态(instance() 体同在 cpp 侧)。
class CTerminalConfigFace : public CGlobalConfigFace
{
public:
	static CTerminalConfigFace *instance(); // FUN_00809d78 face 视图(cpp 侧)

private:
	CTerminalConfigFace() = default; // FUN_00809b90(基构造 + 字段缺省同相;
	                                 //   值面成员族在 CTerminalConfig 真单例)
};

#endif // CGLOBALCONFIGFACE_H
