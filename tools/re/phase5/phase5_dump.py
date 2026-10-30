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
const qbaClear = new NativeFunction(
    mod.getExportByName('_ZN10QByteArray5clearEv'), 'void', ['pointer']);
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
  // 解析器遗留态复位(每序列前,见 baseline() 注释):
  //   +0x101 = checkControlCharacter 挂起(007cadda 直写)
  //   +0xd8  = 挂起尾 QByteArray(半截序列)
  resetState() {
    if (commander === null) return false;
    commander.add(0x101).writeU8(0);
    qbaClear(commander.add(0xd8));
    return true;
  },
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


def _mode(vals):
    """众数(并列取首现)。"""
    best, best_n = None, -1
    for v in vals:
        c = vals.count(v)
        if c > best_n:
            best, best_n = v, c
    return best


def mode_grid(grids):
    """逐格众数:字面态伪影(N 次独立重 dump 偶发)按格投票,众数即读数。"""
    curY = _mode([g.get('curY') for g in grids])
    curX = _mode([g.get('curX') for g in grids])
    rows = [(g.get('lines') or []) for g in grids]
    lines = []
    for y in range(min(max(len(r) for r in rows), 32)):
        vals = [(r[y] if y < len(r) else None) or [] for r in rows]
        lines.append([_mode([v[x] if x < len(v) else 0 for v in vals])
                      for x in range(max(len(v) for v in vals))])
    return {'curY': curY, 'curX': curX, 'lines': lines}


def baseline(script):
    """清屏基线(前置遗留态复位)。

    原版遗留态:ESC-single 动作会置 Commander+0x101(checkControlCharacter,
    007cadda),下一 writeSplitData 的**首个匹配序列**除执行动作外还会被回
    显成字面字形(007d1f5a @7d2077 → 007cc1fa → writeText);另有 +0xd8
    挂起尾(半截序列,入口前拼)。dump 每序列前的基线恰是那个「下一批」,
    于是基线自身的 ESC[2J 字样落在上一序列的收尾光标处(批 29 tbc3 的
    27,91,50,74 = 仪器字节,非序列字节)。
    基线前复位这两项 → 序列读数只含序列自己的字节效应。
    """
    script.exports_sync.resetState()
    script.exports_sync.inject('1b5b324a1b5b481b5b72')


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

    out = []
    for seq in seqs:
        # 字面态伪影重试(loop iter1):0x1b 格签名 → 最多 3 次重基线
        # 重注入,前置 sleep 1.0(vt14 字面直通态竞态,随机性)
        for attempt in range(3):
            baseline(script)     # 清屏基线(双发,见 baseline() 注释)
            time.sleep(1.0)   # 前置 settle(iter1 强化,0.6→1.0)
            # ',' 分批:验证 pending flush(QUIRKS 13)必需——批间即 flush 点
            for part in seq['bytes'].split(','):
                script.exports_sync.inject(part)
                time.sleep(0.05)
            time.sleep(0.6)   # 批后 settle(probe15:E 系列 0.5s 全生效)
            g2 = script.exports_sync.inject('')   # 空注入 = 只读网格
            if seq['name'] == 'esc_literal' or not any(
                    27 in (r or []) for r in g2.get('lines', [])[:6]):
                break   # 干净(或合法 0x1b 字面序列)
            # 重试前排空窗:立即重注入会撞上一次 attempt 的未排空队列
            # (+0xd8 tail 拼接混沌 = 字面化根因,iter1 三连中招实锤)
            print('  glitch(0x1b cell) attempt %d -> retry (drain 2s)'
                  % (attempt + 1), seq['name'])
            time.sleep(2.0)
        # 终裁(批 29):3 次重试仍字面态 → N=5 连读、逐格取众数
        # (每次重基线 + 重注入;伪影随机命中,众数即干净读数)
        if seq['name'] != 'esc_literal' and any(
                27 in (r or []) for r in g2.get('lines', [])[:6]):
            grids = [g2]
            for _ in range(4):
                baseline(script)
                time.sleep(1.0)
                for part in seq['bytes'].split(','):
                    script.exports_sync.inject(part)
                    time.sleep(0.05)
                time.sleep(0.6)
                grids.append(script.exports_sync.inject(''))
            g2 = mode_grid(grids)
            print('  mode-of-%d -> cur %s,%s' % (len(grids), g2['curY'],
                                                 g2['curX']), seq['name'])
        # 稳定性复读(批 30):非 0x1b 的流态噪声族(decom 光标残留
        # 等)不触发上面的字面签名重试——复读一次,读数不稳 →
        # mode-of-5(独立重基线,逐格众数 = 稳定读数)
        baseline(script)
        time.sleep(1.0)
        for part in seq['bytes'].split(','):
            script.exports_sync.inject(part)
            time.sleep(0.05)
        time.sleep(0.6)
        g3 = script.exports_sync.inject('')
        if g3 != g2:
            grids = [g2, g3]
            for _ in range(3):
                baseline(script)
                time.sleep(1.0)
                for part in seq['bytes'].split(','):
                    script.exports_sync.inject(part)
                    time.sleep(0.05)
                time.sleep(0.6)
                grids.append(script.exports_sync.inject(''))
            g2 = mode_grid(grids)
            print('  stability mode-of-%d -> cur %s,%s' % (
                len(grids), g2['curY'], g2['curX']), seq['name'])
        out.append({'name': seq['name'], 'grid': g2})
        print(seq['name'], '-> cur', g2.get('curY'), g2.get('curX'))
    with open(out_path, 'w') as f:
        json.dump(out, f, indent=1)
    print('written', out_path)


if __name__ == '__main__':
    main()
