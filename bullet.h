#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QList>
#include <QMediaPlayer>



class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    //Constructs bullet object, initializes range, damage, distance travelled
    //@param none

public slots:
    void move();
    //Moves bullet, also deletes bullet from scene if collides with zombies
    //@param none

    int getDamage();
    //Accessor function for getting damage
    //@param none

    void setDamage(int d);
    //Setter function for setting damage
    //@param 'd' of type int, represents damage

    void setRange(int r);
    //Setter function for setting range of bullet
    //@param 'r' of type int, represents range

private:
    int damage;
    int distance_traveled;
    int range;
};

#endif // BULLET_H
