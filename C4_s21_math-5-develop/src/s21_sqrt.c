#include "s21_math.h"

long double s21_sqrt(double x) {
  long double left = 0;
  long double result = s21_fmax(1, x);
  while (s21_fabs(result - left) > _S_21_EPS_) {
    if (x < 0) {
      result = _S_21_N_NAN_;
      break;
    }
    left = result;
    result = (left + x / left) / 2;
  }
  return result;
}