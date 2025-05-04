#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  if (x < 0 || (x == _S_21_N_INF_) || (x == _S_21_NAN_)) {
    result = _S_21_NAN_;
  } else if (x == 0) {
    result = _S_21_N_INF_;
  } else if (x == _S_21_INF_) {
    result = _S_21_INF_;
  } else if (x == 1) {
    result = 0;
  } else {
    double int_part = 0.0;
    double fraction_part = x;
    double previous = 0;
    while (fraction_part >= _S_21_E_) {
      fraction_part /= _S_21_E_;
      int_part++;
    }
    int_part += (fraction_part / _S_21_E_);
    fraction_part = x;
    for (int i = 0; int_part != previous && i < 10000; i++) {
      double left, right;
      previous = int_part;
      left = (fraction_part / (s21_exp(int_part - 1.0)));
      right = ((int_part - 1.0) * _S_21_E_);
      int_part = ((left + right) / _S_21_E_);
    }
    result = int_part;
  }
  return result;
}