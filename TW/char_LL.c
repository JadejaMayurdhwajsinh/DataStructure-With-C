#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} SNODE;

typedef struct
{
    SNODE *head;
} LIST;

SNODE *createnode(char x)
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

void insertfront(LIST *lst, char x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memory is full");
        return;
    }
    new->next = lst->head;
    lst->head = new;
}

void display(LIST *lst)
{
    SNODE *temp = lst->head;
    while (temp != NULL)
    {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    printf("\n");
}

void insertend(LIST *lst, char x)
{
    SNODE *new = createnode(x);
    if (new == NULL)
    {
        printf("\n memoey is full");
        return;
    }
    if (lst->head == NULL)
    {
        lst->head = new;
        return;
    }
    SNODE *temp = lst->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
}

char deletefront(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return 0;
    }
    SNODE *temp = lst->head;
    lst->head = lst->head->next;
    char x = temp->data;
    free(temp);
    return x;
}

char deleteend(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return 0;
    }
    if (lst->head->next == NULL)
    {
        lst->head = NULL;
    }
    SNODE *temp = lst->head;
    SNODE *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    char x = temp->data;
    free(temp);
    return x;
}

void reverselist(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *prev = NULL;
    SNODE *current, *nextnode;
    current = nextnode = lst->head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    lst->head = prev;
}

char findmiddle(LIST *lst)
{
    if (lst->head == NULL)
    {
        printf("\n list is empty");
        return 0;
    }
    SNODE *fast, *slow;
    fast = slow = lst->head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    char x = slow->data;
    return x;
}

void insertAtposition(LIST *lst, int pos, char x)
{
    SNODE *new = createnode(x);
    if (pos < 1)
    {
        printf("\n not valid position");
        return;
    }
    if (pos == 1)
    {
        insertfront(lst, x);
    }
    SNODE *temp = lst->head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n out of range");
        free(new);
        return;
    }
    new->next = temp->next;
    temp->next = new;
}

void swapNode(LIST *lst, int front, int end)
{
    SNODE *temp = lst->head;
    while (end != 0)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid Index !");
            return;
        }
        end--;
    }
    SNODE *curr = lst->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        curr = curr->next;
    }
    temp = lst->head;
    while (front != 0)
    {
        temp = temp->next;
        front--;
        if (temp == NULL)
        {
            printf("Invalid Index !");
            return;
        }
    }
    char val = curr->data;
    curr->data = temp->data;
    temp->data = val;
}

void concateList(LIST *lst1, LIST *lst2)
{
    SNODE *temp = lst2->head;
    while (temp != NULL)
    {
        insertend(lst1, temp->data);
        temp = temp->next;
    }
}

int countnode(LIST *lst1)
{
    int count = 0;
    if (lst1->head == NULL)
    {
        printf("\n list is empty");
        return 0;
    }
    SNODE *temp = lst1->head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void findendnode(LIST *lst1, int n)
{

    if (lst1->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *temp = lst1->head;
    SNODE *last = lst1->head;
    for (int i = 0; i <= n; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n not sufficient");
        return;
    }
    while (temp != NULL)
    {
        last = last->next;
        temp = temp->next;
    }
    printf("%c ", last->data);
}

void swap(LIST *lst1, int end, int start)
{
    if (lst1->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *first = lst1->head;
    SNODE *last = lst1->head;

    while (end != 0)
    {
        last = last->next;
        if (last == NULL)
            return;
        end--;
    }

    while (last->next != NULL)
    {
        last = last->next;
        first = first->next;
    }
    last = lst1->head;
    SNODE *temp = NULL;
    while (start != 0)
    {
        last = last->next;
        start--;
    }
    char x = first->data;
    first->data = last->data;
    last->data = x;
}

void reverseList2(LIST *lst2)
{
    if (lst2->head == NULL)
    {
        printf("\n list is empty");
        return;
    }
    SNODE *temp = lst2->head;
    SNODE *cur = lst2->head;
    SNODE *prev = NULL;
    while (cur != NULL)
    {
        temp = temp->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    lst2->head = prev;
}

LIST *copylist(LIST *lst)
{
    LIST *copy = createList();
    SNODE *temp = lst->head;
    while (temp != NULL)
    {
        insertend(copy, temp->data);
        temp = temp->next;
    }
    return copy;
}

LIST *reverse(LIST *lst)
{
    LIST *rev = copylist(lst);
    reverseList2(rev);
    return rev;
}

int isPalindrome(LIST *lst)
{
    LIST *revl = reverse(lst);
    SNODE *list1 = lst->head;
    SNODE *list2 = revl->head;
    while (list1 != NULL)
    {
        if (list1->data != list2->data)
        {
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    printf("\n list is palindrom");
    return 1;
}