#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lchild;
    int key;
    struct node *rchild;
} node;

node* binary_search_recursion(node*, int);
node* binary_search(node*, int);
node* create_node(int);
node* insert_recursion(node*, int);

node * binary_search_recursion(node *r, int key)
{
    if(r == NULL)
        return NULL;
    if(key == r->key)
        return r;
    else if(key < r->key)
        return binary_search_recursion(r->lchild, key);
    else if(key > r->key)
        return binary_search_recursion(r->rchild, key);
}

node* binary_search(node *r, int key)
{
    while(r)
    {
        if(key == r->key)
            return r;
        else if(key < r->key)
            r = r->lchild;
        else if(key > r->key)
            r = r->rchild;
    }
    return NULL;
}

int height(node *r)
{
    int x, y;
    if(!r)
        return 0;
    x = height(r->lchild);
    y = height(r->rchild);
    return x > y ? x + 1 : y + 1;
}

node* in_pre(node *r) // go for right most child on left sub tree
{
    while(r && r->rchild)
        r = r->rchild;

    return r;
}

node* in_succ(node *r) // go for left most child on right sub tree
{
    while(r && r->lchild)
        r = r->lchild;

    return r;
}

node* delete_node(node *r, int key)
{
    node *q, *p;
    p = r;
    if(!p)
        return;
    //lchild and rchild has null then simply delete that node
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(r == p) // if only root node
            r = NULL;
        free(r);
        return NULL;
    }
    if(key < p->key)
        p->lchild = delete_node(p->lchild, key);
    else if(key > p->key)
        p->rchild = delete_node(p->rchild, key);
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q = in_pre(p->lchild);
            p->key = q->key;
            p->lchild = delete_node(p->lchild, q->key);
        }
        else if(height(p->lchild) < height(p->rchild))
        {
            q = in_succ(p->rchild);
            p->key = q->key;
            p->rchild = delete_node(p->rchild, q->key);
        }
    }

    return p;
}

node* insert_recursion(node *r, int key)
{
    node *t = NULL;

    if(!r)
        return create_node(key);

    if(key < r->key)
        r->lchild = insert_recursion(r->lchild, key);
    else if(key > r->key)
        r->rchild = insert_recursion(r->rchild, key);
      return r;
}

void insert(node **r, int key)
{
    node *m = NULL, *d, *t = create_node(key);

    if(!(*r))
        (*r) = t;
    else
    {
        d = *r;

        while(d)
        {
            m = d;
            if(binary_search(r, key)) // duplicate item not allowed
                return;
            else if(key < d->key)
                d = d->lchild;
            else
                d = d->rchild;
        }

        if(t->key < m->key)
            m->lchild = t;
        else
            m->rchild = t;
    }
}

node* create_node(int key)
{
    node *n;
    n = (node *)malloc(sizeof(node));
    n->key = key;
    n->lchild = n->rchild = NULL;
    return n;
}

void preorder(node *p)
{
    if(p)
    {
        printf("%d ",p->key);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->key);
        inorder(p->rchild);
    }
}

void postorder(node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->key);
    }
}
