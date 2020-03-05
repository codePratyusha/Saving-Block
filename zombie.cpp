
#include "zombie.h"
#include <iostream>
#include "gamewindow.h"

extern GameWindow* game;

//Constructor
//@def constructs a zombie object and initializes the position to 0,0
Zombie::Zombie(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
  //create Zombie and set size

   // QPixmap zombiePix(":/images/zombieRight.png");
   // setPixmap(zombiePix);
    //zombiePix.scaled(0,0);
            x_pos = 0;
            y_pos = 0;
            health = 100;
            isDead = false;
            direction = 'R';
            speed = 0;   //TODO: SET SPEED FOR MOVEMENT//
}



//Destructor
Zombie::~Zombie(){}

//Zombie moves across screen - function is called everytime the key is pressed

// @brief




//void Zombie::findGene(){




//void Zombie::moveToPlayer(){}
