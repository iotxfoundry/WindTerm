#pragma once

#include <QJSEngine>
#include <QQmlEngine>
#include <QJSValue>
#include <QObject>

// JsEngine —— 语料转写(批 68 重做;底座勘定:动态 QJSEngine 真库,
// EXT-BOUNDARY 2026-10-31 libQt5Qml 45 符号交集)。铁律 6:逐函数
// 片段见 tools/re 侧笔记(0064a/b 族;地址注释在实现处)。
// 结构实证:sizeof=0x18 = QObject(16B) + QJSEngine* @+0x10(指针,
// 非值;父链 = this,0020:30179)。无自有信号/槽(qt_metacall 5B
// 纯尾调,008fd850/68/aa)。
class JsEngine : public QObject {
    Q_OBJECT

public:
    explicit JsEngine(QObject *parent = nullptr);            // 0064ab10(33B)
    ~JsEngine() override;                                    // 0064ab32/46(零额外拆除)

    // s_MuxPane_64b102(0064b102,1707B)收编 —— FUN_00766192 创建
    // JsEngine 后即调本引导体(0023:33040-44);MuxPaneJs::bootstrap
    // 为其同体旧转写(父链挂 m_pane 差异,退役待批)。
    void bootstrap(QObject *kingMeta, QObject *paneMeta,
                   QObject *appBridge, QObject *windowBridge);

    // 0064abb2(809B):"'use strict'; () => { %1 }" → evaluate →
    //   isError → tr 文本 .arg(lineNumber).arg(正文);非 error 返空串
    QString runScript(const QString &code);

    // 0064af3c(348B):"'use strict';" + code → evaluate
    QJSValue evaluateStrict(const QString &code);

    // 0064ab5e(76B):全局函数按名调用(undefined instance 承载)
    QJSValue call(const QString &name, const QJSValueList &args);

    // 0064b0be(18B)
    QJSValue newObject();

    // 0064b0d0(41B):newQObject → CppOwnership(0)
    QJSValue newQObjectCppOwned(QObject *obj);

public:
    // 内部引擎槽(语料 +0x10;父链 = this)。批 81 keymap §12 门族
    // (SuperKeymap jsEvaluateGate/jsCallGate/jsNewObjectGate)按语料
    // 00767a70/0076745c 直接读 *(host+0x48) 判"引擎未建"空臂态 ——
    // 字段直读 = 语料访问形(MuxPane +0x48 同面公有)。
    QJSEngine *m_engine = nullptr;   // 语料 +0x10;父链 = this
};
