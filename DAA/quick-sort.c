#include<stdio.h>
#define SIZE 8
int i, j;
int A[SIZE]={23,1,45,38,98,42,4}, B[SIZE];


void swap(int *x, int *y) 
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int low, int high){
    i = low;
    j = high;
    int pivot = low;
    int temp;
    while(i<j){
        while(A[i]<=A[pivot]){
            i++;
        }
        while(A[j]>A[pivot]){
            j--;
        }
        if(i<j)
            {
                swap(&A[i],&A[j]);
            }
        }
        swap(&A[pivot],&A[j]);
}

void quicksort(int low, int high){
    if(low<high){
        int p = partition(low, high);
        quicksort(low, p);
        quicksort(p+1, high);

    }
}

void main(){
    quicksort(0, SIZE-1);
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",A[i]);
    }
}