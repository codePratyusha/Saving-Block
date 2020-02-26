#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent) : QGraphicsView(parent)
{
    //Creating scene
    scene = new QGraphicsScene(this);

    //Creating Player object
    QPixmap userIcon(":/game/Stressed_Bruin_Protagonist.png");
    user = new Player(userIcon);
//    user->setPos(400, 250);          //should be middle of game window
    scene->addItem(user);            //adding player to scene

    //Creating music
    titleMusic= new QMediaPlayer(this);
    titleMusic->setMedia(QUrl("qrc:/new/music/Crash Bandicoot Theme.mp3"));
    titleMusic->play();
    connect(titleMusic, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(replayMusic(QMediaPlayer::State)));

    //Customizing scene
    scene->setSceneRect(0, 0, width(), height());  //set scene background
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene);                           //setting scene
    setSceneRect(scene->sceneRect());

    //disabling scrollbars for Game Window class
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameWindow::~GameWindow() {
    //free memory
}

//Move player using WASD keys
void GameWindow::keyPressEvent(QKeyEvent* event) {
     user->keyPressEvent(event);
     user->keyReleaseEvent(event);
}

void endGame() {
//    if (user->getHealth() < 0) {
//        std::cout << "Player is dead \n";
//    }
}
