#include<stdio.h>
#define SIZE 5
int p=4, b=5, i, j, frag=0;
int processSize[SIZE]={212, 417, 112, 426};
int blockSize[SIZE]={100, 500, 200, 300, 600};
int fragmentation[SIZE], visited[SIZE]={0}, allocation[SIZE];

void print(){
    printf("P\tP.Size\tB.Allocated\tFragmentation\n"); 
    for(i=0;i<p;i++){
        printf("%d\t%d\t\t%d\t\t\t\t%d\n", i, processSize[i], allocation[i], fragmentation[i]);
    }
    printf("Total Fragmentation :%d", frag);
}

void bestFit(){
    for(i=0;i<p;i++){
        int bestIdx = -1;
        for(j=0;j<b;j++){
            if(processSize[i]<=blockSize[j] && visited[blockSize[j]]!=1){
                if(bestIdx == -1 || blockSize[bestIdx]>blockSize[j]){
                    bestIdx = j;
                }
            }
        }
        if(bestIdx!=-1){
            allocation[i] = blockSize[bestIdx];
            fragmentation[i] = blockSize[bestIdx] - processSize[i];
            frag += fragmentation[i];
            visited[blockSize[bestIdx]] = 1;
        }
    }
    print();
}

void main(){
    bestFit();
}