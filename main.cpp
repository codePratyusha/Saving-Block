#include "mainwindow.h"
#include "introwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    introWindow w;
    w.setFixedSize(800,500);
    w.setWindowTitle("UCLA Game");
    w.show();
    return a.exec();
}
