#!/usr/bin/env python3
# Phase 5 对比驱动 v2:附加到运行中的原版(Xvfb 下,bash 会话已开)
# 1) hook FUN_007e6f42  2) xdotool 打字触发回显 → 捕获 Screen
# 3) NativeFunction 注入字节序列 → 读 TerminalCore 格子 → 落盘
import json
import subprocess
import sys
import time
import frida

AGENT = r'''
const WRITE_TEXT = ptr('0x7e6f42');
const writeText = new NativeFunction(WRITE_TEXT, 'void', ['pointer', 'pointer', 'int']);
let screen = null;

Interceptor.attach(WRITE_TEXT, {
  onEnter(args) {
    if (screen === null) {
      screen = args[0];
      send({ type: 'captured', screen: screen.toString() });
    }
  }
});

function readGrid() {
  if (screen === null) return { error: 'no screen' };
  const core = screen.add(0x80).readPointer();
  const rowCount = core.add(0x74).readS32();
  const rowsArr = core.add(0x78).readPointer();
  const curY = core.add(0xc4).readS32();
  const curX = core.add(0xc8).readS32();
  const lines = [];
  for (let y = 0; y < rowCount; ++y) {
    const row = rowsArr.add(y * 8).readPointer();
    if (row.isNull()) { lines.push(null); continue; }
    const len = row.add(0x0c).readS32();
    const heads = row.add(0x40).readPointer();
    const cells = [];
    for (let x = 0; x < len; ++x) cells.push(heads.add(x * 2).readU16());
    lines.push(cells);
  }
  return { rowCount, curY, curX, lines };
}

rpc.exports = {
  screen() { return screen === null ? null : screen.toString(); },
  inject(hex) {
    if (screen === null) throw new Error('no screen');
    const buf = hex.match(/../g).map(h => parseInt(h, 16));
    const mem = Memory.alloc(Math.max(buf.length, 1));
    mem.writeByteArray(buf);
    writeText(screen, mem, buf.length);
    return readGrid();
  },
};
'''


def main():
    out_path = '/tmp/opencode/phase5_original.json'
    target = int(sys.argv[1]) if len(sys.argv) > 1 else None
    if target is None:
        out = subprocess.run(['pgrep', '-x', 'WindTerm'],
                             capture_output=True, text=True).stdout.split()
        if not out:
            print('WindTerm not running')
            sys.exit(2)
        target = int(out[0])
    print('attaching to', target)
    device = frida.get_local_device()
    session = device.attach(target)
    script = session.create_script(AGENT)
    script.on('message', lambda m, d: print('[msg]', m.get('payload') or m))
    script.load()

    # 打字触发回显 → 捕获 Screen(点击终端区取得焦点 → type)
    subprocess.run(
        'DISPLAY=:99 xdotool mousemove 500 400 click 1; sleep 0.5; '
        'DISPLAY=:99 xdotool type "echo X5CAP"; '
        'DISPLAY=:99 xdotool key Return',
        shell=True)
    screen = None
    for _ in range(20):
        screen = script.exports_sync.screen()
        if screen:
            break
        time.sleep(0.5)
    print('screen =', screen)
    if not screen:
        print('NO SCREEN CAPTURED')
        sys.exit(3)

    with open('/tmp/opencode/phase5_seq.json') as f:
        seqs = json.load(f)
    out = []
    for seq in seqs:
        grid = script.exports_sync.inject(seq['bytes'])
        out.append({'name': seq['name'], 'grid': grid})
        print('injected', seq['name'], '-> cursor',
              grid.get('curY'), ',', grid.get('curX'))
    with open(out_path, 'w') as f:
        json.dump(out, f, indent=1)
    print('written', out_path)


if __name__ == '__main__':
    main()
