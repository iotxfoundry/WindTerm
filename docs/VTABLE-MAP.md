# P3 勘察笔记 — EditorContext(Editor)vtable / 槽映射 / ctor(2026-10-30)

## 结论速览
- **EditorContext 主 vtable(虚槽 0 起):vptr = 0x11afd30**(ctor 写入值;
  符号基址 0x11afd20 = off-to-top(0)+typeinfo(0x11afa10))。
- **ctor:FUN_00a2c670**(语料名 s_pair_highlightUnmatched_a2c670,1951B,
  Ghidra 命名误导;`*param_1 = &Editor_vtable;` 0x11afb00+0x10、
  `param_1[1] = &Window_vtable;` 0x11ad140+0x10)。
  独占调用者 FUN_00a4f69e(子对象构造:FUN_00a4f69e(param_1+0x10),
  紧接 `*(param_1+0x10)=0x11ae558(ScintillaQt vptr)`)→ 上层
  FUN_0094a056(ScintillaQt ctor,0x1270B 对象)→ editorbase_init
  (0x009451a4,operator_new(0x1270) @0x94525d 存 [this+0x30])→
  FUN_005b3c1c(operator_new(0x68); editorbase_init(new,obj+0x58))。
  析构对:FUN_00a2bf50(dtor)、FUN_00a2c20a(scalar deleting,size 0x1148)。
- **编辑引擎(EditorEngine)子对象**:vptr=0x11afcd0(PTR_FUN_011afcd0,
  size 0x2f0,ctor 内 operator_new),构造 editor_engineCtor(puVar9+2)。
  语料名 PTR_FUN_011afcd0;engine 槽 0-4 = a4b458/a4b45a/a4b4a6/a4b4b0/a4b470。
- **Markers/doc 对象**(this+0x1098 = param_1[0x213]):ctor 尾部
  `param_1[0x211]=puVar8(engine 体);param_1[0x212]=puVar9(控制块);
  param_1[0x213]=puVar8;FUN_0092b504(puVar8,param_1);FUN_00950212(param_1+8,puVar8)`。

## vtable+0xe8(槽 29)裁决:**__cxa_pure_virtual(0x00bec350,ActionHandler_vt2)**
- 主 vtable@0x11afd30 +0xe8 = 0xbec350 = `write(2,"pure virtual method called\n");std::terminate()`。
- 语料映射:Editor 基(0x11afb10)同槽 = 0xbec350;ScintillaQt 派生
  (0x11ae558)+0xe8 = FUN_00948a88(thunk → FUN_00948a48[obj-0x10]):
  FUN_009489f0() 判定 + FUN_00948a24(...) 命中则返回
  `(*(u32*)(hit+0x28)+8 >> 0xf) & 1` —— **这是 ScintillaQt 层重写**,
  `vt+0xe8(self,kind=1/2)` 命令 0x7546/0x7548 实际命中 ScintillaQt 槽
  (EditorContext 实例首 vptr=0x11ae558 者,即 FUN_0094a056 建的 0x1270B 对象);
  Editor 基类槽 29 纯虚,不改写。
- **勘误(批 58b)**:PHASE5.md"静态扫描无命中、运行期转储两路未解"——
  本批经 .data.rel.ro 重定位+语料语义双向静态定位,已解。

## EditorContext 主 vtable 槽表(0x11afd30,派生最终态)
| 槽 | 地址 | 函数 | 语义(语料证据) |
|---|---|---|---|
|0 +0x00|0xa1e46e|Editor_qt_metacall|return *(u8*)(this+0xec1)|
|1 +0x08|0xa1e71a|Editor_dtor|全成员清理(FUN_00a2bf50 同族)|
|2 +0x10|0xa2dd9e|(scalar dtor 簇)||
|3 +0x18|0xa1e442|Editor_vt5|noop|
|4 +0x20|0xa30ae2|Editor_vt6|(self,long*) 参数两枚|
|5 +0x28|0xa1e444|Editor_vt7|jmp *(vt+0x140) → 链式刷新|
|6 +0x30|0xa1e8da|Editor_vt8|(self,QVariant*)|
|7 +0x38|0xa1eaae|Editor_vt9|(self,QVariant*)|
|8/9 +0x40/+0x48|0xa28e16|Editor_vt10|(self,long*)→bool|
|10 +0x50|0xa28e1c|Editor_vt12|(self)|
|11 +0x58|0xbec350|pure||
|12 +0x60|0xa51db2|thunk→Editor_vt14(a1ec3a)|vt14:若 vt+0x188≠a4b448 先调之,再 *(vt+0x148) 尾跳|
|13 +0x68|0xbec350|pure||
|14 +0x70|0xa1e400|置零域|return 16 字节零(全零 Q 变体)|
|15 +0x78|0xa1e708|(0xfe0/0x1008 状态机域)||
|16 +0x80|0xa1e40a|getDocMode|读 +0xfe0(1→若[0x1008]==0 则置 2,返1);= **+0x1067 模式字节的引擎侧对位**|
|17 +0x88|0xa1ec78|(滚动/光标域)||
|18 +0x90|0xa1ed74|(可见性域)||
|21 +0xa8|0xa1e438|noop|1 字节空函数|
|22..29|0xbec350|pure|**+0xe8=槽 29 亦 pure(派生才重写)**|
|30 +0xf0|0xa311be|(key/输入分发:self,ushort*,uint,char)|读 +0x1098/+0x1128(editor_selMake "Insert Text")|
|31 +0xf8|0xbec350|pure|ScintillaQt 重写为滚动条 policy 切换(0x754b/c)|
|32 +0x100|0xa207a4|readOnlyCheck|FUN_009290e8(doc) ? 0 : !FUN_00a2072a|
|33/34|0xbec350/0xbec350|pure||
|35 +0x118|0xa1f282|(重算/刷新域)|FUN_00a1f77c 读 +0xe88 建缓存|
|36 +0x120|0xa1e43a|set|*(u32*)(this+0x10d8)=arg|
|37 +0x128|0xa1814e|get|return *(u32*)(this+0x10d8)|
|38 +0x130|0xbec350|pure||
|39 +0x138|0xa52040|→FUN_00a4f7b4 + +0x1148 子对象构造||
|40 +0x140|0xa51db8|(大函数;Editor 基 slot5/12 经此链接)||
|41 +0x148|0xbec350|pure|基态;Editor_vt14 尾跳目标|
|42 +0x150|0xa1eb62|updateCaret|→FUN_0094485c(this+8,arg);读 +0xeb0 覆写|
|43 +0x158|0xa1e44e|dist|(x1,y1,x2,y2)→bool 平方距离>0x10|
|44 +0x160|0xa1e438|noop||
|45 +0x168|0xa3c676|editor_mousePress|(self,event*,int,int)|
|46/47|0xbec350/0xa4b448|pure/3B 小体|a4b448=vt14 比对锚|
|48 +0x180|0xbec350|pure|ScintillaQt 重写 0x94923f|
|49 +0x188|0xbec350|pure|vt14 首查比对槽(a4b448 锚)|
|50 +0x190|0xa1e476|meta 命中判定|double×4 in-stack,域 0xfe8-0x1000|
|51 +0x198|0xa5205e|命令分发|0x83e/0x89b/0x8a5/0x8a6/0x7531/0x7532…→a4f95e/a51780/a418c4|
|52 +0x1a0|0xbec350|pure||
|53 +0x1a8|0xa4f660|mousePre 中转|(ev*,self,int,int):调 *(vt+0x148) 后 editor_mousePress|
|表 尾|0xbec350|__cxa_pure_virtual||

ScintillaQt 派生(0x11ae558)差异槽:13/15/19-22/24-31/33/35/36/38/40/43/46/48/49/51-55
(0x948949 noop、0x949f3b、0x948b3c→FUN_00948b18[App 静默器 +0xf60 双写 →
FUN_00a3e5ca 刷新]、0x948a88=**+0xe8**、0x949b75、0x94901c、0x949046、
0xa52040、0xa51db8、0x948f4f、0x9489e9、0x94945d、0x949121、0x94923f、
0x949259、0x949268、0xa1e476、0x94a04d、0x949518、0xa4f660→
0x148 + editor_mousePress)。

## 命令→槽映射复核(语料 decomp-part-0034.c:22784-22930)
- 0x7543 → FUN_0092f0f6(doc,arg,mode==2)+session_view_soft_reset+FUN_00a243ae(,0x10)
- 0x7544/0x753e → pixmap 渲染族(FUN_00a4186e/FUN_00a417fe)
- 0x7545 → FUN_00933366(标记导入)
- **0x7546 → (vt+0xe8)(self,1)→QVariant(bool)**;**0x7548 → (vt+0xe8)(self,2)** 同
- 0x7549 → FUN_00930338(doc,arg,1)
- 0x754a → vt+0xd0(self)无参 void(**vt+0xd0 = 0xbec350 pure**;
  ScintillaQt +0xd0 = FUN_00948c89 thunk→FUN_00948c6e)
- 0x754b/0x754c → vt+0xf8(self,1/2,bool)(pure 基;ScintillaQt +0xf8 = 0x948b12 thunk→FUN_00948ab0)
- 0x753f → vt+0xc0(self)(ScintillaQt +0xc0 = FUN_00948b9b thunk)
- 0x753d → caret_changeShape(self,int);0x7542 → vt+0xc8(self,long)
- 0x753c → FUN_00a204a0(self);0x7551 → editctx_beginIter + FUN_00a287f8
- 0x7552-0x7556 族 → buf_substr/FUN_0092777c 等

## ctor 成员初始化表(FUN_00a2c670,首 0x40 字节域)
| 偏移 | 初始值 | 推定 |
|---|---|---|
|+0x00|0x11afb10|vptr Editor(基)|
|+0x08|0x11ad150|vptr Window(基 2)|
|+0x10|0|成员 2|
|+0x18(u32)|0|成员 3|
|+0x20|0x11ad150|vptr Window(基 2 引用)|
|+0x28|0|成员 5|
|+0x30(u32)|0|成员 6|
|+0x39(u8)|0|flag|
|+0x40..0x1070|FUN_00950f9e 域|视图度量/渲染域(param_1+8 起 2KB+ 状态对象)|
|+0x1067(u8)|1|模式字节|
|+0x10ec(u32)|2|caret 形态|
|+0x1088|*(this+0x1088)|dtor 时 FUN_0092b4a8([0x1088],this) 反注册|
|+0x1098([0x213])|engine 体指针(shared_ptr 控制块 [0x212])|doc/markers 对象|
|+0x1118 [0x223]|0x100000010|[fold 状态]|
|+0x1128 [0x225] u8|0|hexMode|
|+0x1130 [0x226]|&DAT_bff0000000000000|double 常量|
|+0x1138 [0x227] u32|0x10101|标志组|
|+0x1148 起|FUN_00a73e20(派生 ctor 补建)|0x1270-0x1148 尾域|

engine 子对象(vptr 0x11afcd0)0x2f0B:体 = editor_engineCtor(puVar9+2),
自引用 puVar9[3]=puVar9(weak?)。engine→ctx 反链:FUN_0092b504(engine,param_1)。

## 方法论备注(静态定位链,全部可复现)
1. .data.rel.ro 裸值即重定位终值(RELATIVE 重定位 addend=0,非零值直接可用);
2. 由 0x925316(engine vtable 占位函数群 00925316/1c/22/28/2e,
   语料体 = *(this+0xe0) 转发)等小函数反查失败(全镜像无 8 字节引用;
   它们本身非槽,是被转发方);
3. 正解:语料函数名(Editor_qt_metacall=0xa1e46e)→ 在 .data.rel.ro 找
   引用槽 → 得三个候选 vtable(0x11ae568/0x11afb20/0x11afd30)→
   ctor 反汇编(FUN_00a2c670)定 vptr 常量(0x11afb00+0x10、0x11ad140+0x10;
   子对象构造者 FUN_00a4f69e 覆写为 0x11afd10+0x10)→ 槽表全出。
4. Qt 风格 vtable:slot0=qt_metacall @基+0x10;槽 N = 基+0x10+8N;
   自 vptr 值起算的"+0xe8"与语料 (vt+0xe8) 一致(0x11afd30+0xe8)。


## 附:槽 29 语料体旁证(FUN_00948a48,+0xe8 重写体)
```
uint FUN_00948a48(self,kind):
  if (!FUN_009489f0(kind)) return 0;        // 滚动条 policy==0(ScrollBarAsNeeded)?
  hit = FUN_00948a24(self,kind);            // h/v scrollBar() (this+0x1258)
  if (hit==0) return 0;
  return (*(u32*)(*(u64*)(hit+0x28)+8) >> 0xf) & 1;   // QScrollBar 内部标志位 bit15
```
thunk 链:0x948a88 = FUN_00948a48(self-0x10)(ScintillaQt+0xe8 槽,参数 (self,int kind))。
返回 bool,kind 1=h / 2=v —— 与 `(bool)(vt+0xe8)(self,1/2)` 吻合:
**= "滚动条可见?" 查询(0x7546=h,0x7548=v)**。

同族槽旁证(均 thunk→真体,+0x10 结构体参数):
- +0xc0(0x753f)= FUN_00948b9b→FUN_00948b5a:滚动条 2 dynamic_cast,命中则 FUN_00a1d782
- +0xf8(0x754b/c)= FUN_00948b12→FUN_00948ab0(self,int,bool):
  kind==1 ? hPolicy : vPolicy;policy!=2 时 setXxxScrollBarPolicy(this+0x1258, arg^1)
- +0xd0(0x754a)= FUN_00948c89→FUN_00948c3e:vbar dynamic_cast 命中 → FUN_00a1d83a

## 方法论勘误补充
- 槽 N 语义双源核对法:.data.rel.ro 值 + 语料 thunk 体(0x948xxx 层)必须同读;
  -0x10 偏移的 thunk(语料 `FUN_0094xxxx(param_1 + -0x10)`)是 Qt 多重继承
  sub-object 调整,不是独立函数。
- CheckEditor(0x8efe12)同型:`this+8→[+0x28]` 判空 → 0x11937c0(另一 typeinfo/vptr),
  与 Editor 族并行存在,勿混淆。
