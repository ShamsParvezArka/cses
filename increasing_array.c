#include <stdio.h>
#include <stdlib.h>

#define LEN 1000000

int main() {
	long int n;
	scanf("%ld", &n);
	long int vector[n];
	for (int i = 0; i < n; i++) {
		scanf("%ld", &vector[i]);
	}
	long int move = 0;
	for (int i = 1; i < n; i++) {
		if (vector[i] < vector[i-1]) {
			move += vector[i-1] - vector[i];
			vector[i] = vector[i] + (vector[i-1] - vector[i]);
		}
	}
	printf("%ld", move);
	return 0;
}
