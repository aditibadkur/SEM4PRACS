#include<stdio.h>
#define SIZE 14
#define frameSize 4
int i, j, hits=0, faults, frameHead;
int queue[frameSize];
int pages[SIZE]={7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};

void print(){
    printf("Pages : %d \t Frames : ",pages[i]);
    for(j = 0; j < frameSize; j++){
        printf("%d \t",queue[j]);
    }
    printf("\n");
}

void fifo(){
    faults=0;
    frameHead=0;
    for(i=0;i<SIZE;i++){ 
        int miss = 0;
        for(j=0;j<frameSize;j++){
            if(queue[j] != pages[i]){ // checking pages in queue
                miss++;
            }
            else{
                hits++;
                break;
            }
        }
        
        if(i<frameSize){ // filling the frames w pages
            queue[faults] = pages[i];
            faults++;
        }
        else if(miss == frameSize){ // page fault check start + circular indexing se back to first frame
            faults++;
            queue[frameHead] = pages[i]; // fifp hai toh 1st waala out hoga
            frameHead = (frameHead+1)%frameSize;
        }
        
        print();
    }
    printf("Page Faults : %d\n",faults);
    printf("Hits: %d\n", hits);
    printf("Misses: %d", SIZE-hits);
}

void main(){
    for(i=0;i<frameSize;i++){
        queue[i] = -1;
    }
    fifo();
}