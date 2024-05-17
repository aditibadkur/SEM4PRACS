#include<stdio.h>
#define SIZE 4
int i, j, k;
int c[SIZE][SIZE], x[SIZE][SIZE], d[SIZE+1]={3,2,4,2,5};

void calc(int i, int j){
    int tempc=1000, tempk=0;
    for(k=i;k<j;k++){
        if(tempc>c[i][k]+c[k+1][j]+d[i]*d[j+1]*d[k+1]){
            tempc = c[i][k]+c[k+1][j]+d[i]*d[j+1]*d[k+1];
            tempk = k+1;
        }
    }
    c[i][j] = tempc;
    x[i][j] = tempk;
}

void optimalOrder(int i, int j){
    if (i == j){
        printf("A%d ", i+1);
    } 
    else{
        printf("(");
        optimalOrder(i, x[i][j]-1);
        optimalOrder(x[i][j], j);
        printf(")");
    }
}

void tableForm(){
    for(i=0;i<SIZE;i++){
        c[i][i] = 0;
    }

    int count = 1;
    while(count<=SIZE-1){
        for(i=0;i<SIZE;i++){
            for(j=0;j<SIZE;j++){
                if(j-i==count){
                    // printf("i:%d j:%d\n",i,j);
                    calc(i,j);
                }
            }
        }
        count++;
    }
}

void main(){
    tableForm();
    printf("\n");

    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }

    optimalOrder(0,SIZE-1);
}