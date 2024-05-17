#include<stdio.h>
#define SIZE 8
int A[SIZE]={23,32,45,3,564,75,22,1}, B[SIZE];
int i, j, k;

void merge(int low, int mid, int high){
    i = low;
    j = mid+1;
    k = 0;

    while(i<=mid && j<=high){
        if(A[i]>A[j])
        {
            B[k++]=A[j++];
        }
        else{
            B[k++]=A[i++];
        }

    }

    while(i<=mid){
        B[k++] = A[i++];
    }
    while(j<=high){
        B[k++] = A[j++];
    }
    
    i = low;
    for(j=0;j<k;j++){
        A[i] = B[j];
        i++;
    }

}

void mergesort(int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergesort(low, mid);
        mergesort(mid+1, high);
        merge(low, mid, high);
    }
}

void main(){
    mergesort(0, SIZE-1);
    for(int i=0;i<SIZE;i++)
    {
        printf("%d ",A[i]);
    }
}