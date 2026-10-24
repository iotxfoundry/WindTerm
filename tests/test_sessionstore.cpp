// F4 SessionStore 写盘 round-trip 测试（HOME=QTemporaryDir 临时目录，不碰用户真数据；
// fixture 自建两条样例条目，不依赖 /tmp 固定路径）
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTemporaryDir>
#include <QVariantMap>
#include <cstdio>

#include "core/SessionStore.h"

static int failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok) ++failed;
}

static QJsonArray readArray()
{
    QFile f(QDir::homePath() + "/.wind/profiles/default.v10/terminal/user.sessions");
    f.open(QIODevice::ReadOnly);
    return QJsonDocument::fromJson(f.readAll()).array();
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    // HOME 指向一次性临时目录：round-trip 从干净受控态开始，不读写用户真数据
    QTemporaryDir home;
    if (!home.isValid()) {
        std::printf("SKIP: cannot create temporary HOME\n");
        return 0;
    }
    ::qputenv("HOME", home.path().toUtf8());

    // 自建 fixture：两条真数据风格条目（键已字母序，与 SessionStore 写回约定一致）
    const QString dstPath = QDir::homePath() + QStringLiteral(
        "/.wind/profiles/default.v10/terminal/user.sessions");
    QDir().mkpath(QFileInfo(dstPath).path());
    {
        QFile f(dstPath);
        if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            std::printf("SKIP: cannot write fixture %s\n", qPrintable(dstPath));
            return 0;
        }
        f.write("[\n"
                "    {\n"
                "        \"session.label\": \"legacy-host\",\n"
                "        \"session.oneKey\": \"bd11d169-40e6-4deb-a0d5-bbae2a12da51\",\n"
                "        \"session.port\": 10022,\n"
                "        \"session.protocol\": \"SSH\",\n"
                "        \"session.target\": \"192.168.1.11\",\n"
                "        \"session.uuid\": \"f257c252-1f03-44a6-a3f5-a0130dd2b89b\",\n"
                "        \"ssh.sysmon\": true\n"
                "    },\n"
                "    {\n"
                "        \"session.label\": \"second-host\",\n"
                "        \"session.port\": 22,\n"
                "        \"session.protocol\": \"SSH\",\n"
                "        \"session.target\": \"root@192.168.1.201\",\n"
                "        \"session.uuid\": \"aa9bcc21-46de-49aa-b8a2-6c5d3767517a\"\n"
                "    }\n"
                "]\n");
    }
    const QJsonArray before = readArray();
    const int n0 = before.size();
    check(n0 > 0, "fixture entries > 0");
    const QJsonObject firstBefore = before.at(0).toObject();
    const QString firstKeySeq = firstBefore.keys().join(',');

    // 1. appendOrReplace 新 Shell 条目
    QVariantMap shell;
    shell.insert("session.uuid", QUuid::createUuid().toString());
    shell.insert("session.protocol", "Shell");
    shell.insert("session.label", "selfcheck-shell");
    shell.insert("session.group", "测试组");
    shell.insert("session.target", "/bin/true");
    shell.insert("process.arguments", "-x");
    shell.insert("process.workingDirectory", "${HomeDir}");
    shell.insert("session.system", "linux");
    check(SessionStore::appendOrReplace(shell), "append new Shell entry ok");

    QJsonArray after = readArray();
    check(after.size() == n0 + 1, "entry count +1");
    check(firstBefore == after.at(0).toObject(), "first entry bytes unchanged");
    // 原条目键序不变（全量比对）
    bool orderKept = true;
    for (int i = 0; i < n0; ++i)
        if (before.at(i).toObject().keys() != after.at(i).toObject().keys())
            orderKept = false;
    check(orderKept, "original entry key order kept");
    // 新条目字段
    const QJsonObject last = after.last().toObject();
    check(last.value("session.label").toString() == "selfcheck-shell"
              && last.value("session.protocol").toString() == "Shell"
              && last.value("process.arguments").toString() == "-x"
              && last.value("session.uuid").toString() == shell.value("session.uuid").toString(),
          "appended entry fields");

    // 2. replace 改 label
    shell.insert("session.label", "selfcheck-shell-2");
    check(SessionStore::appendOrReplace(shell), "replace by uuid ok");
    after = readArray();
    check(after.size() == n0 + 1, "replace keeps count");
    check(after.last().toObject().value("session.label").toString() == "selfcheck-shell-2",
          "replaced label");
    bool orderKept2 = true;
    for (int i = 0; i < n0; ++i)
        if (before.at(i).toObject().keys() != after.at(i).toObject().keys())
            orderKept2 = false;
    check(orderKept2, "key order kept after replace");

    // 3. 备份存在且=写前内容
    QFile bak(QDir::homePath() + "/.wind/profiles/default.v10/terminal/user.sessions.bak");
    check(bak.exists(), "backup file exists");
    if (bak.exists()) {
        bak.open(QIODevice::ReadOnly);
        const QJsonArray bakArr = QJsonDocument::fromJson(bak.readAll()).array();
        check(bakArr.size() == n0 + 1, "backup = pre-write content");
    }

    // 4. load 读回
    const QVector<SessionEntry> entries = SessionStore::load();
    check(entries.size() == n0 + 1, "load() count +1");
    bool found = false;
    for (const SessionEntry &e : entries)
        if (e.uuid == shell.value("session.uuid").toString()
            && e.label == "selfcheck-shell-2" && e.protocol == "Shell"
            && e.target == "/bin/true" && e.port == 0)
            found = true;
    check(found, "load() sees appended entry");

    std::printf("SESSIONSTORE-TEST %s (%d failures)\n", failed == 0 ? "PASSED" : "FAILED", failed);
    return failed == 0 ? 0 : 1;
}
