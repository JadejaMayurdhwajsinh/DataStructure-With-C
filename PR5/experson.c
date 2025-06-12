#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name;
    int amt;
} Person;

typedef struct
{
    Person *data;
    int size;
    int front;
    int rear;
} QUEUE;

QUEUE *createQueue(int size)
{
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    q->data = (Person *)calloc(size, sizeof(Person));
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

int isFullQueue(QUEUE *q)
{
    return q->rear == q->size - 1;
}

int isEmptyQueue(QUEUE *q)
{
    return q->front == -1 || q->front > q->rear;
}

void enQueue(QUEUE *q, Person p)
{
    if (isFullQueue(q))
    {
        printf("\nQueue is Full!");
        return;
    }
    if (isEmptyQueue(q))
    {
        q->front = 0;
    }
    q->data[++q->rear] = p;
    printf("\nENQUEUE({%c, %d})", p.name, p.amt);
}

Person deQueue(QUEUE *q)
{
    Person p = {'\0', 0};
    if (isEmptyQueue(q))
    {
        printf("\nQueue is Empty!");
        return p;
    }
    p = q->data[q->front++];
    printf("\nDEQUEUE() => {%c, %d}", p.name, p.amt);
    return p;
}

void displayQueue(QUEUE *q)
{
    if (isEmptyQueue(q))
    {
        printf("\nQueue is Empty!");
        return;
    }
    printf("\nQueue Contents:\n");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("{%c, %d}\t", q->data[i].name, q->data[i].amt);
    }
    printf("\n");
}