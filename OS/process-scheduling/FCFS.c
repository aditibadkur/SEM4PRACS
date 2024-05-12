// basics so no preemption

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int i, j, CT[SIZE]={0}, TATime[SIZE]={0}, WT[SIZE]={0};
float total_TAT=0, total_WT=0;
int AT[SIZE]={0,2,3,5};
int BT[SIZE]={4,3,2,1};

void calcTime(){
    for(i=0;i<SIZE;i++){
        TATime[i] = CT[i] - AT[i];
        WT[i] = TATime[i] - BT[i];

        total_TAT += TATime[i];
        total_WT += WT[i];
    }
}

void execTime(){
    CT[0] = abs(BT[0]-AT[0]);
    for(i=0;i<SIZE;i++){
        CT[i] = CT[i-1] + BT[i];
    }
}

void print(){
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(j=0;j<SIZE;j++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", j, AT[j], BT[j], CT[j], TATime[j], WT[j]);
    }
    
    printf("\nAvg TAT: %.2f", total_TAT/SIZE);
    printf("\nAvg WT: %.2f", total_WT/SIZE);
}

void main(){
    execTime();
    calcTime();
    print();
}