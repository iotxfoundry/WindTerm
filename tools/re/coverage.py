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


def scan():
    """→ {相对路径: {'lines','classes','addrs':set,'cited'}}"""
    out = {}
    for f in files():
        s = open(f, encoding='utf-8', errors='ignore').read()
        rel = os.path.relpath(f, os.path.join(SRC, '..'))
        out[rel] = {
            'lines': s.count('\n') + 1,
            'classes': re.findall(r'^\s*(?:class|struct)\s+([A-Za-z_]\w*)\s*(?::|\{)', s, re.M),
            'addrs': set(re.findall(r'(?<!PTR_)FUN_([0-9a-f]{8})', s)),
            'cited': len(re.findall(r'//\s*cited|— cited', s)),
        }
    return out


MANIFEST = os.path.join(DATA, 'open_source_files.txt')


def open_source():
    if not os.path.exists(MANIFEST):
        return []
    return [l.strip() for l in open(MANIFEST, encoding='utf-8') if l.strip()]


def impl_addrs():
    """带实现标记(`真身` 或 `// ===` 函数头)的地址 → .cpp 集合。

    只认实现标记,不认普通引用 —— 否则共享腿会淹没真正的重复转写。
    """
    m = collections.defaultdict(set)
    for f in files():
        if not f.endswith('.cpp'):
            continue
        for ln in open(f, encoding='utf-8', errors='ignore'):
            if '真身' not in ln and not re.match(r'\s*//\s*===', ln):
                continue
            for a in re.findall(r'(?<!PTR_)FUN_([0-9a-f]{8})', ln):
                m[a].add(os.path.relpath(f, os.path.join(SRC, '..')))
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
        miss = sorted(alladdr - corp)
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
        bad_missing = [f for f in want if os.path.exists(f)
                       and '[B-OPENSOURCE]' not in open(f, encoding='utf-8', errors='ignore').read()]
        bad_stray = [rel for rel, d in scan_.items()
                     if rel.endswith(('.h', '.cpp'))
                     and '[B-OPENSOURCE]' in open(os.path.join(SRC, '..', rel), encoding='utf-8', errors='ignore').read()
                     and rel not in want]
        suspect = [rel for rel, d in scan_.items()
                   if rel not in want and rel.endswith(('.h', '.cpp'))
                   and not d['addrs'] and d['cited'] == 0 and 'ApplicationTheme' not in rel
                   and 'KingEnums' not in rel and 'Ext' not in rel and 'Stubs' not in rel]
        print('B 类清单: %d 个文件' % len(want))
        print('清单内缺标记: %d %s' % (len(bad_missing), bad_missing[:5]))
        print('有标记但不在清单: %d %s' % (len(bad_stray), bad_stray[:5]))
        print('无标记且零 FUN_/cited(疑似漏标,需人工判): %d' % len(suspect))
        for x in suspect[:12]:
            print('   ', x)
        sys.exit(0 if not bad_missing and not bad_stray else 1)

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
                  '只统计带 `真身` / `// ===` 实现标记的行,普通引用不计 —— 共 **%d** 处。' % len(dup),
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
