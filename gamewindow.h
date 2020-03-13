#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <vector>
#include <iostream>
#include <mainwindow.h>
#include <player.h>
#include <Health.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPointF>
#include <QSet>
#include <zombie.h>
#include <geneblock.h>
#include <QObject>
#include <winwindow.h>
#include <QTimer>

extern int zombieContainerSize;

class GameWindow : public QGraphicsView
{
    Q_OBJECT
    public:
        GameWindow(bool isEasy, QWidget* parent = 0);
        ~GameWindow();
        void keyPressEvent(QKeyEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
        void addNumZombies(int num);

    public slots:
        void muteSound();
        void openWinWindow();

    private:
        QPushButton *muteSoundButton;
        QGraphicsScene* scene = nullptr;
        QImage* gameBackground = nullptr;
        Player* user = nullptr;
        GeneBlock* geneBlock = nullptr;
        Health* health = nullptr;
        QMediaPlayer* titleMusic = nullptr;
        Zombie* zombie = nullptr;
        std::vector<Zombie*> zombieContainer; //vector of ptrs to zombies

        WinWindow* winWindow = nullptr;
        bool isWinWindowOpen;
        void checkContainerSize();
};

#endif // GAMEWINDOW_H

