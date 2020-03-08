#include "mainwindow.h"
#include "introwindow.h"
#include "gamewindow.h"
#include <QApplication>

//GameWindow now accessible to all classes
GameWindow * game;
int gameLevel=1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    introWindow w;
    w.setFixedSize(640,480);
    w.setWindowTitle("UCLA Game");
    w.show();
    return a.exec();
}
