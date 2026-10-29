#!/usr/bin/env python3
# Phase 5 原版侧 dump(对比驱动,仓库固件):
#   附加运行中的原版 WindTerm(Xvfb + bash 会话)→ Frida 捕获
#   commander/screen(writeSplitData/writeText 钩)→ 经
#   SuperCommander_writeSplitData(007d1f5a)注入 phase5_seq.json
#   序列(先 ESC[2J ESC[H 清屏基线)→ 读 TerminalCore 格子网格
#   → /tmp/opencode/phase5_original.json
#
# 锚(非 PIE,运行时地址 = 语料地址):
#   writeSplitData = 0x7d1f5a / writeText = 0x7e6f42
#   core:行数 +0x74 / 行数组 +0x78 / 光标 +0xc4/+0xc8
#   row:长 +0x0c / attrArray +0x40(u16 字头;0xffff=宽字符尾格)
import json
import os
import subprocess
import sys
import time
import frida

AGENT = r'''
const mod = Process.getModuleByName('libQt5Core.so.5');
const qbaNew = new NativeFunction(
    mod.getExportByName('_ZN10QByteArrayC1EPKci'),
    'pointer', ['pointer', 'pointer', 'int']);
const writeSplitData = new NativeFunction(ptr('0x7d1f5a'), 'void',
    ['pointer', 'pointer', 'int']);
let commander = null;
let screen = null;
Interceptor.attach(ptr('0x7e6f42'), {
  onEnter(a) { if (screen === null) screen = a[0]; }
});
Interceptor.attach(ptr('0x7d1f5a'), {
  onEnter(a) { if (commander === null) commander = a[0]; }
});
function grid() {
  if (screen === null) return { error: 'no screen' };
  const core = screen.add(0x80).readPointer();
  const rowCount = core.add(0x74).readS32();
  const rowsArr = core.add(0x78).readPointer();
  const lines = [];
  for (let y = 0; y < Math.min(rowCount, 32); ++y) {
    const row = rowsArr.add(y * 8).readPointer();
    if (row.isNull()) { lines.push(null); continue; }
    const len = row.add(0x0c).readS32();
    const heads = row.add(0x40).readPointer();
    const cells = [];
    for (let x = 0; x < len; ++x) cells.push(heads.add(x * 2).readU16());
    lines.push(cells);
  }
  return { rowCount, curY: core.add(0xc4).readS32(),
           curX: core.add(0xc8).readS32(), lines };
}
rpc.exports = {
  ready() { return commander !== null && screen !== null; },
  inject(hex) {
    if (commander === null) throw new Error('no commander');
    if (!hex) return grid();
    const buf = hex.match(/../g).map(h => parseInt(h, 16));
    const mem = Memory.alloc(buf.length + 1);
    mem.writeByteArray(buf);
    mem.add(buf.length).writeU8(0);
    const ba = Memory.alloc(16);
    qbaNew(ba, mem, buf.length);
    writeSplitData(commander, mem, buf.length);
    return grid();
  },
};
'''


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    seq_file = sys.argv[1] if len(sys.argv) > 1 \
        else os.path.join(here, 'phase5_seq.json')
    out_path = sys.argv[2] if len(sys.argv) > 2 \
        else '/tmp/opencode/phase5_original.json'
    with open(seq_file) as f:
        seqs = json.load(f)

    pids = subprocess.run(['pgrep', '-x', 'WindTerm'],
                          capture_output=True, text=True).stdout.split()
    if not pids:
        print('WindTerm not running(Xvfb + bash 会话需先就绪)')
        sys.exit(2)
    device = frida.get_local_device()
    session = device.attach(int(pids[0]))
    script = session.create_script(AGENT)
    script.on('message', lambda m, d: print('[msg]',
               m.get('payload') or m.get('description')))
    script.load()

    # 打字触发回显 → 捕获 commander/screen;随后 exec sleep 哑化
    # shell(防提示符重绘干扰对比——ALL MATCH 基线的前提)
    env = dict(os.environ, DISPLAY=':99')
    subprocess.run(['xdotool', 'mousemove', '500', '400', 'click', '1'],
                   env=env)
    time.sleep(0.3)
    subprocess.run(['xdotool', 'type', 'echo CAP'], env=env)
    subprocess.run(['xdotool', 'key', 'Return'], env=env)
    time.sleep(0.5)
    subprocess.run(['xdotool', 'type', 'exec sleep 100000'], env=env)
    subprocess.run(['xdotool', 'key', 'Return'], env=env)
    time.sleep(1)
    for _ in range(15):
        if script.exports_sync.ready():
            break
        time.sleep(1)
    print('ready =', script.exports_sync.ready())

    script.exports_sync.inject('1b5b324a1b5b48')   # 清屏基线
    out = []
    for seq in seqs:
        g = script.exports_sync.inject(seq['bytes'])
        out.append({'name': seq['name'], 'grid': g})
        print(seq['name'], '-> cur', g.get('curY'), g.get('curX'))
    with open(out_path, 'w') as f:
        json.dump(out, f, indent=1)
    print('written', out_path)


if __name__ == '__main__':
    main()
