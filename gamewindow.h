#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <mainwindow.h>

class GameWindow : public QWidget
{
    Q_OBJECT

    public:
        GameWindow();
        ~GameWindow();
    public slots:

    private:
        QGridLayout* mainLayout = nullptr;
        QLabel* playerHealthLabel = nullptr;

        void updateHealth();    //if player is damaged, decrement health by 1
        void endGame();         //if player health is 0, then end game
};

#endif // GAMEWINDOW_H
