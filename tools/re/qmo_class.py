#!/usr/bin/env python3
"""qmo_class.py — 按 staticMetaObject 地址读一个类的元对象。

用法:
    python3 tools/re/qmo_class.py 0x119d620 [0x11ab900 ...]

输出:类名 / 基类链(superdata)/ 方法表(信号·槽·构造,含真名)/ 属性表 / 串表。
用途:确定信号与属性的**真名与索引序**——这是 moc 生成面的权威来源,
比反编译里的裸索引可靠(信号/槽个数、属性声明序都从这里读)。

注:方法记录在本二进制里是 **10 个 u16(20 字节)**一条,前 5 个含名字与
   参数个数,后 5 个是参数类型表。
   **信号/槽的分类按 `signals` 计数,不按 flags 位解** —— 本构建里那条
   flags 位实测不可靠(会出现与 activate 索引矛盾的结论),而 Qt 保证
   方法表前 `signals` 条就是信号。带默认实参的信号会额外生成一条克隆记录,
   因此 signals=2 可能只有 1 个真实信号(见 MessageBar)。
"""
import re
import struct
import subprocess
import sys


def sections(path):
    out = subprocess.run(['readelf', '-SW', path], capture_output=True, text=True).stdout
    return [(m.group(1), int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16))
            for m in re.finditer(r'\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', out)], out


def build(data, secs):
    def off(a):
        for _, va, o, sz in secs:
            if va <= a < va + sz:
                return o + (a - va)
        return None

    out = subprocess.run(['readelf', '-SWd', 'x'], capture_output=True, text=True).stdout
    return off


def main():
    path = 'WindTerm'
    data = open(path, 'rb').read()
    secs, raw = sections(path)

    def off(a):
        for _n, va, o, sz in secs:
            if va <= a < va + sz:
                return o + (a - va)
        return None

    m = re.search(r'\.rela\.dyn\s+\S+\s+[0-9a-f]+\s+([0-9a-f]+)\s+([0-9a-f]+)', raw)
    rela = {}
    o, sz = int(m.group(1), 16), int(m.group(2), 16)
    for i in range(0, sz, 24):
        ro, ri, ra = struct.unpack('<QQq', data[o + i:o + i + 24])
        if (ri & 0xffffffff) == 8:
            rela[ro] = ra

    def rd(a):
        p = off(a)
        if p is None:
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

    def class_name(qmo):
        if qmo == 0:
            return None
        sd, dt = rd(qmo + 8), rd(qmo + 16)
        q, d = off(sd), off(dt)
        if q is None or d is None:
            return '?'
        hdr = struct.unpack('<14I', data[d:d + 56])
        return qstr(q, hdr[1])

    for arg in sys.argv[1:]:
        qmo = int(arg, 16)
        sd, dt = rd(qmo + 8), rd(qmo + 16)
        q, d = off(sd), off(dt)
        if q is None or d is None:
            print(f'{arg}: 无法定位 stringdata/data')
            continue
        hdr = struct.unpack('<14I', data[d:d + 56])
        _, _, _, _, m_c, m_d, p_c, p_d = hdr[:8]
        print(f'── {arg}  class={class_name(qmo)!r}')
        print(f'   methods={m_c} signals={hdr[13]} props={p_c}')
        chain, cur = [], rd(qmo)
        while cur and len(chain) < 8:
            chain.append(f'{hex(cur)} {class_name(cur)}')
            cur = rd(cur)
        print('   基类链: ' + (' → '.join(chain) if chain else '(无)'))
        base = d + m_d * 4
        for k in range(m_c):
            u = struct.unpack('<10H', data[base + k * 20:base + k * 20 + 20])
            flag = u[4]
            kind = 'SIGNAL' if k < hdr[13] else 'slot' 
            print(f'   #{k:<2} {kind:<7} {qstr(q, u[0])!r} argc={u[1]} flags=0x{flag:x}')
        for i in range(p_c):
            p = d + p_d * 4 + i * 12
            ni, ti = struct.unpack('<2I', data[p:p + 8])
            print(f'   prop #{i} {qstr(q, ni)!r} : {qstr(q, ti)!r}')


if __name__ == '__main__':
    main()
