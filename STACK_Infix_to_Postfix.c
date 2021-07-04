#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char info;
    struct node *next;
};

char* infix_to_postfix(char *, char *);
int isOperand(char);
int precedence(char);

int main()
{
    char exe[] = "a+b*c-d/e";
    size_t size = strlen(exe) + 1;
    char postfix[size];

    infix_to_postfix(exe, postfix);

    puts(postfix);

    return 0;
}

char* infix_to_postfix(char *infix_str, char *postfix)
{
    struct node *stack = NULL; // must initialize with NULL
    int i = 0, j = 0;

    while(infix_str[i])
        if(isOperand(infix_str[i]))
            postfix[j++] = infix_str[i++];
        else if(precedence(infix_str[i]) > precedence(stack_top(stack)))
            push(&stack, infix_str[i++]);
        else
            postfix[j++] = pop(&stack);

    while(!isEmpty(stack))
        postfix[j++] = pop(&stack);
    postfix[j] = '\0';

    return postfix;
}

int isOperand(char ch)
{
    if(ch == '-' || ch == '+' || ch == '*' || ch == '/')
        return 0;
    return 1;
}

int precedence(char ch)
{
    if(ch == '-' || ch == '+')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    return 0;
}
