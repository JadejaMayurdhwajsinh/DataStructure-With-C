#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int top;
    char *name;
    int size;
} CHAR_STACK;

CHAR_STACK *createStack(int n)
{
    CHAR_STACK *s = (CHAR_STACK *)malloc(sizeof(CHAR_STACK));
    s->top = -1;
    s->size = n;
    s->name = (char *)calloc(s->size, sizeof(char));
    return s;
}

int isEmptystack(CHAR_STACK *s)
{
    return s->top == -1;
}

int isFullstack(CHAR_STACK *s)
{
    return s->top >= s->size - 1;
}

void push(CHAR_STACK *s, char el)
{
    if (isFullstack(s))
    {
        printf("\n stack is full");
        return;
    }
    s->top += 1;
    s->name[s->top] = el;
}

char pop(CHAR_STACK *s)
{
    char x;
    if (isEmptystack(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    x = s->name[s->top];
    s->top -= 1;
    return x;
}

char peak(CHAR_STACK *s)
{
    if (isEmptystack(s))
    {
        printf("\n stack is empty");
        return '\0';
    }
    return s->name[s->top];
}

void displaystack(CHAR_STACK *s)
{
    if (isEmptystack(s))
    {
        printf("\n stack is empty");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c", s->name[i]);
    }
}

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
    return q->rear >= q->size - 1;
}

void enqueue(queue *q, char x)
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

char dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("\n queue is empty\n");
        return '\0';
    }
    char x = q->name[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
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
        printf("%c", q->name[i]);
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

void reversequeue(queue *q)
{
    // If queue is empty, nothing to reverse
    if (isEmpty(q))
    {
        return;
    }

    // Calculate number of elements
    int elemCount = q->rear - q->front + 1;

    // Temporary array to store elements in reverse order
    char *temp = (char *)malloc(elemCount * sizeof(char));

    // Copy elements to temp array
    for (int i = 0; i < elemCount; i++)
    {
        temp[i] = q->name[q->front + i];
    }

    // Reset queue
    q->front = q->rear = -1;

    // Re-enqueue in reverse order
    for (int i = elemCount - 1; i >= 0; i--)
    {
        enqueue(q, temp[i]);
    }

    free(temp);
}