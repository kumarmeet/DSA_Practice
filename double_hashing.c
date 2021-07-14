#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define PRIME 7

int main()
{
    int HT_LP[10] = {0};

    insert(HT_LP, 5);
    insert(HT_LP, 25);
    insert(HT_LP, 15);
    insert(HT_LP, 35);
    insert(HT_LP, 35);

    for(int i = 0; i < 10; i++)
        printf("[%d] %d \n", i, HT_LP[i]);

    return 0;
}

int search(int *H, int key)
{
    int index = hash(key);
    int i = 0;

    while(H[((hash(index) + i) * prime_hash(index)) % SIZE] != 0)
        i++;

    if (H[H[((hash(index) + i) * prime_hash(index)) % SIZE] != 0] == 0)
        return -1;

    return ((hash(index) + i) * prime_hash(index)) % SIZE;
}

void insert(int *H, int key)
{
    int index = hash(key);

    if(H[index] != 0)
        index = double_hashing(H, key);

    H[index] = key;
}

int double_hashing(int *H, int key)
{
    int index = hash(key);
    int i = 0;

    while(H[(hash(index) + i * prime_hash(index)) % SIZE] != 0)
        i++;

    return (index + i * prime_hash(index)) % SIZE;
}

int prime_hash(int key)
{
  return PRIME - (key % PRIME);
}

int hash(int key)
{
    return key % SIZE;
}
