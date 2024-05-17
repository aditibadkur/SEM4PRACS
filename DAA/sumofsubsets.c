#include<stdio.h>
#define SIZE 6
int i, m=30, s=0, k=0, r=73;
int combinations[SIZE], w[SIZE]={5, 10, 12, 13, 15, 18}; 

void sos(int s, int k, int r){
    combinations[k] = 1; // available to be included

    if(s+w[k] == m){ 
        for (i=0;i<SIZE;i++){
            printf("%d\t", combinations[i]);
        }
        printf("\n");  
    }
    else if(s+w[k]+w[k+1]<=m){ // if current+next < m then continue 
        sos(s+w[k], k+1, r-w[k]);
    }
    if((s+r-w[k]>=m) && (s+w[k+1]<=m)){ // to find if m is possible without the current value (w[k]) being used
    // and addition of next value doesnt exceed m
        combinations[k] = 0;
        sos(s, k+1, r-w[k]);
    }
    combinations[k] = 0; // to not include in the subset
}

void main(){
    for(i=0;i<SIZE;i++){
        printf("%d\t", w[i]);
    }
    printf("\n");
    sos(0, 0, 73);
}