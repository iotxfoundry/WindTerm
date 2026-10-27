#!/usr/bin/env python3
"""Generate cited-stub definitions for declared-but-undefined symbols.

Pass 1: linker mangled names give the exact class/method/param types.
Pass 2: header declarations give the return types (mangled names don't
encode them). Emits stubs_gen.cpp; transcription removes its lines.

Usage: gen_stubs.py <lib.so> <out.cpp> <headers...>
"""
import re
import subprocess
import sys

lib, out = sys.argv[1], sys.argv[2]
headers = sys.argv[3:]
CLASSES = ('TerminalCore', 'Screen', 'TextView', 'EditorEngine',
           'SuperCommander', 'SuperSession', 'SuperBridge',
           'PopupWidget', 'ScrollBar', 'Splitter', 'TelnetProtocol',
           'TelnetCommander', 'TelnetSession',
           'SerialSession', 'SerialCommander', 'SerialBridge',
           'ShellSession', 'ShellCommander', 'ShellBridge',
           'SshSession', 'SshCommander', 'SshBridge',
           'TcpSession', 'TcpCommander', 'TcpBridge')

def norm_params(p):
    # normalize a param list to comparable tokens
    toks = []
    for part in p.split(','):
        part = re.sub(r'\b\w+\s*=\s*[^,()]+', '', part)  # defaults
        part = re.sub(r'\b(const\s+)?([A-Za-z_][\w:<>,\s]*?)\s*(?:&|\*)?\s*\w*\s*$',
                      lambda m: (m.group(1) or '') + m.group(2).strip(), part.strip())
        toks.append(re.sub(r'\s+', ' ', part.replace('const', 'const ')))
    return [t for t in toks if t]

# pass 2: header decl map (class -> name -> candidate (ret, params))
decls = {}
for h in headers:
    cls = None
    for line in open(h, encoding='utf-8', errors='replace'):
        m = re.match(r'class\s+(\w+)', line)
        if m:
            cls = m.group(1) if m.group(1) in CLASSES else cls
            continue
        if cls is None:
            continue
        d = re.match(r'\t(.+?)\b(~?\w+)\s*\(([^)]*)\)\s*(?:const)?\s*(?:override)?\s*;', line)
        if not d:
            continue
        ret, name, params = d.group(1).strip(), d.group(2), d.group(3)
        ret = re.sub(r'(?:static|virtual|explicit|inline|Q_SLOTS|signals?)\s+', '', ret).strip()
        decls.setdefault(cls, {}).setdefault(name, []).append((ret, params))

raw = subprocess.run(['nm', '-D', '--undefined-only', lib],
                     capture_output=True, text=True).stdout.splitlines()
mangled = sorted({l.split()[-1] for l in raw if l.strip()})

RET_DEFAULT = {'QVariant': 'QVariant()', 'QString': 'QString()',
               'QByteArray': 'QByteArray()', 'QUuid': 'QUuid()',
               'bool': 'false', 'int': '0', 'uint': '0u',
               'long long': '0', 'double': '0.0', 'float': '0.0f'}

lines = ['// 自动生成 cited-stub(链接器 mangled 名 + 头文件返回类型)',
         '// 转写真身时删除对应行。生成器:tools/re/gen_stubs.py', '',
         '#include "SuperSession.h"',
         '#include "SuperBridge.h"',
         '#include "TerminalCore.h"',
         '#include "Screen.h"',
         '#include "TextView.h"',
         '#include "TelnetCommander.h"', '']
seen, unmatched = set(), []
for m in mangled:
    d = subprocess.run(['c++filt', m], capture_output=True, text=True).stdout.strip()
    mm = re.match(r'^(?:([\w:<>, ]+?)\s)?(?:.*?)((?:%s)::)(~?\w+)\((.*)\)( const)?$'
                  % '|'.join(CLASSES), d)
    if not mm:
        continue
    rtype, prefix, name, params, const = (mm.group(1) or 'void'), mm.group(2), mm.group(3), mm.group(4), mm.group(5) or ''
    key = d
    if key in seen:
        continue
    seen.add(key)
    cls = prefix.rstrip(':')
    # return type from the header when the mangled name didn't carry one
    if rtype == 'void':
        for ret, hp in decls.get(cls, {}).get(name, []):
            if len(norm_params(hp)) == len(norm_params(params)):
                rtype = ret or 'void'
                break
    if name.startswith('~') or name == cls.split('::')[-1]:
        lines.append(f'{prefix}{name}({params}) {{}}   // ctor/dtor stub')
        continue
    ret_expr = RET_DEFAULT.get(rtype)
    if rtype.endswith('*'):
        ret_expr = 'nullptr'
    elif ret_expr is None:
        ret_expr = f'{rtype}{{}}' if rtype and rtype != 'void' else ''
    body = f'return {ret_expr};' if rtype != 'void' else ''
    lines.append(f'{rtype} {prefix}{name}({params}){const} {{ {body} }} // stub')

open(out, 'w', encoding='utf-8').write('\n'.join(lines) + '\n')
print(f'{len(seen)} stubs -> {out}')
