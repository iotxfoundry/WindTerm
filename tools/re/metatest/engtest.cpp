
#include "EditorEngine.h"
#include "Scintilla.h"
#include <QApplication>
#include <cstdio>
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	EditorEngine e;
	e.dispatch(SCI_ADDTEXT, 5, QByteArray("hello"));       // w=len l=text
	const QVariant len = e.dispatch(SCI_GETLENGTH);         // 0x7d6
	printf("hybrid engine: ADDTEXT(2001) -> GETLENGTH(2006) = %lld\n",
	       len.toLongLong());
	e.dispatch(SCI_SETTEXT, 0, QByteArray("你好 WindTerm"));  // SETTEXT(text)
	e.dispatch(SCI_SELECTALL);                          // 0x7dd
	printf("SCI_SELECTALL -> GETSELECTIONS = %lld\n",
	       (long long)e.dispatch(SCI_GETSELECTIONS).toLongLong());
	return 0;
}
