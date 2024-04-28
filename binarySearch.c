#include <stdio.h>
#include <conio.h>
#define max 50

int binarySearch(int arr[], int key, int n)
{
    int s = 0;
    int e = n-1;
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(key < arr[mid])
        {
            e = mid-1;
        }
        else if(key > arr[mid]){
            s = mid+1;
        }
    }
    return -1;
}

void main(){
    int arr[max], n, i, key, ans, temp,j;
    clrscr();
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("After sorting\n");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the key to find\n");
    scanf("%d", &key);
    ans = binarySearch(arr, key, n);
    printf("Element is at %d index",ans);
    getch();
}
