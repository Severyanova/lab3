## Отчет по практической работе №7
Выполнил  
Студент группы 739-1  
Северьянова А.Д.


### 1 Введение
Цель работы: освоение алгоритмов сортировки массивов ("Быстрая сортировка", "Пирамидальная сортировка").

В таблице 1 представлены задачи, которые необходимо выполнить.

Таблица 1 - Поставленные задачи 

| Номер | Задание |
| ------------- | ------------- |
| 1| Должны быть выполнены предыдущие работы |
|2 | Прочитать про односвязные списки на СИ |
|3| Написать программу |
|4| Настроить pipeline |
|5| Написать отчет по работе в разметке Markdown (README.md)|
|6| Залить на gitlab и убедиться, что pipeline проходит успешно|
|7| Защитить работу у преподавателя|


### 2 Ход работы

### 2.1 Работа с программой

Быстрая сортировка — один из самых известных и широко используемых алгоритмов сортировки. Среднее время работы O(nlogn), что является асимптотически оптимальным временем работы для алгоритма, основанного на сравнении. Хотя время работы алгоритма для массива из n элементов в худшем случае может составить Θ(n2), на практике этот алгоритм является одним из самых быстрых.

Код для быстрой сортировки представлен ниже:

```c
 int quicksort(int *arr, int left, int right, int size)
 {
    int l = left;
    int r = right;
    int pivot = arr[(l + r)/ 2];
    while(l <= r) {
      while(arr[l] < pivot) {
        l++;
      }
      while(arr[r] > pivot) 
      r--;
      if(l <= r)
      swap(&arr[l++], &arr[r--]);
    }
    if(left < r) {
      quicksort(arr, left, r, size);
    }
    if(right > l) {
      quicksort(arr, l, right, size);
    }
    return 0;
}
``` 

Пирамидальная сортировка  — алгоритм сортировки, работающий в худшем, в среднем и в лучшем случае (то есть гарантированно) за О(n log n) операций при сортировке n элементов. Количество применяемой служебной памяти не зависит от размера массива (то есть, O(1)).

Код для пирамидальной сортировки представлен ниже: 

```c
void heapSort(int *nums, int arr_size, int n)
{
  for (int i = (arr_size / 2); i >= 0; i--)
    heapify(nums, i, arr_size - 1, n);
    
  for (int i = arr_size - 1; i >= 1; i--)
  {
    swap(&nums[0], &nums[i]);
    heapify(nums, 0, i - 1, n);
  }
}
``` 

Полный код программы можно найти в приложении А.

Пример работы программы представлен на рисунке 1.

![](https://sun9-51.userapi.com/impg/27gxFLAdF-YMmcaVRSGRTQ56WPkxeaRjg3EPVw/cm9r7-IqDYk.jpg?size=287x57&quality=96&sign=4833a2b44450b36b722f98cdef575870&type=album)

Рисунок 1 — Результат работы программы.

Из рисунка 1, что программа работает корректно (выдает ожидаемый результат), а значит код написан правильно. 

## 3 Заключение

В результате выполнения лабораторной работы были достигнуты поставленные цели и решины необходимые задачи. Освоены алгоритмы сортировки массивов. В частности "Быстрая сортировка" и "Пирамидальная сортировка". По ходу выполнения лабораторной работы были закреплены теоретические сведенья, полученные на лекционных занятиях.

## Приложение A

(обязательное)

Листининг кода  первой программы

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

