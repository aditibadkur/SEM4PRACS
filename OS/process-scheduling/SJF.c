// Criteria: BT 
// Always NP if we try to make this preemptive then it becomes SRTF
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int i, j, CT[SIZE]={0}, TATime[SIZE]={0}, WT[SIZE]={0};
float total_TAT=0, total_WT=0;
int process[SIZE]={1, 2, 3, 4};
int AT[SIZE]={1,2,1,4};
int BT[SIZE]={3,4,2,4};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(){
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE-i-1;j++){
            if(BT[j]>BT[j+1]){
                swap(&BT[j], &BT[j+1]);
                swap(&AT[j], &AT[j+1]);
                swap(&process[j], &process[j+1]);
            }
        }
    }
}

void execTime(){
    CT[0] = BT[0]+AT[0];
    for(i=1;i<SIZE;i++){
        CT[i] += CT[i-1] + BT[i];
    }
}

void calcTime(){
    for(i=0;i<SIZE;i++){
        TATime[i] = CT[i] - AT[i];
        WT[i] = TATime[i] - BT[i];

        total_TAT += TATime[i];
        total_WT += WT[i];
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
    sort();
    execTime();
    calcTime();
    print();
}