#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAbstractButton>
#include <QHBoxLayout>
#include <QStackedLayout>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //**TODO: a function that returns a bool value representing the level selected**//
public slots:
    void selectEasy();
    void selectHard();
    void goToGameWindow();
    void goToInstrWindow();
    void goToStartScreen();
private:
    QPushButton *easyButton;
    QPushButton *hardButton;
    QStackedWidget *_stackedWidget;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
