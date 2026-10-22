#!/usr/bin/env python3
# 从 reference/full 推断未命名函数的名字：
#   ① 字符串指纹：函数体引用的标识型字面量（配置键/动作id/类名）→ s_<slug>_<addr6>
#   ② 调用者归属：无名函数的调用者 ≥80% 同一类前缀 → <Class>_h<addr6>
# 输出 symbols-inferred.tsv（addr, name, evidence），不与 symbols.tsv 重复。
import os, re, sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FULL = os.path.join(ROOT, "reference", "full")
OUT = os.path.join(ROOT, "reference", "symbols-inferred.tsv")

cur = None
HDR = re.compile(r"^// ==== entry=([0-9a-f]+) .*====$")
STR = re.compile(r'"((?:[^"\\]|\\.){4,60})"')
CALL = re.compile(r"\b(FUN_[0-9a-f]{6,8})\(")

# 噪声字面量（Qt 通用/格式串/协议词）
NOISE = re.compile(r"^(utf-?8|ascii|png|svg|json|true|false|%\d|[%#{}\[\]<>=+\-*/ ]+|[0-9.]+|"
                   r"application/octet-stream|text/plain|about:blank|http|https|localhost)$", re.I)
# 标识型：含 _/. :: 或驼峰≥6 或已知前缀
IDENT = re.compile(r"^(king::|[a-z]+\.[a-z][A-Za-z0-9_.]{3,40}|[A-Za-z][A-Za-z0-9_]*::[A-Za-z][A-Za-z0-9_]*|"
                   r"[A-Z][a-z0-9]+[A-Z][A-Za-z0-9]{3,40}|[a-z][a-z0-9]*_[a-z][a-z0-9_]{3,40})$")

def slug(s, maxlen=36):
    s = re.sub(r"[^A-Za-z0-9_]", "_", s).strip("_")
    return s[:maxlen].strip("_") or "lit"

funcs = {}          # addr -> dict(name, strs=[], calls=[])
callers = defaultdict(set)
for fn in sorted(os.listdir(FULL)):
    if not fn.endswith(".c"):
        continue
    for line in open(os.path.join(FULL, fn), encoding="utf-8", errors="ignore"):
        m = HDR.match(line)
        if m:
            cur = m.group(1)
            nm_m = re.search(r"(?:^| )name=(\S+)", line)
            nm = nm_m.group(1) if nm_m else "FUN_" + cur
            funcs[cur] = {"name": nm, "strs": [], "calls": []}
            continue
        if cur is None or not line.startswith((" ", "\t", "}")):
            if line and not line.startswith("//"):
                cur0 = cur
            continue
        for s in STR.findall(line):
            if not NOISE.match(s) and IDENT.match(s):
                funcs[cur]["strs"].append(s)
        for c in CALL.findall(line):
            funcs[cur]["calls"].append(c)
            callers[c[4:] if c.startswith("FUN_") else c].add(cur)

# 已具名地址集合
named = {a for a, f in funcs.items() if f["name"] != "FUN_" + a}

out, seen_names = [], set()
def emit(addr, name, ev):
    if addr in named or not name or name in seen_names:
        return False
    seen_names.add(name)
    out.append(f"0x{addr}\t{name}\t{ev}")
    return True

n_str = n_owner = 0
# ① 字符串指纹：取最长标识字面量
for addr, f in sorted(funcs.items()):
    if not f["strs"]:
        continue
    lit = max(f["strs"], key=len)
    a6 = addr.lstrip("0")[-6:]
    if emit(addr, f"s_{slug(lit)}_{a6}", f"字面量 {lit[:48]!r}"):
        n_str += 1

# ② 调用者归属：未命名 & 调用者≥2 且 ≥80% 同类前缀（NamedFoo / NamedFoo_xxx）
CLS = re.compile(r"^([A-Z][A-Za-z0-9]{2,30})(?:_|$)")
for addr, f in sorted(funcs.items()):
    if addr in named:
        continue
    cs = [funcs[c]["name"] for c in callers.get(addr, ()) if c in funcs]
    if len(cs) < 2:
        continue
    from collections import Counter
    prefixes = Counter()
    for c in cs:
        m = CLS.match(c)
        if m:
            prefixes[m.group(1)] += 1
    if not prefixes:
        continue
    cls, cnt = prefixes.most_common(1)[0]
    if cnt / len(cs) >= 0.8 and cnt >= 2 and cls not in ("FUN", "qt", "Q"):
        a6 = addr.lstrip("0")[-6:]
        if emit(addr, f"{cls}_h{a6}", f"调用者归属 {cls}（{cnt}/{len(cs)}）"):
            n_owner += 1

with open(OUT, "w") as fp:
    fp.write("# 自动推断符号（tools/infer-names.py）——s_=字面量指纹 / _h=调用者归属\n")
    fp.write("\n".join(out) + "\n")
print(f"推断完成：字符串指纹 {n_str}，调用者归属 {n_owner}，共 {len(out)}")
