#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //Constructor for main window screen
    //@param none

    ~MainWindow();
    //Deallocates data members
    //@param none
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
