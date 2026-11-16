#!/usr/bin/env python3
"""vtable <-> typeinfo <-> class name 映射(非 PIE, RELATIVE 已落址).

Itanium ABI: vtable[0]=offset-to-top, vtable[1]=&typeinfo;
typeinfo: [0]=vptr, [1]=&name; name = "<len><class>" in .rodata。

用法:
  vtable_scan.py WindTerm                 # 打印全部映射
  vtable_scan.py WindTerm --vtable 0x11afd30
  vtable_scan.py WindTerm --addr 0x6b35a6  # 读该地址处的机器码,抽 mov imm 里的 vtable
"""
import subprocess, re, sys, struct

def elf(path):
    data = open(path, 'rb').read()
    out = subprocess.run(['readelf', '-SW', path], capture_output=True, text=True).stdout
    secs = []
    for m in re.finditer(r'\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', out):
        secs.append((m.group(1), int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16)))
    return data, secs

def read(data, secs, addr, n):
    for name, a, off, size in secs:
        if a <= addr < a + size:
            d = off + (addr - a)
            return data[d:d + n]
    return None

def q(data, secs, addr):
    b = read(data, secs, addr, 8)
    return struct.unpack('<Q', b)[0] if b and len(b) == 8 else None

def cstr_len(data, secs, addr):
    b = read(data, secs, addr, 160)
    if not b:
        return None
    m = re.match(rb'(\d{1,3})([A-Za-z_][A-Za-z0-9_]*)', b)
    if not m:
        return None
    n, s = int(m.group(1)), m.group(2).decode()
    if n != len(s) or b[len(m.group(0)):len(m.group(0)) + 1] != b'\x00':
        return None
    return s

def build(path):
    data, secs = elf(path)
    relro = [s for s in secs if s[0] == '.data.rel.ro'][0]
    _, base, off, size = relro
    # 1) typeinfo: .data.rel.ro 中指向 "<len>Name" 的指针
    ti = {}   # typeinfo_addr -> name
    for p in range(off, off + size, 8):
        v = struct.unpack('<Q', data[p:p + 8])[0]
        if v == 0:
            continue
        nm = cstr_len(data, secs, v)
        if nm:
            ti[base + (p - off) - 8] = nm      # typeinfo 起点 = name_ptr 槽 - 8
    # 2) vtable: 含 &typeinfo 的槽, vtable 起点 = 槽 - 8
    vt = {}
    for p in range(off, off + size, 8):
        v = struct.unpack('<Q', data[p:p + 8])[0]
        if v in ti:
            vt[base + (p - off) - 8] = ti[v]
    return data, secs, vt, ti

if __name__ == '__main__':
    path = sys.argv[1]
    data, secs, vt, ti = build(path)
    if '--selftest' in sys.argv:
        # 已知锚点:EnvironmentDialog ctor 0x6b35a6 写 0x11a2788
        assert vt.get(0x11a2788) == 'EnvironmentDialog', vt.get(0x11a2788)
        assert ti.get(0x11a2770) == 'EnvironmentDialog'
        print('selftest ok: %d vtables / %d typeinfo' % (len(vt), len(ti)))
        sys.exit(0)
    if '--vtable' in sys.argv:
        a = int(sys.argv[sys.argv.index('--vtable') + 1], 16)
        print(hex(a), '→', vt.get(a, '（不是 vtable 起点）'))
    elif '--addr' in sys.argv:
        a = int(sys.argv[sys.argv.index('--addr') + 1], 16)
        for s in secs:
            if s[0] == '.text' and s[1] <= a < s[1] + s[3]:
                off = s[2] + (a - s[1])
                break
        code = data[off:off + 200]
        seen = []
        # mov r64, imm  (48 c7 /0 id) 与 lea rip 略;只抽 64 位立即数落到 .data.rel.ro 的
        for m in re.finditer(rb'\x48\xc7[\xc0-\xc7]((?:[\x00-\xff]){4})', code):
            v = struct.unpack('<i', m.group(1))[0]
            if v > 0x1000000:
                seen.append((a + m.start(), v))
        for pc, v in seen:
            tag = vt.get(v, '')
            print('%08x mov %s  %s' % (pc, hex(v), ('vtable of ' + tag) if tag else ''))
    else:
        print('vtable 数:', len(vt), ' typeinfo 数:', len(ti))
        for a, n in sorted(vt.items()):
            print('%08x  %s' % (a, n))
