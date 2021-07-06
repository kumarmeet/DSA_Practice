#include <stdio.h>
#include <stdlib.h>

struct node* create_node(char, int);
struct que* create_node_q(char);

struct node
{
    char info;
    int priority;
    struct node *next;
};

struct que
{
    char info;
    struct que *next;
}*f = NULL, *r = NULL;

void display(struct node *s)
{
    while(s)
    {
        printf("%c ", s->info);
        s = s->next;
    }
}

char deque(struct que **q) // only for que struct which is delete data from queue
{
    char x = -1;
    if(!(*q))
        printf("Queue is empty");
    else
    {
        f = *q;
        (*q) = f->next;
        x = f->info;
        free(f);
    }
    return x;
}

char deque_priority(struct que **q1, struct que **q2, struct que **q3) 
{
  if(*q1)
    return deque(q1);
  else if(*q2)
    return deque(q2);
  else if(*q3)
    return deque(q3);
  else
    return 'n';
}

void enqueue(struct node **s, char item, int prior) 
{
    struct node *t;
    if(!(*s))
        (*s) = create_node(item, prior);
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;
        t->next = create_node(item, prior);
    }
}

void enqueue_priority(struct node *q, struct que **q1, struct que **q2, struct que **q3) // check priority and insert data 
{
    while(q)
    {
        if(q->priority >= 1 && q->priority <= 3)
        {
            if (!(*q1) && q->priority == 1)
                insert_node(q, q1, q->info);
            else if(q->priority == 1)
                insert_node(q, q1, q->info);

            if(!(*q2) && q->priority == 2)
                insert_node(q, q2, q->info);
            else if(q->priority == 2)
                insert_node(q, q2, q->info);

            if(!(*q3) &&  q->priority == 3)
                insert_node(q, q3, q->info);
            else if(q->priority == 3)
                insert_node(q, q3, q->info);
        }
        q = q->next;
    }
}

void insert_node(struct node q, struct que **k, int item) //this is for only data inserting using from priority queue to queue  
{
    struct que *t;
    if(!(*k))
        (*k) = create_node_q(item);
    else
    {
        r = *k;
        while(r->next != NULL)
            r = r->next;
        r->next = create_node_q(item);
    }
}

struct node* create_node(char item, int prior) // this is for priority queue
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = item;
    n->priority = prior;
    n->next = NULL;
    return n;
}

struct que* create_node_q(char item) //this is for normal queue
{
    struct que *n;
    n = (struct que*)malloc(sizeof(struct que));
    n->info = item;
    n->next = NULL;
    return n;
}
