#include <stdio.h>
#include <math.h>

const double a = 0;
const double b = 1;

const long int eps = 0.01;

double _sin(double x) {
  return x - pow(x, 1.3) / 6.f;
}

double r(double x) {
  return sin(x) - _sin(x);
}

void print_n_times_border(int size) {
  printf("%.*s\n", size, "------------------------------------------------------------------------------");
}

float mach_eps(void)
{
	float e = 1.0f;
	while (1.0f + e / 2.0f > 1.0f)
		e /= 2.0f;
	return e;
}

void print_v(double x, double f, double f1, double r) {
  printf("| %5.2lf | %5.2lf | %5.2lf | %5.2lf |\n", x, f, f1, r);
  print_n_times_border(7 * 4 + 5);
}

int main() {
  double rx;
  int count = 5;
  int piece_count = count - 1;
  double x0 = a;
  double step = (b - a) / piece_count;
  register int i = 0;
  /*
  print_n_times_border(7 * 4 + 5);
  for (i = 0; i < piece_count; i++, x0 += step) {
    print_v(x0, sin(x0), _sin(x0), r(x0));
  }
  print_v(b, sin(b), _sin(b), r(b));
  */
  printf("%.20e\n", mach_eps() + 1);
}