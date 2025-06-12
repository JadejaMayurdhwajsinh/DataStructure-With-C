#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} SNODE;

typedef struct
{
    SNODE *head;
    SNODE *tail;
} DLIST;

DLIST *createlist()
{
    DLIST *dlst = (DLIST *)malloc(sizeof(DLIST));
    dlst->head = NULL;
    dlst->tail = NULL;
    return dlst;
}

SNODE *createnode(int x)
{
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    new->data = x;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insertfront(DLIST *dlst, int x)
{
    SNODE *new = createnode(x);
    if (dlst->head == NULL || dlst->tail == NULL)
    {
        dlst->head = new;
        dlst->tail = new;
        return;
    }
    new->next = dlst->head;
    dlst->head->prev = new;
    dlst->head = new;
    return;
}

void displayforward(DLIST *dlst)
{
    if (dlst->head == NULL || dlst->tail == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *temp = dlst->head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL -> TAIL");
    printf("\n");
}

void displaybackward(DLIST *dlst)
{
    if (dlst->head == NULL || dlst->tail == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *temp = dlst->tail;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL -> HEAD");
    printf("\n");
}

void insertend(DLIST *dlst, int x)
{
    SNODE *new = createnode(x);
    if (dlst->head == NULL || dlst->tail == NULL)
    {
        dlst->head = new;
        dlst->tail = new;
        return;
    }
    SNODE *temp = dlst->tail;
    temp->next = new;
    new->prev = temp;
    dlst->tail = new;
    return;
}

void deletefirst(DLIST *dlst)
{
    if (dlst->head == NULL || dlst->tail == NULL)
    {
        printf("\n list is empty");
        return;
    }
    else if (dlst->head->next == NULL)
    {
        free(dlst->head);
        dlst->head = NULL;
        dlst->tail = NULL;
        return;
    }
    else
    {
        SNODE *temp = dlst->head;
        dlst->head = temp->next;
        dlst->head->prev = NULL;
        free(temp);
        return;
    }
}

void deleteend(DLIST *dlst)
{
    if (dlst->head == NULL || dlst->tail == NULL)
    {
        printf("\n list is empty");
        return;
    }
    else if (dlst->head->next == NULL)
    {
        free(dlst->head);
        dlst->head = NULL;
        dlst->tail = NULL;
        return;
    }
    else
    {
        SNODE *temp = dlst->tail;
        dlst->tail = temp->prev;
        dlst->tail->next = NULL;
        free(temp);
        return;
    }
}

void insertAtpos(DLIST *dlst, int x, int pos)
{
    SNODE *new = createnode(x);
    if (pos < 1)
    {
        printf("\n invalid position");
        return;
    }
    else if (pos == 1)
    {
        insertfront(dlst, x);
        return;
    }
    else
    {
        SNODE *temp = dlst->head;
        SNODE *prevnode = NULL;
        for (int i = 1; i <= pos - 1; i++)
        {
            prevnode = temp;
            temp = temp->next;
        }
        new->next = temp;
        temp->prev = new;
        new->prev = prevnode;
        prevnode->next = new;
        return;
    }
}

void deleteAtpos(DLIST *dlst, int pos)
{
    if (dlst->head == NULL || dlst->tail == NULL)
    {
        printf("\n list is empty");
        return;
    }
    if (pos < 1)
    {
        printf("\n invalid");
        return;
    }
    SNODE *temp = dlst->head;
    SNODE *prevnode = NULL;
    for (int i = 1; i <= pos - 1; i++)
    {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = temp->next;
    temp->next->prev = prevnode;
    free(temp);
    return;
}

void deleteMiddle(DLIST *dlst)
{
    if (!dlst->head)
    {
        printf("\nList is empty\n");
        return;
    }
    SNODE *slow = dlst->head, *fast = dlst->head;
    if (dlst->head == dlst->tail)
    {
        free(dlst->head);
        dlst->head = dlst->tail = NULL;
        return;
    }
    while (fast != dlst->tail && fast->next != dlst->tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == dlst->tail && fast->next == dlst->head)
        slow = slow->next;
    slow->prev->next = slow->next;
    slow->next->prev = slow->prev;
    if (slow == dlst->head)
        dlst->head = slow->next;
    if (slow == dlst->tail)
        dlst->tail = slow->prev;
    free(slow);
}

void deleteEveryKthNode(DLIST *dlst, int k)
{
    if (!dlst->head || k < 1)
    {
        printf("\nInvalid operation\n");
        return;
    }
    SNODE *curr = dlst->head;
    int count;
    while (dlst->head && dlst->head != dlst->tail)
    {
        count = 1;
        while (count < k)
        {
            curr = curr->next;
            count++;
        }
        SNODE *toDelete = curr;
        curr = curr->next;
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        if (toDelete == dlst->head)
            dlst->head = toDelete->next;
        if (toDelete == dlst->tail)
            dlst->tail = toDelete->prev;
        free(toDelete);
    }
    if (dlst->head)
    {
        free(dlst->head);
        dlst->head = dlst->tail = NULL;
    }
}

int main()
{
    DLIST *dlst = createlist();

    insertfront(dlst, 20);
    insertfront(dlst, 10);
    displayforward(dlst);

    insertend(dlst, 30);
    insertend(dlst, 40);
    displayforward(dlst);
    displaybackward(dlst);

    // deletefirst(dlst);
    // displayforward(dlst);
    // displaybackward(dlst);

    // deleteend(dlst);
    // displayforward(dlst);
    // displaybackward(dlst);

    insertAtpos(dlst, 50, 2);
    displayforward(dlst);

    deleteAtpos(dlst, 2);
    displayforward(dlst);
    return 0;
}