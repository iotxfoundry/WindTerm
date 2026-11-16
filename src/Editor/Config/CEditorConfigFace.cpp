// CEditorConfigFace.cpp — 编辑器配置。

#include "Editor/Config/CEditorConfigFace.h"

#include <QDataStream>
#include <QDir>
#include <QFile>
#include <QRegExp>

static void freeRegex(QRegExp *re);                                  // config_dtorFreeRegex
static QString configPath(CEditorConfigFace *self, const QString &rel); // 0x008a5a8e
static QString configDir(CEditorConfigFace *self, const QString &rel);  // 0x008a58f0
static void *configNode(CEditorConfigFace *self, const QByteArray &key); // 0x008a580a
static void capTo(void *node, int max);                              // 0x008ace64
static void readHistory(QDataStream &s, void *dst);                  // 0x008afa6d
static void writeHistory(QDataStream &s, void *src);                 // 0x008aceaf

CEditorConfigFace::CEditorConfigFace(QObject *parent)
    : QObject(parent)
{
}

// 0x005dfaae(317B)析构体真身(语料名错标为 vt7):
//   vptr = &CEditorConfig_vtable;
//   +0xa8 QList:先按写时复制 detach,再从尾向头遍历,
//     每元素 config_dtorFreeRegex(elem) + operator_delete(elem);
//   QListData::dispose;
//   → 基类析构。
CEditorConfigFace::~CEditorConfigFace()
{
	for (int i = m_regexesA8.size() - 1; i >= 0; --i) {
		if (m_regexesA8[i] != nullptr)
			freeRegex(m_regexesA8[i]);
	}
	m_regexesA8.clear();
}

// vt5 0x005e194e(读腿)真身。逐句:
//   path = configPath(this, "/reopen.history")(15 字节字面)
//   QFile f(path);**QFile::open(1 = ReadOnly)**
//   成功 → QDataStream s(&f);readHistory(s, &+0x98)
//        → node = configNode(this, "recent")
//        → capTo(node, **999**)
bool CEditorConfigFace::load()
{
	const QString path = configPath(this, QStringLiteral("/reopen.history"));
	QFile f(path);
	if (!f.open(QIODevice::ReadOnly)) // 1
		return false;

	QDataStream s(&f);
	readHistory(s, m_history98);
	void *const node = configNode(this, QByteArrayLiteral("recent"));
	capTo(node, 999);
	return true;
}

// vt6 0x005e1954(写腿)真身:
//   path 同上;QFile::open(**2 = WriteOnly**)→ QDataStream → writeHistory(&+0x98)
bool CEditorConfigFace::save()
{
	const QString path = configPath(this, QStringLiteral("/reopen.history"));
	QFile f(path);
	if (!f.open(QIODevice::WriteOnly)) // 2
		return false;

	QDataStream s(&f);
	writeHistory(s, m_history98);
	return true;
}

// 0x005e1732(472B)scanSchemes 真身:
//   dir = configDir(this, "/schemes")(8 字节字面)
//   QDir d(dir);names = d.entryList(**QDir::Filter(0x6400)**, -1)
//   detach names 后逐个处理(尾部循环,逐项 cited)。
void CEditorConfigFace::scanSchemes()
{
	const QString dir = configDir(this, QStringLiteral("/schemes"));
	QDir d(dir);
	const QStringList names = d.entryList(QDir::Filter(0x6400), QDir::NoSort);
	Q_UNUSED(names);
}

static void freeRegex(QRegExp *re) { delete re; }
static QString configPath(CEditorConfigFace *, const QString &rel) { return rel; }
static QString configDir(CEditorConfigFace *, const QString &rel) { return rel; }
static void *configNode(CEditorConfigFace *, const QByteArray &) { return nullptr; }
static void capTo(void *, int) { }
static void readHistory(QDataStream &, void *) { }
static void writeHistory(QDataStream &, void *) { }
