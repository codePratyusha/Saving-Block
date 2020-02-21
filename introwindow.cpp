#include "introwindow.h"
#include <QWindow>

bool isEasy;

introWindow::introWindow()
{
    isEasy = true; //sets default difficulty to easy

    instr_window = new QWidget;

    gameTitle = new QLabel("UCLA Meme Page Game: Saving Gene Block!");

    startWindowButton = new QPushButton("Start");
    startWindowButton->setFixedSize(100, 50);

    instructionsButton = new QPushButton("How To Play");
    instructionsButton->setFixedSize(100, 50);

    easyButton = new QPushButton("Easy");
    easyButton->setFixedSize(100, 50);

    hardButton = new QPushButton("Hard");
    hardButton->setFixedSize(100, 50);

    IntroWindowGridLayout = new QGridLayout;

    IntroWindowGridLayout->addWidget(gameTitle,0,0, Qt::AlignCenter);

    IntroWindowGridLayout->addWidget(startWindowButton, 1,0, Qt::AlignCenter);
    IntroWindowGridLayout->addWidget(instructionsButton, 2,0, Qt::AlignCenter);
    IntroWindowGridLayout->addWidget(easyButton,3,0, Qt::AlignLeft);
    IntroWindowGridLayout->addWidget(hardButton,3,0, Qt::AlignRight);

    connect(instructionsButton, SIGNAL(clicked()),this, SLOT(openInstrWindow())); //initiates instructions
    connect(startWindowButton, SIGNAL(clicked()),this, SLOT(openGameWindow())); //initiates instructions
    connect(easyButton, SIGNAL(clicked()),this, SLOT(selectEasy()));  //highlights Easy Level
    connect(hardButton, SIGNAL(clicked()),this, SLOT(selectHard()));  //highlights Hard Level

    setLayout(IntroWindowGridLayout);
}

void introWindow::openGameWindow() {
    GameWindow* game = new GameWindow();
    game->setFixedSize(600, 600);
    game->show();
    std::cout << "Game Window opened \n";   //for debugging purposes
}

//Instructions window
void introWindow::openInstrWindow() {
    InstructionsWindow* instructionsWindow = new InstructionsWindow();
    instructionsWindow->setFixedSize(500, 400);
    instructionsWindow->show();
}

void introWindow::selectEasy(){

    easyButton->setStyleSheet("background-color: green");
    hardButton->setStyleSheet("background-color: rgb(77,77,77)");
    isEasy = true;

    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}

void introWindow::selectHard(){

    hardButton->setStyleSheet("background-color: green");
    easyButton->setStyleSheet("background-color: rgb(77,77,77)");
    isEasy = false;
    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}

//Deletes all objects
introWindow::~introWindow()
{
    delete instr_window;
    delete IntroWindowGridLayout;
    delete gameTitle;
    delete startWindowButton;
    delete instructionsButton;
    delete easyButton;
    delete hardButton;
}



