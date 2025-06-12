#include "Graph.c"

void main(){
    FILE *file;
    int isDirected,isWighted, n, e;
    int source,destination,weight;

    //file = fopen("tgraph.txt", "r"); // Directed unweighted 
    file = fopen("fgraph.txt", "r"); // Undirected weighted 
    // file = fopen("Test_file/DW.txt", "r"); // Directed weighted 
    // file = fopen("Test_file/DU.txt", "r"); // Directed Unweighted
    // file = fopen("Test_file/UW.txt", "r"); // UNDirected weighted
    // file = fopen("Test_file/UU.txt", "r"); // UNDirected Unweighted
    
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fscanf(file, "%d", &isDirected);
    fscanf(file, "%d", &isWighted);
    fscanf(file, "%d", &n);
    fscanf(file, "%d", &e);

    Graph *g = createGraph(n,isDirected,isWighted);
    for(int i = 0; i < e; i++){
        fscanf(file, "%d", &source);
        fscanf(file, "%d", &destination);
        if(g->isWeighted){
            fscanf(file, "%d", &weight);
            addWeightedEdge(g,source,destination,weight);
        }
        else{
            addUnweightedEdge(g,source,destination);
        }
    }
    // display(g);
    printf("\nDFS : ");
    dfs(g,7);
    printf("\nBFS : ");
    bfs(g,7);
}