#include "credit.h"

double FirstPayAnn(double S, double r, int n) {
  double res = 0;
  r = r / 100;
  res = S * r / 12 * powl(1 + r / 12, n) / (powl(1 + r / 12, n) - 1);
  return res;
}

double AllPayAnn(double S, double r, int n) {
  double res = 0;
  for (int i = 0; i < n; i++) {
    double temp = FirstPayAnn(S, r, n);
    res += temp;
  }
  return res;
}

double FirstPayDif(double S, double r, int n, int i) {
  r = r / 100;
  double res = (S / n) + ((S - ((S / n) * i)) * r / 12);
  return res;
}

double AllPayDif(double S, double r, int n) {
  double res = 0;
  for (int i = 0; i < n; i++) {
    double temp = FirstPayDif(S, r, n, i);
    res += temp;
  }
  return res;
}
