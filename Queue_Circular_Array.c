#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int front;
    int rear;
    int size;
    int *arr;
} Q;

void display(Q q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ",q.arr[i]);
        i = (i+1) % q.size;
    }
    while(i != (q.rear+1) % q.size);
}

int deque(Q *q)
{
    int x = -1;
    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front+1) % q->size;
        x = q->arr[q->front];
    }
    return x;
}

void enqueue(Q *q, int item)
{
    if((q->rear+1) % q->size == q->front)
        printf("Queue is Full");
    else
    {
        q->rear = (q->rear+1) % q->size;
        q->arr[q->rear] = item;
    }
}

Q* create_queue(int size)
{
    Q *q = (Q*)malloc(sizeof(Q));
    q->front = q->rear = 0;
    q->size = size;
    q->arr = (int*)malloc(sizeof(int) * size);
    return q;
}

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct queue
//{
//    int front;
//    int rear;
//    int size;
//    int *arr;
//} Q;
//
//void display(Q q)
//{
//    for(int i = q.front; i <= q.rear; i++)
//        printf("%d ", q.arr[i]);
//}
//
//int deque(Q *q)
//{
//    if(q->front == -1)
//        printf("Underflow\n");
//    else if (q->front == q->rear)
//        q->front = q->rear = -1;
//    else if(q->front == q->size - 1)
//        q->front = 0;
//    else
//        return q->arr[q->front++];
//    return -1;
//}
//
//void enqueue(Q *q, int item)
//{
//    if((q->rear + 1 == q->size) && (q->front == 0) || (q->rear + 1 == q->front))
//        printf("Overflow\n");
//    else if(q->rear == -1)
//    {
//        q->rear = q->front = 0;
//        q->arr[q->rear] = item;
//    }
//    else if(q->rear + 1 == q->size)
//    {
//        q->rear = 0;
//        q->arr[q->rear] = item;
//    }
//    else
//        q->arr[q->rear++] = item;
//}
//
//Q* create_queue(int size)
//{
//    Q *q = (Q*)malloc(sizeof(Q));
//    q->front = q->rear = -1;
//    q->size = size;
//    q->arr = (int*)malloc(sizeof(int) * size);
//    return q;
//}
