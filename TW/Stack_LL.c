#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *newList = (Stack *)malloc(sizeof(Stack));
    newList->top = NULL;
    return newList;
}

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmptyStack(Stack *list)
{
    return list->top == NULL;
}
void push(Stack *list, char data)
{
    if (list == NULL)
    {
        printf("\nList Is Not Created !!");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = list->top;
    list->top = newNode;
}

char pop(Stack *list)
{
    if (isEmptyStack(list))
        return '\0';
    char ele = list->top->data;
    list->top = list->top->next;
    return ele;
}
char peak(Stack *list)
{
    if (isEmptyStack(list))
        return '\0';
    return list->top->data;
}
void display(Stack *list)
{

    if (list == NULL)
    {
        printf("\nStack Is Not Created !!");
        return;
    }
    if (list->top == NULL)
    {
        printf("\nStack Underflow !!");
        return;
    }
    Node *temp = list->top;
    printf("\n TOP \n");
    while (temp != NULL)
    {
        printf("\n|%c|\n____", temp->data);
        temp = temp->next;
    }
}
