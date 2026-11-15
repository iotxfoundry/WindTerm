#!/usr/bin/env python3
# 批 180 — reopen.history 全帧字节对表解析器(框架级;铁律 1:结构
# 锚全部出自语料 0076073a/007669b2/008cf0c8 + 原版 789B 样本位级反推,
# 零发明)。用法: parse_reopen_frame.py <reopen.history> [>输出]
import struct, sys

def rdba(d, o):
    n, = struct.unpack_from('>i', d, o); o += 4
    if n < 0: return None, o
    return d[o:o+n], o+n

def parse(path):
    d = open(path, 'rb').read()
    out = {'size': len(d)}
    o = 0
    out['magic'] = '%08x' % struct.unpack_from('>I', d, o)[0]; o += 4   # @0076076f
    cnt, = struct.unpack_from('>i', d, o); o += 4                      # @00760780 窗数
    out['windows'] = cnt
    for i in range(cnt):
        g, o = rdba(d, o)                                               # +0x10 geometry
        p, o = rdba(d, o)                                               # +0x18 payload
        b = d[o]; o += 1                                                # +0x08 focusMode
        out[f'win{i}'] = {'geom': len(g) if g is not None else 'null',
                          'payload': len(p) if p is not None else 'null',
                          'focus': b}
        if p:
            out[f'win{i}.pages'] = parse_pages(p)
    out['consumed'] = o
    return out

def parse_pages(p):  # FUN_007669b2 窄面: count/current/逐页(名+payload)
    o = 0; res = []
    cnt, = struct.unpack_from('>i', p, o); o += 4
    cur, = struct.unpack_from('>i', p, o); o += 4
    res += [('count', cnt), ('current', cur)]
    for _ in range(cnt):
        nl, = struct.unpack_from('>i', p, o); o += 4
        name = p[o:o+nl].decode('utf-16-be'); o += nl
        pl, o = rdba(p, o)
        res.append({'name': name,
                    'payload': len(pl) if pl is not None else 'null',
                    'kit': parse_kit(pl) if pl and pl[:4] == b'\xb9\xe7\xe6\x26' else None})
    return res

def parse_kit(k):  # FUN_008cf0c8 骨架帧: magic+blobA+blobB+blobC(+尾钩段)
    ko = 4
    magic = struct.unpack_from('>I', k, 0)[0]
    a, ko = rdba(k, ko); bb, ko = rdba(k, ko); c, ko = rdba(k, ko)
    tail = k[ko:]
    return {'blobA': parse_blobA(a) if a else None,
            'blobB': parse_blobB(bb) if bb else None,
            'blobC': c.hex() if c is not None else 'null',
            'tail': {'len': len(tail), 'hex': tail.hex()}}

def parse_blobA(a):  # 批 177 判例: [count][tab BA]×count[ss BA] 逐 splitter
    o = 0; res = []
    while o < len(a):
        cnt, = struct.unpack_from('>i', a, o); o += 4
        tabs = []
        for _ in range(cnt):
            t, o = rdba(a, o)
            tabs.append(len(t) if t is not None else 'null')
        ss, o = rdba(a, o)
        res.append({'count': cnt, 'tabs': tabs,
                    'ss': len(ss) if ss is not None else 'null'})
    return res

def parse_blobB(bb):  # 旗标 + [0xb/0xc] 表逐 saveState + flags&1 LastSessions 组块
    o = 0; flag = bb[o]; o += 1
    segs = []
    while o < len(bb):
        try:
            n, = struct.unpack_from('>i', bb, o)
        except struct.error:
            break
        if n < 0 or o+4+n > len(bb): break
        segs.append(n); o += 4 + n
    rest = bb[o:]
    return {'flag': flag, 'saveStates': segs,
            'lastSessions': {'off': o, 'len': len(rest), 'hex': rest.hex()}}

for path in sys.argv[1:]:
    print('==', path, '==')
    r = parse(path)
    import json; print(json.dumps(r, ensure_ascii=False, indent=1))
    print('frame-consumed==size:', r['consumed'] == r['size'])
