#include <stdio.h>
#include <stdlib.h>

struct node* create_node(int);
struct node* search_node(struct node *, int);

struct node
{
    int info;
    struct node *next;
};

void remove_duplicate_node(struct node **s)
{
    struct node *i, *j;
    i = j = *s;
    if(!(*s))
        printf("List is empty");
    else
    {
      while(i)
      {
        while(j != search_node(*s, (*s)->info))
        {
          j = j->next;
        }
        delete_node(&s, j->info);
        i = i->next;
        j = *s;
      }
    }
}

int largest_node(struct node *s)
{
    return sort_node(s);
}

int smallest_node(struct node *s)
{
    sort_node(s);
    return s->info;
}

int sort_node(struct node *s)
{
    int temp;
    struct node *i, *j;
    if(!s)
        printf("List is empty");
    else
    {
        while(s)
        {
            i = s->next;
            while(i)
            {
                if(s->info > i->info)
                {
                    temp = s->info;
                    s->info = i->info;
                    i->info = temp;
                }
                i = i->next;
            }
            j = s; //j will contain last node address
            s = s->next;
        }
    }
    return j->info;
}

int sum_node(struct node *s)
{
    if(s)
        return sum_node(s->next) + s->info;
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
        r->info = update_item;
    }
}

void add_node_after(struct node *s, int item, int insert_item)
{
    struct node *t, *r, *n, *m;
    n = create_node(insert_item);
    r = s;

    if(!s)
        printf("List is empty");
    else if(s->info == item)
    {
        m = s->next;
        s->next = n;
        n->next = m;
    }
    else
    {
        while(r != search_node(s, item))
        {
            r = r->next;
            t = r;
        }
        m = t->next;
        t->next = n;
        n->next = m;
    }
}

void add_node_last(struct node *s, int item)
{
    struct node *r;
    r = create_node(item);
    while(s->next)
        s = s->next;
    s->next = r;
}

void add_node_begining(struct node **s, int item)
{
    struct node *r;
    r = create_node(item);
    r->next = *s;
    *s = r;
}

struct node* search_node(struct node *s, int item)
{
    while(s)
    {
        if(s->info == item)
            return s;
        s = s->next;
    }
    return NULL;
}

void delete_node(struct node **s, int item)
{
    struct node *t, *r;
    r = t = *s;

    if(!(*s))
        printf("List is empty");
    else if((*s)->info == item)
        *s = r->next;
    else
    {
        while(r != search_node(*s, item))
        {
            t = r;
            r = r->next;
        }
        t->next = r->next;
    }
}

void delete_last_node(struct node **s)
{
    struct node *t, *r = NULL;
    t = *s;

    if(!(*s))
        printf("List is empty");
    else
    {
        while(t->next != NULL)
        {
            r = t;
            t = t->next;
        }
        if(r)
            r->next = NULL;
        else
            *s = NULL;
    }
    free(t);
}

void delete_first_node(struct node **s)
{
    struct node *t;
    if(!(*s))
        printf("List is empty");
    else
    {
        t = *s;
        (*s) = t->next;
        free(t);
    }
}

void display(struct node *s)
{
    while(s)
    {
        printf("%d ", s->info);
        s = s->next;
    }
}

int count_node(struct node *s)
{
    if(s)
        return count_node(s->next) + 1;
}

void insert_node(struct node **s, int item)
{
    struct node *t;
    if(!(*s))
        (*s) = create_node(item);
    else
    {
        t = *s;
        while(t->next != NULL)
            t = t->next;
        t->next = create_node(item);
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
