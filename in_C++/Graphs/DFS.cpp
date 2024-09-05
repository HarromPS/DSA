#include<iostream>
#include<cstdio>
using namespace std;

int adj_matrix[7][7]=
{
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};
int visited[7]={0,0,0,0,0,0,0};

// Using recursion & in-built compiler stack
// Implementing DFS
void DFS(int current_node){
    printf("%d ",current_node);

    visited[current_node]=1; // 1 means visited
    for(int i=0;i<7;i++){
        if(adj_matrix[current_node][i]==1 && !visited[i])
        {
            DFS(i);
        }
    }

}
int main(){
    DFS(1);
    return 0;
}