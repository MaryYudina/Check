#include "s21_math.h"

long double s21_sin(double x) {
  long double res = 0, pow = 0, factorial = 0;
  x = s21_fmod(x, 2 * _S_21_PI_);
  for (int i = 0; i < 15; i++) {
    pow = s21_pow_int(-1, i) * s21_pow_int(x, 2 * i + 1);
    factorial = s21_factorial(2 * i + 1);
    res += pow / factorial;
  }
  return res;
}