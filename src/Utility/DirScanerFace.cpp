// DirScanerFace.cpp — 目录扫描线程。

#include "Utility/DirScanerFace.h"

#include <QFileInfo>

// 同属 0x0089xxxx 区,尚未开批(§5 锚入口):
static bool matchOne(DirScanerFace *self, const QFileInfo &fi, bool isDir); // 0x00897348
static void onDirHit(DirScanerFace *self, const QString &path);             // 0x00898178
static void scanRoot(DirScanerFace *self, const QString &str, const QFileInfo &fi); // 0x0089754a

DirScanerFace::DirScanerFace(QObject *parent)
    : QThread(parent)
{
}

// 0x00919bea(126B)freeList 真身:
//   引用计数减一 → 归零后从尾向头遍历 QList,元素(0x10B)
//   QRegExp::~QRegExp + operator_delete(_,0x10)→ QListData::dispose。
void DirScanerFace::freeList(QList<Pattern> &list)
{
	for (int i = list.size() - 1; i >= 0; --i) {
		delete list[i].re;
		list[i].re = nullptr;
	}
	list.clear();
}

// 0x00919c70(229B)dtor 真身:
//   vptr = &DirScaner_vtable;
//   freeList(+0x28) → freeList(+0x20) → +0x18 组同样逐元素释放
//   → QThread::~QThread
// deleting 0x00919d60(238B):同上 + operator_delete(_, size)。
DirScanerFace::~DirScanerFace()
{
	freeList(m_pats28);
	freeList(m_pats20);
	freeList(m_pats18);
}

void DirScanerFace::setRootPath(const QString &path)
{
	m_root38 = path;
}

void DirScanerFace::addPattern(const Pattern &p)
{
	m_pats18.append(p);
}

// vt12 0x00898396(804B)run() 真身。逐句:
//   ① 由 +0x38 构造 QFileInfo 与 QString(0x008843ac / 0x00884404)
//      → 调 0x0089754a(this, &str, &fi) 做根目录首扫
//   ② 取 +0x18 组(QList 的 d 指针,detach 后按 int 下标遍历):
//        每元素 16 字节:{QRegExp* re, int kind}
//        while (+0x10 停止标志 == 0):
//          kind == 0 → 0x00897348(this, fi, true) 命中 → 0x00898178(this, path)
//          kind == 1 → 0x00897348(this, fi, false) 命中
//                      → QFileInfo(path);exists() && isFile()
//                      → 累计 size 到 +0x34(运行期计数)
//   ③ 组遍历完后继续下一个组(0x20 / 0x28 同构)。
// 说明:三组规则共用同一段处理模板,差别只在传入的 isDir 与命中后的动作。
void DirScanerFace::run()
{
	// ① 根目录首扫:语料把 +0x38 同时喂给 QFileInfo 与 QString 两个构造
	const QFileInfo rootInfo(m_root38);
	scanRoot(this, m_root38, rootInfo); // 0x0089754a — cited

	// ② 规则组遍历(模板段)
	for (auto it = m_pats18.begin(); it != m_pats18.end(); ++it) {
		if (m_stop10 != 0)
			break;
		Pattern &p = *it;
		const QFileInfo fi(p.re->pattern());

		if (p.kind == 0) {
			if (matchOne(this, fi, true))
				onDirHit(this, p.re->pattern()); // 0x00898178
		} else if (p.kind == 1) {
			if (matchOne(this, fi, false)) {
				const QFileInfo hit(p.re->pattern());
				if (hit.exists() && hit.isFile())
					m_count34 += int(hit.size()); // 语料:+0x34 自增
			}
		}
	}
}

// ───────── moc 生成面(出处:QMetaObject 元数据) ─────────
// metaObject 0x011aa2e0 → &staticMetaObject(methods=0,signals=0)
// qt_metacast 0x00919ba2(strcmp "DirScaner" → QThread::qt_metacast)
// qt_metacall 0x00919be4(5B):纯转发 QThread::qt_metacall,本类无自有记录。

static void scanRoot(DirScanerFace *, const QString &, const QFileInfo &) { }
