#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;
typedef struct
{
    Node *head;
    Node *tail;
} LL;

LL *createList()
{
    LL *list = (LL *)malloc(sizeof(LL));
    list->head = NULL;
    list->tail = NULL;

    return list;
}
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void insertFirst(LL *list, int data)
{
    Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        list->head->next = list->head;
        return;
    }
    newNode->next = list->head;
    newNode->prev = list->tail;
    list->head->prev = newNode;
    list->head = newNode;
    list->tail->next = list->head;
}

void insertLast(LL *list, int data)
{

    Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        list->head->next = list->head;
        return;
    }
    newNode->prev = list->tail;
    newNode->next = list->head;
    list->tail->next = newNode;
    list->tail = newNode;
    list->head->prev = list->tail;
}

int deleteFirst(LL *list)
{
    if (list->head == NULL)
    {
        printf("List Is EMpty !!");
        return -1;
    }
    if (list->head->next == NULL)
    {
        list->head = list->tail = NULL;
        return -1;
    }
    int data = list->head->data;
    list->head = list->head->next;
    list->head->prev = list->tail;
    list->tail->next = list->head;
    free(list->head->prev);
    return data;
}

int deleteLast(LL *list)
{
    if (list->head == NULL)
    {
        printf("List Is EMpty !!");
        return -1;
    }
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
        return -1;
    }
    int data = list->tail->prev->data;
    list->tail = list->tail->prev;
    list->tail->next = list->head;
    list->head->prev = list->tail;
    // free(list->tail->next);
    return data;
}

void insertIdx(LL *list, int idx, int data)
{
    Node *newNode = createNode(data);
    if (list->head == NULL)
    {
        list->head = list->tail = newNode;
        list->head->next = list->head;
        return;
    }
    if (idx == 0)
    {
        insertFirst(list, data);
        return;
    }
    Node *temp = list->head;
    while (idx > 1 && temp->next != list->head)
    {
        temp = temp->next;
        idx--;
    }
    if (temp->next == list->head)
    {
        insertLast(list, data);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void display(LL *list)
{
    if (list->head == NULL)
    {
        printf("\nList Has No Elements !!");
        return;
    }
    Node *temp = list->head;
    printf("\n\n");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != list->head);
    printf("NULL");
}
void displayRev(LL *list)
{
    if (list->head == NULL)
    {
        printf("\nList Has No Elements !!");
        return;
    }
    Node *temp = list->tail;
    printf("\nReverser \n");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    } while (temp != list->tail);
    printf("NULL");
}