#include <stdio.h>

#define maxN 4

void selection_sort(int *arr, int N) {
	int min, tmp;
	for (int i = 0; i < N; i++) {
		min = i;
		for (int j = i+1; j < N; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		tmp = arr[min];
		arr[min] = arr[i];
		arr[i] = tmp;
	}
}

int arr_to_num(int *arr, int N) {
	int n = 0;
	for (int i = 0; i < N; i++) {
		n = n*10 + arr[i];
	}
	return i;
}



int main() {
	int arr[maxN], arr_reverse[maxN];
	for (int i = 0; i < maxN; i++) {
		scanf("%d", &arr[i]);
	}
	selection_sort(arr, maxN);
	
	return 0;
}
