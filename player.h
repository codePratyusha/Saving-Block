#ifndef PLAYER_H
#define PLAYER_H
#include <mainwindow.h>
#include <introwindow.h>

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QSet>
#include <QPointF>


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        Player(QPixmap& pixmap);
        ~Player();

        int updateHealth();
        void keyPressEvent(QKeyEvent* event);
    public slots:
//        void decreaseHealth();
    private:
        const int easyMaxHealth = 5;
        const int hardMaxHealth = 2;
        int health;
        QSet<int> keysPressed;
};

#endif // PLAYER_H
