#include "winwindow.h"

WinWindow::WinWindow(QWidget* parent) : QGraphicsView(parent)
{   
    //Note: not added to scene
    youWinText = new QLabel("Congrats!\nYou've saved Gene Block!");
    youWinText->setAlignment(Qt::AlignCenter);
    youWinText->setStyleSheet("font: bold 25pt;"
                              "QLabel{color: rgba(255, 255, 255);}");

    //Creating / customizing scene
    winScene = new QGraphicsScene();
    winScene->setSceneRect(45, 0, width(), height());                   //set scene background
    winBackground = new QImage(":/images/winWindowBackground.png");    //set scene background to given image
    QBrush bg_brush(*winBackground);

    winScene->addWidget(youWinText);

    winScene->setBackgroundBrush(bg_brush);
    winScene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(winScene);                           //setting scene
    setSceneRect(winScene->sceneRect());

    //disabling scrollbars for Game Window class
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

//delete dynamically allocated data
WinWindow::~WinWindow() {

}
