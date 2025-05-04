#include "s21_math.h"

long double s21_exp(double x) {
  double result = 1.0;
  if (x == _S_21_INF_)
    result = (double)_S_21_INF_;
  else if (x != x)
    result = (double)_S_21_NAN_;
  else {
    int counter = 1;
    double psevdo_x = x;
    double row_sum = 1;
    if (x < 0.0) psevdo_x = -x;
    for (int i = 0; i < 1000; i++) {
      row_sum *= psevdo_x / counter++;
      result += row_sum;
    }
    if (x < 0.0) result = 1 / result;
  }
  return result;
}