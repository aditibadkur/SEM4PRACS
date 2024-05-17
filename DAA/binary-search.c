#include<stdio.h>
int x=40, a[5]={10, 20, 30, 40, 50};

int bs(int low, int high){
    if(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>x){
            bs(low, mid);
        }
        else if(a[mid]<x){
            bs(mid+1, high);
        }
        else{
            return mid;
        }
    }
    else{
        return -1;
    }
}

void main(){
    printf("Found at index %d ",bs(0, 4));
}   