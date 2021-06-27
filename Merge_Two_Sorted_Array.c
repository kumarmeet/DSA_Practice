#include <stdio.h>
#include <stdlib.h>
//when merging array they should be sorted
int* merge_sorted_array(int*, int, int*, int, int*);
void sort(int*, int)

int main()
{
    int arr1[] = {10,15,36,99,74,51};
    int arr2[] = {66,12,77,140,44};
    int length = (sizeof(arr1) + sizeof(arr2)) / sizeof(int);

    sort(arr1, sizeof(arr1) / sizeof(int));
    sort(arr2, sizeof(arr2) / sizeof(int));

    int arr3[length];
    int *p;

    p = merge_sorted_array(arr1, 5, arr2, 5, arr3);

    for(int i = 0; i < 10; i++)
        printf("%d ", p[i]);

    return 0;
}

void sort(int *arr, int len)
{
    int i, j, temp;

    for(i = 0; i < len; i++)
        for(j = i + 1; j < len; j++)
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int* merge_sorted_array(int *arr1, int size1, int *arr2, int size2, int *arr3)
{
    int i, j, k;
    arr3[size1 + size2];
    i = j = k = 0;

    while(i < size1 && j < size2)
    {
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    for(; i < size1 ; i++)
        arr3[k++] = arr1[i];
    for(; j < size2 ; j++)
        arr3[k++] = arr2[j];

    return arr3;
}

