#pragma once

#include <QJSEngine>
#include <QObject>

// MuxPane JS 宿主引导 —— 语料转写(批 39,s_MuxPane_64b102 1707B;
// 铁律 6)。语料流程:
//   1) 旧引擎 @+0x10 非空 → deleteLater(0064b12x)
//   2) new QJSEngine → 存 +0x10(0064b134)
//   3) installExtensions(All, QJSValue(undefined))(0064b15a)
//   4) "King" → newQMetaObject → globalObject().setProperty("King")
//      → "Object.freeze(%1)" arg → FUN_0064af3c(evaluateStrict)
//      (0064b1a8-0064b218)
//   5) "MuxPane" → newQMetaObject → setProperty → freeze
//      (0064b2ab-0064b2e2)
//   6) "application"(newQObject)→ setProperty → evaluate
//      (0064b3xx 区)
//   7) "window"(newQObject)→ setProperty → evaluate(0064b4xx 区)
// 桥对象(application/window)由宿主装配期提供(应用级单例,
// Phase 4c;本类以参数接收,不发明来源)。
class MuxPaneJs {
public:
    explicit MuxPaneJs(QObject *pane);
    ~MuxPaneJs();

    // s_MuxPane_64b102 引导全程(幂等:旧引擎先 deleteLater)
    void bootstrap(QObject *kingMeta, QObject *muxPaneMeta,
                   QObject *applicationBridge, QObject *windowBridge);

    QJSEngine *engine() const { return m_engine; }   // 语料 +0x10

private:
    QJSEngine *m_engine = nullptr;   // 语料 +0x10
    QObject *m_pane = nullptr;       // 语料 cast 宿主(PTR_011a6c00 面)
};
