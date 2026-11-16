# WindTerm 2.7.0 — 逆向重建工程

本仓库是 **WindTerm 2.7.0 的行为等价重建**(含原版 bug 原封不动)。
不是上游源码,也不是可运行的发行版 —— 是**按反编译语料逐函数转写的重建代码**。

## 基线(以二进制为准)

| 项 | 位置 |
|---|---|
| 基线二进制 | `./WindTerm`(2.7.0,`sha256 9491b87e…7469f54`) |
| 主反编译语料 | `tools/re/decomp/*.c`(49M,每函数带 `entry=ADDR` 头) |
| 运行时依赖库 | `/opt/WindTerm_2.7.0/lib`(Qt5,跑原版用) |
| 数据面参考 | `terminal/` `global/`(→ `wind.actions` 等) |

## 纪律(必读)

完整规则见 **`AGENTS.md`**;三条最常触发:

1. **每行代码有出处**(`FUN_XXXXXXXX` / 语料行),禁止捏造;
2. **bug 原封不动**,发现疑似 bug 只记 `docs/quirks.md`;
3. **不编译、不测试**(`tests/` 已删),只做语料转写 + commit。

## 目录

```
AGENTS.md                铁律 / 基线 / 工具优先 / 踩坑 18 条
src/                     重建代码(Actions/Editor/Sessions/Widgets/…)
src/Scintilla/           上游 Scintilla 4.4.6(标准 SCI_* 委托)
tools/re/decomp/         反编译语料(主语料)
tools/re/*.py            语料检索与 QMetaObject 提取工具
docs/index.md            文档总目录(从这里进)
docs/pending-attribution.md  收尾期工作单(编译前第一步)
lib/*.a                  预构建静态库(构建直接链接)
```

## 构建与测试

**不在本仓库文档范围内**(铁律 7:平时不编译不测试)。何时构建、如何链接、
验收顺序,一律按用户当时指令执行;`tests/` 已删除,不恢复。

---
上游 WindTerm 的功能/性能说明已按文档重整移除(与逆向重建无关;
`license.txt` 仍保留)。
