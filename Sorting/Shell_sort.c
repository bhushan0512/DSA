#include<stdio.h>
void shell_sort(int a[],int n,int increments[], int numinc)
{
    int i,j,k,span,temp;
    for(k=0;k<numinc;k++)
    {
        span=increments[k];
        for(i=span;i<n;i++){
            temp=a[i];
            for(j=i-span;j>=0 && temp<a[j];j=j-span){
                a[j+span]=a[j];
            }
            a[j+span]=temp;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void main()
{
    int n,a[100],i;
    int increments[] = {5, 3, 1}; 
    int numinc = 3;
    
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
        printf("%d\t",a[i]);
    }
    printf("\nArray after sorting\n");
    shell_sort(a, n, increments, numinc);
}
