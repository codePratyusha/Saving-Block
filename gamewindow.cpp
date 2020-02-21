#include "gamewindow.h"

GameWindow::GameWindow()
{
    testLabel = new QLabel("Test Label");
    mainLayout = new QGridLayout;
    mainLayout->addWidget(testLabel, 3, 2);
    setLayout(mainLayout);
}

GameWindow::~GameWindow() {
    delete testLabel;
    delete mainLayout;
}
