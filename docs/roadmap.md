# 还原路线（GUI 骨架）

目标：**可编译、可运行的 Qt Widgets 工程**，复现 WindTerm 界面壳（窗口/面板/菜单/主题/文案），slot 全部留空——能看，不连接。

## 阶段

### Phase 1 — 工程骨架（本次交付）
- CMake + Qt5（≥5.15）Widgets 工程
- 类声明还原自二进制元数据（命名保持一致）：`MainWindow`、`FilerPane`、`SessionPane`、`OutlinePane`、`SenderPane`、`TransferPane`、`MuxPaneGroup`、`CommandButtonBar` 等
- 主窗口布局按截图组装：菜单栏 9 项 + 左/右/底停靠面板 + 彩色会话标签 + 状态栏 + 命令按钮栏
- `ThemeManager` / `LocaleManager`：从外部 assets 目录加载主题与 1,414 条文案（结构兼容 `global/` 布局）
- 占位内容：文件树/会话树/命令历史用静态示例数据

### Phase 2 — 构造函数级精修
- REA 链式定位：RTTI typeinfo → vtable → `MainWindow::MainWindow` 构造函数伪代码
- 逐面板恢复真实 `addWidget/addLayout/setSpacing/setContentsMargins` 结构
- 对话框骨架补齐：`MasterPasswordDialog`、会话设置、Session 弹窗等

### Phase 3 — 视觉打磨
- 从伪代码提取代码内拼接的 qss 样式
- 自绘控件（标签页形状、时间戳槽、按钮徽标）逐个 `paintEvent` 分析
- 主题切换 / 布局持久化（`wind.config`/`wind.keymaps` 解析）

## 明确不做
- Session/SSH/SFTP/协议逻辑（用户明确排除）
- 终端仿真（vt100/xterm 状态机）
- 行为级还原（slot 留空）

## 验证标准
1. `cmake && make` 零警告通过（Qt 5.15）
2. 运行后主窗口与截图逐区域对照：菜单栏/四组停靠面板/标签栏/按钮栏/状态栏齐全
3. 主题资产与文案可加载（切换 zh-CN 标题可见中文）

## 环境依赖
```bash
sudo apt install qtbase5-dev cmake g++   # qtbase5-dev 候选 5.15.13，当前未装（sudo 需密码）
```
未安装前交付物以代码正确性为准，编译验证挂起（见 investigation.md §4.3）。

## 资产接入
不把 103MB 发行包拷进仓库；用 `tools/fetch-assets.sh` 从本机发行包路径复制所需子集（themes 的 images/fonts + locales）。
