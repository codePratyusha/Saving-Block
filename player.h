#ifndef PLAYER_H
#define PLAYER_H
#include <mainwindow.h>
//#include <gamewindow.h>
#include <yerbaitem.h>

#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QSet>
#include <QPointF>


class Player : public QObject, public QGraphicsPixmapItem
{
    public:
        Player(QPixmap& pixmap);
        ~Player();

        void updateHealth();
        int getHealth();
        void keyPressEvent(QKeyEvent* event);
        void keyReleaseEvent(QKeyEvent* event);
    public slots:
//        void decreaseHealth();
    private:
        QSet<int> keysPressed;
        const int easyMaxHealth = 5;    //constant health, player health can never exceed value
        const int hardMaxHealth = 2;    //constant health, player health can never exceed value
        const int STEP_SIZE = 20;       //how much player moves
        int health;                     //health that is decremented
        int xPrevious;
        int yPrevious;

        YerbaItem* yerba = nullptr;
        void shootYerba(QKeyEvent* event);
        int yerbaDistance;
        int range;
};

#endif // PLAYER_H
