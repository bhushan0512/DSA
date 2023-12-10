#include<stdio.h>
void selection_sort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min=i;                  //assuming first element is lowest(in each iteration min stores the index of lowest element)
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;          //storing the index of lowest elemnt
            }
        }
        temp=a[i];              //swapping lowest value 'a[min]' with 'i' index 
        a[i]=a[min];
        a[min]=temp;
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
    selection_sort(a,n);
}
