# AGENTS.md — 本仓库工作规则（对所有 agent 生效）

项目：WindTerm 2.7.0 GUI 骨架还原。目标=仅界面不含逻辑；方法=逆向证据驱动。
完整证据链见 `docs/`（phase2–7 + visual-acceptance）。

## 铁律：证据优先级

**反汇编/反编译代码 ≥ 原始开源代码（WindTerm/src） > 原版数据文件 > 截图 > 直觉**

- 布局、结构、行为一律以反汇编归属与反编译为准；截图只用于最终验收对照，**禁止**从截图推算结构。
- 历史教训：曾按截图把 Explorer/Session 放右侧、Filer 放上——后被反汇编证伪（col 是 Qt::Vertical 三条水平带 [1000,4000,1000]）。见 docs/phase7-findings.md。
- 反汇编与截图冲突时，改代码向反汇编对齐，同时注明"静态近似 vs 原版运行时插入"的边界。

## 陷阱清单（均已踩过，勿重复）

### 逆向（Ghidra/objdump）
1. **Ghidra 伪代码丢失 this 参数**：`addWidget(arg)` 看不出是哪个 splitter 在 add——伪代码只能做导航，树结构必须回读汇编 `mov rdi/rsi` 归属（phase7 教训）。
2. **objdump 反汇编正则**：`地址: 机器码字节  助记符`——冒号后是字节列，`':\s+jmp'` 匹配不到，须 `':.*jmp'`（`call` 同理）。PLT 定位：先 objdump -R 拿 GOT 槽地址，再在反汇编里找 `# <槽地址>` 的 jmp 存根。
3. **导入表反查优于字符串/xref 链**：`QMenuBar::addMenu` 全二进制仅 1 个调用点，一步定位构建器。
4. **CMAKE_DISABLE_FIND_PACKAGE_Qt6 对 REQUIRED find_package 会直接报错**，不能用它做 Qt5 强制。
5. REA 大结果（list_procedures/list_names）会超 10MB MCP 缓冲——用 summary/分页，别全量拉。

### 构建
6. **`find_package(QT NAMES Qt6 Qt5)` 在双 Qt 共存机器上永远选 Qt6**（与顺序无关，已最小复现）→ 本仓库已改为显式 `find_package(Qt5 QUIET)` 优先，勿改回 NAMES 写法。
7. CMake 把产物固定输出到 `<repo>/bin/`：即使 `cmake -B /tmp/xxx`，可执行文件仍写进仓库 bin/——临时实验构建要记得清理。
8. 本机 Qt5 与 Qt6 并存；提交前验证一律用 Qt5 分支跑（当前 CMake 已 Qt5 优先）。

### Qt
9. **QDockWidget 模型是错的**：原版布局是嵌套 QSplitter（导入表零 dock 函数）。勿再引入 dock。
10. `QDockWidget::setCollapsed()` 不存在（Qt5/6 均无）。
11. `WA_DeleteOnClose` 要求 MainWindow 堆分配（main.cpp 已是 `new`，勿改回栈对象）。
12. **QSettings 的 restoreState 连 orientation 一起恢复**：旧保存状态会让新代码设置的方向失效——已解决：持久化键带布局版本前缀 `layout.v2/splitter_<objectName>`（MainWindow 的 LAYOUT_VERSION 常量），布局结构变化时升 v3 即可让旧状态自然失效；恢复时 `!restoreState(state)` 的状态直接忽略。**每次调整布局结构必须记得升版**。
13. `Q_UNIMPLEMENTED()` 占位槽每次触发会打运行时警告，属预期。
14. locale 查表 key 不含 `&` 助记符：先剥离再查；菜单标题的 `标题 + " (&N)"` 数字模式是另一套（复刻二进制格式串 `(&%1)`），勿混淆。

### 数据文件（全部非严格 JSON）
15. `wind.config`：BOM + CRLF + `//` 行尾注释（且 `https://` 会被朴素剥离误伤）——必须**字符串感知**地剥注释（`JsonText::stripLineComments`）。
16. `wind.actions`：字符串内含裸控制字符（脚本换行）——需净化控制字符后再 `QJsonDocument::fromJson`，失败退正则（`ActionRegistry` 已实现）。
17. 资产/配置路径一律用 `Assets::dir()`（exe 同级 `../assets` 优先，CWD 回退）——纯相对路径在换目录启动时静默丢主题（曾致用户截图为浅色默认样式）。

### 协作
18. 子代理只拥有声明过的路径（本仓库惯例：fixer=src/**，docs/tools/git 由主 agent 做）；其"完成"声明必须亲自重新构建 + 离屏运行核验后才提交。
19. 证据冲突时禁止"按看起来合理的方向"自行纠正——升级给需求方（col 方向事件：fixer 自行改 Horizontal 被要求改回）。
20. 关键步骤必须 git 提交（历史惯例：docs 发现、每次结构重写、每次验证闭环各一个 commit）。

## 验证基线

```bash
cmake -B build && cmake --build build -j4   # Qt5 优先，产物在 bin/
QT_QPA_PLATFORM=offscreen timeout 5 ./bin/WindTermGuiSkeleton   # 冒烟（存活到超时=OK）
```

零警告 + 离屏运行存活 = 可提交的最低标准；改布局后须断言 splitter 树方向/计数/比例。
