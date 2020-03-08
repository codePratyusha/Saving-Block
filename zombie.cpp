
#include "zombie.h"
#include <iostream>
#include <QTimer>
#include "gamewindow.h"

extern GameWindow* game;

//Constructor
//@def constructs a zombie object and initializes the position to 0,0
Zombie::Zombie(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
  //create Zombie and set size

   // QPixmap zombiePix(":/images/zombieRight.png");
   // setPixmap(zombiePix);
    //zombiePix.scaled(0,0);
            x_pos = pos().x();
            y_pos = pos().y();
            health = 100;
            isDead = false;
            direction = 'R';

            QTimer* timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(move()));

              //start the timer (call move every 50 ms)
              timer->start(50);

}


//Destructor
Zombie::~Zombie(){}

//Zombie moves across screen - function is called everytime the key is pressed

// @brief



void Zombie::move(){

int speed = 1;

if(direction=='R'){
 setPos(x()+speed, y());
}else if(direction=='L'){
  setPos(x()-speed, y());
}else if(direction=='U'){
    setPos(x(), y()- speed);
}else if(direction =='D'){
    setPos(x(), y()+ speed);
}


//if out of bounds, delete zombie

if(x()>680 || y()>680){

    scene()->removeItem(this);
    delete this;

}





}




//void Zombie::moveToPlayer(){}

void Zombie::setDir(char c){
    direction = c;
}
