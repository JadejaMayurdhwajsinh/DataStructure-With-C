#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    int price;
    char name[30];
    int weight;
} STUD;

typedef struct node
{
    STUD *s;
    struct node *next;
} SNODE;

typedef struct
{
    SNODE *head;
} DLIST;

DLIST *createlist()
{
    DLIST *dlst = (DLIST *)malloc(sizeof(DLIST));
    dlst->head = NULL;
    return dlst;
}

SNODE *createnode(char *name, int weight, int id, int price)
{
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    new->s = (STUD *)malloc(sizeof(STUD));
    strcpy(new->s->name, name);
    new->s->price = price;
    new->s->weight = weight;
    new->s->id = id;
    new->next = NULL;
    return new;
}

void insertfront(DLIST *dlst, char *name, int weight, int id, int price)
{
    SNODE *new = createnode(name, weight, id, price);
    if (dlst->head == NULL)
    {
        dlst->head = new;
        return;
    }
    new->next = dlst->head;
    dlst->head = new;
    return;
}

void displayforward(DLIST *dlst)
{
    if (dlst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *temp = dlst->head;
    while (temp != NULL)
    {
        printf("%d %s %d %d -> ", temp->s->id, temp->s->name, temp->s->price, temp->s->weight);
        temp = temp->next;
        printf("\n");
    }
    printf("NULL -> TAIL");
    printf("\n");
}

void insertend(DLIST *dlst, char *name, int weight, int id, int price)
{
    SNODE *new = createnode(name, weight, id, price);
    if (dlst->head == NULL)
    {
        dlst->head = new;
        return;
    }
    SNODE *temp = dlst->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    return;
}

void deletefirst(DLIST *dlst)
{
    if (dlst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    else if (dlst->head->next == NULL)
    {
        free(dlst->head);
        dlst->head = NULL;
        return;
    }
    else
    {
        SNODE *temp = dlst->head;
        dlst->head = temp->next;
        free(temp);
        return;
    }
}

void deleteend(DLIST *dlst)
{
    if (dlst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    else if (dlst->head->next == NULL)
    {
        free(dlst->head);
        dlst->head = NULL;
        return;
    }
    else
    {
        SNODE *temp = dlst->head;
        SNODE *prev = NULL;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        return;
    }
}

void sortByPrice(DLIST *dlst)
{
    if (dlst->head == NULL || dlst->head->next == NULL)
        return;

    SNODE *i, *j;
    STUD *temp;

    for (i = dlst->head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->s->price > j->s->price)
            {
                // Swap STUD pointers
                temp = i->s;
                i->s = j->s;
                j->s = temp;
            }
        }
    }
}

// void insertAtpos(DLIST *dlst, int x, int pos)
// {
//     SNODE *new = createnode(x);
//     if (pos < 1)
//     {
//         printf("\n invalid position");
//         return;
//     }
//     else if (pos == 1)
//     {
//         insertfront(dlst, x);
//         return;
//     }
//     else
//     {
//         SNODE *temp = dlst->head;
//         SNODE *prevnode = NULL;
//         for (int i = 1; i <= pos - 1; i++)
//         {
//             prevnode = temp;
//             temp = temp->next;
//         }
//         new->next = temp;
//         temp->prev = new;
//         new->prev = prevnode;
//         prevnode->next = new;
//         return;
//     }
// }

// void deleteAtpos(DLIST *dlst, int pos)
// {
//     if (dlst->head == NULL || dlst->tail == NULL)
//     {
//         printf("\n list is empty");
//         return;
//     }
//     if (pos < 1)
//     {
//         printf("\n invalid");
//         return;
//     }
//     SNODE *temp = dlst->head;
//     SNODE *prevnode = NULL;
//     for (int i = 1; i <= pos - 1; i++)
//     {
//         prevnode = temp;
//         temp = temp->next;
//     }
//     prevnode->next = temp->next;
//     temp->next->prev = prevnode;
//     free(temp);
//     return;
// }

int main()
{
    DLIST *dlst = createlist();

    insertfront(dlst, "pant", 2, 2, 1000);
    insertfront(dlst, "shirt", 2, 1, 500);
    displayforward(dlst);

    insertend(dlst, "book", 1, 3, 2000);
    insertend(dlst, "table", 23, 4, 20000);

    displayforward(dlst);
    // displaybackward(dlst);

    // deletefirst(dlst);
    displayforward(dlst);
    // displaybackward(dlst);
    sortByPrice(dlst);
    // deleteend(dlst);
    // displayforward(dlst);
    // displaybackward(dlst);

    // insertAtpos(dlst, 50, 2);
    // displayforward(dlst);

    // deleteAtpos(dlst, 2);
    // displayforward(dlst);
    return 0;
}