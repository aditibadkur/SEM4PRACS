#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
int count=0;

void producer(){
    if(count == SIZE){
        printf("\nBuffer is full!\n");
    }
    else{
        count++;
        printf("\nProducer produces item %d\n", count);
    }   
}

void consumer(){
    if(count == 0){
        printf("\nBuffer is empty!\n");
    }
    else{
        printf("\nConsumer consumes item %d\n", count);
        count--;
    }
}

void main(){
    int choice;
    while(1){
        printf("\n1.Producer\n2.Consumer\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: producer();
        break;
        case 2: consumer();
        break;
        case 3: exit(0);
        
        default: printf("\nEnter valid choice");
        }
    }
}