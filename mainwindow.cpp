#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

bool isEasy;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Start screen -- this is what will be displayed at index0
    QWidget *introWindow = new QWidget;
    QLabel *introTitle = new QLabel(tr("UCLA GAME"));

    QPushButton *instrPushButton = new QPushButton(tr("How to Play"));
    instrPushButton->setFixedSize(200, 50);

    QPushButton *gamePushButton = new QPushButton(tr("Start"));
    gamePushButton->setFixedSize(200, 50);

    easyButton = new QPushButton("Easy");
    easyButton->setFixedSize(100, 50);

    hardButton = new QPushButton("Hard");
    hardButton->setFixedSize(100, 50);


    QGridLayout *introLayout = new QGridLayout(introWindow); // automatically set the layout on the widget
    introLayout->addWidget(introTitle, 1, 0, Qt::AlignCenter);
    introLayout->addWidget(gamePushButton, 2, 0, Qt::AlignCenter);
    introLayout->addWidget(instrPushButton, 3, 0, Qt::AlignCenter);
    introLayout->addWidget(easyButton, 4, 0, Qt::AlignLeft);
    introLayout->addWidget(hardButton, 4, 0, Qt::AlignRight);


    // Instructions screen -- this is what will be displayed on Instructions screen
    QWidget *instrWindow = new QWidget;
    QLabel *instructionTitle = new QLabel(tr("How to Play"));
    QLabel *instructionDetails = new QLabel(tr("Welcome to UCLA Meme Page: Saving Gene Block!\n "
                                       "Uh oh! Gene Block is stuck in the basement of Powell Library and it is up to you to save him.\n"
                                       "Get to the basement door and unlock it to rescue him before the time runs out.\n"
                                       "But beware of the student zombies pulling all-nighters and lurking around Powell.\n"
                                       "Shoot them with Yerba Mates to wake them up before they get to you.\n"
                                       "Use the arrow keys to move and spacebar to shoot. Good luck!\n"));
    instructionDetails->setAlignment(Qt::AlignCenter);
    QGridLayout *instrPageLayout = new QGridLayout(instrWindow); // automatically set the layout on the widget

    QPushButton *goBackButton = new QPushButton(tr("Back"));
     goBackButton->setFixedSize(200, 50);


    instrPageLayout->addWidget(instructionTitle, 0,0, Qt::AlignJustify);  //title set
    instrPageLayout->addWidget(instructionDetails,1,0, Qt::AlignJustify); //details of instructions set
    instrPageLayout->addWidget(goBackButton,2,0, Qt::AlignJustify);  //back button


    //Game screen - this is what will be displayed on the Game screen
    QWidget *gameWindow = new QWidget;
    QLabel *gameTitle = new QLabel(tr("This is the main game screen"));
    QGridLayout *gamePageLayout = new QGridLayout(gameWindow); // automatically set the layout on the widget

    gamePageLayout->addWidget(gameTitle,1,0, Qt::AlignCenter);  //title set-- placeholder


    //Stack Instruction and Game Widgets in main window
    _stackedWidget = new QStackedWidget;
    _stackedWidget->addWidget(introWindow);
    _stackedWidget->addWidget(instrWindow);
    _stackedWidget->addWidget(gameWindow);

    connect(easyButton, SIGNAL(clicked()),this, SLOT(selectEasy()));  //highlights Easy Level
    connect(hardButton, SIGNAL(clicked()),this, SLOT(selectHard()));  //highlights Hard Level
    connect(instrPushButton, SIGNAL(clicked()),this, SLOT(goToInstrWindow())); //goes to instrWindow widget
    connect(gamePushButton, SIGNAL(clicked()),this, SLOT(goToGameWindow()));
    connect(goBackButton, SIGNAL(clicked()),this, SLOT(goToStartScreen()));

   setCentralWidget(_stackedWidget);


}

void MainWindow::goToStartScreen(){

    _stackedWidget->setCurrentIndex(0);

}


void MainWindow::goToInstrWindow(){

    _stackedWidget->setCurrentIndex(1);

}

void MainWindow::goToGameWindow(){

    _stackedWidget->setCurrentIndex(2);

}




void MainWindow::selectEasy(){

    easyButton->setStyleSheet("background-color: green");
    hardButton->setStyleSheet("background-color: rgb(77,77,77)");
    isEasy = true;

    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}

void MainWindow::selectHard(){

    hardButton->setStyleSheet("background-color: green");
    easyButton->setStyleSheet("background-color: rgb(77,77,77)");
    isEasy = false;
    std::cout << "Difficulty: " << isEasy << std::endl; //for debugging purposes, prints difficulty to console
}






MainWindow::~MainWindow()
{
    delete ui;
}

