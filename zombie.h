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
        ~Zombie();

        //Accessors
        int getHealth();
        char getDir();
        bool getStatus();  //accesses isDead

        //Setters
        void setHealth(int amount);
        void setDir(char c);

        void decreaseHealth(int amount);  //decreases health by amount
        void Gene();  //function that finds player using algo
        void hurtGene();   //function that hurts geneBlock when it coollifes

        std::vector<std::pair<int,int>> mypath;
        char zombieMap[26][31];  //2D array scaled representation of the game grid
        double zombieMapToXY(double coord); //linear transformation from zombieMap array to XY coordinate plane for QGraphicsScene

    public slots:
        void setPathToGene(int sourceRow, int sourceCol, int targRow, int targCol); //sets path from source to target
        void moveToGene();  //moves to Gene

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

        size_t k;
};


#endif // ZOMBIE_H




