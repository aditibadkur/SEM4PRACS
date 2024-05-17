#include<stdio.h>
#include<limits.h>
#include<math.h>
#define SIZE 4
int i, j, k;

int a[SIZE][SIZE]={
    {0,3,INT_MAX-100,7},
    {8,0,2,INT_MAX-100},
    {5,INT_MAX-100,0,1},
    {2,INT_MAX-100,INT_MAX-100,0}
};

int parent[SIZE][SIZE]={
    {-1,1,-1,1},
    {2,-1,2,-1},
    {3,-1,-1,3},
    {4,-1,-1,-1}
};

void print(){
    printf("All Pairs Shortest Path is :\n");
    for (i=0;i<SIZE;i++){
        for (j=0;j<SIZE;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("Parent:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",parent[i][j]);
        }
        printf("\n");
    }
}

void selection(){
    for(k=0;k<SIZE;k++){
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                int temp = a[i][j];
                
                if(a[i][j] > a[i][k] + a[k][j]){
                    a[i][j] = a[i][k] + a[k][j];
                }

                if(temp!=a[i][j]){
                    parent[i][j]=k+1;
                }
            }
        }
    }
    print();
}

void main(){
    selection();
}