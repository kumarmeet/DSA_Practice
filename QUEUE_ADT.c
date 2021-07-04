#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
  int front;
  int rear;
  int size;
  int *arr;
}Q;

void display(Q queue)
{
    for(int i = queue.front + 1; i <= queue.rear; i++)
        printf("%d ", queue.arr[i]);
}

int deque(Q *queue)
{
    if(queue->front == queue->rear)
        printf("Underflow\n");
    else
        return queue->arr[++queue->front];
    return -1;
}

void enqueue(Q *queue, int item)
{
    if(queue->rear + 1 == queue->size)
        printf("Overflow\n");
    else
        queue->arr[++queue->rear] = item;
}

Q* create_queue(int size)
{
    Q *queue = (Q*)malloc(sizeof(Q));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->arr = (int*)malloc(sizeof(int) * size);
    return queue;
}
