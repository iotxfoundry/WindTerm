#!/usr/bin/env python3
"""Parse .eh_frame FDEs into authoritative function boundaries.

Every compiled function with unwind info gets exactly one FDE
(start, range). Zero overlaps, tiles .text to the byte — the ground
truth IDA/Ghidra should be backfilled from (see ida_makefuncs generator).

Usage: ehframe_fdes.py <binary> [--json out.json]
"""
import struct, subprocess, sys, re, json

def main():
    path = sys.argv[1]
    data = open(path, 'rb').read()
    out = subprocess.run(['readelf', '-S', path], capture_output=True, text=True).stdout
    m = re.search(r'\.eh_frame\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)', out)
    va, off, size = int(m.group(1), 16), int(m.group(2), 16), int(m.group(3), 16)
    fdes, p = [], off
    while p < off + size - 4:
        ln = struct.unpack('<I', data[p:p + 4])[0]
        if ln == 0:
            break
        body = p + 4
        if struct.unpack('<I', data[body:body + 4])[0] != 0:  # FDE (CIE_pointer != 0)
            anchor = va + (body + 4 - off)
            init = struct.unpack('<i', data[body + 4:body + 8])[0]
            rng = struct.unpack('<i', data[body + 8:body + 12])[0]
            fdes.append((anchor + init, rng))
        p = body + ln
    total = sum(r for _, r in fdes)
    print(f"FDEs: {len(fdes)}, total {total} bytes")
    if '--json' in sys.argv:
        out = sys.argv[sys.argv.index('--json') + 1]
        json.dump([[hex(s), r] for s, r in fdes], open(out, 'w'))

if __name__ == '__main__':
    main()
