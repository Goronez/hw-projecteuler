#include <stdio.h>

void fact(int *number, int num) {
  int i, fd;
  int carry, replace, product;

  fd = 0;
  number[fd] = 1;

  while (num != 1) {
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

    num--;
  }
}

int dsum(int *number) {
  int s = 0;

  for (int i = 0; i < 160; i++) {
    s += number[i];
  }
  return s;
}

int main(void) {
  int number[160];
  int sum;
  for (int i = 0; i < 160; i++) {
    number[i] = 0;
  }
  fact(number, 100);
  sum = dsum(number);
  printf("%d\n", sum);
  return 0;
}
