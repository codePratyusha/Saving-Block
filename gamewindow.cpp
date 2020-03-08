#include "gamewindow.h"
#include "zombie.h"
#include <vector>
#include <iostream> //FOR DEBUG ONLY
#include <stdlib.h>

extern int gameLevel;

GameWindow::GameWindow(QWidget* parent) : QGraphicsView(parent)
{
    //Creating scene
    scene = new QGraphicsScene(this);

    //Creating Player object
    QPixmap userIcon(":/images/Stressed_Bruin_Protagonist.png");    //create image for Player object
    user = new Player(userIcon);                                    //initialize Player object to image
    user->setPos(290, 290);                                         //set position
    user->setScale(1.1);
    scene->addItem(user);                                           //add player to scene

    QPixmap zombieIcon(":/images/zombieRight.png");

     //std::cout<< "zombiecontainersize1: " << zombieContainer.size()<< std::endl;  //DEBUG
    //    For each level, set an initial number of zombies available and visible

    //    Vector of ptrs to Zombies initialized

            //Level 1 - has 2 zombies
            if(gameLevel==1){
                addNumZombies(3);
            }
            else if(gameLevel==2){
                addNumZombies(4);
            }
            else if(gameLevel==3){
                addNumZombies(6);
            }
            else if(gameLevel==4){
               addNumZombies(10);
            }

           //zombie->setPos(10, 490);  //**TODO: Set random position for this bounds: top left (10,0), top right (580,0), bottom left (10,490), bottom right***//
           // std::cout<< "zombiecontainersize2: " << zombieContainer.size()<< std::endl; //DEBUG


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

//        int r = rand()% 4 + 1;
//        if(r==1){
//            zombieContainer[i]->setDir('R');
//        }else if(r==2){
//            zombieContainer[i]->setDir('L');
//        }else if(r==3){
//            zombieContainer[i]->setDir('U');
//        }else if(r==4){
//            zombieContainer[i]->setDir('D');
//        }

        zombieContainer[i]->setPathToGene(rand_x,rand_y, 15, 12);   //Gene is located at (r,c)=(15,12)
        scene->addItem(zombieContainer[i]);

        //scene->addItem(zombieContainer[i]);

    }
}

     //zombie->findPlayer();












//GameWindow::GameWindow(QWidget* parent) : QGraphicsView(parent)
//{
//    //Creating scene
//    scene = new QGraphicsScene(this);

//    //Creating Player object
//    QPixmap userIcon(":/images/Stressed_Bruin_Protagonist.png");
//    user = new Player(userIcon);
//    user->setPos(290, 290);
//    user->setScale(1.1);
//    scene->addItem(user);            //adding player to scene


//    //A vector of type Zombie* is a public member of GameWindow
//    //Initialize the zombies in the zombieContainer by adding new zombies to it depending on the level

//    //QPixmap zombieIcon(":/images/zombieRight.png");

//  //std::cout<< "zombiecontainersize1: " << zombieContainer.size()<< std::endl;  //DEBUG
//    //For each level, set an initial number of zombies available and visible

//    //Vector of ptrs to Zombies initialized

//        //Level 1 - has 2 zombies
//        if(gameLevel==1){
//            addNumZombies(2);
//        }
//        else if(gameLevel==2){
//            addNumZombies(4);
//        }
//        else if(gameLevel==3){
//            addNumZombies(6);
//        }
//        else if(gameLevel==4){
//           addNumZombies(10);
//        }

//       //zombie->setPos(10, 490);  //**TODO: Set random position for this bounds: top left (10,0), top right (580,0), bottom left (10,490), bottom right***//
//      //zombie->setScale(0.17); //scale the zombie
//      // scene->addItem(zombie);
//       // std::cout<< "zombiecontainersize2: " << zombieContainer.size()<< std::endl; //DEBUG





 //Creating Zombie object
//  QPixmap zombieIcon(":/images/zombieRight.png");
//   zombie = new Zombie(zombieIcon);
//   zombie->setPos(10, 490);  //**TODO: Set random position for this bounds: top left (10,0), top right (580,0), bottom left (10,490), bottom right***//
//   zombie->setScale(0.17); //scale the zombie
//   scene->addItem(zombie);





//    //Creating music
//    titleMusic= new QMediaPlayer(this);
//    titleMusic->setMedia(QUrl("qrc:/new/music/Crash Bandicoot Theme.mp3"));
//    titleMusic->play();
//    connect(titleMusic, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(replayMusic(QMediaPlayer::State)));

//    //Customizing scene
//    scene->setSceneRect(0, 0, width(), height());               //set scene background
//    gameBackground = new QImage(":/images/Tiled Floor.png");    //set scene background to given image
//    QBrush bg_brush(*gameBackground);
//    health = new Health();
//    health->setPos(15, 15);
//    scene->addItem(health);

//    scene->setBackgroundBrush(bg_brush);
//    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
//    setScene(scene);                           //setting scene
//    setSceneRect(scene->sceneRect());

//    //disabling scrollbars for Game Window class
//    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



//}

//GameWindow::~GameWindow() {
//    delete scene;
//    delete gameBackground;
//    delete user;
//    delete health;
//    delete titleMusic;

//}

//Move player using WASD keys
//void GameWindow::keyPressEvent(QKeyEvent* event) {
//     user->keyPressEvent(event);
//     user->keyReleaseEvent(event);
//}


//Adds given number of zombies to the GameWindow
//void GameWindow::addNumZombies(int num){

//    QPixmap zombieIcon(":/images/zombieRight.png");

//    for(int i=0; i<num; i++){
//        zombie = new Zombie(zombieIcon);
//        GameWindow::zombieContainer.push_back(zombie);
//            }
//    //set zombie represenations of the zombies in the container
//    for (size_t i=0; i < zombieContainer.size(); i++){
//        //get random position for the zombie


//        int rand_x = (rand() % 570 + 10);
//        int rand_y = (rand() % 490 + 0);


//        //then check if the coordinate is blocked by another zombie, if not then return true for isPosValid()? - DEBUG ZOMBIES HITTING EACH OTHER //**TODO**//
//        //if isPosValid()=1, set the zombieContainer[i] to that position
//        //invalidate that position on the gameMap array and the surrounding areas around it (depending on the size of the zombie -- X coordinate + upto +-30 squares around it, Y is +-70 from position )

//        zombieContainer[i]->setPos(rand_x, rand_y);
//        //zombieContainer[i]->
//      //  std::cout <<"x: " << rand_x << " y: " << rand_y << std::endl; //DEBUG
//        zombieContainer[i]->setScale(0.18);
//        scene->addItem(zombieContainer[i]);

//        //std::cout<< "Zombies added " << i << std::endl; //DEBUG

//        //TEMP

//        //rand()%(max-min)+min;
//    }

//     //zombie->findPlayer();
