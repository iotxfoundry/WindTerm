#!/usr/bin/env python3
"""全仓逆向覆盖索引 —— 转写前的"这里是不是已经做过了"查询入口。

扫描 src/ (排除第三方库), 建立 **二进制地址 → 文件** 反查表, 并给出:
  · 按目录分组的规模/类数/地址数
  · 同一地址被 2+ 个 .cpp 引用(潜在重复实现)
  · src 引用但语料里找不到的地址(出处存疑)

用法:
  coverage.py                 # 总览(分组表)
  coverage.py --addr 006b3124 # 这个函数在哪几个文件里被引用/实现
  coverage.py --dups          # 潜在重复实现
  coverage.py --check         # 地址有效性
  coverage.py --write         # 重新生成 docs/meta/coverage-map.md 与 data/fun_index.tsv
"""
import re, sys, glob, os, collections

SRC = os.path.join(os.path.dirname(__file__), '..', '..', 'src')
DECOMP = os.path.join(os.path.dirname(__file__), 'decomp')
DATA = os.path.join(os.path.dirname(__file__), 'data')
EXCLUDE = ('Scintilla', 'jsoncpp', 'yaml-cpp', 'spdlog', 'fmt', 'dtl', 'libssh', 'Onigmo')


def files():
    for f in glob.glob(os.path.join(SRC, '**', '*.*'), recursive=True):
        if any(x in f for x in EXCLUDE):
            continue
        if f.endswith(('.h', '.cpp')):
            yield f


TEXT_LO, TEXT_HI = 0x4c33c0, 0xc89000     # .text 范围(非 PIE, 只认代码地址)


def addrs_of(text):
    """三种出处写法统一归一化为 8 位地址:

      FUN_0064ab10 / 0064ab10(裸地址) / s_CheckList_534e62(6 位符号名)

    裸地址必须落在 .text 内,避免把 `00000005` 这类字面量当成出处。
    """
    fun = set(re.findall(r'(?<!PTR_)FUN_([0-9a-f]{8})', text))
    out = set(fun)
    for a in re.findall(r'(?<![\w.])(00[0-9a-f]{6})(?![\w])', text):
        if TEXT_LO <= int(a, 16) < TEXT_HI:
            out.add(a)
    for a in re.findall(r'\bs_[A-Za-z0-9_]+_([0-9a-f]{6})\b', text):
        out.add('00' + a)
    return out, fun


def scan():
    """→ {相对路径: {'lines','classes','addrs':set,'cited'}}"""
    out = {}
    for f in files():
        s = open(f, encoding='utf-8', errors='ignore').read()
        rel = os.path.relpath(f, os.path.join(SRC, '..'))
        alladdrs, funaddrs = addrs_of(s)
        out[rel] = {
            'lines': s.count('\n') + 1,
            'classes': re.findall(r'^\s*(?:class|struct)\s+([A-Za-z_]\w*)\s*(?::|\{)', s, re.M),
            'addrs': alladdrs,
            'fun_addrs': funaddrs,
            'cited': len(re.findall(r'//\s*cited|— cited', s)),
        }
    return out


MANIFEST = os.path.join(DATA, 'open_source_files.txt')


def open_source():
    if not os.path.exists(MANIFEST):
        return []
    return [l.strip() for l in open(MANIFEST, encoding='utf-8') if l.strip()]


def impl_addrs():
    """实现级地址归属:每个函数定义绑定**紧邻其上的那一行注释**里的地址。

    只认最近一行(而不是整个注释块) —— 我们的写法里,函数自身出处总在
    定义正上方;再往上多半是「调用了谁」,那些地址属被调方,不是本类实现。
    含「同构」的行跳过(借用姊妹类出处)。
    """
    m = collections.defaultdict(set)
    for f in files():
        if not f.endswith('.cpp'):
            continue
        L = open(f, encoding='utf-8', errors='ignore').read().split('\n')
        for i, l in enumerate(L):
            if not re.match(r'^[\w:<>,*&\s]*?\b\w+::\w+\s*\(', l):
                continue
            k = i - 1
            while k >= 0 and not L[k].strip():
                k -= 1
            # 在紧邻的注释块里找「本函数出处」行:必须带 真身 / 字节数 / ===
            hit = None
            while k >= 0 and L[k].lstrip().startswith('//'):
                if '同构' not in L[k] and (
                        '真身' in L[k]
                        or re.search(r'FUN_[0-9a-f]{8}\s*\(\s*\d+\s*B', L[k])
                        or re.match(r'\s*//\s*===', L[k])):
                    a = re.findall(r'(?<!PTR_)FUN_([0-9a-f]{8})', L[k])
                    if a:
                        hit = a[0]
                        break
                k -= 1
            if hit:
                m[hit].add(os.path.relpath(f, os.path.join(SRC, '..')))
    return m


def corpus_addrs():
    s = set()
    for f in glob.glob(os.path.join(DECOMP, '*.c')):
        s |= set(re.findall(r'entry=([0-9a-f]{8})', open(f, encoding='utf-8', errors='ignore').read()))
    return s


def groups(scan_):
    g = collections.defaultdict(lambda: {'files': 0, 'lines': 0, 'classes': 0, 'addrs': set(), 'cited': 0})
    for rel, d in scan_.items():
        parts = rel.split(os.sep)                      # src/<Group>/...
        key = os.sep.join(parts[1:3]) if len(parts) > 3 else parts[1]
        if not rel.endswith('.h'):                     # 类/行数只按 .h 与 .cpp 合计
            g[key]['files'] += 1
        else:
            g[key]['files'] += 1
        g[key]['lines'] += d['lines']
        g[key]['classes'] += len(d['classes'])
        g[key]['addrs'] |= d['addrs']
        g[key]['cited'] += d['cited']
    return g


def main():
    scan_ = scan()
    addr2files = collections.defaultdict(set)
    for rel, d in scan_.items():
        for a in d['addrs']:
            addr2files[a].add(rel)

    if '--addr' in sys.argv:
        a = sys.argv[sys.argv.index('--addr') + 1].lower().replace('0x', '')
        hit = sorted(addr2files.get(a, []))
        print('FUN_%s → %d 个文件' % (a, len(hit)))
        for h in hit:
            print('   ', h)
        sys.exit(0)

    if '--dups' in sys.argv:
        impl = impl_addrs()
        bad = [(a, sorted(f)) for a, f in impl.items() if len(f) > 1]
        print('疑似重复实现(同一地址在 2+ 个 .cpp 带实现标记):', len(bad))
        for a, f in sorted(bad, key=lambda kv: -len(kv[1])):
            print('  FUN_%s (%d) %s' % (a, len(f), ', '.join(f)))
        sys.exit(0)

    if '--check' in sys.argv:
        corp = corpus_addrs()
        alladdr = set(addr2files)
        claimed = set()
        for d in scan_.values():
            claimed |= d['fun_addrs']
        miss = sorted(claimed - corp)
        print('断言为函数的地址(FUN_ 形式): %d' % len(claimed))
        text = [a for a in miss if int(a, 16) < 0x0c89000]
        data = [a for a in miss if int(a, 16) >= 0x0c89000]
        print('src 引用地址 %d / 语料条目 %d' % (len(alladdr), len(corp)))
        print('语料里找不到: %d  (.text 内 %d / 数据段 %d)' % (len(miss), len(text), len(data)))
        print('\n-- .text 内不在语料(可能是 thunk 或函数内部地址,需人工核) --')
        for a in text:
            print('  FUN_%s  %s' % (a, ', '.join(sorted(addr2files[a]))[:80]))
        print('\n-- 数据段(实为 vtable/符号,不应写成 FUN_ 调用) --')
        for a in data:
            print('  0x%s  %s' % (a, ', '.join(sorted(addr2files[a]))[:80]))
        sys.exit(0)

    if '--audit' in sys.argv:
        want = open_source()
        prose = re.compile(r'语料|反编译|Reconstructed from WindTerm|QMetaObject|出处')
        bmiss, bstray, unlab, empty = [], [], [], []
        for rel, d in scan_.items():
            full = os.path.join(SRC, '..', rel)
            txt = open(full, encoding='utf-8', errors='ignore').read()
            marked = '[B-OPENSOURCE]' in txt
            if rel in want:
                if not marked:
                    bmiss.append(rel)
            elif marked:
                bstray.append(rel)
            elif not d['addrs'] and 'cited' not in txt and not prose.search(txt):
                unlab.append(rel)
            if not txt.strip():
                empty.append(rel)
        print('第一方开源件(B): %d  清单内缺标记 %d / 有标记不在清单 %d'
              % (len(want), len(bmiss), len(bstray)))
        print('有出处或说明(A): %d' % (len(scan_) - len(unlab) - len(want)))
        print('**无任何出处/说明**: %d' % len(unlab))
        for x in unlab:
            print('   ', x)
        print('空文件: %d %s' % (len(empty), empty))
        rc = 1 if (bmiss or bstray or unlab) else 0
        sys.exit(rc)

    g = groups(scan_)
    total = {'files': 0, 'lines': 0, 'classes': 0, 'cited': 0}
    rows = []
    for k in sorted(g):
        d = g[k]
        rows.append((k, d['files'], d['lines'], d['classes'], len(d['addrs']), d['cited']))
        for f in ('files', 'lines', 'classes', 'cited'):
            total[f] += d[f]
    alladdr = set(addr2files)

    if '--write' in sys.argv:
        os.makedirs(DATA, exist_ok=True)
        with open(os.path.join(DATA, 'fun_index.tsv'), 'w', encoding='utf-8') as fh:
            for a in sorted(addr2files):
                for p in sorted(addr2files[a]):
                    fh.write('%s\t%s\n' % (a, p))
        lines = ['# 全仓逆向覆盖索引（自动生成，勿手改）', '',
                 '> 生成:`python3 tools/re/coverage.py --write`。',
                 '> 用途:**转写任何函数前先 `coverage.py --addr <地址>`**,确认是否已有实现,',
                 '> 避免在已有代码上重复新增。', '',
                 '## 1. 分组规模', '',
                 '| 目录 | 文件 | 行数 | 类 | 唯一地址 | cited 标记 |', '|---|---:|---:|---:|---:|---:|']
        for k, n, l, c, a, ci in rows:
            lines.append('| `%s` | %d | %d | %d | %d | %d |' % (k, n, l, c, a, ci))
        lines.append('| **合计** | **%d** | **%d** | **%d** | **%d** | **%d** |'
                     % (total['files'], total['lines'], total['classes'], len(alladdr), total['cited']))
        shared = sorted(((len(f), a) for a, f in addr2files.items()), reverse=True)[:15]
        lines += ['', '## 2. 被引用最多的地址（多为共享腿，不要重复实现）', '',
                  '| 地址 | 文件数 | 位置 |', '|---|---:|---|']
        for n, a in shared:
            lines.append('| `FUN_%s` | %d | %s |' % (a, n, '<br>'.join(sorted(addr2files[a])[:4])))
        impl = impl_addrs()
        dup = [(a, sorted(f)) for a, f in impl.items() if len(f) > 1]
        lines += ['', '## 3. 疑似重复实现（同一地址在 2+ 个 .cpp 带实现标记）', '',
                  '判定:函数定义紧邻注释块中带 `真身`/字节数/`===` 的那一行,'
                  '取首个地址作为该函数出处;含 `同构` 的行不计。共 **%d** 处。' % len(dup),
                  '逐条核对:共享腿(合理,补交叉引用)还是重复转写(应合并)。', '',
                  '| 地址 | 文件 |', '|---|---|']
        for a, f in sorted(dup, key=lambda kv: -len(kv[1])):
            lines.append('| `FUN_%s` | %s |' % (a, '<br>'.join(f)))
        want = open_source()
        lines += ['', '## 4. 第一方开源件（B 类·勿逆向）', '',
                  '文件带 `[B-OPENSOURCE]` 标记;清单 `tools/re/data/open_source_files.txt`;'
                  '校验 `coverage.py --audit`。', '', '| 文件 |', '|---|']
        for w in want:
            lines.append('| `%s` |' % w)
        with open(os.path.join(os.path.dirname(__file__), '..', '..', 'docs', 'meta', 'coverage-map.md'),
                  'w', encoding='utf-8') as fh:
            fh.write('\n'.join(lines) + '\n')
        print('已生成 docs/meta/coverage-map.md（%d 组 / %d 地址 / %d 处重复）'
              % (len(rows), len(alladdr), len(dup)))
        sys.exit(0)

    print('%-26s %5s %7s %4s %6s %6s' % ('目录', '文件', '行数', '类', '地址', 'cited'))
    for k, n, l, c, a, ci in rows:
        print('%-26s %5d %7d %4d %6d %6d' % (k, n, l, c, a, ci))
    print('%-26s %5d %7d %4d %6d %6d' % ('合计', total['files'], total['lines'],
                                         total['classes'], len(alladdr), total['cited']))


if __name__ == '__main__':
    main()
