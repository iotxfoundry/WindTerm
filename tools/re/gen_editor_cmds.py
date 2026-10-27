#!/usr/bin/env python3
"""Extract the cmd->action table from the editor engine dispatcher
(FUN_00a418c4, 37951B) Ghidra decompile in tools/re/decomp/.

Indentation-based walker: each `param_3 == 0x...` comparison opens a
leaf block; action lines are the ones indented deeper, until the next
structural line at the same-or-lower indent.

Usage: gen_editor_cmds.py [corpus.c] > out.md
"""
import re
import sys

path = sys.argv[1] if len(sys.argv) > 1 else 'tools/re/decomp/decomp-part-0034.c'
lines = open(path, encoding='utf-8', errors='replace').read().splitlines()

start = next(i for i, l in enumerate(lines) if 'entry=00a418c4' in l) + 1
end = next(i for i, l in enumerate(lines) if i > start and l.startswith('// ==== entry='))
body = lines[start:end]

eq = re.compile(r'param_3 == (0x[0-9a-f]+)')
call = re.compile(r'\b((?:FUN_|s_|session_|props_|runstyles_|QVariant::|QString::|QByteArray::)[A-Za-z0-9_:]+)\(')
vslot = re.compile(r'\(\*\*\(code \*\*\)\(\*param_2 \+ (0x[0-9a-f]+)\)\)')
ptrwrite = re.compile(r'param_2\[(0x[0-9a-f]+)\] =')
mwrite = re.compile(r'\*\(undefined[48]? \*\)\(param_2 \+ (0x[0-9a-f]+)\) =')

def indent(s):
    return len(s) - len(s.lstrip(' '))

# collect leaf headers
idx = [(i, int(eq.search(l).group(1), 16), indent(l))
       for i, l in enumerate(body) if eq.search(l)]

rows = []
for k, (i, cmd, ind) in enumerate(idx):
    stop = idx[k + 1][0] if k + 1 < len(idx) else len(body)
    calls, vslots, writes = [], [], []
    j = i + 1
    while j < stop and j < i + 40:
        l = body[j]
        if l.strip() and indent(l) <= ind:
            break  # structural line closes this leaf
        for c in call.findall(l):
            if c not in calls:
                calls.append(c)
        for v in vslot.findall(l):
            if 'vt+' + v not in vslots:
                vslots.append('vt+' + v)
        for w in ptrwrite.findall(l) + mwrite.findall(l):
            if '+' + w not in writes:
                writes.append('+' + w)
        j += 1
    rows.append((cmd, calls[:4], vslots[:2], writes[:4]))

def seg(c):
    if c <= 2400: return 'SCI'
    if 20173 <= c <= 20228: return 'EXT'
    if 30001 <= c <= 30166: return 'WT'
    return '?'

print('| cmd | dec | 段 | 实现/动作 | 成员写入 |')
print('|---|---|---|---|---|')
for cmd, calls, vslots, writes in sorted(rows):
    acts = ' '.join((calls + vslots) or ['inline'])
    print(f'| 0x{cmd:x} | {cmd} | {seg(cmd)} | {acts} | {" ".join(writes) or "-"} |')
print(f'\n{len(rows)} ==-leaves captured of {len(idx)} comparisons')
