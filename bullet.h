#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
    int getDamage();
    void setDamage(int d);
    void setRange(int r);

private:
    int damage;
    int distance_traveled;

    int range;

};

#endif // BULLET_H
