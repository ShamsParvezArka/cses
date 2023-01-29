#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define maxN 10

int max_element(int *arr, int N);
int min_element(int *arr, int N);
int arr_to_num(int *arr, int N);
int *remove_duplicates(int *arr, int N, int *new_length);
void num_to_arr(int n, int *arr, int N);

int partition(int *arr, int left, int right);
void swap(int *a, int *b);
void quicksort(int *arr, int left, int right);

bool modified_kaprekar_number(int n) {
  long squared_number = n * n;
  int number_length = floor(log10(squared_number));
  int arr[number_length];
  num_to_arr(squared_number, arr, number_length);
  int checker = 0;
  for (int i = 0; i < number_length; i++) {
    checker += arr[i];
  }
  if (n == checker) return true;
  else return false;
}

int main(void)
{
  int lower_limit, upper_limit;
  scanf("%d %d", &lower_limit, &upper_limit);

  for (int i = lower_limit; i <= upper_limit; i++) {
    //int counter;
    double squared_number = i * i;
    if (squared_number <= 1.00) {
      printf("1 ");
    } else {
      int length = ceil(log10(squared_number));
      int arr[length];
      for (int j = length - 1; j >= 0; j--) {
        arr[i] = length % 10;
        length = length / 10;
      }
      //counter = 0;
      for (int j = 0; j < length; j++) {
        printf("%d", arr[j]);
        //counter += arr[j];
      }
    }
    //if (counter == i) printf("%d ", i);
  }

  return 0;
}

int max_element(int *arr, int N)
{
  int max = INT_MIN;
  for (int i = 0; i < N; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  return max;
}

int min_element(int *arr, int N)
{
  int min = INT_MAX;
  for (int i = 0; i < N; i++)
  {
    if (arr[i] < min)
    {
      min = arr[i];
    }
  }
  return min;
}

void num_to_arr(int n, int *arr, int N)
{
  for (int i = N - 1; i >= 0; i--)
  {
    arr[i] = n % 10;
    n = n / 10;
  }
}

int arr_to_num(int *arr, int N)
{
  int number = 0;
  for (int i = 0; i < N; i++)
  {
    number = number * 10 + arr[i];
  }
  return number;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int *arr, int left, int right)
{
  int pivot = arr[right];
  int i = left - 1;
  for (int j = left; j <= right; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[right]);
  return i + 1;
}

void quicksort(int *arr, int left, int right)
{
  if (right > left)
  {
    int i = partition(arr, left, right);
    quicksort(arr, left, i - 1);
    quicksort(arr, i - 1, right);
  }
}

int *remove_duplicates(int *arr, int N, int *new_length)
{
  int *new_arr = (int *)malloc(N * sizeof(int));

  int unique_count = 0;
  for (int i = 0; i < N; i++)
  {
    bool is_unique = true;
    for (int j = 0; j < unique_count; j++)
    {
      if (new_arr[i] == arr[j])
      {
        is_unique = false;
        break;
      }
    }
    if (is_unique)
    {
      new_arr[unique_count] = arr[i];
      unique_count++;
    }
  }
  if (unique_count != N)
    new_arr = realloc(new_arr, unique_count * sizeof(int));
  *new_length = unique_count;
  return new_arr;
}