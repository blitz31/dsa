#include <stdio.h>
#define max 50
int arr[max];
int swap=0;
int comp=0;

void insertionSort(int n){
    int i,j,temp;
    for(i=0; i<n-1; i++){
        for(j=i+1; j>0; j--){
            comp++;
            if(arr[j-1] > arr[j]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swap++;
            }
            else{
                break;
            }
        }
    }
}

int main(){
    int i, n;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    insertionSort(n);
    printf("After sorting\n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\nNo. of comparisons is %d\nNo. of swaps is %d", comp, swap);
    return 0;
}
