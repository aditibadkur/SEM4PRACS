#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define SIZE 50
int i,  j, table[SIZE][SIZE], b[SIZE][SIZE], arrow[SIZE][SIZE];
char A[SIZE], B[SIZE];

void printLCS(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'd')
    {
        printLCS(i - 1, j - 1);
        printf("%c", A[i - 1]);
    }
    else if (b[i][j] == 'u')
        printLCS(i - 1, j);
    else
        printLCS(i, j - 1);
}

void lcs(char A[], char B[])
{
    for (i = 0; i <= strlen(A); i++)
        arrow[i][0] = 0;
    for (i = 0; i <= strlen(B); i++)
        arrow[0][i] = 0;

    for (i = 1; i <= strlen(A); i++){
        for (j = 1; j <= strlen(B); j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                arrow[i][j] = arrow[i - 1][j - 1] + 1;
                b[i][j] = 'd';
            }
            else if (arrow[i - 1][j] >= arrow[i][j - 1])
            {
                arrow[i][j] = arrow[i - 1][j];
                b[i][j] = 'u';
            }
            else
            {
                arrow[i][j] = arrow[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
    printLCS(strlen(A), strlen(B));
}

void print(){
    printf("\n");
    for(i=1;i<=strlen(A);i++){
        for(j=1;j<=strlen(B);j++){
            printf("%d", table[i][j]);
        }
        printf("\n");
    }
}

void lcs_table(char A[], char B[]){
    for(i=1;i<=strlen(A);i++){
        for(j=1;j<=strlen(B);j++){
            if(A[i-1] == B[j-1]){
                table[i][j] = table[i-1][j-1]+1;
            }
            else{
                table[i][j] = fmax(table[i][j-1], table[i-1][j]);
            }
        }
    }
}

void main(){
    printf("Enter string1: ");
    scanf("%s", &A);
    printf("Enter string2: ");
    scanf("%s", &B);
    lcs(A, B);
    lcs_table(A, B);
    print();
}