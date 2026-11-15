#!/usr/bin/env python3
# 批 180 — 原版 blobB LastSessions 组块(样本 110..417)框架解析:
# 外框字节序 = [int][BA 根 ss][char kind][BA title],byte-perfect 收敛
# 到 417;title 内层 = [int][int]{BA uuid + BA state}×2 + 15B 尾标 ×2
# (写体 = s_RenamedTitle_8bbab6 850B cited — 内层语义不发明)。
import struct, sys
d = open(sys.argv[1] if len(sys.argv)>1 else
         '/home/pana/.local/share/opencode/worktree/b79a6f/batch180-fullframe/tools/re/phase5/5c/original/kitframe-blobB-417B.bin','rb').read()
def rdba(d,o):
    n,=struct.unpack_from('>i',d,o); o+=4
    if n<0: return None,o
    return d[o:o+n],o+n
o=110
cnt,=struct.unpack_from('>i',d,o); o+=4
ss,o=rdba(d,o)
kind=d[o]; o+=1
title,o=rdba(d,o)
print("count(int)=",cnt,"root ss len=",len(ss),"kind(char)=",kind,"title BA len=",len(title))
print("outer consumed",o,"of",len(d),"→ byte-perfect:",o==len(d))
t=0
i1,=struct.unpack_from('>i',title,t); t+=4
i2,=struct.unpack_from('>i',title,t); t+=4
print("title ints:",i1,i2)
for i in range(i2):
    u,t=rdba(title,t); s,t=rdba(title,t)
    print(f"  page{i}: uuid {u.decode('utf-16-be')} state {len(s)}B")
    tag=title[t:t+15]; t+=15
    print(f"         tag15: {tag.hex()}")
print("title consumed",t,"of",len(title),"→",t==len(title))
