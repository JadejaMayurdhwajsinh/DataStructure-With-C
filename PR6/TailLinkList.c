#include "stdio.h"
#include "stdlib.h"
typedef struct Node
{
    int data;
    struct Node *next;
} SNODE;
typedef struct
{
    SNODE *head;
    SNODE *tail;
} LL;

LL *createList()
{
    LL *list = (LL *)malloc(sizeof(LL));
    list->head = list->tail = NULL;

    return list;
}
SNODE *createNode(int data)
{
    SNODE *newNode = (SNODE *)malloc(sizeof(SNODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertFirst(LL *list, int data)
{
    SNODE *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        return;
    }
    newNode->next = list->head;
    list->head = newNode;
}

void insertLast(LL *list, int data)
{

    SNODE *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }
    SNODE *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    list->tail = newNode;
}

int isEmpty(LL *list)
{
    return list->head == NULL;
}

void enQueue(LL *list, int data)
{

    SNODE *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }
    SNODE *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    list->tail = newNode;
}

int deleteFirst(LL *list)
{
    if (list->head == NULL)
    {
        printf("List Is EMpty !!");
        return -1;
    }
    int data = list->head->data;
    list->head = list->head->next;
    return data;
}
int deQueue(LL *list)
{
    if (list->head == NULL)
    {
        printf("Queue Is EMpty !!");
        return -1;
    }
    int data = list->head->data;
    list->head = list->head->next;
    return data;
}

int deleteLast(LL *list)
{
    if (list->head == NULL)
    {
        printf("List Is EMpty !!");
        return -1;
    }
    if (list->head->next == NULL)
    {
        list->head = NULL;
    }
    SNODE *temp = list->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    list->tail = temp;
    return data;
}
int midElement(LL *list)
{
    if (list->head == NULL)
    {
        return -1;
    }
    if (list->head->next == NULL)
    {
        return list->head->data;
    }
    SNODE *slow = list->head;
    SNODE *fast = list->head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
LL *copyList(LL *list)
{
    LL *copyLL = createList();
    SNODE *temp = list->head;
    while (temp != NULL)
    {
        insertLast(copyLL, temp->data);
        temp = temp->next;
    }
    return copyLL;
}
LL *reverseLL(LL *list)
{
    LL *copy = copyList(list);
    SNODE *prev = NULL;
    SNODE *curr = copy->head;
    while (curr != NULL)
    {
        SNODE *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    copy->head = prev;
    return copy;
}

int isPelindrome(LL *list)
{
    LL *revList = reverseLL(list);
    SNODE *list1 = list->head;
    SNODE *list2 = revList->head;
    while (list1 != NULL)
    {
        if (list1->data != list2->data)
        {
            return 0;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return 1;
}

void sortList(LL *list)
{
    if (list == NULL)
    {
        printf("\nList Is Empty !!");
        return;
    }
    if (list->head == NULL)
    {
        printf("\nList Is EMpty !");
        return;
    }
    if (list->head->next == NULL)
    {
        return;
    }
    SNODE *outer = list->head;
    while (outer != NULL)
    {
        SNODE *inner = outer->next;
        SNODE *temp = outer;
        while (inner != NULL)
        {
            if (temp->data > inner->data)
            {
                temp = inner;
            }
            inner = inner->next;
        }
        int data = temp->data;
        temp->data = outer->data;
        outer->data = data;
        outer = outer->next;
    }
}
SNODE *midNode(SNODE *start, SNODE *end)
{
    if (start == NULL)
    {
        return NULL;
    }
    if (start->next == NULL)
    {
        return start;
    }
    SNODE *slow = start;
    SNODE *fast = start;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int searchNode(LL *list, int key)
{
    if (list == NULL)
    {
        printf("\nList Is Empty !!");
        return -1;
    }
    if (list->head == NULL)
    {
        printf("\nList Is EMpty !");
        return -1;
    }
    SNODE *start = list->head;
    SNODE *end = list->tail;
    SNODE *mid = NULL;
    while (start != end)
    {
        mid = midNode(start, end);
        if (mid->data == key)
        {
            printf("\nValue Founded !!");
            return mid->data;
        }
        else if (mid->data > key)
        {
            end = mid;
        }
        else
        {
            start = mid->next;
        }
    }
    if (mid->next->data == key)
    {
        printf("\nValue Founded !");
        return mid->next->data;
    }
    return -1;
}

void solve(SNODE *start)
{
    if (start == NULL)
        return;
    printf("%d ", start->data);
    if (start->next != NULL)
        solve(start->next->next);
    printf("%d ", start->data);
}
void display(LL *list)
{
    if (list->head == NULL)
    {
        printf("\nList Has No Elements !!");
        return;
    }
    SNODE *temp = list->head;
    printf("\n\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void displayRecursion(SNODE *head)
{
    if (head == NULL)
    {
        return;
    }
    printf("%d\t", head->data);
    displayRecursion(head->next);
}