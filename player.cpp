#include "player.h"
#include "bullet.h"

//Constructor
Player::Player(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    xPrevious = pos().x();
    yPrevious = pos().y();
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

        else if (event->key() == Qt::Key_Space)
        {
//            //Creating music and mute button
//            shootMusic= new QMediaPlayer(this);
//            shootMusic->setMedia(QUrl("qrc:/music/Minecraft Pick Item [Sound Effect].mp3"));
//            shootMusic->play();
//            connect(shootMusic, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(replayMusic(QMediaPlayer::State)));

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

