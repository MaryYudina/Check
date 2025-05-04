#include "s21_math.h"

long double s21_tan(double x) {
  long double res = _S_21_NAN_;
  if (x != _S_21_INF_ || x != _S_21_N_INF_ || x != _S_21_NAN_)
    res = s21_sin(x) / s21_cos(x);
  return res;
}