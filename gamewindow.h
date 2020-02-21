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
        QLabel* testLabel = nullptr;
        QGridLayout* mainLayout = nullptr;
};

#endif // GAMEWINDOW_H
