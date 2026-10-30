#ifndef KEYMAPENGINE_H
#define KEYMAPENGINE_H

#pragma once

#include <QString>
#include <QStringList>

// 键位引擎壳 —— 语料转写(批 42;铁律 6:无转写落点不写匹配逻辑)。
// 语料:s_wind_keymaps_768854(00768854,428B)装载器 ——
//   1) FUN_00a7e75e 累积器初始化
//   2) "wind.keymaps" → FUN_005d7cf8(DAT_011c1240,名)解析 →
//      FUN_00a7e78a 入累积器(00668888 区)
//   3) "user.keymaps" → cfg_ensureProfileDir(DAT_011c1240,名)→
//      FUN_00a7e866 入累积器(006688d4 区)
//   4) FUN_0067461a(engine@+0x68,0)引擎复位(0076890d)
//   5) FUN_00a7fdd8 → QVariant::toList 喂引擎(00768927)
// 匹配/分发体语料未转写 → 不写(待定位 keymap 匹配函数后按转写补)。
class KeymapEngine {
public:
    static KeymapEngine &instance();

    // s_wind_keymaps_768854:双源解析(global+user)→ 引擎复位
    // → 源列表;返回解析出的源路径数
    int loadKeymapSources();

    const QStringList &sources() const { return m_sources; }

private:
    KeymapEngine() = default;
    QStringList m_sources;   // 语料累积器( FUN_00a7e75e 族)
};
#endif // KEYMAPENGINE_H
