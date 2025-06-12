#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} SNODE;

typedef struct
{
    SNODE *head;

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

SNODE *insertend(SNODE *head, int x)
{
    SNODE *new = createnode(x);

    if (new == NULL)
    {
        printf("\n memory full");
        return new;
    }
    if (head == NULL)
    {
        head = new;
        return head;
    }
    SNODE *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    return head;
}

void display(SNODE *head)
{
    SNODE *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

SNODE *insertfront(SNODE *head, int x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory full");
        return head;
    }
    new->next = head;
    head = new;
    return head;
}

SNODE *deletefront(SNODE *head)
{
    if (head == NULL)
    {
        printf("\n list is empty");
        return head;
    }
    SNODE *temp = head;
    head = head->next;
    free(temp);
    return head;
}

SNODE *deleteend(SNODE *head)
{
    if (head == NULL)
    {
        printf("\n list is empty");
        return head;
    }
    if (head->next == NULL)
    {
        head = NULL;
    }
    SNODE *temp = head;
    SNODE *prev = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return head;
}

SNODE *insertAfterpos(SNODE *head, int pos, int x)
{
    if (pos < 1)
    {
        printf("\n invalid position");
        return head;
    }
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory is full");
        return head;
    }
    // if (pos == 1)
    // {
    //     new->next = head;
    //     head = new;
    //     return head;
    // }
    SNODE *temp = head;
    for (int i = 1; temp != NULL && i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n out of range");
        free(new);
        return head;
    }
    new->next = temp->next;
    temp->next = new;
    return head;
}

SNODE *insertAtpos(SNODE *head, int pos, int x)
{
    if (pos < 1)
    {
        printf("\n invalid position");
        return head;
    }
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory is full");
        return head;
    }
    if (pos == 1)
    {
        new->next = head;
        head = new;
        return head;
    }
    SNODE *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n out of range");
        free(new);
        return head;
    }
    new->next = temp->next;
    temp->next = new;
    return head;
}

SNODE *insertAtBeforepos(SNODE *head, int pos, int x)
{
    if (pos < 1)
    {
        printf("\n invalid position");
        return head;
    }
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory is full");
        return head;
    }
    if (pos == 1)
    {
        new->next = head;
        head = new;
        return head;
    }
    SNODE *temp = head;
    for (int i = 1; temp != NULL && i > pos + 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n out of range");
        free(new);
        return head;
    }
    new->next = temp->next;
    temp->next = new;
    return head;
}

SNODE *delteAtpos(SNODE *head, int pos)
{
    if (head == NULL)
    {
        printf("\n list is empty");
        return head;
    }
    if (pos < 1)
    {
        printf("\n invalid pos");
        return head;
    }
    if (pos == 1)
    {
        SNODE *temp = head;
        head = temp->next;
        free(temp);
        return head;
    }
    SNODE *temp = head;
    SNODE *prev = NULL;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

SNODE *delteAfterpos(SNODE *head, int pos)
{
    if (head == NULL)
    {
        printf("\n list is empty");
        return head;
    }
    if (pos < 1)
    {
        printf("\n invalid pos");
        return head;
    }
    // if (pos == 1)
    // {
    //     SNODE *temp = head;
    //     head = temp->next;
    //     free(temp);
    //     return head;
    // }
    SNODE *temp = head;
    SNODE *prev = NULL;
    for (int i = 1; i <= pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

SNODE *valueinsert(SNODE *head, int x, int target)
{
    SNODE *temp = head;
    while (temp->data != target)
    {
        temp = temp->next;
    }
    temp->data = x;
    return head;
}

SNODE *reverselist(SNODE *head)
{
    SNODE *prev = NULL;
    SNODE *current, *nextnode;
    current = nextnode = head;
    while (current != NULL)
    {
        nextnode = nextnode->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    return prev;
}

SNODE *findmiddle(SNODE *head)
{
    SNODE *fast, *slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("middle element %d ", slow->data);
    return slow;
}