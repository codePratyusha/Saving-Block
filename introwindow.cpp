#include "introwindow.h"
#include <QWindow>
#include <QBitmap>
#include <QFont>

//To Do: make so that easy button is selected by default (include front end coloring)

bool isEasy;

introWindow::introWindow()
{
    isEasy = true; //sets default difficulty to easy
    isEasySelected = false; //because no difficulty is selected
    isHardSelected = false;

    gameTitle = new QLabel(QString("UCLA Meme Page Game: Saving Gene Block!"));
    gameTitle->setStyleSheet("font: bold 25pt;"
                            "QLabel{color: rgb(255, 255, 255);}");

    startWindowButton = new QPushButton("Start");
    startWindowButton->setStyleSheet("font: bold 15pt;"
                                    "border-color: white;"
                                    "QLabel{color: rgb(255, 255, 255);}");
    startWindowButton->setFixedSize(100, 50);

    instructionsButton = new QPushButton("How To Play");
    instructionsButton->setStyleSheet("font: bold 15pt;"
                                    "border-color: white;"
                                    "QLabel{color: rgb(255, 255, 255);}");
    instructionsButton->setFixedSize(140, 60);

    easyButton = new QPushButton("Easy");
    easyButton->setStyleSheet("font: bold 15pt;"
                                    "border-color: white;"
                                    "QLabel{color: rgb(255, 255, 255);}");
    easyButton->setFixedSize(100, 50);

    hardButton = new QPushButton("Hard");
    hardButton->setStyleSheet("font: bold 15pt;"
                                    "border-color: white;"
                                    "QLabel{color: rgb(255, 255, 255);}");
    hardButton->setFixedSize(100, 50);

    //Setting background image
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/images/Background.png")));
    this->setPalette(palette);

    //Creating grid and adding widgets
    IntroWindowGridLayout = new QGridLayout;

    IntroWindowGridLayout->addWidget(gameTitle, 0, 0, Qt::AlignCenter);

    IntroWindowGridLayout->addWidget(startWindowButton, 1,0, Qt::AlignCenter);
    IntroWindowGridLayout->addWidget(instructionsButton, 2,0, Qt::AlignCenter);
    IntroWindowGridLayout->addWidget(easyButton,3,0, Qt::AlignLeft);
    IntroWindowGridLayout->addWidget(hardButton,3,0, Qt::AlignRight);

    connect(instructionsButton, SIGNAL(clicked()),this, SLOT(openInstrWindow()));   //initiates instructions
    connect(startWindowButton, SIGNAL(clicked()),this, SLOT(openGameWindow()));     //initiates instructions
    connect(easyButton, SIGNAL(clicked()),this, SLOT(selectEasy()));                //highlights Easy Level
    connect(hardButton, SIGNAL(clicked()),this, SLOT(selectHard()));                //highlights Hard Level

    setLayout(IntroWindowGridLayout);
}

void introWindow::openGameWindow() {
    gameWindow = new GameWindow();
    gameWindow->setFixedSize(630, 630);
    gameWindow->setWindowTitle("Save Gene Block");
    gameWindow->show();
    this->close();
}

//Instructions window
void introWindow::openInstrWindow() {
    instructionsWindow = new InstructionsWindow();
    instructionsWindow->setFixedSize(500, 400);
    instructionsWindow->setWindowTitle("How to Play");
    instructionsWindow->show();
}

void introWindow::selectEasy() {
    isEasySelected = true;
    isHardSelected = false;
    easyButton->setStyleSheet("font: bold 15pt;"
                                "border-color: white;"
                                "background-color: green");
    if (isHardSelected == true) {
        hardButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: green");
        easyButton->setStyleSheet("font: bold 15pt;"
                                        "border-color: white;"
                                        "QLabel{color: rgb(255, 255, 255);}");
    }
    isEasy = true;

    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}

void introWindow::selectHard() {
    isHardSelected = true;
    isEasySelected = false;
    if (isEasySelected == true) {
        hardButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: green");
        easyButton->setStyleSheet("font: bold 15pt;"
                                        "border-color: white;"
                                        "QLabel{color: rgb(255, 255, 255);}");
    }
    isEasy = false;
    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}

//Deletes all objects
introWindow::~introWindow()
{
    delete IntroWindowGridLayout;
    delete gameTitle;
    delete startWindowButton;
    delete instructionsButton;
    delete easyButton;
    delete hardButton;
}




