#include <QApplication>
#include "ScintillaEditBase.h"
#include "Scintilla.h"
#include <cstdio>
int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	ScintillaEditBase edit;
	edit.send(SCI_ADDTEXT, 5, (sptr_t)"hello");   // 0x7d1 — 我们逆向的第 1 个命令
	printf("SCI_ADDTEXT(2001) sent; SCI_GETLENGTH(2006) = %lld\n",
	       (long long)edit.send(SCI_GETLENGTH, 0, 0));
	edit.send(SCI_SETSELECTIONMODE, 1, 0);        // 0x870 家族
	printf("SCI_GETSELECTIONS = %lld\n", (long long)edit.send(SCI_GETSELECTIONS, 0, 0));
	return 0;
}
