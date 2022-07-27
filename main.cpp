#include <QCoreApplication>
#include <QDebug>

#include "App.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setApplicationName("athletics-simulator");
    App app;
    app.start();
    return a.exec();
}
