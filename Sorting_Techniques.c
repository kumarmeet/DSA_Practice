#include <stdio.h>
#include <stdlib.h>

//Bubble Sort
//adaptive and stable
///time complexity min O(n) max O(n^2)
void bubble_sort(int *arr, int size)
{
    int flag;

    for(int i = 0; i < size -1; i++)
    {
        flag = 1;
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        if(flag)
            break;
    }
}

//Insertion Sort
//Designed for Linked List
//Adaptive and
///time complexity min O(n) max O(n^2)
void insertion_sort(int *arr, int size)
{
    int temp, j;
    for(int i = 1; i < size; i++)
    {
        j = i - 1;
        temp = arr[i];

        while(j > -1 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
