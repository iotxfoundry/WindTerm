#include <QApplication>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName(QStringLiteral("WindTerm"));

    MainWindow *window = new MainWindow;
    window->show();

    return app.exec();
}
