#include "zoomwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Zoom widget");
    ZoomWidget w;
    w.show();
    return a.exec();
}
