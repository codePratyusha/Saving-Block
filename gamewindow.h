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

class GameWindow : public QGraphicsView
{
    Q_OBJECT

    public:
        GameWindow(QWidget* parent = 0);
        ~GameWindow();
        void keyPressEvent(QKeyEvent* event);
        void mouseMoveEvent(QMouseEvent* event);

        void addNumZombies(int num);

    public slots:

    private:
        QGraphicsScene* scene = nullptr;
        QImage* gameBackground = nullptr;
        Player* user = nullptr;
        Health* health = nullptr;
        QMediaPlayer* titleMusic = nullptr;
        Zombie* zombie = nullptr;
        std::vector<Zombie*> zombieContainer; //vector of ptrs to zombies

        void updateHealth();    //if player is damaged, decrement health by 1
        void endGame();         //if player health is 0, then end game
};

#endif // GAMEWINDOW_H



//class GameWindow : public QGraphicsView
//{
//    Q_OBJECT

//    public:
//        GameWindow(QWidget* parent = 0);
//        ~GameWindow();

//        //Accessors
//        //void getZombie();

//        void keyPressEvent(QKeyEvent* event);
//        bool isBlocked();       //returns true if player or zombie does
//        void addNumZombies(int num);  //adds given number of zombies

//        Player* user = nullptr;

//    private:
//        QGraphicsScene* scene = nullptr;
//        QImage* gameBackground = nullptr;
//        QMediaPlayer* titleMusic = nullptr;
//        Health* health = nullptr;
//        Zombie* zombie = nullptr;
//        std::vector<Zombie*> zombieContainer; //vector of ptrs to zombies

//        int gameMap[640][640];

//        void updateHealth();    //if player is damaged, decrement health by 1
//        void endGame();         //if player health is 0, then end game

//};
