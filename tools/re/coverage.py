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
  coverage.py --write         # 重新生成 coverage-map.md / work-ledger.md / 两个 tsv
  coverage.py --ledger        # 只重算并打印工作总账(四状态 + 双分母)
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


def corpus_entries():
    """→ {addr: (name, size)},只取 .text 内的语料条目(排除 PLT/数据)。"""
    e = {}
    for f in glob.glob(os.path.join(DECOMP, '*.c')):
        for m in re.finditer(r'entry=([0-9a-f]{8}) name=(\S+) size=(\d+)',
                             open(f, encoding='utf-8', errors='ignore').read()):
            if TEXT_LO <= int(m.group(1), 16) < TEXT_HI:
                e[m.group(1)] = (m.group(2), int(m.group(3)))
    return e


def defs_status():
    """→ (real, stub)。按函数定义分两档:

      real = 定义紧邻注释带出处,且函数体去掉注释/空白后 >40 字符(真实现)
      stub = 带出处但体近乎空壳(只有注释 / Q_UNUSED)—— 半成品

    与 impl_addrs() 的区别:impl_addrs 只判「有无出处」(供 --dups),
    本函数额外看体量,供 --ledger 区分真实现与半成品。
    """
    real, stub = set(), set()
    for f in files():
        if not f.endswith('.cpp'):
            continue
        L = open(f, encoding='utf-8', errors='ignore').read().split('\n')
        i = 0
        while i < len(L):
            if not re.match(r'^[\w:<>,*&\s]*?\b\w+::\w+\s*\(', L[i]):
                i += 1
                continue
            s0 = i
            while s0 > 0 and L[s0 - 1].lstrip().startswith('//'):
                s0 -= 1
            cmt = '\n'.join(L[s0:i])
            j, depth, seen = i, 0, False
            while j < len(L):
                depth += L[j].count('{') - L[j].count('}')
                if '{' in L[j]:
                    seen = True
                if seen and depth == 0:
                    break
                j += 1
            body = '\n'.join(L[i:j + 1])
            nb = re.sub(r'//[^\n]*', '', body)
            nb = re.sub(r'/\*.*?\*/', '', nb, flags=re.S)
            nb = re.sub(r'\s+', '', nb)
            a = re.findall(r'(?<!PTR_)FUN_([0-9a-f]{8})', cmt)
            if a:
                (real if len(nb) > 40 else stub).add(a[0])
            i = j + 1
    return real, stub


def work_ledger(addr2files):
    """→ (md_lines, tsv_lines)。四状态 + 双分母(函数数 / 字节数)。"""
    ent = corpus_entries()
    real, stub = defs_status()
    ref = set()
    for d in scan().values():
        ref |= d['addrs']
    st = {}
    for a, (n, sz) in ent.items():
        if a in real:
            st[a] = 'real'
        elif a in stub:
            st[a] = 'stub'
        elif a in ref:
            st[a] = 'ref'
        else:
            st[a] = 'todo'

    order = ['real', 'stub', 'ref', 'todo']
    label = {'real': '真实现', 'stub': '半成品', 'ref': '引用档', 'todo': '未触及'}
    cnt = collections.Counter(st.values())
    byt = collections.Counter()
    for a, (n, sz) in ent.items():
        byt[st[a]] += sz
    tot, totb = len(ent), sum(sz for _, sz in ent.values())

    L = ['# 逆向工作总账（自动生成，勿手改）', '',
         '> 生成:`python3 tools/re/coverage.py --write`(或 `--ledger` 只打印)。',
         '> 分母 = 语料 `.text` 内 %d 条(排除 PLT/数据);' % tot,
         '> 同一件事有两个量纲 —— **函数数**与**字节数**,两者差一倍以上,'
         '所以下表两列都给。', '',
         '## 1. 四状态口径', '',
         '| 状态 | 判据 |', '|---|---|',
         '| 真实现 | 函数定义紧邻注释里带出处,且函数体去掉注释/空白后 >40 字符 |',
         '| 半成品 | 带出处,但函数体近乎空壳(只有注释 / `Q_UNUSED`) |',
         '| 引用档 | 地址只在别处被引用(接口声明、调用点、`cited` 注释),没有本函数定义 |',
         '| 未触及 | 地址不出现在 `src/` 任何文件 |', '',
         '## 2. 总账', '',
         '| 状态 | 函数 | 函数占比 | 字节 | 字节占比 |', '|---|---:|---:|---:|---:|']
    for k in order:
        L.append('| %s | %d | %.2f%% | %d | %.2f%% |'
                 % (label[k], cnt[k], cnt[k] / tot * 100, byt[k], byt[k] / totb * 100))
    L.append('| **合计** | **%d** | 100%% | **%d** | 100%% |' % (tot, totb))

    # 按文件
    per = collections.defaultdict(lambda: collections.Counter())
    for a, s in st.items():
        for f in addr2files.get(a, ()):
            per[f][s] += 1
    rows = sorted(per.items(), key=lambda kv: (-kv[1]['real'] - kv[1]['stub'], kv[0]))
    L += ['', '## 3. 按文件（有落点的）', '',
          '`未触及` 无法按文件分(它没有落点),故只列三档。', '',
          '| 文件 | 真实现 | 半成品 | 引用档 |', '|---|---:|---:|---:|']
    for f, c in rows:
        if not (c['real'] or c['stub']):
            continue
        L.append('| `%s` | %d | %d | %d |' % (f, c['real'], c['stub'], c['ref']))

    # 未触及池
    todo = sorted((sz, a, n) for a, (n, sz) in ent.items() if st[a] == 'todo')
    L += ['', '## 4. 未触及池（按体积降序前 50，下一批候选）', '',
          '| 地址 | 语料名 | 字节 |', '|---|---|---:|']
    for sz, a, n in todo[::-1][:50]:
        L.append('| `%s` | `%s` | %d |' % (a, n, sz))

    # §5 RTTI 类清单:哪些类已有落点文件、文件里落了多少
    # 归属判据:先按「文件名 == 类名(或类名+Face)」钉死,再回退到首个声明点。
    # 只认真正的类定义(`class X {` / `class X : ...`),前向声明 `class X;` 不算。
    decl = collections.defaultdict(list)
    for f in files():
        if not f.endswith('.h'):
            continue
        t = open(f, encoding='utf-8', errors='ignore').read()
        rel = os.path.relpath(f, os.path.join(SRC, '..'))
        for m in re.finditer(r'^\s*(?:class|struct)\s+(\w+)\s*(?::|\{)', t, re.M):
            decl[m.group(1)].append(rel)
    owner = {}
    for name, fl in decl.items():
        keys = [name] + ([name[:-4]] if name.endswith('Face') else [])
        for k in keys:
            hit = [x for x in fl if os.path.basename(x)[:-2] in (k, k + 'Face')]
            if hit:
                owner.setdefault(k, hit[0])
            else:
                owner.setdefault(k, fl[0])
    rtti_path = os.path.join(DATA, 'rtti_classes.txt')
    rtti = [l.strip() for l in open(rtti_path, encoding='utf-8')] if os.path.exists(rtti_path) else []
    built = [(c, owner[c]) for c in rtti if c in owner]
    missing = [c for c in rtti if c not in owner]
    L += ['', '## 5. RTTI 类清单（%d 个：已建 %d / 未建 %d）' % (len(rtti), len(built), len(missing)),
          '',
          '> 类名来自 `tools/re/data/rtti_classes.txt`（typeinfo 扫出，**含上游类**）',
          '> 上游类（Scintilla 的 `RunStyles*`/`GapBuffer*`/`UPartitioning`、',
          '> universalchardet 的 `ns*Prober`、标准库类型）**不是逆向目标**，',
          '> 它们出现在此表只表示「二进制里有多态类」，不代表欠债。',
          '> 已建 = 我方有同名（或去 `Face` 后缀同名）的声明文件。',
          '> 后两列是**文件级**计数：一个文件装多个类时(如 `TriggerPageFace.h` 装 13 个)，',
          '> 这几个类会显示同一组数字 —— 二进制里无法把地址反推到具体类，故不伪造类级数字。', '',
          '| 类 | 文件 | 该文件真实现 | 该文件半成品 |', '|---|---|---:|---:|']
    for c, f in built:
        cc = per.get(f, collections.Counter())
        L.append('| `%s` | `%s` | %d | %d |' % (c, f, cc['real'], cc['stub']))
    L += ['', '**未建 %d 个**：' % len(missing), '',
          ', '.join('`%s`' % c for c in missing)]

    tsv = []
    for a, (n, sz) in sorted(ent.items()):
        tsv.append('%s\t%d\t%s\t%s\t%s'
                   % (a, sz, n, st[a], ','.join(sorted(addr2files.get(a, ())))))
    return L, tsv, (cnt, byt, tot, totb)


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

    if '--ledger' in sys.argv and '--write' not in sys.argv:
        L, tsv, (cnt, byt, tot, totb) = work_ledger(addr2files)
        print('语料 .text 条目 %d / %d 字节' % (tot, totb))
        for k, n in (('real', '真实现'), ('stub', '半成品'),
                     ('ref', '引用档'), ('todo', '未触及')):
            print('  %-8s %6d  %5.2f%%   %9d  %5.2f%%'
                  % (n, cnt[k], cnt[k] / tot * 100, byt[k], byt[k] / totb * 100))
        print()
        print('\n'.join(L[-56:]))
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

    if '--what' in sys.argv:
        arg = sys.argv[sys.argv.index('--what') + 1]
        # 允许传类名:先按类名找声明文件
        if not arg.endswith(('.h', '.cpp')):
            for f in glob.glob(os.path.join(SRC, '**', '*.h'), recursive=True):
                if re.search(r'^\s*(?:class|struct)\s+%s\b' % re.escape(arg),
                             open(f, encoding='utf-8', errors='ignore').read(), re.M):
                    arg = os.path.relpath(f, os.path.join(SRC, '..'))
                    break
            else:   # 退回按文件名匹配(文件名≠类名的情况,如 KingEnums.h)
                for f in glob.glob(os.path.join(SRC, '**', arg + '.*'), recursive=True):
                    arg = os.path.relpath(f, os.path.join(SRC, '..'))
                    break
        if not os.path.exists(arg):
            print('找不到:', arg); sys.exit(1)
        txt = open(arg, encoding='utf-8', errors='ignore').read()
        rel = os.path.relpath(os.path.abspath(arg), os.path.abspath(os.path.join(SRC, '..')))
        third = ('Scintilla', 'jsoncpp', 'yaml-cpp', 'spdlog', 'fmt', 'dtl', 'libssh', 'Onigmo')
        if any(x in rel.split('/')[1:2] for x in third):
            kind, why = 'C 第三方库', '路径在第三方库目录下(不逆向、不改)'
        elif '/Ext/' in '/' + rel:
            kind, why = 'D 外部库接口面', 'Ext/:只声明调用面,实现委托真库'
        elif '/Stubs/' in '/' + rel:
            kind, why = 'E 生成桩', 'Stubs/:gen_stubs 生成的 cited 空实现,转写后删除该行'
        elif '[B-OPENSOURCE]' in txt or rel in open_source():
            kind, why = 'B 第一方开源', '带 [B-OPENSOURCE] 标记 / 在 open_source_files.txt'
        else:
            n_fun = len(re.findall(r'(?<!PTR_)FUN_[0-9a-f]{8}', txt))
            n_bare = len([a for a in re.findall(r'(?<![\w.])(00[0-9a-f]{6})(?![\w])', txt)
                          if 0x4c33c0 <= int(a, 16) < 0xc89000])
            n_sym = len(re.findall(r'\bs_[A-Za-z0-9_]+_[0-9a-f]{6}\b', txt))
            prose = re.search(r'语料|反编译|Reconstructed from WindTerm|QMetaObject|出处', txt)
            if n_fun or n_bare or n_sym or 'cited' in txt or prose:
                kind = 'A 已逆向'
                why = '出处 FUN_×%d / 裸地址×%d / s_符号×%d / cited=%s%s' % (
                    n_fun, n_bare, n_sym, '有' if 'cited' in txt else '无',
                    ' / 说明型出处(%s)' % prose.group(0) if prose and not (n_fun or n_bare or n_sym) else '')
            else:
                kind, why = '?) 未分类', '无任何出处 —— coverage.py --audit 会报'
        qobj = 'Q_OBJECT' if 'Q_OBJECT' in txt else '—'
        bases = re.findall(r'^\s*class\s+\w+\s*:\s*(?:public|private|protected)\s+([\w:]+)',
                           txt, re.M)
        qfwd = len(set(re.findall(r'^class\s+(Q\w+);', txt, re.M)))
        print('文件   :', rel)
        print('类别   :', kind)
        print('依据   :', why)
        print('Q_OBJECT:', qobj, ' 基类:', ', '.join(bases) or '—')
        if qfwd:
            print('Qt 接口: 本文件有 %d 个 Qt 前置声明(Q* 类不属本仓,不逆向)' % qfwd)
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

        L, tsv, (cnt, byt, tot, totb) = work_ledger(addr2files)
        with open(os.path.join(os.path.dirname(__file__), '..', '..', 'docs', 'meta',
                               'work-ledger.md'), 'w', encoding='utf-8') as fh:
            fh.write('\n'.join(L) + '\n')
        with open(os.path.join(DATA, 'work_ledger.tsv'), 'w', encoding='utf-8') as fh:
            fh.write('\n'.join(tsv) + '\n')
        print('已生成 docs/meta/work-ledger.md 与 data/work_ledger.tsv'
              '（真实现 %d / 半成品 %d / 引用档 %d / 未触及 %d）'
              % (cnt['real'], cnt['stub'], cnt['ref'], cnt['todo']))
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
