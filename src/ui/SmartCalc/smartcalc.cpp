#include "smartcalc.h"

#include <math.h>

#include "./ui_smartcalc.h"

SmartCalc::SmartCalc(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::SmartCalc) {
  ui->setupUi(this);
  ui->MulButton->setEnabled(false);
  ui->Div1Button->setEnabled(false);
  ui->PowButton->setEnabled(false);
  ui->Div2Button->setEnabled(false);
  ui->PlusButton->setEnabled(true);
  ui->MinusButton->setEnabled(true);
  ui->DotButton->setEnabled(false);
  ui->BracketRightButton->setEnabled(false);
}

SmartCalc::~SmartCalc() { delete ui; }

void SmartCalc::GraphFunc() {
  double xStart = -5;
  double xEnd = 5;
  double yStart = -2;
  double yEnd = 2;
  if (ui->xEnd->text().isEmpty() || ui->xStart->text().isEmpty() ||
      ui->yEnd->text().isEmpty() || ui->yStart->text().isEmpty()) {
    ui->widget->xAxis->setRange(xStart, xEnd);
    ui->widget->yAxis->setRange(yStart, yEnd);
  } else {
    ui->widget->xAxis->setRange(ui->xStart->text().toDouble(),
                                ui->xEnd->text().toDouble());
    ui->widget->yAxis->setRange(ui->yStart->text().toDouble(),
                                ui->yEnd->text().toDouble());
  }
  QVector<double> x(10001), y(10001);
  for (int i = 0; i < 10001; ++i) {
    QString qstr = ui->result->text();
    x[i] = (i - 5000.0) / fabs(xStart);
    QString x_value = QString::number(x[i]);
    qstr.replace("x", "(" + x_value + ")");
    std::string str = qstr.toStdString();
    const char *cstr = str.c_str();
    y[i] = run_calc(cstr);
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->setData(x, y);
  ui->widget->replot();
}
void SmartCalc::on_ResultButton_clicked() {
  QString qstr = ui->result->text();
  QString x_label = ui->lineEditX->text();
  bool is_number = false;
  bool error_x = false;
  x_label.toDouble(&is_number);
  if (qstr.contains('x')) {
    for (int i = 0; i < qstr.length(); ++i) {
      if (qstr.at(i) == 'x') {
        qstr.replace("x", ui->lineEditX->text());
      } else if (!is_number) {
        error_x = true;
      }
    }
  }
  if (error_x) {
    ui->result->setText("ERROR");
  } else {
    // ui->label->setText(qstr);
    std::string str = qstr.toStdString();
    const char *cstr = str.c_str();
    int invalid = input_validate(cstr);
    if (!invalid) {
      long double num = run_calc(cstr);
      QString i = QString::number(num, 'f', 6);
      ui->result->setText(i);
      StopButton();
      RunButton();
      ui->SqrtButton->setEnabled(false);
      ui->LnButton->setEnabled(false);
      ui->LogButton->setEnabled(false);
      ui->AtanButton->setEnabled(false);
      ui->TanButton->setEnabled(false);
      ui->AsinButton->setEnabled(false);
      ui->AcosButton->setEnabled(false);
      ui->CosButton->setEnabled(false);
      ui->SinButton->setEnabled(false);
      ui->XButton->setEnabled(false);
      ui->BracketRightButton->setEnabled(false);
      ui->BracketLeftButton->setEnabled(false);
    } else {
      ui->result->setText("ERROR");
    }
  }
  if (ui->result->text() == "ERROR" || ui->result->text() == "inf" ||
      ui->result->text() == "nan") {
    StopButton();
  }
}

void SmartCalc::on_XButton_clicked() {
  ui->result->setText(ui->result->text() + "x");
  ui->XButton->setEnabled(false);
  ui->MinusButton->setEnabled(true);
  ui->SqrtButton->setEnabled(false);
  ui->LnButton->setEnabled(false);
  ui->LogButton->setEnabled(false);
  ui->AtanButton->setEnabled(false);
  ui->TanButton->setEnabled(false);
  ui->AsinButton->setEnabled(false);
  ui->AcosButton->setEnabled(false);
  ui->CosButton->setEnabled(false);
  ui->SinButton->setEnabled(false);
  ui->BracketRightButton->setEnabled(true);
  ui->OneButton->setEnabled(false);
  ui->TwoButton->setEnabled(false);
  ui->ThreeButton->setEnabled(false);
  ui->SixButton->setEnabled(false);
  ui->FiveButton->setEnabled(false);
  ui->FourButton->setEnabled(false);
  ui->SevenButton->setEnabled(false);
  ui->EightButton->setEnabled(false);
  ui->NineButton->setEnabled(false);
  ui->ZeroButton->setEnabled(false);

  ui->MulButton->setEnabled(true);
  ui->Div1Button->setEnabled(true);
  ui->PowButton->setEnabled(true);
  ui->Div2Button->setEnabled(true);
  ui->PlusButton->setEnabled(true);
}

void SmartCalc::on_AcButton_clicked() {
  ui->result->setText("");
  RunButton();
  ui->MulButton->setEnabled(false);
  ui->Div1Button->setEnabled(false);
  ui->PowButton->setEnabled(false);
  ui->Div2Button->setEnabled(false);
  ui->PlusButton->setEnabled(true);
  ui->MinusButton->setEnabled(true);
  ui->DotButton->setEnabled(false);
  ui->BracketRightButton->setEnabled(false);
}

void SmartCalc::on_OneButton_clicked() {
  ui->result->setText(ui->result->text() + "1");
  NumberButton();
}

void SmartCalc::on_TwoButton_clicked() {
  ui->result->setText(ui->result->text() + "2");
  NumberButton();
}

void SmartCalc::on_ThreeButton_clicked() {
  ui->result->setText(ui->result->text() + "3");
  NumberButton();
}

void SmartCalc::on_FourButton_clicked() {
  ui->result->setText(ui->result->text() + "4");
  NumberButton();
}

void SmartCalc::on_FiveButton_clicked() {
  ui->result->setText(ui->result->text() + "5");
  NumberButton();
}

void SmartCalc::on_SixButton_clicked() {
  ui->result->setText(ui->result->text() + "6");
  NumberButton();
}

void SmartCalc::on_SevenButton_clicked() {
  ui->result->setText(ui->result->text() + "7");
  NumberButton();
}

void SmartCalc::on_EightButton_clicked() {
  ui->result->setText(ui->result->text() + "8");
  NumberButton();
}

void SmartCalc::on_NineButton_clicked() {
  ui->result->setText(ui->result->text() + "9");
  NumberButton();
}

void SmartCalc::on_ZeroButton_clicked() {
  ui->result->setText(ui->result->text() + "0");
  NumberButton();
}

void SmartCalc::on_DotButton_clicked() {
  ui->result->setText(ui->result->text() + ".");
  ui->DotButton->setEnabled(false);
  ui->SqrtButton->setEnabled(false);
  ui->LnButton->setEnabled(false);
  ui->LogButton->setEnabled(false);
  ui->AtanButton->setEnabled(false);
  ui->TanButton->setEnabled(false);
  ui->AsinButton->setEnabled(false);
  ui->AcosButton->setEnabled(false);
  ui->CosButton->setEnabled(false);
  ui->SinButton->setEnabled(false);
  ui->XButton->setEnabled(false);
  ui->BracketLeftButton->setEnabled(false);
  ui->BracketRightButton->setEnabled(false);
}

void SmartCalc::on_BracketLeftButton_clicked() {
  ui->result->setText(ui->result->text() + "(");
  ui->BracketRightButton->setEnabled(false);
  ui->MinusButton->setEnabled(true);
  ui->PlusButton->setEnabled(true);
}

void SmartCalc::on_BracketRightButton_clicked() {
  ui->result->setText(ui->result->text() + ")");
}

void SmartCalc::on_SqrtButton_clicked() {
  ui->result->setText(ui->result->text() + "sqrt(");
  ui->SqrtButton->setEnabled(false);
}

void SmartCalc::on_LnButton_clicked() {
  ui->result->setText(ui->result->text() + "ln(");
  ui->LnButton->setEnabled(false);
}

void SmartCalc::on_LogButton_clicked() {
  ui->result->setText(ui->result->text() + "log(");
  ui->LogButton->setEnabled(false);
}

void SmartCalc::on_AtanButton_clicked() {
  ui->result->setText(ui->result->text() + "atan(");
}

void SmartCalc::on_TanButton_clicked() {
  ui->result->setText(ui->result->text() + "tan(");
}

void SmartCalc::on_AsinButton_clicked() {
  ui->result->setText(ui->result->text() + "asin(");
}

void SmartCalc::on_AcosButton_clicked() {
  ui->result->setText(ui->result->text() + "acos(");
}

void SmartCalc::on_CosButton_clicked() {
  ui->result->setText(ui->result->text() + "cos(");
}

void SmartCalc::on_SinButton_clicked() {
  ui->result->setText(ui->result->text() + "sin(");
}

void SmartCalc::on_MinusButton_clicked() {
  ui->result->setText(ui->result->text() + "-");
  ui->MinusButton->setEnabled(false);
  ui->PlusButton->setEnabled(false);
  OperatorButton();
}

void SmartCalc::on_PlusButton_clicked() {
  ui->result->setText(ui->result->text() + "+");
  ui->PlusButton->setEnabled(false);
  ui->MinusButton->setEnabled(false);
  OperatorButton();
}

void SmartCalc::on_MulButton_clicked() {
  ui->result->setText(ui->result->text() + "*");
  ui->MulButton->setEnabled(false);
  OperatorButton();
}

void SmartCalc::on_Div1Button_clicked() {
  ui->result->setText(ui->result->text() + "/");
  ui->Div1Button->setEnabled(false);
  OperatorButton();
}

void SmartCalc::on_PowButton_clicked() {
  ui->result->setText(ui->result->text() + "^");
  ui->PowButton->setEnabled(false);
  OperatorButton();
}

void SmartCalc::on_Div2Button_clicked() {
  ui->result->setText(ui->result->text() + "mod");
  ui->Div2Button->setEnabled(false);
  OperatorButton();
}

void SmartCalc::StopButton() {
  ui->OneButton->setEnabled(false);
  ui->TwoButton->setEnabled(false);
  ui->ThreeButton->setEnabled(false);
  ui->SixButton->setEnabled(false);
  ui->FiveButton->setEnabled(false);
  ui->FourButton->setEnabled(false);
  ui->SevenButton->setEnabled(false);
  ui->EightButton->setEnabled(false);
  ui->NineButton->setEnabled(false);
  ui->ZeroButton->setEnabled(false);
  ui->DotButton->setEnabled(false);
  ui->ResultButton->setEnabled(false);
  ui->XButton->setEnabled(false);
  ui->BracketLeftButton->setEnabled(false);
  ui->BracketRightButton->setEnabled(false);
  ui->MulButton->setEnabled(false);
  ui->Div1Button->setEnabled(false);
  ui->PowButton->setEnabled(false);
  ui->Div2Button->setEnabled(false);
  ui->SqrtButton->setEnabled(false);
  ui->LnButton->setEnabled(false);
  ui->LogButton->setEnabled(false);
  ui->AtanButton->setEnabled(false);
  ui->TanButton->setEnabled(false);
  ui->AsinButton->setEnabled(false);
  ui->AcosButton->setEnabled(false);
  ui->CosButton->setEnabled(false);
  ui->SinButton->setEnabled(false);
  ui->MinusButton->setEnabled(false);
  ui->PlusButton->setEnabled(false);
}

void SmartCalc::RunButton() {
  ui->OneButton->setEnabled(true);
  ui->TwoButton->setEnabled(true);
  ui->ThreeButton->setEnabled(true);
  ui->SixButton->setEnabled(true);
  ui->FiveButton->setEnabled(true);
  ui->FourButton->setEnabled(true);
  ui->SevenButton->setEnabled(true);
  ui->EightButton->setEnabled(true);
  ui->NineButton->setEnabled(true);
  ui->ZeroButton->setEnabled(true);
  ui->DotButton->setEnabled(true);
  ui->ResultButton->setEnabled(true);
  ui->XButton->setEnabled(true);
  ui->BracketLeftButton->setEnabled(true);
  ui->BracketRightButton->setEnabled(true);
  ui->MulButton->setEnabled(true);
  ui->Div1Button->setEnabled(true);
  ui->PowButton->setEnabled(true);
  ui->Div2Button->setEnabled(true);
  ui->SqrtButton->setEnabled(true);
  ui->LnButton->setEnabled(true);
  ui->LogButton->setEnabled(true);
  ui->AtanButton->setEnabled(true);
  ui->TanButton->setEnabled(true);
  ui->AsinButton->setEnabled(true);
  ui->AcosButton->setEnabled(true);
  ui->CosButton->setEnabled(true);
  ui->SinButton->setEnabled(true);
  ui->MinusButton->setEnabled(true);
  ui->PlusButton->setEnabled(true);
}

void SmartCalc::NumberButton() {
  ui->XButton->setEnabled(true);
  ui->MulButton->setEnabled(true);
  ui->Div1Button->setEnabled(true);
  ui->PowButton->setEnabled(true);
  ui->Div2Button->setEnabled(true);
  ui->SqrtButton->setEnabled(false);
  ui->LnButton->setEnabled(false);
  ui->LogButton->setEnabled(false);
  ui->AtanButton->setEnabled(false);
  ui->TanButton->setEnabled(false);
  ui->AsinButton->setEnabled(false);
  ui->AcosButton->setEnabled(false);
  ui->CosButton->setEnabled(false);
  ui->SinButton->setEnabled(false);
  ui->MinusButton->setEnabled(true);
  ui->PlusButton->setEnabled(true);
  ui->BracketLeftButton->setEnabled(false);
  ui->BracketRightButton->setEnabled(true);
  ui->DotButton->setEnabled(true);
}

void SmartCalc::OperatorButton() {
  ui->DotButton->setEnabled(true);
  ui->BracketLeftButton->setEnabled(true);
  ui->XButton->setEnabled(true);
  ui->OneButton->setEnabled(true);
  ui->TwoButton->setEnabled(true);
  ui->ThreeButton->setEnabled(true);
  ui->SixButton->setEnabled(true);
  ui->FiveButton->setEnabled(true);
  ui->FourButton->setEnabled(true);
  ui->SevenButton->setEnabled(true);
  ui->EightButton->setEnabled(true);
  ui->NineButton->setEnabled(true);
  ui->ZeroButton->setEnabled(true);
  ui->MulButton->setEnabled(false);
  ui->Div1Button->setEnabled(false);
  ui->PowButton->setEnabled(false);
  ui->Div2Button->setEnabled(false);
  ui->PlusButton->setEnabled(false);
  ui->SqrtButton->setEnabled(true);
  ui->LnButton->setEnabled(true);
  ui->LogButton->setEnabled(true);
  ui->AtanButton->setEnabled(true);
  ui->TanButton->setEnabled(true);
  ui->AsinButton->setEnabled(true);
  ui->AcosButton->setEnabled(true);
  ui->CosButton->setEnabled(true);
  ui->SinButton->setEnabled(true);
  ui->BracketRightButton->setEnabled(false);
}

void SmartCalc::on_PlotButton_clicked() { GraphFunc(); }

void SmartCalc::on_CreditButton_clicked() { Credit.show(); }
