#include "s21_math.h"

long double s21_floor(double x) {
  int counter = 0;
  double y = 0.0;
  if (x < 0) {
    y = -x;
  } else {
    y = x;
  }
  for (counter = 0; x < 0 ? counter < y : counter <= y; counter++) {
  }
  if (x < 0) {
    counter = -counter;
  } else {
    counter = counter - 1;
  }
  return counter;
}