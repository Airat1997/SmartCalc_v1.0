#ifndef SMARTCALC_H
#define SMARTCALC_H
#include <string.h>
#include <QMainWindow>
#include <QVector>
#include <QFont>
#include <credit.h>

extern "C" {
 #include "../../SmartCalc2.h"
}

struct error{
    bool error;
};

QT_BEGIN_NAMESPACE
namespace Ui { class SmartCalc; }
QT_END_NAMESPACE

class SmartCalc : public QMainWindow
{
    Q_OBJECT

public:
    SmartCalc(QWidget *parent = nullptr);
    ~SmartCalc();

private slots:
    void GraphFunc();

    void StopButton();

    void RunButton();

    void NumberButton();

    void OperatorButton();

    void on_OneButton_clicked();

    void on_TwoButton_clicked();

    void on_ThreeButton_clicked();

    void on_SixButton_clicked();

    void on_FiveButton_clicked();

    void on_FourButton_clicked();

    void on_SevenButton_clicked();

    void on_EightButton_clicked();

    void on_NineButton_clicked();

    void on_ZeroButton_clicked();

    void on_DotButton_clicked();

    void on_ResultButton_clicked();

    void on_XButton_clicked();

    void on_AcButton_clicked();

    void on_BracketLeftButton_clicked();

    void on_BracketRightButton_clicked();

    void on_MulButton_clicked();

    void on_Div1Button_clicked();

    void on_PowButton_clicked();

    void on_Div2Button_clicked();

    void on_SqrtButton_clicked();

    void on_LnButton_clicked();

    void on_LogButton_clicked();

    void on_AtanButton_clicked();

    void on_TanButton_clicked();

    void on_AsinButton_clicked();

    void on_AcosButton_clicked();

    void on_CosButton_clicked();

    void on_SinButton_clicked();

    void on_MinusButton_clicked();

    void on_PlusButton_clicked();

    void on_PlotButton_clicked();

    void on_CreditButton_clicked();

private:
    Ui::SmartCalc *ui;
    credit Credit;
};
#endif // SMARTCALC_H
