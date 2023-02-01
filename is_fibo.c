#include <stdio.h>
#include <stdbool.h>

bool is_fibonacci(long n) {
  long a = 0, b = 1;
  if (n == a || n == b) return true;
  long checker = a + b;
  while (checker <= n) {
    if (checker == n) return true;
    a = b;
    b = checker;
    checker = a + b;
  }
  return false;
}

int main() {
  long ts, n;
  scanf("%ld", &ts);
  while (ts--) {
    scanf("%ld", &n);
    if (is_fibonacci(n)) printf("IsFibo\n");
    else printf("IsNotFibo\n");
  }
  return 0;
}