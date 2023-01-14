#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#define LEN 1000000

int64_t vmax(int64_t vector2[], int64_t n) {
	int64_t vmax = INT_MIN;
	for (int64_t i = 0; i < n; i++) {
		if (vmax < vector2[i]) {
			vmax = vector2[i];
		}
	}
	return vmax;
}
int64_t vmin(int64_t vector2[], int64_t n) {
	int64_t vmin = INT_MAX;
	for (int64_t i = 0; i < n; i++) {
		if (vmin > vector2[i]) {
			vmin = vector2[i];
		}
	}
	return vmin;
}
int64_t vmin_non_zero(int64_t vector2[], int64_t n) {
	int64_t vmin_non_zero = INT_MAX;
	for (int64_t i = 0; i < n; i++) {
		if (vmin_non_zero > vector2[i] && vector2[i] > 0) {
			vmin_non_zero = vector2[i];
		}
	}
	return vmin_non_zero;
}
int16_t *parse_vector2(int64_t n) {
	int16_t *vector2 = (int16_t*) malloc(sizeof(int16_t));
	int16_t length = (int16_t) floor(log10(n));
	for (int i = 0; i < length; i++) {
		vector2[length - i] = n % 2;
		n = n / 10;
	}
	return vector2;
}
int64_t max(int64_t a, int64_t b) {
	return (a > b)?a : b;
}
int64_t min(int64_t a, int64_t b) {
	return (a > b)?a : b;
}

int main() {
	uint32_t tc;
	scanf("%u", &tc);

	int64_t x, y;
	while (tc--) {
		scanf("%ld %ld", &x, &y);
		if (x >= y) {
			if ((x & 1) == 0) {
				printf("%ld\n", (x*x) - y+1);
			} else {
				printf("%ld\n", (x-1)*(x-1) + y);
			}
		} else {
			if ((y & 1) == 1) {
				printf("%ld\n", (y*y) - x+1);
			} else {
				printf("%ld\n", (y-1)*(y-1) +x);
			}
		}
	}
	return 0;
}

