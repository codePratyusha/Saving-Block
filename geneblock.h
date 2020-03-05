#ifndef GENEBLOCK_H
#define GENEBLOCK_H
#include <Health.h>
#include <QGraphicsPixmapItem>
//#include <QGraphicsScene>
#include <QPixmap>

class GeneBlock : public QObject, public QGraphicsPixmapItem
{
    public:
        GeneBlock(QPixmap& pixmap);
        ~GeneBlock();
    private:
        Health* geneBlockHealth = nullptr;
};

#endif // GENEBLOCK_H
