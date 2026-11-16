# PHASE 5 — 离屏行为对比(v1 战果与方法)

> 目标:重建行为 vs 原二进制行为,同字节序列逐格对比。
> 工具链:Xvfb(:99)+ xdotool(自动化原版)+ Python frida(附加注入)
> 驱动:tools/re/phase5/phase5_drive.py(spawn 版)/ phase5_attach.py(attach 版)

## 结论快照(截至批 493,2026-11-16 — 当前真值层)

> **读法**:本节为当前真值;下方批次流水(批 20-341 + 阶段段 192-493)为审计轨迹,
> 保留全部历史结论原样。**冲突时以本节与 tools/re/handoff.md
> 「勘正谱系」表为准**(九条勘正链已在谱系表显式化)。

### 里程碑状态(二十四项 + M8 文档整备全部达成,定义见 handoff 总账)

M1 编辑器搜索链闭环(116b)→ M2 残项清零(117/118)→ M3 vtable
清偿 + 5b 通道/构造(119/121/122)→ 5b 终局(123)→ M4 RUBY 终裁 +
扩谱首批(124/125)→ M5 扩谱二批 + scanMask 活性(126/127)→ M6
initDoc 零点 + transient 根治 + 扩谱三批(128/129)→ M7 扩谱四批 +
KitWindow 方案书(130/131)→ M8 文档整备(单页当前态/快照/谱系)→
M9 巨 switch WT 段全清 + KitWindowFace(132/133)→ M10 工厂接线 +
eNodes 侦察方案书(134/135)→ M11 eNodes 建模 + 扩谱五批 EXT 段
(136/137/**136b 布局勘正**;W 族 13/20;键型勘正 int;16 条
static_assert 偏移锁)→ **M12 四车道:eNodes W 族收尾 19/20 + 应用族
真身(138)/EXT 叶全清 34 条(139)/CGlobalConfigFace + menu() 容器型
定案(140)/4a 注册表 Logger 插入侧(141)** → **M13 三车道:KitWindow
宿主接线 + yaml 装载腿 + 双 Meyers 合一(142)/W 尾 inner 词法面 +
0x7545 真值路径开通(143)/注册表余量 Term·Transfer 插入侧(144;
四表插入侧全定案)** → **M14 五车道:注册表面余量(145)/eNodes 深层
(146)/Config 树深下钻(147;configPath 勘正"/")/SplitterGroup 余项
(148;差集 7 项真身 3 定案 4)/启动链对位接线(149)** → **M15 四
车道:恢复腿 0075ffcc→00766c26 真身 + wind.config 默认层(150)/
注册表下行 spdlog 委托面 + Transfer 状态机(151)/eNodes 词法重建
(inner 非恒 null,152)/MuxWindow 归辖取面(153)** → **M16 四车道
(分段式):工作区装载器 522056 定面 + startupSessions 分发腿(154)/
token 引擎真库委托 + 协议虚面(155)/深引擎底座头改版最小集
DeepEngineFace(156)/MuxWindow 宿主 0084dd5a 分段复刻(157)** →
**M17 四车道:宿主深腿 + splitter 段消费(158;旗标布局实读定案)/
522056 收集器 + 扫描深腿(159)/深引擎 ODR 激活(160)/自有 token 腿
+ state 下行 + TcpBridge 生产 face(161)** → **M18 四车道:MuxWindow
深腿尾清(S4-S6 表值/restorePaneSplitter A-E/宿主比较器;旗标不升
定案维持;162)/trie 键值域 + 掩盖腿 + 挂页槽(163)/vt 槽承载 + 清偿
臂升真(164)/%A..%z 渲染 + connectImpl 分段(165)** → **M19 五腿
(5c 转向):持久化全景盘点(explorer)/可运行应用骨架 appboot(166;
**ctest 21→22**)/reopen.history 保存侧 StateStore + roundtrip
(167;**statereopen 注册,22→23**)/kit.startupSessions 写端 +
profiles.config 写侧(169)/三件套保存侧 SessionStore 六函数(168;
**0076913f 定性 = QMetaType 注册族非写腿**)** → **M20 三车道
(5c 对表轮):reopen 原版采集 + 布局 diff 全 MATCH(170;报告
tools/re/phase5/5c/5c-report.md + tools/re/phase5/5c-report.md 双件)/wind.config
122 键盘点 + 序列化同构(171;报告 5c-report.md)/aboutToQuit
挂点闭环(172)** → **M21 四车道:页 payload 序列化升真(173;
**帧结构四段定案:魔数+blobA/blobB/blobC+尾钩,原版 674B 位级
反推**)/wind.config 复合缺口 + 样本对表(174;**122 键 117 标量
全覆盖·0 值型错配;原版 49 条目×24 键全标量框架逐项同相**)/
MuxWindow 尾清(175;**比较器微差实测同相闭环**)/深引擎 + 注册表
尾余合并腿(176;hash remove/三 delegate 槽/RS 灌链真身)** →
**M22 三车道:blobA splitter/tabbar 树实体真身(177;229B 段逐
字段位级反推 3 splitter 结构)/排序真身 + rehash 承接(178;
introsort = std::sort 实例化定性)/SuperApplicationFace 骨架
(qt_metacall 分派 case3/4/5 真身转发,179)**。 → **M23 四腿
(5c 冲刺+尾渣):reopen 全帧对表执行 14 项帧级 MATCH(180)/trie
分裂门真身 + 星数逐字节 + **键串勘正 "tab."→"tabbar."**(181)/
searchEngines 消费链 + **75e56a 定性翻转 = TextView::searchOnline**
(184)/深引擎尾渣(超门分段族收账/rehash 真库定性/RS 灌链余段
升真 2 段,183)**。 → **M24 五腿(界面重建转向,铁律 7 首轮):
GUI 重建范围地图(explorer,gui-map.md 落库)/主窗创建族全文转写
(188)/menu.config 菜单装载腿 + 菜单树消费真身(189)/toolbar_build
工具栏族转写(190)/设置壳 + 分类树转写(191)**。⚠ 铁律 7 生效
(不编译不测试):M24 新码(ToolBarBuilder/SettingsFace/菜单装载/
appboot 扩展)未过编译门,语法/链接雷留收尾期,出处链逐行已落。

### 编辑引擎子系统当前真值

| 面 | 状态 |
|---|---|
| c1c2 内层(0x7576) | 真身(thunk p4/p5/p6=0/0/i 勘正后);T 段真身 + 位面写;残:busy 腿(外库登记)/入口 0095c086(外库边界面坍缩)/p4==2 busy 位(同) |
| M 修改行跟踪器 | ModTrack.h 全建模:读侧七函数/写侧 b152·b15e/位面机 flagmaskSetRange/两段容量机;游程支 RS 合并腿测试装置承载;迁移腿外库登记 |
| markerBand(00927a78) | 真身(经 modTrack);T 段调点已改位面(mtBit4SetClr);残:958108 ctx+0x28 已接线(批 117) |
| 0x4eff 正则搜索 | **已激活**(批 116/116b):OnigSearch 委托(onig_new RUBY 预编译 + onig_search);RUBY 语法 = 永久假设(批 124 终裁,双证伪通道封闭,零反例) |
| bufferScan 引擎 | Onigmo-改 边界委托(ext-boundary;单层针指针契约,批 116b 勘正);engVt50Block/engVt28Class 真身(批 119 转储定案) |
| scanMask | 活性接线 ✅(批 127 buffer 承载建模 + s_scanCarrier 缝;0x7543 initDoc 零接线点定案,批 128) |
| 巨 switch 扩谱 | **全清**:五批 66 + EXT 32(批 137)+ 叶 34(批 139:真身 2/cited 32,差集重 derive);0x4ec2=20162 门漏叶勘误已截获;markerstest q/r/s/t/u/v/w/x/y/z 组 |
| eNodes 节点层 | W 族 20/20 + 深层/词法重建(146/152)+ **深引擎底座头 DeepEngineFace(批 156)+ ODR/vt 槽承载(批 160/164)**:API 面 10 项(19 条 static_assert 锁)/editctxInitThread009714b6 前奏真身/**93fc60 清偿臂升真(GB 密排/spin backoff 坍缩/条目 ~RWLock+free/尾 vt 换面析构链 5328-5345)·88e5a0 门内重排体(gbShrink/gbGrow)·007b5270 骨架门·97142a 尾(123B)真身**;**inner 非恒 null**,|4 链非退化;**0x7545 真值路径开通**;余:00933738 hash remove/超门 0x3fffff 分段族/段插体 delegate 深族 cited |
| KitWindow | 抽象基类定案(menu() 槽 62 纯虚);KitWindowFactory 真身(批 134);**menu() 容器型定案(批 140)**:两腿返回 Config 系单例 → CGlobalConfigFace(基构造 FUN_008a71e4 CGlobalConfig;SharedConfig 系独立小类非基类);**yaml 装载腿真身 + 双 Meyers 合一 + kitWindowRestoreFirstPage(批 142,FUN_0075e3fe 对位)**;**树深下钻真身(批 147)**:loadGroupsElement(008a971e Action3/Menu2/Separator0 三级递归)+ loadViewsElement(s_FilterEdit 七 kind 位面/Columns 内省);configPath 勘正 = DAT_00cba75c "/" 单字符;**启动链 + 恢复腿真身(批 149/150)**:startupChain FUN_007626ce 语料序 + startupRestoreGate FUN_0075ffcc(魔数 0xb9e7e600/路径腿 reopen.history)+ startupRestoreDispatch 00766c26 分发壳(&4==0 页挂真调);wind.config 默认层 jsoncpp 委托;**工作区装载 + startupSessions 真身(批 154)**:WorkspaceLoader(522056 定面/骨架:trimmed 门/kind 位 7|3/三件套/QHash 去重)+ kitStartupSessions(kit.startupSession1-4 四槽实读)+ 建窗窄面/&4 尾段;**007626ce 挂点裁决(批 154):QTimer singleShot thunk 00762925 非信号,零数据引用,cited 维持**;522056 收集器/Editor 扫描深腿 **真身(批 159)**:collectorPaneTypeName/MuxChildren/EditorFilePaths + collectorActiveView + sessionDefaultDir(521702 参数卫/kind 分派)+ editorDirScan QDirIterator + sessionProtocolUrl(URL 拼面 SSH22/Telnet23);**宿主深腿 + splitter 段消费(批 158)**:retitleGroupPane(0084ecf0)/muxSplitterMoved S0-S3/restoreState Shim 几何腿/kitStartupSessions splitter 读游;旗标 0x58 POD = 0x2f 位旗定案 |

### 5b 行为对比终局(批 121-123)

总表 **1/21 MATCH、2 MISMATCH(仪器性)、18 NOT-RUN(通道封闭)**。
原版侧 find 注入通道不存在(memo 唯一串源,op+0x18 零消费,批 123
证伪批 122 绕行);UI 向量判死(quick-find ≠ SearchPane 三框,批 124)。
RUBY 语法假设永久化(零反例;理论备选 = SearchPane UI 自动化,未试)。


### 开放风险(现役)

1. RUBY 假设无行为级证明(见上)。
2. editor 型 doc +0xe0 承载未建模(批 122 登记);0x4e23 +0x214/
   0x4eba-c encoding face/0x4e25-28 formatter 字段族 cited(需
   EditorContext.h 头扩展)。
3. eNodes 尾余:00933738 hash remove 已真身(批 176 QHash 承载;
   rehash 定性 = QHashData::rehash 真库导入非自有面,批 183 收账)/
   88e5a0 超门 0x3fffff 分段族四成员收账入 DeepEngineFace.h 头注
   (批 183)/007b5270 门内段插体三 delegate 槽已真身(批 176)/
   97142a RS 灌链 InsertSpace+runstyles_insert_space_b 真身
   (批 176/183);styled 哨兵 UB(#32)/glibc 复址(#35)待 5c 期
   仪器裁决。
4. 注册表下行尾余:%z 时区面真库 QDateTime 承接已落(批 176,深跳表
   逐字节核对 cited)/TcpBridge dial 声明层落(批 176),真拨号行为
   不逆向;'h'/'n'/state/payload 骨架帧+blobA 树实体已真身
   (批 161/173/177)。
5. 启动链余量(Phase 4a):trie 分裂触发门已真身(批 181,容量 12)/
   星数语义已逐字节同相实证(批 181)/tabBarSelectionBehaviorOnRemove
   **键串勘正 "tab."→"tabbar."**(批 181,0xd0ed40 实读);kit.* 真键
   实机对证。
6. MuxWindow 尾余:introsort 7044B = std::sort 实例化已承接
   (批 178,标准算法不逆向判例)/008e1125 行高桥 005b86c0·vt+0x1a8
   消费 cited;宿主读侧未初始化槽 UB 原样(铁律 2);0x10 宿主接线
   (池生产者写侧)。
7. 5c 对表余项(批 180 后):**全帧对表已执行 = 14 项帧级 MATCH**
   (魔数/段序/长度构成/记录框架,批 180);余深段:blobB LastSessions
   组块写面(外框 byte-perfect 反推,句柄表定序不唯一 cited)/浮停腿
   dock_toggleFloat 866B 全读定性/尾钩 QuickBar 定性(vt+0x248)/
   页 payload 674B 深消费(8cf0c8)/blobA 实体/尾钩体/LastSessions
   组块 cited。
7. 5c 对表余项(批 180 后):**全帧对表已执行 = 14 项帧级 MATCH**
   (魔数/段序/长度构成/记录框架,批 180);余深段:blobB LastSessions
   组块写面(外框 byte-perfect 反推,句柄表定序不唯一 cited)/浮停腿
   dock_toggleFloat 866B 全读定性/尾钩 QuickBar 定性(vt+0x248)/
   页 payload 674B 深消费(8cf0c8)/blobA 实体/尾钩体/LastSessions
   组块 cited。
8. 界面重建(批 188-191,gui-map.md 总账):菜单树消费真身
   (findOrBuildMenu 1119B + King::MenuBar 575B)/menu.config 根
   **勘正 = 单 map 33 键**(旧序列腿 divergence 登记)/主窗创建族
   0075e0f8 全文 + connectSignals S1-S7/toolbar_build 00694276
   S0-S7 + case3 克隆腿/设置壳 006f1036 + 分类树 006e9cd8 + search
   布局 006f09ba;**未编译雷区**:ToolBarBuilder/SettingsFace/菜单
   装载/appboot 扩展未过编译门(铁律 7),收尾期首编译按出处链修;
   menutest/toolbartest 未注册 CMakeLists(收尾期挂接);75e56a
   定性翻转 = TextView::searchOnline(批 184,侦察疑虑证实);
   tabBarSelectionBehaviorOnRemove **键串勘正 "tab."→"tabbar."**
   (批 181,0xd0ed40 实读)。

## 阶段段与批次流水

> 批 342-493 收官段与批 20-341 历史流水已拆出 →
> **`docs/history/phase5-log.md`**(审计轨迹;结论以本文件顶部快照 +
> `../tools/re/handoff.md` 勘正谱系为准)。
