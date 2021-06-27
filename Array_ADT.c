#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int index;
    int capacity;
    int *arr;
} Array;

//dynamically reduce half memory reallocated when element is less than capacity
void halfArray(Array *A)
{
    A->arr = realloc(A->arr, (A->capacity / 2) * sizeof(int));
    A->capacity /= 2;
}

//dynamically increase half memory reallocated when capacity is full
void doubleArray(Array *A)
{
    A->arr = realloc(A->arr, (A->capacity * 2) * sizeof(int));
    A->capacity *= 2;
    A->index++;
}

int count(Array *A)
{
    return A->index + 1;
}

int isEmpty(Array *A)
{
    return (A->index < 0) ? 0: 1;
}

int get(Array *A, int index)
{
    return (index < 0 || index > A->index + 1) ? -1 : A->arr[index];
}

int search(Array *A, int element)
{
    for(int i = 0; i < A->index + 1; i++)
        if(element == A->arr[i])
            return 1;

    return 0;
}

void update(Array *A, int index, int element)
{
    if( index < 0 || index > A->index + 1)
        printf("\nInvalid Index");
    else
        A->arr[index] = element;
}

void delete_element(Array *A, int index)
{
    int i;

    if(A->index == -1)
        printf("\nUnderflow");
    else if( index < 0 || index > A->index + 1)
        printf("\nInvalid Index");
    else
    {
        for(i = index; i < A->index; i++)
            A->arr[i] = A->arr[i + 1];

        A->index--;
    }
}

void insert(Array *A, int index, int element)
{
    int i;

    if(A->index + 1 == A->capacity)
        printf("\nOverflow");
    else if(A->index == -1)
        printf("\nUnderflow");
    else if( index < 0 || index > A->index + 1)
        printf("\nInvalid Index");
    else
    {
        for(i = A->index + 1; i >= index; i--)
            A->arr[i] = A->arr[i - 1];

        A->arr[i + 1] = element;
        A->index++;
    }
}

void display(Array *A)
{
    for(int i = 0; i < A->index + 1; i++)
        printf("%d ", A->arr[i]);
}

void append(Array *A, int element)
{
    if(A->index + 1 == A->capacity)
        printf("\nOverflow");
    else
    {
        ++A->index;
        A->arr[A->index] = element;
    }
}

Array * create_array(int capacity)
{
    Array *A;
    A = (Array *)malloc(sizeof(Array));
    A->index = -1;
    A->capacity = capacity;
    A->arr = (int*) malloc(sizeof(int) * capacity);

    return A;
}


//int search(Array *A, int element) //recursively
//{
//    static int i = 0;
//    if(i == A->capacity + 1)
//        return 0;
//    if(element == A->arr[i])
//        return 1;
//    else
//    {
//        i++;
//        search(A, element);
//    }
//}

