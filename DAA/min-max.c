#include<stdio.h>
#define SIZE 10
int A[SIZE]={80, 40, 30, 100, 90, 70, 60, 20, 50, 10};
int max, min;

void find(int low, int high){
    if(low == high){
        max = A[high];
        min = A[low];
    }

    else if(low ==  high-1){
        if(A[low]< A[high]){
            min = A[low];
            max = A[high];
        }
        else{
            min = A[high];
            max = A[low];
        }
    }

    else{
        int mid = (low+high)/2;
        int max1, min1;
        find(low, mid);
        min1 = min;
        max1 = max;
        find(mid+1, high);

        if(max1>max){
            max=max1;
        }
        if(min1<min){
            min=min1;
        }  
    }
}

void main(){
    find(0, SIZE-1);
    printf("Max: %d\nMin: %d", max, min);
}