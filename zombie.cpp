#include "zombie.h"
#include <iostream>
#include <QTimer>
#include "gamewindow.h"
#include <queue>
#include <map>
#include <vector>

//Constructor
//@def constructs a zombie object and initializes the position to 0,0
Zombie::Zombie(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    x_pos = pos().x();
    y_pos = pos().y();
    health = 100;
    isDead = false;
    direction = 'R';
    k = 0;


    //initialize zombieMap
    for(int i=0; i<26; i++){
        for(int j=0; j<31; j++){
            this->zombieMap[i][j] ='.';
        }
    }

    //QTimer* timer = new QTimer(this);
    timer->singleShot(1000, this, SLOT(moveToGene()));
}


//Destructor
Zombie::~Zombie() {
    delete timer;  
}

void Zombie::setPathToGene(int row_src, int col_src, int row_targ, int col_targ){

    //    int row_src = 10;  //replace hardcoded values with params
    //    int col_src = 23;

    int R = 26;
    int C = 31;
\
    int visited[R][C];

    for(int i=0; i<26; i++){
        for(int j=0; j< 31; j++){
            visited[i][j]=false;
        }
    }

    this->zombieMap[row_targ][col_targ] = 'E';

    //Declare a map that has Nodes for their key values and parents for their mapped values
    std::map<std::pair<int,int>, std::pair<int,int>> mymap;

    struct Node{
    public:
        int row;
        int col;
        Node* parent;
        Node(int x, int y, Node* p) : row(x), col(y) , parent(p){}
        //Node(),
    };

    Node source(row_src, col_src, nullptr);

    // applying BFS on matrix cells starting from source
    std::queue<Node> q;
    q.push(source);
    visited[source.row][source.col] = true;  //source node has null ptr to parents

    while (!q.empty()) {
        Node p = q.front();
        q.pop();

        // Destination found- if p node is the end node//
        if (this->zombieMap[p.row][p.col] == 'E'){
            std::pair<int,int> c = std::pair<int, int>(p.row,p.col);
            std::pair<int,int> parent = std::pair<int, int>(p.parent->row, p.parent->col);
            mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
        }

        //std::cout<< "parentRowB: "<<p.row << " parentY: " << p.col<< std::endl;
        // std::cout<< "parentRow: "<<p.parent->row << " parentY: " << p.parent->col<< std::endl;

        // moving up
        if (p.row - 1 >= 0 && visited[p.row - 1][p.col] == false) {
            Node current(p.row-1,p.col, &p);

            if(current.parent!= nullptr && current.parent!= nullptr){
                current.parent->row = p.row;
                current.parent->col = p.col;
                q.push(current);


                //set current Node as a key
                //set current Node's parents as its mapped value
                std::pair<int,int> c = std::pair<int, int>(p.row-1,p.col);
                std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
            }
            // q.push(Node(p.row - 1, p.col));
            visited[p.row - 1][p.col] = true;
        }

        // moving down
        if (p.row + 1 < R && visited[p.row + 1][p.col] == false) {
            Node current(p.row+1,p.col, &p);
            if(current.parent!= nullptr && current.parent!= nullptr){
                current.parent->row = p.row;
                current.parent->col = p.col;
                q.push(current);
                std::pair<int,int> c = std::pair<int, int>(p.row+1,p.col);
                std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
            }
            // q.push(QItem(p.row + 1, p.col, p.row, p.col));
            visited[p.row + 1][p.col] = true;
        }

        // moving left
        if (p.col - 1 >= 0 && visited[p.row][p.col - 1] == false) {

            Node current(p.row,p.col-1, &p);
            if(current.parent!= nullptr && current.parent!= nullptr){
                current.parent->row = p.row;
                current.parent->col = p.col;
                q.push(current);
                std::pair<int,int> c = std::pair<int, int>(p.row,p.col-1);
                std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
            }
            //q.push(QItem(p.row, p.col - 1, p.row, p.col));
            visited[p.row][p.col - 1] = true;
        }

        // moving right
        if (p.col + 1 < C && visited[p.row][p.col + 1] == false) {

            Node current(p.row, p.col+1, &p);
            if(current.parent!= nullptr && current.parent!= nullptr){
                current.parent->row = p.row;
                current.parent->col = p.col;
                q.push(current);
                std::pair<int,int> c = std::pair<int, int>(p.row,p.col+1);
                std::pair<int,int> parent = std::pair<int, int>(current.parent->row, current.parent->col);
                mymap.insert(std::pair<std::pair<int,int>,std::pair<int,int>>(c, parent));
            }
            //q.push(QItem(p.row, p.col + 1, p.row, p.col));
            visited[p.row][p.col + 1] = true;
        }
    }

    //findPathFromMap(mymap, 10, 23, 16, 16); //LINE GIVING LINKER ERROR


    //this->mypath;
    //std::vector<std::pair<int,int>> mypath;
    //           int target_row = 15;
    //           int target_col =12;
    //           int source_row = 10; //
    //           int source_col = 23; //

    //Store target pair
    this->mypath.push_back({row_targ, col_targ});

    //Store parents of target pair


    //initialize keys for target
    int key_row=row_targ;
    int key_col=col_targ;

    //find parents of current nodes and store in the vector

    while(!(key_row==row_src && key_col == col_src)){
        // std::cout<< "key_x: " << key_x << "key y: " << key_y << std::endl; //DEBUG
        std::pair<int,int> p = mymap.find({key_row,key_col})->second;
        this->mypath.push_back(p);
        // std::cout<< "parent_x: " << p.first << "parent y: " << p.second << std::endl; DEBUG
        key_row = p.first;
        key_col = p.second;
    }

    //store source node in vector
    this->mypath.push_back({row_src, col_src});

    //reverse vector to get path right way round
    std::reverse(this->mypath.begin(),this->mypath.end());

    //                   for(size_t i=0; i<mypath.size(); i++){
    //                      std::cout<<"row: " << mypath[i].first << " y: " << mypath[i].second << std::endl; //DEBUG
    //                   }


    //iterate through reversed vector and each time the timer is called set the position of the zombie to position
    //this->findPathFromMap(std::map<std::pair<int,int>,std::pair<int,int>);
    return;
}


void Zombie::moveToGene(){
    //transform coords into XY plane
    //update zombie position on XY PLane
    //send back a single shot timer

    //set XY coordinates for the zombies

    if(pos().x()==300 && pos().y()==240){
        std::cout<< "enters this" << std::endl;
        isGeneHit=true;
    }

    if(this->mypath.size()!=0){
    double X = (mypath[this->k].first*20);
    double Y = (mypath[this->k].second*20);
     this->setPos(X, Y);
     this->k = this->k+1;

    }




//    std::cout << "row: " << X << "col: " << Y << std::endl;

    if(this->k < this->mypath.size()){
        this->timer->singleShot(800,this,SLOT(moveToGene()));
    }

    //zombies have movedto gene block's position


}



double Zombie::zombieMapToXY(double coord) {
    return coord*20;
}

int Zombie::getHealth() {
    return health;
}

char Zombie::getDir() {
    return direction;
}

bool Zombie::getStatus() {
    return isDead;
}

void Zombie::setHealth(int h) {
    health = h;
}
void Zombie::setDir(char d)
{
    direction = d;
}

void Zombie::decreaseHealth(int amount) {
    health = health-amount;
}
