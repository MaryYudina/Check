#include "s21_math.h"

long double s21_fmax(double x, double y) {
  long double result;
  if (x > y)
    result = x;
  else
    result = y;
  return result;
}