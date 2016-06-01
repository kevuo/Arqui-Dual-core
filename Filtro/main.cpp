#include <QtGui/QApplication>
#include "mapeditor.h"
#include "admimagen.h"
#include "admmatriz.h"
#include "admxml.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapEditor w;
//    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.show();

    return a.exec();
}
