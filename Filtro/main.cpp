#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include "admimagen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//  w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.show();
    return a.exec();
}
