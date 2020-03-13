#include "winwindow.h"
#include <QTimer>
#include <QKeyEvent>

WinWindow::WinWindow() {
    //Creating win screen text
    winTitle = new QLabel(QString("You've Saved Gene Block!"));
    winTitle->setStyleSheet("font: bold 25pt;"
                               "QLabel{color: rgb(255, 255, 255);}");

    //Creating credits
    creditsText = new QLabel(QString("Thanks for Playing!\n"
                                     "Project by Daniel, Michaella, Pratyusha, Jeremy"));
    creditsText->setAlignment(Qt::AlignCenter);
    creditsText->setStyleSheet("font: bold 15pt;"
                               "QLabel{color: rgb(255, 255, 255);}");

    //Creating button
    quitButton = new QPushButton("Quit");
    quitButton->setStyleSheet("font: bold 18pt;"
                                  "border-color: white;"
                                  "background-color: rgba(255, 255, 255, 85);");
    quitButton->setFixedSize(90, 40);
    connect(quitButton, SIGNAL(clicked()),this, SLOT(close()));

    //Setting background image
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/images/winWindowBackground.png")));
    this->setPalette(palette);

    //Setting layout
    winWindowGridLayout = new QGridLayout();
    winWindowGridLayout->addWidget(winTitle, 0,0, Qt::AlignCenter);
    winWindowGridLayout->setVerticalSpacing(55);
    winWindowGridLayout->addWidget(creditsText, 2,0, Qt::AlignCenter);
//    winWindowGridLayout->setVerticalSpacing(10);
    winWindowGridLayout->addWidget(quitButton, 3,0, Qt::AlignCenter);

    //Setting winWindow music
    winWindowMusic = new QMediaPlayer(this);
    winWindowMusic->setMedia(QUrl("qrc:/music/Undertale OST 095 - Bring It In, Guys!.mp3"));
    winWindowMusic->play();
    connect(winWindowMusic, SIGNAL(stateChanged(QMediaPlayer::State)), SLOT(replayMusic(QMediaPlayer::State)));

    setLayout(winWindowGridLayout);
}

//delete dynamically allocated data
WinWindow::~WinWindow() {
    delete winTitle;
    delete winWindowGridLayout;
    delete quitButton;
}
