#include<stdio.h>
#define SIZE 5
int p=4, b=5, i, j, frag=0, allocatedIdx=-1;
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

void nextFit(){
    for(i=0;i<p;i++){

        for(j=allocatedIdx+1;j<b;j++){
            if(processSize[i]<=blockSize[j] && visited[blockSize[j]]!=1){
                allocation[i] = blockSize[j];
                fragmentation[i] = blockSize[j] - processSize[i];
                frag += fragmentation[i];
                visited[blockSize[j]] = 1;
                allocatedIdx = j;
                break;
            }
        }

        if(allocatedIdx==b-1){
            for(j=0;j<allocatedIdx;j++){
                if(processSize[i]<=blockSize[j] && visited[blockSize[j]]!=1){
                    allocation[i] = blockSize[j];
                    fragmentation[i] = blockSize[j] - processSize[i];
                    frag += fragmentation[i];
                    visited[blockSize[j]] = 1;
                    allocatedIdx = j;
                    break;
                }
            }
        }
    }
    print();
}

void main(){
    nextFit();
}