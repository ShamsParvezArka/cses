#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	char *arr;
	arr = (char*) malloc(81 * sizeof(char));
	char ch = getchar();
	int length = 0;
	while (ch != '\n') {
		if (ch != ' ') {
			arr[length] = ch;
			length++;
		}
		ch = getchar();
	}
	arr = (char*) realloc(arr, length * sizeof(char));

	int row = floor(sqrt(length));
	int col = ceil(sqrt(length));
	char matrix[row][col];
	int tracker = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = arr[tracker];
			tracker++;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%c", matrix[j][i]);
		}
		printf(" ");
	}

	return 0;
}
