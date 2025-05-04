#include <stdio.h>

#include "s21_math.h"

long double s21_acos(double x) {
  long double res = _S_21_NAN_;
  if (x == 1)
    res = 0;
  else if (x == (-1))
    res = _S_21_PI_;
  else if (x < 1 && x >= 0) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (x < 0 && x > -1) {
    res = _S_21_PI_ + s21_atan(s21_sqrt(1 - x * x) / x);
  }
  return res;
}