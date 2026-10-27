#include <QMetaObject>
#include <cstdio>
const QMetaObject &MetaProbe_get();
int main()
{
	const QMetaObject &mo = MetaProbe_get();
	printf("metaobject: class=%s methods=%d signals=%d slots=%d enums=%d\n",
	       mo.className(), mo.methodCount() - mo.methodOffset(),
	       mo.methodCount(), mo.methodCount(), mo.enumeratorCount());
	return 0;
}
