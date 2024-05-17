#include<stdio.h>
#include<string.h>
char T[100], P[50];
int pi[100];

int computePrefix(){
    int q = 0;
    pi[0] = 0;
    pi[1] = 0;
    int i, k = 0;

    for(q=2;q<=strlen(P);q++){
        while(k>0 && P[k]!=T[q]){
            k = pi[k];
        }
        if(P[k] == T[q-1]){
            k++;
        }
        pi[q] = k;
    }
    printf("Prefix array: ");
    for (i=1;i<=strlen(P);i++)
    {
        printf("%d ", pi[i]);
    }
    printf("\n");
}

void KMP(){
    int m = strlen(T);
    int n = strlen(P);
    // int pi = computePrefix();
    int i, q = 0;
    for(i=0;i<m;i++){
        while(q>0 && P[q]!=T[i]){
            q = pi[q];
        }
        if(P[q] == T[i]){
            q++;
        }
        if(q == n){
            printf("\nPattern found at shift %d", i-n+1);
            q = pi[q];
        }
    }
}

void main(){
    printf("Enter text: ");
    scanf("%s", &T);
    printf("Enter pattern: ");
    scanf("%s", &P);
    KMP();
}