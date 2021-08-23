#include<stdio.h>

void BubbleSort(int A[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    printf("\nBuble Sorted Array is: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }
}

void main()
{
    int Arr[20],no;
    printf("Enter number of elements in the array to be sorted :");
    scanf("%d",&no);
    printf("\nEnter Array elements to be sorted : ");
    for(int i=0;i<no;i++)
    {
        scanf("%d", &Arr[i]);
    }
    BubbleSort(Arr,no);
}