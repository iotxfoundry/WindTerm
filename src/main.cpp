#include <QApplication>
#include <QPixmap>
#include <QTimer>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    MainWindow *window = new MainWindow;
    window->show();

    if (argc > 1 && QString::fromLocal8Bit(argv[1]) == QStringLiteral("--screenshot")) {
        const QString path = argc > 2 ? QString::fromLocal8Bit(argv[2])
                                      : QStringLiteral("/tmp/opencode/skeleton.png");
        QTimer::singleShot(400, &app, [window, path]() {
            window->grab().save(path, "PNG");
            QCoreApplication::quit();
        });
    }

    return app.exec();
}
