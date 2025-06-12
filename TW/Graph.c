#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data[2];
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} LL;

typedef struct
{
    LL *list;
    int **matrix;
    int vertex;
    int isDirected;
    int isWeighted;
} Graph;

Node *createUnweightedNode(int destination)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data[0] = destination;
    newNode->data[1] = 0;
    newNode->next = NULL;
    return newNode;
}
Node *createWeightedNode(int destination, int weight)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data[0] = destination;
    newNode->data[1] = weight;
    newNode->next = NULL;
    return newNode;
}
void createMatrix(Graph *g)
{
    g->matrix = (int **)calloc(g->vertex, sizeof(int *));
    for (int i = 0; i < g->vertex; i++)
    {
        g->matrix[i] = (int *)calloc(g->vertex, sizeof(int));
    }
    for (int i = 0; i < g->vertex; i++)
    {
        for (int j = 0; j < g->vertex; j++)
        {
            g->matrix[i][j] = -1;
        }
    }
}
void createList(Graph *g)
{
    g->list = (LL *)calloc(g->vertex, sizeof(LL));
    for (int i = 0; i < g->vertex; i++)
    {
        g->list[i].head = NULL;
    }
}
Graph *createGraph(int vertex, int isDirected, int isWeighted)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertex = vertex;
    g->isDirected = isDirected;
    g->isWeighted = isWeighted;
    if (isDirected)
    {
        createMatrix(g);
    }
    else
    {
        createList(g);
    }
    return g;
}

void addEdgeDirectedWeighted(Graph *g, int source, int destination, int weight)
{
    g->matrix[source][destination] = weight;
}
void addEdgeDirectedUnweighted(Graph *g, int source, int destination)
{
    g->matrix[source][destination] = 1;
}
void addEdgeUndirectedWeighted(Graph *g, int source, int destination, int weight)
{
    Node *newNode = createWeightedNode(destination, weight);
    newNode->next = g->list[source].head;
    g->list[source].head = newNode;

    newNode = createWeightedNode(source, weight);
    newNode->next = g->list[destination].head;
    g->list[destination].head = newNode;
}
void addEdgeUndirectedUnweighted(Graph *g, int source, int destination)
{
    Node *newNode = createUnweightedNode(destination);
    newNode->next = g->list[source].head;
    g->list[source].head = newNode;

    newNode = createUnweightedNode(source);
    newNode->next = g->list[destination].head;
    g->list[destination].head = newNode;
}

void addWeightedEdge(Graph *g, int source, int destination, int weight)
{
    if (g->isDirected)
        addEdgeDirectedWeighted(g, source, destination, weight);
    else
        addEdgeUndirectedWeighted(g, source, destination, weight);
}
void addUnweightedEdge(Graph *g, int source, int destination)
{
    if (g->isDirected)
        addEdgeDirectedUnweighted(g, source, destination);
    else
        addEdgeUndirectedUnweighted(g, source, destination);
}

void dfsDirected(Graph *g, int start, int *visited)
{
    visited[start] = 1;
    printf("%d\t", start);
    for (int i = 0; i < g->vertex; i++)
    {
        if (g->matrix[start][i] != -1 && !visited[i])
        {
            dfsDirected(g, i, visited);
        }
    }
}

void dfsUndirected(Graph *g, int start, int *visited)
{
    visited[start] = 1;
    printf("%d\t", start);
    Node *temp = g->list[start].head;
    while (temp)
    {
        if (!visited[temp->data[0]])
        {
            dfsUndirected(g, temp->data[0], visited);
        }
        temp = temp->next;
    }
}

void dfs(Graph *g, int start)
{
    int *visited = (int *)calloc(g->vertex, sizeof(int));
    if (g->isDirected)
        dfsDirected(g, start, visited);
    else
        dfsUndirected(g, start, visited);
}
void bfsUndirected(Graph *g, int start, int *visited)
{
    visited[start] = 1;
    int *queue = (int *)calloc(g->vertex, sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = start;
    while (front < rear)
    {
        int data = queue[front++];
        printf("%d\t", data);
        Node *temp = g->list[data].head;
        while (temp)
        {
            if (!visited[temp->data[0]])
            {
                queue[rear++] = temp->data[0];
                visited[temp->data[0]] = 1;
            }
            temp = temp->next;
        }
    }
}
void bfsDirected(Graph *g, int start, int *visited)
{
    visited[start] = 1;
    int *queue = (int *)calloc(g->vertex, sizeof(int));
    int rear = 0;
    int front = 0;
    queue[rear++] = start;
    while (front < rear)
    {
        int data = queue[front++];
        printf("%d\t", data);
        for (int i = 0; i < g->vertex; i++)
        {
            if (g->matrix[data][i] != -1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}
void bfs(Graph *g, int start)
{
    int *visited = (int *)calloc(g->vertex, sizeof(int));
    if (g->isDirected)
        bfsDirected(g, start, visited);
    else
        bfsUndirected(g, start, visited);
}

void displayList(Graph *g)
{
    for (int i = 0; i < g->vertex; i++)
    {
        Node *temp = g->list[i].head;
        printf("%d -> ", i);
        while (temp)
        {
            printf("%d ", temp->data[0]);
            temp = temp->next;
        }
        printf("\n");
    }
}
void displayMatrix(Graph *g)
{
    for (int i = 0; i < g->vertex; i++)
    {
        for (int j = 0; j < g->vertex; j++)
        {
            printf("%d ", g->matrix[i][j]);
        }
        printf("\n");
    }
}
void display(Graph *g)
{
    if (g->isDirected)
        displayMatrix(g);
    else
        displayList(g);
}