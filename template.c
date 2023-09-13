#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b));
#define MIN(a, b) ((a) < (b) ? (a) : (b));

void  swap_int(int *x, int *y);
int   compare_int(const void *a, const void *b);
float compare_float(const void *a, const void *b);
float randf(float a, float b); //range -> [a, b) 

int main()
{
    srand(time(NULL));
#if 0
    const int size = 10;
    int *container = malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        container[i] = (int) randf(1, 5);
    }
    qsort(container, size, sizeof(container[0]), compare_int);
    free(container);
#endif

    int key = 4;
    int arr[5] = {3, 1, 4, 1, 5};
    int *position = (int*) bsearch(&key, arr, 5, sizeof(int), compare_int);

    if (position == NULL) {
        printf("NOT FOUND\n");
    }
    else {
        printf("FOUND\n");
    }

    return 0;
}

int compare_int(const void *a, const void *b)
{
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;

    if (arg1 > arg2) return 1;
    if (arg1 < arg2) return -1;
    return 0;
}

float compare_float(const void *a, const void *b)
{
    float arg1 = *(float*)a;
    float arg2 = *(float*)b;

    if (arg1 > arg2) return 1;
    if (arg1 < arg2) return -1;
    return 0;
}

float randf(float a, float b) 
{
    float r = (float) rand() / (float) RAND_MAX;
    if (r*b < a) {
        return r*b + (a - r);
    }
    return r*b;
}

void swap_int(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
