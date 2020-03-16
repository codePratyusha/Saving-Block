#ifndef INSTRUCTIONSWINDOW_H
#define INSTRUCTIONSWINDOW_H
#include <mainwindow.h>

class InstructionsWindow : public QWidget
{
    Q_OBJECT

    public:
        InstructionsWindow();
        ~InstructionsWindow();
    public slots:
        void goToIntroWindow();
    private:
        QLabel* instructionsText = nullptr;
        QGridLayout* mainLayout = nullptr;
        QPushButton* goBackButton = nullptr;
};

#endif // INSTRUCTIONSWINDOW_H
