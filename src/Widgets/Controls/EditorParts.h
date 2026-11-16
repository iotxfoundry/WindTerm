#pragma once

#include <QJSValue>
#include <QPlainTextEdit>
#include <QString>
#include <QTranslator>

// EditorParts.h — 编辑/翻译/动作三件(各自一个字段)。
//
// | 类 | 基类(由 dtor 末句判定) | 自有字段 |
// |---|---|---|
// | PlainTextEdit   | **QPlainTextEdit** | +0x30 引用计件(dtor 递减) |
// | SuperTranslator | **QTranslator**    | +0x18 引用计件 |
// | SuperAction     | **QObject**        | +0x10 引用计件 / **+0x18 QJSValue** |
//
// 三处判据都来自 dtor 末句:分别调 QPlainTextEdit:: / QTranslator:: / QObject:: 析构。
//
// **SuperAction 的 +0x18 是 QJSValue** —— 动作能承载脚本值,与 CGlobalConfig 的
// +0x38 QJSValue 同族;说明 WindTerm 的"动作"和"配置"都能挂脚本。
//
// 三者 metacall 均 5 字节纯转发 ⇒ 0 条自有信号槽。
//
// 出处(entry 地址逐一列,真身):
//   PlainTextEdit   dtor 0x008f0f46(88B) / deleting 0x008f0e2c(94B)
//   SuperTranslator dtor 0x00902cde(78B) / deleting 0x00902c8a(84B)
//   SuperAction     dtor 0x009035b6(87B) / deleting 0x0090360e(93B)

class PlainTextEditFace : public QPlainTextEdit {
	Q_OBJECT
public:
	explicit PlainTextEditFace(QWidget *parent = nullptr);
	~PlainTextEditFace() override; // 0x008f0f46
private:
	void *m_ref30 = nullptr; // +0x30
};

class SuperTranslatorFace : public QTranslator {
	Q_OBJECT
public:
	explicit SuperTranslatorFace(QObject *parent = nullptr);
	~SuperTranslatorFace() override; // 0x00902cde
private:
	void *m_ref18 = nullptr; // +0x18
};

class SuperActionFace : public QObject {
	Q_OBJECT
public:
	explicit SuperActionFace(QObject *parent = nullptr);
	~SuperActionFace() override; // 0x009035b6
private:
	void *m_ref10 = nullptr; // +0x10
	QJSValue m_script18;     // +0x18
};
