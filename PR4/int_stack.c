#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
    int top;
    int *name;
    int size;
} INT_STACK;

INT_STACK *createStack(int n)
{
    INT_STACK *s = (INT_STACK *)malloc(sizeof(INT_STACK));
    s->top = -1;
    s->size = n;
    s->name = (int *)calloc(s->size, sizeof(int));
    return s;
}

int isEmpty(INT_STACK *s)
{
    return s->top == -1;
}

int isFull(INT_STACK *s)
{
    return s->top >= s->size - 1;
}

void push(INT_STACK *s, int el)
{
    if (isFull(s))
    {
        printf("\n stack is full");
        return;
    }
    s->top += 1;
    s->name[s->top] = el;
}

int pop(INT_STACK *s)
{
    int x;
    if (isEmpty(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    x = s->name[s->top];
    s->top -= 1;
    return x;
}

int peak(INT_STACK *s)
{
    if (isEmpty(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    return s->name[s->top];
}

void display(INT_STACK *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d", s->name[i]);
    }
}

void stackDestroy(INT_STACK *s)
{
    free(s->name);
    free(s);
}
