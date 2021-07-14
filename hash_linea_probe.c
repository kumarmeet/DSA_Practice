#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    int HT_LP[10] = {0};

    insert(HT_LP, 12);
    insert(HT_LP, 36);
    insert(HT_LP, 42);
    insert(HT_LP, 52);

    for(int i = 0; i < 10; i++)
        printf("[%d] %d \n", i, HT_LP[i]);

    return 0;
}

int search(int *H, int key)
{
    int index = hash(key);
    int i = 0;

    while(H[(index + i) % SIZE] != 0)
        i++;

    return (index + i) % SIZE;
}

void insert(int *H, int key)
{
    int index = hash(key);

    if(H[index] != 0)
        index = probe(H, key);

    H[index] = key;
}

int probe(int *H, int key)
{
    int index = hash(key);
    int i = 0;

    while(H[(index + i) % SIZE] != 0)
        i++;

    return (index + i) % SIZE;
}

int hash(int key)
{
    return key % SIZE;
}
