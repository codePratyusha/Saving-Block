#ifndef GENEBLOCK_H
#define GENEBLOCK_H
#include <Health.h>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class GeneBlock : public QObject, public QGraphicsPixmapItem
{
    public:
        GeneBlock(bool isEasyDifficulty, QPixmap& pixmap);
        ~GeneBlock();
        Health* geneBlockHealth = nullptr;  //data member should be private (to preserve encapsulation)
    private:
//        Health* geneBlockHealth = nullptr;
};

#endif // GENEBLOCK_H
