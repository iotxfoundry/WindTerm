// RunToolDialogFace.cpp — 运行工具对话框装配转写(批 314)
#include "Widgets/Dialogs/RunToolDialogFace.h"

#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QJsonObject>
#include <QRadioButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QVariant>

// RunToolDialog_setupUi(1098B,0022.c:35199 区)装配真身
void RunToolDialogFace::setupUi()
{
	m_check30 = new QCheckBox(this);          // @00707afd(0x30)
	m_buttons38 = new QDialogButtonBox(this); // @00707b18(0x30)
	m_label48 = new QLabel(this);             // @00707b35(0x30)
	m_combo40 = new QComboBox(this);          // @00707b50(combo_makeSearchCombo 壳)
	m_tool50 = new QToolButton(this);         // @00707b6b(0x30)
	m_group58 = new QGroupBox(this);          // @00707b86(0x30)
	m_group60 = new QGroupBox(this);          // @00707ba1(0x30)

	// 两轮组装配 @00707bc7-00707cx:
	//   pass1 → +0x58 组,项表 = +0x68(+0x68 表空 → 仅 addStretch);
	//   pass2 → +0x60 组,项表 = +0x70。
	struct Pass {
		QGroupBox *box;
		const QList<Entry> *items;
	};
	const Pass passes[2] = {{m_group58, &m_items68}, {m_group60, &m_items70}};
	for (const Pass &pass : passes) {
		auto *box = new QVBoxLayout(); // @00707bc7(0x20)
		for (const Entry &item : *pass.items) {
			auto *radio = new QRadioButton(); // @00707c03(0x30)
			radio->setProperty("data",
			                   QVariant(QByteArray(item.value))); // 0xc8977d
			box->addWidget(radio);            // @00707cxx
			// 标签由 applyRadioLabels()(FUN_00707320)铺设。
		}
		box->addStretch();                    // @00707bef
		pass.box->setLayout(box);             // @00707cxx
	}
	applyRadioLabels();                       // FUN_00707320 @00707cxx(批 323)
	m_check30->setChecked(false);             // 实参折叠 — cited
	m_buttons38->addButton(QDialogButtonBox::Ok);    // 0x400
	m_buttons38->addButton(QDialogButtonBox::Apply); // 0x400000
	// FUN_0075263e(0x406e000000000000, app, this) 换算宽度 — cited
	// FUN_0053d596(m_combo40, 1) — cited(组合框面)
	if (QLineEdit *le = m_combo40->lineEdit())
		le->setPlaceholderText(tr("Program [Arguments]...")); // 0xca0359 @00707d2a
}

// RunToolDialog ctor(1116B,0022.c:35237)数据表(逐条 BA 字面实读)
const RunToolDialogFace::Entry RunToolDialogFace::kArgTokens[6] = {
    {"", "&None"},
    {"${CurrentChar}", "Current &Char"},
    {"${CurrentWordText}", "Current &Word"},
    {"${CurrentLineText}", "Current &Line"},
    {"${Selection}", "&Selection"},
    {"${BufferText}", "&Buffer"},
};

const RunToolDialogFace::Entry RunToolDialogFace::kOutputActions[8] = {
    {"ignore", "&Ignore"},
    {"insertText", "&Insert Text"},
    {"newBuffer", "&New Buffer"},
    {"replaceBuffer", "&Replace Buffer"},
    {"replaceSelection", "&Replace Selection"},
    {"showOutput", "Show &Output"},
    {"showTooltip", "Show &Tooltip"},
    {"showHtml", "Show &Html"},
};

// RunToolDialog_ctor(1116B,0022.c:35237)真身:
//   @00707f8e QDialog(parent,0);字段 +0x30..+0x60 = 0;
//   +0x68/+0x70/+0x78 = 空 BA;
//   @0070803x FUN_00708c5e(+0x68, 6 项表)(上表 1);
//   @007081c3 FUN_00708c5e(+0x70, 8 项表)(上表 2);
//   @0070839e RunToolDialog_setupUi(this);@007083a4 FUN_0070716e(this)(cited)。
RunToolDialogFace::RunToolDialogFace(QWidget *parent)
	: QDialog(parent) // @00707f8e
{
	for (const Entry &e : kArgTokens)
		m_items68.append(e); // @0070803x(FUN_00708c5e 6 项)
	for (const Entry &e : kOutputActions)
		m_items70.append(e); // @007081c3(8 项)
	setupUi();               // @0070839e
	// FUN_0070716e(this)@007083a4 — cited(装配后处理体未转写)。
}

// FUN_00708402(1825B,0022.c:35342)真身(键面):
//   @00708402 文案 = QComboBox::currentText();空 → 尾腿;
//   @0070846a obj["command"] = 文案;
//   @00708513 +0x58 组 findChildren<QRadioButton> → isChecked 项的
//     property("data").toString() → obj["stdin"]@007085d7;
//   @007086xx 同面 +0x60 组 → obj["stdout"](键 6 字符);
//   尾腿(QString 0xc91414)cited。
QJsonObject RunToolDialogFace::buildCommandObject() const
{
	QJsonObject obj;
	const QString text = m_combo40 != nullptr ? m_combo40->currentText() : QString();
	if (text.isEmpty()) // @00708402 空文案腿
		return obj;
	obj.insert(QStringLiteral("command"), text); // @0070846a
	auto checkedData = [](QGroupBox *box) -> QString {
		if (box == nullptr)
			return QString();
		const QList<QRadioButton *> radios = box->findChildren<QRadioButton *>();
		for (QRadioButton *r : radios) {
			if (r->isChecked()) // @00708586
				return r->property("data").toString(); // @007085a8
		}
		return QString();
	};
	obj.insert(QStringLiteral("stdin"), checkedData(m_group58));  // @007085d7
	obj.insert(QStringLiteral("stdout"), checkedData(m_group60)); // "stdout"
	// 尾腿(0xc91414 串面)— cited。
	return obj;
}

// FUN_00707320(1849B,0022.c:32182)真身:
//   两轮:组(+0x58/+0x60)内 findChildren<QRadioButton>(递归)逐项:
//     data = property("data").toByteArray();
//     表(+0x68/+0x70)逐条 BA 等长 memcmp(@007074bd)→ 命中 →
//     setText(tr(标签))@007074c8 并 break。
void RunToolDialogFace::applyRadioLabels()
{
	auto apply = [this](QGroupBox *box, const QList<Entry> &items) {
		if (box == nullptr)
			return;
		const QList<QRadioButton *> radios = box->findChildren<QRadioButton *>();
		for (QRadioButton *radio : radios) {
			const QByteArray data = radio->property("data").toByteArray();
			for (const Entry &e : items) {
				if (data == QByteArray(e.value)) { // @007074bd
					radio->setText(tr(e.label));   // @007074c8
					break;
				}
			}
		}
	};
	apply(m_group58, m_items68); // @0070736f 起
	apply(m_group60, m_items70); // @0070754f 起
}
