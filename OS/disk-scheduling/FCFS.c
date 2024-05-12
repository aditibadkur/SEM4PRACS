#include<stdio.h>
#include<stdlib.h>
#define n 7
int i, j, idx, total_mov=0, initial, choice, head=50, SIZE;
int tracks[n] = {82, 170, 43, 140, 24, 16, 190};

void print(int arr[]){
    for(i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void sort(int arr[]){
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    print(tracks);
}

void fcfs(){
    print(tracks);
    for(i=0;i<n;i++){ // for finding index
        if(head<tracks[i]){
            idx = i;
            break;
        }
    }
    
    initial = head;
    printf("%d -> ", head);
    for(i=0;i<n;i++){
        printf("%d -> ", tracks[i]);
        total_mov += abs(tracks[i] - initial);
        initial = tracks[i];
    }
    printf("end");
    printf("\nTotal Mov: %d", total_mov);
    
}

void main(){
    fcfs();
}