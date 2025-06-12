#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} Deque;

void initDeque(Deque *dq, int capacity)
{
    dq->arr = (int *)malloc(sizeof(int) * capacity); // Dynamic allocation
    dq->front = -1;
    dq->rear = -1;
    dq->size = 0;
    dq->capacity = capacity;
}

void freeDeque(Deque *dq)
{
    free(dq->arr);
}

bool isEmpty(Deque *dq)
{
    return dq->size == 0;
}

bool isFull(Deque *dq)
{
    return dq->size == dq->capacity;
}

void insertRear(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert at rear.\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->rear = (dq->rear + 1) % dq->capacity;
    }
    dq->arr[dq->rear] = value;
    dq->size++;
}

void insertFront(Deque *dq, int value)
{
    if (isFull(dq))
    {
        printf("Deque is full. Cannot insert at front.\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->front = (dq->front - 1 + dq->capacity) % dq->capacity;
    }
    dq->arr[dq->front] = value;
    dq->size++;
}

int deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from front.\n");
        return -1;
    }
    int value = dq->arr[dq->front];
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->front = (dq->front + 1) % dq->capacity;
    }
    dq->size--;
    return value;
}

int deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty. Cannot delete from rear.\n");
        return -1;
    }
    int value = dq->arr[dq->rear];
    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->rear = (dq->rear - 1 + dq->capacity) % dq->capacity;
    }
    dq->size--;
    return value;
}

void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    int count = 0;
    while (count < dq->size)
    {
        printf("%d ", dq->arr[i]);
        i = (i + 1) % dq->capacity;
        count++;
    }
    printf("\n");
}

int main()
{
    Deque dq;
    int capacity;
    printf("Enter the capacity of the deque: ");
    scanf("%d", &capacity);

    initDeque(&dq, capacity);

    int choice, value;
    while (1)
    {
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFront(&dq, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertRear(&dq, value);
            break;
        case 3:
            value = deleteFront(&dq);
            if (value != -1)
                printf("Deleted from front: %d\n", value);
            break;
        case 4:
            value = deleteRear(&dq);
            if (value != -1)
                printf("Deleted from rear: %d\n", value);
            break;
        case 5:
            display(&dq);
            break;
        case 6:
            freeDeque(&dq);
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
