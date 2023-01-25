#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	int arr[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	int ans = 0;
	int key = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] % 2 == 0 && i != 0) {
			key = i;
			arr[key-1]++;
			arr[key+1]++;
			ans += 2;
		}
	}
	printf("%d\n", ans);

	return 0;
}
