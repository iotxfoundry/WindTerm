// 五小对话框结构/行为断言（QApplication offscreen）：
// NameDialog 0x006bd7f6 / PasteDialog 0x006caf18 / LogDialog 0x006b874c /
// FocusModeDialog 0x006b6676 / WindowOpacityDialog 0x00704dd2
#include <QApplication>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QFile>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QSpinBox>
#include <QStackedWidget>
#include <QTabBar>
#include <QTemporaryDir>
#include <QDir>
#include <cstdio>

#include "dialogs/FocusModeDialog.h"
#include "dialogs/LogDialog.h"
#include "dialogs/NameDialog.h"
#include "dialogs/PasteDialog.h"
#include "dialogs/WindowOpacityDialog.h"
#include "core/WindConfig.h"

static int failed = 0;
static void check(bool ok, const char *what)
{
    std::printf("%s %s\n", ok ? "PASS" : "FAIL", what);
    if (!ok)
        ++failed;
}

static void writeConfig(const QString &dir, const char *json)
{
    QFile f(dir + QStringLiteral("/wind.config"));
    f.open(QIODevice::WriteOnly | QIODevice::Truncate);
    f.write(json);
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // 1. NameDialog：控件存在 + OK 门控 + 文本 API
    {
        NameDialog d(NameDialog::Mode::Create, QStringLiteral("new file"));
        check(d.windowTitle() == QLatin1String("Create new file"), "name: title Create <name>");
        check(d.findChild<QLabel *>() != nullptr, "name: prompt label");
        check(d.findChild<QLineEdit *>() != nullptr, "name: edit");
        auto *box = d.findChild<QDialogButtonBox *>();
        check(box && (box->standardButtons() & QDialogButtonBox::Ok)
                  && (box->standardButtons() & QDialogButtonBox::Cancel),
              "name: Ok|Cancel box");
        check(!box->button(QDialogButtonBox::Ok)->isEnabled(), "name: empty text → OK disabled");
        d.findChild<QLineEdit *>()->setText(QStringLiteral("x"));
        check(box->button(QDialogButtonBox::Ok)->isEnabled(), "name: non-empty → OK enabled");
        check(d.text() == QLatin1String("x"), "name: text()");
        NameDialog r(NameDialog::Mode::Rename, QStringLiteral("old"));
        check(r.windowTitle() == QLatin1String("Rename old"), "name: rename title");
        // open() 接线面（非模态冒烟：不 exec，只构造型校验由 ctor 覆盖）
    }

    // 2. PasteDialog：控件清单 + 统计刷新 + 行数算法（0x006ca484 语义）
    {
        PasteDialog d(QStringLiteral("a\r\nb\nc"));
        check(d.windowTitle() == QLatin1String("Paste"), "paste: title");
        auto *edit = d.findChild<QPlainTextEdit *>();
        auto *label = d.findChild<QLabel *>();
        auto *spin = d.findChild<QSpinBox *>();
        auto *tab = d.findChild<QCheckBox *>();
        check(edit && label && spin && tab, "paste: widgets exist");
        check(edit->lineWrapMode() == QPlainTextEdit::NoWrap, "paste: NoWrap");
        const QStringList boxTexts = [&] {
            QStringList out;
            const auto btns = d.findChildren<QPushButton *>();
            for (auto *b : btns)
                out << b->text();
            return out;
        }();
        check(boxTexts.contains(QLatin1String("&Paste")), "paste: &Paste button");
        check(boxTexts.contains(QLatin1String("&Send Line By Line")), "paste: &Send Line By Line");
        // "a\r\nb\nc" → 3 行 5 字符（0x006ca4f8 "&Text: %1 lines, %2 characters"）
        check(label->text() == QLatin1String("&Text: 3 lines, 5 characters"),
              "paste: stats CRLF-aware");
        check(spin->minimum() == 1, "paste: spin min 1 (证据值)");
    }

    // 3. LogDialog：键 round-trip（临时 HOME 装载 user.config）+ 单选映射
    QString homePath;
    {
        QTemporaryDir home;
        homePath = home.path();
        home.setAutoRemove(false); // 后续段继续用同一 HOME（进程尾不清理，/tmp 自动回收）
        ::qputenv("HOME", home.path().toUtf8());
        QDir().mkpath(home.path() + QStringLiteral("/.wind/profiles/default.v10"));
        {
            QFile f(home.path() + QStringLiteral("/.wind/profiles/default.v10/user.config"));
            f.open(QIODevice::WriteOnly);
            f.write("{\"session.userLogFilePath\":\"/tmp/x.log\","
                    "\"session.userLogPattern\":\"[%v]\","
                    "\"session.userLogType\":14,"
                    "\"session.userLogOption\":2}");
        }
        writeConfig(home.path(), "{}");
        WindConfig::instance().load(home.path() + QStringLiteral("/wind.config"));

        LogDialog d(nullptr);
        check(d.windowTitle() == QLatin1String("Log Dialog"), "log: title");
        const auto edits = d.findChildren<QLineEdit *>();
        check(edits.size() == 2, "log: two edits");
        const auto radios = d.findChildren<QRadioButton *>();
        check(radios.size() == 4, "log: four radios");
        // 读回：file/pattern 来自键；type=14→All；option=2→Append
        bool sawPath = false, sawPattern = false, allChecked = false, appendChecked = false,
             printableUnchecked = true, overwriteUnchecked = true;
        for (auto *e : edits) {
            if (e->text() == QLatin1String("/tmp/x.log"))
                sawPath = true;
            if (e->text() == QLatin1String("[%v]"))
                sawPattern = true;
        }
        for (auto *r : radios) {
            if (r->text() == QLatin1String("&All session output"))
                allChecked = r->isChecked();
            if (r->text() == QLatin1String("&Append log file"))
                appendChecked = r->isChecked();
            if (r->text() == QLatin1String("&Printable output"))
                printableUnchecked = !r->isChecked();
            if (r->text() == QLatin1String("&Overwrite log file"))
                overwriteUnchecked = !r->isChecked();
        }
        check(sawPath && sawPattern, "log: keys read back");
        check(allChecked && appendChecked && printableUnchecked && overwriteUnchecked,
              "log: type14→All / option2→Append");
        check(d.logType() == 14 && d.logOption() == 2, "log: getters");
    }

    // 4. FocusModeDialog：TabBar/Stacked/Checkbox 清单 + checkbox 初值来自键
    {
        writeConfig(homePath,
                    "{\"focusMode.openFocusModeDialog\": false, \"application.windowOpacity\": 1.0}");
        WindConfig::instance().load(homePath + QStringLiteral("/wind.config"));
        FocusModeDialog d;
        check(d.windowTitle() == QLatin1String("Focus Mode"), "focus: title");
        auto *tabs = d.findChild<QTabBar *>();
        check(tabs && tabs->count() == 2 && tabs->autoHide(), "focus: TabBar 2 pages + autoHide");
        check(tabs->tabText(0) == QLatin1String("Editor")
                  && tabs->tabText(1) == QLatin1String("Terminal"),
              "focus: page names Editor/Terminal");
        auto *stack = d.findChild<QStackedWidget *>();
        check(stack && stack->count() == 2, "focus: QStackedWidget 2 pages");
        tabs->setCurrentIndex(1);
        check(stack->currentIndex() == 1, "focus: tab→stack sync");
        auto *chk = d.findChild<QCheckBox *>();
        check(chk && chk->text() == QLatin1String("&Show this dialog when focus mode starts"),
              "focus: checkbox text");
        check(!chk->isChecked(), "focus: checkbox from key (false)");
        auto *box = d.findChild<QDialogButtonBox *>();
        check(box && (box->standardButtons() == (QDialogButtonBox::Ok | QDialogButtonBox::Cancel)),
              "focus: Ok|Cancel");
    }

    // 5. WindowOpacityDialog：滑条初值/范围 + 预览文案 + opacity()
    {
        writeConfig(homePath, "{\"application.windowOpacity\": 0.75}");
        WindConfig::instance().load(homePath + QStringLiteral("/wind.config"));
        WindowOpacityDialog d;
        check(d.windowTitle() == QLatin1String("Window Opacity"), "opacity: title");
        auto *slider = d.findChild<QSlider *>();
        check(slider && slider->orientation() == Qt::Horizontal, "opacity: horizontal slider");
        check(slider->minimum() == 1 && slider->maximum() == 100, "opacity: range 1..100");
        check(slider->value() == 75, "opacity: init from key (0.75×100)");
        check(qFuzzyCompare(d.opacity(), 0.75), "opacity: opacity() = value/100");
        slider->setValue(10);
        const auto labels = d.findChildren<QLabel *>();
        bool sawTransparent = false;
        for (auto *l : labels)
            if (l->text() == QLatin1String("Transparent"))
                sawTransparent = true;
        check(sawTransparent, "opacity: 10→Transparent preview");
        auto *box = d.findChild<QDialogButtonBox *>();
        check(box && (box->standardButtons() == QDialogButtonBox::Close), "opacity: Close button");
    }

    std::printf("%s\n", failed == 0 ? "ALL PASS" : "FAILURES");
    return failed == 0 ? 0 : 1;
}
