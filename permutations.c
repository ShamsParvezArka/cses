#include <stdio.h>
#include <stdlib.h>

int main() {
	long int n;
	scanf("%ld", &n);
	long int vector[n];

	if (n == 1) {
		printf("1");
	}
	else if (n == 2 || n == 3) {
		printf("NO SOLUTION");
	} else {
		for (int i = 1; i <= n; i++) {
			vector[i-1] = i;
		}
		for (int i = 0; i < n; i++) {
			if (vector[i] % 2 == 0) {
				printf("%ld ", vector[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			if (vector[i] % 2 != 0) {
				printf("%ld ", vector[i]);
			}
		}
	}
	return 0;
}
