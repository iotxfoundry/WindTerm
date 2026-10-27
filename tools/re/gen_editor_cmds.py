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

args = [a for a in sys.argv[1:] if a != '--cpp']
path = args[0] if args else 'tools/re/decomp/decomp-part-0034.c'
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

# --- --cpp mode ---------------------------------------------------------
# Emits reference-tier scaffolding for leaves NOT already hand-wired in
# EditorEngine.cpp: one generic thunk per impl address (uniform
# (engine, a, b) signature; arg conversion documented in the comment)
# plus a dispatch switch. Member-write-only leaves become inline
# assignments against known layout offsets.
if '--cpp' in sys.argv:
    import re as _re
    wired = set()
    try:
        src = open('src/Sessions/EditorEngine.cpp', encoding='utf-8').read()
        wired = {int(m, 16) for m in _re.findall(r'case 0x([0-9a-f]+):', src)}
    except OSError:
        pass
    members = {}
    try:
        hdr = open('src/Sessions/EditorEngine.h', encoding='utf-8').read()
        for m in _re.finditer(r'(\w+)\s*(?:\[\d*\])?;\s*//\s*\+(0x[0-9a-f]+)', hdr):
            members.setdefault(int(m.group(2), 16), m.group(1))
    except OSError:
        pass
    # reuse `rows` from the walker above but re-walk with full detail
    detail = []
    for k, (i, cmd, ind) in enumerate(idx):
        stop = idx[k + 1][0] if k + 1 < len(idx) else len(body)
        seg = body[i:stop]
        sub = [int(x, 16) for x in _re.findall(r'param_3 == (0x[0-9a-f]+)', '\n'.join(seg[1:]))]
        if sub:
            continue  # spine node, not a leaf
        text = '\n'.join(seg)
        impl = []
        for c in _re.findall(r'\b((?:FUN_|s_|session_|props_|runstyles_|buf_|editctx_|editor_)[A-Za-z0-9_]+)\(', text):
            if c not in impl:
                impl.append(c)
        conv = []
        for c in _re.findall(r'QVariant::to(\w+)', text):
            if c not in conv:
                conv.append(c)
        wr = []
        for w in _re.findall(r'param_2\[(0x[0-9a-f]+)\] =|\(param_2 \+ (0x[0-9a-f]+)\) =', text):
            w = w[0] or w[1]
            if w not in wr:
                wr.append(w)
        ret = 'QVariant::QVariant(param_1' in text
        detail.append((cmd, impl, conv, wr, ret))

    thunks, cases = [], []
    for cmd, impl, conv, wr, ret in sorted(detail):
        if cmd in wired:
            continue
        tag = f'0x{cmd:x}'
        seg = 'SCI' if cmd <= 2400 else ('EXT' if cmd <= 20228 else ('WT' if cmd <= 30166 else '?'))
        if len(impl) == 1 and len(conv) <= 2 and len(wr) <= 1:
            fn = impl[0]
            addr = _re.search(r'([0-9a-f]{6,})', fn)
            tname = 't_' + (addr.group(1) if addr else fn)
            sig = ', '.join(f'to{c}' for c in conv) or 'no args'
            if tname not in [t.split(' — ')[0] for t in thunks]:
                thunks.append(f'{tname} — {fn} (args: {sig})')
            cases.append(f'\tcase {tag}:  // {seg} {cmd}: {fn}, args {sig}'
                         f'\n\t\treturn t_call("{tname}", this, a, b);')
        elif len(impl) == 0 and len(wr) == 1:
            off = wr[0]
            m = members.get(int(off, 16))
            if m:
                cases.append(f'\tcase {tag}:  // {seg} {cmd}: member write +{off} -> {m}'
                             f'\n\t\t{m} = a.toInt();\n\t\treturn QVariant(0);')
            else:
                cases.append(f'\tcase {tag}:  // {seg} {cmd}: member write +{off} (unmapped)')
                cases.append('\t\treturn QVariant(0);')
        else:
            notes = ' '.join(impl[:3]) or 'inline'
            cases.append(f'\tcase {tag}:  // {seg} {cmd}: complex leaf ({notes}) — hand pass pending'
                         '\n\t\treturn QVariant(0);')
    print('\n// ==== generated thunk registry (impl address -> thunk) ====')
    for t in thunks:
        print(f'// {t}')
    print('// ==== generated switch ====')
    for c in cases:
        print(c)
