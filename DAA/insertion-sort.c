#include<stdio.h>
#define SIZE 5
int i, j, a[SIZE];

void insertion(){
    int temp;
    for(i=1;i<SIZE;i++){
        temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }   
}

void main(){
    insertion();
    for(i=0;i<SIZE;i++){
        printf("%d",a[i]);
    }
}