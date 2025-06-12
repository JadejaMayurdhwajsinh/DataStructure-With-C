#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct DoublyNode
{
    int data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
};

struct Node *create_singly_node(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct DoublyNode *create_doubly_node(int data)
{
    struct DoublyNode *new_node = (struct DoublyNode *)malloc(sizeof(struct DoublyNode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

struct Node *insert_singly_end(struct Node *head, int data)
{
    struct Node *new_node = create_singly_node(data);
    if (head == NULL)
    {
        return new_node;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void insert_doubly_end(struct DoublyNode **head, int data)
{
    struct DoublyNode *new_node = create_doubly_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    struct DoublyNode *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void copy_to_doubly_list(struct Node *headnode, struct DoublyNode **doubly_head)
{
    struct Node *temp = headnode;
    while (temp != NULL)
    {
        insert_doubly_end(doubly_head, temp->data);
        temp = temp->next;
    }
}

int find_pair_with_sum(struct DoublyNode *head, int target_sum)
{
    struct DoublyNode *left = head;
    struct DoublyNode *right = head;

    while (right != NULL && right->next != NULL)
    {
        right = right->next;
    }

    while (left != NULL && right != NULL && left != right && right->next != left)
    {
        int sum = left->data + right->data;
        if (sum == target_sum)
        {
            printf("Pair found: %d and %d\n", left->data, right->data);
            return 1; // Pair found
        }
        else if (sum < target_sum)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return 0;
}

void display_singly(struct Node *head)
{
    if (head == NULL)
    {
        printf("Singly Linked List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_doubly(struct DoublyNode *head)
{
    if (head == NULL)
    {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    struct DoublyNode *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *headnode = NULL;
    struct DoublyNode *doubly_head = NULL;
    int target_sum;

    headnode = insert_singly_end(headnode, 1);
    headnode = insert_singly_end(headnode, 4);
    headnode = insert_singly_end(headnode, 6);
    headnode = insert_singly_end(headnode, 8);
    headnode = insert_singly_end(headnode, 9);

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    printf("Singly Linked List: ");
    display_singly(headnode);

    copy_to_doubly_list(headnode, &doubly_head);

    printf("Doubly Linked List: ");
    display_doubly(doubly_head);

    if (!find_pair_with_sum(doubly_head, target_sum))
    {
        printf("No pair found with the target sum %d\n", target_sum);
    }

    return 0;
}