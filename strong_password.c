#include <stdio.h>
#include <ctype.h>

#define PASS_SIZE 64

int main() 
{
    char input[PASS_SIZE];
    fgets(input, PASS_SIZE, stdin);
            
    int actual_size = 0;
    int i = 0;
    while (input[i] != '\0') {
        actual_size++;
        i++;
    }

    input[0] = toupper(input[0]);
    for (int i = 0; i < actual_size; i++) {
        switch (input[i]) {
            case 's':
                input[i] = '$';
                break;
            case 'i':
                input[i] = '!';
                break;
            case 'o':
                input[i] = '(';
                for (int j = actual_size; j > i; j--) {
                    input[j + 1] = input[j];
                }
                input[i + 1] = ')';
                actual_size++;
                break;

            default:
                break;
        }
    }

    printf("%s.\n", input);
    

    return 0;
}