#include <stdio.h>

int main() {
	int N, ts;
	scanf("%d %d", &N, &ts);
	int arr[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	int i, j;
	while (ts--) {
		scanf("%d %d", &i, &j);
		int min = arr[i];
		for (int x = i; x <= j; x++) {
			if (arr[x] < min) {
				min = arr[x];
			}
		}
		printf("%d\n", min);
	}
	
	return 0;
}
