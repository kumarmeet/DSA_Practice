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
//Adaptive and stable
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

//Selection Sort
//Not Adaptive and Not Stable
///time complexity min O(n) max O(n^2)
void selection_sort(int *arr, int size)
{
    int i, j, k;

    for(i = 0; i < size - 1; i++)
    {
        for(j = k = i; j < size; j++)
        {
            if(arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(&arr[i], &arr[k]);
    }
}

//Quick Sort
//Not Adaptive and Not Stable
///if partitioning is only in middle O(nlogn)
///if partitioning is not in middle O(n^2) if already sorted
///if pivot is in middle O(nlogn) if already sorted
//last index considered infinity

void quick_sort(int *arr, int low, int high)
{
    int j;
    if(low < high) //atleast two elements
    {
        j = partition(arr,low,high);
        quick_sort(arr, low, j);
        quick_sort(arr, j + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    do
    {
        do
        {
            i++;
        }
        while(arr[i] <= pivot);
        do
        {
            j--;
        }
        while(arr[j] > pivot);

        if(i < j)
            swap(&arr[i], &arr[j]);
    }
    while(i < j);

    swap(&arr[low], &arr[j]);
    return j;
}
//Quick Sort End

//Merge
///Lists must be arranged in sorted order
void mergeing_two(int *merge, int *arr1, int *arr2, int size1, int size2)
{
    int i, j, k;
    size_t size3 = (sizeof(arr1) / sizeof(arr1[0])) + sizeof(arr2) / sizeof(arr2[0]);

    merge[size3];

    i = j = k = 0;

    while(i < size1 && j < size2)
    {
        if(arr1[i] < arr2[j])
            merge[k++] = arr1[i++];
        else
            merge[k++] = arr2[j++];
    }

    while(i < size1)
        merge[k++] = arr1[i++];

    while(j < size2)
        merge[k++] = arr2[j++];
}

//this is for one array
void merge_one(int A[],int l,int mid,int h)
{
    int i = l,j = mid + 1, k = l;
    int B[100];
    while(i <= mid && j <= h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i <= mid; i++)
        B[k++] = A[i];
    for(; j <= h; j++)
        B[k++] = A[j];
    for(i=l; i <= h; i++)
        A[i] = B[i];
}

//Merge Sort Iterative Method
///Time complexity O(nlogn)
void i_merge_sort(int *A, int n)
{
    int p, l, h, mid, i;

    for(p = 2; p <= n; p = p * 2)
    {
        for(i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge_one(A,l,mid,h);
        }
        if(n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge_one(A, l, mid, n-1);
        }
    }
    if(p / 2 < n)
        merge_one(A, 0, p / 2 - 1, n - 1);
}

//Merge Sort recursive Method
///time complexity is O(nlogn)
void merge_sort(int *arr, int l, int h)
{
    int mid;

    if(l < h)
    {
        mid = (l + h) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, h);
        merge_one(arr, l, mid, h);
    }
}
//Merge End

//Count Sort
///time complexity O(n)
//it takes more space

void count_sort(int *arr, int size)
{
    int max = find_max(arr, size);
    int count[max + 1];

    for(int i = 0; i < max + 1; i++)
        count[i] = 0;

    for(int i = 0; i < size; i++)
        count[arr[i]]++;

    int i = 0, j = 0;
    while(i < max + 1)
    {
        if(count[i] > 0)
        {
            arr[j++] = i;
            count[i]--;
        }
        else
            i++;
    }
}

int find_max(int *arr, int size)
{
    int i, max = arr[0];
    for(i = 1; i < size; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
//Count Sort End

//Shell Sort
///time complexity is O(nlogn)
//this is useful for large number of elements

void shell_sort(int A[],int n)
{
    int gap, i, j, temp;

    for(gap = n / 2; gap >= 1; gap / = 2)
    {
        for(i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while(j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
