#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() 
{
	char query[] = {"abcdefghijklmnopqrstuvwxyz"};
	char message[100];
	scanf("%[^\n]%*c", message);

	message[0] = tolower(message[0]);
	for (size_t i = 0; i < strlen(query); i++) {
		char search = query[i];
		if (!memchr(message, search, strlen(message))) {
			printf("not pangram\n");
			return 0;
		}
	}

	printf("pangram\n");
	return 0;
}
