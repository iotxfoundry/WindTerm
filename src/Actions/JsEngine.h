#pragma once

#include <QJSEngine>
#include <QJSValue>
#include <QObject>

// JsEngine —— 语料转写(批 36,0064aXXX 族;铁律 6)。
// 语料类:JsEngine(QObject 派生;metaObject 008fd850;vtable
// 0020:29879;JsEngine_dtor 0064ab32/0064ab46)。QJSEngine 为组合
// 成员(宿主面语料:MuxPane QJSEngine @+0x48,见 FUN_00767a70/
// d08/d2e 三门)。
// 体转写:
//   FUN_0064abb2(809B):字面 "'use strict'; () => { %1 }"(0x1a)
//     QString::arg(param_3) → QJSEngine::evaluate
//   FUN_0064af3c(348B):分配 len+0xd → "use strict';"(0xd 字节)
//     convertFromAscii 前缀 + 原串 memcpy(×2 字节)→ resize →
//     QJSEngine::evaluate
//   FUN_0064b0be(18B):QJSEngine::newObject
//   FUN_0064b0d0(41B):QJSEngine::newQObject
// 注:decomp 中 evaluate(ret, program, name) 槽位 —— program =
// 成员串(@param+0x10),name = 包装/拼接串;Ghidra 槽位歧义已在
// 实现处标注,两字面串均为语料事实。
class JsEngine : public QObject {
    Q_OBJECT

public:
    explicit JsEngine(QObject *parent = nullptr);

    // 0064abb2:"'use strict'; () => { %1 }" 包装
    QJSValue evaluateArrow(const QString &program, const QString &name);

    // 0064af3c:"'use strict';" + name 拼接
    QJSValue evaluateStrict(const QString &program, const QString &name);

    // 0064b0be
    QJSValue newObject();

    // 0064b0d0
    QJSValue newQObject(QObject *obj);

private:
    QJSEngine m_engine;
};
