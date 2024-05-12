#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int count=0, mutex=1, full=0, empty=SIZE;
// mutex = 1 available

int wait(int s){ // blocks semaphore
    return --s;
}

int signal(int s){ // releases semaphore
    return ++s;
}

void producer(){
    mutex = wait(mutex); // checking if any other process is accessing buffer
    full = signal(full); // signal sent - buffer full 
    empty = wait(empty); // waiting for atleast one slot of buffer to be empty

    count++;
    printf("\nProducer produces item %d\n", count);
    mutex = signal(mutex);
}

void consumer(){
    mutex = wait(mutex); 
    empty = signal(empty); // signal sent - buffer empty
    full = wait(full); // waiting for atleast one slot of buffer to be full

    printf("\nConsumer consumes item %d\n", count);
    count--;
    mutex = signal(mutex);
}

void main(){
    int arr[20] = {1, 2};
    while(1){
        int c = arr[rand() % 2];
        switch(c){
            case 1: 
            if(mutex == 1 && empty!=0){
                producer();
            }
            else{
                printf("\nBuffer is full!");
            }
            break;
            
            case 2:
            if(mutex == 1 && full!=0){
                consumer();
            }
            else{
                printf("\nBuffer is empty!");
            }
            break;
            
            case 3: exit(0);
        }
        sleep(2);
    }
}