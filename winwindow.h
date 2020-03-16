#ifndef WINWINDOW_H
#define WINWINDOW_H
#include <mainwindow.h>
#include <QMediaPlayer>

class WinWindow : public QWidget
{
    Q_OBJECT

    public:
        WinWindow();
        ~WinWindow();
    private:
        QGridLayout* winWindowGridLayout = nullptr;
        QLabel* winTitle = nullptr;
        QLabel* creditsText = nullptr;
        QPushButton* quitButton = nullptr;
        QMediaPlayer* winWindowMusic = nullptr;
};

#endif // WINWINDOW_H
