#include "introwindow.h"
#include <QWindow>

//generateParticles = new QPushButton("Generate Particles");
//spin_box_posRows = new QSpinBox;
//spin_box_posRows->setRange(0,20);
//spin_box_posCol = new QSpinBox;
//spin_box_posCol->setRange(0,20);

//Label_posRows = new QLabel("Rows");
//Label_posCol = new QLabel("Columns");

//layout = new QGridLayout;
//layout->addWidget(generateParticles, 1, 1);
//layout->addWidget(Label_posRows,2,1);
//layout->addWidget(Label_posRows, 2, 2);
//layout->addWidget(Label_posCol,3,1);
//layout->addWidget(spin_box_posCol, 3, 2);
//setLayout(layout);

introWindow::introWindow()
{
    gameTitle = new QLabel("UCLA Meme Page Game: Saving Gene Block!");

    startWindowButton = new QPushButton("Start");
    startWindowButton->setFixedSize(100, 50);

    instructionsButton = new QPushButton("Instructions");
    instructionsButton->setFixedSize(100, 50);

    easyButton = new QPushButton("Easy");
    easyButton->setFixedSize(100, 50);

    hardButton = new QPushButton("Hard");
    hardButton->setFixedSize(100, 50);

    verticalLayout = new QGridLayout;
    horizontalLayout = new QGridLayout;

    verticalLayout->addWidget(gameTitle,0,0, Qt::AlignCenter);

    verticalLayout->addWidget(startWindowButton, 1,0, Qt::AlignCenter);
    verticalLayout->addWidget(instructionsButton, 2,0, Qt::AlignCenter);
    verticalLayout->addWidget(easyButton,3,0, Qt::AlignLeft);
    verticalLayout->addWidget(hardButton,3,0, Qt::AlignRight);


    connect(instructionsButton, SIGNAL(clicked()),this, SLOT(openInstrWindow())); //initiates instructions
    connect(easyButton, SIGNAL(clicked()),this, SLOT(selectEasy()));  //highlights Easy Level
    connect(hardButton, SIGNAL(clicked()),this, SLOT(selectHard()));  //highlights Hard Level


    setLayout(verticalLayout);
}

//Instructions window
void introWindow::openInstrWindow(){
    QWidget *instr_window = new QWidget;
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

}

void introWindow::selectHard(){

    hardButton->setStyleSheet("background-color: green");
    easyButton->setStyleSheet("background-color: rgb(77,77,77)");
}

introWindow::~introWindow()
{
}





