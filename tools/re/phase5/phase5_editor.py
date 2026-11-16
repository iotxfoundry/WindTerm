#!/usr/bin/env python3
# Phase 5b 原版侧捕获(批 121,M3-①):编辑引擎 21 序列注入原版 →
#   返回值/选区/docBytes 同格式 JSON → /tmp/opencode/phase5_editor_original.json
#
# 通道(00a418c4 dispatch 钩 armed 法;批 121 实测定案):
#   · editor = 钩 a[1](0x1270B EditorContext;vptr = ScintillaQt 0x11ae558,
#     vtable-map 定案)。**vtable+0x1c0 直呼不可行** — 0x1270B 对象表
#     尾 0x1c0 = 0(rpc 线程 access violation 实锤 ×2)。
#   · dispatch 本体 = FUN_00a418c4 五参直呼(ret,editor,cmd,a,b)在
#     **钩内**(= 自然 dispatch 上下文,GUI 线程;rpc 线程直呼同函数
#     反而崩 — 批 121 实测:7576 rpc 直呼 ret=0 但 4f00/4eff 段挂)。
#     armed 单命令队列:rpc.arm() → 下一自然 dispatch 钩内消费回读。
#     触发器 = xdotool 空格回显(exec sleep 哑化后 tty 仍回显,phase5_px
#     2026-11-02 实证同源)。
#   · ⚠ op 桥面 0x4f00 withOp 首测 = 目标进程死(script destroyed;批 121
#     事故)。裁决:0x4f00/0x4eff 的 op 指针经 QVariant(int64) 传入后,
#     原版段 A codec 族(FUN_0089a756 canOld → op+0xc&5 门)在 **桥面 op
#     零值 flags=0** 下走 +0x58 针缓存查(QHash<QString,null> 壳态)→
#     深腿候选(canOld=false 分支 selMode 翻转 + 0x4f00 段 B type==3
#     事务 cited 0x009cff30 → editor_undoBegin 0092be0a 698B — undo 族
#     深腿在真 undo 栈上跑)——B 族构型触发原版 undo/选区写侧深链,
#     稳定性不足 = 仪器级风险。**收口裁决:withOp 腿禁用**(任务书环境
#     纪律"勿动勿杀勿重启"优先;重启原版一次后本脚本不再触碰 op 直填,
#     B/C 族改走 dispatchRet 读数 + ctx 读格)。
#   · A 族:op 直填同禁 → 0x4eff dispatch 经 a=null(qint64 0)→ 语料
#     22609 toULongLong → opb=0 非空判?0 = null 桥 → 原版 12651 链在
#     op=0 上解引用会崩。**A 族只捕 dispatchRet 经 0x7576 同构 armed 读**
#     不发 0x4eff/0x4f00;原版 A 族对账改由 **b116/drive 样例**(calibration
#     批 116 五样例,同引擎腿字节对账)承担,原版侧 dispatch 面读数记
#     not-run + 原因。
#
# 产出 JSON 行:{seq_id, family, dispatchRet?, opHits?, sel?, err/notRun}
# 对表:tools/re/phase5/phase5_editor_compare.py(我方基线
#   /tmp/opencode/phase5_seq_editor.json)。
import json
import os
import subprocess
import sys
import time

import frida

SEQS_PATH = '/tmp/opencode/phase5_seq_editor.json'
OUT_PATH = '/tmp/opencode/phase5_editor_original.json'

AGENT = r'''
// ---- 符号面(nm -D @@Qt_5 逐一核验;phase5_px 同法)----
const core = Process.getModuleByName('libQt5Core.so.5');
const qvarLlong = new NativeFunction(
    core.getExportByName('_ZN8QVariantC1Ex'), 'void', ['pointer', 'int64']);
const qvarDtor = new NativeFunction(
    core.getExportByName('_ZN8QVariantD1Ev'), 'void', ['pointer']);
const userType = new NativeFunction(
    core.getExportByName('_ZNK8QVariant8userTypeEv'), 'int', ['pointer']);
const toLlong = new NativeFunction(
    core.getExportByName('_ZNK8QVariant10toLongLongEPb'),
    'long', ['pointer', 'pointer']);
const DISPATCH = ptr('0x00a418c4');   // s_line_caret_remote_a418c4(0034:20740)
const dispatchFn = new NativeFunction(DISPATCH, 'void',
    ['pointer', 'pointer', 'uint', 'pointer', 'pointer']);

let editor = null;      // 00a418c4 钩 a[1](0x1270B EditorContext)
let armed = null;       // 单命令队列(rpc.arm → 钩内消费)
let result = null;      // 回读

function mkVar(v) { const m = Memory.alloc(16); qvarLlong(m, int64(v)); return m; }

Interceptor.attach(DISPATCH, {
  onEnter(a) {
    if (editor === null && !a[1].isNull()) {
      editor = a[1];
      send({ type: 'editor-captured', editor: editor.toString() });
    }
    if (armed !== null && editor !== null) {
      const r = armed;
      armed = null;                       // 一次一捕(批 98 竞态教训)
      const ret = Memory.alloc(16);
      dispatchFn(ret, editor, r.cmd, r.a, r.b);
      const out = { t: userType(ret),
                    v: toLlong(ret, NULL).toString() };
      qvarDtor(ret);
      if (r.selRead) {
        const r1 = Memory.alloc(16), r2 = Memory.alloc(16);
        dispatchFn(r1, editor, 2143, mkVar(0), Memory.alloc(16)); // SCI_GETSELSTART
        dispatchFn(r2, editor, 2145, mkVar(0), Memory.alloc(16)); // SCI_GETSELEND
        out.sel = [toLlong(r1, NULL).toString(),
                   toLlong(r2, NULL).toString()];
        qvarDtor(r1); qvarDtor(r2);
      }
      // ctx 读格(C 族):runvector/charUsed 挂 **c92c 对象** = 
      //   *(editor+0x10a0)(0x4f00 22852 面 param_2[0x214] = c92c 载体;
      //   runvector = c92c+0x178 = 槽 [0x2f](FUN_009585a2 ctor 26062 清零
      //   面);charUsed = c92c+0x180 = 槽 [0x30]。editor+0x178/0x180 是
      //   EditorContext(我方模型)偏移 — 原版 c92c obj 独立承载,批 121
      //   实测勘正(0x178 直读 = 0x1000d0000 垃圾)。
      const c92c = editor.add(0x10a0).readPointer();
      if (!c92c.isNull()) {
        const rv = c92c.add(0x2f * 8).readPointer();
        if (!rv.isNull()) {
          const d = rv.readPointer();
          if (!d.isNull())
            out.runVec = d.add(4).readS32() - d.readS32(); // end−begin
          else out.runVec = 0;
        } else out.runVec = 0;
        const cu = c92c.add(0x30 * 8).readPointer();
        out.charUsed = cu.isNull() ? null : cu.toString();
      }
      result = out;
    }
  }
});

rpc.exports = {
  editor() { return editor === null ? null : editor.toString(); },
  // 置单命令(cmd, a 的 qint64 值;是否附选区读)。**不带 op 桥面**:
  //   0x4f00/0x4eff withOp 腿批 121 实测目标死(头注裁决)。
  arm(cmd, along, selRead) {
    if (armed !== null) return false;      // 队列占用(前发未消费)
    armed = { cmd: cmd, a: mkVar(along), b: Memory.alloc(16),
              selRead: !!selRead };
    result = null;
    return true;
  },
  poll() { return result; },
  pending() { return armed !== null; },
};
'''


def attach():
    pids = subprocess.run(['pgrep', '-x', 'WindTerm'],
                          capture_output=True, text=True).stdout.split()
    if not pids:
        print('WindTerm not running')
        sys.exit(2)
    print('attaching to', pids[0])
    session = frida.get_local_device().attach(int(pids[0]))
    script = session.create_script(AGENT)
    script.on('message', lambda m, d: print('[msg]',
               m.get('payload') or m.get('description')))
    script.load()
    return script


def trigger(env):
    subprocess.run(['xdotool', 'mousemove', '640', '450', 'click', '1'],
                   env=env)
    time.sleep(0.15)
    subprocess.run(['xdotool', 'key', 'space'], env=env)


def wait_result(script, env, timeout=6.0):
    t0 = time.time()
    while time.time() - t0 < timeout:
        if not script.exports_sync.pending():
            return script.exports_sync.poll()
        trigger(env)
        time.sleep(0.7)
    return None


def main():
    with open(SEQS_PATH) as f:
        seqs = json.load(f)
    script = attach()
    env = dict(os.environ, DISPLAY=':99')

    # 捕 editor(xdotool 回显触发自然 dispatch)
    subprocess.run(['xdotool', 'mousemove', '500', '400', 'click', '1'],
                   env=env)
    time.sleep(0.3)
    editor = None
    for _ in range(24):
        try:
            editor = script.exports_sync.editor()
        except Exception:
            editor = None
        if editor:
            break
        trigger(env)
        time.sleep(0.5)
    print('editor =', editor)
    if not editor:
        print('NO EDITOR CAPTURED')
        sys.exit(3)

    out = []
    for seq in seqs:
        sid = seq['seq_id']
        fam = seq.get('family')
        rec = {'seq_id': sid, 'family': fam}
        if fam in ('4eff-ruby', '4f00-wordstep'):
            # op 桥面直填腿禁用(脚本头注裁决:批 121 目标死事故);
            # dispatch 读数 notRun,对账由 calibration 批 116 五样例
            # (同引擎腿字节对账)与我方 onigtest/wordsteptest 承担。
            rec['notRun'] = 'op-bridge disabled (b121 crash gate)'
        elif fam == '7576-insertstyle':
            try:
                ok = script.exports_sync.arm(0x7576, 0, False)
                r = wait_result(script, env) if ok else None
                if r:
                    rec['ret'] = int(r.get('v', '0'))
                    rec['userType'] = r.get('t')
                    rec['runVecSize'] = r.get('runVec')
                    rec['charUsedPtr'] = r.get('charUsed')
                else:
                    rec['notRun'] = 'armed dispatch not consumed'
            except Exception as e:
                rec['err'] = str(e)[:160]
        else:
            rec['skip'] = 'unknown family'
        out.append(rec)
        print('[seq]', sid, '->', json.dumps(
            {k: v for k, v in rec.items() if k != 'family'})[:140])
        time.sleep(0.15)

    with open(OUT_PATH, 'w') as f:
        json.dump(out, f, indent=1)
    print('written', OUT_PATH)


if __name__ == '__main__':
    main()
