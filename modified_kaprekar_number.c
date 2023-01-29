#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
  long lower_limit, upper_limit;
  scanf("%ld %ld", &lower_limit, &upper_limit);

  long determinant, r_split, l_split;
  bool flag = false;
  for (long i = lower_limit; i <= upper_limit; i++) {
    long squared_number = pow(i, 2);
    long digit = (int) floor(log10(i)) + 1;

    r_split = squared_number % (long) pow(10, digit);
    l_split = squared_number / (long) pow(10, digit);

    determinant = l_split + r_split;
    
    if (determinant == i) {
      printf("%ld ", i); 
      flag = true;
    }
  }

  if (flag == 0) printf("INVALID RANGE\n");
  return 0;
}