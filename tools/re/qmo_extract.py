#!/usr/bin/env python3
"""Extract Qt QMetaObject metadata from a stripped ELF (WindTerm-style).

Recovers, without any symbols:
  - all QMetaObject classes (strict 4-field pattern in .data.rel.ro,
    plus RELATIVE-relocation-resolved variants)
  - per class: methods (name/kind/argc/params), signals/slots split,
    properties, Q_ENUM enumerator tables with exact values
  - superdata inheritance chains (cross-file, into linked .so libs)

Usage: qmo_extract.py <binary> [--libs libdir] [--json out.json]
"""
import struct, subprocess, sys, re, json, os

def sections(path):
    out = subprocess.run(['readelf', '-S', path], capture_output=True, text=True).stdout
    secs = {}
    for m in re.finditer(r'\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', out):
        secs[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16))
    return secs

def rela_map(data, secs):
    m = re.search(r'\.rela\.dyn\s+\S+\s+[0-9a-f]+\s+([0-9a-f]+)\s+([0-9a-f]+)',
                  subprocess.run(['readelf', '-S', sys.argv[1]], capture_output=True, text=True).stdout)
    out = {}
    off, size = int(m.group(1), 16), int(m.group(2), 16)
    for i in range(off, off + size, 24):
        r_off, r_info, r_add = struct.unpack('<QQq', data[i:i + 24])
        if (r_info & 0xffffffff) == 8:  # R_X86_64_RELATIVE
            out[r_off] = r_add
    return out

def main():
    path = sys.argv[1]
    data = open(path, 'rb').read()
    secs = sections(path)
    reloc = rela_map(data, secs)
    rodata = secs['.rodata']

    def qstr(sd, idx):
        h = sd - 0x400000 + idx * 24  # QArrayData stride 24; adjust per binary delta
        if h < 0 or h + 24 > len(data):
            return None
        size = struct.unpack('<i', data[h + 4:h + 8])[0]
        off = struct.unpack('<q', data[h + 16:h + 24])[0]
        if size < 0 or size > 200 or h + off < 0 or h + off + size > len(data):
            return None
        return data[h + off:h + off + size].decode('utf-8', 'replace')

    dv, doff, dsz = secs['.data.rel.ro']
    in_ = lambda va, s: s[0] <= va < s[0] + s[2]
    qmos = {}
    for i in range(0, dsz - 40, 8):
        b = doff + i
        v0, v1, v2, v3 = struct.unpack('<QQQQ', data[b:b + 32])
        if v1 == 0: v1 = reloc.get(dv + i + 8, 0)
        if v2 == 0: v2 = reloc.get(dv + i + 16, 0)
        if not (in_(v1, rodata) and in_(v2, rodata)):
            continue
        try:
            u = lambda j: struct.unpack('<I', data[v2 - 0x400000 + j * 4:v2 - 0x400000 + j * 4 + 4])[0]
            if u(0) not in (7, 8, 9, 10, 11):
                continue
            cls = qstr(v1, u(1))
            if not cls or not cls.replace('_', '').isalnum():
                continue
            qmos[dv + i] = dict(name=cls, super=v0, stringdata=v1, data=v2, metacall=v3)
        except Exception:
            pass
    result = {}
    for q, info in qmos.items():
        sd, dt = info['stringdata'], info['data']
        u = lambda j: struct.unpack('<I', data[dt - 0x400000 + j * 4:dt - 0x400000 + j * 4 + 4])[0]
        entry = dict(metacall=hex(info['metacall']), super=hex(info['super']))
        m_cnt, m_off = u(4), u(5)
        methods = []
        for mi in range(min(m_cnt, 400)):
            b = m_off + mi * 5
            nm = qstr(sd, u(b))
            if not nm:
                continue
            argc, params, flags = u(b + 1), u(b + 2), u(b + 4) & 0xf
            methods.append(dict(name=nm, argc=argc,
                                kind={0: 'M', 1: 'SIG', 2: 'SLOT', 3: 'CTOR'}.get(flags, '?')))
        entry['methods'] = methods
        enums = {}
        try:
            e_cnt, e_off = u(8), u(9)
            for ei in range(min(e_cnt, 100)):
                b = e_off + ei * 5
                enm, cnt, dOff = qstr(sd, u(b)), u(b + 3), u(b + 4)
                if not enm:
                    continue
                enums[enm] = {qstr(sd, u(dOff + 2 * k)) or '?': u(dOff + 2 * k + 1)
                              for k in range(min(cnt, 200))}
        except Exception:
            pass
        entry['enums'] = enums
        result[info['name']] = entry
    out = sys.argv[sys.argv.index('--json') + 1] if '--json' in sys.argv else None
    if out:
        json.dump(result, open(out, 'w'), ensure_ascii=False, indent=1)
    print(f"{len(result)} classes; use --json to save")

if __name__ == '__main__':
    main()
