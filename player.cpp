#include "player.h"
#include "bullet.h"

//Constructor
Player::Player(bool isE, QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    xPrevious = pos().x();
    yPrevious = pos().y();
    isEasy = isE;
}

//Destructor
Player::~Player() {
    delete shootMusic;
}

//Moves player with WASD keys
void Player::keyPressEvent(QKeyEvent* event) {
    if (
            event->key() == Qt::Key_W ||
            event->key() == Qt::Key_A ||
            event->key() == Qt::Key_S ||
            event->key() == Qt::Key_D ||
            event-> key() == Qt::Key_O||
            event-> key() == Qt::Key_I||
            event-> key() == Qt::Key_L||
            event-> key() == Qt::Key_J
        )
    {
        keysPressed.insert(event->key());
    }

    //if only one key is pressed, simply move in direction
    if (keysPressed.size() == 1){
        switch (event->key()){
        case Qt::Key_D:
            setPos(x()+STEP_SIZE,y());
            break;
        case Qt::Key_A:
            setPos(x()-STEP_SIZE,y());
            break;
        case Qt::Key_W:
            setPos(x(),y()-STEP_SIZE);
            break;
        case Qt::Key_S:
            setPos(x(),y()+STEP_SIZE);
            break;
        case Qt::Key_O:
            setPos(x()+STEP_SIZE,y()-STEP_SIZE);
            break;
        case Qt::Key_I:
            setPos(x()-STEP_SIZE,y()-STEP_SIZE);
            break;
        case Qt::Key_L:
            setPos(x()+STEP_SIZE,y()+STEP_SIZE);
            break;
        case Qt::Key_J:
            setPos(x()-STEP_SIZE,y()+STEP_SIZE);
            break;
        }
    }

        else if (event->key() == Qt::Key_Space)
        {
            Bullet * bullet = new Bullet();
            // bullet->setPos(x(),y());
            bullet->setPos(mapToScene(50,-5));
            bullet->setRotation(rotation());
            //bullet->setRotation(-40);
            scene()->addItem(bullet);
        }

    xPrevious = pos().x();
    yPrevious = pos().y();
}

void Player::keyReleaseEvent(QKeyEvent *event){
    keysPressed.remove(event->key());
}

void Player::setAngle(double a)
{
    angle = a;
}

double Player::getAngle()
{
    return angle;
}

QPointF Player::getOrigin(){

    return mapToScene(transformOriginPoint());
}

