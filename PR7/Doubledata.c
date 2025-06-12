#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char roll[7];
    char name[30];
    char gen[6];
} STUD;

typedef struct node
{
    STUD *s;
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

SNODE *createnode(char *roll, char *name, int id, char *gen)
{
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    new->s = (STUD *)malloc(sizeof(STUD));
    strcpy(new->s->roll, roll);
    strcpy(new->s->name, name);
    strcpy(new->s->gen, gen);
    new->s->id = id;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insertfront(DLIST *dlst, char *roll, char *name, int id, char *gen)
{
    SNODE *new = createnode(roll, name, id, gen);
    // printf("Roll No : %s", new->s->roll);
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
        // printf("%s", temp->s->roll);
        printf("%d %s %s %s -> ", temp->s->id, temp->s->roll, temp->s->name, temp->s->gen);
        temp = temp->next;
        printf("\n");
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
        printf("\n\n %s %s %d %s -> \n\n", temp->s->roll, temp->s->name, temp->s->id, temp->s->gen);
        printf("\n");
        temp = temp->prev;
    }
    printf("NULL -> HEAD");
    printf("\n");
}

void insertend(DLIST *dlst, char *roll, char *name, int id, char *gen)
{
    SNODE *new = createnode(roll, name, id, gen);
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

    insertfront(dlst, "MCA040", "krutik", 2, "male");
    insertfront(dlst, "MCA041", "keval", 1, "male");
    displayforward(dlst);

    insertend(dlst, "MCA037", "mayur", 3, "male");
    insertend(dlst, "MCA046", "kartik", 4, "male");
    displayforward(dlst);
    // displaybackward(dlst);

    deletefirst(dlst);
    displayforward(dlst);
    // displaybackward(dlst);

    deleteend(dlst);
    displayforward(dlst);
    // displaybackward(dlst);

    // insertAtpos(dlst, 50, 2);
    // displayforward(dlst);

    // deleteAtpos(dlst, 2);
    // displayforward(dlst);
    return 0;
}