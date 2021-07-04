#include <stdio.h>
#include <stdlib.h>

struct node
{
    char info;
    struct node *next;
};

int main()
{
    char exp[] = "{[a + b] * [c * d]}";
    printf("%d", parenthesis_matching(exp));
    return 0;
}

int parenthesis_matching(char *str)
{
    struct node *stack = NULL;
    int i = 0;
    char ch;
    while(str[i])
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(&stack, str[i]);
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if(isEmpty(stack)) //check if stack is empty and and expression will containing the closing bracket
                return 0;

            ch = pop(&stack);

            if(ch == '(' && str[i] != ')')
                return 0;
            else if(ch == '[' && str[i] != ']')
                return 0;
            else if(ch == '{' && str[i] != '}')
                return 0;
        }
        i++;
    }

    return isEmpty(stack)? 1 : 0;
}
