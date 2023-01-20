#include <stdio.h>

int find_repeted_number(int *arr, int N) {
	int count, tmp, key;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i] == arr[j]) {
				count++;
			}
		}
		if (count > tmp) {
			tmp = count;
			key = arr[i];
			count = 0;
		} else {
			count = 0;
		}
	}
	return key;
}

int main() {
	int n, ans;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int rmax = find_repeted_number(arr, n);
	for (int i = 0; i < n; i++) {
		if (arr[i] != rmax) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

