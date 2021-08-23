#include<stdio.h>

void main()
{
    int n,A[20],item,down,up,mid;
    printf("Enter the number of elements ");
    scanf("%d",&n);
    printf("Enter the elements in ascending order : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nEnter the element to be searched :");
    scanf("%d",&item);
    down=0;
    up=n;
    mid=down+(up-down)/2;
    while(mid>=0)
    {

        
        if(mid==item)
        {
            printf("\nElement is found at %d",mid);
            return;

        }
        else if(item>A[mid])
        {
            down=mid+1;
        }
        else if(item<A[mid])
        {
            up=mid-1;
        }
        mid=down+(up-down)/2;

    }
}