#include "gamewindow.h"

//instr_window = new QWidget;
//QLabel *instr_text = new QLabel(instr_window);
//instr_text->setText("Welcome to UCLA Meme Page: Saving Gene Block!\n "
//                    "Uh oh! Gene Block is stuck in the basement of Powell Library and it is up to you to save him.\n"
//                    "Get to the basement door and unlock it to rescue him before the time runs out.\n"
//                    "But beware of the student zombies pulling all-nighters and lurking around Powell.\n"
//                    "Shoot them with Yerba Mates to wake them up before they get to you.\n"
//                    "Use the arrow keys to move and spacebar to shoot. Good luck!\n");
//instr_text->setAlignment(Qt::AlignCenter);
//instr_text->show();
//instr_window->show();

GameWindow::GameWindow()
{
    //To do: change from layout to scene

    std::string str = "Health: ";
//    str += std::to_string(maxPlayerHealth);

    playerHealthLabel = new QLabel("Health: ");
    mainLayout = new QGridLayout;

    scene = new QGraphicsScene(this);

    QPixmap userIcon(":/images/player.png");
    user = new Player(userIcon);
    user->setPos(325, 325); //should be middle of game window

    scene->addItem(user);

    mainLayout->addWidget(playerHealthLabel, 0, 0, Qt::AlignTop);
    setLayout(mainLayout);
}

GameWindow::~GameWindow() {
    delete playerHealthLabel;
    delete mainLayout;
}
