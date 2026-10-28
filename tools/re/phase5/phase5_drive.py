#!/usr/bin/env python3
# Phase 5 离屏行为对比驱动(Python frida):
# 孵化原版 WindTerm(offscreen)→ 捕获 Screen(shell 横幅经
# writeText)→ 注入字节序列 → 读 TerminalCore 格子网格 → 落盘。
#
# 锚(非 PIE,运行时地址 = 语料地址):
#   Screen::writeText(const char*, int) = FUN_007e6f42
#   Screen:m_core = +0x80;core:m_cursorY +0xc4 / m_cursorX +0xc8
#   core:rowCount +0x74 / rows 数组 +0x78;row:length +0x0c /
#   attrArray +0x40(u16 字头;0xffff = 宽字符尾格)
import json
import sys
import frida

AGENT = r'''
const WRITE_TEXT = ptr('0x7e6f42');
const writeText = new NativeFunction(WRITE_TEXT, 'void', ['pointer', 'pointer', 'int']);
let screen = null;

Interceptor.attach(WRITE_TEXT, {
  onEnter(args) {
    if (screen === null) {
      screen = args[0];
      send({ type: 'screen-captured', screen: screen.toString() });
    }
  }
});

function readGrid() {
  if (screen === null) return { error: 'no screen captured yet' };
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
  waitScreen(timeoutMs) {
    return new Promise((resolve) => {
      const t0 = Date.now();
      const iv = setInterval(() => {
        if (screen !== null) { clearInterval(iv); resolve(screen.toString()); }
        else if (Date.now() - t0 > timeoutMs) { clearInterval(iv); resolve(null); }
      }, 100);
    });
  },
  inject(hex) {
    if (screen === null) throw new Error('no screen');
    const buf = hex.match(/../g).map(h => parseInt(h, 16));
    const mem = Memory.alloc(Math.max(buf.length, 1));
    mem.writeByteArray(buf);
    writeText(screen, mem, buf.length);
    return readGrid();
  },
  grid() { return readGrid(); },
};
'''


def on_message(msg, _data):
    if msg['type'] == 'send':
        print('[agent]', json.dumps(msg['payload']))
    elif msg['type'] == 'error':
        print('[agent-err]', msg.get('description'))


def main():
    seq_file = sys.argv[1] if len(sys.argv) > 1 else '/tmp/opencode/phase5_seq.json'
    with open(seq_file) as f:
        seqs = json.load(f)

    device = frida.get_local_device()
    # 注意:env= 重载会令该二进制 spawn 阻塞——用 sh -c 包裹传变量
    pid = device.spawn([
        '/bin/sh', '-c',
        'QT_QPA_PLATFORM=offscreen LD_LIBRARY_PATH=/opt/WindTerm_2.7.0/lib '
        'exec /opt/WindTerm_2.7.0/WindTerm',
    ])
    print('spawned pid', pid)
    session = device.attach(pid)
    script = session.create_script(AGENT)
    script.on('message', on_message)
    script.load()
    device.resume(pid)

    api = script.exports_sync
    scr = api.wait_screen(30000)
    print('screen =', scr)
    if not scr:
        print('NO SCREEN CAPTURED')
        sys.exit(2)

    out = []
    for seq in seqs:
        grid = api.inject(seq['bytes'])
        out.append({'name': seq['name'], 'grid': grid})
        print('injected', seq['name'], '-> rows', grid.get('rowCount'),
              'cursor', grid.get('curY'), ',', grid.get('curX'))
    with open('/tmp/opencode/phase5_original.json', 'w') as f:
        json.dump(out, f, indent=1)
    print('written /tmp/opencode/phase5_original.json')


if __name__ == '__main__':
    main()
