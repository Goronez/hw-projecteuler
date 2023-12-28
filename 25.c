#include <stdio.h>
#define E 1e999L
#include <math.h>

int yes(long double f_n) {
  if (E <= f_n)
    return 1;
  return 0;
}

long double fib(int n) {
  long double phi = (1 + powl(5, 0.5)) / 2;
  long double vphi = (1 - phi);
  long double f_n = (powl(phi, n) - powl(vphi, n)) / (phi - vphi);
  return f_n;
}

int main(void) {
  int n = 2;
  while (!yes(fib(n))) {
    n++;
  }

  printf("%d\n", n);
  //	printf("%Lf\n", fib(4782));
  return 0;
}
