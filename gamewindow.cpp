#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent) : QGraphicsView(parent)
{
    //Creating scene
    scene = new QGraphicsScene(); //(this)

    //Creating Player object
    QPixmap userIcon(":/new/images/Stressed_Bruin_Protagonist.png");
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
    setMouseTracking(true);

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

void GameWindow::mouseMoveEvent(QMouseEvent *event){
    QPixmap userIcon(":/new/images/Stressed_Bruin_Protagonist.png");
    user->setTransformOriginPoint(userIcon.rect().center());
    //rotate the player an angle between the player's position and the mouse position
    QPointF pt1(user->getOrigin());
    QPointF pt2(event->pos());
    QLineF line(pt1,pt2);
    double angle = -1 * line.angle();

    // angle of a line is measured COUNTER clock wise
    // rotation of scene items are measured CLOCK wise, therefore we must negate the line angle
    user->setRotation(angle);
    user->setAngle(angle); // player's angle property is used to determine rotation of spawned arrows
}
