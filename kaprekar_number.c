#include <stdio.h>
#include <math.h>

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
	return n;
}

void num_to_arr(int number, int *arr, int N) {
	for (int i = N-1; i >= 0; i--) {
		arr[i] = number % 10;
		number = number / 10;
	}
}

int main() {
	int new_arr[maxN];
	
	return 0;
}
