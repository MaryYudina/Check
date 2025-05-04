#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (x == _S_21_INF_) return _S_21_PI_ / 2;
  if (x == _S_21_N_INF_) return _S_21_N_PI_ / 2;
  if (x != x) return x;
  if (x == 1) return 0.785398163;
  if (x == -1) return -0.785398163;
  int is_in_range = (x > -1 && x < 1);
  res = is_in_range ? x : 1.0 / x;
  for (int i = 1; i < 7000; i++) {
    double a = s21_pow_int(-1, i);
    double b = s21_pow_int(x, (1 + 2 * i) * (is_in_range ? 1 : -1));
    double c = 1 + 2 * i;
    res += a * b / c;
  }
  if (!is_in_range) res = (_S_21_PI_ * s21_fabs(x) / (2 * x)) - res;
  return res;
}