#include "SuperSessionPrivate.h"
#include <QCoreApplication>
#include <cstdio>
int main(int argc, char **argv)
{
	QCoreApplication app(argc, argv);
	SuperSessionPrivate d(nullptr);
	d.openSession("127.0.0.1", 22, "test");
	QStringList m = d.authMethods();
	printf("ssh session open, authMethods probe: %d methods listed (offline)\n", m.size());
	return 0;
}
