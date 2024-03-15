#include "credit.h"

#include <QApplication>
#include <QButtonGroup>
#include <QRadioButton>

#include "ui_credit.h"

credit::credit(QWidget *parent) : QWidget(parent), ui(new Ui::credit) {
  ui->setupUi(this);
  connect(ui->AnnuityButton, SIGNAL(toggled(bool)), this,
          SLOT(onRadioButtonToggled(bool)));
  connect(ui->DifferentiatedButton, SIGNAL(toggled(bool)), this,
          SLOT(onRadioButtonToggled(bool)));
}

void credit::onRadioButtonToggled(bool checked) {
  if (ui->AnnuityButton->isChecked()) {
  } else if (ui->DifferentiatedButton->isChecked()) {
  }
}

credit::~credit() { delete ui; }

void credit::on_CalcButton_clicked() {
  if (ui->AnnuityButton->isChecked()) {
    AnnuityCalc();
  } else if (ui->DifferentiatedButton->isChecked()) {
    DifferentiatedCalc();
  }
}

void credit::AnnuityCalc() {
  ui->FirstPay_2->setText(0);
  ui->LustPay->setText(0);
  double S = ui->SummCredit->text().toDouble();
  double P = ui->ProcentCredit->text().toDouble();
  int N = ui->TimeCredit->text().toInt();

  double MonthPay_num = FirstPayAnn(S, P, N);
  QString MonthPay = QString::number(MonthPay_num, 'f', 6);
  ui->MonthPay->setText(MonthPay);

  double All_MonthPay_num = AllPayAnn(S, P, N);
  QString All_MonthPay = QString::number(All_MonthPay_num, 'f', 6);
  ui->AllPay->setText(All_MonthPay);

  double OverPay_num = All_MonthPay_num - S;
  QString OverPay = QString::number(OverPay_num, 'f', 6);
  ui->OverPay->setText(OverPay);
}

void credit::DifferentiatedCalc() {
  ui->MonthPay->setText(0);
  double S = ui->SummCredit->text().toDouble();
  double P = ui->ProcentCredit->text().toDouble();
  int N = ui->TimeCredit->text().toInt();
  double FirstPay_2_num = FirstPayDif(S, P, N, 0);
  QString FirstPay_2 = QString::number(FirstPay_2_num, 'f', 6);
  ui->FirstPay_2->setText(FirstPay_2);

  double All_MonthPay_num = AllPayDif(S, P, N);
  QString All_MonthPay = QString::number(All_MonthPay_num, 'f', 6);
  ui->AllPay->setText(All_MonthPay);

  double OverPay_num = All_MonthPay_num - S;
  QString OverPay = QString::number(OverPay_num, 'f', 6);
  ui->OverPay->setText(OverPay);

  double LustPay_num = FirstPayDif(S, P, N, N - 1);
  QString LustPay = QString::number(LustPay_num, 'f', 6);
  ui->LustPay->setText(LustPay);
}
