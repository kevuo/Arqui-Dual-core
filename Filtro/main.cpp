#include <QtWidgets/QApplication>
#include "saltfilter.h"
#include "admimagen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SaltFilter w;
//  w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.show();
    return a.exec();
}
