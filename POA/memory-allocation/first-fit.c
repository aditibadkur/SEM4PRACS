#include<stdio.h>
#define SIZE 5
int p=4, b=4, i, j, frag=0;
int processSize[SIZE]={110, 220, 330, 440};
int blockSize[SIZE]={100, 200, 300, 400};
int fragmentation[SIZE], visited[SIZE]={0}, allocation[SIZE];

void print(){
    printf("P\tP.Size\tB.Allocated\tFragmentation\n"); 
    for(i=0;i<p;i++){
        printf("%d\t%d\t\t%d\t\t\t\t%d\n", i, processSize[i], allocation[i], fragmentation[i]);
    }
    printf("Total Fragmentation :%d", frag);
}

void firstFit(){
    for(i=0;i<p;i++){
        for(j=0;j<b;j++){
            if(processSize[i]<=blockSize[j] && visited[blockSize[j]]!=1){
                allocation[i] = blockSize[j];
                fragmentation[i] = blockSize[j] - processSize[i];
                frag += fragmentation[i];
                visited[blockSize[j]] = 1;
                break;
            }
        }
    }
    print();
}

void main(){
    firstFit();
}