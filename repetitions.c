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
	int16_t *vector2 = (int16_t*) malloc(SHRT_MAX * sizeof(short));
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

int main() {
	char vector2[LEN];
	char ch = getchar();
	int64_t index = 0;
	int64_t ans = 1;
	int64_t count = 1;
	while (ch != EOF) {
		vector2[index] = ch;
		ch = getchar();
		index++;
	}
	for (int i = 0; i < index - 1; i++) {
		if (vector2[i] == vector2[i+1]) {
			count++;	
		} else {
			count = 1;
		}
		ans = max(ans, count);
	}
	printf("%ld", ans);
	return 0;
}
