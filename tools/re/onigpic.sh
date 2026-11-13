#!/usr/bin/env bash
# 批 116:onig PIC 化替身(strip-debug;lib/libonig.a 非 PIC debug 域勘定)。
# 用法:onigpic.sh <outdir> <ar> <objcopy> <libonig.a>
set -e
out="$1"; ar="$2"; objcopy="$3"; srclib="$4"
rm -rf "$out/obj"; mkdir -p "$out/obj"
cd "$out/obj"
"$ar" x "$srclib"
for o in *.o; do "$objcopy" --strip-debug "$o"; done
"$ar" rcs "$out/libonigpic.a" *.o
