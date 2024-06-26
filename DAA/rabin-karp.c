#include<stdio.h>
#include<string.h>
#include<math.h>
int i, j;
char T[100], P[50];

int val(char x){
    return ((int)x)-96;
}

void rabinkarp(char *T, char *P, int d, int q){
    int m = strlen(T);
    int n = strlen(P);
    int h = ((int)pow(d, n-1))%q;
    int t=0,  p=0;

    for(i=0;i<n;i++){
        t = (d*t+val(T[i]))%q;
        p = (d*p+val(P[i]))%q;
    }

    for(i=0;i<=m-n+1;i++){
        if(p == t){
            int count = 0;
            for(j=0;j<n;j++){
                if(P[j] == T[j+i]){
                    count++;
                }
            }
            if(count == n){
                printf("pattern found at %d\n", i);
            }
        }
        if(i<=m-n){
            t = (d*(t-val(T[i])*h) + val(T[i+n]))%q;
        }
    }

}

void main(){
    rabinkarp("abecdcd", "cd", 10, 10);
}