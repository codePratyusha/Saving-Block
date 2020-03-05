#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <mainwindow.h>
#include <player.h>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPointF>
#include <QSet>

class GameWindow : public QGraphicsView
{
    Q_OBJECT

    public:
        GameWindow(QWidget* parent = 0);
        ~GameWindow();
        void keyPressEvent(QKeyEvent* event);
        void mouseMoveEvent(QMouseEvent* event);

    public slots:
    private:
        QGraphicsScene* scene = nullptr;
        Player* user = nullptr;
        QMediaPlayer* titleMusic = nullptr;
        void updateHealth();    //if player is damaged, decrement health by 1
        void endGame();         //if player health is 0, then end game
};

#endif // GAMEWINDOW_H
