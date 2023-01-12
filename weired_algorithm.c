#include <stdio.h>

int main() {
	long int n;
	scanf("%ld", &n);
	long int ans = 0;
	if (n == 1) {
		printf("1");
	}
	else {
		printf("%ld ", n);
		while (ans != 1) {
			if (n % 2 == 0) {
				n = n / 2;
				ans = n;
			}
			else if (n % 2 != 0){
				n = (n * 3) + 1;
				ans = n;
			}
			printf("%ld ", ans);
		}
	}
	return 0;
}
