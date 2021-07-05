#include <stdio.h>
#include <stdlib.h>

struct node* create_node(int);

struct node
{
    int info;
    struct node *next;
}*front = NULL, *rear = NULL;

void display(struct node *s)
{
    while(s)
    {
        printf("%d ", s->info);
        s = s->next;
    }
}

int deque(struct node **s)
{
    int x = -1;
    if(!(*s))
        printf("Queue is empty");
    else
    {
        front = *s;
        (*s) = front->next;
        x = front->info;
        free(front);
    }
    return x;
}

void enqueue(struct node **s, int item)
{
    if(!(*s))
        (*s) = front = create_node(item);
    else
    {
        rear = *s;
        while(rear->next != NULL)
            rear = rear->next;
        rear->next = create_node(item);
    }
}

struct node* create_node(int item)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = item;
    n->next = NULL;
    return n;
}
