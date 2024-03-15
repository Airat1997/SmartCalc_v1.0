#include <QApplication>

#include "smartcalc.h"

int main(int argc, char *argv[]) {
  error A = {0};
  QApplication a(argc, argv);

  SmartCalc w;
  w.show();
  return a.exec();
}
