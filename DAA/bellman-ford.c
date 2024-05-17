#include<stdio.h>
#define SIZE 8
int i, j, k, source=0;
int parent[SIZE], dist[SIZE];
int graph[SIZE][SIZE]={
    {0,6,5,5,0,0,0},
    {0,0,0,0,-1,0,0},
    {0,-2,0,0,1,0,0},
    {0,0,-2,0,0,-1,0},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,3},
    {0,0,0,0,0,0,0}
};

void initialiseSingleSource(){
    for(i=0;i<SIZE;i++){
        parent[i] = -1;
        dist[i] = 999;
    }
    dist[source] = 0;
}

void relax(int u, int v){
    if(dist[v]>dist[u]+graph[u][v]){
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
    }
}

void bellman(){
    int c;
    initialiseSingleSource();
    for(k=0;k<SIZE-1;k++){
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                if(graph[i][j]!=0){
                    relax(i, j);
                }
            }
        }
    }

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(dist[j]>dist[i]+graph[i][j] && graph[i][j]!=0){
                c = 1;
            }
        }
    }

    if(c==1){
        printf("\nNo answer(presence of -ve wts)");
    }
    else{
        printf("\nDistance :");
        for(i=0;i<SIZE;i++){
            printf("%d ",dist[i]);
        }
        printf("\nParent:");
        for(i=0;i<SIZE;i++){
            printf("%d ",parent[i]+1);
        }
    }

}

void main(){
    bellman();

}