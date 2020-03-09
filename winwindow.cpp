#include "winwindow.h"
#include <QTimer>
#include <QKeyEvent>

WinWindow::WinWindow() {
    //Creating win screen text
    winTitle = new QLabel(QString("You've Saved Gene Block!"));
    winTitle->setStyleSheet("font: bold 25pt;"
                               "QLabel{color: rgb(255, 255, 255);}");

    //Creating button
    quitButton = new QPushButton("Quit");
    quitButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: rgba(255, 255, 255, 85);");
    quitButton->setFixedSize(90, 40);

    //Setting background image
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/images/winWindowBackground.png")));
    this->setPalette(palette);

    //Setting layout
    winWindowGridLayout = new QGridLayout();
    winWindowGridLayout->addWidget(winTitle, 0,0, Qt::AlignCenter);
    winWindowGridLayout->setVerticalSpacing(340);
    winWindowGridLayout->addWidget(quitButton, 1,0, Qt::AlignCenter);

    connect(quitButton, SIGNAL(clicked()),this, SLOT(close()));

    setLayout(winWindowGridLayout);
}

//delete dynamically allocated data
WinWindow::~WinWindow() {
    delete winTitle;
    delete winWindowGridLayout;
    delete quitButton;
}
