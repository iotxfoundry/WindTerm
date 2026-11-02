#!/usr/bin/env python3
# phase5 像素差分管线(0x7547 marker band,骨架):原版侧经 Frida 钩
# FUN_00a1e1a4(QScrollBar paintEvent 助手)在 GUI 线程内直呼 editor vtable
# 槽 +0x1c0 的 0x7547 腿 → QPixmap → toImage → save PNG;Python 侧复用
# phase5_dump.py 的序列注入惯例(ESC[2J 基线 + 分批 + settle),再以 PIL
# 双 PNG reload ARGB32 逐像素 diff。
#
# 语料锚(非 PIE,运行时地址 = 语料地址;设计全文 /tmp/opencode/p3_notes_pxd.md):
#   FUN_00a1e1a4   paintEvent 助手(0033.c:55572;调用链 QScrollBar::paintEvent
#                  → FUN_00a1d6d0 → 本函数,0033.c:55649)
#   slot +0x1c0    0x7547 腿调用形态(*(*(editor)+0x1c0))(&ret,editor,0x7547,&a,&b)
#                  (0033.c:55600-55604;0x7547 语料体 = 0034.c:22866-22875,
#                  dispatch 本体 s_line_caret_remote_a418c4 = 0x00a418c4,0034.c:20740)
#   editor         = *(widget+0x48)(0033.c:55600 区)
#   userType==0x41 QMetaType::QPixmap=65(qmetatype.h:472;语料门 0033.c:55623)
#   constData→QPixmap 拷贝(0033.c:55623-55626;拷贝 ctor = 00a1e240 同款导出符号)
#   writeSplitData = 0x7d1f5a / resetState +0x101/+0xd8(007cadda)——phase5_dump.py 同源
#
# Qt5 导出符号链(libQt5Core/Gui 5.15,@@Qt_5 逐一 nm -D 核验):
#   QVariant(QSizeF) / ~QVariant / userType / constData /
#   QPixmap(QPixmap&) / ~QPixmap / toImage / QImage::save(QString,const char*,int) /
#   QString::fromUtf8_helper(sret) / QImage::convertToFormat(diff 侧备)
#   未导出(inline):QSizeF ctor/width/height(qsize.h:300 constexpr)、QString dtor
#   (qstring.h:1308)、QVariant() 默认 ctor(qvariant.h:208)→
#   QSizeF = POD{double wd,double ht} 手填(qsize.h:276-277,ABI 事实非自研);
#   nullQVariant = 16B 零填(sizeof(QVariant)=16:qvariant.h:394-440)。
#
# TODO(p3_notes_pxd)未证链清单:
#   1. 滚动条必 paint 未证(原设计唯一未证链)→ 2026-11-02 实测补充:
#      00a1e1a4 确实 fire(键盘回显触发),但 windowsize **不**触发 paint;
#      force_repaint 已改走键盘回显。纯滚动条 paint 路径仍未单独证实,
#      dispatch 备路钩内直呼(实测 userType=65+PNG 落盘全链通)兜底。
#   2. 备路(dispatch 钩内直呼槽)轻量重入风险未证(p3_notes_pxd.md §2,
#      先走 paint 钩主路,dispatch 模式为 opt-in)。
#   3. 原设计零长 writeSplitData 触发 dispatch:零长写行为未证 + rpc 线程
#      直呼槽违反 GUI 线程约束 → 已弃用,备路改为钩内自然 dispatch 触发。
#      TODO(p3_notes_pxd)。
#   4. QString filename 每次 capture 泄漏一个(dtor inline 未导出;
#      QArrayData::deallocate 已导出,在线验证后再补手工释放,TODO(p3_notes_pxd))。
#   5. 本方(renderpixtest)同参 dispatch 侧 + QUIRKS 对账自动化不在本文件
#      写域(diff 子命令已备,输入两侧 PNG 即可)。
#   6. 整链不在线上跑(原版在线环境主线程验证)——本骨架只保证结构与符号链。
#
# 用法:
#   python3 phase5_px.py [seq.json] [out.json]   # 捕获(同 phase5_dump.py 形参)
#   python3 phase5_px.py diff orig.png ours.png  # 逐像素 diff 报告
import json
import os
import subprocess
import sys
import time

import frida

AGENT = r'''
// ---- Qt 导出符号(逐一 nm -D 核验 @@Qt_5;模块锚:phase5_dump.py 同款)----
const core = Process.getModuleByName('libQt5Core.so.5');
const gui  = Process.getModuleByName('libQt5Gui.so.5');
// QVariant(const QSizeF&) — 00a1e21a 原版同款
const qvarFromSizeF = new NativeFunction(
    core.getExportByName('_ZN8QVariantC1ERK6QSizeF'), 'void', ['pointer', 'pointer']);
const qvarDtor = new NativeFunction(
    core.getExportByName('_ZN8QVariantD1Ev'), 'void', ['pointer']);
const userType = new NativeFunction(
    core.getExportByName('_ZNK8QVariant8userTypeEv'), 'int', ['pointer']);
const constData = new NativeFunction(
    core.getExportByName('_ZNK8QVariant9constDataEv'), 'pointer', ['pointer']);
// QString::fromUtf8_helper — 静态,sret:void f(QString* ret, const char*, int)
const strFromUtf8 = new NativeFunction(
    core.getExportByName('_ZN7QString15fromUtf8_helperEPKci'),
    'void', ['pointer', 'pointer', 'int']);
// QPixmap(const QPixmap&) — 00a1e240 原版同款(0033.c:55623-55626)
const pixCopy = new NativeFunction(
    gui.getExportByName('_ZN7QPixmapC1ERKS_'), 'void', ['pointer', 'pointer']);
const pixDtor = new NativeFunction(
    gui.getExportByName('_ZN7QPixmapD1Ev'), 'void', ['pointer']);
// QPixmap::toImage — QImage 按值返回 → sret:void f(QImage* ret, const QPixmap*)
const toImage = new NativeFunction(
    gui.getExportByName('_ZNK7QPixmap7toImageEv'), 'void', ['pointer', 'pointer']);
// QImage::save(const QString&, const char* format, int quality) → bool
const imgSave = new NativeFunction(
    gui.getExportByName('_ZNK6QImage4saveERK7QStringPKci'),
    'bool', ['pointer', 'pointer', 'pointer', 'int']);
const imgDtor = new NativeFunction(
    gui.getExportByName('_ZN6QImageD1Ev'), 'void', ['pointer']);
// PNG 字节回传读盘(libc 标准 ABI;实例式取符号——frida 17 静态
// Module.getExportByName 已移除,TypeError 实锤)
const libc = Process.getModuleByName('libc.so.6');
const _fopen = new NativeFunction(
    libc.getExportByName('fopen'), 'pointer', ['pointer', 'pointer']);
const _fread = new NativeFunction(
    libc.getExportByName('fread'), 'ulong',
    ['pointer', 'ulong', 'ulong', 'pointer']);
const _fclose = new NativeFunction(
    libc.getExportByName('fclose'), 'int', ['pointer']);

// ---- 注入通道(phase5_dump.py 同源:commander 0x7d1f5a / reset +0x101,+0xd8)----
const qbaNew = new NativeFunction(
    core.getExportByName('_ZN10QByteArrayC1EPKci'), 'pointer',
    ['pointer', 'pointer', 'int']);
const qbaClear = new NativeFunction(
    core.getExportByName('_ZN10QByteArray5clearEv'), 'void', ['pointer']);
const writeSplitData = new NativeFunction(ptr('0x7d1f5a'), 'void',
    ['pointer', 'pointer', 'int']);   // SuperCommander_writeSplitData(007d1f5a)
let commander = null;

// commander 捕获钩(phase5_dump.py 同款;a[0]=SuperCommander this)
Interceptor.attach(ptr('0x7d1f5a'), {
  onEnter(a) { if (commander === null) commander = a[0]; }
});

// ---- 0x7547 捕获态 ----
let armed = false;      // rpc.arm() 置位;一次一捕
let armedMode = 'paint';
let curW = 0, curH = 0; // 受控 QSizeF 实参(与 renderpixtest 同参,p3_notes §驱动1)
let curPath = null;
let captured = false;
let lastWidget = null;  // paint 钩 onEnter 存(p3_notes §关键约束1)
let editorBackup = null;// 备路:00a418c4 a[1]=editor(设计锚 p3_notes §2)

// 钩内直呼 0x7547 腿:合法性由语料背书——原版 FUN_00a1e1a4 自身就在
// paintEvent(GUI)线程做同一调用(0033.c:55600-55604)。
function callSlot(editor) {
  // QSizeF POD 手填:{double wd, double ht}(qsize.h:276-277;
  // constexpr inline ctor qsize.h:300 未导出 → ABI 事实直填,非自研行为)
  const sizeF = Memory.alloc(16);
  sizeF.writeDouble(curW);
  sizeF.add(8).writeDouble(curH);
  const va = Memory.alloc(16);
  qvarFromSizeF(va, sizeF);            // a = QVariant(QSizeF),同款 ctor
  const vb = Memory.alloc(16);         // b = nullQVariant(零填,qvariant.h:208 inline)
  const ret = Memory.alloc(16);
  const slot = editor.readPointer().add(0x1c0).readPointer(); // vtable +0x1c0
  const fn = new NativeFunction(slot, 'void',
      ['pointer', 'pointer', 'int', 'pointer', 'pointer']);
  fn(ret, editor, 0x7547, va, vb);     // (0033.c:55604 原样形态)
  let ok = false;
  if (userType(ret) === 0x41) {        // 0x41=65=QPixmap(0033.c:55623)
    const src = Memory.alloc(16);
    pixCopy(src, constData(ret));      // constData → QPixmap 拷贝(0033.c:55623-55626;
                                       // 原版此处 swap 进 widget+0x78 缓存——
                                       // 我方只捕获不写缓存,避免改原版态)
    const img = Memory.alloc(16);
    toImage(img, src);                 // QPixmap → QImage(导出链 p3_notes §QPixmap)
    const qs = Memory.alloc(16);
    strFromUtf8(qs, Memory.allocUtf8String(curPath), curPath.length);
    ok = imgSave(img, qs, Memory.allocUtf8String('PNG'), -1); // PNG 直落盘
    // TODO(p3_notes_pxd):qs 的 QString 未释放(dtor inline 未导出;
    // 每次捕获泄漏一个 filename,清单第 4 条)
    imgDtor(img);
    pixDtor(src);
  }
  qvarDtor(va);
  qvarDtor(vb);
  qvarDtor(ret);
  captured = ok;
  return ok;
}

// ---- 主路钩:FUN_00a1e1a4(0033.c:55572;paintEvent 上下文,GUI 线程)----
Interceptor.attach(ptr('0x00a1e1a4'), {
  onEnter(a) { lastWidget = a[0]; },
  onLeave(r) {
    if (!armed || armedMode !== 'paint' || captured || lastWidget === null) return;
    const editor = lastWidget.add(0x48).readPointer();  // *(widget+0x48),0033.c:55600 区
    if (editor.isNull()) return;
    armed = false;                       // 一次一捕
    callSlot(editor);
  }
});

// ---- 备路钩:0x00a418c4 = s_line_caret_remote_a418c4 主 dispatch(0034.c:20740;
//      0x7547 腿 0034.c:22866-22875)。a[1]=editor(设计锚 p3_notes §2)。
//      opt-in(arm('dispatch'));callSlot 只在钩内(= GUI 线程)跑——
//      rpc 线程直呼槽违反 GUI 线程约束(设计 §关键约束1),绝不从 rpc 调。----
Interceptor.attach(ptr('0x00a418c4'), {
  onEnter(a) {
    editorBackup = a[1];
    if (!armed || armedMode !== 'dispatch' || captured) return;
    if (editorBackup === null || editorBackup.isNull()) return;
    armed = false;
    callSlot(editorBackup);
  }
});

function readAllBytes(path) {
  const rp = Memory.allocUtf8String(path);
  const fp = _fopen(rp, Memory.allocUtf8String('rb'));
  if (fp.isNull()) return null;
  const chunks = [];
  const buf = Memory.alloc(65536);
  for (;;) {
    const n = _fread(buf, 1, 65536, fp).toNumber();
    if (n === 0) break;
    chunks.push(buf.readByteArray(n));
  }
  _fclose(fp);
  return chunks;
}

rpc.exports = {
  ready() { return commander !== null; },
  // 解析器遗留态复位(phase5_dump.py 同源:+0x101 checkControlCharacter
  // 007cadda 直写 / +0xd8 挂起尾 QByteArray)
  resetState() {
    if (commander === null) return false;
    commander.add(0x101).writeU8(0);
    qbaClear(commander.add(0xd8));
    return true;
  },
  inject(hex) {
    if (commander === null) throw new Error('no commander');
    if (!hex) {
      // TODO(p3_notes_pxd):零长 writeSplitData 作为 dispatch 备路触发器,
      // 零长写行为未证(清单第 3 条)
      writeSplitData(commander, Memory.alloc(1), 0);
      return true;
    }
    const buf = hex.match(/../g).map(h => parseInt(h, 16));
    const mem = Memory.alloc(buf.length + 1);
    mem.writeByteArray(buf);
    mem.add(buf.length).writeU8(0);
    const ba = Memory.alloc(16);
    qbaNew(ba, mem, buf.length);
    writeSplitData(commander, mem, buf.length);
    return true;
  },
  // 置钩参数(mode:'paint'|'dispatch');实参 dims 与 renderpixtest 对齐
  arm(mode, w, h, path) {
    armed = true; armedMode = mode;
    curW = w; curH = h; curPath = path; captured = false;
    return true;
  },
  // 回传实参宽高(与 renderpixtest 对账,p3_notes §驱动1)
  readSize() { return { w: curW, h: curH, mode: armedMode, captured: captured }; },
  // 轮询捕获完成 → 读 PNG 字节回传(zlib 版本差不可字节比,仅作存在性/体积回传;
  // 逐像素 diff 在 Python 侧 PIL reload 做,p3_notes §5)
  save(path, timeoutMs) {
    const t0 = Date.now();
    while (!captured && Date.now() - t0 < (timeoutMs || 3000)) {
      Thread.sleep(0.05);
    }
    if (!captured) return { ok: false, w: curW, h: curH };
    const chunks = readAllBytes(path || curPath);
    return { ok: chunks !== null, w: curW, h: curH, bytes: chunks };
  },
};
'''


def force_repaint(env):
    """强制重绘兜底(p3_notes §2;xdotool 通道)。

    实测(2026-11-02):windowsize 不触发 00a1e1a4(paintN 不涨);
    键盘回显必触发(typing probe paintEnter/paintLeave 实锤)→
    echo 回显作为 repaint 触发器。
    """
    subprocess.run(['xdotool', 'mousemove', '640', '450', 'click', '1'],
                   env=env)
    time.sleep(0.3)
    subprocess.run(['xdotool', 'key', 'space'], env=env)
    time.sleep(0.6)
    return True


def baseline(script):
    """清屏基线(遗留态复位 + ESC[2J ESC[H ESC[r;phase5_dump.py baseline 同源)。"""
    script.exports_sync.resetState()
    script.exports_sync.inject('1b5b324a1b5b481b5b72')


def capture(script, seq, dims, out_dir, env, idx):
    """单序列:基线 → 注入 → arm → 强制重绘 → PNG 落盘。

    TODO(p3_notes_pxd):主路 paint 不 fire 时转 dispatch 备路(opt-in),
    两条未证链都留待在线验证(清单第 1/2 条)。
    """
    path = os.path.join(out_dir, 'px_orig_%d.png' % idx)
    baseline(script)
    time.sleep(1.0)                      # 前置 settle(phase5_dump iter1 强化)
    for part in seq['bytes'].split(','):
        script.exports_sync.inject(part)
        time.sleep(0.05)                 # 批间 flush 点(phase5_dump QUIRKS 13)
    time.sleep(0.6)                      # 批后 settle(phase5_dump probe15)
    script.exports_sync.arm('paint', dims[0], dims[1], path)
    force_repaint(env)
    res = script.exports_sync.save(path, 3000)
    if not res.get('ok'):
        # 备路(设计 §2):arm dispatch → 下一次任意 dispatch 钩内(GUI 线程)
        # 直呼;不主动 inject(零长写未证 + rpc 线程直呼违规)。触发 = 复发
        # 键盘回显(TODO 清单第 3 条:未证链保留原文,现按实测改走钩内)。
        script.exports_sync.arm('dispatch', dims[0], dims[1], path)
        force_repaint(env)
        res = script.exports_sync.save(path, 3000)
    dims_used = script.exports_sync.readSize()
    print(seq['name'], '->', 'captured' if res.get('ok') else 'MISS',
          'dims', dims_used.get('w'), dims_used.get('h'))
    return {'name': seq['name'], 'path': path if res.get('ok') else None,
            'dims': [dims_used.get('w'), dims_used.get('h')],
            'mode': dims_used.get('mode')}


def run_capture():
    here = os.path.dirname(os.path.abspath(__file__))
    seq_file = sys.argv[1] if len(sys.argv) > 1 \
        else os.path.join(here, 'phase5_seq.json')
    out_path = sys.argv[2] if len(sys.argv) > 2 \
        else '/tmp/opencode/phase5_px_original.json'
    out_dir = os.path.dirname(out_path)
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

    # 捕 commander(writeSplitData 钩;phase5_dump.py 同款打字触发 + exec sleep 哑化)
    # 注意:exec sleep 哑化 shell 后键盘仍有回显(sleep 进程不消费输入,行缓冲
    # 由 tty 回显)——force_repaint 的 space 回显依赖此点(2026-11-02 实证)。
    env = dict(os.environ, DISPLAY=':99')
    subprocess.run(['xdotool', 'mousemove', '640', '450', 'click', '1'],
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

    dims = (30, 101)   # 受控 QSizeF,与 renderpixtest 同参(p3_notes §驱动1)
    out = [capture(script, seq, dims, out_dir, env, i)
           for i, seq in enumerate(seqs)]
    with open(out_path, 'w') as f:
        json.dump(out, f, indent=1)
    print('written', out_path)


def diff_png(orig_png, ours_png):
    """双 PNG reload ARGB32 逐像素 diff(非字节比,zlib 版本差,p3_notes §5)。

    差异对账:cited 空洞(markerBand 桩 / S5 色槽 EditorEngine.cpp:2205-2230
    asm 未核)为预期差;其余 = 真转写 bug(QUIRKS 裁决流程,AGENTS 铁律 5)。
    """
    from PIL import Image
    a = Image.open(orig_png).convert('RGBA')   # reload → ARGB32 归一
    b = Image.open(ours_png).convert('RGBA')
    if a.size != b.size:
        print('SIZE MISMATCH %s vs %s' % (a.size, b.size))
        return 1
    ab, bb = a.tobytes(), b.tobytes()
    w = a.size[0]
    diffs = [i // 4 for i in range(0, len(ab), 4) if ab[i:i + 4] != bb[i:i + 4]]
    print('size %sx%s  diff pixels %d/%d' % (w, a.size[1], len(diffs),
                                             w * a.size[1]))
    for p in diffs[:20]:
        print('  (%d,%d) orig=%s ours=%s' % (
            p % w, p // w,
            tuple(ab[p * 4:p * 4 + 4]), tuple(bb[p * 4:p * 4 + 4])))
    # TODO(p3_notes_pxd):cited 空洞/markerBand 桩的自动分桶未做(清单第 5 条);
    # 坐标清单人工与 QUIRKS/cited 清单对账。
    return 0 if not diffs else 1


def main():
    if len(sys.argv) > 1 and sys.argv[1] == 'diff':
        sys.exit(diff_png(sys.argv[2], sys.argv[3]))
    run_capture()


if __name__ == '__main__':
    main()
