#include<stdio.h>
void interpolation_search(int a[],int l,int r,int x)
{
    int mid;
    while(l<=r){
        mid=l+(r-l)*((x-a[l])/(a[r]-a[l]));
        if(x==a[mid]){
            printf("Element found at index %d",mid);
            return;
        }
        if(x<a[mid]){
            r=mid-1;
        }
        else{
            l=mid+1;
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
    
    for(i=0;i<n-1;i++)          //sorting the array to perform the interpolation search
    {
        for(j=0;j<n-i-1;j++)
        {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    
    printf("Enter the element to be searched : ");
    scanf("%d",&x);
    interpolation_search(a,0,n-1,x);
}
