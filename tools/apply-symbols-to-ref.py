#!/usr/bin/env python3
# 把 reference/symbols.tsv 的名字回写进 reference/full 分块文件头：
#   // ==== entry=<addr> name=<旧FUN名> ====  →  // ==== entry=<addr> orig=<旧名> name=<新名> ====
# 幂等可重复运行。
import os, re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TSV = os.path.join(ROOT, "reference", "symbols.tsv")
FULL = os.path.join(ROOT, "reference", "full")

# 读符号表：addr → name（后写优先，同 cracked 规则）
syms = {}
for line in open(TSV, encoding="utf-8"):
    line = line.rstrip("\n")
    if not line or line.startswith("#"):
        continue
    p = line.split("\t")
    if len(p) >= 2:
        syms[p[0].lstrip("0x0").lstrip("0") or "0"] = p[1]
# 规范 key：补零形式（entry=004b9110 的 10 位）
norm = {}
for k, v in syms.items():
    norm[k.zfill(16)] = v
    norm[str(int(k, 16))] = v

changed = files = 0
for fn in sorted(os.listdir(FULL)):
    if not fn.endswith(".c"):
        continue
    path = os.path.join(FULL, fn)
    lines = open(path, encoding="utf-8", errors="ignore").read().split("\n")
    mod = False
    for i, l in enumerate(lines):
        if l.startswith("// ==== entry=") and "name=" in l and "orig=" not in l:
            m = re.match(r"// ==== entry=([0-9a-f]+) name=(\S+?)(?: size=\d+)? ====", l)
            if not m:
                continue
            key = m.group(1).lstrip("0") or "0"
            new = norm.get(key.zfill(16)) or norm.get(str(int(key, 16)))
            if new:
                size_part = ""
                sm = re.search(r" size=\d+", l)
                if sm:
                    size_part = sm.group(0)
                lines[i] = f"// ==== entry={m.group(1)} orig={m.group(2)}{size_part} name={new} ===="
                mod = True
                changed += 1
    if mod:
        open(path, "w", encoding="utf-8", errors="ignore").write("\n".join(lines))
        files += 1
print(f"回写完成：{changed} 个函数头更新，覆盖 {files} 个分块文件")
