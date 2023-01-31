#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define maxN 30

int main() {
  int arr[maxN+1];
	for (int i = 1; i <= maxN; i++) arr[i] = true;

  for (int i = 2; i <= (int) sqrt(maxN); i++) {
    for (int j = 2; j <= maxN / i; j++) {
			if (arr[j]) arr[i*j] = false;
    }
  }

  for (int i = 0; i < maxN+1; i++) {
    if (arr[i]) printf("%d ", i);
  }
	printf("\n");
  return 0;
}