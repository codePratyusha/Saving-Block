#ifndef PLAYER_H
#define PLAYER_H
#include <mainwindow.h>

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>
#include <QSet>
#include <QPointF>


class Player : public QObject, public QGraphicsPixmapItem
{
    public:
        Player(QPixmap& pixmap);
        ~Player();

        int updateHealth();
        void keyPressEvent(QKeyEvent* event);
        void keyReleaseEvent(QKeyEvent* event);

        void setAngle(double a);
        double getAngle();
        int getHealth();


        QPointF getOrigin();
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
        double angle;
};

#endif // PLAYER_H
