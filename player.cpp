#include "player.h"

Player::Player(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    if (isEasy == true) {       //if easy difficulty is selected
        health = easyMaxHealth; //health assigned to 5
    } else {                    //if hard difficult is selected
        health = hardMaxHealth;  //health assigned to 2
    }
}

Player::~Player() {
    //delete objects
}


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

        const int STEP_SIZE = 2;  //originally set to 10

//        //if only one key is pressed, simply move in direction
//        if (keysPressed.size() == 1){
//            switch (event->key()){
//            case Qt::Key_D:
//                setPos(x()+STEP_SIZE,y());
//                break;
//            case Qt::Key_A:
//                setPos(x()-STEP_SIZE,y());
//                break;
//            case Qt::Key_W:
//                setPos(x(),y()-STEP_SIZE);
//                break;
//            case Qt::Key_S:
//                setPos(x(),y()+STEP_SIZE);
//                break;
//            }
//        }

//        //if two keys are being pressed at same time, move player diagonally
//        if (keysPressed.size() > 1){

//            // up right
//            if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_D)){
//                setPos(x()+STEP_SIZE,y()-STEP_SIZE);
//            }
//            // up left
//            if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_A)){
//                setPos(x()-STEP_SIZE,y()-STEP_SIZE);
//            }
//            // down right
//            if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_D)){
//                setPos(x()+STEP_SIZE,y()+STEP_SIZE);
//            }
//            // down left
//            if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_A)){
//                setPos(x()-STEP_SIZE,y()+STEP_SIZE);
//            }
//        }
}
