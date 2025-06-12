#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int front;
    int rear;
    char *name;
} queue;

int isEmpty(queue *q)
{
    return q->front == -1;
}

int isFull(queue *q)
{
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(queue *q, char x)
{
    if (isFull(q))
    {
        printf("\n queue is full\n");
        return;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->name[q->rear] = x;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->name[q->rear] = x;
    }
}

char dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("\n queue is empty\n");
        return '\0';
    }
    else if (q->front == q->rear)
    {
        char x = q->name[q->front];
        q->front = q->rear = -1;
        return x;
    }
    else
    {
        char x = q->name[q->front];
        q->front = (q->front + 1) % q->size;
        return x;
    }
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty\n");
        return;
    }

    int i = q->front;
    while (1)
    {
        printf("%c ", q->name[i]);
        if (i == q->rear)
            break; // Stop once the rear element is printed
        i = (i + 1) % q->size;
    }
}

queue *createqueue(int n)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = n;
    q->front = q->rear = -1;
    q->name = (char *)calloc(q->size, sizeof(char));
    return q;
}

void destroyqueue(queue *q)
{
    free(q->name);
    free(q);
}

char front(queue *q)
{
    if (isEmpty(q))
    {
        printf("\n queue is empty \n");
        return '\0';
    }
    return q->name[q->front];
}