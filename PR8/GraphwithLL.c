#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

typedef struct node
{
    int dest;
    struct node *next;
} SNODE;

typedef struct
{
    SNODE *head;
} LL;

typedef struct
{
    LL *list;
    int vertices;
} Graph;

Graph *creategraph(int vertices)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->vertices = vertices;
    g->list = (LL *)calloc(vertices, sizeof(LL));
    for (int i = 0; i < vertices; i++)
    {
        g->list[i].head = NULL;
    }
    return g;
}

SNODE *createnode(int dest)
{
    SNODE *new = (SNODE *)malloc(sizeof(SNODE));
    new->dest = dest;
    new->next = NULL;
    return new;
}

void addedges(Graph *g, int src, int dest)
{
    if ((src >= 0 && src < g->vertices) && (dest >= 0 && dest < g->vertices))
    {
        SNODE *new = createnode(src);
        new->next = g->list[dest].head;
        g->list[dest].head = new;

        new = createnode(dest);
        new->next = g->list[src].head;
        g->list[src].head = new;
    }
}

void printgraph(Graph *g)
{
    for (int i = 0; i < g->vertices; i++)
    {
        SNODE *temp = g->list[i].head;
        while (temp)
        {
            printf("%d -> %d ", i, temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
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
            SNODE *temp = g->list[current].head;
            while (temp)
            {
                if (!visited[temp->dest])
                {
                    visited[temp->dest] = 1;
                    enqueue(q, temp->dest);
                }
                temp = temp->next;
            }
        }
    }
    printf("\n");
}

void DFSutil(Graph *g, int start, int *visited)
{
    visited[start] = 1;
    printf("%d  ", start);
    SNODE *temp = g->list[start].head;
    while (temp)
    {
        if (!visited[temp->dest])
        {
            DFSutil(g, temp->dest, visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph *g, int start)
{
    int *visited = (int *)calloc(g->vertices, sizeof(int));
    DFSutil(g, start, visited);
}

int main()
{
    int n;
    printf("\n enter Vertices ");
    scanf("%d", &n);
    Graph *g = creategraph(n);
    populategraph(g);
    printgraph(g);
    BFS(g, 0);
    DFS(g, 1);
}