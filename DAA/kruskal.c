#include<stdio.h>
#define SIZE 5
int graph[SIZE][SIZE]={
    {0, 4, 7, 9, 8},
    {4, 0, 1, 0, 0},
    {7, 1, 0, 2, 0},
    {9, 0, 2, 0, 6},
    {8, 0, 0, 6, 0}
};

void kruskal(){
    int visited[SIZE] = {0};
    visited[0] = 1;
    int i, j, edges = 1, mincost=0;
    while(edges<SIZE){
        int a=-1, b=-1, min=999;
        for(i=0;i<SIZE;i++){
            if(visited[i]){
                for(j=0;j<SIZE;j++){
                    if(!visited[j] && graph[i][j]!=0 && min>graph[i][j]){
                        min = graph[i][j];
                        a=i;
                        b=j; 
                    }
                }
            }
        }
        if(a!=-1 && b!=-1){
            printf("%d edge (%d,%d) = %d\n", edges++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
    }
    printf("\nMinimum cost = %d\n", mincost);
}

void main(){
    kruskal();
}