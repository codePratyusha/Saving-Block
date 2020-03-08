#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <mainwindow.h>

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QSet>
#include <QPointF>
#include <QObject>


class Zombie: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    //Zombie(QGraphicsItem * parent=0);
    Zombie(QPixmap& pixmap);
    ~Zombie();

    //Accessors
    int getHealth();
    char getDir();
    bool getStatus();  //accesses isDead




    //Modifiers
    void setHealth();
    void setDir(char c);


    void decreaseHealth(int amount);  //decreases health by amount
    void Gene();  //function that finds player using algo
    void hurtGene();   //function that hurts geneBlock when it coollifes


public slots:
    void move();
    //void doSomething();  // function that checks the status of the zombie, if zombie !isDead then call findPlayer()- called every second of the game
    //int binary_search(int x_player, int y_player, int x_pos, int y_pos);



private:
   int health;
   char direction;
   int speed;
   bool isDead;
   double x_pos;
   double y_pos;
   QPointF destination;


};

#endif // ZOMBIE_H
