#pragma once

#include <QCoreApplication>
#include <QDir>
#include <QString>

namespace Assets {

// 可执行文件同级 ../assets 优先（bin/ 启动），否则 CWD/assets；都没有则返回相对串由加载器静默失败
inline QString dir()
{
    const QString appDir = QCoreApplication::applicationDirPath();
    if (!appDir.isEmpty()) {
        const QString candidate = appDir + QStringLiteral("/../assets");
        if (QDir(candidate).exists())
            return candidate;
    }

    const QString cwdCandidate = QDir::currentPath() + QStringLiteral("/assets");
    if (QDir(cwdCandidate).exists())
        return cwdCandidate;

    return QStringLiteral("assets");
}

} // namespace Assets
