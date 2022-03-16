#include <stdio.h>

int main ()
{
  int arr[10] = {1, 2, 3, 40, 5, -6, 7, -8, 9, 10};
  int max = arr[0];
  int min = arr[0];
  int i;

  for (i = 0; i < 9; i++)
  {
    if (arr[i + 1] > max)
    {
      max = arr[i + 1];
    }

    if (arr[i + 1] < min)
    {
      min = arr[i + 1];
    }
  }

  printf("max: %d \n", max);
  printf("min: %d \n", min);
  return 0;
}
