#include "gamewindow.h"
#include "zombie.h"
#include <vector>
#include <iostream> //FOR DEBUG ONLY
#include <stdlib.h>

int zombieContainerSize = 5;    //hard-coding zombie container size as 5
bool isGeneHit = false;   //setting gene status

GameWindow::GameWindow(bool isEasy, QWidget* parent) : QGraphicsView(parent)
{
    isWinWindowOpen = false;
    //isLoseWindowOpen = false;

    //Creating scene
    scene = new QGraphicsScene(this);

    //Creating Player object
    QPixmap userIcon(":/images/sad_bruin.png");     //create image for Player object
    user = new Player(userIcon);                    //initialize Player object to image
    user->setPos(280, 40);                         //choose arbitrary position for player
    user->setScale(1.1);
    scene->addItem(user);                           //add player to scene

    //Creating Gene Block object
    QPixmap geneBlockIcon(":/images/daddy_block.png");
    geneBlock = new GeneBlock(isEasy, geneBlockIcon);
    geneBlock->setScale(0.35);
    geneBlock->setPos(300,240);
    scene->addItem(geneBlock);

    //Adding zombies to scene
    addNumZombies(5);

    //std::cout<< "zombiecontainersize1: " << zombieContainer.size()<< std::endl;  //DEBUG
    //    For each level, set an initial number of zombies available and visible

    //Creating mainTimer that keeps track of when gene is hit

    //QTimer *main_timer = new QTimer(this);
    main_timer->singleShot(1000, this, SLOT(checkGeneStatus()));
    //connect(main_timer, SIGNAL(timeout()), this, SLOT(checkGeneStatus()));
    //main_timer->start(1000);



    //Creating music and mute button
    titleMusic= new QMediaPlayer(this);
    titleMusic->setMedia(QUrl("qrc:/music/Crash Bandicoot Theme.mp3"));
    titleMusic->play();
    connect(titleMusic, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(replayMusic(QMediaPlayer::State)));
    QPushButton *muteSoundButton = new QPushButton(tr("Mute"));
    muteSoundButton->setFixedSize(60,60);

    QGridLayout *button_layout = new QGridLayout;
    button_layout->addWidget(muteSoundButton, 0,0, Qt::AlignTop);
    setLayout(button_layout);
    connect(muteSoundButton, SIGNAL(clicked()),this, SLOT(muteSound()));

    //Customizing scene
    scene->setSceneRect(0, 0, width(), height());               //set scene background
    gameBackground = new QImage(":/images/Tiled Floor.png");    //set scene background to given image
    QBrush bg_brush(*gameBackground);

    //Adding health bar to scene
    //health = geneBlock->returnGeneBlockHealth();
    //health->setPos(0, -70); //setting position at top left
    //scene->addItem(health);

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
    delete muteSoundButton;
    delete scene;
    delete gameBackground;
    delete geneBlock;
    delete user;
    delete health;
    delete titleMusic;
    delete zombie;

    for(size_t i=0; i< zombieContainer.size(); i++){
        delete zombieContainer[i];
    }

}

//Move player using WASD keys
void GameWindow::keyPressEvent(QKeyEvent* event) {
    user->keyPressEvent(event);
    user->keyReleaseEvent(event);

    //Check container size
    checkContainerSize();
}

void GameWindow::mouseMoveEvent(QMouseEvent *event){
    QPixmap userIcon(":/images/sad_bruin.png");
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

//Opens Win Window if all zombies are dead
void GameWindow::openWinWindow() {
    winWindow = new WinWindow();
    winWindow->setFixedSize(720, 480);
    winWindow->setWindowTitle("Congrats!");
    this->close();
    titleMusic->stop();
    winWindow->show();
}

//Opens Lose Window if Gene has been hit
//void GameWindow::openLoseWindow(){
//    loseWindow = new LoseWindow();
//    loseWindow->setFixedSize(720, 480);
//    loseWindow->setWindowTitle("Oh no!");
//    this->close();
//    titleMusic->stop();
//    loseWindow->show();
//}

//Check size of zombie container
void GameWindow::checkContainerSize() {
    std::cout << "ran" << std::endl;
    if (zombieContainerSize <= 0) {
        isWinWindowOpen = true;
        openWinWindow();
    }
}

//Checks status of gene
void GameWindow::checkGeneStatus(){
    std::cout << "ran2" << std::endl;
    if (isGeneHit==true) {
       losewindow = new LoseWindow();
       losewindow->setFixedSize(720, 480);
       losewindow->setWindowTitle("Oh no!");
        this->close();
        titleMusic->stop();
        losewindow->show();
    }

    else{
        this->main_timer->singleShot(1000,this,SLOT(checkGeneStatus()));
    }

}

//Adds given number of zombies to the GameWindow
void GameWindow::addNumZombies(int num){
    //Create zombie object
    QPixmap zombieIcon(":/images/Calpirg_Zombie.png");

    //Push zombies onto vector
    for(int i = 0; i < num; ++i){
        zombie = new Zombie(zombieIcon);
        GameWindow::zombieContainer.push_back(zombie);
    }
    //set zombie represenations of the zombies in the container
    for (size_t i=0; i < zombieContainer.size(); i++){


       //initialize x and y pos
        double rand_x=1;
        double rand_y=1;

        rand_x=(rand() % 30 + 0);   //zombieMap x indices range from 0-30
        rand_y= (rand() % 25 + 0);    //zombieMap y indices range from 0-25

        double XYrand_x = zombieContainer[i]->zombieMapToXY(rand_x); //returns coords in XY-plane for zombie
        double XYrand_y = zombieContainer[i]->zombieMapToXY(rand_y);

        //zombieContainer[i]->setPos(rand_x, rand_y);
        zombieContainer[i]->setX(XYrand_x);
        zombieContainer[i]->setY(XYrand_y);

        //  std::cout <<"x: " << rand_x << " y: " << rand_y << std::endl; //DEBUG
        zombieContainer[i]->setScale(0.35);

        zombieContainer[i]->setPathToGene(rand_x,rand_y, 15, 12);   //Gene is located at (r,c)=(15,12)
        scene->addItem(zombieContainer[i]);
    }
}

//Mute audio of Game Window
void GameWindow::muteSound(){
    titleMusic->stop();
}

