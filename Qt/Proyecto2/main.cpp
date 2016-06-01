#include "mainwindow.h"
#include "api.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    API api;
    api.writeDMA();
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //return a.exec();
}
