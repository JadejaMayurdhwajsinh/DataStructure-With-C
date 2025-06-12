#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
typedef struct
{
    int vertices;
    int **adjacencymatrix;
} Graph;

Graph *initialize(int v)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertices = v;
    g->adjacencymatrix = (int **)malloc(g->vertices * sizeof(int *));
    for (int i = 0; i < g->vertices; i++)
    {
        g->adjacencymatrix[i] = (int *)calloc(g->vertices, sizeof(int));
    }
    return g;
}

void printgraph(Graph *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            printf("%d ", g->adjacencymatrix[i][j]);
        }
        printf("\n");
    }
}

void printedgestotaldegree(Graph *g)
{
    int totaledges = 0;
    for (int i = 0; i < g->vertices; i++)
    {
        int degree = 0;
        for (int j = 0; j < g->vertices; j++)
        {
            if (g->adjacencymatrix[i][j] == 1)
            {
                degree++;
            }
        }
        printf("\n");
        printf("Vertex %d : %d degree", i, degree);
        totaledges += degree;
    }
    totaledges /= 2;
    printf("\n total edges : %d ", totaledges);
    printf("\n");
}

void BFS(Graph *g, int start)
{
    int *visited = (int *)calloc(g->vertices, sizeof(int));
    queue *q = createqueue(g->vertices);
    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q))
    {
        int current = dequeue(q);
        printf("%d  ", current);

        for (int i = 0; i < g->vertices; i++)
        {
            if (g->adjacencymatrix[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

void DFS(Graph *g, int start, int *visited)
{
    visited[start] = 1;
    printf("%d ", start);
    for (int i = g->vertices; i >= 0; i--)
    {
        if (g->adjacencymatrix[start][i] == 1 && !visited[i])
        {
            DFS(g, i, visited);
        }
    }
}

void addedges(Graph *g, int src, int dest)
{
    g->adjacencymatrix[src][dest] = 1;
}

void main()
{
    Graph *g = initialize(4);
    addedges(g, 0, 1);
    addedges(g, 0, 2);
    addedges(g, 1, 2);
    addedges(g, 1, 3);
    printgraph(g);
    printedgestotaldegree(g);
    BFS(g, 3);
    int *visited = (int *)calloc(g->vertices, sizeof(int));
    DFS(g, 0, visited);
}