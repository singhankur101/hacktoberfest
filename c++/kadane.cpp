#include <iostream>

using namespace std;

int max_sum(int* arr, int n)
{
  int max_so_far = 0;
  int max_ending_here = 0;

  for (int i = 0; i < n; i++)
  {
    max_ending_here += arr[i];

    if (max_ending_here <= 0)
      max_ending_here = 0;
    if (max_so_far < max_ending_here)
      max_so_far = max_ending_here;
  }

  return max_so_far;
}

int main(void)
{
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  printf("%d\n", max_sum(arr,  n));
}
