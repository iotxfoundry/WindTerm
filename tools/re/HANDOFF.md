# 新会话起点(交接文档 · 单页当前态)

> 用途:新会话冷启动。冷启动顺序:AGENTS.md → 本文件 → docs/PLAN.md →
> docs/PHASE5.md(**顶部「结论快照」节 = 当前真值,正文批次流水为审计
> 轨迹,冲突时以快照为准**)→ docs/QUIRKS.md。
> 本文件 2026-11-14 重构:旧 24 层堆叠交接删除(历史在 git log,
> 检索关键词"第 X 次交接");永续内容(环境/恢复/提交规范)保留。

> 目标:编译出与 /opt/WindTerm_2.7.0/WindTerm 行为一致的程序。

## 一句话状态(2026-11-16 第四十次交接,批 190 · M24 达成 · 界面重建转向)

**M24「范围地图 + 主窗族 + 菜单装载 + 工具栏 + 设置壳」达成(用户
定,五腿语料驱动),界面重建转向起步**:①GUI 重建范围地图落库
(GUI-MAP.md 七节全枚举 + P1-P6 优先级,界面批总账)②主窗创建族
全文转写(0075e0f8 765B 全文 + connectSignals S1-S7;批 188)③
**menu.config 根勘正 = 单 map 33 键** + 菜单树消费真身(findOrBuildMenu
1119B + King::MenuBar 575B)+ **menutest 25/25 vs /opt 原版对账**
(已注册 ctest 24/24;批 189)④toolbar_build 00694276 S0-S7 + case3
克隆腿/Popup/Columns(批 190)⑤设置壳 006f1036 + 分类树 006e9cd8 +
search 布局 006f09ba(批 191)。**铁律 7 生效(不编译不测试)**:
188/189 落地于冻结前(其门 24/24 有效),190/191 未编译——雷区
出处链逐行已落,收尾期首编译修。三项勘正入档:menu.config 根单
map/75e56a = TextView::searchOnline/键串 "tab."→"tabbar."。
此前:M23(180/181/183/184)、M22(177-179)、M21(173-176)、
M20(170-172)、M19(166-169/168)、M18(162-165)、M17(158-161)、
M16(154-157)、M15(150-153)、M14(145-149)、M13(142-144)、
M12(138-141)、M11(136/137/136b)、M10(134/135)、M9(132/133)、
M8 文档整备、M1-M7。

**M23「全帧对表 + trie 尾渣 + 深引擎收账 + 消费链」达成(用户定,
四腿分段式),车道停开**:①**reopen 全帧对表执行 = 14 项帧级
MATCH**(魔数/段序/长度构成/记录框架;原版 789B 喂恢复门闭环全过;
解析器+原版切段归档;批 180)②trie 分裂触发门真身(容量 12)+ 星数
逐字节同相实证 + **键串勘正 "tab."→"tabbar."**(0xd0ed40 实读;
批 181)③searchEngines 消费链 face + **75e56a 定性翻转 =
TextView::searchOnline**(批 184)④深引擎尾渣(超门分段族四成员
收账/**rehash 定性 = QHashData::rehash 真库导入非自有面**/RS 灌链
余段升真 2 段;批 183)。主仓终门 ctest **23/23** ×5 + dlopen OK。
⚠ 主控教训再录:docs 长锚猜编三次失败 → 改 python 区段重排(锚 =
节标题,中间整体换);车道虚报/截断 155/168/171 三例同款 → 复活
硬纪律续推有效。此前:M22(177-179)、M21(173-176)、M20(170-172)、
M19(166-169/168)、M18(162-165)、M17(158-161)、M16(154-157)、
M15(150-153)、M14(145-149)、M13(142-144)、M12(138-141)、
M11(136/137/136b)、M10(134/135)、M9(132/133)、M8 文档整备、M1-M7。

**M22「blobA 树实体 + 排序真身 + SuperApplicationFace」达成(用户
定,三车道分段式),车道停开**:①**blobA splitter/tabbar 树实体
真身**(8cf0c8 段全读 + **原版 674B blobA 229B 段逐字段位级反推**:
3 splitter 结构全解;写侧从现役树只读收集;blobB 升真逐 splitter
saveState;LastSessions 组块/浮停腿/尾钩 cited;批 177)②排序真身
(0084c145 定性 = std::sort 实例化 → 语义等价承接 std::sort + 比较
器真身,标准算法不逆向判例;hash remove 分离担查 QHashData::detach
真库承接/rehash 收口;超门分段族外库边界收账;批 178)③
SuperApplicationFace 骨架(qt_metacall case3/4/5 真身转发 + 24 case
cited;aboutToQuit 挂点升 face 级;批 179)。主仓终门 ctest **23/23**
×5 + dlopen OK。此前:M21(173-176)、M20(170-172)、M19(166-169/168)、
M18(162-165)、M17(158-161)、M16(154-157)、M15(150-153)、
M14(145-149)、M13(142-144)、M12(138-141)、M11(136/137/136b)、
M10(134/135)、M9(132/133)、M8 文档整备、M1-M7。

**M21「payload 帧 + 复合缺口 + MuxWindow 尾清 + 尾余合并腿」达成
(用户定,四车道分段式),车道停开**:①页 payload 序列化升真
(8cf0c8 2233B 读体定案 = **骨架帧四段:0xb9e7e626 魔数 + blobA
splitter/tabbar 树 + blobB 旗标+states+LastSessions + blobC 三
bool + 尾钩 vtable+0x248**,原版 674B 位级反推;StateStore 腿升真
骨架帧,深段 cited;批 173)②wind.config 五复合缺口
(jsonValueToVariant FUN_00a7ecde 递归真身)+ **user.sessions 原版
样本 22863B 对表:49 条目×24 键全标量,saveSessions 框架逐项同相**
(键序差 cited;批 174)③MuxWindow 尾清(008e1125 411B T1-T7/
moveTab 升真/**宿主 S4 比较器微差实测同相闭环**;批 175)④深引擎
+注册表尾余(hash remove QHash 承载/三 delegate 槽/RS 灌链 + ptB
D1 承载型修正拆段错误雷;%z 真库承接/dial 声明层;批 176)。主仓
终门 ctest **23/23** ×5 + dlopen OK。⚠ 主控合流两次踩锚点截断陷阱
(批 171 复活交付哈希混淆/PHASE5 快照区多轮编辑错位)——docs 大段
编辑一律 python 区段重排,不再用长 oldString 猜锚。
此前:M20(170-172)、M19(166-169/168)、M18(162-165)、M17(158-161)、
M16(154-157)、M15(150-153)、M14(145-149)、M13(142-144)、
M12(138-141)、M11(136/137/136b)、M10(134/135)、M9(132/133)、
M8 文档整备、M1-M7。

**M19「5c 转向五腿」达成(用户定,盘点 + 三 fixer + 续推),Phase 5c
起步**:①持久化全景盘点矩阵(explorer;reopen 写侧 FUN_0076073a+
005dd6fc 定位/wind.config 无写者=只读对表/缺口 Top-4)②**可运行
应用骨架 appboot**(真启动链 offscreen 载体,断裂清单空;ctest
21→22,批 166)③reopen.history 保存侧 StateStore + roundtrip
(**魔数写侧实读 0xb9e7e626,读侧 0xb9e7e600 系掩码门**;statereopen
注册 22→23,批 167)④kit.startupSessions 三态写端 + profiles.config
回写侧(批 169)⑤三件套保存侧 SessionStore 六函数(**0076913f 定性
= QMetaType 注册族非写腿**;q+0x10 消费链之外的会话库变更面;批 168,
复活硬纪律收口)。主仓终门 ctest **23/23** ×5 + dlopen OK(21→22→23)。
下一步:对表驱动批(reopen 字节 diff vs 原版产物——需 Xvfb 环境
重开,sudo 步骤待用户确认)+ wind.config/三件套对表。
此前:M18(162-165)、M17(158-161)、M16(154-157)、M15(150-153)、
M14(145-149)、M13(142-144)、M12(138-141)、M11(136/137/136b)、
M10(134/135)、M9(132/133)、M8 文档整备、M1-M7。

**M18「MuxWindow 尾清 + trie 键值 + vt 承载 + 渲染引擎」达成(用户
定,四车道分段式),车道停开**:①MuxWindow 深腿尾清(S4 表值命中/S5
PanePosNode/S6 QTimer + m_f38 定案/restorePaneSplitter 903B A-E/
宿主 S4 比较器;**collectorMuxChildren 嵌套对位修正 = stack 页族
直读撤销 findChildren 兜底**;**0x10 生产者定案 + 宿主读侧未初始化
槽 UB 原样**,批 162)②trie 键值域(StrTrie 承载替/defaultDirTrie
腔真身 **kind=8 JA 直入腔腿勘正批 159 case8 面**)/掩盖腿 ×2 入
URL 面/kitStartupOpenSession 宿主槽 + tabBar 配置腿(批 163)③vt
槽承载(函数指针槽形态)+ 93fc60 清偿臂升真/析构链/重排体/骨架门/
97142a 尾真身(批 164)④渲染真库 format 承接 + TcpBridge
connectImpl 状态机面真身(批 165)。主仓终门 ctest **21/21** ×5 +
dlopen OK。⚠ 合流教训:M17/M18 两次 mwctest 组名撞车(f6)冲突解丢
闭 `}` → 陈旧二进制假阳性绿——构建门后必查退出码再录。
此前:M17(158-161)、M16(154-157)、M15(150-153)、M14(145-149)、
M13(142-144)、M12(138-141)、M11(136/137/136b)、M10(134/135)、
M9(132/133)、M8 文档整备、M1-M7。

**M17「宿主深腿 + 收集器 + ODR 激活 + token 腿」达成(用户定,四
车道分段式),车道停开**:①MuxWindow 宿主深腿(retitleGroupPane/
muxSplitterMoved S0-S3/restoreState Shim 几何腿/S4 壳级;**旗标 0x58
POD 实读定案 0x2f 位旗**)+ kitStartupSessions splitter 段读游消费
(批 158)②522056 收集器三函数/sessionDefaultDir/editorDirScan/
sessionProtocolUrl 真身 + 骨架三腿接线(批 159)③深引擎 ODR 激活
(DeepEngineFace.cpp:三调面字段面/容量门/清偿早退门;**逐槽清偿臂
定案 = vt 槽不可承载零迭代同相**;批 160)④'h'/'n' 自有 token 腿 +
SessionTokenState 0x48B 窄面 + **TcpBridge 生产 face(q+0x10 = iface
调整指针定案)**(批 161)。⚠ 合流教训:M16 车道组名撞车(f6)冲突解
丢闭 `}` → 陈旧二进制假阳性绿——构建门后必查退出码,grep 计数非零
即排查。主仓终门 ctest **21/21** ×5 + dlopen OK。
此前:M16(154-157)、M15(150-153)、M14(145-149)、M13(142-144)、
M12(138-141)、M11(136/137/136b)、M10(134/135)、M9(132/133)、
M8 文档整备、M1-M7。

**M16「工作区装载 + token 引擎 + 底座头 + MuxWindow 宿主」达成(用户
定,四车道分段式),车道停开**:①WorkspaceLoader 新落(522056 定面
骨架 + kitStartupSessions 真身四槽实读 + 建窗窄面/&4 尾段;
**007626ce 挂点裁决 = QTimer singleShot thunk 非信号,cited 维持**,
批 154)②token 引擎真库委托(applyLinePattern ③ 尾段;①段旗位集 ⊂
spdlog flags)+ **q+0x10 槽真身语义定案 = bridge 对象** →
SessionProtocolFace 虚槽 + virtualLabel 真虚调(批 155,续推腿收口)
③深引擎底座头 DeepEngineFace 落库(API 面 10 项/19 条偏移锁;
editctxInitThread 前奏真身;实现体 cited 待激活批,批 156)④MuxWindow
宿主 0084dd5a 分段复刻(9 段:真身 6/cited 3;zoom 复测 #33 再锚定;
批 157)。⚠ 批 155 首跑虚报未做 → 续推腿实做收口(主控核验)。主仓
终门 ctest **21/21** ×5 + dlopen OK。
此前:M15(150-153)、M14(145-149)、M13(142-144)、M12(138-141)、
M11(136/137/136b)、M10(134/135)、M9(132/133)、M8 文档整备、M1-M7。

**M15「恢复腿 + 注册表下行 + 词法重建 + MuxWindow 取面」达成(用户
定,四车道并行),车道停开**:①启动链恢复腿真身(startupRestoreGate
FUN_0075ffcc 魔数 0xb9e7e600 + startupRestoreDispatch 00766c26 分发
壳/&4==0 页挂真调;wind.config 默认层 jsoncpp 委托,批 150)②注册
表下行(SpdlogFace 真库委托面 null_sink 截停/Transfer attachSftp·
connectFaces 真身/virtualLabel 近面,批 151)③eNodes 词法重建
(rebuild00970850 栈面转写 → **inner 非恒 null**,|4 链非退化;
96cb3c/b6c/b84 三路复用;QUIRKS #35,批 152)④MuxWindow 归辖取面
(zoomedPane/paneByIndex 真身;宿主 0084dd5a cited 分段;批 153)。
主仓终门 ctest **21/21** ×5 + dlopen OK。
此前:M14(145-149)、M13(142-144)、M12(138-141)、M11(136/137/136b)、
M10(134/135)、M9(132/133)、M8 文档整备、M1-M7。

**M14「注册表面 + eNodes 深层 + 树深下钻 + SplitterGroup + 启动链」
达成(用户定,五车道并行),车道停开**:①注册表面余量(logger 腿体
buildLeg 真身,spdlog sink 三段 EXT-BOUNDARY cited;SessionTransfer
真对象 008ec79a 字段面;批 145)②eNodes 深层(WNodeInner +0xa8/
inner 链真身/trie 有序插入;scanner 词法重建面 cited;QUIRKS #31·32;
批 146)③Config 树深下钻(loadGroupsElement/loadViewsElement 真身;
**configPath 勘正 = DAT_00cba75c "/" 单字符**,批 140 槽内嵌串误读;
批 147)④SplitterGroup 余项(差集 7 项:真身 3/定案 4;removePage
690B asm 全读;sgtest 新建,ctest 20→**21**;批 148)⑤启动链对位
(startupChain FUN_007626ce 语料序,深度腿 cited 全登记 Phase 4a;
批 149)。QUIRKS #33·34 新登。主仓终门 ctest **21/21** ×5 + dlopen OK。
此前:M13(142-144)、M12(138-141)、M11(136/137/136b)、M10(134/135)、
M9(132/133)、M8 文档整备、M1-M7。

**M13「宿主接线 + W 尾/0x7545 真值 + 注册表余量」达成(用户定,三
车道并行),车道停开**:①KitWindow 宿主接线(yaml 装载腿真库委托
真身/双 Meyers 合一 = CTerminalConfig 私有继承 face 同址 upcast/
kitWindowRestoreFirstPage FUN_0075e3fe 对位,产品启动链无消费点 →
mwctest 级,批 142)②W 尾 **20/20 清**(96f782/96f6fe 词法门·复位)+
**0x7545 真值路径开通**(0093f7aa trie + 00a92326 varint + 非空
data 断言;96d022 runMatch 命中即止;批 143)③注册表四表插入侧
**全定案**:Logger(141)/Term FUN_007d9776/Transfer FUN_007daedc
(144)/Commander 与 Term 共体无独立原语(144 定案);SessionLogger
ctor 真身(腿体 spdlog 外库 cited)。markerstest **273 断言** fail=0;
主仓终门 ctest 20/20 ×5 + dlopen OK。

**M12「eNodes 收尾 + EXT 全清 + Config face + 4a 插入侧」达成(用户
定,四车道并行),车道停开**:①eNodes W 族 **19/20**(余 inner 词法
面 96f782/96f6fe cited)+ 0x75e4/75aa/7581/75c8/75f6 应用族真身
(批 138)②EXT 叶全清 **34 条**(真身 2/cited 32;0x4ec2=20162 门
漏叶勘误;差集重 derive 勘正"17 叶"起点,批 139)③CGlobalConfigFace
+ menu() 容器型定案(**两 Config 单例基构造 = FUN_008a71e4
CGlobalConfig,SharedConfig 系独立小类非基类**——侦察候选被 ctor
首句实读勘正;批 140)④4a 注册表 **Logger 表**插入侧
insertLoggerSession(FUN_007da228;**任务书"Term 表"判读被三源
勘正**;Term/Commander 插入侧仍挂账,批 141)。ctest 19→**20**
(reginserttest);主仓终门 20/20 ×5 + dlopen OK。
此前:M11(136/137/136b)、M10(134/135)、M9(132/133)、M8 文档
整备、M1-M7。

**M11「eNodes 建模 + 扩谱五批」达成(批 136/137/136b)**:①eNodes
建模(ENodes.h W 族 13/20;EditorContext 键型勘正 int;6 条 cited 腿
激活 + 0x754f 误接勘误)②扩谱五批 EXT 段余量 32 条(真身 6/cited 26,
17 叶登记余量)③**批 136b 主控布局勘正**:ENodeTask 虚 D1 编译器
vptr 与显式 vtbl 成员双计 +0x00 槽 → 全字段 +8 漂移(删 vtbl 成员,
runs face 语料原生 begin/end,16 条 static_assert 偏移锁);
markerstest w/x 组冲突解 + int 键 + 真对象夹具(裸缓冲析构段错误
根除)。⚠ 门盲区双踩登记:markerstest 编译失败被旧二进制 ctest
假阳性掩盖(136/137 两车道同踩)——构建门必查退出码。

**M10「KitWindowFace 工厂接线 + eNodes 侦察」达成(批 134/135)**:
①KitWindowFactory.{h,cpp} 真(工厂三分派/页挂 s_HistoryHints 全读/
menu() 腿经 CTerminalConfig 真单例,CEditorConfig cited 不发明;
mwctest d1/d2 零真窗口)②eNodes 侦察方案书(ENODES-RECON.md 245 行:
E+0x2d8 QMap **键型 char 实锤我方失配**/DocumentTask·ScanTask 字段
级清单/W1-W4 可转写族 20 函数方案)。⚠ 门教训登记:合流新 .cpp 必须
重跑 cmake configure(GLOB 坑),构建门查退出码非 grep "error"。

**M9「巨 switch 全清 + KitWindowFace 真身」达成(批 132/133)**:
①WT 段(0x7531-0x75ff)**全清零未审项**(批 132:真身 12/cited 3/
缺省空 3,除 0x75dc 定案不存在;扩谱五批累计 66 条,v 组 17 断言)
②KitWindowFace 壳 + showConfigMenu 三段真身(方案书直执,menu()
纯虚 void* 面不发明容器;真容器落库时签名或需校正,头注已记)。

- **七个里程碑 M1-M7 全部达成**(定义与达成批见下「里程碑总账」);
  Phase 5b 终局:总表 1/21 MATCH、2 MISMATCH(仪器性)、18 NOT-RUN
  (通道封闭,见「已定案边界与永久假设」)。
- 本会话批 102-131 共 **30 个实现批**(含 114b/116b 两个主控勘误批),
  ctest 从 16 → **19/19**(8 个断言组:modtracktest 17+f6·i 组 8/
  onigtest 24/engtest5 61/wordsteptest g·i 组 8/markerstest q·r·s·t·u 组
  71),dlopen OK,wordsteptest 37 连跑零失败(transient 已根治)。
- 本地领先 origin/dev 43 commit,**只提交不主动推送**。
- 环境已清:原版/Xvfb 拆除,ptrace 恢复 1(重开需 sudo,见恢复流程)。

## 里程碑总账(全部 ✅,定义均为用户终点条件)

| 里程碑 | 内容 | 达成批 |
|---|---|---|
| M1 | 编辑器搜索链闭环:0x4eff onig 委托激活/c1c2 剩余定案/M+0x28 flagmask/迁移腿裁决 | 116b/115/114+114b/111 |
| M2 | 编辑器残项清零:行槽接线真身/busy 腿边界登记/scanMask 定案 | 117/118 |
| M3 | vtable 清偿 + 5b 通道与构造(原版捕获对表部分完成) | 119/121/122 |
| M4 | RUBY 直证终局(UI 向量判死 → 假设永久化)+ 扩谱首批 9 条 | 124/125 |
| M5 | 扩谱二批 14 条 + scanMask 活性接线(buffer 承载建模) | 126/127 |
| M6 | initDoc 挂线零点定案 + transient 根治 + 扩谱三批 15 条 | 128/129 |
| M7 | 扩谱四批 14 条 + KitWindow 侦察方案书 | 130/131 |

## 已定案边界与永久假设(新会话勿重开)

- **RUBY 语法假设(永久化,批 124 终裁)**:0x4eff onig 委托以
  ONIG_SYNTAX_RUBY 预编译(批 116 五真实样例对账);两条证伪通道
  实证封闭——注入通道(memo 唯一串源,dispatch 无 find 写命令,
  批 123 op+0x18 零消费证伪批 122 绕行)与 UI 向量(quick-find ≠
  SearchPane 三框面,批 124 frida 双钩零命中)。理论备选 =
  SearchPane UI 自动化输入(未试,需 SearchPane 弹出条件侦察)。
- **外库边界登记**:busy 腿 009e975a(doc 批处理通知器 + 线程池
  底座,批 117)/迁移腿 0099bc2c(piecetable 链,批 111)/
  Onigmo-改(EXT-BOUNDARY 第一方组件,批 102 定案:00b4xxxx 停
  逆向,src/Onigmo 委托)。
- **scanMask 活性接线 ✅**(批 127:buffer 承载建模 + s_scanCarrier
  缝;残项 0x7543 initDoc 驱动挂线经批 128 定案 = **零接线点**,
  RAII 即语料挂线,FUN_0092ef06 拆建腿不含 +0xf8)。
- **KitWindow = 抽象基类**(menu() 槽 62 纯虚,showConfigMenu 消费
  = 零字段 + 一虚调用);转写车道照 tools/re/KITWINDOW-RECON.md
  方案书**免侦察直执**(批 131)。

## 勘正谱系(现结论 ← 被勘正;新会话读到旧结论先查此表)

| 现结论 | 勘正来源 | 被勘正旧结论 |
|---|---|---|
| c1c2 p4/p5/p6 = 0/0/i( thunk 0095c91e 寄存器洗牌) | 批 103(kuna asm) | 批 83:p4=i/p5=sv/p6=-1 |
| T 段 fA/fB = bit4 位 + mtBit4SetClr 位面写 | 批 114b(asm 三源) | 批 113:整字节写 |
| wordsteptest transient 真因 = i3 simdBlocks 0x10 应为 len<<4 | 批 128 | 批 126:"未定位" |
| UI quick-find ≠ SearchPane 三框面 | 批 124(frida 双钩零命中) | 批 123:UI 误读 |
| GrepNeedle448 无 regex 编译产物字段 | 批 105(kuna 全读) | 批 93 假定 |
| 0x4eff 激活形态 = 预编译缺省语法(引擎硬编码,无参数化入口) | 批 110(face 定案) | 批 109 传参假定 |
| 0x7555/7557 非批 77 同体 | 批 130(清点) | 批 77 清点 |
| dat_d15860 = 编译环境 face(fold 表非恒等) | 批 110 | 主控批 109 静态转储初判 |
| FUN_007da228 = +0x40 **Logger** 表插入侧(三源:ctor vtable/loggerRemoved 配对/qmo idx5) | 批 141 | 批 141 任务书判读"Term 表" |
| 两 Config 单例基构造 = FUN_008a71e4 **CGlobalConfig**;SharedConfig = 独立 0x18B 小类非基类 → face 平铺 | 批 140(ctor 首句实读) | 批 138 侦察:SharedConfig 基类候选 |
| 0x4ec2(20162)落 SCI/EXT 边界下沿,dispatch 门 cmd≥20163 漏叶 → 已截获 | 批 139 | 批 137 前"门 20163 全含"假定 |
| configPath = DAT_00cba75c "/" 单字符 | 批 147(二进制实读) | 批 140 "/configs/"(槽内嵌串误读) |

## 现役队列(批 190 后,按需开批)

> ⚠ 测试冻结令 + 铁律 7 生效:各批只做转写+引用+commit,不编译不测试。

1. **GUI 重建 P1-P6(依赖序,GUI-MAP.md 总账)**:P1 KitWindow 延迟
   装配链 008d3cc2(菜单栏+splitter 恢复,Phase 4c 门)/P2 菜单族
   ActionFactory 槽接线(QMenu 触发链 0066a148)/P3 状态栏
   statusbar.config JS 引擎装载/其余 toolbar kind 5·6 cited
2. **P4 设置页族**:页面引擎五件(settings_loadWidgets 0072e4f6/
   connectSignals 00735056/enableDependentWidgets 00736bfe/
   buildRadioGroup 0070bb32/table_row_item 0071b02e)+ 触发器 8 页
   + 会话页(单点收益最大区)
3. **P5 对话框高频件**:RunToolDialog/envDialog/pasteDialog/通用
   dialog_* 件族(buttonsConnect 006c00ce 2230B 等)
4. **P6 + 尾渣**:KitGroup/TabBar/RenamedTitle 真身;eNodes 超门
   分段族收账(已落)/rehash 体 cited;Phase 4a 尾渣;收尾期首编译
   修雷(ToolBarBuilder/SettingsFace/菜单装载/appboot 扩展)
   / 0x4eff 观察(ptrace=0 + Xvfb :99 本会话已预置)

## 已知开放问题

- wordsteptest transient 已根治(批 128,i3 simdBlocks 勘误);
  若复现超 1/20 失败率须重开排查。
- 0x7545 真值路径已开通(批 143;varint 承载替值序怪癖 QUIRKS #31,
  字节级对表留 5c 期)。
- editor 型 doc +0xe0 承载与 terminal 型不同构,未建模(批 122 登记)。
- 0x7564 勘正(批 130)的他处 dispatch 消费者 xref 未查。

## 环境速查

- ctest 门:`cd build && ctest`(**20 项**;engtest3 ctest 态间歇 —
  直跑复核;wordsteptest transient 已根治,批 128)。
- RE 探针:tools/re/metatest/(手工 g++;**改含内联成员的头后必须
  重编**,踩坑 15)。
- frida:pip --user;REA MCP 已配置(项目 opencode.json,207 工具);
  ida-pro-mcp 1.4.0 已装(原版开启时 localhost:13337)。
- kuna CLI:`~/.local/share/rea/bin/kuna`(优于语料 grep,支持
  --addr;批 103/128 两次实战破案)。
- libssh-dev/patchelf/Xvfb 已装;ptrace_scope 重启后回 1,frida 前
  需 `sudo sysctl -w kernel.yama.ptrace_scope=0`。

## 原版环境拉起流程(5b/对比批用;批 121-123 实战)

1. `sudo sysctl -w kernel.yama.ptrace_scope=0`(须密码,主控代输)
2. `Xvfb :99 -screen 0 1280x900x24 &`(日志 /tmp/opencode/xvfb.log)
3. `DISPLAY=:99 nohup /opt/WindTerm_2.7.0/WindTerm`(约 10s 起窗)
4. xdotool 双击开会话:1014,331 → 1040,359;打字触发回显;
   `exec sleep 100000` 哑化 shell(ALL MATCH 基线前提)
5. `python3 tools/re/phase5/phase5_attach.py $(pgrep -x WindTerm)`
   验证附加;**一次挂上复用,勿竞态**(批 98 事故)
6. 收尾:拆原版/Xvfb,ptrace 恢复 1(批 123 后惯例)

## 提交规范(2026-10-29 修订)

- 中文 commit;**只提交,不主动推送**(push 仅在用户明示时执行,
  届时必带 `-c http.proxy=http://192.168.1.106:7890`)
- commit 与 push 永远不在同一条命令行;每轮改动 + 对应 .md 更新,
  一条 commit
- 车道批次:worktree 隔离 + 恰好一个 commit + 绝不 push(详见
  下方车道方法论)

## 车道方法论(硬护栏,四轮 12 车道实战沉淀)

- worktree 隔离 + 写域互斥任务书 + 主控统一 docs(PHASE5/HANDOFF
  主控写;车道越权写 PHASE5 两起,内容合格保留,主控核对)
- 大语料读取型任务书**必须带输出上限**(批 107 首轮零产物教训)
- **边读边落 + shell 预算 ≤60**(批 112 500+ shell 零产物教训;
  批 129 ~70 超限如实自报)
- 落条前 case/符号唯一性自查(批 129 重复 case 事故)
- 取证型车道配失败条款:批 105/109/110/115/118/122/123 七次正确
  拒绝无证激活/发明
- 权限审批:车道 worktree 路径 reply always 预放行
- 勘正谱系见上表;新会话读到与谱系冲突的旧结论,以谱系为准
