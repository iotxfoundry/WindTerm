#pragma once

#include <QByteArray>
#include <QString>
#include <QThread>

class QTextCodec;
class Language;

// FileReaderFace — 文件加载线程(编码/EOL/缩进/类型 四类探测 + 进度回报)。
//
// 出处:RTTI "FileReader";QMetaObject 0x011a06a0
// (rev=8,class="FileReader",methods=8,**signals=8**,props=0,superdata=0);
// sizeof = **0x30**(deleting 0x00647ce2 的 operator_delete(_,0x30));
// dtor 0x00647c66(123B);信号桥 0x009032ee(454B);
// metacast 0x009034b4 / metacall 0x009034f6(93B)。
//
// 八条信号 —— **真名 + 形参名 + 形参类型都从串表一次读全**,
// 形参个数与桥 0x009032ee 的 switch 逐条对上:
//   #0 error(const QString &error)                                    1 参
//   #1 fileCodecDetected(QTextCodec *fileCodec, bool convertToUtf8,
//                        bool hasBom)                                 3 参
//   #2 fileEolDetected(int eol)                                       1 参
//   #3 fileIndentDetected(int tabSize, int indentSize,
//                         bool useTabPosition)                        3 参
//   #4 fileInfoDetected(bool isBinaryFile, bool isVirtualFile,
//                       const QString &filePath,
//                       const QString &fileIcon)                     4 参
//   #5 fileSchemeDetected(Language *fileScheme)                      1 参
//   #6 mapped(qint64 filePosition, char firstChar, char lastChar,
//             const QByteArray &bytes, int lines)                    5 参
//   #7 progressed(qint64 offset, qint64 total)                       2 参
//
// 这套信号说明加载流程:先认编码(带 BOM/需转 UTF-8)→ 认 EOL → 认缩进
// → 认类型/虚拟文件/图标 → 认语言方案 → 交内容 + 进度。
//
// 字段:+0x20 QString(错误串/文件名,dtor 里减引用)
class FileReaderFace : public QThread {
	Q_OBJECT

public:
	explicit FileReaderFace(QObject *parent = nullptr);
	~FileReaderFace() override; // 0x00647c66

signals:
	void error(const QString &error);                            // #0
	void fileCodecDetected(QTextCodec *fileCodec, bool convertToUtf8, bool hasBom); // #1
	void fileEolDetected(int eol);                               // #2
	void fileIndentDetected(int tabSize, int indentSize, bool useTabPosition); // #3
	void fileInfoDetected(bool isBinaryFile, bool isVirtualFile,
	                      const QString &filePath, const QString &fileIcon); // #4
	void fileSchemeDetected(Language *fileScheme);               // #5
	void mapped(qint64 filePosition, char firstChar, char lastChar,
	            const QByteArray &bytes, int lines);             // #6
	void progressed(qint64 offset, qint64 total);                // #7

private:
	QString m_f20; // +0x20
};
