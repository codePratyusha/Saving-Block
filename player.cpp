#include "player.h"

//Constructor
Player::Player(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    health = easyMaxHealth; //health assigned to 5 (default is easy difficulty)
    xPrevious = pos().x();
    yPrevious = pos().y();

    yerbaDistance = 0;
    range = 50;
    // connect a timer to move()
//    int MOVE_EVERY = 1000 / game->30; //fps = 30
//    QTimer * timer = new QTimer(this);
//    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
//    timer->start(MOVE_EVERY);
}

//Destructor
Player::~Player() {
    //delete dynamically allocated data members
}

void Player::updateHealth() {
    //increment or decrement health
}

int Player::getHealth() {
    return health;
}

//Moves player with WASD keys
void Player::keyPressEvent(QKeyEvent* event) {
    if (
            event->key() == Qt::Key_W ||
            event->key() == Qt::Key_A ||
            event->key() == Qt::Key_S ||
            event->key() == Qt::Key_D
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

    //if two keys are being pressed at same time, move player diagonally
        if (keysPressed.size() > 1){

            // up right
            if (keysPressed.contains(Qt::Key_O)){
                setPos(x()+STEP_SIZE,y()-STEP_SIZE);
            }
            // up left
            if (keysPressed.contains(Qt::Key_I)){
                setPos(x()-STEP_SIZE,y()-STEP_SIZE);
            }
            // down right
            if (keysPressed.contains(Qt::Key_L)){
                setPos(x()+STEP_SIZE,y()+STEP_SIZE);
            }
            // down left
            if (keysPressed.contains(Qt::Key_J)){
                setPos(x()-STEP_SIZE,y()+STEP_SIZE);
            }
        }

    xPrevious = pos().x();
    yPrevious = pos().y();
}

void Player::keyReleaseEvent(QKeyEvent *event){
    keysPressed.remove(event->key());
}

void Player::shootYerba(QKeyEvent *event) {
    if (event->key() == Qt::Key_W) {
        yerba = new YerbaItem();
        yerbaDistance += 10;
        // delete the arrow if its past its range
        if (yerbaDistance > range){
//            game->scene->removeItem(this);
//            delete this;
//            return;
        }
    }
}
