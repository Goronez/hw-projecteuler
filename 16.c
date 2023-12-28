#include <stdio.h>

void power(int *number, int num) {
  int i, fd;
  int carry, replace, product, count;

  fd = 0;
  number[fd] = 1;

  for (count = 1; count <= 1000; count++) {
    carry = 0;
    for (i = 0; i <= fd; i++) {
      product = num * number[i] + carry;
      replace = product % 10;
      carry = product / 10;

      number[i] = replace;

      if ((i == fd) && (carry > 0)) {
        fd++;
      }
    }
  }
}

int dsum(int *number) {
  int s = 0;

  for (int i = 0; i < 330; i++) {
    s += number[i];
  }
  return s;
}

int main(void) {
  int number[330];
  int sum;
  for (int i = 0; i < 330; i++) {
    number[i] = 0;
  }
  power(number, 2);
  sum = dsum(number);
  printf("%d\n", sum);
  return 0;
}
