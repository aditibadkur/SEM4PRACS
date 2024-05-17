#include<stdio.h>
#define SIZE 4
int i, j, k, x[SIZE];
int graph[SIZE][SIZE]={
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0},
};

int nextValue(int k){
    while(1){
        x[k] = (x[k]+1)%(SIZE);
        if(x[k] == 0){
            return 0;
        }   
        for(j=0;j<SIZE;j++){
            if(graph[k][j]!=0 && x[k]==x[j]){ // to check if that graph edge exists and if two vertices are being 
                // assigned the same color
                    break;
                }
            }
        if(j==SIZE){
            return 1;
        }
    }
}

int gc(int k){
    while(1){
        nextValue(k);
        if(x[k] == 0){
            return 0;
        }
        else if(k == SIZE-1){
            for(i=0;i<SIZE;i++)
            {
                printf("%d ",x[i]);
            }
            printf("\n");
        }
        else{
            gc(k+1);
        }
    }
}

void main(){
    gc(0);
}