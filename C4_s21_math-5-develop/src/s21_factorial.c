#include "s21_math.h"

long double s21_factorial(long long int x) {
  long double res = 0;
  if (x == 1 || x == 0)
    res = 1;
  else
    res = x * s21_factorial(x - 1);
  return res;
}