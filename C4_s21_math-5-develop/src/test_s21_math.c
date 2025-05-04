#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

// ABS_TEST
START_TEST(abs_tests) {
  ck_assert_int_eq(s21_abs(-1), abs(1));
  ck_assert_int_eq(s21_abs(1), abs(-1));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-0xA13), abs(-0xA13));
  ck_assert_int_eq(s21_abs(-1234567890), abs(-1234567890));
  ck_assert_int_eq(s21_abs(-123), abs(-123));
  ck_assert_int_eq(s21_abs(2121), abs(2121));
}
END_TEST

// FABS_TEST
START_TEST(fabs_tests) {
  ck_assert_double_eq(s21_fabs(-1.123), fabs(1.123));
  ck_assert_double_eq(s21_fabs(1.123), fabs(-1.123));
  ck_assert_double_eq(s21_fabs(0.00), fabs(0.00));
  ck_assert_int_eq(s21_abs(-0xA13), abs(-0xA13));
  ck_assert_double_eq(s21_fabs(-1234567890.1234567890),
                      fabs(1234567890.1234567890));
  ck_assert_double_eq(s21_fabs(2121.2121), fabs(2121.2121));
  ck_assert_double_eq(s21_fabs(-987.789), fabs(-987.789));
}
END_TEST

// CEIL_TEST
START_TEST(ceil_tests) {
  ck_assert_int_eq(s21_ceil(0.5), ceil(0.5));
  ck_assert_int_eq(s21_ceil(0.12356789), ceil(0.123456789));
  ck_assert_int_eq(s21_ceil(0.00), ceil(0.00));
  ck_assert_int_eq(s21_ceil(-1234567890.12345), ceil(-1234567890.12345));
  ck_assert_int_eq(s21_ceil(2121.2121), ceil(2121.2121));
  ck_assert_int_eq(s21_ceil(-987.789), ceil(-987.789));
  ck_assert_int_eq(s21_ceil(-0.00), ceil(-0.00));
  ck_assert_int_eq(s21_ceil(0.499999999), ceil(0.499999999));
  ck_assert_int_eq(s21_ceil(210), ceil(210));
}
END_TEST

// FLOOR_TEST
START_TEST(floor_tests) {
  ck_assert_int_eq(s21_floor(0.5), floor(0.5));
  ck_assert_int_eq(s21_floor(0.12356789), floor(0.123456789));
  ck_assert_int_eq(s21_floor(0.00), floor(0.00));
  ck_assert_int_eq(s21_floor(-1234567890.1234567890),
                   floor(-1234567890.1234567890));
  ck_assert_int_eq(s21_floor(2121.2121), floor(2121.2121));
  ck_assert_int_eq(s21_floor(-987.789), floor(-987.789));
  ck_assert_int_eq(s21_floor(-0.00), floor(-0.00));
  ck_assert_int_eq(s21_floor(0.499999999), floor(0.499999999));
  ck_assert_int_eq(s21_floor(210), floor(210));
}
END_TEST

// EXP_TEST
START_TEST(exp_tests) {
  ck_assert_ldouble_nan(s21_exp(_S_21_NAN_));
  ck_assert_ldouble_nan(s21_exp(_S_21_N_NAN_));
  ck_assert_ldouble_infinite(s21_exp(_S_21_INF_));
  ck_assert_uint_eq(s21_exp(1), exp(1));
  ck_assert_uint_eq(s21_exp(5), exp(5));
  ck_assert_uint_eq(s21_exp(0.00), exp(0.00));
  ck_assert_uint_eq(s21_exp(-1), exp(-1));
  ck_assert_uint_eq(s21_exp(21.21), exp(21.21));
  ck_assert_uint_eq(s21_exp(-9.789), exp(-9.789));
  ck_assert_ldouble_eq_tol(exp(123.456e-20), s21_exp(123.456e-20), 1e-6);
}
END_TEST

// LOG_TEST
START_TEST(log_tests) {
  ck_assert_ldouble_nan(s21_log(_S_21_NAN_));
  ck_assert_ldouble_nan(s21_log(_S_21_N_NAN_));
  ck_assert_ldouble_infinite(s21_log(_S_21_INF_));
  ck_assert_int_eq(s21_log(12345), log(12345));
  ck_assert_int_eq(s21_log(5), log(5));
  ck_assert_int_eq(s21_log(0.00), log(0.00));
  ck_assert_int_eq(s21_log(-1), log(-1));
  ck_assert_int_eq(s21_log(1), log(1));
  ck_assert_int_eq(s21_log(21.21), log(21.21));
  ck_assert_int_eq(s21_log(1.001), log(1.001));
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
}
END_TEST

// FMOD_TEST
START_TEST(fmod_tests) {
  ck_assert_int_eq(s21_fmod(14.0, 3.5), fmod(14.0, 3.5));
  ck_assert_int_eq(s21_fmod(15.0, 5.0), fmod(15.0, 5.0));
  ck_assert_int_eq(s21_fmod(356.0, 1.390625), fmod(356.0, 1.390625));
  ck_assert_int_eq(s21_fmod(12345.6789, 123.123), fmod(12345.6789, 123.123));
}
END_TEST

// POW_TEST
START_TEST(pow_tests) {
  ck_assert_int_eq(s21_pow(100.0, 0.0), pow(100.0, 0.0));
  ck_assert_int_eq(s21_pow(10.0, 10.0), pow(10.0, 10.0));
  ck_assert_int_eq(s21_pow(123.123, 3.7), pow(123.123, 3.7));
  ck_assert_int_eq(s21_pow(0.0, 0.0), pow(0.0, 0.0));
  ck_assert_int_eq(s21_pow(-195.287, 15.01), pow(-195.287, 15.01));
  ck_assert_int_eq(s21_pow(12.34, -11.22345), pow(12.34, -11.22345));
  ck_assert_int_eq(s21_pow(-321.4, -5.6789), pow(-321.4, -5.6789));
}
END_TEST

// SQRT_TEST
START_TEST(sqrt_tests) {
  ck_assert_int_eq(s21_sqrt(1298.0), sqrt(1298.0));
  ck_assert_int_eq(s21_sqrt(0.0), sqrt(0.0));
  ck_assert_int_eq(s21_sqrt(144.0), sqrt(144.0));
  ck_assert_int_eq(s21_sqrt(599.955), sqrt(599.955));
  ck_assert_int_eq(s21_sqrt(-12345.6789), sqrt(-12345.6789));
  ck_assert_int_eq(s21_sqrt(-1.1234567), sqrt(-1.1234567));
  ck_assert_int_eq(s21_sqrt(0.021), sqrt(0.021));
}
END_TEST

// SIN_TEST
START_TEST(sin_tests) {
  ck_assert_double_eq_tol(s21_sin(1), sin(1), 0.000001);
  ck_assert_double_eq_tol(s21_sin(6.12), sin(6.12), 0.000001);
  ck_assert_double_eq_tol(s21_sin(-12.6), sin(-12.6), 0.000001);
  ck_assert_double_nan(s21_sin(_S_21_NAN_));
  ck_assert_ldouble_nan(s21_sin(_S_21_INF_));
  ck_assert_double_nan(s21_sin(_S_21_N_INF_));
  ///////////////////////////////////////////////////////////////////////////////////////////
  // сторонние тесты
  ck_assert_double_eq_tol(s21_sin(1), sin(1), 0.000001);
  ck_assert_double_eq_tol(s21_sin(6.12), sin(6.12), 0.000001);
  ck_assert_double_eq_tol(s21_sin(-12.6), sin(-12.6), 0.000001);
  for (double i = _S_21_N_PI_; i < _S_21_PI_; i += 0.01) {
    ck_assert_int_eq(s21_sin(i), sin(i));
  }
  ck_assert_int_eq(s21_sin(0.0), sin(0.0));
  ck_assert_int_eq(s21_sin(12345.0), sin(12345.0));
}
END_TEST

// ASIN_TEST
START_TEST(asin_tests) {
  ck_assert_double_nan(s21_asin(7));
  ck_assert_double_nan(s21_asin(100));
  ck_assert_double_nan(s21_asin(-17));
  ck_assert_double_eq_tol(s21_asin(0), asin(0), 0.000001);
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), 0.000001);
  ck_assert_double_eq_tol(s21_asin(1), asin(1), 0.000001);
  ck_assert_double_eq_tol(s21_asin(0.5), asin(0.5), 0.000001);
  /////////////////////////////////////////////////////////////////////////////////
  //  сторонние тесты
  ck_assert_int_eq(s21_asin(0.43), asin(0.43));
  ck_assert_int_eq(s21_asin(0.12), asin(0.12));
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_asin(i), asin(i));
  }
  for (double i = -1; i < 5; i += 0.01) {
    ck_assert_int_eq(s21_asin(i), asin(i));
  }
}
END_TEST

// COS_TEST
START_TEST(cos_tests) {
  ck_assert_double_eq_tol(s21_cos(1206), cos(1206), 0.000001);
  ck_assert_double_eq_tol(s21_cos(-6.12), cos(-6.12), 0.000001);
  ck_assert_double_eq_tol(s21_cos(0), cos(0), 0.000001);
  ck_assert_double_eq_tol(s21_cos(_S_21_PI_), cos(_S_21_PI_), 0.000001);
  ck_assert_double_eq_tol(s21_cos(_S_21_M_PI_), cos(_S_21_M_PI_), 0.000001);
  ck_assert_double_nan(s21_sin(INFINITY));
  ck_assert_double_nan(s21_sin(NAN));
  ////////////////////////////////////////////////////////////////////////////////////
  // сторонние тесты
  ck_assert_int_eq(s21_cos(0), cos(0));
  ck_assert_int_eq(s21_cos(112343), cos(112343));
  ck_assert_int_eq(s21_cos(-312345), cos(-312345));
}
END_TEST

// ACOS_TEST
START_TEST(acos_tests) {
  ck_assert_double_eq_tol(s21_acos(0), acos(0), 0.000001);
  ck_assert_double_eq_tol(s21_acos(-0.1702), acos(-0.1702), 0.000001);
  ck_assert_double_eq_tol(s21_acos(1), acos(1), 0.000001);
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 0.000001);
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(s21_acos(-INFINITY));
  ck_assert_double_nan(s21_acos(NAN));
  ck_assert_double_nan(s21_acos(1234));
  ck_assert_double_nan(s21_acos(-6));
  ////////////////////////////////////////////////////////////////////////////////
  //сторонние тесты
  ck_assert_int_eq(s21_acos(-0.99999), acos(-0.99999));
  ck_assert_int_eq(s21_acos(0.49), acos(0.49));
  ck_assert_int_eq(s21_acos(-1), acos(-1));
}
END_TEST

// TAN_TEST
START_TEST(tan_tests) {
  ck_assert_double_nan(s21_tan(INFINITY));
  ck_assert_double_nan(s21_tan(-INFINITY));
  ck_assert_double_nan(s21_tan(NAN));
  ck_assert_double_eq_tol(s21_tan(612), tan(612), 0.000001);
  ck_assert_double_eq_tol(s21_tan(-66), tan(-66), 0.000001);
  ck_assert_double_eq_tol(s21_tan(0), tan(0), 0.000001);
  ck_assert_double_eq_tol(s21_tan(M_PI), tan(M_PI), 0.000001);
  ck_assert_double_eq_tol(s21_tan(0.12), tan(0.12), 0.000001);
  ////////////////////////////////////////////////////////////////////////////////////
  // сторонние тесты
  ck_assert_int_eq(s21_tan(0.23), tan(0.23));
  ck_assert_int_eq(s21_tan(1234567), tan(1234567));
  ck_assert_int_eq(s21_tan(-1234567), tan(-1234567));
  for (double i = -100; i < 100; i += 2) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
  for (double i = -1; i < 1; i += 0.02) {
    ck_assert_int_eq(s21_tan(i), tan(i));
  }
}
END_TEST

// ATAN_TEST
START_TEST(atan_tests) {
  ck_assert_double_eq_tol(s21_atan(0), atan(0), 0.000001);
  ck_assert_double_eq_tol(s21_atan(1), atan(1), 0.000001);
  ck_assert_double_eq_tol(s21_atan(-1), atan(-1), 0.000001);
  ck_assert_double_nan(s21_atan(_S_21_NAN_));
  ck_assert_double_eq_tol(s21_atan(_S_21_INF_), atan(_S_21_INF_), 0.000001);
  ck_assert_double_eq_tol(s21_atan(_S_21_N_INF_), atan(_S_21_N_INF_), 0.000001);
  ck_assert_double_eq_tol(s21_atan(-19.52), atan(-19.52), 0.000001);
  ck_assert_double_eq_tol(s21_atan(0.1), atan(0.1), 0.000001);
  ////////////////////////////////////////////////////////////////////////////////////
  // сторонние тесты
  ck_assert_int_eq(s21_atan(0.12), atan(0.12));
  ck_assert_int_eq(s21_atan(0.987651234), atan(0.987651234));
  ck_assert_int_eq(s21_atan(0.1243), atan(0.1243));
  ck_assert_int_eq(s21_atan(1), atan(1));
  ck_assert_int_eq(s21_atan(-1), atan(-1));
  ck_assert_int_eq(s21_atan(-12345), atan(-12345));
  ck_assert_int_eq(s21_atan(12345), atan(12345));
  ck_assert_int_eq(s21_atan(0), atan(0));
  ck_assert_int_eq(s21_atan(0.001), atan(0.001));
}
END_TEST

Suite *suite_func(void) {
  Suite *st = suite_create("New_Suite");
  ////////////////////  НЕ ТРИГОНОМЕТРИЯ  //////////////////
  TCase *tc_abs = tcase_create("NEW_Test-ABS");
  TCase *tc_fabs = tcase_create("NEW_Test-FABS");
  TCase *tc_ceil = tcase_create("NEW_Test-CEIL");
  TCase *tc_floor = tcase_create("NEW_Test-FLOOR");
  TCase *tc_exp = tcase_create("NEW_Test-EXP");

  TCase *tc_log = tcase_create("NEW_Test-LOG");
  TCase *tc_fmod = tcase_create("NEW_Test-FMOD");
  TCase *tc_pow = tcase_create("NEW_Test-POW");
  TCase *tc_sqrt = tcase_create("NEW_Test-SQRT");

  ////////////////////  ТРИГОНОМЕТРИЯ  ///////////////////////////

  TCase *tc_sin = tcase_create("NEW_Test-SIN");
  TCase *tc_asin = tcase_create("NEW_Test-ASIN");
  TCase *tc_cos = tcase_create("NEW_Test-COS");
  TCase *tc_acos = tcase_create("NEW_Test-ACOS");
  TCase *tc_tan = tcase_create("NEW_Test-TAN");
  TCase *tc_atan = tcase_create("NEW_Test-ATAN");

  ////////////////////  НЕ ТРИГОНОМЕТРИЯ  //////////////////
  suite_add_tcase(st, tc_abs);
  tcase_add_test(tc_abs, abs_tests);
  suite_add_tcase(st, tc_fabs);

  tcase_add_test(tc_fabs, fabs_tests);
  suite_add_tcase(st, tc_ceil);

  tcase_add_test(tc_ceil, ceil_tests);
  suite_add_tcase(st, tc_floor);

  tcase_add_test(tc_floor, floor_tests);
  suite_add_tcase(st, tc_exp);

  tcase_add_test(tc_exp, exp_tests);
  suite_add_tcase(st, tc_log);

  tcase_add_test(tc_log, log_tests);
  suite_add_tcase(st, tc_fmod);

  tcase_add_test(tc_fmod, fmod_tests);
  suite_add_tcase(st, tc_pow);

  tcase_add_test(tc_pow, pow_tests);
  suite_add_tcase(st, tc_sqrt);
  tcase_add_test(tc_sqrt, sqrt_tests);

  ////////////////////  ТРИГОНОМЕТРИЯ  ///////////////////////////
  suite_add_tcase(st, tc_sin);
  tcase_add_test(tc_sin, sin_tests);

  suite_add_tcase(st, tc_asin);
  tcase_add_test(tc_asin, asin_tests);

  suite_add_tcase(st, tc_cos);
  tcase_add_test(tc_cos, cos_tests);

  suite_add_tcase(st, tc_acos);
  tcase_add_test(tc_acos, acos_tests);

  suite_add_tcase(st, tc_tan);
  tcase_add_test(tc_tan, tan_tests);

  suite_add_tcase(st, tc_atan);
  tcase_add_test(tc_atan, atan_tests);

  return st;
}

int main(void) {
  Suite *sut = suite_func();
  SRunner *srun = srunner_create(sut);
  srunner_run_all(srun, CK_VERBOSE);
  srunner_free(srun);
  return 0;
}
