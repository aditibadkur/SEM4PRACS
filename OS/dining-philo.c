#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h> 
#define n 5
int i;

void thinking(int id){
    printf("\nPhilosopher %d is thinking", id);
    sleep((rand()%5));
}

void eating(int id){
    printf("\nPhilosopher %d is eating", id);
    sleep((rand()%5));
}

void philosopher(int id){
    while(1){
        thinking(id);
        eating(id);
    }
}

int main(){
    srand(time(NULL));
    for(i=0;i<n;i++){
        pid_t pid = fork();
        if(pid == 0){
            philosopher(i);
            exit(0);
        }
        else if(pid<0){
            perror("\nFork error");
            exit(1);
        }
    }
    for (i=0;i<n;i++)
    {
        wait(NULL);
    }
    return 0;
}