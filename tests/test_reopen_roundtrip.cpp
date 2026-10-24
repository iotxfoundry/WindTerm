// reopen.history round-trip（原 /tmp/opencode/reopen-rt/reopen_rt.cpp）：
// 构造 ReopenState→save→load→逐字段相等；临时目录，不依赖固定路径
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QTemporaryDir>
#include "core/ReopenHistory.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    QTemporaryDir tmpDir;
    if (!tmpDir.isValid()) {
        qWarning() << "SKIP: cannot create temp dir";
        return 0;
    }
    const QString path = tmpDir.filePath(QStringLiteral("reopen-test.history"));

    ReopenState in;
    in.geometry = QByteArray(66, '\x01'); // 模拟 saveGeometry 66B（样例 66B 同长）
    in.maximized = true;
    in.currentIndex = 2;
    in.tabs = {ReopenTabEntry{QStringLiteral("$0a2b3c4d-1111-2222-3333-445566778899")},
               ReopenTabEntry{QStringLiteral("$deadbeef-aaaa-bbbb-cccc-ddddeeeeffff")},
               ReopenTabEntry{QStringLiteral("::explorer")}}; // 内部视图 url 也透传
    in.menuBarVisible = false;
    in.statusBarVisible = true;
    in.toolBarVisible = false;

    if (!ReopenHistory::save(path, in)) {
        qWarning() << "RT FAIL: save";
        return 1;
    }

    ReopenState out;
    if (!ReopenHistory::load(path, out)) {
        qWarning() << "RT FAIL: load";
        return 1;
    }

    int failed = 0;
    auto check = [&failed](bool ok, const char *what) {
        qInfo() << (ok ? "RT OK  " : "RT FAIL") << what;
        if (!ok)
            ++failed;
    };
    check(out.geometry == in.geometry, "geometry bytes equal");
    check(out.geometry.size() == 66, "geometry byte count == 66");
    check(out.maximized == in.maximized, "maximized");
    check(out.currentIndex == in.currentIndex, "currentIndex");
    check(out.tabs.size() == in.tabs.size(), "tab count");
    for (int i = 0; i < qMin(out.tabs.size(), in.tabs.size()); ++i)
        check(out.tabs.at(i).url == in.tabs.at(i).url, qPrintable(QStringLiteral("tab[%1] uuid").arg(i)));
    check(out.menuBarVisible == in.menuBarVisible, "bars[0] menuBar");
    check(out.statusBarVisible == in.statusBarVisible, "bars[1] statusBar");
    check(out.toolBarVisible == in.toolBarVisible, "bars[2] toolBar");

    qInfo() << "TEST_REOPEN_ROUNDTRIP" << (failed == 0 ? "PASSED" : "FAILED") << "(" << failed
            << "failures)" << "file size =" << QFileInfo(path).size() << "B";
    return failed == 0 ? 0 : 1;
}
