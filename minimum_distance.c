#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	int N;
	scanf("%d", &N);
	int arr[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	int key;
	int tmp = 0;
	int distance = 0;
	for (int i = 0; i < N; i++) {
		key = i;
		for (int j = i+1; j < N; j++) {
			if (arr[key] == arr[j]) {
				tmp = abs(key - j);
				break;
			}
		}
		if (distance > tmp) distance = tmp;
	}
	if (distance == 0) {
		printf("-1\n");
	} else {
		printf("%d\n", distance);
	}
	return 0;
}
