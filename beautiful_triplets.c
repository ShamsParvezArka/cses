#include <stdio.h>

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	int ans = 0;
	int i, j, k;
	for (int z = 0; z < n; z++) {
		i = arr[z];
		j = d + i;
		k = 2*d + i;
		for (int y = 0; y < n; y++) {
			if (arr[y] != i) {
				if (arr[y] == j) {
					for (int x = y; x < n; x++) {
						if (arr[x] != i) {
							if (arr[x] == k) {
								ans++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
