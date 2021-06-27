#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {3,9,44,6,81,25,76,82,31,46,71};
    sort(arr, 11);
    printf("\n%d", recursion_binary_search(arr, 0, 11, 13));
    return 0;
}

int binary_search(int *arr, int low, int high, int key)
{
    int mid = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else if(key > arr[mid])
            low = mid + 1;
    }
    return -1;
}

int recursion_binary_search(int *arr, int low, int high, int key)
{
    static mid;

    if(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            return binary_search(arr, low, mid - 1, key);
        else
            return binary_search(arr, mid + 1, high, key);
    }
    return -1;
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
    for(i = 0; i < len; i++)
        printf("%d ", arr[i]);
}
