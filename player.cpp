#include "player.h"

//Constructor
Player::Player(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    health = easyMaxHealth; //health assigned to 5 (default is easy difficulty)
}

//Destructor
Player::~Player() {
    //delete dynamically allocated data members
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

        const int STEP_SIZE = 2;  //originally set to 10

        //if only one key is pressed, simply move in direction
        if (keysPressed.size() == 1){
            switch (event->key()){
            case Qt::Key_D:
                setPos(x()+STEP_SIZE,y());
                std::cout << "Moving right \n";
                break;
            case Qt::Key_A:
                setPos(x()-STEP_SIZE,y());
                std::cout << "Moving left \n";
                break;
            case Qt::Key_W:
                setPos(x(),y()-STEP_SIZE);
                std::cout << "Moving up \n";
                break;
            case Qt::Key_S:
                setPos(x(),y()+STEP_SIZE);
                std::cout << "Moving down \n";
                break;
            }
        }

        //if two keys are being pressed at same time, move player diagonally
        if (keysPressed.size() > 1){

            // up right
            if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_D)){
                setPos(x()+STEP_SIZE,y()-STEP_SIZE);
            }
            // up left
            if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_A)){
                setPos(x()-STEP_SIZE,y()-STEP_SIZE);
            }
            // down right
            if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_D)){
                setPos(x()+STEP_SIZE,y()+STEP_SIZE);
            }
            // down left
            if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_A)){
                setPos(x()-STEP_SIZE,y()+STEP_SIZE);
            }
        }
}
