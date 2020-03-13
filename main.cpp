#include "mainwindow.h"
#include "gamewindow.h"

#include <introwindow.h>
#include "losewindow.h"
#include "winwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    introWindow w;
    w.setFixedSize(640,480);
    w.setWindowTitle("UCLA Game");
    w.show();
    return a.exec();

//    QApplication a(argc, argv);
//    WinWindow w;
//    w.setFixedSize(720,480);
//    w.setWindowTitle("UCLA Game");
//    w.show();
//    return a.exec();
}
