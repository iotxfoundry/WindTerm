#!/usr/bin/env python3
"""mo_find.py — 按类名反查 staticMetaObject 地址。

用法:
    python3 tools/re/mo_find.py KitWindow EditorWindow

为什么要它:很多类的 metaObject 函数不带类名前缀(如 KitWindow 的 metaObject
根本没出现在 `KitWindow_*` 命名里),但 `qmo_class.py` 需要地址入口。
本脚本扫 `.data.rel.ro`,把每个 8 字节对齐位置当 QMetaObject 试解,
比对 class 字符串即得地址。
"""
import re
import struct
import subprocess
import sys


def main():
    data = open('WindTerm', 'rb').read()
    out = subprocess.run(['readelf', '-SW', 'WindTerm'], capture_output=True, text=True).stdout
    secs = [(m.group(1), int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16))
            for m in re.finditer(r'\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', out)]

    def off(a):
        for _n, va, o, sz in secs:
            if va <= a < va + sz:
                return o + (a - va)
        return None

    m = re.search(r'\.rela\.dyn\s+\S+\s+[0-9a-f]+\s+([0-9a-f]+)\s+([0-9a-f]+)', out)
    rela = {}
    o, sz = int(m.group(1), 16), int(m.group(2), 16)
    for i in range(0, sz, 24):
        ro, ri, ra = struct.unpack('<QQq', data[o + i:o + i + 24])
        if (ri & 0xffffffff) == 8:
            rela[ro] = ra

    def rd(a):
        p = off(a)
        if p is None or p + 8 > len(data):
            return 0
        return rela.get(p, struct.unpack('<Q', data[p:p + 8])[0])

    def qstr(q, i):
        p = q + i * 24
        if p + 24 > len(data):
            return None
        ln = struct.unpack('<i', data[p + 4:p + 8])[0]
        so = struct.unpack('<q', data[p + 16:p + 24])[0]
        if ln < 0 or ln > 300 or p + so < 0 or p + so + ln > len(data):
            return None
        return data[p + so:p + so + ln].decode('utf-8', 'replace')

    def cls(qmo):
        sd, dt = rd(qmo + 8), rd(qmo + 16)
        q, d = off(sd), off(dt)
        if q is None or d is None or d + 56 > len(data):
            return None
        hdr = struct.unpack('<14I', data[d:d + 56])
        if hdr[0] != 8 or hdr[1] > 500:
            return None
        return qstr(q, hdr[1])

    want = set(sys.argv[1:])
    found = {}
    drv = [s for s in secs if s[0] == '.data.rel.ro'][0]
    _, va, o, sz = drv
    for addr in range(va, va + sz, 8):
        try:
            c = cls(addr)
        except struct.error:
            continue
        if c in want and c not in found:
            found[c] = addr
            print(f'{c:28} {hex(addr)}')


if __name__ == '__main__':
    main()
