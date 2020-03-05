#include "geneblock.h"

GeneBlock::GeneBlock(QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    geneBlockHealth = new Health();
}

GeneBlock::~GeneBlock() {
    delete geneBlockHealth;
}
