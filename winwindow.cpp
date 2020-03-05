#include "winwindow.h"

WinWindow::WinWindow()
{   
    youWinText = new QLabel("Congrats!\nYou've saved Gene Block!");
    youWinText->setAlignment(Qt::AlignCenter);
    youWinText->setStyleSheet("font: bold 25pt;"
                             "QLabel{color: rgb(255, 255, 255);}");

    winWindowGridLayout = new QGridLayout;

    winWindowGridLayout->addWidget(youWinText, 0, 0, Qt::AlignVCenter);

    setLayout(winWindowGridLayout);
}

WinWindow::~WinWindow() {
    delete youWinText;
    delete winWindowGridLayout;
}
