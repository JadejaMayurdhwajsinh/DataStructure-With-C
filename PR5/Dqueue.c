#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
} QUEUE;

QUEUE *createqueue(int sz)
{
    QUEUE *q = (QUEUE *)malloc(sizeof(QUEUE));
    q->front = q->rear = -1;
    q->size = sz;
    q->arr = (int *)calloc(q->size, sizeof(int));
    return q;
}

int isEmpty(QUEUE *q)
{
    return q->front == -1;
}

int isFull(QUEUE *q)
{
    return q->rear == q->size - 1;
}

void enqueue(QUEUE *q, int x)
{
    if (isFull(q))
    {
        printf("\n queue is full");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = x;
        return;
    }
    q->rear += 1;
    q->arr[q->rear] = x;
}

void enqueueFront(QUEUE *q, int x)
{
    if (q->front == 0)
    {
        printf("\n no jagya");
        return;
    }
    if (q->front == -1)
    {
        enqueue(q, x);
        return;
    }
    q->front -= 1;
    q->arr[q->front] = x;
    return;
}

int dequeueRear(QUEUE *q)
{
    if (isEmpty(q))
    {
        printf("\n no jagya");
        return 0;
    }
    int x = q->arr[q->rear];
    q->rear -= 1;
    return 1;
}

int dequeue(QUEUE *q)
{
    if (isEmpty(q))
    {
        printf("\n queue is empty");
        return 0;
    }
    if (q->front == q->rear)
    {
        int x = q->arr[q->front];
        q->front = q->rear = -1;
        return x;
    }
    int x = q->arr[q->front];
    q->front += 1;
    return x;
}

void display(QUEUE *q)
{
    if (isEmpty(q))
    {
        printf("\n queue is empty");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void main()
{
    QUEUE *q = createqueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    dequeue(q);
    display(q);
    enqueueFront(q, 60);
    dequeueRear(q);
    display(q);
}