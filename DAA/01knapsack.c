// CHECK 

#include<stdio.h>
#define MAX 100
#define items 4
int maxWt=5, maxProfit;
int profit[MAX]={3, 4, 5, 8}, weight[MAX]={2, 3, 4, 5};

struct State{
    int profit,  wts;
}states[MAX];

void knapsack(){
    int i, j, tempCount, stateCount=1;
    states[0].profit = 0;
    states[0].wts = 0;
    for(i=0;i<items;i++){
        struct State tempStates[MAX];
        tempCount = 0;

        // The new state has the profit of the old state plus the profit of the current item, 
        // and the weight of the old state plus the weight of the current item. 
        for(j=0;j<stateCount;j++){ 
            tempStates[j].profit = states[j].profit + profit[i];
            tempStates[j].wts = states[j].wts + weight[i];
            tempCount++;
        }

        // If the new state's weight does not exceed the maximum weight capacity (maxWeight), 
        // it is added to the states array.
        for(j=0;j<tempCount;j++){
            if(tempStates[j].wts <=  maxWt){
                states[stateCount] = tempStates[j];
                stateCount++;   
            }
        }
    }

    // find the state with the highest profit that does not exceed the weight capacity.
    maxProfit = 0;
    for(i=0;i<tempCount;i++){
        if(states[i].profit>maxProfit && states[i].wts<= maxWt){
            maxProfit = states[i].profit;
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
}

void main(){
    knapsack();
}