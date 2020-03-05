#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent) : QGraphicsView(parent)
{
    //Creating scene
    scene = new QGraphicsScene(this);

    //Creating Player object
    QPixmap userIcon(":/images/Stressed_Bruin_Protagonist.png");    //create image for Player object
    user = new Player(userIcon);                                    //initialize Player object to image
    user->setPos(150, 150);                                         //set position
    scene->addItem(user);                                           //add player to scene

    //Creating Gene Block object
    QPixmap geneBlockIcon(":/images/gene_block.png");
    geneBlock = new GeneBlock(geneBlockIcon);
    geneBlock->setPos(285, 230);                                         //set position
    scene->addItem(geneBlock);

    //Creating music
    titleMusic= new QMediaPlayer(this);
    titleMusic->setMedia(QUrl("qrc:/new/music/Crash Bandicoot Theme.mp3"));
    titleMusic->play();
    connect(titleMusic, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(replayMusic(QMediaPlayer::State)));

    //Customizing scene
    scene->setSceneRect(0, 0, width(), height());               //set scene background
    gameBackground = new QImage(":/images/Tiled Floor.png");    //set scene background to given image
    QBrush bg_brush(*gameBackground);

    //Adding health bar to scene
    health = new Health();
    health->setPos(15, 15);
    scene->addItem(health);

    scene->setBackgroundBrush(bg_brush);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene);                           //setting scene
    setSceneRect(scene->sceneRect());
    setMouseTracking(true);

    //disabling scrollbars for Game Window class
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameWindow::~GameWindow() {
    delete scene;
    delete gameBackground;
    delete user;
    delete health;
    delete titleMusic;
}

//Move player using WASD keys
void GameWindow::keyPressEvent(QKeyEvent* event) {
     user->keyPressEvent(event);
     user->keyReleaseEvent(event);
}

void GameWindow::mouseMoveEvent(QMouseEvent *event){
    QPixmap userIcon(":/images/Stressed_Bruin_Protagonist.png");
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
