#ifndef INTROWINDOW_H
#define INTROWINDOW_H
#include <mainwindow.h>

extern bool isEasy; //global variable (accessible across all files) to set difficulty

class introWindow : public QWidget
{
    Q_OBJECT

    public:
        introWindow();      //Constructor
        ~introWindow();     //Destructor
    public slots:
        void openInstrWindow();
        void openGameWindow();
        void selectEasy();
        void selectHard();
    private:
        //Windows
        QWidget* gameWindow = nullptr;
        QWidget* instr_window = nullptr;

        //Layout
        QGridLayout* IntroWindowGridLayout = nullptr;

        //Label(s)
        QLabel* gameTitle = nullptr;

        //Buttons
        QPushButton* startWindowButton = nullptr;
        QPushButton* instructionsButton = nullptr;
        QPushButton* easyButton = nullptr;
        QPushButton* hardButton = nullptr;
};

#endif // INTROWINDOW_H
