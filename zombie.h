#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <mainwindow.h>

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QSet>
#include <QPointF>
#include <QObject>
#include <map>
#include <iostream>

class Zombie: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Zombie(QPixmap& pixmap);
    //Constructor for zombie object
    //@param 'pixmap' as type QPixmap&

    ~Zombie();
    //Destructor for zombie object, deallocates data members
    //@param none

    int getHealth();
    //Getter for health data member
    //@param none

    char getDir();
    //Getter for direction
    //@param none

    bool getStatus();
    //Getter for if zombie is dead
    //@param none

    void setHealth(int amount);
    //Sets Zombie health to given parameter
    //@param 'amount' as type int

    void setDir(char c);
    //Sets Zombie direction to given parameter
    //@param 'c' as type char

    void decreaseHealth(int amount);
    //Decreases zombie health by given amount
    //@param 'amount' as type int

    double zombieMapToXY(double coord);
    //Linearly transforms zombieMap array to XY coordinate plane for QGraphicsScene
    //@param 'coord' as type double

public slots:
    void setPathToGene(int sourceRow, int sourceCol, int targRow, int targCol);
    //sets path from source to target
    //@param 'sourceRow' and 'sourceCol' as both type int, where zombie spawns
    //       'targRow' and 'targCol' as both type int, where zombie moves towards

    void moveToGene();
    //Function that moves Zombies towards Gene object
    //@param none

private:
    int health;
    char direction;
    int speed;
    bool isDead;
    double x_pos;
    double y_pos;
    std::map<std::pair<int,int>,std::pair<int,int>> mymap; //map containing keys of zombieMap and values as parents of each node in zombieMap
    void findPathFromMap(std::map<std::pair<int,int>,std::pair<int,int>>, int sourceX, int sourceY, int targetX, int targetY);
    QPointF destination;
    QTimer *timer;
    std::vector<std::pair<int,int>> mypath;
    char zombieMap[26][31];  //2D array scaled representation of the game grid
    size_t k;
};


#endif // ZOMBIE_H




