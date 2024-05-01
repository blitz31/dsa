#include<stdio.h>
#include<stdlib.h>
float arr[50]={0};
int capacity[50]={0};

void sort(int itemno[], int profit[], int weight[], int n)
{
    int i, j, temp;
    float ratio[50];

    for(i = 0; i < n; i++)
        ratio[i] = (float)profit[i] / weight[i];

    for(i = 0; i < n - 1; i++)
    {
        for(j = i+1; j < n ; j++)
        {
            if(ratio[j] > ratio[i])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                
                temp = itemno[j];
                itemno[j] = itemno[i];
                itemno[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
            }
        }
    }
}

float greedyKnapsack(int itemno[], int profit[], int weight[], int n, int rcapacity)
{
    float maxProfit = 0.0;
    int i;

    for(i = 0; i < n; i++)
    {
        
        if(weight[i] <= rcapacity)
        {
            maxProfit = maxProfit + profit[i];
            rcapacity = rcapacity - weight[i];
            arr[itemno[i]] = 1;
            capacity[i] = rcapacity;
        }
        else
        {
            maxProfit = maxProfit + (float)profit[i] * rcapacity / weight[i];
            arr[itemno[i]] = (float)rcapacity / weight[i];
            capacity[i] = rcapacity;
            break;
        }
    }

    return maxProfit;
}

void displayTable(int itemno[], int profit[], int weight[], int n)
{
    int i;

    printf("\nItem\tProfit\tWeight\tRemaining Capcity\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", itemno[i], profit[i], weight[i], capacity[i]);
    }
}



int main()
{
    int i, n, rcapacity, itemno[50], profit[50], weight[50], tprofit = 0;

    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    printf("\nEnter the profit and weight of each item:\n");
    for(i = 0; i < n; i++){
        scanf("%d %d", &profit[i], &weight[i]);
        itemno[i] = i;
    }
        

    printf("\nEnter the total capacity of the knapsack: ");
    scanf("%d", &rcapacity);

    sort(itemno, profit, weight, n);

    tprofit = greedyKnapsack(itemno, profit, weight, n, rcapacity);
    
    displayTable(itemno,profit, weight, n);
    printf("\nMaximum profit = %d", tprofit);
    
    printf("\n[ ");
    for(i=0; i<n; i++){
        printf("%.2f ", arr[i]);
    }
    printf("]");

    return 0;
}
