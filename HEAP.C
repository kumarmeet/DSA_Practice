#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Heap[] = {10, 20, 30, 25, 5, 40, 35};

    size_t size = sizeof(Heap) / sizeof(Heap[0]);

    for(int i = 1; i <= size; i++)
        max_binary_heap_insertion(Heap, i);

    for(int i = 0; i < size; i++)
        printf("%d ", Heap[i]);

    return 0;
}

//max heap
void max_binary_heap_insertion(int *H, int n)
{
    int temp, i = n;
    temp = H[i];

    while(i > 1 && temp > H[(i-1)/2])
    {
        H[i] = H[(i - 1)/2];
        i = (i-1) / 2;
    }

    H[i] = temp;
}

//min heap
void min_binary_heap_insertion(int *H, int n)
{
    int temp, i = n;
    temp = H[n];

     while(i > 1 && temp > H[(i-1)/2])
    {
        H[i] = H[(i - 1)/2];
        i = (i-1) / 2;
    }

    H[i] = temp;
}

int delete_max_binary_heap(int *H, int n) // Heap Sort as well as priority queue also
{
    int i, j, val;  ////0, 40, 25, 35, 10, 5, 20, 30

    val = H[1];

    H[1] = H[n];

    i = 1;
    j = i * 2; //left child 2 * i

    while(j < n - 1)
    {
        if(H[j + 1] > H[j])
            j++;
        if(H[i] < H[j])
        {
            swap(&H[i], &H[j]);
            i = j;
            j = 2 * j; //  go to left child
        }
        else
            break;
    }

    return val;
}

void Heapify(int H[], int n)
{
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i = (n / 2) - 1; i >= 0; i--)
    {

        int j = 2 * i + 1;  // Left child for current i

        while(j < n - 1)
        {
            // Compare left and right children of current i
            if (H[j] < H[j + 1])
                j = j + 1;

            // Compare parent and largest child
            if (H[i] < H[j])
            {
                swap(&H[i], &H[j]);
                i = j;
                j = 2 * i + 1;
            }
            else
                break;
        }
    }
}

void swap(int *i, int *j)
{
    int k;

    k = *i;
    *i = *j;
    *j = k;
}
