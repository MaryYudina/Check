#ifndef _S_21_MATH_H_
#define _S_21_MATH_H_

#define _S_21_PI_ 3.14159265358979324
#define _S_21_N_PI_ -3.14159265358979324
#define _S_21_M_PI_ 3.14159265358979324 / 2
#define _S_21_EPS_ 1e-6
#define _S_21_E_ 2.7182818284590452
#define _S_21_INF_ (1.0 / 0.0)
#define _S_21_N_INF_ ((-1.0) / 0.0)
#define _S_21_NAN_ (0.0 / 0.0)
#define _S_21_N_NAN_ (-0.0 / 0.0)
#define _S_21_MAX_DOUBLE_ 1.7976931348623157e308

/////////////////// основные функции ////////////////////////
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

//////////////////// доп функции ///////////////////////////
long double s21_factorial(long long int x);
int s21_is_nan_answer(double x, double y);
long double s21_fmax(double x, double y);

////////////////////////////////////////////////////////////
long double s21_pow_int(double base, long long int exp);
#endif