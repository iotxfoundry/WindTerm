# 引擎命令 ↔ Scintilla 真名对照(inc/scintilla 源码头直读)

392 个 case 中 120 个命中上游 SCI_* 真名;其余 147 为
WindTerm 扩展(EXT 20163-20228 / WT 30001-30166)自有命名空间。

| cmd | dec | Scintilla 真名 | 库内注释 |
|---|---|---|---|
| 0x7d6 | 2006 | **SCI_GETLENGTH** | SCI 2006: shared tail (LAB_00a45135) = document length |
| 0x7dc | 2012 | **SCI_SETUNDOCOLLECTION** | doc bool op, returns 0 |
| 0x7dd | 2013 | **SCI_SELECTALL** | FUN_00a26df4 (177B): SELECT ALL via the range |
| 0x7e5 | 2021 | **SCI_SETVIEWWS** | change-detect write + vtable+0xa0 repaint |
| 0x7e6 | 2022 | **SCI_POSITIONFROMPOINT** | position from point (x,y doubles), nearest mode 0 |
| 0x7e7 | 2023 | **SCI_POSITIONFROMPOINTCLOSE** | same, mode 1 |
| 0x7f8 | 2040 | **SCI_MARKERDEFINE** | packed int table: 32 slots, 11-byte stride at this+8 |
| 0x7fb | 2043 | **SCI_MARKERADD** | FUN_0092a2b2 (155B): GapBuffer_insertChar on |
| 0x7fc | 2044 | **SCI_MARKERDELETE** | SCI 2044: FUN_0092a356, args toInt, toLongLong |
| 0x7fd | 2045 | **SCI_MARKERDELETEALL** | FUN_00925c8c (168B): clears the selection run-list |
| 0x800 | 2048 | **SCI_MARKERPREVIOUS** | backward scan: first position <= a whose style hits mask b |
| 0x801 | 2049 | **SCI_MARKERDEFINEPIXMAP** | packed style table, u64 value variant of 0x7f8 |
| 0x833 | 2099 | **SCI_STYLESETCHANGEABLE** | SCI_AUTOCACTIVE family — bool via (engine,0,0) |
| 0x834 | 2100 | **SCI_AUTOCSHOW** | reset style +0x1238 then apply |
| 0x835 | 2101 | **SCI_AUTOCCANCEL** | SCI_AUTOCCANCEL (repo-verified) |
| 0x836 | 2102 | **SCI_AUTOCACTIVE** | bool state probe |
| 0x837 | 2103 | **SCI_AUTOCPOSSTART** | SCI_AUTOCPOSSTART (repo-verified) |
| 0x83c | 2108 | **SCI_AUTOCSELECT** | style pair write +0x123c |
| 0x83e | 2110 | **SCI_AUTOCSETCANCELATSTART** | +0x1240 target: optional object call w/ int arg |
| 0x840 | 2112 | **SCI_AUTOCSETFILLUPS** | style write +0x1238 |
| 0x84f | 2127 | **SCI_GETLINEINDENTATION** | gated by +0x1067 (byte at engine) |
| 0x851 | 2129 | **SCI_GETCOLUMN** | +0x1128 gate: plain vs column-modulo conversion |
| 0x858 | 2136 | **SCI_GETLINEENDPOSITION** | line end: dual path by the same gate |
| 0x863 | 2147 | **SCI_GETPRINTMAGNIFICATION** | inferred id: the <0x864 sibling read of the pair |
| 0x865 | 2149 | **SCI_GETPRINTCOLOURMODE** | read sibling of the 0x864 write: +0xea8 |
| 0x867 | 2151 | **SCI_FORMATRANGE** | SCI 2151: FUN_00a223e8, args toBool, toULongLong |
| 0x869 | 2153 | **SCI_GETLINE** | getLine text: pos -1 -> cursor line, slice line..line+1 |
| 0x86a | 2154 | **SCI_GETLINECOUNT** | SCI 2154: FUN_00925570 + editor_textLength + soft reset |
| 0x86b | 2155 | **SCI_SETMARGINLEFT** | change-detect +0xd4c write then soft reset |
| 0x86f | 2159 | **SCI_GETMODIFY** | FUN_00927a58(doc, 0) != 0 |
| 0x870 | 2160 | **SCI_SETSEL** | setSelection(anchor, caret): negative defaults |
| 0x873 | 2163 | **SCI_HIDESELECTION** | change-detect bool + repaint |
| 0x874 | 2164 | **SCI_POINTXFROMPOSITION** | X coordinate of a position: scroll double minus |
| 0x875 | 2165 | **SCI_POINTYFROMPOSITION** | scroll set (pos >= 0), XMM double return |
| 0x877 | 2167 | **SCI_POSITIONFROMLINE** | line start: FUN_00925200(doc, line) + FUN_00958498 |
| 0x879 | 2169 | **SCI_SCROLLCARET** | SCI 2169: FUN_00a2913a, args no args |
| 0x87a | 2170 | **SCI_REPLACESEL** | SCI 2170: FUN_00a25808, args toULongLong, toInt |
| 0x87b | 2171 | **SCI_SETREADONLY** | SCI 2171: +0x132 flag write (FUN_009290f0) |
| 0x87d | 2173 | **SCI_CANPASTE** | engine vtable +0x110 -> bool |
| 0x87e | 2174 | **SCI_CANUNDO** | FUN_00927a40 + FUN_009290e8 flag pair |
| 0x880 | 2176 | **SCI_UNDO** | SCI 2176: FUN_00a23b58, args toInt |
| 0x882 | 2178 | **SCI_COPY** | engine vtable +0x108 |
| 0x883 | 2179 | **SCI_PASTE** | SCI_COPY: vtable +0x118 then mode guard tail |
| 0x885 | 2181 | **SCI_SETTEXT** | select-all style make (mode str @0xcb99b6) |
| 0x887 | 2183 | **SCI_GETTEXTLENGTH** | SCI 2183: same shared tail — FUN_0092801a |
| 0x898 | 2200 | **SCI_CALLTIPSHOW** | run-style range (wparam=range start ll, lparam=ull) |
| 0x89c | 2204 | **SCI_CALLTIPSETHLT** | two-int op on +0x1148 (wparam from b, lparam from a) |
| 0x8a4 | 2212 | **SCI_CALLTIPUSESTYLE** | +0x1148 then soft view reset |
| 0x8a5 | 2213 | **SCI_CALLTIPSETPOSITION** | +0x1148 then soft view reset (bool arg) |
| 0x8e2 | 2274 | **SCI_SETSCROLLWIDTH** | on success clears bit0 of the object's +0x50 flags |
| 0x8e3 | 2275 | **SCI_GETSCROLLWIDTH** | inferred: +0x10c8 object's +0x40 read |
| 0x8e4 | 2276 | **SCI_TEXTWIDTH** | SCI 2276: FUN_00a3028e, args toULongLong |
| 0x8ea | 2282 | **SCI_APPENDTEXT** | insert at document end (-1 anchor) |
| 0x914 | 2324 | **SCI_EDITTOGGLEOVERTYPE** | ranges 0x914-0x91a, 0x91d-0x91f, 0x924-0x928 forward |
| 0x92e | 2350 | **SCI_LINELENGTH** | char width: pos+1 offset minus pos offset |
| 0x933 | 2355 | **SCI_GETVIEWEOL** | read +0xd8c |
| 0x934 | 2356 | **SCI_SETVIEWEOL** | write +0xd8c, change-detect + vtable+0xa0 repaint |
| 0x936 | 2358 | **SCI_SETDOCPOINTER** | margin number/timestamp width recalc (vt+0x148 guard) |
| 0x945 | 2373 | **SCI_SETZOOM** | zoom set: FUN_009502a0(engine+8, n); margins recalc + |
| 0x946 | 2374 | **SCI_GETZOOM** | SCI 2374: FUN_00950294, args toInt |
| 0x94c | 2380 | **SCI_SETFOCUS** | SCI 2380: FUN_00a2d544, args toBool |
| 0x950 | 2384 | **SCI_SETMOUSEDOWNCAPTURES** | write +0xec4 |
| 0x951 | 2385 | **SCI_GETMOUSEDOWNCAPTURES** | read +0xec4 |
| 0x952 | 2386 | **SCI_SETCURSOR** | write +0xed8 + vtable+0x160(1) |
| 0x953 | 2387 | **SCI_GETCURSOR** | read +0xed8 |
| 0x961 | 2401 | **SCI_MOVECARETINSIDEVIEW** | EXT 2401: FUN_00a233b8, args no args |
| 0x966 | 2406 | **SCI_SETPRINTWRAPMODE** | write +0xeac |
| 0x967 | 2407 | **SCI_GETPRINTWRAPMODE** | read +0xeac |
| 0x971 | 2417 | **SCI_POSITIONBEFORE** | EXT 2417: FUN_009252f4, args toLongLong |
| 0x972 | 2418 | **SCI_POSITIONAFTER** | EXT 2418: FUN_009252f4, args toLongLong |
| 0x973 | 2419 | **SCI_COPYRANGE** | EXT 2419: FUN_00a2c5c8, args toLongLong |
| 0x974 | 2420 | **SCI_COPYTEXT** | EXT 2420: FUN_00a2fdc6, args toInt, toULongLong |
| 0x975 | 2421 | **SCI_SETHOTSPOTSINGLELINE** | EXT 2421: session_view_soft_reset, args toBool |
| 0x998 | 2456 | **SCI_FINDCOLUMN** | EXT 2456: FUN_009286d4, args toLongLong |
| 0x9a2 | 2466 | **SCI_MARKERADDSET** | doc + toLL(a), toInt(b) -> FUN_0092a49e |
| 0x9a3 | 2467 | **SCI_SETPASTECONVERTENDINGS** | write +0x1058 low byte |
| 0x9a4 | 2468 | **SCI_GETPASTECONVERTENDINGS** | read +0x1058 |
| 0x9a5 | 2469 | **SCI_SELECTIONDUPLICATE** | editor_duplicateLines(engine, 0) |
| 0x9c1 | 2497 | **SCI_GETHOTSPOTSINGLELINE** | read +0xd48 |
| 0x9d4 | 2516 | **SCI_SETSCROLLWIDTHTRACKING** | +0x10c8 obj +0x57 bit5 set |
| 0x9d5 | 2517 | **SCI_GETSCROLLWIDTHTRACKING** | +0x10c8 obj +0x57 bit5 read |
| 0x9e1 | 2529 | **SCI_MARKERSYMBOLDEFINED** | packed style table READ (32 slots, 11B stride) |
| 0x9e2 | 2530 | **SCI_MARGINSETTEXT** | doc + toLL(a), toULL(b) -> FUN_00925d4c |
| 0x9e3 | 2531 | **SCI_MARGINGETTEXT** | std::string return (s_text_default_92565a) |
| 0x9e4 | 2532 | **SCI_MARGINSETSTYLE** | doc + toLL(a), toInt(b) -> FUN_00925e2a |
| 0x9e5 | 2533 | **SCI_MARGINGETSTYLE** | std::string return (s_text_default sibling) |
| 0x9e8 | 2536 | **SCI_MARGINTEXTCLEARALL** | doc -> FUN_00925df0 |
| 0x9fc | 2556 | **SCI_SETEMPTYSELECTION** | select-to-position: runnode(pos) -> FUN_00a21110(e,node,0) |
| 0xa01 | 2561 | **SCI_CHARPOSITIONFROMPOINT** | position from point, mode (0,1,1) |
| 0xa02 | 2562 | **SCI_CHARPOSITIONFROMPOINTCLOSE** | position from point, mode (1,1,1) |
| 0xa0a | 2570 | **SCI_GETSELECTIONS** | EXT 2570: FUN_00a1fc2e, args no args |
| 0xa0c | 2572 | **SCI_SETSELECTION** | setSelection(anchor a, caret b): dual runnode |
| 0xa0e | 2574 | **SCI_SETMAINSELECTION** | FUN_00a2373a(engine, int) |
| 0xa10 | 2576 | **SCI_SETSELECTIONNCARET** | insert text at position (len from flags buf) |
| 0xa11 | 2577 | **SCI_GETSELECTIONNCARET** | target text value |
| 0xa12 | 2578 | **SCI_SETSELECTIONNANCHOR** | set search text at position (len from buf) |
| 0xa13 | 2579 | **SCI_GETSELECTIONNANCHOR** | search-range text value |
| 0xa15 | 2581 | **SCI_GETSELECTIONNCARETVIRTUALSPACE** | target text length |
| 0xa17 | 2583 | **SCI_GETSELECTIONNANCHORVIRTUALSPACE** | search-range text length |
| 0xa18 | 2584 | **SCI_SETSELECTIONNSTART** | set range text at position (FUN_00a1ff9c family) |
| 0xa19 | 2585 | **SCI_GETSELECTIONNSTART** | range text value (FUN_00a1ff9c read) |
| 0xa1a | 2586 | **SCI_SETSELECTIONNEND** | set range text at position (FUN_00a20050 family) |
| 0xa1e | 2590 | **SCI_SETRECTANGULARSELECTIONANCHOR** | target+position variant (FUN_00a20050 -> runnode) |
| 0xa1f | 2591 | **SCI_GETRECTANGULARSELECTIONANCHOR** | range text length (FUN_00a20050) |
| 0xa20 | 2592 | **SCI_SETRECTANGULARSELECTIONCARETVIRTUALSPACE** | EXT 2592: FUN_00a1ff24, args toInt |
| 0xa21 | 2593 | **SCI_GETRECTANGULARSELECTIONCARETVIRTUALSPACE** | EXT 2593: FUN_00a1ff0e, args toInt |
| 0xa24 | 2596 | **SCI_SETVIRTUALSPACEOPTIONS** | EXT 2596: FUN_00a203ca, args toBool |
| 0xa25 | 2597 | **SCI_GETVIRTUALSPACEOPTIONS** | EXT 2597: FUN_00a203be, args no args |
| 0xa3e | 2622 | **SCI_SETIDENTIFIER** | EXT 2622: member write +0x21b (unmapped) |
| 0xa3f | 2623 | **SCI_GETIDENTIFIER** | EXT 2623: vtable+0x138 with a default guard — when |
| 0xa40 | 2624 | **SCI_RGBAIMAGESETWIDTH** | EXT 2624: member write +0x1d2 (unmapped) |
| 0xa41 | 2625 | **SCI_RGBAIMAGESETHEIGHT** | EXT 2625: member write +0x1d3 (unmapped) |
| 0xa42 | 2626 | **SCI_MARKERDEFINERGBAIMAGE** | EXT 2626: packed style write with a FLOAT scale — |
| 0xa47 | 2631 | **SCI_GETTECHNOLOGY** | EXT 2631: reads +0xe88 ([0x1d1]) |
| 0xa49 | 2633 | **SCI_COUNTCHARACTERS** | EXT 2633: FUN_00925352, args toLongLong |
| 0xa55 | 2645 | **SCI_DELETERANGE** | EXT 2645: FUN_0092c1ba, args toLongLong |
| 0xa5a | 2650 | **SCI_GETSELECTIONEMPTY** | EXT 2650: FUN_00a20248, args no args |
| 0xa5b | 2651 | **SCI_RGBAIMAGESETSCALE** | EXT 2651: member write +0x1d4 (unmapped) |
| 0xbb9 | 3001 | **SCI_STARTRECORD** | EXT 3001: member write +0x208 (unmapped) |
| 0xbba | 3002 | **SCI_STOPRECORD** | EXT 3002: member write +0x208 (unmapped) |
