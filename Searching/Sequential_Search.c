#include<stdio.h>
void sequential_search(int a[],int n,int x)
{
    int i;
    for(i=0;i<n;i++){
        if(a[i]==x){
            printf("Element found at index %d",i);
            return;
        }
    }
    printf("Element not found");
}
void main()
{
    int n,a[100],i,j,x,temp;
    printf("Enter the number of elements in an array\n");
    scanf("%d",&n);
    printf("Enter array elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("Enter the element to be searched : ");
    scanf("%d",&x);
    sequential_search(a,n,x);
}
