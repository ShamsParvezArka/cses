#include <stdio.h>
#include <string.h>

#define maxN 10

int main(void) 
{
	char string[maxN];
	for (size_t i = 0; i < maxN; i++) {
		scanf("%c", &string[i]);
	}
	int hour = (string[0] - 48) * 10 + (string[1] - 48);
	if (string[8] == 'P' && hour != 12) {
		hour+= 12;
		string[0] =  (hour / 10)+48;
		string[1] =  (hour % 10)+48;
	} 
	else if (string[8] == 'A' && hour == 12) {
		string[0] = '0';
		string[1] = '0';
	}
	for (size_t i = 0; i < maxN-2; i++) {
		printf("%c", string[i]);
	}
	printf("\n");
	return 0;
}

