#include "EditorEngine.h"
#include <QApplication>
#include <cstdio>
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	EditorEngine e;
	e.dispatch(2001, 5, QByteArray("hello"));          // SCI_ADDTEXT
	e.dispatch(0x75c4, 4);                             // WT setTabSize
	printf("tabSize=%lld len=%lld\n",
	       e.dispatch(0x75c1).toLongLong(),            // WT tabSize read
	       e.dispatch(2006).toLongLong());             // SCI_GETLENGTH
	QVariant m = e.dispatch(0x757e, QVariantList{"ell", 0, 5, 0, 1}); // indexOf
	printf("indexOf ell -> start=%lld\n", m.toMap()["start"].toLongLong());
	return 0;
}
