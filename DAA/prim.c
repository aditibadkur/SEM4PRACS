#include<stdio.h>
#include<limits.h>
#define SIZE 9

int min(int d[], int visited[]){
    int minElement = INT_MAX;
    int i, minIndex=-1;
    for(i=0;i<SIZE;i++){
        if(visited[i]==0 && d[i]<minElement){
            minIndex = i;
            minElement = d[i];
        }
    }
    return minIndex;
}

void prim(int graph[SIZE][SIZE]){
    int i, j, visited[SIZE], d[SIZE], parent[SIZE];
    for(i=0;i<SIZE;i++){
        visited[i] = 0;
        d[i] = INT_MAX;
    }

    d[0] = 0;
    parent[0] = -1;
    for(i=0;i<SIZE;i++){
        int minIndex = min(d, visited);
        visited[minIndex] = 1;
        for(j=0;j<SIZE;j++){
            if(graph[minIndex][j]!=0 && visited[j] == 0 && d[j]>graph[minIndex][j]){
                d[j] = graph[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }

    for (i=1;i<SIZE;i++)
    {
        printf("Parent(%d) - Vertex(%d) \t%d \n", (parent[i]), i, d[i]);
    }
}

void main(){
    int graph[SIZE][SIZE]={
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 11, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    prim(graph);   
}