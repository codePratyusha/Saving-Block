#ifndef INTROWINDOW_H
#define INTROWINDOW_H
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include<QLabel>
#include <QMainWindow>

class introWindow : public QWidget
{
    Q_OBJECT

    public:
        introWindow();      //Constructor
        ~introWindow();     //Destructor

public slots:
        void openInstrWindow();
        void selectEasy();
        void selectHard();
    private:
        //Layout
        QGridLayout* horizontalLayout = nullptr;
        QGridLayout* verticalLayout = nullptr;

        //Label(s)
        QLabel* gameTitle = nullptr;

        //Buttons
        QPushButton* startWindowButton = nullptr;
        QPushButton* instructionsButton = nullptr;
        QPushButton* easyButton = nullptr;
        QPushButton* hardButton = nullptr;
};




#endif // INTROWINDOW_H
