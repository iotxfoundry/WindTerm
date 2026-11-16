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
2. **bug 原封不动**,发现疑似 bug 只记 `docs/QUIRKS.md`;
3. **不编译、不测试**(`tests/` 已删),只做语料转写 + commit。

## 目录

```
AGENTS.md                铁律 / 基线 / 踩坑 22 条
src/                     重建代码(Actions/Editor/Sessions/Widgets/…)
src/Scintilla/           上游 Scintilla 4.4.6(标准 SCI_* 委托)
tools/re/decomp/         反编译语料(主语料)
tools/re/*.py            语料检索与 QMetaObject 提取工具
docs/INDEX.md            文档总目录(从这里进)
docs/PENDING-ATTRIBUTION.md  收尾期工作单(编译前第一步)
lib/*.a                  预构建静态库(构建直接链接)
```

## 收尾期(唯一允许编译测试的阶段)

语料锚定段全清后:清归属工作单 → 全量编译修错 → dlopen 零 undefined →
装配 `main` → Xvfb 截图 vs `./WindTerm` 对表。

---
上游项目说明(功能清单/性能对比,非本仓库内容)见
[`docs/UPSTREAM-README.md`](docs/UPSTREAM-README.md)。
