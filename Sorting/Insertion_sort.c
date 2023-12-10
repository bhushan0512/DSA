#include<stdio.h>
void insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        for(j=i-1;j>=0 && temp<a[j];j--){
                a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
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
    insertion_sort(a,n);
}
