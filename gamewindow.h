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
        const int maxPlayerHealth = 3;  //maybe put data memebr in Player class
        const int minPlayerHealth = 0;
};

#endif // GAMEWINDOW_H
