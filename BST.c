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
