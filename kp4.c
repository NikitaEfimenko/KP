#include <stdio.h>
#include <math.h>
#define EPS 0.00001f

const double a = 0.f;
const double b = 1.f;

typedef struct RESULT {
  double x;
  double a;
  double b;
} RESULT;

typedef double(*FN)(double);
typedef double(*MFN)(FN, double*, double*);
typedef double * pd;

double f(double x) {
  return sqrt(1.f - x) - tan(x);
}

double sign(double x) {
  return x < 0 ? -1.f : 1.f;
}

double dx(FN f, double x) {
  return (f(x + EPS) - f(x)) / EPS;
}
double d2x(FN f, double x) {
  return (dx(f, x + EPS) - dx(f, x)) / EPS;
}

double abs(double x) {
  return x * sign(x);
}

double solve(
  MFN method,
  FN f,
  double* a,
  double* b
) {
  double x;
  while(abs(*a - *b) >= EPS) {
    x = method(f, a, b);
  }
  return x;
}

double bisection_step(FN f, pd a, pd b) {
  const double mid = (*a + *b) / 2.f;
  const double fa = f(*a);
  const double fx = f(mid);
  if (fa * fx > 0) {
    *a = mid;
  } else {
    *b = mid;
  }
  return mid;
}

RESULT bisection_step_v2(FN f, const double a, const double b) {
  RESULT r;
  const double mid = (a + b) / 2.f;
  const double fa = f(a);
  const double fx = f(mid);
  r = (RESULT) { mid, a, b };
  if (fa * fx > 0) {
    r.a = mid;
  } else {
    r.b = mid;
  }
  return r;
}

int main() {
  // double a = 0.f;
  // double b = 1.f;
  printf("dx|x0 = %.4lf\n", dx(f, 0.f));
  //printf("x0 = %.4lf\n", bisection_step_v2(f, a, b));
  return 0;
}