#include "mainwindow.h"
#include "gamewindow.h"

#include "winwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    introWindow w;
//    w.setFixedSize(640,480);
//    w.setWindowTitle("UCLA Game");
//    w.show();

    WinWindow w;
    w.setFixedSize(640,480);
    w.show();
    return a.exec();
}
