#ifndef WINWINDOW_H
#define WINWINDOW_H
#include <mainwindow.h>

class WinWindow : public QWidget
{
    Q_OBJECT

    public:
        WinWindow();
        ~WinWindow();
    private:
        QGridLayout* winWindowGridLayout = nullptr;
        QLabel* winTitle = nullptr;
        QPushButton* quitButton = nullptr;
};

#endif // WINWINDOW_H
