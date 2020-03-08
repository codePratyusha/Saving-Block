#include "Health.h"
#include <QFont>

//To Do: implement hard difficulty using conditionals
Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    health = 3; //is 3 by default

    //draw text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::lightGray);
    setFont(QFont("times", 20));
}

void Health::decrease() {
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth() {
    return health;
}
