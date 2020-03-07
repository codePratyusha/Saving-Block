#ifndef WINWINDOW_H
#define WINWINDOW_H
#include <mainwindow.h>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

class WinWindow : public QGraphicsView
{
    Q_OBJECT

    public:
        WinWindow(QWidget* parent = 0);
        ~WinWindow();
    public slots:

    private:
        QLabel* youWinText = nullptr;
        QGraphicsScene* winScene = nullptr;
        QImage* winBackground = nullptr;

        void animateGeneBlock();
        void animateYerba();
};

#endif // WINWINDOW_H
