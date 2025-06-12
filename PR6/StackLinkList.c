#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char data;
    struct node *next;
} SNODE;

typedef struct
{
    SNODE *top;
} LIST;

SNODE *createnode(int x)
{
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    if (new == NULL)
    {
        return new;
    }
    new->data = x;
    new->next = NULL;
    return new;
}

LIST *createList()
{
    LIST *lst = (LIST *)malloc(sizeof(LIST));
    lst->top = NULL;
    return lst;
}

void push(LIST *lst, int x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory is full");
        return;
    }
    new->next = lst->top;
    lst->top = new;
}

void display(LIST *lst)
{
    SNODE *temp = lst->top;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

char pop(LIST *lst)
{
    if (lst->top == NULL)
    {
        printf("\n list is empty");
        return 0;
    }
    SNODE *temp = lst->top;
    lst->top = lst->top->next;
    char x = temp->data;
    free(temp);
    return x;
}

char peak(LIST *lst)
{
    if (lst->top == NULL)
    {
        printf("\n list is empty");
        return 0;
    }
    return lst->top->data;
}

int main()
{
    LIST *lst1 = createList();
    push(lst1, 10);
    push(lst1, 20);
    push(lst1, 30);
    push(lst1, 40);
    push(lst1, 50);
    pop(lst1);
    pop(lst1);
    pop(lst1);
    display(lst1);
    return 0;
}