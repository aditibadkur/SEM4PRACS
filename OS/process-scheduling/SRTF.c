#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int i, j, CT[SIZE]={0}, TATime[SIZE]={0}, WT[SIZE]={0}, time, count=0;
float total_TAT=0, total_WT=0;
int process[SIZE]={1, 2, 3, 4};
int AT[SIZE]={0, 1, 2, 4};
int BT[SIZE]={5, 3, 4, 1};
int bt[SIZE]={5, 3, 4, 1};

void print(){
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(j=0;j<SIZE;j++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", j, AT[j], bt[j], CT[j], TATime[j], WT[j]);
        total_TAT += TATime[i];
        total_WT += WT[i];
    }
    
    printf("\nAvg TAT: %.2f", total_TAT/SIZE);
    printf("\nAvg WT: %.2f", total_WT/SIZE);
}

void srtf(){
    for(time=0;count<SIZE;time++){ // count = how many process have been executed completely
        int min = 10;
        for(i=0;i<SIZE;i++){ // loop for iterating through all the processes after decrementing
            if(AT[i]<=time && BT[i]<BT[min] && BT[i]>0){ // calculating which process has min BT
                min = i;
            }
        }
        BT[min]--;

        if(BT[min] == 0){ 
            count++; 
            CT[min] = time+1;
            TATime[min] = CT[min] - AT[min];
            WT[min] = TATime[min] - bt[min];
        }
    }
    print();
}

void main(){
    for(i=0;i<SIZE;i++){
        bt[i] = BT[i];
    }
    BT[10] = 999;
    srtf();
}