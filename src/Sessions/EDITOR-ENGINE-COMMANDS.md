# 编辑器引擎主分派器命令表(FUN_00a418c4,37,951B)

两级分派第二级(第一级 0xa5205e SCI 快速段,见 TEXTVIEW-IMPL.md)。
由 tools/re/gen_editor_cmds.py 从反编译语料机械提取:336 个 `==` 叶
(全部比较点),实现/动作列 = 叶内前 4 个调用 + 引擎虚表槽,成员列 =
直接写入的引擎偏移。TextView 方法列为 TEXTVIEW-COMMANDS.md 交叉。

| cmd | dec | 段 | TextView 方法 | 实现/动作 | 成员写入 |
|---|---|---|---|---|---|
| 0x7d1 | 2001 | SCI | QVariant::toULongLong QVariant::toLongLong FUN_00a28a68 | - |
| 0x7d4 | 2004 | SCI | FUN_00a26756 QVariant::QVariant | - |
| 0x7d6 | 2006 | SCI | inline | - |
| 0x7da | 2010 | SCI | QVariant::toLongLong FUN_0092801a FUN_00926c8c QVariant::QVariant | - |
| 0x7db | 2011 | SCI | QVariant::toInt FUN_00a23b8c | - |
| 0x7dc | 2012 | SCI | QVariant::toBool FUN_00927a30 QVariant::QVariant | - |
| 0x7dd | 2013 | SCI | selectAll | FUN_00a26df4 | - |
| 0x7de | 2014 | SCI | FUN_00927ddc | - |
| 0x7e0 | 2016 | SCI | FUN_00927a4c FUN_009290e8 QVariant::QVariant | - |
| 0x7e4 | 2020 | SCI | QVariant::QVariant | - |
| 0x7e5 | 2021 | SCI | QVariant::toInt vt+0xa0 | +0x1b0 |
| 0x7e6 | 2022 | SCI | QVariant::toDouble FUN_0095019c FUN_0096bbc0 QVariant::QVariant | - |
| 0x7e7 | 2023 | SCI | QVariant::toDouble FUN_0095019c FUN_0096bbc0 QVariant::QVariant | - |
| 0x7ec | 2028 | SCI | FUN_0092814a QVariant::QVariant | - |
| 0x7f2 | 2034 | SCI | QVariant::QVariant | - |
| 0x7f3 | 2035 | SCI | QVariant::toBool | - |
| 0x7f8 | 2040 | SCI | QVariant::toUInt QVariant::toInt FUN_009501b0 FUN_00a1f7be | - |
| 0x7fb | 2043 | SCI | QVariant::toInt FUN_0092a2b2 QVariant::QVariant | - |
| 0x7fc | 2044 | SCI | QVariant::toInt QVariant::toLongLong FUN_0092a356 | - |
| 0x7fd | 2045 | SCI | QVariant::toInt FUN_00925c8c | - |
| 0x7ff | 2047 | SCI | QVariant::toInt QVariant::toLongLong FUN_009251ea QVariant::QVariant | - |
| 0x801 | 2049 | SCI | QVariant::toUInt QVariant::toULongLong FUN_00a4e234 FUN_009501b0 | - |
| 0x81e | 2078 | SCI | QVariant::toULongLong FUN_00927a08 | - |
| 0x81f | 2079 | SCI | FUN_00927a14 | - |
| 0x84e | 2126 | SCI | QVariant::toInt QVariant::toLongLong FUN_0092c4ae | - |
| 0x850 | 2128 | SCI | QVariant::toLongLong FUN_00928404 QVariant::QVariant | - |
| 0x851 | 2129 | SCI | QVariant::toLongLong FUN_00928624 QVariant::QVariant | +0x225 |
| 0x857 | 2135 | SCI | QVariant::QVariant | - |
| 0x858 | 2136 | SCI | QVariant::toLongLong FUN_0092520c QVariant::QVariant | +0x225 |
| 0x85c | 2140 | SCI | FUN_009290e8 QVariant::QVariant | - |
| 0x862 | 2146 | SCI | QVariant::toInt | - |
| 0x864 | 2148 | SCI | QVariant::toInt | +0x1d5 |
| 0x865 | 2149 | SCI | QVariant::QVariant | - |
| 0x867 | 2151 | SCI | QVariant::toBool QVariant::toULongLong FUN_00a223e8 QVariant::QVariant | - |
| 0x869 | 2153 | SCI | QVariant::toLongLong FUN_00975bc6 FUN_0096bbc0 FUN_0092522a | - |
| 0x86a | 2154 | SCI | FUN_00925570 QVariant::QVariant | +0x225 |
| 0x86b | 2155 | SCI | QVariant::toInt session_view_soft_reset | - |
| 0x86f | 2159 | SCI | FUN_00927a58 QVariant::QVariant | - |
| 0x870 | 2160 | SCI | QVariant::toLongLong FUN_0092801a runstyles_runnode_init FUN_00a20eb2 | - |
| 0x873 | 2163 | SCI | QVariant::toBool vt+0xa0 | - |
| 0x874 | 2164 | SCI | QVariant::toLongLong runstyles_runnode_init FUN_00a225be FUN_0096bb02 | - |
| 0x876 | 2166 | SCI | QVariant::toLongLong runstyles_runnode_init FUN_009587cc QVariant::QVariant | - |
| 0x877 | 2167 | SCI | QVariant::toLongLong FUN_00925200 FUN_00958498 QVariant::QVariant | +0x225 |
| 0x879 | 2169 | SCI | FUN_00a2913a | - |
| 0x87a | 2170 | SCI | QVariant::toULongLong QVariant::toInt FUN_00a25808 | - |
| 0x87b | 2171 | SCI | QVariant::toBool FUN_009290f0 | - |
| 0x87d | 2173 | SCI | QVariant::QVariant vt+0x110 | - |
| 0x87e | 2174 | SCI | FUN_00927a40 FUN_009290e8 QVariant::QVariant | - |
| 0x87f | 2175 | SCI | FUN_00927dbe | - |
| 0x880 | 2176 | SCI | QVariant::toInt FUN_00a23b58 | - |
| 0x881 | 2177 | SCI | FUN_00a25f72 | - |
| 0x882 | 2178 | SCI | copy | vt+0x108 | - |
| 0x883 | 2179 | SCI | paste | FUN_00a235ce vt+0x118 | - |
| 0x885 | 2181 | SCI | runstyles_runnode_init FUN_00a21110 FUN_0096bb02 QVariant::toULongLong | - |
| 0x887 | 2183 | SCI | inline | - |
| 0x8b2 | 2226 | SCI | QVariant::toLongLong FUN_00958416 FUN_00a239ee vt+0xa0 | - |
| 0x8b3 | 2227 | SCI | QVariant::toLongLong FUN_00958416 FUN_00a239ee vt+0xa0 | - |
| 0x8b4 | 2228 | SCI | QVariant::toLongLong FUN_0095855e QVariant::QVariant | - |
| 0x8b6 | 2230 | SCI | QVariant::toLongLong FUN_00958b68 QVariant::QVariant | - |
| 0x8b7 | 2231 | SCI | QVariant::toLongLong FUN_00975bc6 FUN_009587cc QVariant::toInt | - |
| 0x8bc | 2236 | SCI | FUN_0095854c QVariant::QVariant | - |
| 0x8d8 | 2264 | SCI | QVariant::toInt | - |
| 0x8d9 | 2265 | SCI | QVariant::QVariant | - |
| 0x8da | 2266 | SCI | QVariant::toBool QVariant::toLongLong FUN_00a282a8 QVariant::QVariant | - |
| 0x8db | 2267 | SCI | QVariant::toBool QVariant::toLongLong FUN_00a282a8 QVariant::QVariant | - |
| 0x8e2 | 2274 | SCI | QVariant::toLongLong FUN_00a169cc | - |
| 0x8e4 | 2276 | SCI | QVariant::toULongLong FUN_00a3028e QVariant::QVariant | - |
| 0x8ea | 2282 | SCI | QVariant::toULongLong QVariant::toLongLong FUN_00a287f8 | - |
| 0x8f0 | 2288 | SCI | QVariant::toLongLong FUN_00a218f6 | - |
| 0x8f1 | 2289 | SCI | QVariant::toULongLong QVariant::toInt FUN_00a21d26 | - |
| 0x92e | 2350 | SCI | QVariant::toLongLong FUN_00958498 QVariant::QVariant | - |
| 0x933 | 2355 | SCI | QVariant::QVariant | - |
| 0x934 | 2356 | SCI | setEolVisible | QVariant::toBool vt+0xa0 | - |
| 0x936 | 2358 | SCI | QVariant::toULongLong FUN_00a2c222 s_margin_number_a302fe s_margin_timestamp_a30e02 vt+0x148 | - |
| 0x945 | 2373 | SCI | setZoomFactor | QVariant::toInt FUN_009502a0 FUN_00a23c7a s_margin_number_a302fe | - |
| 0x946 | 2374 | SCI | FUN_00950294 QVariant::QVariant | - |
| 0x94c | 2380 | SCI | QVariant::toBool FUN_00a2d544 | - |
| 0x950 | 2384 | SCI | QVariant::toBool | - |
| 0x951 | 2385 | SCI | QVariant::QVariant | - |
| 0x952 | 2386 | SCI | QVariant::toInt vt+0x160 | +0x1d6 |
| 0x953 | 2387 | SCI | QVariant::QVariant | - |
| 0x961 | 2401 | ? | FUN_00a233b8 | - |
| 0x966 | 2406 | ? | QVariant::toInt | - |
| 0x967 | 2407 | ? | QVariant::QVariant | - |
| 0x971 | 2417 | ? | QVariant::toLongLong FUN_009252f4 QVariant::QVariant | - |
| 0x972 | 2418 | ? | QVariant::toLongLong FUN_009252f4 QVariant::QVariant | - |
| 0x973 | 2419 | ? | QVariant::toLongLong FUN_00a2c5c8 | - |
| 0x974 | 2420 | ? | QVariant::toInt QVariant::toULongLong FUN_00a2fdc6 | - |
| 0x975 | 2421 | ? | QVariant::toBool session_view_soft_reset | - |
| 0x998 | 2456 | ? | QVariant::toLongLong FUN_009286d4 QVariant::QVariant | +0x225 |
| 0x9a2 | 2466 | ? | QVariant::toInt QVariant::toLongLong FUN_0092a49e | - |
| 0x9a3 | 2467 | ? | QVariant::toBool | - |
| 0x9a4 | 2468 | ? | QVariant::QVariant | - |
| 0x9a5 | 2469 | ? | inline | - |
| 0x9c1 | 2497 | ? | QVariant::QVariant | - |
| 0x9d4 | 2516 | ? | QVariant::toBool | - |
| 0x9d5 | 2517 | ? | QVariant::QVariant | - |
| 0x9e1 | 2529 | ? | QVariant::toUInt QVariant::QVariant | - |
| 0x9e2 | 2530 | ? | QVariant::toULongLong QVariant::toLongLong FUN_00925d4c | - |
| 0x9e3 | 2531 | ? | QVariant::toLongLong s_text_default_92565a FUN_00a4b6df QVariant::QVariant | - |
| 0x9e4 | 2532 | ? | QVariant::toInt QVariant::toLongLong FUN_00925e2a | - |
| 0x9e5 | 2533 | ? | QVariant::toLongLong s_text_default_92565a FUN_00a4b6df QVariant::QVariant | - |
| 0x9e8 | 2536 | ? | FUN_00925df0 | - |
| 0x9fc | 2556 | ? | QVariant::toLongLong runstyles_runnode_init FUN_00a21110 FUN_0096bb02 | - |
| 0xa01 | 2561 | ? | QVariant::toDouble FUN_0095019c FUN_0096bbc0 QVariant::QVariant | - |
| 0xa02 | 2562 | ? | QVariant::toDouble FUN_0095019c FUN_0096bbc0 QVariant::QVariant | - |
| 0xa0a | 2570 | ? | FUN_00a1fc2e QVariant::QVariant | - |
| 0xa0c | 2572 | ? | setSelection | QVariant::toLongLong runstyles_runnode_init FUN_0096be24 FUN_00a20fb0 | - |
| 0xa0e | 2574 | ? | QVariant::toInt FUN_00a2373a | - |
| 0xa10 | 2576 | ? | QVariant::canConvert QVariant::toInt QVariant::toLongLong FUN_00a1fda6 | - |
| 0xa11 | 2577 | ? | QVariant::canConvert QVariant::toInt FUN_00a1fda6 FUN_0096bbc0 | - |
| 0xa12 | 2578 | ? | QVariant::canConvert QVariant::toInt QVariant::toLongLong FUN_00a1fe5a | - |
| 0xa13 | 2579 | ? | QVariant::canConvert QVariant::toInt FUN_00a1fe5a FUN_0096bbc0 | - |
| 0xa15 | 2581 | ? | QVariant::canConvert QVariant::toInt FUN_00a1fda6 QVariant::QVariant | - |
| 0xa17 | 2583 | ? | QVariant::canConvert QVariant::toInt FUN_00a1fe5a QVariant::QVariant | - |
| 0xa18 | 2584 | ? | QVariant::canConvert QVariant::toInt QVariant::toLongLong FUN_00a1ff9c | - |
| 0xa19 | 2585 | ? | QVariant::canConvert QVariant::toInt FUN_00a1ff9c FUN_0096bbc0 | - |
| 0xa1a | 2586 | ? | QVariant::canConvert QVariant::toInt QVariant::toLongLong FUN_00a20050 | - |
| 0xa1e | 2590 | ? | QVariant::canConvert QVariant::toInt FUN_00a20050 FUN_0096bbc0 | - |
| 0xa1f | 2591 | ? | QVariant::canConvert QVariant::toInt FUN_00a20050 QVariant::QVariant | - |
| 0xa20 | 2592 | ? | setSelectionType | QVariant::toInt QVariant::canConvert FUN_00a1ff24 | - |
| 0xa21 | 2593 | ? | QVariant::canConvert QVariant::toInt FUN_00a1ff0e QVariant::QVariant | - |
| 0xa24 | 2596 | ? | QVariant::toBool FUN_00a203ca | - |
| 0xa25 | 2597 | ? | FUN_00a203be QVariant::QVariant | - |
| 0xa3e | 2622 | ? | QVariant::toInt | +0x21b |
| 0xa3f | 2623 | ? | QVariant::QVariant vt+0x138 | - |
| 0xa40 | 2624 | ? | QVariant::toDouble | +0x1d2 |
| 0xa41 | 2625 | ? | QVariant::toDouble | +0x1d3 |
| 0xa42 | 2626 | ? | QVariant::toUInt QVariant::toULongLong FUN_00a4e2e4 FUN_009501b0 | - |
| 0xa47 | 2631 | ? | QVariant::QVariant | - |
| 0xa49 | 2633 | ? | QVariant::toLongLong FUN_00925352 QVariant::QVariant | - |
| 0xa55 | 2645 | ? | QVariant::toLongLong FUN_0092c1ba QVariant::QVariant | - |
| 0xa5a | 2650 | ? | FUN_00a20248 QVariant::QVariant | - |
| 0xa5b | 2651 | ? | QVariant::toFloat | +0x1d4 |
| 0xbb9 | 3001 | ? | inline | - |
| 0xbba | 3002 | ? | inline | - |
| 0x4e23 | 20003 | ? | FUN_00a4d0e2 | - |
| 0x4e25 | 20005 | ? | QVariant::toLongLong FUN_00a24866 | - |
| 0x4e26 | 20006 | ? | inline | - |
| 0x4e27 | 20007 | ? | FUN_009cff30 QVariant::toLongLong FUN_0092d76e FUN_009cff96 | - |
| 0x4e28 | 20008 | ? | FUN_00930ec0 QVariant::QVariant | - |
| 0x4e2e | 20014 | ? | QVariant::toLongLong | - |
| 0x4e2f | 20015 | ? | QVariant::toLongLong | - |
| 0x4e37 | 20023 | ? | QVariant::toLongLong | - |
| 0x4e38 | 20024 | ? | QVariant::toLongLong | - |
| 0x4e49 | 20041 | ? | inline | - |
| 0x4e4a | 20042 | ? | inline | - |
| 0x4e4c | 20044 | ? | FUN_00a38c56 | - |
| 0x4e75 | 20085 | ? | QVariant::toULongLong FUN_00951844 FUN_00959890 s_margin_number_a302fe | - |
| 0x4e8c | 20108 | ? | FUN_00a5ebb0 | - |
| 0x4ebb | 20155 | ? | FUN_00927600 QVariant::QVariant | - |
| 0x4ebc | 20156 | ? | FUN_009276e2 QVariant::QVariant | - |
| 0x4ec2 | 20162 | ? | FUN_00926e6a QVariant::QVariant | - |
| 0x4ec3 | 20163 | ? | QVariant::toLongLong FUN_00926e76 QVariant::QVariant | - |
| 0x4ec5 | 20165 | ? | QVariant::toBool | - |
| 0x4ec6 | 20166 | ? | QVariant::QVariant | - |
| 0x4ec7 | 20167 | ? | QVariant::toLongLong FUN_00927ce0 QVariant::QVariant | - |
| 0x4ec8 | 20168 | ? | QVariant::toLongLong FUN_00927e22 QVariant::QVariant | - |
| 0x4ec9 | 20169 | ? | QVariant::toBool FUN_00927a68 QVariant::QVariant | - |
| 0x4ecd | 20173 | EXT | activateNextSelection | FUN_00a237a6 | - |
| 0x4ece | 20174 | EXT | activatePreviousSelection | FUN_00a23808 | - |
| 0x4ecf | 20175 | EXT | lockSelection | FUN_00a2386a | - |
| 0x4ed0 | 20176 | EXT | dropSelection | QVariant::toInt FUN_00a23894 | - |
| 0x4ed2 | 20178 | EXT | splitSelection | FUN_00a20198 | - |
| 0x4ed4 | 20180 | EXT | FUN_00a20266 | - |
| 0x4ee4 | 20196 | EXT | FUN_00a385ee QVariant::QVariant | - |
| 0x4ee6 | 20198 | EXT | FUN_00a286a2 | - |
| 0x4ee8 | 20200 | EXT | FUN_00a1fc18 QVariant::QVariant | - |
| 0x4ee9 | 20201 | EXT | QVariant::toByteArray FUN_00a28d1e | - |
| 0x4eeb | 20203 | EXT | FUN_009257a8 | - |
| 0x4eed | 20205 | EXT | QVariant::toLongLong FUN_009257f0 QVariant::QVariant | - |
| 0x4eef | 20207 | EXT | QVariant::toInt FUN_00928454 QVariant::QVariant | - |
| 0x4ef0 | 20208 | EXT | QVariant::toInt FUN_0093499e QVariant::QVariant | - |
| 0x4ef1 | 20209 | EXT | QVariant::toInt FUN_0093493e QVariant::QVariant | - |
| 0x4ef2 | 20210 | EXT | QVariant::toInt FUN_0093496e QVariant::QVariant | - |
| 0x4ef3 | 20211 | EXT | QVariant::toULongLong QVariant::toBool FUN_00a2e858 | - |
| 0x4ef5 | 20213 | EXT | inline | - |
| 0x4ef8 | 20216 | EXT | FUN_00a28424 QVariant::QVariant | - |
| 0x4ef9 | 20217 | EXT | FUN_00a28388 QVariant::QVariant | - |
| 0x4efa | 20218 | EXT | FUN_00926c6e QVariant::QVariant | - |
| 0x4efb | 20219 | EXT | FUN_00926d1a QVariant::QVariant | - |
| 0x4efd | 20221 | EXT | FUN_00926dfc QVariant::QVariant | - |
| 0x4eff | 20223 | EXT | QVariant::toULongLong QVariant::QVariant | - |
| 0x4f00 | 20224 | EXT | QVariant::toULongLong QVariant::QVariant | - |
| 0x4f01 | 20225 | EXT | FUN_00a28662 | - |
| 0x4f02 | 20226 | EXT | moveTo | QVariant::toByteArray FUN_00a2f82a QVariant::QVariant | - |
| 0x4f04 | 20228 | EXT | cancelMultipleSelections | FUN_00a20104 | - |
| 0x7533 | 30003 | WT | QVariant::toBool | - |
| 0x7535 | 30005 | WT | QVariant::toInt FUN_00a30d26 | - |
| 0x7536 | 30006 | WT | QVariant::toULongLong FUN_00a23d26 | - |
| 0x7537 | 30007 | WT | inline | - |
| 0x7538 | 30008 | WT | QVariant::toULongLong FUN_00a24126 | - |
| 0x753a | 30010 | WT | QVariant::toMap FUN_0092ed32 | - |
| 0x753c | 30012 | WT | FUN_00a297c6 QVariant::QVariant | - |
| 0x753d | 30013 | WT | QVariant::toInt | - |
| 0x753e | 30014 | WT | QVariant::toDouble FUN_00a417fe | - |
| 0x753f | 30015 | WT | vt+0xc0 | - |
| 0x7541 | 30017 | WT | QVariant::toDouble FUN_00a204a0 | - |
| 0x7543 | 30019 | WT | QVariant::toULongLong FUN_0092f0f6 FUN_0095cc7e session_view_soft_reset | - |
| 0x7544 | 30020 | WT | QVariant::toReal FUN_00a4186e | - |
| 0x7545 | 30021 | WT | addScrollBarMark | QVariant::toULongLong QVariant::toString FUN_00933366 | - |
| 0x7546 | 30022 | WT | QVariant::QVariant vt+0xe8 | - |
| 0x7548 | 30024 | WT | QVariant::QVariant vt+0xe8 | - |
| 0x754a | 30026 | WT | vt+0xd0 | - |
| 0x754b | 30027 | WT | QVariant::toBool | - |
| 0x754c | 30028 | WT | QVariant::toBool | - |
| 0x754d | 30029 | WT | FUN_0092e44e | - |
| 0x754f | 30031 | WT | FUN_009305e6 QVariant::QVariant | - |
| 0x7551 | 30033 | WT | appendText | QVariant::toULongLong QVariant::toLongLong QVariant::toByteArray QVariant::toBool | - |
| 0x7552 | 30034 | WT | QVariant::toULongLong FUN_00a4e152 QVariant::toByteArray FUN_00a2893e | - |
| 0x7553 | 30035 | WT | QVariant::toLongLong FUN_00a4b6df QVariant::QVariant | - |
| 0x7554 | 30036 | WT | subString | QVariant::toLongLong FUN_0092777c QVariant::QVariant | - |
| 0x7556 | 30038 | WT | FUN_00927ec8 QVariant::QVariant | - |
| 0x7558 | 30040 | WT | FUN_00927a24 FUN_00927dbe FUN_00a26756 FUN_00927ebc | - |
| 0x7559 | 30041 | WT | QVariant::toList FUN_0069eb30 QVariant::toString QVariant::toBool | - |
| 0x755a | 30042 | WT | QVariant::toString FUN_00927efc | - |
| 0x755b | 30043 | WT | QVariant::toBool FUN_00927f16 | - |
| 0x755c | 30044 | WT | QVariant::QVariant | - |
| 0x755d | 30045 | WT | QVariant::QVariant | - |
| 0x755e | 30046 | WT | FUN_00a29014 FUN_0096bbc0 QVariant::QVariant FUN_0096bb02 | - |
| 0x755f | 30047 | WT | QVariant::QVariant | - |
| 0x7560 | 30048 | WT | QVariant::QVariant | - |
| 0x7561 | 30049 | WT | QVariant::toBool FUN_00a2d5a0 | - |
| 0x7563 | 30051 | WT | QVariant::toInt FUN_00a2d648 | - |
| 0x7565 | 30053 | WT | QVariant::toLongLong FUN_009284aa QVariant::QVariant | - |
| 0x7566 | 30054 | WT | QVariant::toLongLong FUN_0093079a QVariant::QVariant | - |
| 0x7567 | 30055 | WT | QVariant::toReal FUN_00959890 s_margin_number_a302fe s_margin_timestamp_a30e02 | +0x1a2 |
| 0x7568 | 30056 | WT | FUN_008ddd50 QVariant::toList FUN_0069eb30 QVariant::canConvert | +0x1b6 +0x1b7 +0x1b8 +0x1b9 |
| 0x756a | 30058 | WT | QVariant::toBool vt+0xa0 | - |
| 0x756c | 30060 | WT | QVariant::toBool | - |
| 0x756d | 30061 | WT | FUN_00925c02 QVariant::toULongLong QVariant::toInt FUN_0092671c | - |
| 0x756e | 30062 | WT | FUN_00925c02 QVariant::toULongLong QVariant::toInt FUN_0092671c | - |
| 0x756f | 30063 | WT | fold | QVariant::toLongLong FUN_00a5ec00 | - |
| 0x7571 | 30065 | WT | fold | QVariant::toBool QVariant::toLongLong FUN_00a5ed6e | - |
| 0x7572 | 30066 | WT | QVariant::toLongLong FUN_00a5ed6e | - |
| 0x7573 | 30067 | WT | QVariant::toLongLong FUN_00a5e952 | - |
| 0x7575 | 30069 | WT | QVariant::toBool QVariant::toLongLong FUN_00a5ed6e | - |
| 0x7576 | 30070 | WT | QVariant::toLongLong runstyles_runnode_init FUN_0095c92c FUN_0096bb02 vt+0xa0 | - |
| 0x7577 | 30071 | WT | eolString | QVariant::toLongLong FUN_00a21a0e QVariant::QVariant | - |
| 0x7578 | 30072 | WT | FUN_00a21b1e QVariant::QVariant | - |
| 0x757a | 30074 | WT | QVariant::toInt FUN_00a21b6a | - |
| 0x757c | 30076 | WT | QVariant::toBool | - |
| 0x757d | 30077 | WT | QVariant::toLongLong FUN_00925200 FUN_0092520c FUN_009284aa | - |
| 0x757e | 30078 | WT | indexOf | QVariant::toList FUN_0069eb30 QVariant::toString QVariant::toLongLong | - |
| 0x757f | 30079 | WT | QVariant::toLongLong QVariant::toULongLong FUN_00a38936 QVariant::QVariant | - |
| 0x7581 | 30081 | WT | QVariant::toBool FUN_00a28316 | - |
| 0x7583 | 30083 | WT | QVariant::toBool FUN_00a10c68 s_pair_highlightUnmatched_a29352 vt+0xa0 | - |
| 0x7584 | 30084 | WT | QVariant::QVariant | - |
| 0x7586 | 30086 | WT | QVariant::toInt vt+0xa0 | +0x1b1 |
| 0x7588 | 30088 | WT | QVariant::toLongLong FUN_009588b8 QVariant::QVariant | - |
| 0x758a | 30090 | WT | QVariant::toMap QVariant::toByteArray QVariant::toInt QVariant::toBool | - |
| 0x758b | 30091 | WT | QVariant::toBool vt+0xa0 | - |
| 0x758c | 30092 | WT | QVariant::toFloat session_view_soft_reset | - |
| 0x758d | 30093 | WT | QVariant::toBool QVariant::toLongLong FUN_00927ea8 | - |
| 0x758f | 30095 | WT | QVariant::toPoint FUN_00a2a982 QVariant::QVariant | - |
| 0x7591 | 30097 | WT | margins | QVariant::QVariant | - |
| 0x7592 | 30098 | WT | QVariant::toStringList session_view_soft_reset | +0x1ae |
| 0x7593 | 30099 | WT | QVariant::toBool | - |
| 0x7594 | 30100 | WT | removeMargin | QVariant::toByteArray FUN_005445c4 FUN_00a4bc60 | +0x1ac |
| 0x7595 | 30101 | WT | inline | +0x1ae +0x1ab +0x1ac +0x1ad |
| 0x7597 | 30103 | WT | setMarginTrackChange | QVariant::toBool FUN_00a1fd8c | - |
| 0x7598 | 30104 | WT | QVariant::QVariant | - |
| 0x7599 | 30105 | WT | QVariant::toBool vt+0xa0 | - |
| 0x759a | 30106 | WT | setHexBase | QVariant::toInt FUN_00a28e7c | - |
| 0x759c | 30108 | WT | QVariant::toInt vt+0xa0 | - |
| 0x759e | 30110 | WT | setHexMode | QVariant::toBool FUN_00a30c2e | - |
| 0x759f | 30111 | WT | FUN_00926e08 QVariant::QVariant | - |
| 0x75a0 | 30112 | WT | QVariant::toLongLong FUN_00975bc6 FUN_0096bbc0 FUN_0092522a | - |
| 0x75a1 | 30113 | WT | QVariant::toUInt FUN_00926e3e QVariant::QVariant | - |
| 0x75a3 | 30115 | WT | QVariant::toUInt FUN_00926e1c runstyles_runnode_init FUN_0096be24 | - |
| 0x75a5 | 30117 | WT | setOvertypeEnabled | QVariant::toBool FUN_00a2d3ec | - |
| 0x75a6 | 30118 | WT | QVariant::toString QVariant::toLongLong FUN_00a5940a QVariant::QVariant | - |
| 0x75a7 | 30119 | WT | QVariant::toBool QVariant::toLongLong FUN_009252f4 QVariant::QVariant | - |
| 0x75a8 | 30120 | WT | FUN_00a21576 QVariant::QVariant | - |
| 0x75aa | 30122 | WT | FUN_00a282b8 | - |
| 0x75ac | 30124 | WT | gotoPosition | QVariant::toLongLong FUN_00a26f32 | - |
| 0x75ad | 30125 | WT | FUN_00a20438 QVariant::QVariant | - |
| 0x75ae | 30126 | WT | FUN_00a2b0a2 FUN_00a20430 QVariant::QVariant | - |
| 0x75af | 30127 | WT | FUN_00a28398 QVariant::QVariant | - |
| 0x75b1 | 30129 | WT | FUN_00a224e4 QVariant::QVariant | - |
| 0x75b3 | 30131 | WT | QVariant::toInt QVariant::QVariant | - |
| 0x75b4 | 30132 | WT | QVariant::toInt FUN_00a2398e | - |
| 0x75b5 | 30133 | WT | QVariant::toInt QVariant::toLongLong FUN_00a169cc FUN_00a167ac | - |
| 0x75b6 | 30134 | WT | FUN_00a36e40 QVariant::QVariant | - |
| 0x75b8 | 30136 | WT | selectionText | QVariant::toBool QVariant::toString FUN_00a36f26 QVariant::QVariant | - |
| 0x75ba | 30138 | WT | cancelSnippetMode | FUN_00a28ee8 | - |
| 0x75bb | 30139 | WT | FUN_00a2eee0 QVariant::QVariant | - |
| 0x75bc | 30140 | WT | QVariant::toBool FUN_00a28efe QVariant::QVariant | - |
| 0x75bd | 30141 | WT | QVariant::toByteArray FUN_00a2f09a QVariant::QVariant | - |
| 0x75bf | 30143 | WT | FUN_00a28fa8 QVariant::QVariant | - |
| 0x75c1 | 30145 | WT | QVariant::QVariant | - |
| 0x75c2 | 30146 | WT | QVariant::QVariant | - |
| 0x75c3 | 30147 | WT | QVariant::QVariant | - |
| 0x75c4 | 30148 | WT | setTabSize | QVariant::toInt FUN_00925338 session_view_soft_reset QVariant::QVariant | - |
| 0x75c6 | 30150 | WT | setUseTabStop | QVariant::toBool | - |
| 0x75c8 | 30152 | WT | QVariant::toLongLong FUN_0092759a QVariant::QVariant | - |
| 0x75c9 | 30153 | WT | FUN_00926b28 QVariant::QVariant | - |
| 0x75ca | 30154 | WT | FUN_00926afe QVariant::QVariant | - |
| 0x75cb | 30155 | WT | FUN_00a20680 FUN_0096bbc0 FUN_00a20666 QVariant::toLongLong | - |
| 0x75cd | 30157 | WT | QVariant::QVariant | - |
| 0x75cf | 30159 | WT | QVariant::toLongLong FUN_009589f0 QVariant::QVariant | - |
| 0x75d0 | 30160 | WT | QVariant::toPoint FUN_00a2059c QVariant::QVariant | - |
| 0x75d1 | 30161 | WT | QVariant::toLongLong runstyles_runnode_init FUN_009587cc QVariant::QVariant | - |
| 0x75d2 | 30162 | WT | QVariant::toLongLong FUN_00958498 QVariant::QVariant | - |
| 0x75d4 | 30164 | WT | QVariant::toLongLong FUN_00a2267c QVariant::QVariant | - |
| 0x75d6 | 30166 | WT | setWordSeparators | QVariant::toBool QVariant::toString FUN_009279ec | - |
| 0x75d7 | 30167 | ? | QVariant::QVariant | - |
| 0x75d8 | 30168 | ? | FUN_00a218dc QVariant::QVariant | - |
| 0x75d9 | 30169 | ? | QVariant::toInt FUN_00a218dc FUN_00a245c6 | - |
| 0x75db | 30171 | ? | QVariant::toBool session_view_soft_reset | - |
| 0x75dd | 30173 | ? | FUN_0096bbc0 FUN_0092522a QVariant::QVariant | - |
| 0x75de | 30174 | ? | FUN_0096bbc0 QVariant::QVariant | - |
| 0x75df | 30175 | ? | QVariant::QVariant | - |
| 0x75e0 | 30176 | ? | QVariant::userType QVariant::constData QVariant::convert FUN_00a2cea8 | - |
| 0x75e2 | 30178 | ? | QVariant::QVariant | - |
| 0x75e4 | 30180 | ? | QVariant::toBool FUN_00a2cea8 | - |
| 0x75e5 | 30181 | ? | FUN_00a3175e | - |
| 0x75e6 | 30182 | ? | QVariant::toULongLong QVariant::toBool FUN_0095021a FUN_0094a576 | - |
| 0x75e7 | 30183 | ? | QVariant::toPoint FUN_00a29fa8 QVariant::QVariant | - |
| 0x75e9 | 30185 | ? | QVariant::toPoint FUN_00a2a002 QVariant::QVariant | - |
| 0x75eb | 30187 | ? | QVariant::toPoint FUN_00a2b7fc QVariant::QVariant | - |
| 0x75ec | 30188 | ? | QVariant::toLongLong runstyles_runnode_init FUN_00a2a0ea QVariant::QVariant | - |
| 0x75ed | 30189 | ? | QVariant::toInt QVariant::toPoint FUN_00a2b854 QVariant::QVariant | - |
| 0x75ee | 30190 | ? | QVariant::toLongLong runstyles_runnode_init FUN_00a2a15e QVariant::QVariant | - |
| 0x75f0 | 30192 | ? | FUN_00a2a44a | - |
| 0x75f2 | 30194 | ? | QVariant::QVariant | - |
| 0x75f3 | 30195 | ? | QVariant::QVariant | - |
| 0x75f4 | 30196 | ? | QVariant::toLongLong FUN_00929336 | - |
| 0x75f5 | 30197 | ? | QVariant::toInt FUN_00925ae4 | - |
| 0x75f7 | 30199 | ? | QVariant::toByteArray FUN_00a2a504 | - |
| 0x75f9 | 30201 | ? | FUN_00927170 QVariant::QVariant | - |
| 0x75fa | 30202 | ? | QVariant::toBool QVariant::toLongLong FUN_00a2a6e6 QVariant::QVariant | - |
| 0x75fb | 30203 | ? | QVariant::toBool QVariant::toLongLong FUN_00a2a6e6 QVariant::QVariant | - |
| 0x75fc | 30204 | ? | QVariant::toByteArray FUN_00927216 s_margin_timestamp_a30e02 | - |
| 0x75fe | 30206 | ? | QVariant::toByteArray | - |
| 0x75ff | 30207 | ? | QVariant::toLongLong FUN_009271e4 | - |

336 ==-leaves captured of 336 comparisons
