#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int front;
    int rear;
    int *name;
} queue;

int isEmpty(queue *q)
{
    return q->front == -1;
}

int isFull(queue *q)
{
    return q->rear >= q->size - 1;
}

void enqueue(queue *q, int x)
{
    if (isFull(q))
    {
        printf("\n queue is full\n");
        return;
    }
    q->rear += 1;
    q->name[q->rear] = x;
    if (q->front == -1)
    {
        q->front += 1;
    }
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("\n queue is empty\n");
        return -1;
    }
    int x = q->name[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
        q->front += 1;
    return x;
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("\n queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->name[i]);
    }
    printf("\n");
}

queue *createqueue(int n)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = n;
    q->front = q->rear = -1;
    q->name = (int *)calloc(q->size, sizeof(int));
    return q;
}

void destroyqueue(queue *q)
{
    free(q->name);
    free(q);
}