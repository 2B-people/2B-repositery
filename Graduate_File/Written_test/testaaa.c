
#include <stdio.h>

void change(int *ptr, int val) { *ptr = val; }

int main() {
  int x = 10;
  for (int i = 1; i <= 3; i++) {
    if (x % i == 0) {
      change(&x, x / i);
    }
  }

  printf("%d\n", x);
  return 0;
}