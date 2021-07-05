#include <stdio.h>
#include <stdlib.h>

struct node* create_node(int, int);

struct node
{
    int info;
    int priority;
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

void enqueue(struct node **s, int item, int prior) // priority queue based on increasing order smaller higher and greater lesser
{
    struct node *t = create_node(item, prior);

    if ((*s)->priority > prior)
    {
        t->next = *s;
        (*s) = t;
    }
    else
    {
        rear = (*s);
        while(rear->next != NULL && rear->next->priority < prior)
            rear = rear->next;

        t->next = rear->next;
        rear->next = t;
    }
}

struct node* create_node(int item, int prior)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = item;
    n->priority = prior;
    n->next = NULL;
    return n;
}
