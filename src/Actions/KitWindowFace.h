#pragma once

#include <QString>
#include <QDataStream>
#include <QStringList>
#include <QVariantList>

#include <QByteArray>
#include <QMainWindow>
#include <QSplitter>

#include "Editor/CGlobalConfigFace.h"
#include "Widgets/Splitter.h"

// KitWindowFace —— 语料 KitWindow(typeinfo 011ab390,名 "9KitWindow" ELF
// 实读)承载面壳(MainWindowFace 判例批 100;铁律 6:抽象身份 + 纯虚 menu()。
// showConfigMenu 消费清单 = 零实例字段 + 一记虚调用 —— KITWINDOW-RECON.md
// Q2 实证"KitWindow 实例字段被读数 = 0",故本壳不落数据成员。
// ⚠ 批 192 勘正:Q2"字段零消费"只对 showConfigMenu 面成立;延迟装配链
//   008d3cc2 / 008cd068 / 008d2f7e 直读 +0x30 门与 +0x38..+0x68 七槽
//   (ctor 0x8cc6ba-c6f7 + 装配腿写面,≥2 源一致),故落字段族(见下);
//   +0x70 / +0x78..+0x90 / +0x98 / +0xa0..+0xb0 无本波消费面 → cited 不落。
// ctor 字段初始化面证据在案(FUN_008cc692,214B,decomp-part-0028.c:13331
// 全读):+0x30 WORD=0x0101(+0x30/+0x31 双 BYTE)/+0x38..+0x68 七 qw 槽位族 /
// +0x70 BYTE=1 / +0x78..+0x90 四 qw / +0x98 QList shared_null / +0xa0..+0xb0
// 三 qw;sizeof(KitWindow)=0xb8(deleting dtor FUN_008cc7d2 尾 delete 0xb8,
// 0028.c:13392)。抽象类:vtable 槽 62(+0x1f0)= __cxa_pure_virtual(0xbec350
// 实证),零直接构造点;槽 53-74 对位声明不在本壳做(22 虚零消费,声明即自造
// ABI 面;menu() 槽位由 C++ 自洽,见方案书 §3 要点)。
// 接线:工厂 FUN_0089d752(0027.c:55302)页插属 MainWindow 宿主批 —— 本壳
// 不造实例(批 133 任务书§4)。
class KitWindowFace : public QMainWindow {
public:
	// FUN_008cc692(214B,0028.c:13331):QMainWindow(parent,flags0) @0x8cc69b
	//   + 字段初值族 @0x8cc6ba-c6f7 + 尾 setAcceptDrops(true) @0x8cc75c。
	//   初值照记录:+0x30 WORD=0x0101 → 两 BYTE 皆 1;+0x38..+0x68 七槽 = 0。
	//   (+0x70 BYTE=1 / +0x98 QList shared_null / +0xa0..+0xb0 = 0 属未落
	//    字段族,cited——见类注。)
	explicit KitWindowFace(QWidget *parent = nullptr)
		: QMainWindow(parent, Qt::WindowFlags(0)) // @0x8cc69b
		, m_assemble0x30(1)                       // movw $0x101,0x30(%rbx) @0x8cc6ba
		, m_flag0x31(1)
	{
		setAcceptDrops(true); // @0x8cc75c
	}
	// FUN_008cc770(92B,0028.c:13364)cited:壳无字段 → 清偿面即
	//   QMainWindow 析构(语料 +0xa0 FUN_00674550+delete(0x20)/+0x98
	//   FUN_008d60a0 detach 消解腿属字段族,未落不发明)。
	virtual ~KitWindowFace() = default;
	// ── 字段族(批 192;ctor 偏移实读 + 装配腿写面 ≥2 源)──────────────
	// +0x30 = 装配待命门:008d3cc2 首门 cmpb 0x30 @0x8d3cc2 / 清零
	//   movb 0x30 @0x8d3d17;008d2f7e movzbl 0x30 @0x8d2f8f(门 != 0 → 返 0)。
	quint8 m_assemble0x30 = 1;

	// --- QuickBar 槽(批 441;语料 +0xd8 名称 / +0xe0 宿主 QPointer 对)---
	//   +0xd8 QString 名称(QuickBar 懒建时以 objectName "QuickBar" 取,0xd0e6d4)
	//   +0xe0 宿主控件指针(其 +0x68 = 快捷项名表 QStringList)
	//   仅 StateStore 写侧(stateStoreSerializeQuickBar)与读侧消费;
	//   建面(lazy ctor)未转写 → 两个 setter 由装配面调用(cited 建面)。
	const QString &quickBarName() const { return m_quickBarName; }
	QWidget *quickBarHost() const { return m_quickBarHost; }
	const QStringList &quickBarItemNames() const { return m_quickBarItems; }
	void setQuickBar(const QString &name, QWidget *host, const QStringList &items)
	{
		m_quickBarName = name;
		m_quickBarHost = host;
		m_quickBarItems = items;
	}
	// FUN_0085ae06(97B,0026.c:51529)应用快捷项:**顺序实读** ——
	//   先 FUN_0085ad2e()(预备);再 +0xd8/+0xe0 双槽有效时
	//   FUN_00570a80(+0xe0, 列表)(把项灌进宿主),宿主无效则喂 0。
	void applyQuickBarItems(const QStringList &items)
	{
		// FUN_0085ad2e() 预备腿 — cited
		if (!m_quickBarName.isEmpty() && m_quickBarHost != nullptr) {
			m_quickBarItems = items;               // FUN_00570a80(host, list)
			setQuickBar(m_quickBarName, m_quickBarHost, items);
		}
	}

	// FUN_008595c8(56B,0026.c:50519)收起:**仅** +0xd8 与 +0xe0 都有效时
	//   调 QWidget::hide();否则什么都不做(不建栏)。
	void collapseQuickBar()
	{
		if (m_quickBarHost != nullptr && !m_quickBarName.isEmpty())
			m_quickBarHost->hide();
	}

	// FUN_0085e0c0(350B,0027.c:595)读 QVariantList(写侧 count+项 的镜像):
	//   FUN_0081a2f6(out)(清空)→ **>> int count** → FUN_006ec720(out,count)
	//   (预留)→ 循环 **>> QString** + qlist_qvariant_append;
	//   流状态异常 → 清 out 后中止。
	static bool readVariantList(QDataStream &in, QVariantList &out);

	// FUN_0085af56(329B,0026.c:51580)**TransferBar 懒建**(非 QuickBar):
	//   +0xe8 引用计数数据空 || +0xf0 宿主空 →
	//     bar = new 0x58 + FUN_005858fe(this)(TransferBar ctor)→
	//     存 +0xe8(ExternalRefCountData)/+0xf0(宿主)→
	//     connect(bar, 信号 **TransferBar_h8f1b18** → 闭包 impl
	//       **s_TransferPane_857528**,flags = **2**,smeta 011967a0)→
	//   末尾 `s_SearchPane_85a7a6(this, 宿主)`(与搜索面板联动)。
	void ensureTransferBar();
	QObject *m_transferBarF0 = nullptr;  // +0xf0(TransferBar 宿主)
	QString m_quickBarName;      // +0xd8
	QWidget *m_quickBarHost = nullptr; // +0xe0
	QStringList m_quickBarItems; // +0xe0 宿主的 +0x68 表(承接)
	// +0x31 ctor 同 WORD 高字节;深段(008d2f7e 选择行为腿)消费,本波不读。
	quint8 m_flag0x31 = 1;
	// +0x38..+0x50 四 QSplitter(QWidget*0):
	//   operator_new(0x30)+QSplitter ctor @0x8cd08b/0x8cd0a6/0x8cd0c1/0x8cd0dc。
	QSplitter *m_split0x38 = nullptr;
	QSplitter *m_split0x40 = nullptr;
	QSplitter *m_split0x48 = nullptr;
	QSplitter *m_split0x50 = nullptr;
	// +0x58..+0x68 三 Splitter 子类(0x38 字节):operator_new + 
	//   Splitter::Splitter(QWidget*0) @0x8cd0f7/0x8cd112/0x8cd12d。
	Splitter *m_split0x58 = nullptr;
	Splitter *m_split0x60 = nullptr;
	Splitter *m_split0x68 = nullptr;
	// +0xa0 懒建状态件(0x20 字节;ctor FUN_006741a0:
	//   +0x00 QList(shared_null)/+0x08 &DAT_011c5118(共享常量,cited)/
	//   +0x10 int=2/+0x18 同上)。ensureStateA0 = FUN_008c9fc2(55B):
	//   +0xa0 非空直返,否则 new+ctor。
	struct StateA0 {
		QList<void *> list; // +0x00
		void *p8 = nullptr; // +0x08
		int i10 = 2;        // +0x10
		void *p18 = nullptr; // +0x18
	};
	void *m_fA0 = nullptr; // +0xa0
	void ensureStateA0();
	// +0x88 当前视图缓存(FUN_008cabee 首读;ctor 清零)。
	QWidget *m_f88 = nullptr;
	// FUN_008cabee(49B,0028.c:12130)当前视图:
	//   +0x88 非空 → 直返;否则 g = currentPaneGroup() →
	//   FUN_008bca9e(g,1)(= MuxPaneGroup::currentView(true))。
	QWidget *activeView();
	// FUN_008cad6a(237B,0028.c:12262)焦点收敛:
	//   w = activeView();空 → 0;w->activateWindow();父链找 cast 011ab930
	//   (KitDock)→ FUN_008d9764(dock) 内层页 → setFocus(3);无 dock →
	//   w->setFocus(3);返回 1。
	bool focusActiveView();
	// FUN_008cb0c0(24B)/FUN_008cb0a0(31B)dock 尾刷新:
	//   focusActiveView() 失败 → g = currentPaneGroup() 非空 →
	//   FUN_008b9838(g)(找 0119aec0 子件 → FUN_00548630(w,1),cited)。
	void refreshAfterDockChange();
	// FUN_008b9838(79B,0027.c:76771):group 下 findChild<0119aec0>
	//   (递归=1;语料类型即 BreadCrumb — 00548630 的 +0x30 编辑件面同相)
	//   非空 → FUN_00548630(child,1)(= setCrumbsActive(true))。
	void activateCrumbsOf(QWidget *group);
	// +0x80 当前页组缓存(FUN_008ca6ca 首读;ctor 清零 @0x8cc70x)。
	QWidget *m_f80 = nullptr;
	// FUN_008ca6ca(170B,0028.c:11922)当前页组:
	//   +0x80 非空 → 直返;否则 QApplication::focusWidget() 上溯
	//   cast 011ab130(MuxPaneGroup/KitGroup 同址 +0x38 TabGroup);
	//   无 → findChild<011ab360>(+0x48,递归)。
	QWidget *currentPaneGroup();
	// +0x70 BYTE=1(ctor movb $0x1,0x70 @0x8cc6f8)— 槽 8 的 splitter 选择位:
	//   1 → +0x68,否则 +0x60(008ca0de 0x8ca0f5 cmpb/cmovne 实读)。
	quint8 m_flag0x70 = 1;
	// vtable 槽 62(+0x1f0)纯虚;子类实现:EditorWindow 0x5e97d2 /
	//   TerminalWindow 0x858fce(懒单例容器 + FUN_008aa896 校验尾)。
	//   返回 = Config 系单例(批 140 定案:Editor 腿 CEditorConfig 单例
	//   FUN_005df8d6 / Terminal 腿 CTerminalConfig 单例 FUN_00809d78,两
	//   单例 IS-A CGlobalConfig 基,src/Editor/CGlobalConfigFace.h 头注);
	//   K 效消费面 FUN_00692ef0 只触 +0x28/+0x38 → face 即 CGlobalConfigFace
	//   字段面(批 133 头注风险条款兑现)。
	virtual CGlobalConfigFace *menu() = 0;
	// ── 装配腿虚槽(批 192;调用点 = 008d3cc2/008c9ee4,asm 取证)────────
	// +0x210:非默认实现才调用(cmp 目标 FUN_008c99b6 = 1 字节 ret)——
	//   本类默认 no-op 与之同相 @0x8d3cf0-0x8d3de5。
	virtual void kitAssembleHook() {}
	// +0x208:startupSessions 失败腿 @0x8d3db9;默认实现未取证 → cited 空体。
	virtual void kitAssembleFailHook() {}
	// +0x250:装配尾必调 @0x8d3dc5;默认实现未取证 → cited 空体。
	virtual void kitAssembleFinishHook() {}
	// +0x218:菜单栏角落件 @0x8c9f3e;默认实现未取证 → cited nullptr。
	virtual QWidget *kitCornerWidget() { return nullptr; }
	// +0x1d0:栏可见性槽(名,bool)@0x8d34c3/0x8d350e/0x8d356c;默认实现
	//   未取证 → cited 空体(Editor/Terminal 腿各自真身化)。
	virtual void kitSetBarVisible(const QString &name, bool visible)
	{
		Q_UNUSED(name);
		Q_UNUSED(visible);
	}
	// FUN_008d3cc2(296B,0028.c:17649)延迟装配门 → KitWindowAssemblyFace.cpp
	void kitWindowAssembleDeferred();
	// s_kit_startupSessions_8d2f7e(3122B,0028.c:17278)恢复分发真身(批 237):
	//   gate → 空负载 → magic(0xb9e7e615 旧格式门)→ splitter 段 →
	//   states 段 → bars 段(0xb9e7e621 门)→ 尾钩 0x240(cited)。
	bool kitWindowStartupSessions(const QByteArray &history, int hints);
	// FUN_008ce8f6(1347B,0028.c:14741)旧格式恢复(< 0xb9e7e615):
	//   同三槽结构(FUN_008d7840 [+0x38,+0x40,+0x50])→ 逐 splitter
	//   >>int 页数 → 逐页 >>BA → kitDockRestorePage(89d860+8b881c+addWidget)。
	//   旧帧尾部差异段未逐句核对 → cited 注记。
	bool kitStartupSessionsLegacy(const QByteArray &payload);
	// s_kit_startupSessions 尾段(栏可见性,0028.c:17450 域)→ cpp
	bool kitWindowBarsRestore(const QByteArray &frame, quint32 magic, quint32 flags);
	// ── 槽位访问族(批 198;id 字面 1/2/8 = asm 立即数)───────────────
	//   1 → +0x38 / 2 → +0x40 / 8 → +0x50(三 QSplitter 槽);
	//   id 1·2 经 +0x58 的 index 0·2 取用,id 8 经 +0x68/+0x60 的 index 1,
	//   与 008cd068 中央树子序 [+0x38,+0x60,+0x40] 自洽。
	QSplitter *kitSlotSplitter(int id);            // 008ca096(33B)
	int kitSlotIdOf(QWidget *widget);              // 008ca0b8(37B)
	bool kitSlotVisible(int id);                    // 008ca0de(65B)
	void kitSlotSetVisible(int id, bool visible);   // 008ca120(72B)
	void kitSlotHide(int id);                       // 008ca168(7B)
	void kitSlotShow(int id);                       // 008ca170(10B)
	// 008ce100(244B,0028.c:14347)展开/收起:splitter = (+0x70==1 ? +0x68 :
	//   +0x60);on==0 → showIndex(0)@008ce1xx;否则 hideIndex;随后
	//   +0x50 下 findChildren<KitDock> 逐个同步展开钮(008b8c68 13B →
	//   s_ExpandButton_5ab32a 584B cited)。
	void kitSetSlotExpanded(bool expanded);
	// 008ca17a(110B,0028.c:11586)子件槽恢复:子件父级为 QSplitter →
	//   kitSlotIdOf + kitSlotShow(信号 arg 为 false 腿才执行)。
	void kitRestoreSlotOfChild(QWidget *child);
	// 008ca17a(110B)槽体:浮停变更信号(bool)——arg 非 0 直返;
	//   sender(cast 011aaed0)非空 → kitRestoreSlotOfChild(sender)。
	void kitOnDockFloatChanged(bool floating);
};
