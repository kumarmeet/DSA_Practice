#include <stdio.h>
#include <stdlib.h>

struct root
{
    struct root *lchild;
    int data;
    struct root *rchild;
};

struct node
{
    struct root *info;
    struct node *next;
}*front = NULL, *rear = NULL;

struct node* create_node(struct root*);

struct node* create_node(struct root *address)
{
    struct node *n;

    n = (struct node*)malloc(sizeof(struct node));
    n->info = (struct root*)malloc(sizeof(struct root));
    n->info = address;
    n->next = NULL;
    return n;
}

struct node* deque(struct node **s)
{
    struct node *x = NULL;

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

void tree(struct node **q, struct root **r, int item)
{
    struct root *p, *t;

    if(!(*r))
    {
        *r = (struct root*)malloc(sizeof(struct root));
        (*r)->data = item;
        (*r)->lchild = (*r)->rchild = NULL;
        enqueue(q, *r);
    }
    else
    {
            p = deque(q);
            t = (struct root*)malloc(sizeof(struct root));
            t->data = item;
            t->lchild = t->rchild = NULL;

            if(item < p->data)
            p->lchild = t;
            else if(item > p->data)
            p->rchild = t;

            enqueue(q, t);
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

void preorder(struct root *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(struct root *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void postorder(struct root *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int isEmpty(struct node *q)
{
    return !q ? 1 : 0;
}

void enqueue(struct node **s, struct root *address)
{
    if(!(*s))
        (*s) = front = create_node(address);
    else
    {
        rear = *s;
        while(rear->next != NULL)
            rear = rear->next;
        rear->next = create_node(address);
    }
}
