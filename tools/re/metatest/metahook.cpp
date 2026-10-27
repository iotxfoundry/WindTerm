#include <QMetaObject>
#include "SuperSession.h"
const QMetaObject &MetaProbe_get();
const QMetaObject &MetaProbe_get() { return SuperSession::staticMetaObject; }
