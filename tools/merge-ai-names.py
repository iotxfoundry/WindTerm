#!/usr/bin/env python3
# 合并 AI 命名批次结果 → 校验 → 并入 symbols.tsv
# 用法: python3 tools/merge-ai-names.py /tmp/opencode/ai-batches/result-1.tsv result-2.tsv ...
import os, re, sys, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TSV = os.path.join(ROOT, "reference", "symbols.tsv")
NAME_OK = re.compile(r"^[A-Za-z_][A-Za-z0-9_]{0,60}$")

def main():
    paths = sys.argv[1:] or sorted(glob.glob("/tmp/opencode/ai-batches/result-*.tsv"))
    merged = {}
    conflicts = 0
    for p in paths:
        if not os.path.exists(p):
            print(f"WARN 缺失 {p}"); continue
        for line in open(p, encoding="utf-8"):
            line = line.strip()
            if not line or line.startswith("#"): continue
            parts = line.split("\t")
            if len(parts) < 3: continue
            addr = "0x" + parts[0].removeprefix("0x").lower().zfill(16)
            name, ev = parts[1].strip(), parts[2].strip()
            if not NAME_OK.match(name):
                print(f"INVALID {addr} {name!r}"); continue
            if addr in merged and merged[addr][0] != name:
                conflicts += 1  # 多批次冲突：保先到
                continue
            merged[addr] = (name, ev)
    # 排除已有符号
    existing = set()
    for line in open(TSV, encoding="utf-8"):
        if line.startswith("#") or not line.strip(): continue
        p = line.split("\t")
        if p: existing.add(p[0].lower().zfill(16))
    new = {a: v for a, v in merged.items() if a not in existing}
    with open(TSV, "a", encoding="utf-8") as fp:
        fp.write("\n# —— AI 理解批（fixer 阅读，证据列=一句话依据）——\n")
        for a, (name, ev) in sorted(new.items()):
            fp.write(f"0x{int(a,16):016x}\t{name}\t{ev}\n")
    print(f"输入 {sum(1 for _ in paths)} 文件 → 合并 {len(merged)}，冲突 {conflicts}，新增 {len(new)}")

if __name__ == "__main__":
    main()
