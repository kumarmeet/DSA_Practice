#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} Node;

Node* create_node(int);

int hash(int key) // it will give last digit of any number
{
    return key % 10;
}

void insert(Node *H[], int key)
{
    int index = hash(key);
    sort_insert_node(&H[index], key);
}

Node* search(Node *s, int key)
{
    while(s)
    {
        if(key == s->info)
            return s;
        s = s->next;
    }
    return NULL;
}

void delete_hash_node(struct node **s, int item)
{
    struct node *t, *r;
    r = t = *s;

    if(!(*s))
        printf("List is empty");
    else if((*s)->info == item)
        *s = r->next;
    else
    {
        while(r != search(*s, item))
        {
            t = r;
            r = r->next;
        }
        t->next = r->next;
    }
}

void sort_insert_node(Node **s, int item)
{
    Node *t = create_node(item), *p = *s, *q = NULL;
    if(!(*s))
        (*s) = t;
    else
    {
        while(p && p->info < item)
        {
            q = p;
            p = p->next;
        }
        if(p == *s)
        {
            t->next = *s;
            *s = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

Node* create_node(int item)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = item;
    n->next = NULL;
    return n;
}
