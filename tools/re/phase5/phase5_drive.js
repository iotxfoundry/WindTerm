// Phase 5 离屏行为对比驱动:Frida 孵化原版 WindTerm(offscreen),
// 捕获 Screen 指针(shell 横幅经 writeText 流过),注入字节序列,
// 读其 TerminalCore 格子网格,与我们重建侧对比。
//
// 锚(非 PIE,运行时地址 = 语料地址):
//   Screen::writeText(const char*, int) = FUN_007e6f42
//   Screen 布局:m_core = +0x80;core:m_cursorY +0xc4 / m_cursorX +0xc8
//               rowCount +0x74 / rows数组 +0x78;row:length +0x0c /
//               attrArray +0x40(u16 字头;0xffff = 宽字符尾格)
//
// 用法:node phase5_drive.js <seqfile.json>
const frida = require('/home/pana/.bun/install/global/node_modules/frida');

const AGENT = `
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
    for (let x = 0; x < len; ++x) {
      cells.push(heads.add(x * 2).readU16());
    }
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
`;

async function main() {
  const seqFile = process.argv[2] || '/tmp/opencode/phase5_seq.json';
  const seqs = JSON.parse(require('fs').readFileSync(seqFile, 'utf8'));

  const device = await frida.getLocalDevice();
  const pid = await device.spawn(['/opt/WindTerm_2.7.0/WindTerm'], {
    env: {
      LD_LIBRARY_PATH: '/opt/WindTerm_2.7.0/lib',
      QT_QPA_PLATFORM: 'offscreen',
      HOME: '/home/pana',
    },
  });
  console.log('spawned pid', pid);
  const session = await device.attach(pid);
  const script = await session.createScript(AGENT);
  script.message.connect((msg) => {
    if (msg.type === 'send') console.log('[agent]', JSON.stringify(msg.payload));
    else if (msg.type === 'error') console.log('[agent-err]', msg.description);
  });
  await script.load();
  await device.resume(pid);

  const api = script.exports;
  const scr = await api.waitScreen(30000);
  console.log('screen =', scr);
  if (!scr) { console.log('NO SCREEN CAPTURED'); process.exit(2); }

  const out = [];
  for (const seq of seqs) {
    const grid = await api.inject(seq.bytes);
    out.push({ name: seq.name, grid });
    console.log('injected', seq.name, '-> rows', grid.rowCount,
                'cursor', grid.curY + ',' + grid.curX);
  }
  require('fs').writeFileSync('/tmp/opencode/phase5_original.json',
                              JSON.stringify(out, null, 1));
  console.log('written /tmp/opencode/phase5_original.json');
  // 会话保持:RE 宿主不杀目标;驱动退出即分离(目标继续运行)
  process.exit(0);
}

main().catch((e) => { console.error(e); process.exit(1); });
