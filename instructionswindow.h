#ifndef INSTRUCTIONSWINDOW_H
#define INSTRUCTIONSWINDOW_H
#include <mainwindow.h>

class InstructionsWindow : public QWidget
{
    Q_OBJECT

public:
    InstructionsWindow();
    //Constructor, creates instructions window
    //@param none

    ~InstructionsWindow();
    //Deallocates data members
    //@param none
private:
    QLabel* instructionsText = nullptr;
    QGridLayout* mainLayout = nullptr;
    QPushButton* goBackButton = nullptr;
};

#endif // INSTRUCTIONSWINDOW_H
