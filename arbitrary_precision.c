#include <stdio.h>

#define maxN 500

int multiply(int x, int arr[], int N);
void factorial(int n);

int main()
{
	factorial(100);
	printf("\n");
	return 0;
}

int multiply(int x, int arr[], int N) 
{
	int carry = 0;
	
	for (int i = 0; i < N; i++) {
		int prod = arr[i] * x + carry;
		arr[i] = prod % 10;
		carry  = prod / 10;
	}
	while (carry) {
		arr[N] = carry % 10;
		carry = carry / 10;
		N++;
	}
	return N;
}

void factorial(int n)
{
	int arr[maxN];
	arr[0] = 1;
	int N = 1;
	
	for (int x = 2; x <= n; x++) 
		N = multiply(x, arr, N);
	
	for (int i = N - 1; i >= 0; i--)
	printf("%d", arr[i]);
}
