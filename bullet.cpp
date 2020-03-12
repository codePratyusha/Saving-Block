#include "bullet.h"
#include "zombie.h"
#include <QTimer>
#include <QList>
#include <qmath.h>
#include <QGraphicsScene>

Bullet::Bullet():QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/yerbe_mate.png").scaled(50, 50, Qt::KeepAspectRatio));

    distance_traveled = 0;
    range = 650;
    damage = 50;

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    //if bullet hits zombies, delete both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Zombie))
        {
            Zombie * attacked_object = dynamic_cast<Zombie *>(colliding_items[i]);
            attacked_object->decreaseHealth(damage);
            //remove bullet every time
            //scene()->removeItem(this);
            //delete this;
            //check if zombie dead
            if (attacked_object->getHealth() <= 0)
            {
                scene()->removeItem(attacked_object);
                scene()->removeItem(this);
                //delete attacked_object;
                //delete attacked_object;   //ADDED
                //attacked_object = nullptr;
                delete this;
                return;
            }
            else
            {
                scene()->removeItem(this);
                delete this;
                return;
            }

        }
    }

    int STEP_SIZE = 45;

    // find the dx and dy
    int dx = STEP_SIZE * qCos(qDegreesToRadians(rotation()));
    int dy = STEP_SIZE * qSin(qDegreesToRadians(rotation()));

    setX(x()+dx);
    setY(y()+dy);

    distance_traveled += STEP_SIZE;

    // delete the arrow if its past its range
    if (distance_traveled > range){
        scene()->removeItem(this);
        delete this;
        return;
    }

    // delete the arrow if its out of bounds
    double pos_x = scenePos().x();
    double pos_y = scenePos().y();
    double scene_width = this->scene()->sceneRect().width();
    double scene_height = scene()->sceneRect().height();
    if (pos_x > scene_width || pos_x < 0 || pos_y > scene_height || pos_y < 0){
        scene()->removeItem(this);
        delete this;
        return;
    }
}

int Bullet::getDamage() {
    return damage;
}

void Bullet::setDamage(int val){
    damage = val;
}

void Bullet::setRange(int n){
    range = n;
}
