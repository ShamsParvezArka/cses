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
	
	int key, tmp;
	int distance = INT_MAX;
	for (int i = 0; i < N; i++) {
		key = i;
		for (int j = i+1; j < N; j++) {
			if (arr[key] == arr[j]) {
				tmp = abs(key - j);
				if (distance > tmp) distance = tmp;
			}
		}
	}
	if (distance == 0 || distance == INT_MAX) {
		printf("-1\n");
	} else printf("%d\n", distance);
	
	return 0;
}
