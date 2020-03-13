#include "introwindow.h"
#include <QWindow>
#include <QBitmap>
#include <QFont>


introWindow::introWindow()
{
    isEasy = true;              //sets default difficulty to easy
    isEasySelected = false;
    isHardSelected = false;

    gameTitle = new QLabel(QString("UCLA Meme Page Game: Saving Gene Block!"));
    gameTitle->setStyleSheet("font: bold 25pt;"
                             "QLabel{color: rgb(255, 255, 255);}");

    startWindowButton = new QPushButton("Start");
    startWindowButton->setStyleSheet("font: bold 15pt;"
                                     "border-color: white;"
                                     "background-color: rgba(255, 255, 255, 85);");
    startWindowButton->setFixedSize(100, 50);

    instructionsButton = new QPushButton("How To Play");
    instructionsButton->setStyleSheet("font: bold 15pt;"
                                      "border-color: white;"
                                      "background-color: rgba(255, 255, 255, 85);");
    instructionsButton->setFixedSize(140, 60);

    easyButton = new QPushButton("Easy");
    easyButton->setStyleSheet("font: bold 15pt;"
                              "border-color: white;"
                              "background-color: rgba(255, 255, 255, 100);");
    easyButton->setFixedSize(100, 50);

    hardButton = new QPushButton("Hard");
    hardButton->setStyleSheet("font: bold 15pt;"
                              "border-color: white;"
                              "background-color: rgba(255, 255, 255, 100);");
    hardButton->setFixedSize(100, 50);

    //Setting theme music
    introMusic= new QMediaPlayer(this);
    introMusic->setMedia(QUrl("qrc:/music/Crash Twinsanity - Theme Song.mp3"));
    introMusic->play();

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
    gameWindow = new GameWindow(isEasy);
    gameWindow->setFixedSize(680, 680);
    gameWindow->setWindowTitle("Save Gene Block");

    std::cout << "Game Window Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console

    introMusic->stop();

    gameWindow->show();
    this->close();
}

//Instructions window
void introWindow::openInstrWindow() {
    instructionsWindow = new InstructionsWindow();
    instructionsWindow->setFixedSize(440, 295);
    instructionsWindow->setWindowTitle("How to Play");
    instructionsWindow->show();
}

void introWindow::selectEasy() {
    isEasySelected = true;
    if ((isEasySelected == true) && (isHardSelected == false)) {
        easyButton->setStyleSheet("font: bold 15pt;"
                                  "bo rder-color: white;"
                                  "background-color: rgba(0, 215, 115, 90);");      //green background color
    } else if ((isHardSelected == true) && (isEasySelected == true)) {
        isHardSelected = false;
        easyButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: rgba(0, 215, 115, 90);");      //green background color
        hardButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: rgba(255, 255, 255, 100);");   //white background color
    }
    isEasy = true;

    //Debugging to console
//    std::cout << "isEasySelected: " << isEasySelected << "\nisHardSelected: " << isHardSelected << std::endl;
    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}

void introWindow::selectHard() {
    isHardSelected = true;
    if ((isHardSelected == true) && (isEasySelected == false)) {
        hardButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: rgba(235, 75, 50, 90);");      //red background color
    } else if ((isEasy == true) && (isHardSelected == true)) {
        isEasySelected = false;
        hardButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: rgba(235, 75, 50, 90);");      //red background color
        easyButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: rgba(255, 255, 255, 100);");   //white background color
    }
    isEasy = false;

    //Debugging to console
//    std::cout << "isEasySelected: " << isEasySelected << "\nisHardSelected: " << isHardSelected << std::endl;
    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}

//Deletes all objects
introWindow::~introWindow()
{
    delete instructionsWindow;
    delete IntroWindowGridLayout;
    delete gameTitle;
    delete startWindowButton;
    delete instructionsButton;
    delete goBackButton;
    delete easyButton;
    delete hardButton;
    delete introMusic;
}

bool introWindow::getDifficulty() {
    return isEasy;
}



