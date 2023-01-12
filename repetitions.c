#include <stdio.h>
#include <stdlib.h>

#define LEN 1000000

long int maximum(long int vector[4]) {
	long int max = 1;
	for (int i = 0; i < 4; i++) {
		if (max < vector[i]) {
			max = vector[i];
		}
	}
	return max;
}

int main() {
	char vector_ch[LEN];
	long int index = 0;
	char ch = getchar();
	while (ch != EOF) {
		vector_ch[index] = ch;
		index++;
		ch = getchar();
	}

	long int A = 1;
	long int T = 1;
	long int G = 1;
	long int C = 1;

	for (int i = 0; i < index - 1; i++) {
		if (vector_ch[i] == 'A' && vector_ch[i] == vector_ch[i+1]) {
			A++;
		}
		else if (vector_ch[i] == 'T' && vector_ch[i] == vector_ch[i+1]) {
			T++;
		}
		else if (vector_ch[i] == 'G' && vector_ch[i] == vector_ch[i+1]) {
			G++;
		}
		else if (vector_ch[i] == 'C' && vector_ch[i] == vector_ch[i+1]) {
			C++;
		}
	}

	long int vector[4] = {A, T, G, C};
	printf("%ld", maximum(vector));
	return 0;
}
