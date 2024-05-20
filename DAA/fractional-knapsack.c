#include<stdio.h>
#define SIZE 3
int i, j, maxWt=20;
float ratio[SIZE];
int visited[SIZE]={0};
float P[SIZE]={25.0, 24.0, 15.0};
float W[SIZE]={18.0, 15.0, 10.0};

void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void sort(float arr[]){
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swap(&P[j], &P[j+1]);
                swap(&W[j], &W[j+1]);
            }
        }
    }
}

void knapsack(){
    for(i=0;i<SIZE;i++){
        ratio[i] = P[i]/W[i];
    }
    sort(ratio);
    for(i=0;i<SIZE;i++){
        printf("%.2f\t", P[i]);
    }
    printf("\n");
    for(i=0;i<SIZE;i++){
        printf("%.2f\t", W[i]);
    }
    printf("\n");
    for(i=0;i<SIZE;i++){
        printf("%.2f\t", ratio[i]);
    }

    float totalValue = 0.0;
    float remaining = (float)maxWt;

    printf("\nTarget weight: %d\n", maxWt);
    for (i = 0; i < SIZE; i++) {
        if(remaining == 0){
            break;
        }
        if (W[i] <= remaining) {
            // If the whole item can be added
            remaining -= W[i];
            totalValue += P[i];
            printf("Added item %d: weight = %.2f, value = %.2f, remaining capacity = %.2f\n", i+1, W[i], P[i], remaining);
        } 
        else {
            // If only part of the item can be added
            totalValue += P[i] * (remaining / W[i]);
            printf("Added part of item %d: weight = %.2f, value = %.2f, remaining capacity = 0\n", i+1, remaining, P[i] * (remaining / W[i]));
            remaining = 0;
            break;
        }
    }
    printf("Total value of items in the knapsack: %.2f\n", totalValue);

    // printf("\nTarget wt %d", maxWt);
    // int count = 0, maxRatio, maxRatioIndex, remaining=18;
    // while(count<SIZE){
    //     for(i=0;i<SIZE-1;i++){
    //         if(visited[i] == 0){
    //             maxRatio = ratio[i]>ratio[i+1]?ratio[i]:ratio[i+1];
    //             maxRatioIndex = ratio[i]>ratio[i+1]?i:i+1;
    //         }
    //     }
    //     remaining -= W[maxRatioIndex];
    //     printf("\nMax ratio found at index %d", maxRatioIndex);
    //     printf("\nRemaining wt: %d", remaining);
    //     visited[maxRatioIndex] = 1;
    //     count++;
    // }


}

void main(){
    printf("\n");
    knapsack();
}