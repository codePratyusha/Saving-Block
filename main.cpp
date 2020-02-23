#include "mainwindow.h"
#include "introwindow.h"
#include "gamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    introWindow w;
    w.setFixedSize(800,500);
    w.setWindowTitle("UCLA Game");
    w.show();

    //Testing game window
//    GameWindow w;
//    w.setFixedSize(800, 600);
//    w.setWindowTitle("Debugging");
//    w.show();
    return a.exec();
}
