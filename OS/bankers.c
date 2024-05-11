#include<stdio.h>
#define process 5
#define resources 3
int i, j, need[process][resources], visited[process], safeSeq[process];

int allocation[process][resources]={
    {0, 1, 0},  
    {2, 0, 0},  
    {3, 0, 2},  
    {2, 1, 1},  
    {0, 0, 2}   
};

int max[process][resources] = {
    {7, 5, 3},  
    {3, 2, 2},  
    {9, 0, 2},  
    {2, 2, 2},  
    {4, 3, 3} 
};

int avail[resources] = {3, 3, 2};

void print(){
    for(i=0;i<process;i++){
        printf("%d -> ", safeSeq[i]);
    }
    printf("end");
}

int isSafe(int p){
    for(j=0;j<resources;j++){
        if(need[p][j]>avail[j]){
            return 0;
        }
    }
    return 1;
}

void bankers(){
    int count=0;
    while(count<process){
        int found=0;
        for(i=0;i<process;i++){
            if(!visited[i] && isSafe(i)){
                for(j=0;j<resources;j++){
                    avail[j] += allocation[i][j];
                   
                }
                visited[i] = 1;
                safeSeq[count++] = i;
                found = 1;
            }
        }
        if(!found){
            printf("\nNot Safe Sequence");
            return;
        }
    }
    printf("\nSafe Sequence\n");
    print();
}

void main(){
    for(i=0;i<process;i++){
        for(j=0;j<resources;j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    bankers();
}