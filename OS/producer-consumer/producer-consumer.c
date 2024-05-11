#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
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
    int choice;
    while(1){
        printf("\n1.Producer\n2.Consumer\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: 
        if((mutex == 1) && (empty != 0)) 
            producer();
        else 
            printf("\nBuffer is full!\n");
        break;

        case 2: 
        if((mutex == 1) && (full != 0)) 
            consumer();
        else 
            printf("\nBuffer is empty!\n");
        break;

        case 3: exit(0);
        
        default: printf("\nEnter valid choice");
        }
    }
}