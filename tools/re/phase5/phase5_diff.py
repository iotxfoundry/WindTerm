#!/usr/bin/env python3
"""60 序列 diff 一键工具:跑我方 dump(可选)+ 原版 dump(可选)+ diff。
用法:phase5_diff.py [ours] [orig]   (任一参数 = 跳过对应 dump)
文件新鲜度校验:两侧 JSON mtime 差 > 600s 时告警。"""
import json, os, subprocess, sys, time

W = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
OURS = '/tmp/opencode/phase5_ours.json'
ORIG = '/tmp/opencode/phase5_original.json'
SEQ = os.path.join(W, 'tools/re/phase5/phase5_seq.json')

if 'ours' in sys.argv:
    env = dict(os.environ, LD_LIBRARY_PATH='/tmp/opencode/wtbuild2:/opt/WindTerm_2.7.0/lib',
               QT_PLUGIN_PATH='/opt/WindTerm_2.7.0/lib', QT_QPA_PLATFORM='offscreen')
    subprocess.run(['/tmp/opencode/wtbuild2/tests/engtest4'], env=env,
                   stdout=subprocess.DEVNULL, timeout=60, check=False)
if 'orig' in sys.argv:
    subprocess.run(['python3', os.path.join(W, 'tools/re/phase5/phase5_dump.py')],
                   timeout=400, check=False)

age = abs(os.path.getmtime(OURS) - os.path.getmtime(ORIG))
if age > 600:
    print(f'[warn] 两侧 JSON mtime 差 {age:.0f}s —— 可能跨会话/跨代码版本!')

orig = {s['name']: s['grid'] for s in json.load(open(ORIG))}
ours = {s['name']: s['grid'] for s in json.load(open(OURS))}
seqs = [s['name'] for s in json.load(open(SEQ))]
fails = 0; ok = 0; fails_names = []
for name in seqs:
    o, u = orig.get(name, {}), ours.get(name, {})
    bad = []
    if (o.get('curY'), o.get('curX')) != (u.get('curY'), u.get('curX')):
        bad.append(f"cur {o.get('curY')},{o.get('curX')} vs {u.get('curY')},{u.get('curX')}")
    for y in range(0, 5):
        ol = (o.get('lines', []) or [None]*5)[y] if y < len(o.get('lines', [])) else None
        ul = (u.get('lines', []) or [None]*5)[y] if y < len(u.get('lines', [])) else None
        ol = (ol or [])[:89]; ul = (ul or [])[:89]
        m = max(len(ol), len(ul)); ol += [0]*(m-len(ol)); ul += [0]*(m-len(ul))
        diff = [x for x in range(m) if ol[x] != ul[x]]
        if diff: bad.append(f"row{y}@{diff[:4]}(o={ol[diff[0]]},u={ul[diff[0]]})")
    if bad:
        fails += 1; fails_names.append(name); print(f'{name:14s} FAIL {" | ".join(bad)[:110]}')
    else: ok += 1
print(f'=== PHASE5: {ok}/{len(seqs)} MATCH, {fails} DIFFS: {fails_names}')
