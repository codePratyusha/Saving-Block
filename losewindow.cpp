#include "losewindow.h"

LoseWindow::LoseWindow() {
    //Creating lose screen text
    loseTitle = new QLabel(QString("You've Failed to Save Gene Block"));
    loseTitle->setStyleSheet("font: bold 25pt;"
                               "QLabel{color: rgb(255, 255, 255);}");

    //Creating button
    quitButton = new QPushButton("Quit");
    quitButton->setStyleSheet("font: bold 15pt;"
                                  "border-color: white;"
                                  "background-color: rgba(255, 255, 255, 85);");
    quitButton->setFixedSize(90, 40);

    //Setting background image
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/images/loseWindowBackground.png")));
    this->setPalette(palette);

    //Adding rain
    rain1 = new QMovie(":/images/rain.gif");
    rain2 = new QMovie(":/images/rain.gif");
    rain3 = new QMovie(":/images/rain.gif");
    rainLabel1 = new QLabel(this);
    rainLabel2 = new QLabel(this);
    rainLabel3 = new QLabel(this);
    rainLabel1->setGeometry(QRect(300, 10, width() / 2, height () / 2));
    rainLabel1->setMovie(rain1);
    rainLabel2->setGeometry(QRect(150, 10, width() / 2, height () / 2));
    rainLabel2->setMovie(rain1);
    rainLabel3->setGeometry(QRect(0, 10, width() / 2, height () / 2));
    rainLabel3->setMovie(rain1);
    rain1->start();
    rain2->start();
    rain3->start();

    //Setting layout
    loseWindowGridLayout = new QGridLayout();
    loseWindowGridLayout->addWidget(loseTitle, 0,0, Qt::AlignCenter);
    loseWindowGridLayout->setVerticalSpacing(340);
    loseWindowGridLayout->addWidget(quitButton, 1,0, Qt::AlignCenter);

    connect(quitButton, SIGNAL(clicked()),this, SLOT(close()));

    setLayout(loseWindowGridLayout);
}

LoseWindow::~LoseWindow() {
    delete loseWindowGridLayout;
    delete loseTitle;
    delete quitButton;
    delete rain1;
    delete rainLabel1;
    delete rain2;
    delete rainLabel2;
    delete rain3;
    delete rainLabel3;
}
