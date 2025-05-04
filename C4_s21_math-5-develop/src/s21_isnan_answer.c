#include "s21_math.h"

int s21_is_nan_answer(double x, double y) {
  int a = (y == 0);
  int b = _S_21_INF_ == (x) || _S_21_N_INF_ == (x);
  int c = _S_21_INF_ == (y) || _S_21_N_INF_ == (y);
  int d = (b && c && x != y);
  return (a || b || d);
}