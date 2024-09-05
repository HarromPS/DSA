#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int adj_matrix[7][7] =
    {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

void DFS(int current_node)
{
    printf("%d ",current_node);
    visited[current_node]=1;    // marking 1 for the vuisited node
    for(int j=0;j<7;j++){       // traversing the connected nodes
        if(adj_matrix[current_node][j]==1 && !visited[j])
        {
            DFS(j);
        }
    }
}
int main()
{
    DFS(5);
    return 0;
}