#include "Health.h"
#include <QFont>

Health::Health(bool isEasyDifficulty) {
    if (isEasyDifficulty == true) {    //if easy difficulty
        health = 5;
    } else {    //if hard difficulty
        health = 2;
    }

    //set text
    setPlainText(QString("Gene Block Health: ") + QString::number(health));
    setDefaultTextColor(Qt::lightGray);
    setFont(QFont("times", 20));
}

void Health::decrease() {
    health--;
    setPlainText(QString("Gene Block Health: ") + QString::number(health));
}

int Health::getHealth() {
    return health;
}
