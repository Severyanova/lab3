```c
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int k = *a;
    *a = *b;
    *b = k;
}

int quicksort(int *arr, int left, int right, int size) 
{
    int l = left; 
    int r = right; 
    int pivot = arr[(l + r)/ 2]; 
    while(l <= r) 
    {
      while(arr[l] < pivot) 
      {
        l++;
      }
      while(arr[r] > pivot) 
      r--;
      if(l <= r)
      swap(&arr[l++], &arr[r--]);
    }
    if(left < r) 
    {
      quicksort(arr, left, r, size);
    }
    if(right > l) 
    {
      quicksort(arr, l, right, size);
    }
    return 0;
}

void heapify(int *nums, int root, int bottom, int size)
{
    int max; 
    int done = 0; 
    while ((root * 2 <= bottom) && (!done)) 
    {
      if (root * 2 == bottom)   
      max = root * 2;  
      else if (nums[root * 2] > nums[root * 2 + 1])
      max = root * 2;
      else
      max = root * 2 + 1;
      if (nums[root] < nums[max]) 
      {
      swap(&nums[max], &nums[root]);
      root = max;
      }
      else 
      done = 1; 
    }
}


void heapSort(int *nums, int arr_size, int n)
{
  // Формирование низа пирамиды
  for (int i = (arr_size / 2); i >= 0; i--)
    heapify(nums, i, arr_size - 1, n);
  // Сортировка остальных элементов
  for (int i = arr_size - 1; i >= 1; i--) 
  {
    swap(&nums[0], &nums[i]);
    heapify(nums, 0, i - 1, n);
  }
}

void read_arr(int *a, int *b, int n) 
{
    int x;
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &x); 
        a[i] = x; 
        b[i] = x; 
    }
}

void print_arr(int *a, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d", a[i]);
        if (i != n-1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() 
{
    int size; 
    scanf("%d", &size); 
    int *arr_1 = malloc(size * sizeof(int)); 
    int *arr_2 = malloc(size * sizeof(int));
    read_arr(arr_1, arr_2, size); 
    quicksort(arr_1, 0, size - 1, size); 
    heapSort(arr_2, size, size);
    print_arr(arr_1, size); 
    return 0;
}
```

