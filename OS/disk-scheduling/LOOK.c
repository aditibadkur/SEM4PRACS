#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
int i, j, head=50, idx, initial=0, choice, totalMov=0;
int tracks[SIZE] = {176, 79, 34, 60, 92, 11, 41, 114};
int visited[SIZE], movement[SIZE];

void print(int tracks[]){
    for(i=0;i<SIZE;i++){
        printf("%d\t", tracks[i]);
    }
}

void sort(int tracks[]){
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE-i-1;j++){
            if(tracks[j]>tracks[j+1]){
                int temp = tracks[j+1];
                tracks[j+1] = tracks[j];
                tracks[j] = temp;
            }
        }
    }
    print(tracks);
}

void look(){
    sort(tracks);
    for(i=0;i<SIZE;i++){ // for finding head ka idx
        if(head<=tracks[i]){
            idx = i;
            break;
        }
    }
    printf("\nIndex: %d", idx);
    printf("\nUP=0, DOWN=1: ");
    scanf("%d", &choice);
    printf("%d -> ", head);

    switch (choice)
    {
    case 0: // UP
    for(i=idx-1;i>=0;i--){ // 3 2 1
        printf("%d -> ", tracks[i]);
        totalMov += abs(tracks[i] - initial);
        initial = tracks[i];
    }
    for(i=idx;i<SIZE;i++){ // 4 5 6
        printf("%d -> ", tracks[i]);
        totalMov += abs(tracks[i] - initial);
        initial = tracks[i];
    }

    break;

    case 1: // DOWN 
    for(i=idx;i<SIZE;i++){ // 3 4 5 6 
        printf("%d -> ", tracks[i]);
        totalMov += abs(tracks[i] - initial);
        initial = tracks[i];
    }
    for(i=idx-1;i>=0;i--){ // 2 1
        printf("%d -> ", tracks[i]);
        totalMov += abs(tracks[i] - initial);
        initial = tracks[i];
    }
    
    break;

    default: printf("\nEnter valid option");
        break;
    }
    printf("end");
    printf("\nTotal Movement: %d", totalMov-head);
}

void main(){
    look();
}