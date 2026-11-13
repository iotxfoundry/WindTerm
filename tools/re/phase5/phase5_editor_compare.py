#!/usr/bin/env python3
# 批 121:Phase 5b 21 序列对表(我方基线 phase5_seq_editor.json × 原版
#   phase5_editor_original.json)→ 逐序列 MATCH/MISMATCH + RUBY 语法假设
#   裁决节。只报告,不修产品码(QUIRKS 裁决流程)。
import json
import sys

OURS = '/tmp/opencode/phase5_seq_editor.json'
ORIG = '/tmp/opencode/phase5_editor_original.json'


def field(rec, name):
    v = rec.get(name)
    return None if v is None else v


def main():
    ours = json.load(open(OURS))
    orig = {r['seq_id']: r for r in json.load(open(ORIG))}
    match, mism, notrun = 0, [], []
    print('%-4s %-18s %-28s %s' % ('seq', 'family', 'ours', 'original'))
    for o in ours:
        sid = o['seq_id']
        d = orig.get(sid, {})
        if 'notRun' in d or 'err' in d:
            reason = d.get('notRun') or d.get('err', '')[:60]
            notrun.append((sid, reason))
            print('%-4s %-18s NOT-RUN original: %s' % (sid, o['family'], reason))
            continue
        if o['family'] == '7576-insertstyle':
            o_ret = o.get('ret')
            o_rv = o.get('runVecSize')
            o_cu = o.get('charUsedRuns')
            d_ret = d.get('ret')
            d_rv = d.get('runVecSize')
            # 原版 charUsedPtr = null → runs 不可数(壳态无 0x20 壳对象)
            d_cu = -1 if d.get('charUsedPtr') is None else None
            bad = []
            if o_ret != d_ret:
                bad.append('ret %s vs %s' % (o_ret, d_ret))
            if o_rv != d_rv:
                bad.append('runVec %s vs %s' % (o_rv, d_rv))
            if d_cu is not None and o_cu != d_cu:
                bad.append('charUsedRuns %s vs %s' % (o_cu, d_cu))
            if bad:
                mism.append((sid, bad))
                print('%-4s %-18s MISMATCH %s' % (sid, o['family'],
                                                  '; '.join(bad)))
            else:
                match += 1
                print('%-4s %-18s MATCH ret=%s rv=%s' % (sid, o['family'],
                                                         o_ret, o_rv))
        else:
            notrun.append((sid, 'op-bridge gate'))
    print()
    print('=== 5B: %d/%d MATCH, %d MISMATCH, %d NOT-RUN' % (
        match, len(ours), len(mism), len(notrun)))
    if mism:
        for sid, bad in mism:
            print('  MISMATCH', sid, bad)
    return 0


if __name__ == '__main__':
    sys.exit(main())
