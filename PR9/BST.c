#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node *createnode(int x)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->left = NULL;
    new->right = NULL;
    new->data = x;
    return new;
}

Node *insert(Node *root, int x)
{
    Node *new = createnode(x);
    if (root == NULL)
    {
        root = new;
        return root;
    }
    if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
    }
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelorder(Node *root)
{

    if (root == NULL)
        return;
    Node **queue = (Node **)malloc(100 * sizeof(Node *)); // Assuming a maximum of 100 nodes
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear)
    {
        Node *current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    free(queue); // Free the allocated memory for the queue
}

int search(Node *root, int elem)
{
    if (root == NULL)
        return -1;
    if (root->data == elem)
        return 1;
    if (elem < root->data)
        return search(root->left, elem);
    else
        return search(root->right, elem);
}

int countExternalNodes(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

int countInternalNodes(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return countInternalNodes(root->left) + countInternalNodes(root->right) + 1;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void main()
{
    Node *root = NULL;
    int n, x, target;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("\n level order \n");
    levelorder(root);
    printf("\n enter target for search");
    scanf("%d", &target);
    printf("%d", search(root, target));
    printf("\n internal nodes %d\n  external nodes %d", countInternalNodes(root), countExternalNodes(root));
    printf("\n");
    free(root); // Free the allocated memory for the root node
}