#include "s21_math.h"

long double s21_asin(double x) {
  long double result = x;
  long double y = x;
  long double iter = 1;
  while (s21_fabs(result) > _S_21_EPS_) {
    if (x < -1 || x > 1) {
      y = _S_21_NAN_;
      break;
    }
    if (x == 1 || x == -1) {
      y = _S_21_PI_ / 2 * x;
      break;
    }
    result *=
        x * x * (2 * iter - 1) * (2 * iter - 1) / ((2 * iter + 1) * 2 * iter);
    iter += 1;
    y += result;
  }
  return y;
}