#include<stdio.h>
#define SIZE 11
int i, j;
int AT[SIZE]={1, 3, 0, 5, 3, 5, 6, 7, 8, 2, 12}, BT[SIZE]={4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16}, activity_start[SIZE], activity_end[SIZE];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(){
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE-i-1;j++){
            if(BT[j]>BT[j+1]){
                swap(&AT[j], &AT[j+1]);
                swap(&BT[j], &BT[j+1]);
            }
        }
    }
}

void print(){
    for(i=0;i<SIZE;i++){
        if(activity_start[i] != 0 && activity_end[i] != 0){
            printf("%d -> %d", activity_start[i], activity_end[i]);
            printf("\n");
        }
        else{
            continue;
        }
    }
}

void selection(){
    int start=0;
    for(i=0;i<SIZE;i++){
        if(AT[i]>=start){
            start = BT[i];
            activity_start[i] = AT[i];
            activity_end[i] = BT[i];
        }
    }
    print();
}


void main(){
    sort();
    selection();
}