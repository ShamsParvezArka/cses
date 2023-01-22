#include <stdio.h>
#include <stdlib.h>


int main() {
	int maxN = 1000;
	char str[maxN];
	fgets(str, maxN, stdin);
	str[0] = (int) str[0] + 32;
	char key;
	for (int i = 0; i < maxN; i++) {
		key = str[i];
		for (int j = i+1; j < maxN; j++) {
			if (key == str[j]) {
				for (int k = j; k < maxN; k++) {
					str[k] = str[k+1];
				}
				j--;
				maxN--;
			}
		}
	}
	
	int index = 0;
	int count = 0;
	while (str[index] != '\n') {
		if (str[index] != ' ') {
			count++;
		}
		index++;
	}
	if (count == 26) {
		printf("pangram");
	} else {
		printf("not pangram");
	}
}
