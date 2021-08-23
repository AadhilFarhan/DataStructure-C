#include<stdio.h>
#include<stdlib.h>
int a[10],n,temp;
void insertion()
{
    for(int i=1;i<n;i++)
    {
        temp=a[i];
        int j=i-1;
        while(temp<a[j]&&j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int i;
    printf("Enter number of elements in the array : ");
    scanf("%d",&n);
    printf("Enter elements of the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nARRAY BEFORE SORTING IS :");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    insertion();
    printf("\n");
    printf("\nARRAY AFTER INSERTION SORTING IS :");
    for(int i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    return 0;
}