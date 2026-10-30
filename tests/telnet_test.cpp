// Telnet 会话链冒烟(loop Iter3):telnet.protocol 装载 + IAC 握手解析
#include <cstdio>
#include "TelnetCommander.h"

int main()
{
    int fails = 0;
    TelnetCommander c;
    if (!c.loadProtocol(QLatin1String(
            "/opt/WindTerm_2.7.0/terminal/protocols/telnet.protocol"))) {
        printf("loadProtocol: FAIL\\n");
        return 1;
    }
    int optHits = 0, subHits = 0;
    QStringList cmds;
    QList<int> opts;
    int subOpt = -1, subAct = -1;
    QObject::connect(&c, &TelnetCommander::optionNegotiated,
        [&](const QString &cmd, int opt) { ++optHits; cmds << cmd; opts << opt; });
    QObject::connect(&c, &TelnetCommander::subOptionReceived,
        [&](int option, int action) { ++subHits; subOpt = option; subAct = action; });

    // NegotiateOption = IAC+cmd+opt(DO ECHO(1) + WILL SGA(3))
    c.feed(QByteArray("\xff\xfd\x01"
                      "\xff\xfb\x03"));
    printf("optHits=%d cmds=%s,%s\n", optHits,
           qPrintable(cmds.value(0)), qPrintable(cmds.value(1)));
    fails += optHits != 2;
    fails += !(cmds.contains(QLatin1String("DO")) && cmds.contains(QLatin1String("WILL")));
    fails += !(opts.contains(1) && opts.contains(3));
    // NegotiateSubOption = IAC SB opt act IAC SE(模式含 IAC 前缀)
    // 显式长度:嵌套 \x00 会被 QByteArray(const char*) 的 strlen 截断
    const QByteArray out = c.feed(QByteArray("\xff\xfa\x18\x00\xff\xf0"
                                             "hello", 11));
    printf("subHits=%d sub=%d/%d passthrough=%s\n", subHits, subOpt,
           subAct, out.constData());
    fails += subHits != 1;
    fails += !(subOpt == 24 && subAct == 0);
    fails += out != QByteArray("hello");
    // 选项状态记录
    fails += c.optionStates.value(1) != QLatin1String("DO");
    fails += c.optionStates.value(3) != QLatin1String("WILL");
    // 半截序列挂起 → 补齐后解析
    const QByteArray tail = c.feed(QByteArray("\xff\xfd"));   // DO 无 option
    const QByteArray out2 = c.feed(QByteArray("\x18"));       // option=24
    printf("tail feed: optHits=%d passthrough2=%d\\n", optHits, out2.size());
    fails += optHits != 3;
    fails += c.optionStates.value(24) != QLatin1String("DO");

    printf("telnet_test fails=%d\\n", fails);
    return fails != 0;
}
