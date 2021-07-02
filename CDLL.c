#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
} Node;

Node* create_node(int);
Node* search_node(Node *, int);

void display(Node *s)
{
    Node *t;
    t = s;
    if(!s)
        return;
    do
    {
        printf("%d ", t->info);
        t = t->next;
    }
    while(t->next != s->next);
}

int count(Node *s)
{
    Node *t;
    t = s;
    int i = 0;
    if(!s)
        return;
    do
    {
        ++i;
        t = t->next;
    }
    while(t->next != s->next);
    return i;
}

void reverse_node(struct node **s)
{
    struct node *prev, *cur, *next, *last;

    if(!(*s))
        return NULL;

    // Head is going to be our last node after reversing list
    last = (*s);

    prev  = (*s);
    cur   = (*s)->next;
    *s = (*s)->next;

    // Iterate till you reach the initial node in circular list
    while (*s != last)
    {
        *s = (*s)->next;
        cur->next = prev;

        prev = cur;
        cur  = *s;
    }

    cur->next = prev;
    *s = prev;       // Make last node as head
}

Node* search_node(Node *s, int item)
{
    Node *t;
    t = s;
    if(!s)
        return NULL;
    else
    {
        do
        {
            if(item == t->info)
                return t;
            t = t->next;
        }
        while(t->next != s->next);
    }
    return NULL;
}

void insert_node_after(Node **s, int item, int insert_item)
{
    Node *t, *n = create_node(insert_item);

    t = (*s);

    if(!(*s))
        return NULL;
    else if((*s)->prev->info == item)
        insert_node_end(s,insert_item);
    else
    {
        if(search_node(t, item))
        {
            t = search_node(t, item);

            t->next->prev = n;
            n->next = t->next;
            n->prev = t;
            t->next = n;
        }
    }
}

void delete_node(Node **s, int item)
{
    Node *t = (*s);

    if(!(*s))
        return NULL;
    else if((*s)->info == item)
        delete_node_begining(s);
    else if((*s)->prev->info == item)
        delete_node_end(s);
    else
    {
        if(search_node(t, item))
        {
            t = search_node(t, item);
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
    }
}

void update_node(Node *s, int item, int update_item)
{
    if(!s)
        return NULL;
    else
    {
        if(search_node(s, item))
            search_node(s, item)->info = update_item;
    }
}

void delete_node_end(Node **s)
{
    if(!(*s))
        return;
    else if((*s) == (*s)->next)
        *s = NULL;
    else
    {
        (*s)->prev->prev->next = *s;
        (*s)->prev = (*s)->prev->prev;
    }
}

void insert_node_end(Node **s, int item)
{
    Node *n = create_node(item);

    if(!(*s))
        return;
    else
    {
        n->prev = (*s)->prev;
        (*s)->prev->next = n;
        n->next = (*s);
        (*s)->prev = n;
    }
}

void delete_node_begining(Node **s)
{
    Node *t;
    t = *s;

    if(!(*s))
        return;
    else
    {
        *s = t->next;
        (*s)->prev = t->prev;
        (*s)->prev->next = *s;
        free(t);
    }
}

void insert_node_begining(Node **s, int item)
{
    Node *t, *n = create_node(item);
    t = *s;

    if(!(*s))
        return;
    else
    {
        n->prev = t->prev;
        n->next = t;
        t->prev->next = n;
        *s = n;
    }
}

void add_node(Node **s, int item)
{
    Node *t, *n = create_node(item);
    n = create_node(item);

    if(!(*s))
        (*s) = n;
    else
    {
        t = *s;
        while(t->next != *s)
            t = t->next;
        t->next = n;
        n->prev = t;
        (*s)->prev = n;
        n->next = *s;
    }
}

Node* create_node(int item)
{
    Node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->prev = n->next = n;
    n->info = item;
    return n;
}
