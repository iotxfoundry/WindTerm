// EditorParts.cpp — 编辑/翻译/动作三件(见头注对照表)。

#include "Widgets/Controls/EditorParts.h"

// 出处:三者 metacall 均 5 字节纯转发;ctor 均内联在调用点,只转发基构造。

// dtor 0x008f0f46(88B)真身:+0x30 引用计件递减 → QPlainTextEdit 析构;
// deleting 0x008f0e2c(94B)真身。
PlainTextEditFace::PlainTextEditFace(QWidget *parent) : QPlainTextEdit(parent) { }
PlainTextEditFace::~PlainTextEditFace() = default;

// dtor 0x00902cde(78B)真身:+0x18 引用计件递减 → QTranslator 析构;
// deleting 0x00902c8a(84B)真身。
SuperTranslatorFace::SuperTranslatorFace(QObject *parent) : QTranslator(parent) { }
SuperTranslatorFace::~SuperTranslatorFace() = default;

// dtor 0x009035b6(87B)真身:**先 QJSValue::~QJSValue(+0x18)** →
// +0x10 引用计件递减 → QObject 析构;
// deleting 0x0090360e(93B)真身。
SuperActionFace::SuperActionFace(QObject *parent) : QObject(parent) { }
SuperActionFace::~SuperActionFace() = default;
