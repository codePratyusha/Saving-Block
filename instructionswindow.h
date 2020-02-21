#ifndef INSTRUCTIONSWINDOW_H
#define INSTRUCTIONSWINDOW_H
#include <mainwindow.h>

class InstructionsWindow : public QWidget
{
    Q_OBJECT

    public:
        InstructionsWindow();
        ~InstructionsWindow();
    private:
        QLabel* instructionsText = nullptr;
        QHBoxLayout* mainLayout = nullptr;

};

#endif // INSTRUCTIONSWINDOW_H
