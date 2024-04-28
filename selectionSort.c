#include <stdio.h>

#define MAX_SIZE 50

int arr[MAX_SIZE];

int getMax(int s, int e) {
    int i;
    int vmax = s;
    for (i = s; i <= e; i++) {
        if (arr[vmax] < arr[i]) {
            vmax = i;
        }
    }
    return vmax;
}

void swap(int f, int s) {
    int temp;
    temp = arr[f];
    arr[f] = arr[s];
    arr[s] = temp;
}

void selectionSort(int n) {
    int i, last, max;
    for (i = 0; i < n; i++) {
        last = n - i - 1;
        max = getMax(0, last);
        swap(max, last);
    }
}

int main() {
    int i, n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("Enter the elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("After sorting\n");
    selectionSort(n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
