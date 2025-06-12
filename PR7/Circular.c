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

LIST *createList()
{
    LIST *lst = (LIST *)malloc(sizeof(LIST));
    lst->head = NULL;
    return lst;
}

void insertfront(LIST *lst, int x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory full");
        return;
    }
    SNODE *temp = lst->head;
    if (lst->head == NULL)
    {
        lst->head = new;
        new->next = lst->head;
        return;
    }
    while (temp->next != lst->head)
    {
        temp = temp->next;
    }
    new->next = lst->head;
    lst->head = new;
    temp->next = new;
    return;
}

void insertend(LIST *lst, int x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory full");
        return;
    }
    if (lst->head == NULL)
    {
        lst->head = new;
        new->next = lst->head;
        return;
    }
    SNODE *temp = lst->head;
    while (temp->next != lst->head)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->next = lst->head;
    return;
}

void display(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *temp = lst->head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != lst->head);
    printf("%d ", lst->head->data);
    printf("\n");
}

void deletefront(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *temp = lst->head;
    if (lst->head->next == lst->head)
    {
        free(lst->head);
        lst->head = NULL;
        return;
    }
    SNODE *last = lst->head;
    while (last->next != lst->head)
    {
        last = last->next;
    }
    lst->head = lst->head->next;
    last->next = lst->head; // Maintain circular link
    free(temp);
}

void deleteend(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    if (lst->head->next == lst->head)
    {
        free(lst->head);
        lst->head = NULL;
        return;
    }
    SNODE *temp = lst->head;
    SNODE *prev = NULL;
    while (temp->next != lst->head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = lst->head;
    free(temp);
    return;
}

void deletemiddle(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *fast = lst->head;
    SNODE *slow = lst->head;
    SNODE *prev = NULL;
    while (fast->next != lst->head && fast->next->next != lst->head)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if (fast->next->next == lst->head)
    {
        prev = slow;
        slow = slow->next;
    }

    prev->next = slow->next;
    free(slow);
    return;
}

void insertafter(LIST *lst, int x, int pos)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory full");
        return;
    }
    if (pos < 0)
    {
        printf("\n invalid position");
        return;
    }
    if (lst->head == NULL)
    {
        lst->head = new;
        new->next = lst->head;
        return;
    }
    SNODE *temp = lst->head;
    SNODE *prev = NULL;
    for (int i = 1; i <= pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n out of range");
        return;
    }
    prev->next = new;
    new->next = temp;
}

void insertBeforevalue(LIST *lst, int target, int x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory full");
        return;
    }
    if (lst->head->data == target)
    {
        insertfront(lst, x);
        return;
    }
    SNODE *temp = lst->head;
    SNODE *prev = NULL;
    do
    {
        prev = temp;
        temp = temp->next;
    } while (temp->data != target);
    prev->next = new;
    new->next = temp;
}

void insertAftervalue(LIST *lst, int target, int x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory full");
        return;
    }
    SNODE *temp = lst->head;
    SNODE *prev = NULL;
    do
    {
        prev = temp;
        temp = temp->next;
    } while (prev->data != target);
    prev->next = new;
    new->next = temp;
}

void deletemiddle(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\nList is empty");
        return;
    }

    SNODE *fast = lst->head;
    SNODE *slow = lst->head;
    SNODE *prev = NULL;

    // Find middle node using tortoise-hare algorithm
    while (fast->next != lst->head &&
           fast->next->next != lst->head)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Handle even-length adjustment
    if (fast->next->next == lst->head)
    {
        prev = slow;
        slow = slow->next;
    }

    // Delete middle node
    if (prev == NULL)
    {
        // Single node case
        free(lst->head);
        lst->head = NULL;
    }
    else
    {
        prev->next = slow->next;
        if (slow == lst->head)
            lst->head = prev->next;
        free(slow);
    }
}

void deleteEveryKthNode(LIST *lst, int k)
{
    if (lst->head == NULL || k <= 0)
    {
        printf("\nInvalid position or empty list");
        return;
    }

    SNODE *current = lst->head;
    SNODE *prev = NULL;
    int count = 1;

    do
    {
        if (count == k)
        {
            SNODE *temp = current;

            // Handle single node case
            if (current->next == current)
            {
                free(current);
                lst->head = NULL;
                return;
            }

            // Adjust pointers
            if (prev)
                prev->next = current->next;
            if (current == lst->head)
                lst->head = current->next;

            current = current->next;
            free(temp);
            count = 1;
        }
        else
        {
            prev = current;
            current = current->next;
            count++;
        }
    } while (current != lst->head && lst->head != NULL);
}