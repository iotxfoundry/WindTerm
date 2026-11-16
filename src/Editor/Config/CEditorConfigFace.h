#pragma once

#include <QList>
#include <QObject>
#include <QString>

class QRegExp;

// CEditorConfigFace — 编辑器配置(方案扫描 + 重开历史)。
//
// 出处:RTTI "CEditorConfig";sizeof = **0xb0**
// (deleting 0x005dfbec 的 operator_delete(_,0xb0));
// 析构 0x005e1932(28B)/deleting 0x005dfbec(23B);
//   —— 语料把析构体错标成 `CEditorConfig_vt7`(317B),真正的 vt7 是它;
// 五条虚面(语料给出 5 字节入口,函数体被 Ghidra 接到了下一个 entry):
//   vt5 0x005e194e load()      —— 读 `/reopen.history`(15 字节字面)
//   vt6 0x005e1954 save()      —— 写同一文件
//   vt7 0x005dfaae(317B)       —— **析构体**(清 +0xa8 的正则列表)
//   vt8 0x005dfbec(23B)        —— deleting 析构
// 方案目录扫描 0x005e1732(472B)。
//
// 两个磁盘面(字面实读):
//   · `"/reopen.history"`(15):QFile::open(**1 = ReadOnly**)后 QDataStream
//     读进 +0x98;随后按 bytearray key **"recent"** 取子节点,
//     再 0x008ace64(node, **999**) 限定上限 —— 重开历史上限 999 条。
//   · `"/schemes"`(8):拼配置目录后 QDir::entryList(**0x6400**, -1)
//     —— 0x6400 = QDir::Files | QDir::Readable(?按字面保留),列出方案文件。
//
// 字段(dtor 实读):
//   +0xa8 QList<QRegExp *>(析构里 detach 后逐个 config_dtorFreeRegex +
//        operator_delete)
//   +0x98 重开历史容器(QDataStream 直接读写的目标)
class CEditorConfigFace : public QObject {
	Q_OBJECT

public:
	explicit CEditorConfigFace(QObject *parent = nullptr);
	~CEditorConfigFace() override; // 0x005dfaae / deleting 0x005dfbec

	bool load();       // vt5 0x005e194e
	bool save();       // vt6 0x005e1954
	void scanSchemes(); // 0x005e1732

private:
	// +0x98 的容器类型未复原(QDataStream 直接 << / >>),先按不透明块持有
	char m_history98[0x10] = {};
	QList<QRegExp *> m_regexesA8; // +0xa8
};
