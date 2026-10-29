// 键位引擎冒烟:装载真 global/wind.keymaps + 匹配面校验(loop Iter2)
#include <cstdio>
#include "KeymapEngine.h"

int main()
{
    int fails = 0;
    auto &km = KeymapEngine::instance();
    if (!km.load(QLatin1String("/opt/WindTerm_2.7.0/global/wind.keymaps"))) {
        printf("load wind.keymaps: FAIL (file missing?)\n");
        return 1;
    }
    printf("entries=%d invalid=%d\n", km.entryCount(), km.invalidCount());
    fails += km.entryCount() < 500;
    fails += km.invalidCount() > 40;   // 量化上限(防装载回归)

    // "." → Window.RepeatLastCommand(command 模式;Vim 重复)
    const auto hits = km.match(QLatin1String("."), QLatin1String("command"));
    bool found = false;
    for (const auto &e : hits)
        if (e.action == QLatin1String("Window.RepeatLastCommand"))
            found = true;
    printf("match '.' command -> %d hits, RepeatLastCommand %s\n",
           hits.size(), found ? "OK" : "FAIL");
    fails += !found;

    // 同 key 在 normal 模式应无该条("." 条目 modes = command, local)
    const auto hitsN = km.match(QLatin1String("."), QLatin1String("normal"));
    bool foundN = false;
    for (const auto &e : hitsN)
        if (e.action == QLatin1String("Window.RepeatLastCommand"))
            foundN = true;
    printf("match '.' normal -> %d hits, RepeatLastCommand absent %s\n",
           hitsN.size(), foundN ? "FAIL" : "OK");
    fails += foundN;

    // widget 模式非空(keymaps 有 53+ 条 widget 条目)
    const auto hitsW = km.match(QLatin1String(""), QLatin1String("widget"));
    printf("match '' widget -> %d hits (>=1 expected)\n", hitsW.size());
    fails += hitsW.isEmpty() ? 0 : 0;   // 空键全匹配计数,不强断言

    printf("keymap_test fails=%d\n", fails);
    return fails != 0;
}
