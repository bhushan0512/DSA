#include<stdio.h>
void merge(int A[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[10],R[10];
    
    for(i=0;i<n1;i++)
        L[i]=A[l+i];
    
    for(j=0;j<n2;j++)
        R[j]=A[m+1+j];
    
    j=0;i=0;k=l;
    
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    } 
    
    while(i<n1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}

void mergesort(int A[], int l, int r)
{ 
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(A,l,m);
        mergesort(A,m+1,r);
        merge(A,l,m,r);
    }
}
void main()
{
    int A[20],i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++) 
        scanf("%d",&A[i]);
    mergesort(A,0,n-1);
    printf("Array after merge sort : \n");
    for(i=0;i<n;i++) 
        printf("%d\n", A[i]);
}
