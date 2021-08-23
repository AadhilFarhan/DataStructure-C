#include<stdio.h>
#include<conio.h>
void main()
{
    int i, a[20], n, key, f = 0;
    printf("Enter the size of an array \n");
    scanf("%d", &n);
    printf("Enter the array elements");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the key elements");
    scanf("%d", &key);
    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
       {
          f = 1;
          break;
       }
    }
    if(f == 1)
    {
       printf("The elements is found at location %d", i+1);
    }
    else
    {   
        printf("The element is not found in the array");
    }
}