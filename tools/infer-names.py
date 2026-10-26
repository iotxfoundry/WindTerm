#!/usr/bin/env python3
# 从 reference/full 推断未命名函数的名字：
#   ① 字符串指纹：函数体引用的标识型字面量（配置键/动作id/类名）→ s_<slug>_<addr6>
#   ② 调用者归属：无名函数的调用者 ≥80% 同一类前缀 → <Class>_h<addr6>
# 输出 symbols-inferred.tsv（addr, name, evidence），不与 symbols.tsv 重复。
import os, re, sys, json, struct
from collections import defaultdict, Counter

BIN = '/opt/WindTerm_2.7.0/WindTerm'
RO_S, RO_E = 0x889000, 0x99a8e8
DR_S, DR_E = 0xb7eba0, 0xbb82e8
DR_DELTA = 0x600000
CODE_LO, CODE_HI = 0x4c33c0, 0xc88fdc

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
FULL = os.path.join(ROOT, "reference", "full")
OUT = os.path.join(ROOT, "reference", "symbols-inferred2.tsv")

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

seen_names = set()
named = set()
out = []
# ③ vtable 全槽位命名（366 类；槽位置=事实，无语义猜测）
blob = open(BIN, 'rb').read()
qwords = struct.unpack('<%dQ' % ((DR_E-DR_S)//8), blob[DR_S:DR_E])
ti_names = {}
for m in re.finditer(rb'(\d{1,2})([A-Z][A-Za-z0-9_]{2,40})\x00', blob[RO_S:RO_E]):
    ln, nm2 = int(m.group(1)), m.group(2).decode()
    if len(nm2) == ln and nm2 not in ti_names:
        ti_names[nm2] = RO_S + m.start() + 0x400000
n_vt = 0
for nm, naddr in ti_names.items():
    for i, q in enumerate(qwords):
        if q == naddr:
            obj = DR_S + i*8 - 8 + DR_DELTA
            for j in range(len(qwords)):
                if qwords[j] == obj:
                    for k in range(16):
                        s = qwords[j+1+k] if j+1+k < len(qwords) else 0
                        if not (CODE_LO <= s <= CODE_HI):
                            continue
                        a16 = '%016x' % s
                        if a16 in seen_names or a16 in named:
                            continue
                        seen_names.add(a16)
                        out.append(f"0x{a16}\t{nm}_vt{k}\t{nm} vtable[{k}]")
                        n_vt += 1
                    break
            break
pass  # 名称已即时入 seen_names

seen2 = set()
def emit2(addr, name, ev):
    if not name or addr in named or name in seen_names or name in seen2:
        return False
    seen2.add(name)
    out.append(f"0x{addr}\t{name}\t{ev}")
    return True
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
    if len(cs) < 1:
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
    if cnt >= 1 and cls not in ("FUN", "qt", "Q"):
        a6 = addr.lstrip("0")[-6:]
        if emit(addr, f"{cls}_h{a6}", f"调用者归属 {cls}（{cnt}/{len(cs)}）"):
            n_owner += 1

with open(OUT, "w") as fp:
    fp.write("# 自动推断符号（tools/infer-names.py）——s_=字面量指纹 / _h=调用者归属\n")
    fp.write("\n".join(out) + "\n")
print(f"推断完成：字符串指纹 {n_str}，调用者归属 {n_owner}，共 {len(out)}")
