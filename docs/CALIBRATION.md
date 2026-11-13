# 校准映射 — src/ 内官方开源组件 → 我方子系统

> 我方 src/ 本就包含官方开源的全部组件(== kingToolbox/WindTerm 仓库
> src/,Apache-2.0 第一方)。原则:对应子系统**停止逆向,改为移植/校准**。
> 终端核心(Sessions/ 的 Screen/TerminalCore/SuperCommander、Editor/、
> 解析引擎)不在开源集 = 项目逆向范围的权威边界确认。

| 组件(src/ 下) | 官方说明(src/README.md) | 校准动作 |
|---|---|---|
| Utility/Cryptographic | PBKDF2(RFC 8018)+ 对称加解密,masterPassword 保护用户数据 | 用 user.sessions 已知密文**对拍验证**;salt/key/iv 链直接对照 |
| Protocols/TelnetProtocol | Telnet 协议实现 | Phase 4a Telnet 计划改道:**移植替代逆向** |
| Pty(UnixPty/WinPty/ConPty) | 基于 ptyqt 几乎全部重写 | 会话装配阶段的参考实现 |
| Widgets(Splitter/ScrollBar/PopupWidget) | 64-bit range 滚动条等 | Phase 4c 直接采用 |
| Utility/CircularBuffer, Spin, ScopeGuard, MemoryPointer, ThreadLocal | 环形缓冲/自旋锁/RAII/智能指针/线程局部 | +0x118 自旋锁等命名结构校准 |
| libssh(改版) | 基于 0.95:pageant、external socket、hmac-md5-96(-etm)、hmac-sha1-96(-etm) | **diff 官方 0.95 = 认证行为差异清单**(单独轮) |
| Onigmo(改版 5.13.5) | 新增 iterator 可匹配 gap buffer/非邻接内存块 | EditorEngine 搜索面机制对照 |
| Scintilla/jsoncpp/yaml-cpp/dtl/fmt/spdlog | 第三方原版 | 已按 EXT-BOUNDARY 委托真库 |

## 组件校准结论(2026-10-30,三路 subagent 并行)

| 组件 | 判定 | 要点 |
|---|---|---|
| **Utility/Cryptographic** | ✅ 同版(实验锚全过) | 解密链端到端对拍成功(见上) |
| **Protocols/TelnetProtocol** | ⚠️ 部分同版 | 叶子逻辑(名字表/GetOption*)与 2.7.0 精确同版(00860b30/00860cd6/00861156);基类被裁剪(SuperProtocol 0x128 缺);**协商非 C++ 状态机** = telnet.protocol 正则 + TelnetCommander 槽;option=49 越界读怪癖两侧一致(勿修) |
| **Pty/UnixPty** | ⚠️ 部分同版 | posix_openpt 链/termios/setupChildProcess/utmpx 逐句同构,内存布局逐字段吻合(+0x50 master 等);差异:二进制多第 5 纯虚(readlink /proc/pid/cwd)、Q_OBJECT、stop() 顺序 |
| **Widgets/ScrollBar** | ✅ 同版 | 全族零差异,布局 0x48 逐字节吻合,4 信号索引一致 |
| **Widgets/Splitter** | ✅ 同版 | sizeof 0x38、m_mainIndex@+0x30、"ratio"+0.18 缺省 ✓;Phase 4c 需补 SplitterGroup(仓库缺) |
| **Widgets/PopupWidget** | ⚠️ 部分同版 | 全同,唯 TRIANGLE_HEIGHT 18↔语料 6 待核 |
| libssh(改版) | 待 diff | README 列明:pageant/external socket/hmac-md5-96(-etm)/hmac-sha1-96(-etm) |

## 组件校准结论(2026-10-30 三路并行校准 + 落地)

| 组件 | 判定 | 落地/差异 |
|---|---|---|
| Cryptographic | ✅ 同版(实验锚全过) | 解密链端到端对拍(fingerprint 盐 + 空口令派生) |
| Protocols/TelnetProtocol | ⚠️ 部分同版 | 叶子逻辑同版(00860b30/00860cd6/00861156);协商 = telnet.protocol 正则驱动;option=49 越界读怪癖两侧一致(勿修);**响应策略 = 实验锚捕获**(批 33,telnet_capture.json:init/DO24 重发/NAWS/TTYPE xterm-256color/DO39 WONT;策略体语料不可达,实验为准) |
| Pty/UnixPty | ⚠️ 部分同版 | posix_openpt 链/termios/utmpx 逐句同构+布局吻合;差异 = 第 5 纯虚(cwd readlink)/Q_OBJECT/stop() 顺序;**base 签名已对齐**(QProcessEnvironment/int;setErrorCode Linux strerror 分支);ShellProcess 抽 ShellProcess.h(moc 类扫描盲区:基类子句换行) |
| Widgets/ScrollBar+Splitter | ✅ 同版 | 布局逐字节吻合;Phase 4c 需补 SplitterGroup(仓库缺) |
| Widgets/PopupWidget | ⚠️ 部分同版 | TRIANGLE_HEIGHT 18↔6 待核 |
| KeymapEngine(新) | ⏳ 引壳+装载器转写(批 42/47) | 装载器 s_wind_keymaps_768854(428B)转写落地;匹配体 = FUN_0067500e(9978B)已定位,转写待专用批 |
| TelnetCommander(新) | ⏳ 槽体结构转写(批 41/48b) | metacall 00917e20 → 槽 0/1(FUN_008606fe/00860642)结构落地;协商 = session.term 配置驱动分类(批 48b/52 全链闭环);助手链(0085e2xx/0085fa60/00860a50)已转写;响应写出(term_processCR)与会话终端面(72014e)待转写 |
| JsEngine(新) | ✅ 重做(批 68) | 底座勘定 = 动态 QJSEngine(EXT-BOUNDARY);12 函数逐个转写(0064a/b 族)+ bootstrap 收编 0064b102;tr 文本 0xc91268 字面 cited |

## 混合架构边界增补(2026-10-30 批 51)

- **QtSvg 委托实证**:语料 QtSvg 符号族(0001.c QSvgRenderer::
  render/isValid/elementExists + 二进制 _ZN12QSvgRenderer* 导入)
  —— SVG 光栅化 = 真库委托(同 libssh/yaml-cpp 策略);
  libqt5svg5-dev 入构建环境,Qt5::Svg 链接

## 校准协议(2026-10-29 定,**逆向为准**)

> 担忧:仓库 src 持续演进,2.7.0 编译时点可能不同 → 开源码**只是
> 候选参考**,二进制行为才是裁决者。三步锚定:

1. **存在性锚**(已做,2026-10-29):组件符号/vtable/moc 串命中
   二进制。结果:TelnetProtocol=1、UnixPty=3、Splitter=45、
   ScrollBar=30、PopupWidget=3、Cryptographic=2 ✓ 全在;
   ConPty/WinPty=0(Linux 构建应然)、CircularBuffer=0(header-only
   模板无符号,不构成反证)。
2. **行为锚**(随各子系统逆向逐函数做):语料函数体 vs 开源源码
   逐句对——零 diff 才判"同版可校准";diff 处**以语料为准**(版本
   差异或作者后改),并把差异登记为"开源码-二进制差异清单"。
   方法同 AGENTS 踩坑 #6(特征串命中率定版本)。
3. **实验锚**(金标准):可执行对拍。首个:Cryptographic 用
   user.sessions 真 blob 解密验证(源码已在本树,编译即测)。

**实验锚 #1 ✅✅ 全链闭环(2026-10-30)**:
- autoLogin 解密链**端到端验证**:`decrypt(b64)` → `AES-256-CBC`
  (key=pbkdf2[0:32], iv=pbkdf2[32:48]) → JSON
  `{"Password":…,"session.user":…,"uuidSalt":…}`
- **KDF 派生链验证**:`pbkdf2 = PBKDF2-HMAC-SHA3-512(password="",
  salt=fingerprint(64B 原始), 100000, 48)` — masterPassword=false ⇒
  空口令;fingerprint(user.config)= **KDF 盐**(角色定案);
  pbkdf2 本身不落盘(内存 config+0xc0)
- 方法:frida spawn 钩 0xa7e12e(decrypt)拿 (data, pbkdf2) 实参 →
  本地 python 复解 → 派生矩阵反推 password/salt —— 三段互证
- uuidSalt(密文内)= 条目级盐,用于 changeMasterPassword 重加密
  (推测,未验)
- 现场已恢复:user.sessions 还原、sshd 关闭、WindTerm 重启
- 敏感信息处理:明文/pbkdf2/fingerprint 值不入库(仅机制描述)

**实验锚 #1 完成(2026-10-29,Cryptographic 同版验证 ✓)**:
- **语料定位**:doCrypt=00a7dfb0(EVP_CIPHER_CTX_new→aes_256_cbc→
  CipherInit(enc)→Update→Final,与开源码逐句同构)、decrypt=
  00a7e12e(enc=0)、encrypt=00a7e258(enc=1)、pbkdf2=00a7e5f6
  `deriveKeyPbkdf2(ret,0xe,pw,salt,100000,0x30)`、salt=00a7e61c
  (generate64→number→Sha512(=6)→base64)——**全家族与开源码
  同版零差异**;0xe=14=Qt5.15 枚举 Sha3_512(系统头 76 行域已核)
- **调用点**:decrypt(data, CTerminalConfig+0xc0)——pbkdf2 存于
  配置单例 0x11c2220 +0xc0(实例指针 DAT_011c2200);fingerprint
  64B≠48B 角色(盐?存储 key?)未定,+0xc0 布局待读(探测见
  /tmp/opencode/p5probe3*.py)
- **运行时触发未闭合**:autoLogin 属 SSH 会话 118,实测均
  key/onekey 免密(3 次)→ 密码解密未执行;强制触发 = password-only
  sshd(:2222,已建已撤,118 曾指向它实验)+ 指纹对话框确认流,
  UI 自动化不稳定,留给下一轮(scripts p5probe24-33)
- 副作用已恢复:user.sessions 已还原备份,sshd 已关,WindTerm 已重启

**实验锚 #1 进行中(2026-10-29,Cryptographic × session.autoLogin)**:
- autoLogin blob(280B base64)属于 SSH 会话 192.168.1.118(本地集群组);
  三次触发(开 bash/盲扫/双击 118 行)均**免密登录成功**(key/onekey
  路径)→ **autoLogin 密码解密从未触发**,EVP 捕获对(启动 120 对/
  重开 125 对)无一对 blob 可解
- 但 **EVP_CipherInit_ex(enc)+ Decrypt/EncryptInit_ex 对偶模式在
  二进制中出现**(启动对:Decrypt c20be809…/Encrypt f1fe3b97… 同
  ctx 系)——源码 doCrypt 单 ctx 双向模式与二进制同型 ✓(部分行为锚)
- 下一步:造 password-only 触发(临时 sshd 或改测会话)强制
  autoLogin 解密 → 抓真 key/iv → 与 fingerprint 派生链对拍
- 副作用备注:probe 期间曾开 39.100.119.145/118 的 SSH 标签并重启
  WindTerm(未在任何远程会话输入内容)

**已核**:deriveKeyPbkdf2 导入符号与源码签名精确同型
(Algorithm,QByteArray,QByteArray,int,ulong);Cryptographic 为
Qt/OpenSSL 薄胶水(AES-256-CBC,key=pbkdf2[0..32),iv=[32..48),
SHA3-512 PBKDF2×100000,salt=base64(SHA512(number(generate64))))。

## 批 105:0x4eff 正则搜索腿取证(未激活;Onigmo-改 边界委托复核)

> 任务书失败条款触发:第 1 步取证**未拿到 onig_new 语法/编码选项实参**
> → 不落行为码,零新增 TU,仅 MatchEngine.h cited 注记补取证结论。

### 取证结论(2026-11-13,kuna CLI 全实证)

1. **0x448 GrepNeedle448 无 regex 编译产物字段**(任务书假定勘正):
   - 产腿 = 0089a0a0(operator_new(0x448)@0xa32d57 反汇编实证)→
     refs{1,1} + vtable 0x1192460 → convCtor(&v7[2])(00a32d5c 面)。
   - convCtor(0089c450)写域 = conv+0x10..+0x437(skip 表 +0x414 止/
     allowedBits +0x418/SIMD 三块 +0x420/428/430)恰满 0x448−0x10 头
     — **零剩余字节**,无 OnigRegex 指针落点。
   - 00b422d0 param_2 正则对象与 GrepNeedle448 布局零重叠(见 3)。
2. **canOld=true 搜索腿的正则不在针对象**(0xa33001 调用点反汇编):
   - sub_92547e(doc, v7, v21, &v10, v21):param_4 = &v10 =
     canEncodeMemo(0089b85e → 00a8450a Uint32Bimap 0x20 ctl)缓存对象
     (00a32d30 实证),非 onig regex 对象。
   - 搜索正则由 doc+0x1098 FindContext 深腿持有(cited);编译 =
     Onigmo-改 惰性编译栈(FUN_00ad7360 304B/FUN_00ad2ae0 17929B,
     批 101 三源互证)。
   - 业务区(0093/0095/00a3)零 onig_new 直调:kuna xrefs --to onig_new
     无名命中;语料 49M onig_new/regex_compile/REG_COMPILE 零命中
     (批 103 L3 勘察同判)。
3. **b422d0 param_2 正则对象布局**(kuna 反编译 0x00b422d0 实测;
   Onigmo-改 扩展 regex_t,上游 regex_t 无此域):
   | 偏移 | 域 | 证据 |
   |---|---|---|
   | +0x48 | 编码/迭代 vtable | *vt+0x90 step_back / +0x28 mbc_enc_len / +0x38 is_mbc_newline / +0x08 mbc_enc_len(0xb422d0 内尾调) |
   | +0x50/+0x51 | 选项位(&0x10 find_longest 类 / &0x80) | 0xb42888 分支 |
   | +0x70/+0x74/+0x78 | 优化标志(int/int/u32,&4/&1/&8/&0x10/&0x8000 分支) | 0xb4240x/0xb427a8 |
   | +0x80/+0x88 | minLen/maxLen(ulong) | 0xb42a53 边界剪枝 |
   | +0x1c0 | 精确串指针(优化跳过面) | 0xb4257c |
   | +0x14 | 捕获对容量(regex_nfa_compile b41ee0 扩容面) | sub_b421c0 |
4. **激活缺证清单**(下次接手入口):
   - FindContext(doc+0x1098)正则条目构造链:findStr → onig 编译栈
     (00ad7360/00ad2ae0)入参(语法 ONIG_SYNTAX_*/编码 ONIG_ENCODING_*
     /选项 ONIG_OPTION_*/SE_ONIG_OPTION_WHOLEWORD 扩展位)。
   - 搜索器(doc+0x88)sub_b422d0 param_2 对象的装载点(谁写 +0x48
     vtable 与优化域)。
   - 取到 1/2 后按本文件"校准协议"逐句映射 onig_new/onig_search 形参
     (libonig.a 委托面已就绪:四符号 nm 实证;OnigIterator = {at,ptr}
     16B 回调结构,oniguruma.h:118-122)。
## 批 109:FindContext→编译栈 深腿取证(未激活;缺证清单 1/2 收口)

> 结论:**仍未达激活门槛** — 编码/语法运行值零实证,零行为码。
> 缺证清单 1 勘正(条目不在 FindContext 自身)/ 2 收口(装载点已定)。

### 编译栈调用链(kuna 全链反编译,2026-11-13)

- **编译门**:00a81655(210B,唯一编译入口封装,上游 0xa816d1)→
  00a9c780(22512B,Onigmo-改 parse+compile 本体)→ 唯一编译调用方
  00ad7360(304B 惰性编译门,产物挂对象 a0[4]=+0x20 槽)。
  - **改版差异标注**(对 src/Onigmo/regcomp.c:5941 onig_new 7 参):
    a9c780 签名 6 参 (pat*, len, option, err_code*, err_pos*, syntax*)
    — regex** 出参改返回值、OnigErrorInfo* 拆 err_code*/err_pos* 两出参、
    **无 encoding 形参**(编码硬连内部);error code 正值域(0x74 等,
    上游为负值域)与上游 -100 域不同。
- **构造器族**(全部已反编译):
  - 00a81a88(450B)← 00a81c4a(200B ctor:选项两字域 field_0x48/0x4c、
    field_0x50 位面基值 |0x1a)← 0x80a2c5/0x89c0fb/0xa84f32 三调用点。
  - 00a848d6(207B)← 00a140b2(368B QByteArray→std::string 桥,选项恒
    (1,1,0x2000,0))← 00a14222(300B Qt 装载腿)/00a144d2(1112B:序列化
    "//…//" 剥壳与 /*…*/ 分支)← 00a15ef6(90B)← 00a121a0(1600B)。
- **消费侧**:searcher 复位 a83622 → sub_a83c7a(400B)取
  *(needle+0x18)=regex 对象 → FUN_00ad74a0(431B,Onigmo-改 onig_search
  等价:param_6=region,+0x18/+0x20/+0x40 结果写面)。

### FindContext 条目勘正(缺证清单 1 收口)

- 构造产物**不在 FindContext**:a81a88/a848d6 均写调用方对象 +0x0;
  doc+0x1098 仅经 9975c8(+0x28 槽[5])供 pattern 串源(getter
  9276e2/927600,editor_replaceAll 12551-12557 取串)。编译时机 =
  各上游调用点,非 doc 持有编译栈。

### 语法/编码/选项证据状态(不齐 → 不激活)

| 项 | 证据 | 状态 |
|---|---|---|
| 语法 | a9c780 默认 = &dat_d15860(a5==0);业务三调用点(a81a88/a848d6/a82450)语法参恒 0 | ❌ dat_d15860 数据内容不可达(无符号对照);上游 ONIG_SYNTAX_RUBY 仅候选 |
| 编码 | a9c780 无 encoding 形参;旁支栈 00b3b090→00b39830 传 DAT_011becc8,唯一写点 00b39540(9B)xrefs=0 → 运行值 0 | ❌ ONIG_ENCODING_* 对应值无实证 |
| 选项 | a81655 入口重组(0x2000000→0x80000000; a1→0x8000008; a2→0x20);a140b2 恒 0x2000 | ⚠️ 位面吻合但多调用点恒 0,非正向证据 |

### 下批入口

1. ~~dat_d15860 数据段转储~~(**已完成,主控静态转储 2026-11-13**,
   ELF program headers 直接读,无需 IDA/memdump):
   - dat_d15860 = `{q:0xaa1f70(.text fn), q:0xaa1f80(.text fn), 0, 0, 0,
     q:0xd35f40(.rodata 恒等字节表), −1, bytes{02,05,00,fa}}` —
     **函数表头结构,非上游 OnigSyntaxType 字面布局**(上游首域
     options 为整数)。布局对照需 Onigmo-改 改版头(库内只有上游
     src/Onigmo),结构性结论:改版语法 face 带函数表头 + 恒等表 +
     {2,5,250} 数值域 — 不能直接映射 ONIG_SYNTAX_*。
   - DAT_011becc8 = `{q:0x40000000, {0x73,0x73}, q:0x11bf020(自引
     .data), q:0x600360167ff7d556, q:0x100880a0001b, 0x5c, 0, 0}` —
     同样无法映射上游 OnigEncodingTypeSt 字面。
   - **结论修正**:两个"运行值"的形态是改版 face 结构,激活映射
     需要先逆向改版 face 布局(00aa1f70/00aa1f80 两函数 + 0xd35f40
     表消费点),而非对照上游语法枚举。入口转为:读 00aa1f70/
     00aa1f80 函数体定 face 语义 → 反推 dat_d15860 域含义。
2. DAT_011becc8 运行时观察(实验锚)仍可选 — 静态转储已给形态,
   运行时仅确认写点 00b39540(xrefs=0)是否真未执行。
3. 两值定案后按"校准协议"逐句映射 bufferScan00b422d0 委托
   (libonig.a onig_new/onig_search/onig_free 已就绪)。


## 批 110:Onigmo-改 face 定案取证(未激活;face 语义三源定案,枚举映射缺证)

> 结论:**零行为码**。dat_d15860/DAT_011becc8 face 语义定案(见下),
> 但与上游 ONIG_SYNTAX_*/ONIG_ENCODING_* 枚举的映射仍无证据 —
> 改版结构非上游布局,libonig 委托激活继续挂起。

### face 语义定案(kuna 函数体 + xrefs + ELF 静态转储三源互证,2026-11-13)

- **00aa1f70(5B)= malloc 尾调用;00aa1f80(5B)= free 尾调用**
  (kuna 反编译直证)— 非编码钩子(任务书候选证伪)。
- **dat_d15860 = 编译环境 face(Onigmo-改 语法 face 容器,0x48B)**:
  - 消费点唯一:kuna xrefs --to 0xd15860 = 1 hit @a9c7ee(sub_a9c780,
    编译本体)— a5==0 时默认 face。a81655 param_5!=0 时改用
    aa2060(0) 堆构造同构 0x48B 对象(默认分支逐域写 dat_d15860
    的镜像值)→ **静态 dat = 堆 face 的原型**。
  - 域语义(a9c780 消费面 + aa2060 默认值两源一致):
    `[0]=alloc(aa1f70) [1]=free(aa1f80) [2]=ctx [3],[4]=0
     [5]=0xd35f40 折叠表 [6]=-1(pattern 长度上限=∞;v77=strlen
     检查 v19[6]<len 才报 0xbc)[7]=u16{2,5}+u32{0xfa}
     [8]=flags u32(静态 0;检查 &0xffffff80 / &0xc)`
  - aa24c0/aa24f0/aa2510/aa2520 setter 族:+0x38 short(1..2)/
    +0x3a short(1..6)/+0x3c u32/+0x40 u32 = 运行期可变域。
- **0xd35f40 = ASCII case-fold 表(256B,非恒等表!)**:ELF 转储
  实测 A-Z(0x41-0x5A)→ a-z(0x61-0x7A),其余字节恒等 —
  主控"恒等表/定长单字节编码 face"推断**勘正**:256B 是
  忽略大小写折叠表(消费:a9c780 v24 默认,face[5] 覆盖)。
- **dat_d158a8(同区邻接表)= 对象 vtable(9 项 fn)**:
  `{aa1f80, aa26b0×6, aa2728×2}`;aa1f90(size,parent)分配
  {alloc_fn, vt=dat_d158a8} 2 头继承对象 — C++ 虚表继承模式;
  aa26b0/aa2728 = pattern 字节扫描虚方法(0x55-0x61 switch,
  0x0f/0x10 特判 = UTF-8 双字节窗)。**上游 meta_char_table
  对照不成立**(全指针同值,非 CodePoint 常量),仅形态候选。
- **DAT_011becc8 = 旁支编译栈的独立 face**:唯一写点 b39540
  (9B setter)xrefs=0;00b39830(编译门)直接引用 — face 与
  dat_d15860 无关,不属上游 OnigEncodingTypeSt 布局({0x73,0x73}
  非 min/max_enc_len)。语义未定案,维持观察项。

### 缺证清单(激活剩余)

1. **语法 op/op2/behavior 位面不在 face 内**:a9c780 对 v19 仅消费
   [0]/[1]/[2]/[5]/[6]/[7]/[8](alloc/free/ctx/fold 表/限额/u16/flags)
   — 上游 OnigSyntaxType 四整数域(op/op2/behavior/options)零消费,
   语法行为已硬编码进 a9c780 内部(改版去可变语法)。上游
   ONIG_SYNTAX_RUBY 等枚举映射**无落点** → libonig onig_new
   委托无 syntax 实参可给。
2. **编码 face 无上游对应**:编译主链(a81655→a9c780)无 encoding
   形参,编码行为进 a9c780 内部(d35f40 ASCII fold 表 = 唯一编码
   面证据,指向 ASCII/单字节,但非上游 face 结构)。ONIG_ENCODING_*
   映射无证据。
3. b422d0 委托激活路径再确认:GrepNeedle448 与 onig regex 对象
   布局零重叠(批 105 ①)— 委托需自建转换层,校准协议逐句映射
   仍待 1/2 收口后启动。
