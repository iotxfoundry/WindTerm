#!/usr/bin/env python3
# calls-with-receivers.py — 恢复 C++ 成员调用的 receiver（this）
# 背景：Ghidra 反编译显示层不打印隐含 this（C++ 调用 receiver=RDI），
#       导致 "X::addWidget(w)" 读不出 X 是谁。机器码层完整：call 前必有
#       `mov rdi, <src>`。本工具对地址区间跑 objdump 并回溯 receiver/arg1。
# 用法：
#   python3 tools/calls-with-receivers.py 0x<start> 0x<stop> [回溯条数=5] [二进制=/opt/WindTerm_2.7.0/WindTerm]
# 示例：
#   python3 tools/calls-with-receivers.py 0x8cd068 0x8cd478
import re
import subprocess
import sys

BIN = '/opt/WindTerm_2.7.0/WindTerm'
CALL = re.compile(r'^\s*([0-9a-f]+):.*?\bcall[q]?\s+[0-9a-f]+ <(.+?)>')
MOV = re.compile(r'^\s*([0-9a-f]+):.*?\bmov\s+(0x[0-9a-f]+\(%\w+\)|0x[0-9a-f]+|%r[a-z0-9]+),(%r(?:di|si|dx|cx|8|9))')


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 1
    start, stop = sys.argv[1], sys.argv[2]
    back = int(sys.argv[3]) if len(sys.argv) > 3 else 5
    binary = sys.argv[4] if len(sys.argv) > 4 else BIN
    out = subprocess.run(
        ['objdump', '-d', f'--start-address={start}', f'--stop-address={stop}', binary],
        capture_output=True, text=True).stdout
    hist = []
    for line in out.splitlines():
        cm = CALL.match(line)
        if cm:
            addr, callee = cm.group(1), cm.group(2)
            regs = {}
            for _h, src, rd in reversed(hist):
                if rd not in regs:
                    regs[rd] = src
            parts = []
            if 'rdi' in regs:
                parts.append(f'receiver={regs["rdi"]}')
            if 'rsi' in regs:
                parts.append(f'arg1={regs["rsi"]}')
            print(f'  {addr}: {callee}({", ".join(parts)})')
            hist.clear()
            continue
        mm = MOV.match(line)
        if mm:
            hist.append((mm.group(1), mm.group(2), mm.group(3).lstrip('%')))
            if len(hist) > back:
                hist.pop(0)
    return 0


if __name__ == '__main__':
    sys.exit(main())
