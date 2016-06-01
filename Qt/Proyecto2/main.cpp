#include "mainwindow.h"
#include "api.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //API api;
    //api.writeDMA();

    MainWindow w;
    w.show();

    return a.exec();
}
