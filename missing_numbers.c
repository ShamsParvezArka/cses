#include <stdio.h>

int main() {
	long int n;
	scanf("%ld", &n);
	long int vector[n-1];
	long int given_sum = 0;
	for (int i = 0; i < (n - 1); i++) {
		scanf("%ld", &vector[i]);
		given_sum += vector[i];
	}
	long int actual_sum = (n * (n + 1)) / 2;
	long int ans = actual_sum - given_sum;
	printf("%ld", ans);
	
	return 0;
}
