# WindTerm 2.7.0 还原可行性调查

日期：2026-10-22 · 调查对象：发行包 `WindTerm_2.7.0/`（Linux）+ 部分开源源码 `WindTerm/`

## 1. 现有材料

### 发行包（103MB）
| 项 | 事实 |
|---|---|
| 主程序 `WindTerm` | 12.3MB，ELF x86-64，**已完全 strip**（无 `.symtab`/`.debug_*`） |
| 运行库 | Qt 5.6（ICU 56）、libssh.so.4、OpenSSL 1.1，全部随包捆绑 |
| 数据资产 | `global/`（4 套主题、33 个语言包、keymaps、actions、config）、`terminal/`（schemes/protocols/configs）、`vendors/`（lrzsz） |

### 部分源码 `WindTerm/`（8.4MB，529 文件）
README 原话：*"WindTerm is a **partial** open source project"*。
- `src/libssh` 4.7M、`src/Onigmo` 3.6M —— 第三方库完整源码
- 真正属于应用自身的仅 **~150KB / 25 文件**（Protocols / Pty / Utility / Widgets）
- **整个 GUI 主程序从未开源**

## 2. 二进制泄露面（实测）

| 可恢复 | 不可恢复 |
|---|---|
| 动态符号 6,323 个 | 函数名、变量名 |
| RTTI 类名 465 个 | 类型签名、类/成员内存布局 |
| Qt 元对象字符串：数百个类名 + signals/slots 签名 | 模板实例、宏、注释 |
| 命名空间：boost/spdlog/YAML/Tmux/Lang/tcl/dtl/Ssh | 全部逻辑行为细节 |

典型类名（`strings` 直接可见）：`MainWindow`、`CommanderView`、`FilerPane`、`ExplorerPane`、`KitPane`、`MuxPane(Group)`、`FindInFilesPane`、`OutlinePane`、`OutputPane`、`SshBridge/Session/Commander`、`SerialSession`、`SftpTransfer`、`MasterPasswordDialog` 等。

## 3. REA + Ghidra 实测探针

- Ghidra 12.1.4 可正常导入并完成自动分析
- **47,980 个函数**、15,768 个字符串被识别
- `main()` 反编译样例（Evidence `ev_4ae457d1…`）：

```c
undefined4 main(undefined4 param_1, undefined8 param_2) {
  QCoreApplication::setAttribute(0x14,1);   // 枚举退化为魔数
  ...
```

- 二进制 sha256：`9491b87eec5c4482f34a01cca78be6ecbf5f7f427278dcec48eb7d20a7469f54`
- 函数级命名全部丢失（`search_procedures("Ssh")` 命中 0），需要 RTTI→vtable→构造函数链式定位

## 4. 结论

### 4.1 完整还原"原始能够编译"的源码：**不可行**
1. C++ 反编译产物是 C 伪代码，无类定义/头文件/成员布局/虚表/moc 元对象——这些是"能编译"的前提，原理上不可恢复
2. 规模：~4.8 万函数 ≈ 估计 50–100 万行原始 C++，人力以人年计
3. 属有意的闭源策略（作者只开源可独立复用的工具库）

### 4.2 仅还原 GUI 界面（不含逻辑）：**可行**，依据三根证据支柱
1. **视觉资产零成本**：`global/themes/` 4 套主题，含完整 SVG 图标库、字体（RobotoMono/FiraCode/NerdFont）、音效
2. **全部 UI 文案**：`global/locales/*.locale` 为 JSON（en/tr 对），zh-CN 含 **1,414 条**完整界面文案；菜单结构可见：File/Edit/Connection/Session/Panes/Layout/Keyboard/Help…
3. **控件结构可恢复**：Qt 元数据给出类名与信号槽签名；截图给出实际布局；构造函数伪代码（`addWidget/addLayout/setSpacing` 序列）可恢复窗口树
4. **主窗口实际布局**（来自 `images/screenshots/WindTerm.png`）：
   - 菜单栏：Session / Edit / Search / Selection / Goto / View / Mode / Window / Help
   - 左停靠：Filer 面板（文件树，Name/Date 列，路径面包屑）
   - 中央：彩色会话标签页（Mux）+ 终端视图
   - 右停靠：Session 面板（会话树）+ Outline 面板（命令历史）
   - 底部停靠：Sender | Transfer 标签页（传输进度条）
   - 底部命令按钮栏（对应 `global/wind.actions`：File/Copy/Move/…、Network/ping/traceroute/…、Shell/ls/cat/vi、System/reboot/crontab）
   - 状态栏：Ready · Remote Mode · Ln/Ch · 主机 · 时间 · WindTerm

### 4.3 已知限制
- 自绘控件 `paintEvent` 像素级效果需逐函数啃，首版骨架只保证"结构 + 主题正确"
- qss 样式为代码内拼接，需从伪代码提取，首版以主题资产近似
- 本机无 Qt5 开发头文件（`qtbase5-dev` 未安装，sudo 需密码），编译验证待环境就绪

## 5. 证据索引
- Ghidra 会话 Evidence：`ev_45154b27…`（overview：47,980 函数）、`ev_4ae457d1…`（main 伪代码）、`ev_b2e0dfc0…`（过程清单 >10MB）
- 截图参照：`WindTerm/images/screenshots/WindTerm.png`、`SplitView.png`、`WindTerm_DigeWhite_Theme.png`
