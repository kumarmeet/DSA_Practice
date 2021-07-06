#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    int size;
    int *arr;
} STACK;

int deque(STACK *s1, STACK *s2) //pop element only from stack two
{
    if(isEmpty(s2))
    {
        if(isEmpty(s1))
            return -1;
        else
            while(!isEmpty(s1))
                push(s2, pop(s1));
    }
    return pop(s2);
}

void enque(STACK *s1, STACK *s2, int item) //push data only from stack one
{
    if(!isEmpty(s2))
        printf("Stack two is not empty");
    else
        push(s1, item);
}

void view_stack(STACK *stack)
{
    printf("\n");
    for(int i = 0; i <= stack->top; i++)
        printf("%d ", stack->arr[i]);
}

int isFull(STACK *stack)
{
    if(stack->top == stack->size - 1)
        return 1;
    return 0;
}

int isEmpty(STACK *stack)
{
    if(stack->top == -1)
        return 1;
    return 0;
}

int peek(STACK *stack, int pos)
{
    if(pos < 0 || pos > stack->size) // invalid pos checking and it will work stack terminology like bottom to top (increasing order)
        return -1;
    return stack->arr[stack->top - pos + 1];
}

int stack_top(STACK *stack)
{
    if(stack->top == -1)
        return -1;
    return stack->arr[stack->top];
}

int pop(STACK *stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->arr[stack->top--];
}

void push(STACK *stack, int item)
{
    if(isFull(stack))
        printf("Overflow\n");
    else
        stack->arr[++stack->top] = item;
}

STACK* create_stack(int size)
{
    STACK *stack = (STACK*)malloc(sizeof(STACK));

    stack->top = -1;
    stack->size = size;
    stack->arr = (int*)malloc(sizeof(int) * size);
    return stack;
}
