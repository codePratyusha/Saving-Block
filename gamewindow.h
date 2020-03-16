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
#include <losewindow.h>
#include <QTimer>

extern int zombieContainerSize;
extern bool isGeneHit;

class GameWindow : public QGraphicsView
{
    Q_OBJECT
public:
    GameWindow(bool isEasy, QWidget* parent = 0);
    //Creates game window object where everything is played from
    //@param difficulty setting and parent

    ~GameWindow();
    //Deallocates class data members
    //@param none

    void keyPressEvent(QKeyEvent* event);
    //Detects if player presses keys, responds depending on what key is pressed
    //@param 'event' as type QKeyEvent*

    void mouseMoveEvent(QMouseEvent* event);
    //Moves player if mouse moved, responds depending on mouse event
    //@param 'event' as type QKeyEvent*

    void addNumZombies(int num);
    //Adds number of zombies to scene
    //@param 'num' as type int

public slots:
    void muteSound();
    //Mutes game window audio
    //@param none

    void openWinWindow();
    //Opens win window when all zombies are dead
    //@param none
    void checkGeneStatus();
    //Checks if gene is dead or alive
    //@param none

private:
    QPushButton *muteSoundButton;
    QTimer *main_timer;
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
    //Checks size of zombie container when called
    //@param none

    LoseWindow* losewindow = nullptr;


};

#endif // GAMEWINDOW_H

