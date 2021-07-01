#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *pre;
    int info;
    struct node *next;
};

struct node* create_node(int);

void display(struct node *s)
{
    while(s)
    {
        printf("%d ", s->info);
        s = s->next;
    }
}

void reverse_node(struct node **s)
{
    struct node *t, *p;
    p = *s;

    while(p)
    {
        t = p->next;
        p->next = p->pre;
        p->pre = t;
        p = p->pre;

        if(p != NULL && p->next == NULL)
            *s = p;
    }
}

struct node* search_node(struct node *s, int item)
{
    if(!s)
        return NULL;
    else
    {
        while(s)
        {
            if(s->info == item)
                return s;
            s=s->next;
        }
        return NULL;
    }
}

void delete_node(struct node **s, int item)
{
    struct node *r;
    r = (*s);

    if(!(*s))
        return;
    else if((*s)->info == item)
        delete_node_begining(s);
    else
    {
        while(r != search_node(*s,item))
            r = r->next;

        if(r->next != NULL)
        {
            r->pre->next = r->next;
            r->next->pre = r->pre;
        }
        else
            delete_node_last(s);
    }
}

void add_node_after(struct node *s, int item, int insert_item)
{
    struct node *r, *n;
    n = create_node(insert_item);
    r = s;

    if(!s)
        return;
    else
    {
        while(r != search_node(s,item))
            r = r->next;

        if(!search_node(s, item))
            printf("List doesn't contain %d in the list", item);
        else if(r->next != NULL)
        {
            r->next->pre = n;
            n->pre = r;
            n->next = r->next;
            r->next = n;
        }
    }
}

void update_node(struct node *s, int item, int update_item)
{
    struct node *r = s;

    if(!s)
        printf("List is empty");
    else if(s->info == item)
        s->info = update_item;
    else
    {
        while(r != search_node(s, item))
            r = r->next;
        if(!search_node(s, item))//if item is not found
            return;
        r->info = update_item;
    }
}

void delete_node_last(struct node **s)
{
    struct node *t = (*s);

    if(!(*s)->next)
        (*s) = NULL;
    else
    {
        while(t->next)
            t = t->next;

        t->pre->next = NULL;
        free(t);
    }
}

void insert_node_last(struct node *s, int item)
{
    struct node *n;
    n = create_node(item);

    if(!s)
        s = n;
    else
    {
        while(s->next)
            s = s->next;

        s->next= n;
        n->pre = s;
    }
}

void delete_node_begining(struct node **s)
{
    struct node *t;

    if(!(*s))
        *s = NULL;

    t = *s;
    *s = t->next;
    (*s)->pre = NULL;
    free(t);
}

void insert_node_begining(struct node **s, int item)
{
    struct node *n;
    n = create_node(item);

    if(!(*s))
        (*s) = n;
    else
    {
        (*s)->pre = n;
        n->next = (*s);
        *s = n;
    }
}

void add_node(struct node **s, int item)
{
    struct node *t, *n;
    n = create_node(item);

    if(!(*s))
        (*s) = n;
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;
        n->pre = t;
        t->next = n;
    }
}

struct node* create_node(int item)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->pre = n->next = NULL;
    n->info = item;
    return n;
}
