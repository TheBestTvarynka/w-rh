#include "mainguiwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainGUIWindow w;
    w.show();
    return a.exec();
}
