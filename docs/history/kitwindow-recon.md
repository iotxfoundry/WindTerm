# kitwindow-recon — KitWindow 承载面侦察(批 131,M7-②)

> ⚠ 2026-11-16:`tests/` 已删除(用户令),
> 本文中"ctest 通过"类判据**不再适用**;本文转为历史方案书,结论引用前查 `tools/re/handoff.md` 勘正谱系。

> 侦察批:只侦察不转写产品码。产出 = 方案书,供后续转写车道**免侦察直接执行**。
> 语料根:tools/re/decomp/decomp-part-NNNN.c(行号即 `grep -n "entry=…"` 落点);
> vtable/typeinfo 为 WindTerm ELF .data.rel.ro / .rodata 实读(kuna read / readelf -rW)。

## Q1 类边界:ctor、vtable、体量、成员字段清单

### 1.1 构造器与继承链
- **KitWindow 基类子对象 ctor = FUN_008cc692(214B,decomp-part-0028.c:13331,asm 0x8cc692-0x8cc76c)**:
  `QMainWindow::QMainWindow(this,parent,0)` → 写 KitWindow 双 vptr(+0=0x11ab3b8 主 / +0x10=0x11ab620 QPaintDevice 副)→ 字段初始化(见 1.4)→ 尾 `QWidget::setAcceptDrops(true)`(try 008cc75c-60)。
- **KitWindow 是抽象类**:vtable 槽 62(menu())= `__cxa_pure_virtual`(0xbec350 实证);D1/D0 槽(@0x11ab3d0/0x11ab3d8)= 0(无重定位,抽象基惯例)。**零直接构造调用点**(全 .text 无 `0x11ab3b8/0x11ab620` 立即数装载;ctor 唯二调用者 = 两个子类 ctor,见 Q4)。
- 子类(均为 MainWindow +0x58 QStackedWidget 页):
  - **EditorWindow**:ctor s_EditorWindow_5e96ac(187B,decomp-part-0019.c:22692)先调 FUN_008cc692 再覆 EditorWindow vptr(0x119ee38 族);`operator_new(0xd0)`;objectName="EditorWindow";dtor deleting 0x5e979c(delete 0xd0)。
  - **TerminalWindow**:ctor s_TerminalWindow_859902(296B,decomp-part-0026.c:50716)先调 FUN_008cc692,再 +0xb8 落 QAbstractNativeEventFilter 基(0x11a7f48),覆 TerminalWindow vptr(0x11a7c88 族);`operator_new(0x110)`;objectName="TerminalWindow";尾 `movb $0,0x31(%rbx)`(清 KitWindow 置的 +0x31=1)。
- 语料命名勘误候选:decomp `KitWindow_dtor`(0x8fc56e,66B)实为 **EditorWindow::qt_metacast**(strcmp "EditorWindow" → 转 s_KitWindow_91d250);真 KitWindow metacast = 0x91d250。

### 1.2 vtable / typeinfo 实测(.data.rel.ro VA 0x117eba0=file 0xb7eba0)
- KitWindow typeinfo 对象 @**0x11ab390** = {si_vptr 0x11b1c00, name "9KitWindow"(0xce6b00), base _ZTI11QMainWindow@Qt_5(reloc 落 0x11ab3a0)}——decomp `PTR_PTR_011ab390` 即指此(与 MuxPaneGroup.cpp 注记一致)。
- 主 vtable 组:offset_to_top @0x11ab3a8=0,TI 槽 @0x11ab3b0=0x11ab390,**vptr = 0x11ab3b8**;QPaintDevice 副组 TI @0x11ab618,**副 vptr = 0x11ab620**。
- 槽位(主 vptr 起,`+0x…` 为 vptr 偏移,即 vcall 偏移):

| slot | vptr+off | KitWindow 值 | 语义 |
|---|---|---|---|
| 0 | +0x00 | 0x91b180 | metaObject → staticMetaObject **0x11ab660** |
| 1 | +0x08 | 0x91d250 | qt_metacast("KitWindow",strcmp @0030.c:12973) |
| 2 | +0x10 | 0x91d292 | qt_metacall(≤0x6f=111 方法 → 体 0x91b3d6 7801B,0030.c:12993) |
| 3/4 | +0x18/+0x20 | 0 | D1/D0(抽象基,零 reloc) |
| 5/6 | +0x28/+0x30 | 0 / 0x8d54e0 | event=0(abstract 态)/ **eventFilter 0x8d54e0(1805B,SuperApplication_vt6 内调 @0x76240d,组件 wheel 事件过滤)** |
| 17 | +0x88 | 0x8d3e0e | setVisible 门(sub_8d3cc2 前置钩) |
| 33 | +0x108 | 0x8d51e6 | (TerminalWindow 0x85d326 消费链;`+0x12&4` 门) |
| 53 | +0x1a8 | pure | EditorWindow 0x5ea806 / TerminalWindow 0x85a442 |
| 54 | +0x1b0 | pure | 0x5ea91a / 0x85a5be |
| 55-61 | +0x1b8..+0x1e8 | 0x8ca332/0x8cdffa/0x8ca604/0x8cfa86/0x8d0676/0x8d4c70/0x8d1476 | pane 查找族:0x8cdffa=findChildren(KitPane MO **0x11ab100**)/0x8ca604=pane 索引链(008ca23e+008a0d7c+008c39de)/0x8d4c70 布局读/0x8d1476 列表读 |
| **62** | **+0x1f0** | **pure(__cxa_pure_virtual 0xbec350)** | **menu()——showConfigMenu 唯一虚消费点**;EditorWindow 0x5e97d2(懒全局 0x11c12e0←FUN_005df8d6)/TerminalWindow 0x858fce(懒全局 0x11c2200←**FUN_00809d78**=CTerminalConfig 单例族,AGENTS 注册表同址)——两者尾均 FUN_008aa896(78B,0027.c:64033,四 vcall AND 校验)后返回容器 |
| 63/64 | +0x1f8/+0x200 | 0x8c99b0(ret1)/0x8bebde(ret0) | TerminalWindow 覆 0x85cafa/0x85b4aa |
| 65 | +0x208 | 0x8cb89a | QSplitter::addWidget(sub_89f516(this,+0x31 byte))——读 **+0x48** splitter 槽 |
| 66-73 | +0x210..+0x248 | 0x8c99b6/0x8cbffe/0x8d23ee/0x8cb8b4/0x8d1208/0x8d1014/0x8d5bee(ret1)/0x8d5bf4(void) | 布局/视图族(转写批逐条定名) |
| 74 | +0x250 | pure | 0x5ea2fe / 0x85a384 |

- QMetaObject:qmo_extract 权威——**111 方法(98 槽 + 13 信号)**;信号:doSearch(2)/muxPaneGotFocus(1)/muxPaneLostFocus(1)/viewActivated(1)/viewAdded(1)/viewChanged(1)/viewClosing(1)/viewClosed(1)/viewDiscarded(1)/viewGotFocus(1)/viewLostFocus(1)/viewRemoved(2)/viewStateChanged(2);信号发射体 FUN_0091b198..(staticMetaObject 0x11ab660,idx 0..12,0030.c:11436 起)。onOptionChanged(QByteArray,QVariant) lambda 四连(0xcba140 符号族,menu 容器侧)。

### 1.3 体量
- **sizeof(KitWindow) = 0xb8**:基类 deleting dtor FUN_008cc7d2(23B,0028.c:13392)尾 `operator_delete(this,0xb8)`;EditorWindow=0xd0(+0x18),TerminalWindow=0x110。

### 1.4 成员字段清单(ctor FUN_008cc692 写面 + dtor FUN_008cc770 92B(0028.c:13364)消解面)

| 偏移 | 型(证据) | 语义 |
|---|---|---|
| +0x30 | WORD=0x0101(movw @0x8cc6ba) | 双 BYTE:+0x30=1、+0x31=1(TerminalWindow ctor 尾清 +0x31=0;+0x31 被 vtable 槽 65 消费) |
| +0x38..+0x68 | 7×qw=0 | 槽位族(vt65 读 +0x48 = splitter;其余转写批定名) |
| +0x70 | BYTE=1 | 状态门(FUN_008cc84e 184B,0028.c:13430:save/restore sizes 门槛,写侧更新) |
| +0x78..+0x90 | 4×qw=0 | 槽位族 |
| +0x98 | QList(QListData::shared_null,mov @0x8cc725) | dtor FUN_008d60a0(+0x98) detach 清偿 |
| +0xa0 | ptr=0 | dtor:FUN_00674550(p)+operator_delete(p,0x20)——0x20B 子对象 |
| +0xa8/+0xb0 | qw=0 | FUN_005df958(0019.c:15761)读 **+0xa8 QList**(menu 容器侧遍历) |

## Q2 showConfigMenu(s_MuxPaneGroup_8de2d4)对 KitWindow 的消费清单(只列不建模)

全链 asm/decomp 已读(s_MuxPaneGroup_8de2d4 214B @0028.c:25588;FUN_006926a0 34B @0021.c:18550;FUN_00692ef0 310B @0021.c:18914;FUN_005ac790 275B @0018.c:26415):

1. **类型身份**:父链上溯 `dynamic_cast<KitWindow>`(PTR_PTR_011ab390)@008de2f1-30f;未命中直返 @008de319。
2. **虚调用 menu()**:+0x1f0(槽 62)取菜单容器 @006926a0(容器=懒单例对象,非 KitWindow 实例字段)。
3. **容器操作** FUN_00692ef0(容器,QByteArray("MuxPaneGroup"),pane):容器 **+0x28 QList** 查/建 QMenu(FUN_006926c2 164B @0021.c:18568 memcmp 键匹配;未命中 → QMetaObject::tr(name) + operator_new(0x30) QMenu 新建 @00692fbf)。
4. **按钮弹层** FUN_005ac790(pane+0x38,"ConfigButton",menu):findChild<QToolButton*>(smo)→ setAutoRaise(false)@005ac81f → QPoint(0,btn->width()+1)@005ac802-16 → mapToGlobal → QMenu::exec(pos,nullptr)@005ac83c → setAutoRaise(true)@005ac849 → new QEvent(Leave 0xb)+postEvent(btn)@005ac84e-70。

**KitWindow 实例字段被读数 = 0**(仅类型身份 + 一记纯虚调用;容器/按钮均非 KitWindow 数据成员)。

## Q3 最小承载面方案书(照 MainWindowFace 判例;转写车道照此执行,免再侦察)

**判定**:四槽判定(批 106)三槽落 MuxWindow,唯 showConfigMenu 动态类型是 KitWindow(抽象基,页容器家族根)——不可借道 MuxWindow;照 MainWindowFace 先例落**宿主语义壳**。

### 步骤 1:src/Actions/KitWindowFace.h(新,声明壳;零 .cpp 行为体)

```cpp
#pragma once
#include <QMainWindow>
class QMenu;
// KitWindowFace —— 语料 KitWindow(011ab390)承载面壳(MainWindowFace 判例批 100;
// 铁律 6:抽象身份 + 纯虚 menu();showConfigMenu 消费清单 = 零字段 + 一虚调用,
// 见 docs/history/kitwindow-recon.md Q2,故不落数据成员,布局证据在案待后续批)。
// ctor/dtor 对位 FUN_008cc692(214B,0028.c:13331)/FUN_008cc770(92B,0028.c:13364)。
class KitWindowFace : public QMainWindow {
public:
    explicit KitWindowFace(QWidget *parent = nullptr);   // FUN_008cc692(QMainWindow(parent,0)+setAcceptDrops(true))
    virtual ~KitWindowFace();                            // FUN_008cc770(cited 基类清偿)
    // 语料 vtable 槽 62(+0x1f0)纯虚;子类实现:EditorWindow 0x5e97d2 /
    // TerminalWindow 0x858fce(懒单例容器 + FUN_008aa896 校验)。
    virtual QMenu *menu() = 0;                           // cited — 抽象,无体
};
```

要点(车道执行细则):
- **不加 Q_OBJECT**:四槽判定只走 menu() 虚调用,无信号/槽接续(坑 14/19 规避);qmo 111 方法清单留给 EditorWindow/TerminalWindow face 批。
- ctor 真身仅两句:`QMainWindow(parent, Qt::WindowFlags(0))` + `setAcceptDrops(true)`(语料尾 try/catch 包裹,Qt API 直调非自研);字段不落 → 无清零面。
- dtor = cited(FUN_008cc770 消偿 +0xa0/+0x98,本壳无字段则体 = 虚 ~ + QMainWindow 析构,注记即可)。
- **vtable 槽 53-74 对位声明不在本壳做**(22 虚函数零消费,声明了即自造 ABI 面;menu() 在我们自有类中的槽位由 C++ 自洽,无需复刻 +0x1f0 绝对偏移——跨类一致性由「showConfigMenu 与 face 同库编译」保证)。

### 步骤 2:src/Actions/MuxPaneGroup.cpp — showConfigMenu 升真身

```cpp
void MuxPaneGroup::showConfigMenu()
{
    // S1:qcoreapp_self_get() 值弃 @008de2e1
    KitWindowFace *kit = nullptr;
    for (QWidget *w = this; w != nullptr; w = w->parentWidget())
        if ((kit = dynamic_cast<KitWindowFace *>(w)) != nullptr) break; // @008de2f1-30f(011ab390)
    if (kit == nullptr)
        return;                                                          // @008de319(直返,无菜单操作)
    QMenu *container = kit->menu();                                      // FUN_006926a0 @008de331(+0x1f0 槽 62)
    // S2:FUN_00692ef0(容器,QByteArray("MuxPaneGroup"),this)@008de33b-57:
    //   容器 +0x28 QList 查(FUN_006926c2 memcmp 键)→ 未命中 tr(name) 新建 QMenu(operator_new 0x30)
    QMenu *menu = kitFindOrCreateGroupMenu(container, QStringLiteral("MuxPaneGroup"), this); // 转写 0021.c:18914
    // S3:FUN_005ac790(+0x38,"ConfigButton",menu)@008de389:
    //   findChild<QToolButton*>("ConfigButton")→setAutoRaise(false)→exec(mapToGlobal QPoint(0,w+1))
    //   →setAutoRaise(true)→postEvent(Leave) — 注记全读,MuxPaneGroup.cpp 239-263 行在案
    kitPopupConfigButton(this, menu);                                    // 转写 0018.c:26415
}
```
- `kitFindOrCreateGroupMenu` / `kitPopupConfigButton` = FUN_00692ef0(310B,0021.c:18914 + 006926c2 0021.c:18568)/ FUN_005ac790(275B,0018.c:26415)逐句转写,**文件头 fwd: 区前向声明**(坑 3);tr 取串走 QMetaObject::tr 汇合腿(照 renamePane 判例)。
- S3 需 pane+0x38 槽位——对照 MuxPaneView 既有建模,无则按 FUN_005ab316/008de3b2(0028.c:25611)currentPane 链取,缺口 cited 不发明。
- 239-256 行旧注记保留案例标签(s_MuxPaneGroup_8de2d4),cited 块替换为上体;**case 标签注释绝不删**(坑 13)。

### 步骤 3:验证门
worktree `cmake -S . -B build && cmake --build build -j && ctest` 19/19 + dlopen OK;KitWindowFace 无 moc 新类(Q_OBJECT 缺席)→ 零 moc 面。

## Q4 ctor 接线点(grep 语料实证)

- KitWindow 本体零构造点(抽象)。**子类构造唯一工厂 = FUN_0089d752(246B,decomp-part-0027.c:55302)**:
  `name=="Editor"` → operator_new(0xd0)+s_EditorWindow_5e96ac;`"Terminal"` → operator_new(0x110)+s_TerminalWindow_859902;`"Buy"`(DAT_00d0eaa4)→ operator_new(0xd0)+s_EditorWindow_5e96ac;其余 → nullptr。
- 工厂唯一调用点 = **s_HistoryHints_7664a2(244B,decomp-part-0023.c:33200)@asm 0x7664c7**:工厂产物 setProperty×2 → **QStackedWidget::addWidget(mainwin+0x58)**(+0x58 = MainWindowFace::Slots::f58,批 100 已落库)→ param_3 时 setCurrentIndex → FUN_008b346e(KitBar +0x50,index,…)。
- s_HistoryHints 调用点:0x766603(FUN_007665ae,"Terminal" 首页)与 0x766dd6(页开路径二);FUN_007665ae ← 0x75e519。
- **接线结论**:KitWindowFace 挂 **src/Actions/(MainWindowFace 旁)**——接线动作 = MainWindow 宿主批落库时,在 stack(f58)页插点调用 face 子类工厂(对位 FUN_0089d752);**不挂 EditorEngine/主控**(EditorEngine = 编辑引擎宿主,非窗口宿主;无任何窗口构造调用面)。转写车道只需落 face 壳 + showConfigMenu,工厂/页插属 MainWindow 宿主批写域。

## 证据索引(免再 grep)

| 项 | 地址 | 语料落点 |
|---|---|---|
| KitWindow ctor | FUN_008cc692 214B | 0028.c:13331(asm 0x8cc692-0x8cc76c) |
| KitWindow dtor / deleting | FUN_008cc770 92B / FUN_008cc7d2 23B(delete 0xb8) | 0028.c:13364/13392 |
| metaObject / metacast / metacall | 0x91b180 / 0x91d250 / 0x91d292(→0x91b3d6 7801B) | 0030.c:12973/12993 |
| typeinfo "9KitWindow" | 对象 0x11ab390;主 vptr 0x11ab3b8;副 vptr 0x11ab620 | .data.rel.ro 实读 |
| staticMetaObject | 0x11ab660(metacall 0x91b3d6;111 方法) | qmo_extract / 0030.c:11436 |
| eventFilter | 0x8d54e0 1805B | SuperApplication_vt6(0023.c:29626)@0x76240d 调 |
| menu() 槽 62 纯虚 | 0xbec350(__cxa_pure_virtual) | vtable 实读 |
| EditorWindow ctor / menu | s_EditorWindow_5e96ac 187B / 0x5e97d2 | 0019.c:22692 / — |
| TerminalWindow ctor / menu | s_TerminalWindow_859902 296B / 0x858fce(FUN_00809d78 单例) | 0026.c:50716 / AGENTS 注册表 |
| 工厂 | FUN_0089d752 246B | 0027.c:55302(唯一调用 0x7664c7) |
| 页挂 | s_HistoryHints_7664a2 244B | 0023.c:33200(+0x58 stack/+0x50 KitBar) |
| showConfigMenu 链 | 008de2d4 214B / 006926a0 34B / 00692ef0 310B / 006926c2 164B / 005ac790 275B | 0028.c:25588 / 0021.c:18550/18914/18568 / 0018.c:26415 |

## 未解(如实登记,不猜)
1. menu() 容器对象的确切类型/类名:TerminalWindow 腿返回 FUN_00809d78 单例(AGENTS 记 CTerminalConfig 地址)却作菜单容器被 FUN_00692ef0 消费(+0x28 QList)——容器类建模与 tr 归属待转写批读 FUN_008a99de/FUN_008aa39e/FUN_00809b90(432B,0025.c:43201)后定。
2. vtable 槽 55-74 逐槽命名(仅列地址与可读摘要);槽 5(event)=0 的抽象基语义(不可实例化类不触发)未深究。
3. FUN_008cc84e(save/restore)+0x60/+0x68 键串与 +0x50 的序列化面(将来布局批写域)。
