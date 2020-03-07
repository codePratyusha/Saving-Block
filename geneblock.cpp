#include "geneblock.h"

GeneBlock::GeneBlock(bool isEasyDifficulty, QPixmap& pixmap) : QObject(), QGraphicsPixmapItem(pixmap) {
    geneBlockHealth = new Health(isEasyDifficulty); //easy difficulty by default
}

GeneBlock::~GeneBlock() {
    delete geneBlockHealth;
}
