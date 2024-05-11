#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
int i, j, head=50, idx, initial=0, choice, totalMov=0;
int tracks[SIZE] = {82, 170, 43, 140, 24, 16, 190};
int visited[SIZE], movement[SIZE];

void print(int tracks[]){
    for(i=0;i<SIZE;i++){
        printf("%d\t", tracks[i]);
    }
}

void fcfs(){
    print(tracks);
    for(i=0;i<SIZE;i++){ // for finding head ka idx
        if(head<=tracks[i]){
            idx = i;
            break;
        }
    }
    printf("\n");
    printf("%d -> ", head);

    for(i=idx;i<SIZE;i++){ // 3 4 5 6 
        printf("%d -> ", tracks[i]);
        totalMov += abs(tracks[i] - initial);
        initial = tracks[i];
    }
    for(i=0;i<idx;i++){ // 1 2 
        printf("%d -> ", tracks[i]);
        totalMov += abs(tracks[i] - initial);
        initial = tracks[i];
    }
    
    printf("end");
    printf("\nTotal Movement: %d", totalMov-head);
}

void main(){
    fcfs();
}