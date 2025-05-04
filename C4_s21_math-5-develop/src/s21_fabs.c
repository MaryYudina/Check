#include "s21_math.h"

long double s21_fabs(double x) {
  if (x < 0) x = (long double)-x;
  return x;
}