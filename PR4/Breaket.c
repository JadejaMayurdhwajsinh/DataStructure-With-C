#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct
{
    int size;
    int top;
    char *data;
} Stack;

int isEmpty(Stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}
int isFull(Stack *s)
{
    if ((s->top + 1) == s->size)
    {
        int newSize = s->size / 2;
        s->size += newSize;
        s->data = (char *)realloc(s->data, s->size * sizeof(char));
        return 1;
    }
    return 0;
}
void push(Stack *s, char data)
{
    if (isFull(s))
    {
        printf("\nSize Increased ");
    }
    s->data[s->top + 1] = data;
    s->top++;
}
int peak(Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Is Empty !");
        return -1;
    }
    return s->data[s->top];
}
char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Is Empty !");
        return ' ';
    }
    return s->data[s->top--];
}
Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->size = 5;
    s->data = (char *)malloc(s->size * sizeof(char));
    return s;
}
int main()
{
    Stack *s = createStack();
    char expresion[] = "{()()}";
    printf("%d", '(' == ')');
    for (int i = 0; i < strlen(expresion); i++)
    {
        char ch = expresion[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(s, ch);
        }
        else
        {
            if (!(ch == '}' && pop(s) == '{'))
            {
                printf("invalid !");
                return 0;
            }
            if (!(ch == ')' && pop(s) == '('))
            {
                printf("invalid !");
                return 0;
            }
            if (!(ch == ']' && pop(s) == '['))
            {
                printf("invalid !");
                return 0;
            }
        }
    }
    if (isEmpty(s))
        printf("\n\nValid !");
    else
        printf("\n\nInvalid");
    return 1;
}