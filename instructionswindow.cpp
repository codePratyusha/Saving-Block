#include "instructionswindow.h"

InstructionsWindow::InstructionsWindow()
{
    mainLayout = new QHBoxLayout;
    instructionsText = new QLabel("Welcome to UCLA Meme Page: Saving Gene Block!\n\n"
                                  "Uh oh! Gene Block is stuck in the basement of Powell Library and it is up to you to save him.\n"
                                  "Get to the basement door and unlock it to rescue him before the time runs out.\n"
                                  "But beware of the student zombies pulling all-nighters and lurking around Powell.\n"
                                  "Shoot them with Yerba Mates to wake them up before they get to you.\n"
                                  "Use the arrow keys to move and spacebar to shoot. Good luck!\n");
    mainLayout->addWidget(instructionsText);
    instructionsText->setAlignment(Qt::AlignCenter);
    setLayout(mainLayout);
}

InstructionsWindow::~InstructionsWindow() {
    delete instructionsText;
    delete mainLayout;
}
