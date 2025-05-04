#include "s21_math.h"

long double s21_ceil(double x) {
  int counter;
  double y = 0.0;
  if (x < 0) {
    y = -x;
  } else {
    y = x;
  }
  for (counter = 0; x < 0 ? counter <= y : counter < y; counter++) {
  }
  if (x < 0) {
    counter = -counter + 1;
  }
  return counter;
}