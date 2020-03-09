#include "gamewindow.h"
#include "zombie.h"
#include <vector>
#include <iostream> //FOR DEBUG ONLY
#include <stdlib.h>

extern int gameLevel;

GameWindow::GameWindow(bool isEasy, QWidget* parent) : QGraphicsView(parent)
{
    //Creating scene
    scene = new QGraphicsScene(this);

    //Creating Player object
    QPixmap userIcon(":/images/sad_bruin.png");    //create image for Player object
    user = new Player(userIcon);                                    //initialize Player object to image
    user->setPos(150, 150);                                         //set position
    user->setScale(1.1);
    scene->addItem(user);                                           //add player to scene

    //Creating Gene Block object
        QPixmap geneBlockIcon(":/images/daddy_block.png");
        geneBlock = new GeneBlock(isEasy, geneBlockIcon);
        geneBlock->setPos(240,300);
        //geneBlock->setPos((width() / 2) - 35, (height() / 2));  //setting position in middle of board
        scene->addItem(geneBlock);


     //Creating zombie object
        QPixmap zombieIcon(":/images/zombieRight.png");
        addNumZombies(3);

     //std::cout<< "zombiecontainersize1: " << zombieContainer.size()<< std::endl;  //DEBUG
    //    For each level, set an initial number of zombies available and visible

    //    Vector of ptrs to Zombies initialized

//            //Level 1 - has 2 zombies
//            if(gameLevel==1){
//                addNumZombies(3);
//            }
//            else if(gameLevel==2){
//                addNumZombies(4);
//            }
//            else if(gameLevel==3){
//                addNumZombies(6);
//            }
//            else if(gameLevel==4){
//               addNumZombies(10);
//            }



    //Creating music and mute button
    titleMusic= new QMediaPlayer(this);
    titleMusic->setMedia(QUrl("qrc:/new/music/Crash Bandicoot Theme.mp3"));
    titleMusic->play();
    connect(titleMusic, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(replayMusic(QMediaPlayer::State)));
    QPushButton *muteSoundButton = new QPushButton(tr("Mute"));
    muteSoundButton->setFixedSize(60,60);

    QGridLayout *button_layout = new QGridLayout;
    //scene->addWidget(muteSoundButton);
    button_layout->addWidget(muteSoundButton, 0,2,1,1, Qt::AlignTop);
    setLayout(button_layout);

    //muteSoundButton->setLayout(button_layout);
   // muteSoundButton->set
    //scene->addWidget(muteSoundButton)
    //muteSoundButton->setLayout()
    //scene->addWidget(muteSoundButton); //addWidget(muteSoundButton, 1, 1);

    //Customizing scene
    scene->setSceneRect(0, 0, width(), height());               //set scene background
    gameBackground = new QImage(":/images/Tiled Floor.png");    //set scene background to given image
    QBrush bg_brush(*gameBackground);

    //Adding health bar to scene
        health = geneBlock->returnGeneBlockHealth();
        health->setPos(20, -55); //setting position at top left
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



//Adds given number of zombies to the GameWindow
void GameWindow::addNumZombies(int num){

    QPixmap zombieIcon(":/images/zombieRight.png");

    for(int i=0; i<num; i++){
        zombie = new Zombie(zombieIcon);
        GameWindow::zombieContainer.push_back(zombie);
            }
    //set zombie represenations of the zombies in the container
    for (size_t i=0; i < zombieContainer.size(); i++){
        //get random position for the zombie


        double rand_x = (rand() % 30 + 0);   //zombieMap x indices range from 0-30
        double rand_y = (rand() % 25 + 0);    //zombieMap y indices range from 0-25

        double XYrand_x = zombieContainer[i]->zombieMapToXY(rand_x); //returns coords in XY-plane for zombie
        double XYrand_y = zombieContainer[i]->zombieMapToXY(rand_y);

        //zombieContainer[i]->setPos(rand_x, rand_y);
        zombieContainer[i]->setX(XYrand_x);
        zombieContainer[i]->setY(XYrand_y);

      //  std::cout <<"x: " << rand_x << " y: " << rand_y << std::endl; //DEBUG
        zombieContainer[i]->setScale(0.2);

        zombieContainer[i]->setPathToGene(rand_x,rand_y, 15, 12);   //Gene is located at (r,c)=(15,12)
        scene->addItem(zombieContainer[i]);


    }
}




