#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result;
  if (exp == 0.0)
    result = 1;
  else
    result = s21_exp(exp * s21_log(base));
  return result;
}