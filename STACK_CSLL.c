#include <stdio.h>
#include <stdlib.h>

struct node* create_node(int);

struct node
{
    int info;
    struct node *next;
};

void display(struct node *stack)
{
    struct node *t;

    if(!stack)
        return;
    else
    {
        t = stack->next;
        do
        {
            printf("%d ",t->info);
            t=t->next;
        }
        while(t != stack->next);
    }
}

int count(struct node *stack)
{
    struct node *t;
    int count = 0;

    if(!stack)
        return - 1;
    else
    {
        t = stack->next;
        do
        {
            ++count;
            t=t->next;
        }
        while(t != stack->next);
    }
    return count;
}

int isFull(struct node *stack)
{
    return stack ? 0 : 1; // if stack is NULL then its full return 0
}

int isEmpty(struct node *stack)
{
    return (!stack) ? 1 : 0; // if stack is NULL then its empty return 1
}

int peek(struct node *stack, int pos)
{
    if(pos < 0 || pos > count(stack))
        return - 1;
    while(pos)
    {
        stack = stack->next;
        pos--;
    }
    return stack->info;
}

int stack_top(struct node *stack)
{
    if(!stack)
        return -1;
    else
        return stack->next->info;
}

void pop(struct node **stack)
{
    if(!(*stack))
        printf("Underflow\n");
    else if((*stack)->next == *stack)
    {
        free(*stack);
        *stack = NULL;
    }
    else
    {
        struct node *r = (*stack)->next;
        (*stack)->next = r->next;
        free(r);
    }
}

void push(struct node **stack, int item)
{
    struct node *n = create_node(item);

    if(*stack == NULL)
        *stack = n;
    else
    {
        n->next = (*stack)->next;
        (*stack)->next = n;
    }
}

struct node* create_node(int item)
{
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = item;
    n->next = n;
    return n;
}
