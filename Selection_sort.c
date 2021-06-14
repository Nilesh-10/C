/*
    Selection sort is a simple sorting algorithm.
    This sorting algorithm is an in-place comparison-based algorithm in
    which the list is divided into two parts, the sorted part at the left end and the unsorted part at the right end.
    Initially, the sorted part is empty and the unsorted part is the entire list.
*/

#include<stdio.h>
int min(int a[],int k,int n)
{
    int MIN,LOC;
    MIN=a[k];
    LOC=k;

    //Finding min value.

    for(int i=k+1;i<=n-1;i++)
    {
        if(MIN>a[i])
        {
            MIN=a[i];
            LOC=i;
        }
    }
    return(LOC);
}
void SelectionSort(int a[],int n)
{
    int t,l;
    for(int i=0;i<=n-2;i++)
    {
        l=min(a,i,n);
        t=a[i];
        a[i]=a[l];
        a[l]=t;
    }
}
int main()
{
    int a[]={5,8,6,1,4};
    SelectionSort(a,5);

    //print the sorted no's.

    for(int i=0;i<5;i++)
    {
        printf(" %d",a[i]);
    }
    return 1;
}

/*
    Input:5,8,6,1,4
    output:1,4,5,6,8

    Time Complexity:n^2.
    Space complexity:n
*/
