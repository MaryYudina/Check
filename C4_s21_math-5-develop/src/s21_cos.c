#include "s21_math.h"

long double s21_cos(double x) {
  long double res = _S_21_NAN_;
  if (x != _S_21_INF_ || x != _S_21_N_INF_ || x != _S_21_NAN_)
    res = s21_sin(_S_21_PI_ / 2 - x);
  return res;
}