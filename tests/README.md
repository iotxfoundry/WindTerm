# 行为门测试(每轮提交门)

| 测试 | 覆盖 |
|---|---|
| e2eterm | 端到端终端路径:config→Screen→core→单元格(25 断言) |
| recheck | 数据表+键哈希抽查(22 例) |
| engtest | 编辑引擎混合层 |
| engtest2 | tabSize/indexOf 抽查 |
| engtest3 | TerminalView 离屏渲染(格子→像素、viewWrite、resize) |
| engtest4 | Phase 5 对称 dump(writeText→格子 JSON,对比原版) |

运行:`cd build && ctest`(环境已封装:bundled Qt + offscreen;
测试链接不得带 LD_LIBRARY_PATH,详见根 CMakeLists 注记)。
序列/驱动资产:tools/re/phase5/。RE 探针:tools/re/metatest/。
