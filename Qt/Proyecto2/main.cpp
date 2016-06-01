#include "mainwindow.h"
#include "api.h"
#include <QApplication>
#include "qpushbutton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    API api;
    api.writeDMAMatriz(1210);
    api.readDMAMatriz();

    //MainWindow w;
    //w.show();

    return a.exec();
}
