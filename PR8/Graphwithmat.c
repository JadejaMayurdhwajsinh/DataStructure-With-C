#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

typedef struct
{
    int vertices;
    int **adjacentmatrix;
} Graph;

Graph *creategraph(int vertices)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertices = vertices;
    g->adjacentmatrix = (int **)calloc(g->vertices, sizeof(int *));
    for (int i = 0; i < vertices; i++)
    {
        g->adjacentmatrix[i] = (int *)calloc(g->vertices, sizeof(int));
    }
    return g;
}

void printgraph(Graph *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            printf("%d ", g->adjacentmatrix[i][j]);
        }
        printf("\n");
    }
}

void addedges(Graph *g, int src, int dest)
{
    if ((src >= 0 && src < g->vertices) && (dest >= 0 && dest < g->vertices))
    {
        g->adjacentmatrix[src][dest] = 1;
        g->adjacentmatrix[dest][src] = 1;
    }
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

        for (int i = g->vertices - 1; i >= 0; i--)
        {
            if (g->adjacentmatrix[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");
}

void DFSutil(Graph *g, int start, int *visited)
{
    visited[start] = 1;
    printf("%d  ", start);

    for (int i = g->vertices - 1; i >= 0; i--)
    {
        if (g->adjacentmatrix[start][i] == 1 && !visited[i])
        {
            DFSutil(g, i, visited);
        }
    }
}

void DFS(Graph *g, int start)
{
    int *visited = (int *)calloc(g->vertices, sizeof(int));
    DFSutil(g, start, visited);
}

void freeGraph(Graph *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        free(g->adjacentmatrix[i]);
    }
    free(g->adjacentmatrix);
    free(g);
}

void populategraph(Graph *g)
{
    int edges, src, dest;
    printf("\n enter edges");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++)
    {
        printf("\n enter src for edge %d ", i + 1);
        scanf("%d", &src);
        printf("\n enter dest for edge %d ", i + 1);
        scanf("%d", &dest);
        addedges(g, src, dest);
    }
}

void totaledges(Graph *g)
{
    int total = 0;
    for (int i = 0; i < g->vertices; i++)
    {
        int degree = 0;
        for (int j = 0; j < g->vertices; j++)
        {
            if (g->adjacentmatrix[i][j] == 1)
            {
                degree++;
            }
        }
        total += degree;
        printf("Vertex %d : %d degree", i, degree);
        printf("\n");
    }
    total /= 2;
    printf("TOTAL %d ", total);
}

int main()
{
    int n;
    printf("\n enter vertices");
    scanf("%d", &n);
    Graph *g = creategraph(n);
    populategraph(g);
    printgraph(g);
    BFS(g, 0);
    DFS(g, 1);
    totaledges(g);
}