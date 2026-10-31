#ifndef KEYMAPENGINE_H
#define KEYMAPENGINE_H

#pragma once

#include "SuperKeymap.h"

#include <QString>
#include <QStringList>
#include <QVariant>

// 键位引擎 —— 语料转写(批 47 + 本批装载翼/匹配翼骨架;铁律 6)。
// 总入口 FUN_0076b430(68B)= 引擎懒建 + 装载:
//   *(this+0x68)==0 → operator_new(0x20)+FUN_00674648 = SuperKeymap ctor
//   → s_wind_keymaps_768854(00768854)→ FUN_0076aee6(JSON 腿)
// 装载器 s_wind_keymaps_768854(00768854,428B)流程:
//   FUN_00a7e75e(43B)累积器初始化 {flags, userPath@+8,
//     globalPath@+0x10, 0x18-0x21}
//   FUN_005d7cf8(174B):applicationDirPath() + "/global/" + 名
//     → FUN_00a7e78a(12B):全局槽 + flags &= ~0x04
//   cfg_ensureProfileDir 005d7dae(438B):"%1/profiles/%2/%3"
//     (.wind 根/profile/名)→ mkpath → FUN_00a7e866(12B):
//     用户槽 + flags &= ~0x01
//   FUN_0067461a(engine@+0x68,0)引擎复位(批 46 SuperKeymap::reset)
//   FUN_00a7fdd8(71B)(全局)→ yaml_toQVariant → toList →
//     FUN_00678a56(engine, list, 0)   [YAML 装载腿 ×2:两源各自独立喂]
//   FUN_00a8017e(71B)(用户)→ yaml_toQVariant → toList →
//     FUN_00678a56(engine, list, 0)
// JSON 导入腿 FUN_0076aee6(1185B):工具清单容器(DAT_011c1240+0x10)
//   逐项建 {keys, script|when} 条目 → FUN_0067461a(engine,1)→
//   FUN_00678a56(engine, list, 1)—— 面未转写,cited。
// 匹配翼:FUN_006777e6(1347B)→ FUN_0067500e(9978B)×3(mode 2/0/1)
//   → FUN_00674456 状态栏 —— SuperKeymap::feedKey/matchTrie(本批骨架)。
class KeymapEngine {
public:
    static KeymapEngine &instance();

    // FUN_0076b430:懒建 + 装载总入口(YAML 双源 + JSON 腿 cited)
    void load();

    // s_wind_keymaps_768854:双源路径解析 → 引擎复位 → YAML 双源
    // 各自 loadEntries(mode=0);返回非空解析源数
    int loadKeymapSources();

    const QStringList &sources() const { return m_sources; }
    const QVariant &loaded() const { return m_loaded; }   // FUN_00a7fdd8 产物

private:
    KeymapEngine() = default;
    void loadJsonLeg();   // FUN_0076aee6 — cited — wave-2
    QStringList m_sources;
    QVariant m_loaded;      // FUN_00a7fdd8/00a8017e 产物(逐源喂引擎)
    SuperKeymap m_keymap;   // 语料 engine@+0x68(0076b430 懒建;内嵌等价)
};
#endif // KEYMAPENGINE_H
