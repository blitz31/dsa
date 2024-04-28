#include<stdio.h>
 
void merge(int a[],int s,int m,int m1,int e)
{
    int temp[50];
    int i,j,k;
    i=s;
    j=m1;
    k=0;
    while(i<=m && j<=e)
    {
    if(a[i]<a[j])
        temp[k++]=a[i++];
    else
        temp[k++]=a[j++];
    }
    while(i<=m)
        temp[k++]=a[i++];
    while(j<=e)
        temp[k++]=a[j++];
    for(i=s,j=0;i<=e;i++,j++)
        a[i]=temp[j];
}

void mergesort(int a[],int s,int e)
{
    int mid;
    if(s<e)
    {
    mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);
    merge(a,s,mid,mid+1,e);
    }
}
 
void main()
{
    int a[30],n,i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\nSorted array is :");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
