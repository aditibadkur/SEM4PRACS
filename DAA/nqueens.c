// CHECK

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int i, j, k, x[SIZE];

int place(int k, int n){
    for(i=0;i<k;i++){
        if(x[i] == n || abs(x[i]-n) == abs(i-k)){
            return 0;
        }
    }
    return 1;
}

void nqueen(int k){
    if(k==SIZE){
        for(i=0;i<SIZE;i++)
        {
            printf("%d ",x[i]+1);
        }
        printf("\n");
        return;
    }

    for(j=0;j<SIZE;j++){
        if(place(k, j)){
            x[k] = j;
            nqueen(k+1);
        }
    }
}

int main(){
    nqueen(0);
    return 0;
}