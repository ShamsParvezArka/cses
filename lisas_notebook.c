#include <stdio.h>

int main() {
	int N, k;
	scanf("%d %d", &N, &k);
	int arr[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	int total_problems = 0;
	for (int i = 0; i < N; i++) {
		total_problems += arr[i];
	}
	int total_pages = total_problems / k;
	
	//int important_q = 0;
	int index = 0;
	for (int i = 1; i <= total_pages; i++) {
		for (int j = 1; j <= arr[index]; j++) {
			if (j > k) i++;
			printf("(%d, %d),", i, j);
		}
		index++;
		printf("\n");
	}
	
	//printf("%d\n", important_q);
	
	return 0;
}
