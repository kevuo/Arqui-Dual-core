#include "mainwindow.h"
#include "api.h"
#include <QApplication>
#include "qpushbutton.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    API api;
    api.leerMatriz();
    api.escribirMatriz();
    api.obtenerNiosStatus();
    api.escribirDimensiones();
    api.escribirEstadoDatoListo();

    //MainWindow w;
    //w.show();

    return a.exec();
}
