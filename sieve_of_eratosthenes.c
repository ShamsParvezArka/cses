#include <stdio.h>
#include <math.h>

#define maxN 100000

int main() {
  int arr[maxN+1];
	arr[1] = 1;
  for (int i = 2; i <= maxN; i++) arr[i] = 1;

  for (int i = 2; i <= (int) sqrt(maxN); i++) {
    for (int j = 2; j <= maxN / i; j++) {
			if (arr[j]) arr[i*j] = 0;
    }
  }

  for (int i = 0; i < maxN+1; i++) {
    if (arr[i]) printf("%d ", i);
  }
	printf("\n");
  return 0;
}