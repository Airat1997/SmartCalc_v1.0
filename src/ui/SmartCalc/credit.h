#ifndef CREDIT_H
#define CREDIT_H

#include <QWidget>

extern "C" {
 #include "../../calculator/credit.h"
}


namespace Ui {
class credit;
}

class credit : public QWidget
{
    Q_OBJECT

public:
    explicit credit(QWidget *parent = nullptr);
    ~credit();

private slots:
    void onRadioButtonToggled(bool checked);
    void on_CalcButton_clicked();
    void AnnuityCalc();
    void DifferentiatedCalc();

private:
    Ui::credit *ui;
};

#endif // CREDIT_H
