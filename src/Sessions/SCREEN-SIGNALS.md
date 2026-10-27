# Screen 信号表(经 setScreen 安装器布线 + 发射器 activate 索引)

| 信号 idx | 发射器 | 接收槽(TerminalWidget) | 已证名 |
|---|---|---|---|
| 3 | FUN_00913274 | FUN_0083acf4 | - |
| 4 | FUN_0091340c | FUN_0083d8e6 | - |
| 5 | FUN_00913436 | FUN_0083a906 | - |
| 6 | FUN_00913592 | FUN_0083ac06 | - |
| 7 | FUN_00913460 | FUN_0083aa14 | cursorVisible |
| 8 | FUN_009131c8 | FUN_0083a988 | mouseMode |
| 9 | FUN_0091329e | FUN_0083daf6 | - |
| 10 | FUN_00913498 | FUN_008421ec | - |
| 12 | FUN_009132f8 | FUN_0083b8a4 | - |
| 17 | FUN_009136b2 | FUN_00840e66 | - |
| 18 | FUN_009134d0 | FUN_0083ab80 | reverseScreen |
| 19 | FUN_0091318c | FUN_0083fc2c | - |
| 24 | FUN_0091334c | FUN_0083b240 | - |
| 25 | FUN_009131fe | FUN_0083acce | - |
| 26 | FUN_009136dc | FUN_0083af62 | - |
| 27 | FUN_0091370c | FUN_0083af9a | - |
| 28 | FUN_00913760 | FUN_0084dd5a | - |
| 29 | FUN_00913736 | FUN_0083be38 | - |
| 30 | FUN_0091378a | FUN_00848d6a | - |
| 31 | FUN_009137ce | FUN_0083ad32 | - |
| 33 | FUN_009133b2 | FUN_0083d3f6 | - |
| 34 | FUN_00913540 | FUN_0083ac2a | - |
| 35 | FUN_009137f8 | FUN_0083ad60 | - |
| (scrollbar) | FUN_00913508 | FUN_0083aa9a | scrollbarNotify |

Screen 元对象 0x11a82e0 信号索引至少覆盖 1..35(20+ 个已读出索引),
远超此前实证的 5 个;全部经 FUN_008464ec 安装器连接到 TerminalWidget 槽。
