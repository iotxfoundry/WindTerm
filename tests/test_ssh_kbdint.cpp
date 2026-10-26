// SSH keyboard-interactive 验证（深逆 0x00592e5a/0x00594366/0x00595e52/0x005941e2/
// 0x005961b0/0x00629dea/0x008644b8/0x008619b6）：
// 1) 表单：假 prompts（name/instruction/2 prompts）→行数=1 头行+2 输入行、全 echoMode
//    ==Password、"Retrieving..." 占位先现后撤
// 2) 焦点推进：首行 returnPressed→焦点次行；次行→accepted 信号
// 3) 收集：QMap 键=trimmed(label)、值正确；重复 label 覆盖
// 4) 状态机（fake libssh 指针表，不连真网络）：rc=3 prompts A→答案→setanswer 调用序
//    →再入 rc=3 prompts B→二轮→rc=0 终结
#include <QApplication>
#include <QEventLoop>
#include <QFormLayout>
#include <QLabel>
#include <QLayoutItem>
#include <QLineEdit>
#include <QTimer>

#include <cstdio>

#include "widgets/LoginAuthForm.h"

static int g_failed = 0;
#define CHECK(ok, what)                                     \
    do {                                                    \
        if (ok)                                             \
            printf("PASS: %s\n", what);                     \
        else {                                              \
            printf("FAIL: %s\n", what);                     \
            ++g_failed;                                     \
        }                                                   \
    } while (0)

// singleShot(0) 插行落地（0x00594366 延迟重建）
static void spin(QObject *ctx)
{
    QEventLoop l;
    QTimer::singleShot(0, &l, &QEventLoop::quit); // ctx 非接收者,借本地 loop 退出
    l.exec();
}
#define QTest__spin spin

// 头行（name+instruction 合并 QLabel）+逐 prompt 输入行结构断言
static QLineEdit *fieldAt(LoginAuthForm *form, int promptIndex)
{
    // m_fields 私有——经 form 遍历 QFormLayout：FieldRole 顺序即 prompt 序
    QVector<QLineEdit *> fields;
    const QFormLayout *f = form->findChild<QFormLayout *>();
    for (int i = 0; i < f->rowCount(); ++i) {
        QLayoutItem *it = f->itemAt(i, QFormLayout::FieldRole);
        if (auto *e = it ? qobject_cast<QLineEdit *>(it->widget()) : nullptr)
            fields.append(e);
    }
    return promptIndex < fields.size() ? fields.at(promptIndex) : nullptr;
}

// ---- 状态机（4）：fake libssh 指针表驱动 kbdint 两阶段循环 ----
// 复刻 SshWorker KbdInt 循环骨架（0x00629dea/0x008644b8/0x008619b6），libssh 调用点
// 换成可注入函数对象；setanswer 调用序记录断言。
namespace fake {

struct Server
{
    // 轮次脚本：每轮 {name, instruction, prompts, 期望答案→本轮后 rc}
    struct Round
    {
        QString name;
        QString instruction;
        QStringList prompts;
        QStringList expect; // 与 prompts 对位
        int nextRc = 0;     // setanswer 全提交后下一轮 kbdint 返回值
    };
    QVector<Round> rounds;
    int round = 0;
    QStringList submitted; // setanswer 调用序（"i=answer"）
    int roundStart = 0;    // 本轮 submitted 基线（checkExpect 只对位本轮）
    bool answersMatch = true;

    int kbdint() // ssh_userauth_kbdint 等效
    {
        return round < rounds.size() ? 3 : -1;
    }
    int nprompts() const { return rounds[round].prompts.size(); }
    QString prompt(int i) const { return rounds[round].prompts.at(i); }
    void setAnswer(int i, const QByteArray &buf)
    {
        submitted.append(QStringLiteral("%1=%2").arg(i).arg(QString::fromUtf8(buf)));
    }
    bool checkExpect()
    {
        const Round &r = rounds[round];
        const int base = roundStart;
        if (submitted.size() - base != r.expect.size())
            return false;
        for (int i = 0; i < r.expect.size(); ++i) {
            if (submitted.at(base + i) != QStringLiteral("%1=%2").arg(i).arg(r.expect.at(i)))
                return false;
        }
        return true;
    }
};

// SshWorker::runAuthOp KbdInt 分支同构循环（fake 表换 libssh 调用）
int drive(Server &srv, const QMap<QString, QString> &answersByLabel)
{
    int rc = srv.kbdint();
    while (rc == 3) {
        const int np = srv.nprompts();
        srv.roundStart = srv.submitted.size();
        for (int i = 0; i < np; ++i) {
            const QString key = srv.prompt(i).trimmed(); // 0x005961b0 label trimmed 键
            const QByteArray buf = answersByLabel.value(key).toUtf8(); // 0x008619b6 toUtf8
            srv.setAnswer(i, buf);
        }
        if (!srv.checkExpect()) {
            srv.answersMatch = false;
            return -99; // setanswer 序不符 → 失败不推进
        }
        ++srv.round;
        if (srv.round >= srv.rounds.size())
            return 0; // 终结（rc=0）
        rc = 3; // 再入：新一轮 prompts
    }
    return rc;
}

} // namespace fake

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // ---- 1) 表单结构 + "Retrieving..." 占位先现后撤 ----
    {
        LoginAuthForm form;
        const QFormLayout *f = form.findChild<QFormLayout *>();
        CHECK(f && f->objectName() == QLatin1String("Keyboard Interactive"),
              "1) QFormLayout objectName 'Keyboard Interactive' (0x00592e5a)");
        CHECK(f->rowWrapPolicy() == 2, "1) rowWrapPolicy==2 (0x00592e5a)");
        CHECK(f->rowCount() == 1, "1) pre-prompt placeholder row present");
        QLabel *wait = qobject_cast<QLabel *>(f->itemAt(0, QFormLayout::SpanningRole)
                                                 ? f->itemAt(0, QFormLayout::SpanningRole)->widget()
                                                 : nullptr);
        CHECK(wait && wait->text().contains(QLatin1String("Retrieving prompts")),
              "1) placeholder text 'Retrieving prompts, please wait...'");

        form.setPrompts(QStringLiteral("Login Name"), QStringLiteral("Enter your credentials"),
                        {QStringLiteral("Username:"), QStringLiteral("Password:")});
        QTest__spin(&form); // singleShot(0) 插行落地
        CHECK(f->rowCount() == 3, "1) rows = 1 head (name+instruction merged) + 2 prompts");
        CHECK(fieldAt(&form, 0) && fieldAt(&form, 1), "1) two prompt input rows");
        // 占位撤
        bool waitGone = true;
        for (int i = 0; i < f->rowCount(); ++i) {
            for (int r = 0; r < QFormLayout::FieldRole + 1; ++r) {
                QLayoutItem *it = f->itemAt(i, static_cast<QFormLayout::ItemRole>(r));
                if (auto *lbl = it ? qobject_cast<QLabel *>(it->widget()) : nullptr)
                    if (lbl->text().contains(QLatin1String("Retrieving")))
                        waitGone = false;
            }
        }
        CHECK(waitGone, "1) placeholder withdrawn after prompts arrive");
        // 全掩码（echo 标志读后丢弃——0x00629dea）
        CHECK(fieldAt(&form, 0)->echoMode() == QLineEdit::Password
                  && fieldAt(&form, 1)->echoMode() == QLineEdit::Password,
              "1) all fields echoMode==Password (0x00629dea)");
        // 重复相同 prompts → 跳过（防重复）
        const int rowsBefore = f->rowCount();
        form.setPrompts(QStringLiteral("Login Name"), QStringLiteral("Enter your credentials"),
                        {QStringLiteral("Username:"), QStringLiteral("Password:")});
        QTest__spin(&form);
        CHECK(f->rowCount() == rowsBefore, "1) identical prompts skipped (no dup)");
    }

    // ---- 2) 焦点推进：首行 returnPressed→次行；次行→accepted ----
    {
        LoginAuthForm form;
        form.setPrompts(QString(), QString(),
                        QStringList{QStringLiteral("user:"), QStringLiteral("pass:")});
        QTest__spin(&form);
        form.show(); // offscreen 焦点链需可见窗口
        QTest__spin(&form);
        QLineEdit *first = fieldAt(&form, 0);
        QLineEdit *second = fieldAt(&form, 1);
        int acceptedCount = 0;
        QObject::connect(&form, &LoginAuthForm::accepted,
                         [&] { ++acceptedCount; });
        first->setFocus();
        first->returnPressed(); // 首行回车
        CHECK(QApplication::focusWidget() == second, "2) first returnPressed → focus second");
        second->returnPressed(); // 末行回车
        CHECK(acceptedCount == 1, "2) last row returnPressed → accepted emitted");
    }

    // ---- 3) 收集：键=trimmed(label)、值正确、重复 label 覆盖 ----
    {
        LoginAuthForm form;
        form.setPrompts(QStringLiteral("n"), QStringLiteral("i"),
                        {QStringLiteral("  Username: "), QStringLiteral("Password:")});
        QTest__spin(&form);
        fieldAt(&form, 0)->setText(QStringLiteral("alice"));
        fieldAt(&form, 1)->setText(QStringLiteral("s3cret"));
        const QMap<QString, QString> got = form.collect();
        CHECK(got.size() == 2 && got.value(QStringLiteral("Username:")) == QLatin1String("alice")
                  && got.value(QStringLiteral("Password:")) == QLatin1String("s3cret"),
              "3) collect keys trimmed + values correct");
        // 重复 label 覆盖（0x005961b0 同 key 覆盖）
        LoginAuthForm dup;
        dup.setPrompts(QString(), QString(),
                       {QStringLiteral("Code:"), QStringLiteral("Code:")});
        QTest__spin(&dup);
        QVector<QLineEdit *> dupFields;
        const QFormLayout *df = dup.findChild<QFormLayout *>();
        for (int i = 0; i < df->rowCount(); ++i) {
            QLayoutItem *it = df->itemAt(i, QFormLayout::FieldRole);
            if (auto *e = it ? qobject_cast<QLineEdit *>(it->widget()) : nullptr)
                dupFields.append(e);
        }
        dupFields[0]->setText(QStringLiteral("1111"));
        dupFields[1]->setText(QStringLiteral("2222"));
        const QMap<QString, QString> gotDup = dup.collect();
        CHECK(gotDup.size() == 1 && gotDup.value(QStringLiteral("Code:")) == QLatin1String("2222"),
              "3) duplicate label → same key overwritten (0x005961b0)");
    }

    // ---- 4) 状态机：两轮 prompts→answers→rc=0 终结（fake libssh 表）----
    {
        fake::Server srv;
        fake::Server::Round a;
        a.name = QStringLiteral("Verification");
        a.instruction = QStringLiteral("OTP required");
        a.prompts = QStringList{QStringLiteral("User:"), QStringLiteral("OTP:")};
        a.expect = QStringList{QStringLiteral("alice"), QStringLiteral("123456")};
        a.nextRc = 3; // 再入
        fake::Server::Round b;
        b.prompts = QStringList{QStringLiteral("Second factor:")};
        b.expect = QStringList{QStringLiteral("9999")};
        b.nextRc = 0; // 终结
        srv.rounds = QVector<fake::Server::Round>{a, b};

        QMap<QString, QString> answers;
        answers.insert(QStringLiteral("User:"), QStringLiteral("alice"));
        answers.insert(QStringLiteral("OTP:"), QStringLiteral("123456"));
        answers.insert(QStringLiteral("Second factor:"), QStringLiteral("9999"));

        const int rc = fake::drive(srv, answers);
        CHECK(rc == 0, "4) state machine terminates rc=0 after round B");
        CHECK(srv.answersMatch, "4) setanswer call order matches prompts (0x008619b6)");
        CHECK(srv.submitted == (QStringList{QStringLiteral("0=alice"), QStringLiteral("1=123456"),
                                            QStringLiteral("0=9999")}),
              "4) per-round setanswer sequence: A(2) then B(1) re-indexed");
    }

    printf("SELFCHECK %s (%d failures)\n", g_failed == 0 ? "PASSED" : "FAILED", g_failed);
    return g_failed == 0 ? 0 : 1;
}
