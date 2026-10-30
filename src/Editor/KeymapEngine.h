#ifndef KEYMAPENGINE_H
#define KEYMAPENGINE_H

#pragma once

#include "SuperKeymap.h"

#include <QString>
#include <QStringList>
#include <QVariant>

// 键位引擎 —— 语料转写(批 47;铁律 6)。
// 装载器 s_wind_keymaps_768854(00768854,428B)流程:
//   FUN_00a7e75e(43B)累积器初始化 {flags, userPath@+8,
//     globalPath@+0x10, 0x18-0x21}
//   FUN_005d7cf8(174B):applicationDirPath() + "/global/" + 名
//     → FUN_00a7e78a(12B):全局槽 + flags &= ~0x04
//   cfg_ensureProfileDir 005d7dae(438B):"%1/profiles/%2/%3"
//     (.wind 根/profile/名)→ mkpath → FUN_00a7e866(12B):
//     用户槽 + flags &= ~0x01
//   FUN_0067461a(engine@+0x68,0)引擎复位(批 46 SuperKeymap::reset)
//   FUN_00a7fdd8(71B)→ FUN_00a7fd5e(113B):bit2 门 → yaml 解析 →
//     yaml_toQVariant(ConfigBridge 委托,0x00a7ecde 族)
// 匹配体:语料未定位(cited — wave-2,PHASE5 批 46 记录)。
class KeymapEngine {
public:
    static KeymapEngine &instance();

    // s_wind_keymaps_768854:双源路径解析 → 引擎复位 → YAML 装载;
    // 返回非空解析源数
    int loadKeymapSources();

    const QStringList &sources() const { return m_sources; }
    const QVariant &loaded() const { return m_loaded; }   // FUN_00a7fdd8 产物

private:
    KeymapEngine() = default;
    QStringList m_sources;
    QVariant m_loaded;      // FUN_00a7fdd8 合并产物(toList 喂引擎面)
    SuperKeymap m_keymap;   // 语料 engine@+0x68
};
#endif // KEYMAPENGINE_H
