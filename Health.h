#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem {
public:
    Health(QGraphicsItem* parent = 0);
    void decrease();
    int getHealth();
private:
    int health;
};

#endif // SCORE_H
