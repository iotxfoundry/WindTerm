// 动作面冒烟(批 32):JsEngine 动作表装载 + 桥对象调用 +
// KeymapEngine 分发。语料锚:wind_actions_build 00667102 /
// JsEngine evaluate 0064abb2 / newQObject 0064b0d0
#include <cstdio>
#include <QCoreApplication>
#include "JsEngine.h"
#include "KeymapEngine.h"
#include <QObject>

static int fails = 0;

class FakeApp : public QObject
{
    Q_OBJECT
public:
    int exitCalls = 0;
    int lastOpacity = -1;
    Q_INVOKABLE void exit() { ++exitCalls; }
    Q_INVOKABLE void setWindowOpacity(double v) { lastOpacity = int(v); }
};

#include "actions_test.moc"

int main(int argc, char **argv)
{
    QCoreApplication kapp(argc, argv);
    FakeApp app;
    auto &js = JsEngine::instance();
    js.installBridge(QLatin1String("application"), &app);

    const int n = js.loadActions(
        QLatin1String("/opt/WindTerm_2.7.0/global/wind.actions"));
    printf("actions loaded=%d\n", n);
    fails += n < 400;   // wind.actions 2700 行/数百动作(量化下限)

    // 1) 注册表命中 + 桥调用(Application.Exit → application.exit())
    fails += !js.hasAction(QLatin1String("Application.Exit"));
    js.runAction(QLatin1String("Application.Exit"));
    fails += app.exitCalls != 1;
    printf("runAction Application.Exit -> exitCalls=%d\n", app.exitCalls);

    // 2) 带参动作(setWindowOpacity(0.5))
    js.runAction(QLatin1String("Application.SetWindowTransparent"));
    fails += app.lastOpacity != 0;
    printf("SetWindowTransparent -> lastOpacity=%d\n", app.lastOpacity);

    // 3) 未注册动作:静默 miss
    js.runAction(QLatin1String("No.Such.Action"));
    fails += app.exitCalls != 1;

    // 4) KeymapEngine 分发:真 wind.keymaps 命中 → action 走注册表
    auto &km = KeymapEngine::instance();
    if (!km.load(QLatin1String(
            "/opt/WindTerm_2.7.0/global/wind.keymaps"))) {
        printf("load wind.keymaps: FAIL\n");
        return 1;
    }
    js.loadActions(QLatin1String(
        "/opt/WindTerm_2.7.0/global/wind.actions"));
    const auto r = km.dispatch(QLatin1String("."),
                               QLatin1String("command"));
    printf("dispatch '.' command: hits=%d ran=%d missed=%d\n",
           r.hits, r.ran, r.missed);
    fails += r.hits < 1;
    fails += r.missed > r.hits;   // 大部 action 应注册在表

    // 5) script 项直评:任意 mode 下有 script 条目即评
    const auto rs = km.dispatch(QLatin1String("."),
                                QLatin1String("normal"));
    printf("dispatch '.' normal: hits=%d ran=%d missed=%d\n",
           rs.hits, rs.ran, rs.missed);

    printf("actions_test fails=%d\n", fails);
    return fails != 0;
}
