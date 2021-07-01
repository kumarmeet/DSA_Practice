#include <stdio.h>
#include <stdlib.h>

struct node* create_node(int);

struct node
{
    int info;
    struct node *next;
};

struct node* search_node(struct node *last, int item)
{
    struct node *r = last;
    if(!last)
        return NULL;
    r = last->next;
    do
    {
        if(r->info == item)
            return r;
        r = r->next;
    }
    while(r->next != last->next);

    return NULL;
}

void display(struct node *last)
{
    struct node *t;

    if(last == NULL)
        return;
    else
    {
        t = last->next;
        do
        {
            printf("%d ",t->info);
            t=t->next;
        }
        while(t != last->next);
    }
}

void delete_node(struct node **last, int item)
{
    struct node *r, *t, *p, *q;
    p = r = (*last)->next;
    q = *last;

    if(!(*last))
        return;
    if(r->info == item)//for first node
        delete_node_begining(last);
    else if((*last)->info == item) // for last node
        delete_node_last(last);
    else
    {
        while(search_node(r, item))
        {
            t = r;
            r = r->next;
        }

        t->next = r->next;
        (*last)->next = p;
        *last = q;
        free(r);
    }
}


void delete_node_begining(struct node **last)
{
    if(*last == NULL)
        return;
    if((*last)->next == *last)
    {
        free(*last);
        *last = NULL;
    }
    else
    {
        struct node *r = (*last)->next;
        (*last)->next = r->next;
        free(r);
    }

}

void insert_node_begining(struct node **last, int item)
{
    struct node *n = create_node(item);

    if(*last == NULL)
        *last = n;
    else
    {
        n->next = (*last)->next;
        (*last)->next = n;
    }
}

void delete_node_last(struct node **last)
{
    struct node *r;
    if(*last == NULL)
        return;
    if((*last)->next == *last)
    {
        free(*last);
        *last = NULL;
    }
    else
    {
        r = *last;
        while(r->next != *last)
            r = r->next;
        r->next = (*last)->next;
        free(*last);
        *last = r;
    }
}

void insert_node_last(struct node **last, int item)
{
    struct node *n = create_node(item);

    if(!(*last))
        *last = n;
    else
    {
        n->next = (*last)->next;
        (*last)->next = n;
    }

    *last = n;
}

struct node* create_node(int item)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = item;
    n->next = n;
    return n;
}
