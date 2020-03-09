#ifndef LOSEWINDOW_H
#define LOSEWINDOW_H
#include <mainwindow.h>
#include <QMovie>
#include <QRectF>
#include <QMediaPlayer>

class LoseWindow : public QWidget
{
    Q_OBJECT

    public:
        LoseWindow();
        ~LoseWindow();
    private:
        QGridLayout* loseWindowGridLayout = nullptr;
        QLabel* loseTitle = nullptr;
        QPushButton* quitButton = nullptr;

        QMovie* rain1 = nullptr;
        QLabel* rainLabel1 = nullptr;

        QMovie* rain2 = nullptr;
        QLabel* rainLabel2 = nullptr;

        QMovie* rain3 = nullptr;
        QLabel* rainLabel3 = nullptr;

        QMediaPlayer* lostWindowMusic = nullptr;
};

#endif // LOSEWINDOW_H
