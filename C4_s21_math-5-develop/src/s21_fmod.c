#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (s21_is_nan_answer(x, y)) return _S_21_NAN_;
  if (_S_21_N_INF_ == (y) || _S_21_INF_ == (y)) return (long double)x;
  int n = x / y;
  long double remainder = (long double)x - n * (long double)y;
  return remainder;
}