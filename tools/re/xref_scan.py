#!/usr/bin/env python3
"""One-pass ELF cross-reference scanner (numpy, ~8MB .text in seconds).

Builds every call/jmp/rip-relative target in one sweep, then answers:
  - callers of any address (direct call/jmp)
  - all references to any rip-relative target (strings, data, GOT)
  - PLT/GOT import resolution: symbol name -> stub VA -> call sites

Usage: xref_scan.py <binary> [--callers 0xADDR] [--refs 0xADDR] [--imports 'substr']
"""
import struct, subprocess, sys, re
import numpy as np

def load(path):
    data = open(path, 'rb').read()
    out = subprocess.run(['readelf', '-S', path], capture_output=True, text=True).stdout
    secs = {}
    for m in re.finditer(r'\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', out):
        secs[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16), int(m.group(4), 16))
    return data, secs

def build_callmap(data, secs):
    tv, toff, tsz = secs['.text']
    buf = np.frombuffer(data, dtype=np.uint8, count=tsz, offset=toff)
    u = buf.astype(np.uint32)
    rel32 = (u[:-3] | (u[1:-2] << 8) | (u[2:-1] << 16) | (u[3:] << 24)).view('<i4')
    e8 = np.where(buf[:len(rel32)] == 0xe8)[0]   # call rel32
    e9 = np.where(buf[:len(rel32)] == 0xe9)[0]   # jmp rel32
    t_e8 = tv + e8 + 5 + rel32[e8]
    t_e9 = tv + e9 + 5 + rel32[e9]
    sites = np.concatenate([e8, e9]); tgts = np.concatenate([t_e8, t_e9])
    order = np.argsort(tgts)
    return rel32, tgts[order], sites[order], tv

def build_refmap(rel32, tv):
    pos = np.arange(len(rel32), dtype=np.int64)
    t = tv + pos + 4 + rel32.astype(np.int64)
    return t

def plt_imports(data, secs):
    dv, doff, _ = secs['.dynsym']; sv, soff, _ = secs['.dynstr']
    def sym(i):
        e = doff + i * 24
        no = struct.unpack('<I', data[e:e + 4])[0]
        return data[soff + no:data.find(b'\0', soff + no)].decode()
    got2sym = {}
    for secn in ('.rela.plt', '.rela.dyn'):
        _, off, size = secs[secn]
        for i in range(off, off + size, 24):
            r_off, r_info, r_add = struct.unpack('<QQq', data[i:i + 24])
            if (r_info & 0xffffffff) in (7, 6):
                got2sym[r_off] = sym(r_info >> 32)
    lv, loff, lsz = secs['.plt']
    plt = {}
    for i in range(loff, loff + lsz - 6):
        if data[i] == 0xff and data[i + 1] == 0x25:
            rel = struct.unpack('<i', data[i + 2:i + 6])[0]
            got = lv + (i - loff) + 6 + rel
            if got in got2sym:
                plt[got2sym[got]] = lv + (i - loff)
    return plt

def main():
    data, secs = load(sys.argv[1])
    rel32, t_sorted, p_sorted, tv = build_callmap(data, secs)
    refs = build_refmap(rel32, tv)
    def callers(addr):
        i0 = np.searchsorted(t_sorted, addr); i1 = np.searchsorted(t_sorted, addr, 'right')
        return [hex(tv + int(x)) for x in p_sorted[i0:i1]]
    args = sys.argv[2:]
    i = 0
    while i < len(args):
        if args[i] == '--callers':
            print(callers(int(args[i + 1], 16))); i += 2
        elif args[i] == '--refs':
            hits = np.where(refs == int(args[i + 1], 16))[0]
            print([hex(tv + int(x)) for x in hits[:20]]); i += 2
        elif args[i] == '--imports':
            plt = plt_imports(data, secs)
            for n in sorted(plt):
                if args[i + 1] in n:
                    print(hex(plt[n]), n, callers(plt[n])[:5]); 
            i += 2
        else:
            i += 1

if __name__ == '__main__':
    main()
