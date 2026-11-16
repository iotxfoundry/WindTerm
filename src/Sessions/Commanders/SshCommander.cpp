// 出处:QMetaObject 元数据(moc 仅声明本类,无独立 meta 方法 —— 见 .h 头注)。
// ctor 入口地址**未单点取证**:真身化时回二进制补 FUN_ 地址,勿按基类推测。

#include "SshCommander.h"

SshCommander::SshCommander(QObject *parent)
	: SuperCommander(parent)
{
}
