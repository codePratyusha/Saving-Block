#ifndef GENEBLOCK_H
#define GENEBLOCK_H
#include <Health.h>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class GeneBlock : public QObject, public QGraphicsPixmapItem
{
public:
    GeneBlock(bool isEasyDifficulty, QPixmap& pixmap);
    //Creates Gene Block object with difficulty and image directory
    //@param difficult as bool, and pixmap as QPixmap

    ~GeneBlock();
    //Deallocates class data members
    //@param none

    Health* returnGeneBlockHealth() const;
    //Getter for health object
    //@param none
private:
    Health* geneBlockHealth = nullptr;
};

#endif // GENEBLOCK_H
