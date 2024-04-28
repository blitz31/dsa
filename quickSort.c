#include<stdio.h>

void quickSort(int arr[], int low, int hi){

    int temp;
    int s = low;
    int e = hi;
    int mid = (s+e)/2;
    int pivot = arr[mid];
   
    if(low >= hi)
        return;
   
    while(s<=e){
        while(arr[s] < pivot)
            s++;
        while(arr[e] > pivot)
            e--;
           
        if(s <= e){
            temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
    quickSort(arr, low, e);
    quickSort(arr, s, hi);
}
 
void main()
{
    int arr[30],n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quickSort(arr, 0, n-1);
    printf("\nSorted array is :");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
