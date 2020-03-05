#ifndef WINWINDOW_H
#define WINWINDOW_H
#include <mainwindow.h>


class WinWindow :  public QWidget
{
    Q_OBJECT

    public:
        WinWindow();
        ~WinWindow();
    public slots:

    private:
        QLabel* youWinText = nullptr;
        QGridLayout* winWindowGridLayout = nullptr;
};

#endif // WINWINDOW_H
