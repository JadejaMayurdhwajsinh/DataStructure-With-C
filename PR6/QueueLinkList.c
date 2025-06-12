#include "stdio.h"
#include "stdlib.h"

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

Queue *createQueue()
{
    Queue *newqueue = (Queue *)malloc(sizeof(Queue));
    newqueue->front = NULL;
    newqueue->rear = NULL;
    return newqueue;
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enQueue(Queue *queue, int data)
{
    if (queue == NULL)
    {
        printf("\nQueue Is Not Created !!");
        return;
    }
    Node *newNode = createNode(data);
    if (queue->front == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int deQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Is Empty !");
        return -1;
    }
    int data = queue->front->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->front = queue->rear = NULL;
    }
    return data;
}

void display(Queue *queue)
{

    if (queue == NULL)
    {
        printf("\nqueue Is Not Created !!");
        return;
    }
    if (queue->front == NULL)
    {
        printf("\nqueue Has No Elements !!");
        return;
    }
    Node *temp = queue->front;
    printf("\n\n");
    while (temp != NULL)
    {
        printf("%d <-- ", temp->data);
        temp = temp->next;
    }
    printf("END");
}
