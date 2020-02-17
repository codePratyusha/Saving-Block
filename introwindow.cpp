#include "introwindow.h"
#include <QWindow>

bool isEasy;

introWindow::introWindow()
{
    isEasy = true; //sets default difficulty to easy

    gameWindow = new QWidget;
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
    connect(startWindowButton, SIGNAL(clicked()),this, SLOT(openGameWindow())); //opens game window
    connect(easyButton, SIGNAL(clicked()),this, SLOT(selectEasy()));  //highlights Easy Level
    connect(hardButton, SIGNAL(clicked()),this, SLOT(selectHard()));  //highlights Hard Level

    setLayout(IntroWindowGridLayout);
}

//Game window
void introWindow::openGameWindow() {
    gameWindow->setFixedSize(650,650);
    gameWindow->show();
}

//Instructions window
void introWindow::openInstrWindow() {
    instr_window = new QWidget;
    QLabel *instr_text = new QLabel(instr_window);
    instr_text->setText("Welcome to UCLA Meme Page: Saving Gene Block!\n "
                        "Uh oh! Gene Block is stuck in the basement of Powell Library and it is up to you to save him.\n"
                        "Get to the basement door and unlock it to rescue him before the time runs out.\n"
                        "But beware of the student zombies pulling all-nighters and lurking around Powell.\n"
                        "Shoot them with Yerba Mates to wake them up before they get to you.\n"
                        "Use the arrow keys to move and spacebar to shoot. Good luck!\n");
    instr_text->setAlignment(Qt::AlignCenter);
    instr_text->show();
    instr_window->show();
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
    delete gameWindow;
    delete instr_window;
    delete IntroWindowGridLayout;
    delete gameTitle;
    delete startWindowButton;
    delete instructionsButton;
    delete easyButton;
    delete hardButton;
}




