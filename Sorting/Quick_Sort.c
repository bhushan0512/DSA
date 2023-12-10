#include<stdio.h>
void quick_sort(int a[],int low, int high)
{
    int i,j,temp,x;
    if(low>=high)
    return;
    else{
        x=a[low];
        i=low+1;
        j=high;
        while(i<=j){
        while(a[i]<x && i<=high){
            i++;
        }
        while(a[j]>x && j>low){
            j--;
        }
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
        }
        a[low]=a[j];
        a[j]=x;
        
        quick_sort(a,low,j-1);
        quick_sort(a,j+1,high);
    }
}
void main()
{
    int n,a[100],i;
    printf("Enter the number of elements in an array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array before sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\n",a[i]);
    }
    printf("Array after sorting\n");
    quick_sort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\t\n",a[i]);
    }
}
