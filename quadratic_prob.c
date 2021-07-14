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

    while(H[(index + i * i) % SIZE] != 0)
        i++;

    if (H[(index + i*i) % SIZE] == 0)
        return -1;

    return (index + i * i) % SIZE;
}

void insert(int *H, int key)
{
    int index = hash(key);

    if(H[index] != 0)
        index = quad_probe(H, key);

    H[index] = key;
}

int quad_probe(int *H, int key)
{
    int index = hash(key);
    int i = 0;

    while(H[(index + i * i) % SIZE] != 0)
        i++;

    return (index + i * i) % SIZE;
}

int hash(int key)
{
    return key % SIZE;
}
