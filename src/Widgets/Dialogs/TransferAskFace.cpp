// TransferAskFace.cpp — 传输覆盖策略下拉(批 385)
#include "Widgets/Dialogs/TransferAskFace.h"

#include <QComboBox>
#include <QLabel>
#include <QVariant>

// dialog_add_yn_combo(1482B,0021.c:47258)真身
QComboBox *TransferAskFace::addOverwriteCombo(QWidget *host, bool withAppend, QLabel **outLabel)
{
	if (host == nullptr)
		return nullptr;
	auto *label = new QLabel(QStringLiteral("When destination file &exists:")); // tr(0xc9d920)
	auto *combo = new QComboBox(host);              // new 0x30,父 = 宿主
	combo->setObjectName(QStringLiteral("overwriteCombo")); // 语料宿主 +0x40 槽(此处以命名承接)

	combo->addItem(QStringLiteral("Overwrite"), QVariant(QStringLiteral("-y")));       // 0xc9da0a
	combo->addItem(QStringLiteral("Overwrite when source file newer"),
	               QVariant(QStringLiteral("-n")));                                    // 0xc9d940
	combo->addItem(QStringLiteral("Overwrite when source file newer or longer"),
	               QVariant(QStringLiteral("-N")));                                    // 0xc9d968
	if (withAppend)                                                                     // param_2 != 0
		combo->addItem(QStringLiteral("Append"), QVariant(QStringLiteral("-+")));      // 0xc9da1d
	combo->addItem(QStringLiteral("Rename"), QVariant(QStringLiteral("-E")));          // 0xc9da27
	combo->addItem(QStringLiteral("Resume"), QVariant(QStringLiteral("-r")));          // 0xc8ab2f
	combo->addItem(QStringLiteral("Skip"), QVariant(QString()));                       // 0xc9da2e(data "")

	label->setBuddy(combo);                         // 语料末句 setBuddy
	if (outLabel != nullptr)
		*outLabel = label;
	return combo;
}
